#ifndef GLOBALSPEED_H
#define GLOBALSPEED_H

#include "rotaryEncoder.h"

class globalSpeed {
    public:
        float getGlobalSpeedKmh(); // Retourne la vitesse en km/h
        float getGlobalSpeedRpm(); // Retourne la vitesse en RPM

    private:
        float meanGlobalAngularSpeed; // Vitesse angulaire en RPM
        float meanGlobalLinearSpeed; // Vitesse linéaire en km/h

        rotaryEncoder rotaryEncoderFrontRight;
        rotaryEncoder rotaryEncoderFrontLeft;
        rotaryEncoder rotaryEncoderBackRight;
        rotaryEncoder rotaryEncoderBackLeft;

};

#endif
