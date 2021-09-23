#include<app/app.controller.hpp>
#include<app/app.runner.hpp>
#include<logging.hpp>

namespace app {
  namespace main {

    AppController::AppController(AppComponent * const component)
    :Controller(component) {
      logging::logger->debug("In AppController Constructor");
      this->runner = app::Runner::get_instance();
    };

    AppController * AppController::run() {
      char ch = getch();
      while (ch != 'q') {
        logging::logger->debug("Character:" + std::string(1, ch));
        ch = getch();
      }
      logging::logger->debug("Character:" + std::string(1, ch));
      this->finish();
      return this;
    }

    AppController * AppController::finish() {
      this->runner->finish();
      return this;
    }
  }
}
