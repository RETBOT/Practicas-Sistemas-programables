/*
Descripción
El botón puede controlar las velocidades de la ruleta.
AUTOR: RETBOT 
*/
//Practica 14 
#define BOTON 13

// boton 
int   anterior;      // guardamos el estado anterior del boton.
int   estado;        // el estado del botón.
unsigned long temporizador;
unsigned long tiemporebote = 50;

int velocidad = 0;

const int pins[7] = { 8,7,6,5,4,3,2 };

const byte numbers[3] = {0b1111110,
                         0b1010000,
                         0b1101101};
                                   
const byte DisplayAnode[6] = {0b0000010, //
                              0b0100000, //
                              0b1000000, //
                              0b0010000, //
                              0b0000100, //
                               0b0001000};//
                                      
void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(BOTON, INPUT);
  estado = HIGH;
  anterior = HIGH;
  lightSegmentsNum(0);
}

void loop() {
  estadoBoton();
 for(int i=0; i<6; i++){
    if(velocidad == 1){
      estadoBoton();
      Serial.println("Opc 1");
      lightSegments(i);
      delay(100);
    }else if(velocidad == 2){
      estadoBoton();
      Serial.println("Opc 2");
      lightSegments(i);
      delay(50);
     }
   }
 }

void lightSegments(int number) {
  byte numberBit = DisplayAnode[number];
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
  }
}

void lightSegmentsNum(int number) {
  byte numberBit = numbers[number];
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
    Serial.print("Velocidad :");
    if(velocidad == 0){
      velocidad = 1;
      lightSegmentsNum(1);
      delay(500);
    }else if(velocidad == 1){
      velocidad = 2;
      lightSegmentsNum(2);
      delay(500);
    }else if(velocidad == 2){
      velocidad = 0;
      lightSegmentsNum(0);
      delay(500);
      }
    Serial.println(velocidad);
  }
  anterior = estado;
}
// AUTOR: RETBOT 