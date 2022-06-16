/*
Descripción
1. Ubicamos el sensor ultrasónico en la placa protoboard, tomar en cuenta cómo están y para qué son los pines del sensor.
2. Conectar el pin de Vcc al pin de 5V del arduino, de igual manera el pin de Gnd al pin correspondiente en el arduino.
3. Conectar el pin Trigger al pin digital 12. Y el pin Echo al pin digital bidireccional ~11
AUTOR: RETBOT 
*/

#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
}
// AUTOR: RETBOT 
