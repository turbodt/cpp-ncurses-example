#ifndef INCLUDE_COMPONENT
#define INCLUDE_COMPONENT

#include<ncurses.h>
#include<logging.hpp>

namespace app {

  class Position {
    public:
      int y, x;
      Position();
      Position(int y, int x);
      Position & operator+=(const Position & position);
      Position & operator-=(const Position & position);
  };
  Position operator+(Position lhs, const Position & rhs);
  Position operator-(Position lhs, const Position & rhs);

  struct Size {
    int rows, cols;
  };

  class Component {
    protected:
      WINDOW * window;
      Component * parent = nullptr;
      Size size;
      Position position;
      Component * start();

    public:
      Component(Component * const parent);
      Component(Component * const parent, Position position);
      Component(Component * const parent, Size size);
      Component(Component * const parent, Position position, Size size);
      ~Component();
      Size const * const get_size() const;
      Position const * const get_position() const;

      Component * render();
  };

}


#endif
