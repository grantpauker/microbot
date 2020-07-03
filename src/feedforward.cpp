#include "feedforward.hpp"

#define SIGN(x) (x >= 0 ? 1 : -1)
Feedforward::Feedforward(float _ks, float _kv, float _ka){
	ks = _ks;
	kv = _kv;
	ka = _ka;
	last_setpoint = 0;
}

float Feedforward::calculate(float setpoint, float dt)
{
	int direction = SIGN(setpoint);
	float accel_setpoint = (setpoint - last_setpoint) / dt;
	float output = (ks * direction) + (kv * setpoint) + (ka * accel_setpoint);
	return output;
}
