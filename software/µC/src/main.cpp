#include <Arduino.h>
#include <STM32FreeRTOS.h>
#include "main.h"

#include "motorController/motorController.h"
#include "motorController/movementController.h"
#include "speedMesurement/rotaryEncoder.h"

void UartTask(void *pvParameters);
void MotorTask(void *pvParameters);
void speedMesurementTask(void *pvParameters);
void displayInformationTask(void *pvParameters);

void task_create(void);

void task_create(void){
  Serial.println("Init FreeRTOS Task...");
  // Créer deux tâches
  xTaskCreate(UartTask, "UartTask", 256, NULL, 1, NULL);
  xTaskCreate(MotorTask, "MotorTask", 256, NULL, 1, NULL);
  xTaskCreate(speedMesurementTask, "rotaryEncoderTask", 256, NULL, 1, NULL);
  xTaskCreate(displayInformationTask, "displayInformationTask", 256, NULL, 1, NULL);

  Serial.println("Done");
}

volatile unsigned int nombreTours = 0;
volatile unsigned int nombreTours2 = 0;

HallSensor hallSensor1;
rotaryEncoder rotaryEncoder1;
movementController movementController1;

HardwareSerial Serial2(PD6, PD5);

void compterTour() {
  nombreTours++;
}

void compterTour2() {
  nombreTours2++;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(rightBackMotorHigh, OUTPUT);
  pinMode(rightBackMotorLow, OUTPUT);
  pinMode(rightBackMotorPWM, OUTPUT);
  pinMode(rightBackFirstHallSensor, INPUT);
  pinMode(rightBackSecondHallSensor, INPUT);

  pinMode(leftBackMotorHigh, OUTPUT);
  pinMode(leftBackMotorLow, OUTPUT);
  pinMode(leftBackMotorPWM, OUTPUT);

  Serial.begin(115200);


  Serial2.begin(9600);

  delay(1000); // Laisse le temps au port série de s'initialiser

  attachInterrupt(digitalPinToInterrupt(rightBackFirstHallSensor), compterTour, FALLING); // Détection du front descendant
  attachInterrupt(digitalPinToInterrupt(rightBackSecondHallSensor), compterTour2, FALLING); // Détection du front descendant

  task_create();
  // Démarrer le scheduler FreeRTOS
  vTaskStartScheduler();

}

void loop() {
  // put your main code here, to run repeatedly:
  /*Serial.println("Ahah");
  delay(100);*/
}

void UartTask(void *pvParameters) {
  (void) pvParameters;
  while (1) {
    Serial2.println("Hello from UartTask");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

  // ---------- Tâche 2 ----------
  void MotorTask(void *pvParameters) {
    (void) pvParameters;
    while (1) {

      motorController();

      vTaskDelay(pdMS_TO_TICKS(200));
    }
  }

  float vitesse = 0;
  void speedMesurementTask(void *pvParameters) {
    (void) pvParameters;
    while (1) {

      vitesse = rotaryEncoder1.getMeanSpeedKmh(nombreTours, nombreTours2);
      nombreTours = 0;
      nombreTours2 = 0;


      vTaskDelay(pdMS_TO_TICKS(1000));
    }
  }

  void displayInformationTask(void *pvParameters) {
    (void) pvParameters;
    while (1) {

      /*Serial.print("Encodeur1= ");
      Serial.println(nombreTours);
      Serial.print("Encodeur2= ");
      Serial.println(nombreTours2);*/
      Serial.print("La vitesse en km/h = ");
      Serial.println(vitesse),3;

      vTaskDelay(pdMS_TO_TICKS(1000));
    }
  }