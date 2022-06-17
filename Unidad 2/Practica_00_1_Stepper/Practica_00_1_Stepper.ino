/*
Descripción:
Los motores paso a paso son ideales para la construcción de mecanismos en donde se requieren movimientos muy precisos. Su característica principal es que se pueden mover de un paso a la vez por cada pulso que se aplique. Esto significa que girará en ángulos de paso discretos.
Este paso puede variar desde 90° hasta pequeños movimientos de 0.72°, es decir, se requerirán 500 pasos para dar el giro completo de 360°. El tamaño mínimo del paso dependerá del motor.
AUTOR: RETBOT 
*/

#include <Stepper.h>
#define STEPS 100
Stepper stepper(STEPS, 8, 9, 10, 11);
int previous = 0;
void setup() {
stepper.setSpeed(30);
}
void loop() {
int val = analogRead(0);
stepper.step(val - previous);
previous = val;
}
// AUTOR: RETBOT 