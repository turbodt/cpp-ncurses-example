#include<app/header.component.hpp>
using namespace app;
using namespace main;

HeaderComponent::HeaderComponent(Component * const parent):
  Component(parent, (Size){3, parent->get_size()->cols}) {
  logging::logger->debug("In HeaderComponent Constructor");
};

HeaderComponent * HeaderComponent::render(const std::string & title) {
  box(this->window, 0, 0);
  mvwprintw(
    this->window,
    this->size.rows/2,
    (this->size.cols - title.size())/2,
    title.c_str()
  );
  wrefresh(this->window);
  return this;
}
