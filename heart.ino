typedef enum {COMPUTING_HR} STATE_T;
/* --------------------------- Symbolic Constants --------------------------- */
// inicializar y declarar variables
typedef struct
{
int current_reading ; // esta variable rastrea el estado del botón, bajo si no se presiona, alto si se presiona
int previous_time  ; // esta variable rastrea el estado del LED, negativo si está apagado, positivo si está encendido
long previous_reading; // la última vez que se alteró el pin de salida
int current_time;
int heart_rate;
STATE_T state;
}
void setup() {
  // put your setup code here, to run once:
   current_reading= previous_reading =LOW;
    previous_time=millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(pin -> state) //la variable a evaluar para el cambio de estado es PIN -> state
{
case COMPUTING_HR: //primer estado
  if (previous_reading ==LOW && current_reading==HIGH ) {
    current_time=millis();
    heart_rate=600000/ (current_time-previous_time);
    current_time=previous_time;
    previous=current;
    current= clean_signal;
    }
    else {
      previous = current;
      current = clean_signal;
      }
}
