# Buttons-for-vexV5
This repository has all of the necessary code to add your own buttons to the vex v5 Brain!'


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

The first argument in the scruct square is the x coordinate, then the y, then the width, and height.
