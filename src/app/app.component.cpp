#include<app/app.component.hpp>
#include<logging.hpp>

namespace app {
  namespace main {

    AppComponent::AppComponent(Size size)
    :Component(nullptr, size) {
      logging::logger->debug("In AppComponent Constructor");
      this->controller = new AppController(this);
      this->header = new HeaderComponent(this);
    };

    AppComponent::~AppComponent() {
      logging::logger->debug("In AppComponent Destructor");
      delete this->header;
      delete this->controller;
      this->~Component();
    }

    AppComponent * AppComponent::render() {
      refresh();
      mvwprintw(
        this->window,
        this->size.rows/2,
        (this->size.cols - this->title.size())/2,
        this->title.c_str()
      );
      // wborder(this->window, '|', '|', '-', '-', '+', '+', '+', '+');
      wrefresh(this->window);
      this->header->render(this->title);
      this->controller->run();
      return this;
    }
  }
}
