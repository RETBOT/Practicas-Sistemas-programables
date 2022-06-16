/*
Descripción:
En esta práctica se controlará la secuencia de encendido de cada LED
*/

//** Definiciones **// 
int verde=13; //definimos el valor del pin para el led verde 
int amarillo=9; //definimos el valor del pin para el led amarillo 
int rojo=5; //definimos el valor del pin para el led rojo 

//** Programa **// 
void setup() { //declaraciones 
pinMode(verde,OUTPUT); //declaramos el pin verde como salida 
pinMode(amarillo,OUTPUT);//declaramos el pin amarillo como salida 
pinMode(rojo,OUTPUT); //declaramos el pin rojo como salida 
} 

void loop() { //bucle a repetir continuamente 
digitalWrite(verde,HIGH); //encendemos el led verde 
delay(1000); //esperamos 1 segundo 
digitalWrite(verde,LOW); //apagamos el led verde 
delay(250); //esperamos 0,250 segundos 

digitalWrite(amarillo,HIGH); //encendemos el led amarillo 
delay(1000); //esperamos 1 segundo
digitalWrite(amarillo,LOW); //apagamos el led amarillo 
delay(250); //esperamos 0,250 segundos 

digitalWrite(rojo,HIGH); //encendemos el led rojo 
delay(1000); //esperamos 1 segundo
digitalWrite(rojo,LOW); //apagamos el led rojo 
delay(250); //esperamos 0,250 segundos 
}
