
#include "vex.h"
#include "button.h"

typedef char *string;
square s;
bool clicked = false;
bool isDisabled = false;
void (*functionpointer)(void);

bool checkCollsion(point p, square s)
{
    return p.x >= s.x && p.x <= s.x + s.w && p.y >= s.y && p.y <= s.y + s.h;
}

void button::setButtonDisabled(bool x)
{
  isDisabled = x;
}

void button::destroy()
{
  clear();
  setButtonDisabled(true);
}
void button::clear()
{
  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(s.x, s.y, s.w, s.h);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(s.x, s.y, s.w, s.h);
  Brain.Screen.setPenColor(transparent);
}

int button::CheckCollisions()   {
    while(true) {
      waitUntil(Brain.Screen.pressing());
      point p = {Brain.Screen.xPosition(),Brain.Screen.yPosition()};
      if (checkCollsion(p, this->s) && isDisabled != true) {

         this->functionpointer();
         return EXIT_SUCCESS;
      }
    }
  while(true) {
    // Allow other tasks to run
    this_thread::sleep_for(10);
  }
  return EXIT_SUCCESS;
}

void button::setup(int x, int y, int width, int height, string text, void (*ptr)(void))
{
    Brain.Screen.drawRectangle(x, y, width, height);
    s = {x, y, width, height};
    int tw = vexDisplayStringWidthGet(text);
    int th = vexDisplayStringHeightGet(text);
    int tl = s.x + (s.w / 2) - (tw/2);
    int tt = s.y + (s.h / 2) - (th / 2);
    Brain.Screen.printAt(tl, tt, false, text);
    functionpointer = ptr;
    return;
}

void button::setup(square s, string text, void (*ptr)(void)) {button::setup(s.x, s.y, s.w, s.h, text, ptr);}
