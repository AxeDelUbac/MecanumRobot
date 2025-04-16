#include "motorController.h"
#include "motorGearBox.h"

int state = 0;

motorGearBox motorGearBox1(rightBackMotorHigh, rightBackMotorLow, rightBackMotorPWM);
motorGearBox motorGearBox2(leftBackMotorHigh, leftBackMotorLow, leftBackMotorPWM);

void motorController(void) {
    if (Serial.available() > 0)
    {
      state = Serial.parseInt();
      if (state > 0) // avant
      {
        motorGearBox1.setMotorDirection(1,state);
        motorGearBox2.setMotorDirection(1,state);

        Serial.print("Avant ");
      }
      else if (state < 0) // arrière
      {
        motorGearBox1.setMotorDirection(0,state);
        motorGearBox2.setMotorDirection(0,state);

        Serial.print("Arriere ");
      }
      else // Stop (freinage)
      {
        motorGearBox1.stopMotor();
        motorGearBox2.stopMotor();
      }

    }
}