#include <button.h>

class buttonManager
{
  public:
    void addButtons(button b[], int size);
    int checkCollisionsTrampoline(void *arg);
};