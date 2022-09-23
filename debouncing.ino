typedef enum {FOLLOWING_INPUT, IGNORE_INPUT} STATE_T;
/* --------------------------- Symbolic Constants --------------------------- */
// inicializar y declarar variables

const int pin = 13; // PULSADOR adjunto a este pin
const int pout = 2; // LED adjunto a este pin
int current_reading ; // esta variable rastrea el estado del botón, bajo si no se presiona, alto si se presiona
int previous_time  ; // esta variable rastrea el estado del LED, negativo si está apagado, positivo si está encendido
long previous_reading; // la última vez que se alteró el pin de salida
long extinction ; // el tiempo de rebote; aumentar si la salida parpadea
STATE_T state;

/*********** Setup Function ************/
void setup()
{
  // establece el modo de los pines ...
  pinMode (pout, OUTPUT);
  pinMode (pin, INPUT);
} // cerrar configuración de vacío
/*********** Loop Function ************/
void loop()
  // muestra el estado del botón - ¿está presionado o no?
  previous_reading = current_reading = digitalRead (pin);
  digitalWrite (pin, current_reading );
  extinction =50;
  switch(state) //la variable a evaluar para el cambio de estado
{
case FOLLOWING_INPUT: //primer estado
  if (previous_reading == current_reading ) {
    previous_reading = current_reading;
    current_reading = digitalRead (pin);
    state = FOLLOWING_INPUT;
    }
    else {
      digitalWrite(disp, current_reading);
      previous_time = millis();
      pin -> state = IGNORE_INPUT;
      }
case IGNORE_INPUT:
     if (millis() - previous_time >= extinction){
    previous_reading = current_reading;
  current_reading = digitalRead( pin );
  pin state = FOLLOWING_INPUT;
     }
     else {
      state = IGNORE_INPUT;
     }
     }
} 
