#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// -------- DHT Sensor --------
#define DHT_PIN PA0
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

// -------- LCD --------
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // Start DHT sensor
  dht.begin();

  // Start I2C
  Wire.begin();

  // Start LCD
  lcd.init();
  lcd.backlight();

  // Initial message
  lcd.setCursor(0, 0);
  lcd.print("Temp & Humidity");

  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  delay(2000);

  lcd.clear();
}

void loop()
{
  // Read temperature
  float temperature = dht.readTemperature();

  // Read humidity
  float humidity = dht.readHumidity();

  // Check if readings are valid
  if (isnan(temperature) || isnan(humidity))
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");

    delay(2000);
    return;
  }

  // Display temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C   ");

  // Display humidity
  lcd.setCursor(0, 1);
  lcd.print("Hum : ");
  lcd.print(humidity, 1);
  lcd.print("%   ");

  delay(2000);
}
