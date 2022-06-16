/*
Descripción:
En esta práctica se controlará el nivel de voltaje con el potenciómetro. 
Al subir el código a la placa, ubíquese en el IDE de Arduino. 
Seleccione Herramientas/Serial Potter para visualizar el cambio en los niveles de voltaje al mover el vástago del potenciómetro.
AUTOR: RETBOT 
*/

//** Programa **// 
void setup()
{
  // Inicializa la comunicación serial
  Serial.begin(9600);
}

void loop()
{
  // Lee la entrada analógica del pin 0  
  int sensorValue = analogRead(A0);
  // calculo de voltaje = 5.0 Voltaje maximo y 1023 lectura maxima analogica
  float voltage = sensorValue * (5.0/1023.0); 
  Serial.print(voltage);
  Serial.println(" v");
  delay(50);
}
// AUTOR: RETBOT 
