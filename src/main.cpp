/*This code uses an Arduino UNO board and the following components: a red LED connected to pin 2 of the board and a green LED connected to pin 3. A blue LED is connected to pin 4. Four buttons are connected to pins 5-8 and a start/stop button is connected to pin 9. An LCD display is also used.

After powering up the system the red LED will light up. When the start/stop button is pressed (using interrupts), the green LED will light up and one of four actions can be performed depending on which of the four buttons is pressed. If button one is pressed then the blue LED will light up using Morse code for the text “UPT”. If button two is pressed then it will light up using Morse code for “AC”. If button three is pressed then it will light up using Morse code for “INFORMATICA” and if button four is pressed then it will light up using Morse code for “EMBEDDED SYSTEMS”. The user can interrupt at any time by pressing another button. The LCD will display each letter.*/
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int redLED = 2;
const int greenLED = 3;
const int blueLED = 4;
const int button1 = 5;
const int button2 = 6;
const int button3 = 7;
const int button4 = 8;
const int startStopButton = 9;

LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup()
{
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    pinMode(button4, INPUT_PULLUP);
    pinMode(startStopButton, INPUT_PULLUP);

    lcd.init();
    lcd.backlight();

    digitalWrite(redLED, HIGH); // red LED on
}

void dot()
{
    digitalWrite(blueLED, HIGH);
    delay(200);
    digitalWrite(blueLED, LOW);
    delay(200);
}

void dash()
{
    digitalWrite(blueLED, HIGH);
    delay(600);
    digitalWrite(blueLED, LOW);
    delay(200);
}

void morseCode(String text)
{
    for (int i = 0; i < text.length(); i++)
    {
        lcd.clear();
        lcd.print(text[i]);
        switch (text[i])
        {
        case 'A':
            dot();
            dash();
            break;
        case 'B':
            dash();
            dot();
            dot();
            dot();
        case 'C':
            dash();
            dot();
            dash();
            dot();
            break;

        case 'D':
            dash();
            dot();
            dot();
            break;
        case 'E':
            dot();
            break;
        case 'F':
            dot();
            dot();
            dash();
            dot();
            break;
        case 'G':
            dash();
            dash();
            dot();
            break;
        case 'H':
            dot();
            dot();
            dot();
            dot();
            break;
        case 'I':
            dot();
            dot();
            break;
        case 'J':
            dot();
            dash();
            dash();
            dash();
            break;
        case 'K':
            dash();
            dot();
            dash();
            break;
        case 'L':
            dot();
            dash();
            dot();
            dot();
            break;
        case 'M':
            dash();
            dash();
            break;
        case 'N':
            dash();
            dot();
            break;
        case 'O':
            dash();
            dash();
            dash();
        case 'P':
            dot();
            dash();
            dash();
            dot();
            break;
        case 'Q':
            dash();
            dash();
            dot();
            dash();
            break;
        case 'R':
            dot();
            dash();
            dot();
            break;
        case 'S':
            dot();
            dot();
            dot();
            break;
        case 'T':
            dash();
            break;
        case 'U':
            dot();
            dot();
            dash();
            break;
        case 'V':
            dot();
            dot();
            dot();
            dash();
            break;
        case 'W':
            dot();
            dash();
            dash();
            break;
        case 'X':
            dash();
            dot();
            dot();
            dash();
            break;
        case 'Y':
            dash();
            dot();
            dash();
            dash();
            break;
        case 'Z':
            dash();
            dash();
            dot();
            dot();
            break;

        default:
            delay(1000);
        }
        delay(1000);
    }
}
void shortBlink()
{
    digitalWrite(blueLED, HIGH);
    delay(200);
    digitalWrite(blueLED, LOW);
    delay(200);
}
void longBlink()
{
    digitalWrite(blueLED, HIGH);
    delay(600);
    digitalWrite(blueLED, LOW);
    delay(200);
}
void space()
{
    delay(600);
}
void endLetter()
{
    delay(400);
}
void endWord()
{
    delay(800);
}

void loop()
{
    if (digitalRead(startStopButton) == LOW)
    {
        digitalWrite(greenLED, HIGH); // green LED on
        digitalWrite(redLED, LOW);    // red LED off
        while (digitalRead(startStopButton) == LOW)
        {
            if (digitalRead(button1) == LOW)
            {
                lcd.clear();
                lcd.print("UPT");
                morseCode("UPT");
            }
            else if (digitalRead(button2) == LOW)
            {
                lcd.clear();
                lcd.print("AC");
                morseCode("AC");
            }
            else if (digitalRead(button3) == LOW)
            {
                lcd.clear();
                lcd.print("INFORMATICA");
                morseCode("INFORMATICA");
            }
            else if (digitalRead(button4) == LOW)
            {
                lcd.clear();
                lcd.print("EMBEDDED");
                morseCode("EMBEDDED SYSTEMS");
            }
        }
        digitalWrite(greenLED, LOW); // green LED off
        digitalWrite(redLED, HIGH);  // red LED on
    }
}
