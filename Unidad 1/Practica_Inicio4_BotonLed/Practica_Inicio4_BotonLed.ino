/*
Descripción:
En esta práctica se controlará el encendido del LED con el botón. El led deberá encender siempre que el botón esté presionado. Y cuando se suelte, el led debe apagarse.
AUTOR: RETBOT 
*/

//** Definiciones **// 
const int buttonPin = 2;     // pin del pushbutton 
const int ledPin =  13;      // pin del led rojo 
   
int buttonState = 0;         // variable para la lecutra del pushbutton

//** Programa **// 
void setup() {
  pinMode(ledPin, OUTPUT); //declaramos el pin ledPin como salida 
  pinMode(buttonPin, INPUT); //declaramos el buttonPin como entrada
}

void loop() { //bucle a repetir continuamente 
  // lectura de entrada del pushbutton
  buttonState = digitalRead(buttonPin);

  // comprobar si el pulsador está pulsado. Si es así, el estado del botón es HIGH:
  if (buttonState == HIGH) {
   // enciende el LED:
    digitalWrite(ledPin, HIGH);
  } else {
   // apaga el LED:
    digitalWrite(ledPin, LOW);
  }
}
// AUTOR: RETBOT 
