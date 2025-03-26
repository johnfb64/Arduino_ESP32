#include <DHT.h>
#include <LiquidCrystal.h>

// Pines del LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(26, 25, 33, 32, 27, 14);

// Configuración del sensor DHT
#define DHTPIN 5         // Pin de datos del sensor
#define DHTTYPE DHT11    // Cambia a DHT11 si tienes ese modelo

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  
  dht.begin();
  delay(2000);
}

void loop() {
  delay(1000);
  float temperatura = dht.readTemperature(); // °C
  float humedad = dht.readHumidity();        // %
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" - Hum: ");
  Serial.println(humedad);

  if (isnan(temperatura) || isnan(humedad)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error sensor");
    delay(2000);
    return;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1); // 1 decimal
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humedad, 1);
  lcd.print(" %");

  delay(3000); // Espera antes de actualizar
}
