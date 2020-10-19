#include<app/base/component.hpp>

namespace app {
  Position::Position():y(0), x(0) {};
  Position::Position(int y, int x):y(y), x(x) {};
  Position & Position::operator+=(const Position & position) {
    this->x += position.x;
    this->y += position.y;
    return *this;
  }
  Position & Position::operator-=(const Position & position) {
    this->x -= position.x;
    this->y -= position.y;
    return *this;
  }
  Position operator+(Position lsh, const Position & rhs) {
    return lsh += rhs;
  }
  Position operator-(Position lsh, const Position & rhs) {
    return lsh -= rhs;
  }

  Component::Component(Component * const parent) {
    logging::logger->debug("In Component Constructor");
    this->parent = parent;
    this->position = Position(0,0);
    if (parent) {
      this->position += *(this->parent->get_position());
    }
    this->size = {0,0};
    this->start();
  }
  Component::Component(Component * const parent, Position position) {
    logging::logger->debug("In Component Constructor");
    this->parent = parent;
    this->position = position;
    if (parent) {
      this->position += *(this->parent->get_position());
    }
    this->size = {0,0};
    this->start();
  }
  Component::Component(Component * const parent, Size size) {
    logging::logger->debug("In Component Constructor");
    this->parent = parent;
    this->position = Position(0,0);
    if (parent) {
      this->position += *(this->parent->get_position());
    }
    this->size = size;
    this->start();
  }
  Component::Component(Component * const parent, Position position, Size size) {
    logging::logger->debug("In Component Constructor");
    this->parent = parent;
    this->position = position;
    if (parent) {
      this->position += *(this->parent->get_position());
    }
    this->size = size;
    this->start();
  }

  Component::~Component() {
    logging::logger->debug("In Component Destructor");
    delwin(this->window);
  }

  Position const * const Component::get_position() const {
    return &(this->position);
  }

  Size const * const Component::get_size() const {
    return &(this->size);
  }

  Component * Component::start() {
     this->window = newwin(
        this->size.rows,
        this->size.cols,
        this->position.y,
        this->position.x
    );
    refresh();
    return this;
  }

  Component * Component::render() {
    box(this->window, 0, 0);
    wrefresh(this->window);
    return this;
  }
}
