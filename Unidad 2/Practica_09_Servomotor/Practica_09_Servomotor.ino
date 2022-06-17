/*
Descripción
El servomotor se controla por medio de pulsos eléctricos con periodo de 20ms y el ancho del pulso le indican al Arduino a qué posición se debe de mover.
En general, en todos los modelos:
• Un pulso entre 500-1000 ms corresponde con 0 grados.
• Un pulso de 1500 ms corresponde con 90 grados (punto neutro)
• Un pulso entre 2000-2500 ms corresponde con 180 grados.
AUTOR: RETBOT 
*/
#include Servo myservo;
int pos = 0; // posición de inicio del servomotor
void setup() {
myservo.attach(9); // pin del servo
Serial.begin(9600); // Inicializamos la comunicación serial a 9600
}
void loop() {
for (pos = 0; pos <= 180; pos += 1) { // inicia en el ángulo 0 y termina
hasta llegar al ángulo 180 del servomotor
myservo.write(pos);
delay(15);
}
for (pos = 180; pos >= 0; pos -= 1) { // inicia en el ángulo 180 y
termina hasta llegar al ángulo 0
degrees myservo.write(pos);
delay(15);
}
}