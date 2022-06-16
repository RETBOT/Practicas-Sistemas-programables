/*
Descripción
1. Conectamos el sensor de temperatura a la protoboard, teniendo el lado plano del sensor de frente realizamos las conexiones de la siguiente forma:
    1. El pin izquierdo lo conectamos a 5v.
    2. El pin derecho lo conectamos a tierra.
    3. El pin central lo conectamos a cualquier pin analógico de nuestro Arduino (el pin A0 en nuestro caso).
2. Conectamos dos LEDs de distintos colores, agregamos una resistencia a cada LED en la parte plana que vaya a tierra.
3. El otro pin del LED lo conectamos uno al 3 y 5 que son los que tienen funcionalidad PWM.
4. Conectamos los cables de tierra y 5V de la Arduino a la protoboard.
5. Cargamos el código.
AUTOR: RETBOT 
*/

//** Definiciones **// 
const int sensor = 0; // entrada del sensor LM35
const int ledRojo = 5; // pin del LED rojo
const int ledAzul = 3; // pin del LED azul

long miliVolts;
long temperatura;
int brillo;

long calctemp(int datosSensor){
  /*Calculamos los mV en la entrada*/
  miliVolts = (analogRead(datosSensor) * 5000L) / 1023; 
  /* Calculamos la temperatura*/
  temperatura = miliVolts / 10;
  /*Regresamos el valor de temperatura*/
  return temperatura;
}

//** Programa **// 
void setup () {
  Serial.begin(9600); // iniciamos la comunicacion serial
  /*Declaramos los LEDs como salida*/
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}
void loop () {//bucle a repetir continuamente 
  /*Llamamos a la función para calcular temperatura
   y guardamos el valor*/
  temperatura = calctemp(sensor);

  /*Ajustamos la escala de temperatura para poder usar analoWrite*/
  brillo = map(temperatura, 24,29, 0, 255);
  /*Restringimos el rango de brillo entre 0 y 255*/
  brillo = constrain(brillo, 0, 255);

  /*Ajustamos el color de los LED*/
  analogWrite(ledRojo, (250 - brillo));
  analogWrite(ledAzul, brillo);

  /*Mandamos el valor de la temperatura al monitor serial
  y agregamos un delay para no saturar el monitor*/
  Serial.print("Temperatura: "); 
  Serial.print(temperatura);
  Serial.println("grados");
  delay(200);
}
// AUTOR: RETBOT 