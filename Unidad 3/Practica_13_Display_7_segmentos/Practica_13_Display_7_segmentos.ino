/*
Descripción
Con el botón se controlará el despliegue de números en el display.
1. Leemos el botón
  1. Si está en estado alto
    1. Obtenemos número aleatorio
    2. Mostramos el número en el display
    3. Esperamos un tiempo hasta permitir otra pulsación
2. Si está en estado bajo
  1. No hacemos nada
AUTOR: RETBOT 
*/

//Practica 13
#define BOTON 13
// boton 
int   anterior;      // guardamos el estado anterior del boton.
int   estado;        // el estado del botón.
unsigned long temporizador;
unsigned long tiemporebote = 50;

bool bandera = false;


const int pins[7] = { 8,7,6,5,4,3,2 };
//Paso 2
const byte numbersDisplayAnode[10] = {0b1111110, //0
                                      0b1010000, //1
                                      0b1101101, //2
                                      0b1110101, //3
                                      0b1010011, //4
                                      0b0110111, //5
                                      0b0111111, //6
                                      0b1110000, //7
                                      0b1111111, //8
                                      0b1110111}; //9
                                      
void setup() {
  //Paso 3
  Serial.begin(9600);
  for(int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(BOTON, INPUT);
  //Establecemos semilla para números aleatorios
  randomSeed(analogRead(A0));
  lightSegments(0);
}

void loop() {
  // Leemos el valor del boton
   estadoBoton();
  if (bandera){
    //Genera un numero aleatorio entre 1 y 9
    int randomNumber = random(1, 10);
    lightSegments(randomNumber);
 }
 bandera = false;
 delay(100);
}

void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
}
}

void estadoBoton(){
// Leemos el valor del boton
  if ( estado==digitalRead(BOTON) ) {
    temporizador = 0;
  }else if(temporizador == 0){
    temporizador = millis();
  }else if(millis()-temporizador > tiemporebote ){
    estado = !estado;  
  }

  if ( anterior==HIGH && estado==LOW ) {
    bandera = true;
    Serial.println(bandera);
  }
  anterior = estado;
}
// AUTOR: RETBOT 