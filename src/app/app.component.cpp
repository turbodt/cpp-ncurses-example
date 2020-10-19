#include<app/app.component.hpp>
#include<app/app.runner.hpp>

namespace app {
  namespace main {

    AppComponent::AppComponent(Size size)
    :Component(nullptr, size) {
      logging::logger->debug("In AppComponent Constructor");
      this->runner = app::Runner::get_instance();
      this->header = new HeaderComponent(this);
    };

    AppComponent::~AppComponent() {
      logging::logger->debug("In AppComponent Destructor");
      delete this->header;
      this->~Component();
    }

    AppComponent * AppComponent::render() {
      mvwprintw(
        this->window,
        this->size.rows/2,
        (this->size.cols - this->title.size())/2,
        this->title.c_str()
      );
      // wborder(this->window, '|', '|', '-', '-', '+', '+', '+', '+');
      wrefresh(this->window);
      this->header->render(this->title);
      getch();
      this->runner->finish();
      return this;
    }
  }
}
