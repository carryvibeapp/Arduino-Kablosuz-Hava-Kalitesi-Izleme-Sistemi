#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <RF24.h>
#include <LiquidCrystal_I2C.h>

#define CE_PIN   9
#define CSN_PIN 10
#define ALARM_PIN 11

RF24 radio(CE_PIN, CSN_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

struct SensorData {
  float temperature;
  float humidity;
  float gasValue;
};

Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  lcd.begin(16, 2);
  lcd.backlight();

  pinMode(ALARM_PIN, OUTPUT);

  if (!bme.begin(0x76)) {
    Serial.println("BME280 sensörü bulunamadı!");
    while (1);
  }

  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E1LL);
}

void loop() {
  SensorData data;
  data.temperature = bme.readTemperature();
  data.humidity = bme.readHumidity();
  data.gasValue = analogRead(A0);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sicaklik: ");
  lcd.print(data.temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Nem: ");
  lcd.print(data.humidity);
  lcd.print(" %");

  Serial.print("Sıcaklık: ");
  Serial.print(data.temperature);
  Serial.print(" °C\tNem: ");
  Serial.print(data.humidity);
  Serial.print(" %\tGaz Değeri: ");
  Serial.print(data.gasValue);
  Serial.println("");

  if (data.gasValue > 500) {
    digitalWrite(ALARM_PIN, HIGH);
    lcd.setCursor(13, 1);
    lcd.print("!");
  } else {
    digitalWrite(ALARM_PIN, LOW);
  }

  radio.write(&data, sizeof(data));
  delay(1000);
}
