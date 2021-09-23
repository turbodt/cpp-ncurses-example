#ifndef INCLUDE_APP_COMPONENT
#define INCLUDE_APP_COMPONENT

#include<future>
#include<ncurses.h>
#include<string>
#include<app/base/component.hpp>
#include<app/app.controller.hpp>
#include<app/header.component.hpp>

namespace app {
  namespace main {

    class AppComponent : public Component {
      protected:
        AppController * controller = nullptr;

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
