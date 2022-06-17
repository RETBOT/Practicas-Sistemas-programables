/*
Descripción
Programar un barrido continuo de 0 a 180 grados en un servo. 
Activar y desactivar el barrido con una pulsación de un botón. 
Un ejemplo, limpiaparabrisas. 
Hacer tres velocidades de barrido: cada pulsación sube de velocidad y la cuarta lo detiene.
AUTOR: RETBOT 
*/
#include Servo myservo;
const int controlPin = 2;
int velocidad = 0;
int pulsacion = 0;
int estado_boton;
int estado_boton_anterior;
int pos = 0;
void setup() {
Serial.begin(9600); myservo.attach(9);
myservo.write(20);
pinMode(controlPin, INPUT_PULLUP);
estado_boton_anterior = digitalRead(controlPin);
}
void loop() {
detecta_pulsacion();
if (pulsacion > 0) {
for (pos = 20; pos <= 160; pos += 5) {
myservo.write(pos);
delay(velocidad);
detecta_pulsacion();
}
for (pos = 160; pos >= 20; pos -= 5) {
degrees myservo.write(pos);
delay(velocidad);
detecta_pulsacion();
}
}
}
void detecta_pulsacion() {
estado_boton = digitalRead(controlPin) //Detección pulsación boton
if (estado_boton != estado_boton_anterior) {
if (estado_boton == HIGH) {
Serial.println("Nueva pulsacion");
pulsacion++;
switch (pulsacion) {
case 1: velocidad = 30;break;
case 2: velocidad = 20; break;
case 3: velocidad = 10; break;
case 4: pulsacion = 0; break;
}
}
}
estado_boton_anterior = estado_boton;
}
// AUTOR: RETBOT 