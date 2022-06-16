/*
Descripción:
Se verá el uso de un sensor de inclinación.
AUTOR: RETBOT 
*/

//** Definiciones **// 
int inPin = 3; //Establece el número del pin de entrada (sensor de inclinación)
int reading; //Establece la lectura actual del pin de entrada (sensor de inclinación)
int RedLedPin = 13; //Establece el número del pin de salida del LED rojo
const int SpeakerPin = 7; // Establece el número del pin del altavoz/zumbador

//** Programa **// 
void setup(){
pinMode (inPin, INPUT); //Esto establecerá inPin como ENTRADA
pinMode (RedLedPin, OUTPUT); //Esto establecerá RedLedPin como SALIDA
}

void loop () { //bucle a repetir continuamente 
reading = digitalRead(inPin); //Esto leerá la salida del inPin(sensor de inclinación)
if (reading == 1) { //Si la lectura es 1 o Verdadera
digitalWrite(RedLedPin, HIGH); // si el sensor de inclinación está inclinado, encenderá el LED rojo
tone(SpeakerPin, 494, 500); // si el sensor de inclinación está inclinado, encienda el altavoz
delay(500); //pausa por 0.5 segundos
} else { //si no
digitalWrite(RedLedPin, LOW); //Apaga el LED
}
delay(200); // pausa 200 milisegundos entre lecturas
}
//AUTOR: RETBOT 
