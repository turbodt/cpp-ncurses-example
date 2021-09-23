#ifndef INCLUDE_APP_CONTROLLER
#define INCLUDE_APP_CONTROLLER

#include<future>
#include<ncurses.h>
#include<string>
#include<logging.hpp>
#include<app/base/controller.hpp>

namespace app {
  class Runner;
  namespace main {
    class AppComponent;

    class AppController : public Controller {
      protected:
        Runner * runner;

      public:
        AppController(AppComponent * const component);
        AppController * run();

        AppController * finish();
    };

  }
}

#endif
