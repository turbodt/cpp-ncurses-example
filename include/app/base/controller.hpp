#ifndef INCLUDE_CONTROLLER
#define INCLUDE_CONTROLLER

#include<ncurses.h>
#include<app/base/component.hpp>

namespace app {

  class Controller {
    protected:
      Component * component = nullptr;
      bool _is_focus = false;

    public:
      Controller(Component * const component);
      ~Controller();

      Controller * focus(bool focus = true);
      bool is_focus() const;
  };

}


#endif
