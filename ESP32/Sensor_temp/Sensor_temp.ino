#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

// LCD RS, E, D4, D5, D6, D7
LiquidCrystal lcd(26, 25, 33, 32, 27, 14);

// Sensor DHT
#define DHTPIN 5
#define DHTTYPE DHT11 // Cambia si es DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  
  dht.begin();
  delay(2000); // Espera tras iniciar sensor
}

void loop() {
  delay(1000); // Da tiempo al sensor

  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer DHT");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error sensor");
    delay(2000);
    return;
  }

  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" - Hum: ");
  Serial.println(humedad);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humedad, 1);
  lcd.print(" %");

  delay(3000);
}
