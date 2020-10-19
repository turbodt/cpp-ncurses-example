#ifndef INCLUDE_HEADER_COMPONENT
#define INCLUDE_HEADER_COMPONENT

#include<ncurses.h>
#include<string>
#include<logging.hpp>
#include<app/base/component.hpp>

namespace app {
  namespace main {

    class HeaderComponent : public Component {
      public:
        HeaderComponent(Component * const parent);
        HeaderComponent * render(const std::string & title);
    };

  }
}

#endif
