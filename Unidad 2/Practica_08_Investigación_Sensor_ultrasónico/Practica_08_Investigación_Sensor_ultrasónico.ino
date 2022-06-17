/*
Descripción
Utilizar el sensor ultrasónico para medir la distancia y se debe desplegar en el display. El potenciómetro ayudará a regular el contraste del display.
AUTOR: RETBOT 
*/
#include "SR04.h"
#include <LiquidCrystal.h>
#define TRIG_PIN 10
#define ECHO_PIN 9
#define COLS 16 // Columnas del LCD
#define ROWS 2 // Filas del LCD
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
// Lo primero es inicializar la librería indicando los pins de la interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
Serial.begin(9600);
delay(1000);
// Configuramos las filas y las columnas del LCD en este caso 16 columnas
y 2 filas
lcd.begin(COLS, ROWS);
}

void loop() {
// Limpiamos la pantalla
lcd.clear();
// Situamos el cursor en la columna 0 fila 0
lcd.setCursor(0,0);
// Distancia indicada del ultrasonico
a=sr04.Distance();
lcd.print(a); // se imprime en el lcd
lcd.print(" cm");
Serial.print(a); // se imprime en el monitor
Serial.print(" cm");
delay(100);
}
// AUTOR: RETBOT 