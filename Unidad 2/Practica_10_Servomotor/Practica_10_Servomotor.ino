/*
Descripción
Si la posición del servomotor no coincide con el ángulo correspondiente, es porque el ancho del pulso que maneja la librería no coincide con los del servo, para esto es necesario indicarle el ancho de pulso min(para 0°) y el máximo (para 180°), la única modificación sería en la siguiente línea:
myservo.attach(9,900,2100); // asignamos el pin 9 al servo, 900->0° y 2100->180°
AUTOR: RETBOT 
*/
#include Servo myservo; //objeto servo
void setup() {
myservo.attach(9); // ponemos el pin 9 al servo.
Serial.begin(9600); // Inicializamos la comunicación serial a 9600
}
void loop() {
int adc = analogRead(A0); // lectura del potenciómetro
int angulo = map(adc, 0, 1023, 0, 180); // se indica el ángulo, indicado
del potenciómetro.
myservo.write(angulo); // el servomotor gira según lo indicado del
potenciómetro
Serial.print("Angulo: "); // se imprime el ángulo en el monitor
Serial.println(angulo);
delay(10);
}
// AUTOR: RETBOT 