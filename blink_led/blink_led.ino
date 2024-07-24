
/*Descripción: digitalWrite() es una funcion que permite el linkeo de leds y se compone de 2 parametros:
 * Numero de pin de la placa: ejemplo 13. 
 * binario High o Low. 
 */

//variables

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); //mayor nivel de voltaje. encendido. 
  delay(1000);//tiempo, donde 1000 = 1s. 
  digitalWrite(LED_BUILTIN, LOW); //Menor nivel de voltaje. Apagado. 
  delay(1000);
}
