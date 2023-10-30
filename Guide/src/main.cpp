
  #pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor leftmoter = motor(PORT16, ratio18_1, false);

motor rightmoter = motor(PORT14, ratio18_1, false);

distance front = distance(PORT10);
distance leftdis = distance(PORT6);
distance rightdis = distance(PORT9);
inertial Inertial12 = inertial(PORT12);

optical down = optical(PORT2);
/*vex-vision-config:begin*/
vision::signature Vision1__ROCK = vision::signature (1, -6951, -1849, -4400,-6847, 1031, -2908,0.9, 0);
vision Vision1 = vision (PORT1, 50, Vision1__ROCK);
/*vex-vision-config:end*/



// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}

#pragma endregion VEXcode Generated Robot Configuration
// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

int Brain_precision = 0, Console_precision = 0, Vision1_objectIndex = 0;

float myVariable;

event _E6_B6_88_E6_81_AF1 = event();
event turnleft = event();
event turnright = event();
event stop = event();
event slow = event();
event none = event();

// "when I receive slow" hat block
void onevent_slow_0() {
  leftmoter.setVelocity(10.0, percent);
  rightmoter.setVelocity(10.0, percent);
  leftmoter.spin(forward);
  rightmoter.spin(forward);
}

// "when started" hat block
int whenStarted1() {
  if (leftdis.objectDistance(mm) < 400.0) {
    turnright.broadcast();
  }
  else {
    if (rightdis.objectDistance(mm) < 400.0) {
      turnleft.broadcast();
    }
    else {
      if (front.objectDistance(mm) < 400.0) {
        stop.broadcast();
      }
      else {
        if (!down.isNearObject()) {
          stop.broadcast();
        }
        else {
          if (Inertial12.orientation(roll, degrees) < -5.0) {
            slow.broadcast();
          }
          else {
            Vision1.takeSnapshot(Vision1__ROCK);
            if (Vision1.objectCount > 0) {
              Vision1_objectIndex = static_cast<int>(1.0) - 1;
              if (Vision1.objects[Vision1_objectIndex].centerX > 120.0) {
                turnleft.broadcast();
              }
              else {
                if (Vision1.objects[Vision1_objectIndex].centerX < 80.0) {
                  turnright.broadcast();
                }
                else {
                  none.broadcast();
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

// "when I receive stop" hat block
void onevent_stop_0() {
  leftmoter.setVelocity(100.0, percent);
  rightmoter.setVelocity(100.0, percent);
  leftmoter.spin(forward);
  rightmoter.spin(forward);
}

// "when I receive turnright" hat block
void onevent_turnright_0() {
  rightmoter.setVelocity(100.0, percent);
  leftmoter.spin(forward);
}

// "when I receive turnleft" hat block
void onevent_turnleft_0() {
  leftmoter.setVelocity(100.0, percent);
  leftmoter.spin(forward);
}

// "when I receive none" hat block
void onevent_none_0() {
  leftmoter.stop();
  rightmoter.stop();
}

// Used to find the format string for printing numbers with the
// desired number of decimal places
const char* printToBrain_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Brain_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everthing else
  }
}

// "when started" hat block
int whenStarted2() {
  while (true) {
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(front.objectDistance(mm)));
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(leftdis.objectDistance(mm)));
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(rightdis.objectDistance(mm)));
  wait(5, msec);
  }
  return 0;
}

// "when started" hat block
int whenStarted3() {
  while (true) {
    if (rightdis.objectDistance(mm) < 500.0) {
      turnleft.broadcast();
    }
    else {
      if (leftdis.objectDistance(mm) < 500.0) {
        turnright.broadcast();
      }
      else {
        if ((leftdis.objectDistance(mm) < 500.0 && rightdis.objectDistance(mm) < 500.0) && front.objectDistance(mm) < 500.0) {
          stop.broadcast();
        }
        else {
          if (Inertial12.orientation(pitch, degrees) > 5.0) {
            slow.broadcast();
          }
          else {
            _E6_B6_88_E6_81_AF1.broadcast();
          }
        }
      }
    }
  wait(5, msec);
  }
  return 0;
}

// "when I receive none" hat block
void onevent_none_1() {
  leftmoter.stop();
  rightmoter.stop();
}

// "when I receive turnright" hat block
void onevent_turnright_1() {
  leftmoter.stop();
  leftmoter.setVelocity(100.0, percent);
  rightmoter.spin(forward);
}

// "when started" hat block
int whenStarted4() {
  while (true) {
    Vision1.takeSnapshot(Vision1__ROCK);
    if (Vision1.objectCount > 0) {
      Vision1_objectIndex = static_cast<int>(1.0) - 1;
      if (Vision1.objects[Vision1_objectIndex].centerX > 160.0) {
        turnleft.broadcast();
      }
      else {
        if (Vision1.objects[Vision1_objectIndex].centerX < 150.0) {
          turnright.broadcast();
        }
        else {
          none.broadcast();
        }
      }
    }
    wait(0.2, seconds);
  wait(5, msec);
  }
  return 0;
}

// "when I receive turnleft" hat block
void onevent_turnleft_1() {
  rightmoter.stop();
  leftmoter.setVelocity(100.0, percent);
  leftmoter.spin(forward);
}

// "when I receive slow" hat block
void onevent_slow_1() {
  leftmoter.setVelocity(20.0, percent);
  rightmoter.setVelocity(20.0, percent);
  leftmoter.spin(forward);
  rightmoter.spin(forward);
}

// "when I receive stop" hat block
void onevent_stop_1() {
  leftmoter.setVelocity(100.0, percent);
  rightmoter.setVelocity(100.0, percent);
  leftmoter.spin(forward);
  rightmoter.spin(forward);
}

// "when started" hat block
int whenStarted5() {
  while (true) {
    if (down.isNearObject()) {
      Vision1.takeSnapshot(Vision1__ROCK);
      if (leftdis.objectDistance(mm) < 350.0) {
        turnright.broadcastAndWait();
      }
      else {
        if (rightdis.objectDistance(mm) < 350.0) {
          turnleft.broadcastAndWait();
        }
        else {
          if (Inertial12.orientation(pitch, degrees) > 5.0) {
            slow.broadcastAndWait();
          }
          else {
            _E6_B6_88_E6_81_AF1.broadcast();
          }
        }
      }
    }
    else {
      stop.broadcast();
      none.broadcast();
    }
  wait(5, msec);
  }
  return 0;
}

// "when I receive turnleft" hat block
void onevent_turnleft_2() {
  leftmoter.setVelocity(100.0, percent);
  leftmoter.spin(forward);
  rightmoter.stop();
}

// "when I receive turnright" hat block
void onevent_turnright_2() {
  rightmoter.setVelocity(100.0, percent);
  rightmoter.spin(forward);
  leftmoter.stop();
}

// "when I receive _E6_B6_88_E6_81_AF1" hat block
void onevent__E6_B6_88_E6_81_AF1_0() {
  leftmoter.stop();
  rightmoter.stop();
}

// "when I receive none" hat block
void onevent_none_2() {
  while (true) {
    Vision1.takeSnapshot(Vision1__ROCK);
    if (Vision1.objectCount > 0) {
      Vision1_objectIndex = static_cast<int>(1.0) - 1;
      if (Vision1.objects[Vision1_objectIndex].width > 100.0) {
        if (Vision1.objects[Vision1_objectIndex].centerX < 180.0) {
          turnright.broadcastAndWait();
        }
        else {
          turnleft.broadcastAndWait();
        }
      }
      else {
        _E6_B6_88_E6_81_AF1.broadcast();
      }
    }
  wait(5, msec);
  }
}

// "when I receive stop" hat block
void onevent_stop_2() {
  leftmoter.setVelocity(100.0, percent);
  leftmoter.setVelocity(100.0, percent);
  rightmoter.spin(forward);
  leftmoter.spin(forward);
}

// "when I receive slow" hat block
void onevent_slow_2() {
  leftmoter.setVelocity(20.0, percent);
  leftmoter.setVelocity(20.0, percent);
  rightmoter.spin(forward);
  leftmoter.spin(forward);
  wait(0.4, seconds);
  leftmoter.stop();
  rightmoter.stop();
}


int main() {
  // register event handlers
  slow(onevent_slow_0);
  slow(onevent_slow_1);
  slow(onevent_slow_2);
  stop(onevent_stop_0);
  stop(onevent_stop_1);
  stop(onevent_stop_2);
  turnright(onevent_turnright_0);
  turnright(onevent_turnright_1);
  turnright(onevent_turnright_2);
  turnleft(onevent_turnleft_0);
  turnleft(onevent_turnleft_1);
  turnleft(onevent_turnleft_2);
  none(onevent_none_0);
  none(onevent_none_1);
  none(onevent_none_2);
  _E6_B6_88_E6_81_AF1(onevent__E6_B6_88_E6_81_AF1_0);

  wait(15, msec);
  // post event registration

  // set default print color to black
  printf("\033[30m");

  // wait for rotation sensor to fully initialize
  wait(30, msec);

  vex::task ws1(whenStarted2);
  vex::task ws2(whenStarted3);
  vex::task ws3(whenStarted4);
  vex::task ws4(whenStarted5);
  whenStarted1();
}

