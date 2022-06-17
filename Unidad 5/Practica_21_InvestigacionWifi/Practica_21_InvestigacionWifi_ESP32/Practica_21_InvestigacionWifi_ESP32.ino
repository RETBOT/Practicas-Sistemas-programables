// Librería para ESP32 WiFi 
#include "WiFi.h"

// Nombre de la red WiFi
const char* ssid = "ESP32";
// Contraseña
const char* password = "ESP12345678";

//numero de puerto 
WiFiServer server(80);

//almacen de http 
String header;

//estados de salida
String output26State = "off";
String output27State = "off";

// Tiempo actual
unsigned long currentTime = millis();
// Tiempo anterior 
unsigned long previousTime = 0;
// Define el tiempo de espera en milisegundos (ejemplo: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);

  // conecta a la red Wi-Fi con SSID y contraseña
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // imprime la dirección IP local e inicie el servidor web
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  
  WiFiClient client = server.available();   // Escucha los clientes entrantes

  if (client) {                             // Si un nuevo cliente se conecta
    currentTime = millis();
    previousTime = currentTime;
    String currentLine = "";                // hacer una cadena para contener los datos entrantes del cliente
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // Ciclo mientras el cliente está conectado
      currentTime = millis();
      if (client.available()) {             // Si hay bytes para leer del cliente,
        char c = client.read();             // lee un byte, entonces
        header += c;
        if (c == '\n') {                    // si el byte es un carácter de nueva línea
          // si la línea actual está en blanco, tienes dos caracteres de nueva línea seguidos. 
          // ese es el final de la solicitud HTTP del cliente, para enviar una respuesta:
          if (currentLine.length() == 0) {
            // Los encabezados HTTP siempre comienzan con un código de respuesta (por ejemplo, HTTP/1.1 200 OK)
             // y un tipo de contenido para que el cliente sepa lo que viene, luego una línea en blanco:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // enciende y apaga los GPIO
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("a");
              output26State = "on";
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("b");
              output26State = "off";
            } else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("c");
              output27State = "on";
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("d");
              output27State = "off";
            }

            // Muestra la página web HTML
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS para diseñar los botones de encendido/apagado
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            // Encabezado de la página web
            client.println("<body><h1>ESP32_RETBOT</h1>");

            // Muestra el estado actual y los botones ON/OFF para GPIO 26
            client.println("<p>GPIO Rojo - State " + output26State + "</p>");
            // Si output26State está apagado, muestra el botón ON
            if (output26State == "off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Muestra el estado actual y los botones ON/OFF para GPIO 27
            client.println("<p>GPIO Verde - State " + output27State + "</p>");
            // Si output27State está apagado, muestra el botón ON
            if (output27State == "off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            // La respuesta HTTP termina con otra línea en blanco
            client.println();
            // Salir del ciclo while
            break;
          } else { // si tiene una nueva línea, borra la línea actual
            currentLine = "";
          }
        } else if (c != '\r') {  // si obtuvo algo más que un carácter de retorno de carro,
          currentLine += c;      // agregarlo al final de currentLine
        }
      }
    }
    // Borrar la variable de encabezado
    header = "";
    // Cierra la conexión
    client.stop();
  }
}
