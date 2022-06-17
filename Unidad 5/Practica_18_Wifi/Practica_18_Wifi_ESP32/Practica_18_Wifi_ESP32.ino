// AUTOR: RETBOT 
// Librería para ESP32 WiFi 
#include "WiFi.h"

// Nombre de la red WiFi
const char* ssid = "ESP32";
// Contraseña
const char* password = "ESP32";

void setup() {
 //  Inicialización de la comunicación serial  
  Serial.begin(115200);
  Serial.println("ESP32");
  // Conexión a la red WiFi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) { // Conectando a la red 
    delay(500); 
    Serial.println("Conectando a Wi-Fi..");
  }
 // Conexión exitosa
  Serial.println("Conectado a la red Wi-Fi");
}
 
void loop() {}
// AUTOR: RETBOT 