#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <DHT.h>

// --- LCD I2C (dirección 0x27, 16 columnas, 2 filas) ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- WiFi ---
const char* ssid = "Andris";
const char* password = "3158063656";

// --- Sensor DHT ---
#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// --- Web Server ---
WiFiServer server(80);

float temperatura = 0.0;
float humedad = 0.0;

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  dht.begin();

  WiFi.begin(ssid, password);
  lcd.setCursor(0, 1);
  lcd.print("Conectando WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("WiFi conectado: ");
  Serial.println(WiFi.localIP());

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi OK:");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());

  server.begin(); // Inicia el servidor web
}

void loop() {
  temperatura = dht.readTemperature();
  humedad = dht.readHumidity();

  if (!isnan(temperatura) && !isnan(humedad)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatura, 1);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humedad, 1);
    lcd.print(" %");
  }

  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><meta http-equiv='refresh' content='5'>";
    html += "<title>Sensor DHT11</title></head><body>";
    html += "<h1>Lectura del sensor</h1>";
    html += "<p>Temperatura: " + String(temperatura) + " °C</p>";
    html += "<p>Humedad: " + String(humedad) + " %</p>";
    html += "</body></html>";

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println(html);
    client.stop();
  }

  delay(1000);
}
