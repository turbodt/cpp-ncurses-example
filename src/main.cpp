#include <ncurses.h>
#include <string>
#include "spdlog/spdlog.h"
#include <logging.hpp>
#include <app/app.runner.hpp> 

int main() {

  spdlog::set_level(spdlog::level::debug);
  logging::logger->debug("In main()");

  app::Runner * runner = app::Runner::get_instance();
  runner->run();
  delete runner;
  return 0;
}
