// AUTOR: RETBOT 
char blueToothVal; // Variable para la recepción de los datos del Bluetooth
char lastValue; // Variable para mantener el último elemento enviado del Bluetooth
int led = 8;// Pin del LED

void setup() {
  
Serial.begin(115200);// inicializacion de la comunicación serial
Serial.println("Arduino Mega");// Imprime un mensaje en consola
pinMode(led, OUTPUT); // Se pone el pin del led como salida

  while (!Serial)
   {
    ; //espere a que se conecte el puerto serie. Necesario solo para puerto USB nativo
  }
 
while (Serial.read() >= 0) {} // Vaciar el caché del puerto serie
  Serial1.begin(115200);
}

void loop() {
    if(Serial1.available()>0) // Determine si el puerto serie 1 recibe datos (aquí el puerto serie 1 se refiere a TX1 y RX1)
    {
      blueToothVal=Serial1.read(); // Almacena el valor enviado al puerto serial 1
    }
    
   
   if(Serial.available()>0) // Determine si el puerto serie 0 ha recibido datos
    {
      Serial1.write(Serial.read()); // Enviar los datos leídos por el puerto serie 0 al puerto serie 1
    }
    
    if(blueToothVal == 'a'){ // Si el valor recibido es un char 'a' 
      digitalWrite(led, HIGH); //Encendemos el led rojo 
      if(lastValue != 'a') // Si el ultimo valor es diferente a el char de 'a'
         Serial.println(F("Led is on")); // Imprime el mensaje en consola

      lastValue=blueToothVal; // Guarda el último valor recibido 
      
    }else if(blueToothVal == 'b'){ // Si el valor recibido es un char 'b'
      digitalWrite(led, LOW); // apaga el led  
      if(lastValue != 'b') // Si el ultimo valor es diferente a el char de 'b'
         Serial.println(F("Led is Off")); // Imprime el mensaje en consola
         
     lastValue=blueToothVal; // Guarda el último valor recibido 
    }
    delay(100);// Espera 0.1 segundos
}
// AUTOR: RETBOT 