#ifndef INCLUDE_APP_RUNNER
#define INCLUDE_APP_RUNNER

#include<ncurses.h>
#include<future>
#include<app/app.component.hpp>

namespace app {

  class Runner {
    private:
      static Runner * _p_instance;
      static std::mutex _mutex;

      main::AppComponent * app = nullptr;
      Size size;
      std::promise<void> barrier;

    protected:
      Runner();

    public:
      ~Runner();
      Runner(Runner const & runner) = delete;
      void operator=(Runner const & copy) = delete;
      static Runner * get_instance();

      int run();
      void finish();
  };

}

#endif
