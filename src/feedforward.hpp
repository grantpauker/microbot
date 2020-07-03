#ifndef FEEDFORWARD_H
#define FEEDFORWARD_H

#include "Arduino.h"

class Feedforward
{
public:
  Feedforward(float, float, float);

  float calculate(float, float);

private:
  float ks;
  float kv;
  float ka;

  float last_setpoint;
};

#endif
