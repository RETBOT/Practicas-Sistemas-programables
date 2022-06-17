/*
Descripción:
Utilizar el sensor óptico de barrera o sensores infrarrojos (emisor y receptor, asegúrense que sean de la misma frecuencia). Una vez detectado la interrupción del haz de luz en los sensores, el motor deberá girar en sentido contrario. Pueden fijar una velocidad baja, luego que se detenga y enseguida que gire de forma contraria.
AUTOR: RETBOT 
*/

#define ENABLE 5 //Cable amarillo
#define SPIN1 4 //Cable verde
#define SPIN2 3 //Cable azul
const int analogInPin = A1; // Pin analogico 1 para la lectura
int sensorValue = 0; // Inicializamos el valor del sensor
bool estatus = true; // se crea la bandera para indicar el estado del motor (giro del motor)
void setup() {
// Inicializamos la comunicación serial a 9600 bps:
Serial.begin(9600);
pinMode(ENABLE,OUTPUT); // Se le indica las salidas que tendrá el motor
pinMode(SPIN1,OUTPUT);
pinMode(SPIN2,OUTPUT);
digitalWrite(ENABLE,HIGH); // Se activa el motor
}
void loop() {
// leemos el pin para y asignamos el valor a la variable.
sensorValue = analogRead(analogInPin);
Serial.println(sensorValue);
if(sensorValue > 300){ // dependiendo de los valores que del sensor de
barrera será el giro
estatus = false;
}else{
estatus = true;
}
if(estatus){
digitalWrite(SPIN1, HIGH);
digitalWrite(SPIN2, LOW);
}
else{
digitalWrite(SPIN1, LOW);
digitalWrite(SPIN2,HIGH);
}
}
// AUTOR: RETBOT 