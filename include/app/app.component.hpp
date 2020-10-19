#ifndef INCLUDE_APP_COMPONENT
#define INCLUDE_APP_COMPONENT

#include<future>
#include<ncurses.h>
#include<string>
#include<logging.hpp>
#include<app/base/component.hpp>
#include<app/header.component.hpp>

namespace app {
  class Runner;
  namespace main {

    class AppComponent : public Component {
      protected:
        Runner * runner;
        std::string title = "My awesome C++ App";
        HeaderComponent * header;

      public:
        AppComponent(Size size);
        ~AppComponent();
        AppComponent * render();
    };

  }
}

#endif
