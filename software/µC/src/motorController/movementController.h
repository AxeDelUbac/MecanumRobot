#ifndef DIRECTIONCONTROLLER_H
#define DIRECTIONCONTROLLER_H

#include "motorGearBox.h"
#include "main.h"

class movementController {
    public:

        movementController();

        void setDirection(int Xaxis, int Yaxis);
        void setRotation();
        void stopMovement(); // Stoppe le moteur

    private:

        motorGearBox rightBackMotor;
        motorGearBox leftBackMotor;
        motorGearBox rightFrontMotor;
        motorGearBox leftFrontMotor;

};

#endif