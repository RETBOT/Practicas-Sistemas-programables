/*
Descripción
Debe crear una maqueta para que simule la puerta eléctrica de una cochera. Puede utilizar sensores para que la puerta se accione o un botón.
AUTOR: RETBOT 
*/
#include "SR04.h"
#include <Servo.h>
#define TRIG_PIN 12 // cable amarillo
#define ECHO_PIN 11 // cable verde
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a; // distancia
Servo myservo; // crea objeto servo para controlar un servo
bool abierto = false; // Bandera para indicar si el portón está abierto o cerrado.
int rojo = 4; // Led Rojo
int verde = 3; // Led Verde
int SpeakerPin = 7; // Buzzer
void setup() {
myservo.attach(9); // Servo
Serial.begin(9600); // Inicializamos el puerto serial
pinMode(rojo, OUTPUT); // pin del led Rojo como salida
pinMode(verde, OUTPUT); // pin del led Verde como salida
myservo.write(0); // Se reinicia el ángulo del servomotor
digitalWrite(rojo, HIGH); // se Prende el led Rojo
}
void loop() {
a=sr04.Distance(); // Se usa el ultrasónico para ver si tenemos objetos
cercanos
Serial.print(a); // Distancia del objeto más cercano
Serial.println("cm");
if(a < 10 && abierto == false){ // Si el objeto está a 10 cm, la puerta se va a
abrir
Serial.println("Abrir");
digitalWrite(verde, HIGH); // Se prende el led Verde
digitalWrite(rojo, LOW); // Se apaga el led Rojo
for(int i = 0;i<=180; i+=20){// Se abre el portón en ángulo de 20 en 20
myservo.write(i);
delay(500);
tone(SpeakerPin, 1000, 500); // Suena el buzzer
}
abierto = true; // Se indica que el portón está abierto
delay(4000); Retraso de 4 seg
}else if(a > 10 && abierto == true){ // Si el objeto está a más de 10 cm, la
puerta se va a cerrar
Serial.println("Cerrar");
digitalWrite(rojo, HIGH); // se prende el led Rojo
digitalWrite(verde, LOW); // se apaga el led Verde
for(int i = 180;i>=0; i-=20){ // Se cierra el portón en ángulo de 20 en 20
myservo.write(i);
delay(500);
tone(SpeakerPin, 500, 500); // Suena el buzzer
}
abierto = false; // Se indica que el portón está cerrado
}
delay(100);
}
// AUTOR: RETBOT 