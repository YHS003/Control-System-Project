#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
const int sensor = A0;  // Assigning analog pin A1 to variable 'sensor'
const int rainPin = A1;
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit
float vout;   //temporary variable to hold sensor reading
int PushButton = 3;
int PushButton2 = 2;
int thresholdValue = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);  // Configuring pin A1 as input
  pinMode(rainPin, INPUT);
  pinMode(PushButton, INPUT);
  pinMode(PushButton2, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("Welcome to");
  lcd.setCursor(1, 1);
  lcd.print("Control System");
  delay(10000);
  lcd.clear();
  lcd.print("Choose your Mode");
  lcd.setCursor(0, 0);
  delay(5000);
  lcd.clear();
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("Mode 1");
  lcd.setCursor(0, 1);
  lcd.print("Mode 2");
  delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:

  // int ButtonState = digitalRead(PushButton);
  // int ButtonState2 = digitalRead(PushButton2);
  // int sensorValue = analogRead(rainPin);
  switch (digitalRead(PushButton)) {
    case HIGH:

      while (digitalRead(PushButton) == HIGH) {
        lcd.clear();
        vout = analogRead(sensor);
        vout = (vout * 500) / 1023;
        tempc = vout;               // Storing value in Degree Celsius
        tempf = (vout * 1.8) + 32;  // Converting to Fahrenheit
        lcd.setCursor(0, 0);
        lcd.print("TDegreeC=");
        lcd.print(tempc);
        lcd.setCursor(0, 1);
        lcd.print("TFahrenheit=");
        lcd.print(tempf);
        delay(500);  //Delay of 1 second for ease of viewing in serial monitor
      }
      break;
    case 0:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Mode 1");
      lcd.setCursor(0, 1);
      lcd.print("Mode 2");
      delay(500);
  }
  switch (digitalRead(PushButton2)) {
    case HIGH:

      while (digitalRead(PushButton2) == HIGH) {
        lcd.clear();
        if (analogRead(rainPin) < thresholdValue) {
          lcd.print(" - It's wet");
          delay(500);
        } else {
          lcd.print(" - It's dry");
          delay(500);
        }
      }
      break;
    case 0:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Mode 1");
      lcd.setCursor(0, 1);
      lcd.print("Mode 2");
      delay(500);
  }
}
