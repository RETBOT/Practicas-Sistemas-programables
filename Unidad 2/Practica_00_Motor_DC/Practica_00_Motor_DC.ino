/*
Descripción:
Uso del L293D con motor de DC. Consultar Data Sheet del L293D para mejor comprensión de su funcionamiento. En la siguiente imagen se muestra las funciones de cada pin.
Durante la sesión se explicó el chip L293D tanto su funcionamiento como sus conexiones. Además se explicó cómo conectarlo al motor DC. En seguida se muestran las imágenes que solicitaron de la práctica
AUTOR: RETBOT 
*/
#define ENABLE 5 //Encendido del motor dc
#define SPIN 4 //Giro del motor
void setup() {
pinMode(ENABLE,OUTPUT); // Se selecciona el pin 5 como salida
pinMode(SPIN,OUTPUT); //Se selecciona el pin 4 como salida
digitalWrite(ENABLE,HIGH); // Se activa el motor
}
void loop(){
digitalWrite(SPIN, HIGH); //Se activa el giro del motor
}
// AUTOR: RETBOT 