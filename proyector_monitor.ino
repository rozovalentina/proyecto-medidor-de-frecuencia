# include <SevenSeg.h> // incluimos la librería para nuestro display

String datos;  // en esta variable se almacenan los numero a mostrar o letras.

SevenSeg disp(2,3,4,5,6,7,8); //declaramos nuestro display y definimos sus pines
//            A,B,C,D,E,F,G

 const int numOfDigits =4; // definimos el numero de dígitos de nuestro display

 int digitPins [numOfDigits]={13,12,11,10}; // los pines para cada Digito
//                            D1,D2,D3,D4
 
void setup(){
 Serial.begin(9600);  //configuramos nuestro puerto serie
 disp.setDigitPins (numOfDigits ,digitPins); //Configuramos el display
}
 void loop () {
while(Serial.available() != 0){
datos = Serial.readString();   //si hay datos en el puerto se leen y almacenan el la variable
}
disp.write(datos);  // mostramos los números o letras en el display
}
