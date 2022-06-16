/*
Descripción:
Se trata de simular un luxómetro.
AUTOR: RETBOT 
*/


// Practica 9. Luxometro sencillo Lux = 500/ResistenciaLDR
double Light (int RawADC0)
{
double Vout=RawADC0*0.0048828125;
int lux=500/(10*((5-Vout)/Vout));//use esta ecuación si el LDR está en la parte superior del divisor
//int lux=(2500/Vout-500)/10;
return lux;
}
void setup() {
Serial.begin(9600);
}
void loop() {
Serial.print("Light Intensity:");
Serial.print(int(Light(analogRead(0)))); //pin A0
Serial.println(" Lux");
delay(1000);
}
//AUTOR: RETBOT 