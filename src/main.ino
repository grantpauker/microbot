#include "motor.hpp"
/*
red    - M1
black  - M2
blue   - VCC
yellow - CHAN A
white  - CHAN B
green  - GND
*/
#define A_IN_1 5
#define A_IN_2 6
// #define B_IN_1 5
// #define B_IN_2 6

#define A_CHAN_A 3
#define A_CHAN_B 4
// #define B_CHAN_A 9
// #define B_CHAN_B 10

#define CPR_LEFT 452
// #define CPR_RIGHT 452

Motor motor_left = Motor(A_IN_1, A_IN_2, A_CHAN_A, A_CHAN_B);
// Motor motor_right = Motor(B_IN_1, B_IN_2, B_CHAN_A, B_CHAN_B);
void motorLeftUpdate()
{
    motor_left.updateCounts();
}
// void motorRightUpdate()
// {
//     motor_right.updateCounts();
// }
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(A_IN_1, OUTPUT);
    pinMode(A_IN_2, OUTPUT);
    // pinMode(B_IN_1, OUTPUT);
    // pinMode(B_IN_2, OUTPUT);

    pinMode(A_CHAN_A, INPUT);
    pinMode(A_CHAN_B, INPUT);
    // pinMode(B_CHAN_A, INPUT);
    // pinMode(B_CHAN_B, INPUT);

    attachInterrupt(digitalPinToInterrupt(A_CHAN_A), motorLeftUpdate, CHANGE);
    // attachInterrupt(digitalPinToInterrupt(B_CHAN_A), motorRightUpdate, CHANGE);

    motor_left.setCPR(CPR_LEFT);
    // motor_left.setCPR(CPR_RIGHT);
    Serial.begin(115200);
}
int i = 0;
void loop()
{
    
    motor_left.setSpeed(i);
    // // motor_right.setSpeed(30);
    motor_left.getCounts();
    // Serial.print(' ');
    // Serial.println(motor_right.getCounts());
    i+=1;
    if(i >= 255){
        i = 0;
    }
    Serial.println(i);
    delay(500);
}