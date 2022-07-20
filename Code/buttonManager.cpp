#include <vex.h>
#include <buttonManager.h>
#include <memory>


// This class is used so you don't have to create a new task and function to check collisions.
template <class F>
task launch_task(F&& function) {
  //static_assert(std::is_invocable_r_v<void, F>);
  return task([](void* parameters) {
    std::unique_ptr<std::function<void()>> ptr{static_cast<std::function<void()>*>(parameters)};
    (*ptr)();
    return 0;
  }, new std::function<void()>(std::forward<F>(function)));
}

void buttonManager::addButtons(button b[], int size)
{
  for (int i = 0; i < size; i++)
  {
    std::function<void()> func = [=] { b[i].CheckCollisions(); };
    launch_task(func);
  }
}

