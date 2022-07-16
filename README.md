# Buttons-for-vexV5

This repository has all of the necessary code to add your own buttons to the vex v5 Brain!


The **first** thing you are going to want to do to set up the buttons is
downloading and including button.h. **Note button.h will not work if you do not have
button.cpp installed.**

Now you have the required files installed this step doesn't matter as much
but, your file structure should look something like this.
```
include/
  robot-config.h
  vex.h
  button.h
src/
  main.cpp
  robot-config.cpp
  button.cpp
```

**Note: you don't have to use the namespace vex but it's recommended.**
```cpp
#include "vex.h"
#include <button.h>

using namespace vex;
```

# Second step

---

Your beginning main function should look something like this, in main.cpp.
```cpp
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
 }
 ```
 
 Jump to the top of your file and add this.
 ```cpp
 
button b; // Making the button.

// Struct square, x, y, width, height.
square button = 
{
  480 / 2,
  240 / 2,
  155,
  50
};

```

The first argument in the struct square is the x coordinate,
then the y, then the width, and height.

The second to last step is to add functionallity to your button!

```cpp
int buttonCollsions()
{
  b.CheckCollisions();
  return 0;
}
void buttonFunctionallity()
{
  Brain.Screen.clearScreen();
}
```

then the final step in main,
```cpp
  b.setup(button, "example code.", buttonFunctionallity); // void setup(square s, string text, void (*ptr)(void));
  task check(buttonCollsions);
```

# What your file should look like.

---

```cpp
#include "vex.h"
#include <button.h>

using namespace vex;

button b;
square button = 
{
  480 / 2,
  240 / 2,
  155,
  50
};
int buttonCollsions()
{
  b.CheckCollisions();
  return 0;
}
void buttonFunctionallity()
{
  Brain.Screen.clearScreen();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  b.setup(button, "example code.", buttonFunctionallity); // void setup(square s, string text, void (*ptr)(void));
  task check(buttonCollsions);
}
```

# Results 😁

---

## Before button click!

![Before Click](https://user-images.githubusercontent.com/84548368/179364353-ae1f35a0-35fe-41b6-b6b3-d30c5a88a382.jpg)

## After button click!

![After Click](https://user-images.githubusercontent.com/84548368/179364362-744eea57-ebf9-480f-bbdf-d173f1135149.jpg)

## Thank you for reading through this. 😃

### Credits 💳
This github page and 100% of the code is managed and written by Void (me).
[Void's github](https://github.com/ItzVoidYT)

---
