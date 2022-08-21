#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
SoftwareSerial sim(9, 10); //SIM800L Tx & Rx is connected to Arduino #9 & #10

LiquidCrystal_I2C lcd(0x27, 16, 2);
int INPUT_01 = 4;
int INPUT_02 = 5;
int INPUT_03 = 8;

String number1 = "+94779926813"; // +94 is the country code & add Emergency Department number

int State1 = 0;
int State2 = 0;
int State3 = 0;

int faultSent1 = 0;
int faultSent2 = 0;
int faultSent3 = 0;
int faultSent4 = 0;
int faultSent5 = 0;
int faultSent6 = 0;
int faultSent7 = 0;


void setup()
{
  Serial.begin(9600);
  sim.begin(9600);
  delay(7000);
  lcd.init();
  lcd.backlight();
  lcd.clear();


  pinMode(INPUT_01, INPUT);
  pinMode(INPUT_02, INPUT);
  pinMode(INPUT_03, INPUT);

}

void loop()
{
  State1 = digitalRead(INPUT_01);
  State2 = digitalRead(INPUT_02);
  State3 = digitalRead(INPUT_03);

  if ((State1  == 0) && (State2  == 0) && (State3  == 0)) { //check if the voltage pin 1&2&3

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 0) && (State2  == 0) && (State3  == 0)) { //check for the fault again

      //LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("NORMAL OPERATION");
      delay(2000);
      
      faultSent1 = 0;
      faultSent2 = 0;
      faultSent3 = 0;
      faultSent4 = 0;
      faultSent5 = 0;
      faultSent6 = 0;
      faultSent7 = 0;
    }
  } else if ((State1  == 0) && (State2  == 0) && (State3  == 1) && (faultSent1  == 0)) { //check if the voltage pin 1&2&3

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 0) && (State2  == 0) && (State3  == 1) && (faultSent1  == 0)) { //check for the fault again

      //LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("phase 3 fault");
      delay(2000);
      //SMS
      sim.println("AT+CMGF=1");
      delay(1000);
      sim.println("AT+CMGS=\"" + number1 + "\"\r");
      delay(1000);
      String SMS = "phase 3 fault";
      sim.println(SMS);
      delay(100);
      sim.println((char)26);
      delay(1000);

      faultSent1 = 1;
      faultSent2 = 0;
      faultSent3 = 0;
      faultSent4 = 0;
      faultSent5 = 0;
      faultSent6 = 0;
      faultSent7 = 0;

    }
  } else  if ((State1  == 0) && (State2  == 1) && (State3  == 0) && (faultSent2  == 0)) { //check if the voltage pin 1&2&3

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 0) && (State2  == 1) && (State3  == 0) && (faultSent2  == 0)) { //check for the fault again

      //LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("phase 2 fault");
      delay(2000);

      //SMS
      sim.println("AT+CMGF=1");
      delay(1000);
      sim.println("AT+CMGS=\"" + number1 + "\"\r");
      delay(1000);
      String SMS = "phase 2 fault";
      sim.println(SMS);
      delay(100);
      sim.println((char)26);
      delay(1000);

      faultSent1 = 0;
      faultSent2 = 1;
      faultSent3 = 0;
      faultSent4 = 0;
      faultSent5 = 0;
      faultSent6 = 0;
      faultSent7 = 0;
    }
  } else if ((State1  == 1) && (State2  == 0) && (State3  == 0) && (faultSent3  == 0)) { //check if the voltage pin 1&2&3

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 1) && (State2  == 0) && (State3  == 0) && (faultSent3  == 0)) { //check for the fault again

      //LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("phase 1 fault");
      delay(2000);

      //SMS
      sim.println("AT+CMGF=1");
      delay(1000);
      sim.println("AT+CMGS=\"" + number1 + "\"\r");
      delay(1000);
      String SMS = "phase 1 fault";
      sim.println(SMS);
      delay(100);
      sim.println((char)26);
      delay(1000);

      faultSent1 = 0;
      faultSent2 = 0;
      faultSent3 = 1;
      faultSent4 = 0;
      faultSent5 = 0;
      faultSent6 = 0;
      faultSent7 = 0;
    }
  } else if ((State1  == 0) && (State2  == 1) && (State3  == 1) && (faultSent4  == 0)) { //check if the voltage pin 1&2&3

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 0) && (State2  == 1) && (State3  == 1) && (faultSent4  == 0)) { //check for the fault again

      //LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("phase 2&3 fault");
      delay(2000);

      //SMS
      sim.println("AT+CMGF=1");
      delay(1000);
      sim.println("AT+CMGS=\"" + number1 + "\"\r");
      delay(1000);
      String SMS = "phase 2&3 fault";
      sim.println(SMS);
      delay(100);
      sim.println((char)26);
      delay(1000);

      faultSent1 = 0;
      faultSent2 = 0;
      faultSent3 = 0;
      faultSent4 = 1;
      faultSent5 = 0;
      faultSent6 = 0;
      faultSent7 = 0;
    }
  } else if ((State1  == 1) && (State2  == 0) && (State3  == 1) && (faultSent5  == 0)) { //check if the voltage pin 1&2&3

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 1) && (State2  == 0) && (State3  == 1) && (faultSent5  == 0)) { //check for the fault again

      //LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("phase 1&3 fault");
      delay(2000);

      //SMS
      sim.println("AT+CMGF=1");
      delay(1000);
      sim.println("AT+CMGS=\"" + number1 + "\"\r");
      delay(1000);
      String SMS = "phase 1&3 fault";
      sim.println(SMS);
      delay(100);
      sim.println((char)26);
      delay(1000);

      faultSent1 = 0;
      faultSent2 = 0;
      faultSent3 = 0;
      faultSent4 = 0;
      faultSent5 = 1;
      faultSent6 = 0;
      faultSent7 = 0;
    }
  } else if ((State1  == 1) && (State2  == 1) && (State3  == 0) && (faultSent6  == 0)) { //check if the voltage pin 1&2&3

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 1) && (State2  == 1) && (State3  == 0) && (faultSent6  == 0)) { //check for the fault again

      //LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("phase 1&2 fault");
      delay(2000);

      //SMS
      sim.println("AT+CMGF=1");
      delay(1000);
      sim.println("AT+CMGS=\"" + number1 + "\"\r");
      delay(1000);
      String SMS = "phase 1&2 fault";
      sim.println(SMS);
      delay(100);
      sim.println((char)26);
      delay(1000);

      faultSent1 = 0;
      faultSent2 = 0;
      faultSent3 = 0;
      faultSent4 = 0;
      faultSent5 = 0;
      faultSent6 = 1;
      faultSent7 = 0;
    }
  } else if ((State1  == 1) && (State2  == 1) && (State3  == 1) && (faultSent7  == 0)) { //check if the voltage pin 1&2&3

    delay(100); //delay for 0.1 sec to see if the fault is still happening
    if ((State1  == 1) && (State2  == 1) && (State3  == 1) && (faultSent7  == 0)) { //check for the fault again

      //LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Operation status");
      lcd.setCursor(0, 1);
      lcd.print("phase 1&2&3 fault");
      delay(2000);

      //SMS
      sim.println("AT+CMGF=1");
      delay(1000);
      sim.println("AT+CMGS=\"" + number1 + "\"\r");
      delay(1000);
      String SMS = "phase 1&2&3 fault";
      sim.println(SMS);
      delay(100);
      sim.println((char)26);
      delay(1000);

      faultSent1 = 0;
      faultSent2 = 0;
      faultSent3 = 0;
      faultSent4 = 0;
      faultSent5 = 0;
      faultSent6 = 0;
      faultSent7 = 1;
    }
  }
}
