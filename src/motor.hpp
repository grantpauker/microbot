#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor
{
public:
  Motor(int, int, int, int);

  void attachEncoder();

  void setSpeed(int);
  void stop();

  void updateCounts();
  
  int getCounts();
  float getAngle();

  void setBrakeMode(bool);
  void setCPR(int);

private:
  int _in_1;
  int _in_2;
  int _chan_a;
  int _chan_b;

  bool _brake_mode = false;

  int _cpr = 0;
  float _cprad = 0;
  float _radpc = 0;

  volatile int _counts;
  volatile int _last_b;

};

#endif