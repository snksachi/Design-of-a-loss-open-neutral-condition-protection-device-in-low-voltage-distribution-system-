#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int INPUT_01 = 9;
int INPUT_02 = 10;
int RELAY = 8;

int State1 = 0;
int State2 = 0;
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(RELAY, OUTPUT);
  pinMode(INPUT_01, INPUT);
  pinMode(INPUT_02, INPUT);

}

void loop()
{
  State1 = digitalRead(INPUT_01);
  State2 = digitalRead(INPUT_02);
  Serial.print(State1);
  Serial.print("  |   ");
  Serial.println(State2);
  delay(1000);
  if ((State1  == 1) && (State2  == 0)) { //check if the over voltage pin is high and the other is low

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 1) && (State2  == 0)) { //check for the fault again

      digitalWrite(RELAY, HIGH);  //activate the output and drive the relay

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("OVER VOLTAGE ");
      delay(2000);
    }
  } else if ((State1  == 0) && (State2  == 1)) {//check if under voltage pin is high and the other is low

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 0) && (State2  == 1)) { //check for the fault again

      digitalWrite(RELAY, HIGH);  //activate the output and drive the relay

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("UNDER VOLTAGE ");
      delay(2000);


    }
  } else if ((State1  == 0) && (State2  == 0)) { //chck if there is no under voltage or over voltage

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 0) && (State2  == 0)) { //check for the fault again

      digitalWrite(RELAY, LOW);  //output off andrelay is off

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("NORMAL OPERATION ");
      delay(2000);

    }
  } else {
    digitalWrite(RELAY, HIGH);  //relay is off
  }

}
