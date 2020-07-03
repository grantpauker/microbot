#include "motor.hpp"
#include <math.h>

Motor::Motor(int in_1, int in_2, int chan_a, int chan_b)
{
  _in_1 = in_1;
  _in_2 = in_2;
  _chan_a = chan_a;
  _chan_b = chan_b;
}

void Motor::setSpeed(int speed)
{
  bool forwards = speed >= 0;
  speed = abs(speed);
  if (forwards && !_brake_mode)
  {
    analogWrite(_in_1, speed);
    digitalWrite(_in_2, 0);
  }
  else if (forwards && _brake_mode)
  {
    digitalWrite(_in_1, 1);
    analogWrite(_in_2, speed);
  }
  else if (!forwards && !_brake_mode)
  {
    digitalWrite(_in_1, 0);
    analogWrite(_in_2, speed);
  }
  else if (!forwards && _brake_mode)
  {
    analogWrite(_in_1, speed);
    digitalWrite(_in_2, 1);
  }
}

void Motor::stop()
{
  digitalWrite(_in_1, _brake_mode);
  digitalWrite(_in_2, _brake_mode);
}

int Motor::getCounts()
{
  return _counts;
}

float Motor::getAngle()
{
  return _counts * _radpc;
}

void Motor::updateCounts()
{
  int a = digitalRead(_chan_a);
  int b = digitalRead(_chan_b);
  int delta = 0;
  if (b != _last_b)
  {
    delta = (a == b) ? 1 : -1;
  }
  _counts += delta;
  _last_b = b;
}

void Motor::setBrakeMode(bool brake_mode)
{
  _brake_mode = brake_mode;
}

void Motor::setCPR(int cpr)
{
  _cpr = cpr;
  _cprad = _cpr / (2 * M_PI);
  _radpc = 1 / _cprad;
}