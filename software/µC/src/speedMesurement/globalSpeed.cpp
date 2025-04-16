#include "globalSpeed.h"
#include "encoderParameter.h"
#include <Arduino.h>

float globalSpeed::getGlobalSpeedKmh(){

    /*this->meanGlobalAngularSpeed= ((rotaryEncoderBackLeft.getMeanSpeedRpm +
                                    rotaryEncoderBackRight.getMeanSpeedRpm +
                                    rotaryEncoderFrontLeft.getMeanSpeedRpm +
                                    rotaryEncoderFrontRight.getMeanSpeedRpm
                                    )/4);*/

    return this->meanGlobalAngularSpeed;
  }