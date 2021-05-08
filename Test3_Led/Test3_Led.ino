int BOTON = 2; //pulsador
int LED = 3;
int ESTADO = LOW;
void setup() {

  pinMode(BOTON, INPUT); //PIn dos como entrada
  pinMode(LED, OUTPUT); // pin 3 salida

}

void loop() {
  while  (digitalRead(BOTON) == LOW){    //evalua si entrada esta a nivel alto
   
   }
  ESTADO = digitalRead(LED); //lee estado led
  digitalWrite(LED, !ESTADO); //escribe valor contrario
  while(digitalRead(BOTON) == HIGH){ //antirebote
    
  }
} 
