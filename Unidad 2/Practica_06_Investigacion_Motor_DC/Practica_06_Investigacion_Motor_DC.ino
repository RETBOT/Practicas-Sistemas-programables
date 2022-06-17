/*
Descripción:
Se puede utilizar el sensor óptico de barrera o sensores infrarrojos (emisor y receptor, asegúrense que sean de la misma frecuencia) y también pueden utilizar un display LCD (módulo LCD 1602) para desplegar las rpm.
AUTOR: RETBOT 
*/

const int analogInPin = A1; // Pin analogico 1 para la lectura
int sensorValue = 0; // Inicializamos el valor del sensor
int v = 0; // velocidad del motor
void setup() {
// Inicializamos la comunicación serial a 9600 bps:
Serial.begin(9600);
}
void loop() {
// leemos el pin para y asignamos el valor a la variable.
sensorValue = analogRead(analogInPin);
if(sensorValue < 700) {
// Cuando se activa el sensor da lecturas menores a 700
v++;
// Esto se usa para contar las veces que las aspas pasan por el
sensor óptico de barrera, cada que pasa se le suma uno a la
velocidad
}
Serial.print("Velocidad = " );
Serial.println(v/3); // Se calcula la cantidad de vueltas del motor con la
cantidad de vueltas entre 3 (tres aspas del motor)
}
// AUTOR: RETBOT 
