void setup() {

  pinMode(2, INPUT); //PIn dos como entrada
  pinMode(3, OUTPUT); // pin 3 salida

}

void loop() {
  if  (digitalRead(2) == HIGH){ //evalua si entrada esta a nivel alto
    digitalWrite(3, HIGH);//enciende led
  }
  else{
    digitalWrite(3,LOW);//apaga led
  }

}
