#include "movementController.h"
#include <Arduino.h>



movementController::movementController()
    : 
    rightFrontMotor(100, 101, 102),
    leftFrontMotor(200, 201, 202),
    rightBackMotor(rightBackMotorHigh, rightBackMotorLow, rightBackMotorPWM),
    leftBackMotor(leftBackMotorHigh, leftBackMotorLow, leftBackMotorPWM) {}

void movementController::setDirection(int Xaxis, int Yaxis){
    int speed = 100;
    if (Xaxis == 0 && Yaxis == 1) { // Avant
        this->rightFrontMotor.setMotorDirection(1, speed);
        this->leftFrontMotor.setMotorDirection(1, speed);
        this->rightBackMotor.setMotorDirection(1,speed);
        this->leftBackMotor.setMotorDirection(1,speed);
    } else if (Xaxis == 0 && Yaxis == -1) { // Arrière
        this->rightFrontMotor.setMotorDirection(0, speed);
        this->leftFrontMotor.setMotorDirection(0, speed);
        this->rightBackMotor.setMotorDirection(0,speed);
        this->leftBackMotor.setMotorDirection(0, speed);
    } else if (Xaxis == 1 && Yaxis == 0) { // Droite
        this->rightFrontMotor.setMotorDirection(1, speed);
        this->leftFrontMotor.setMotorDirection(0, speed);
        this->rightBackMotor.setMotorDirection(0,speed);
        this->leftBackMotor.setMotorDirection(1, speed);
    } else if (Xaxis == -1 && Yaxis == 0) { // Gauche
        this->rightFrontMotor.setMotorDirection(1, speed);
        this->leftFrontMotor.setMotorDirection(0, speed);
        this->rightBackMotor.setMotorDirection(0,speed);
        this->leftBackMotor.setMotorDirection(1, speed);
    }
}

void movementController::setRotation(){
    int speed = 100;
    int Xaxis; // Exemple de valeur pour Xaxis
    int Yaxis; // Exemple de valeur pour Yaxis

    if (Xaxis == 1 && Yaxis == 1) { // Rotation droite
        this->rightFrontMotor.setMotorDirection(1, speed);
        this->leftFrontMotor.setMotorDirection(0, speed);
        this->rightBackMotor.setMotorDirection(1,speed);
        this->leftBackMotor.setMotorDirection(0, speed);
    } else if (Xaxis == -1 && Yaxis == -1) { // Rotation gauche
        this->rightFrontMotor.setMotorDirection(0, speed);
        this->leftFrontMotor.setMotorDirection(1, speed);
        this->rightBackMotor.setMotorDirection(0,speed);
        this->leftBackMotor.setMotorDirection(1, speed);
    }
}
  
void movementController::stopMovement(){  
    this->rightBackMotor.stopMotor();
    this->leftBackMotor.stopMotor();
    this->rightFrontMotor.stopMotor();
    this->leftFrontMotor.stopMotor();
}