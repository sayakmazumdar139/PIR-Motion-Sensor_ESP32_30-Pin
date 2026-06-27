#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIR_PIN     27
#define LED_PIN     26
#define BUZZER_PIN  25

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("ESP32 Security");

  lcd.setCursor(0,1);
  lcd.print("System Ready");

  delay(2000);
  lcd.clear();
}

void loop()
{
  int motion = digitalRead(PIR_PIN);

  if(motion == HIGH)
  {
    Serial.println("Motion Detected");

    digitalWrite(LED_PIN,HIGH);
    digitalWrite(BUZZER_PIN,HIGH);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Motion");

    lcd.setCursor(0,1);
    lcd.print("Detected!");

    delay(2000);
  }
  else
  {
    Serial.println("No Motion");

    digitalWrite(LED_PIN,LOW);
    digitalWrite(BUZZER_PIN,LOW);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Motion");

    lcd.setCursor(0,1);
    lcd.print("Monitoring...");

    delay(300);
  }
}
