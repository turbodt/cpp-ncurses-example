#include<app/base/controller.hpp>
#include<logging.hpp>

namespace app {

  Controller::Controller(Component * const component) {
    logging::logger->debug("In Controller Constructor");
    this->component = component;
  }

  Controller::~Controller() {
    logging::logger->debug("In Controller Destructor");
  }

  Controller * Controller::focus(bool focus) {
    this->_is_focus = focus;
    return this;
  }

  bool Controller::is_focus() const {
    return this->_is_focus;
  }
}
