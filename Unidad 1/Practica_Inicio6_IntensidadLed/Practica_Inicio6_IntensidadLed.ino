/*
Descripción:
En esta práctica se controlará la intensidad de luz de un led por medio de una señal de modulación de ancho de pulso.
AUTOR: RETBOT 
*/

//** Definiciones **// 
int led = 9;           // el pin PWM al que está conectado el LED
int brightness = 0;    // qué tan brillante es el LED
int fadeAmount = 5;    // Puntos para desvanecer el LED por

//** Programa **// 
void setup() {
  pinMode(led, OUTPUT); // declara que el pin 9 es una salida
}

void loop() {//bucle a repetir continuamente 
  analogWrite(led, brightness); // establecer el brillo del pin 9
  brightness = brightness + fadeAmount; // cambia el brillo para la próxima vez a través del ciclo

// invertir la dirección del desvanecimiento en los extremos del desvanecimiento
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // espere 30 milisegundos para ver el efecto de atenuación
  delay(30);
}
// AUTOR: RETBOT 
