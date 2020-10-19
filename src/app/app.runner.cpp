#include <app/app.runner.hpp>
#include <logging.hpp>
using namespace app;

Runner * Runner::_p_instance{nullptr};
std::mutex Runner::_mutex;

Runner * Runner::get_instance() {
  std::lock_guard<std::mutex> lock(Runner::_mutex);
  if (Runner::_p_instance == nullptr) {
    Runner::_p_instance = new Runner();
  }
  return Runner::_p_instance;
}

Runner::Runner() {}

Runner::~Runner() {
  endwin();
}

void Runner::finish() {
  this->barrier.set_value();
}

int Runner::run() {
  logging::logger->debug("In Runner.run()");
  initscr();
  if (has_colors() == false) {
    //
  } else {
    start_color();
  }

  std::future<void> barrier_future = this->barrier.get_future();

  getmaxyx(stdscr, this->size.rows, this->size.cols);

  this->app = new main::AppComponent(this->size);
  this->app->render();

  barrier_future.wait();

  delete this->app;
  return 0;
}

