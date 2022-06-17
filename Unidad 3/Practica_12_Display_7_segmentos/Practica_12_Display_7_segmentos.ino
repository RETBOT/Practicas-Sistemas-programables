/*
Descripción
Existen dos tipos de display de 7 segmentos: ánodo común y cátodo común.
AUTOR: RETBOT 
*/
//Practica 12
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
  for(int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
  //Paso 5
  lightSegments(0);
}

void loop() {
  //Paso 6
  for(int i = 0; i < 10; i++) {
    lightSegments(i);
    delay(1000);
  }
}
//Paso 4
void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
}
}
// AUTOR: RETBOT 