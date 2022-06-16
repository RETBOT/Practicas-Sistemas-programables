/*
Descripción:
En esta práctica conectará el LED a un puerto digital del Arduino. 
El led se encenderá un segundo y se apagará un segundo repetidamente.
*/

//** Definiciones **// 
int ledRojo = 13; // pin del led rojo 

//** Programa **// 
void setup(){
 
  pinMode(ledRojo, OUTPUT);//declaramos el pin rojo como salida 
}

void loop(){//bucle a repetir continuamente 
  digitalWrite(ledRojo, HIGH); //encendemos el led rojo 
  delay(1000); // espera por 1 segundo
  digitalWrite(ledRojo, LOW); // apaga el led  
  delay(1000); // espera por 1 segundo
}
