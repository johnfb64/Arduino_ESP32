void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT); //PIN 13 output

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); //Pin 13 high leve (l)
  delay(3000); // Delay 1 sec. 
  digitalWrite(13, LOW); //Pin 13 low level (0)
  delay(3000);

}
