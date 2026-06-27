# PIR-Motion-Sensor_ESP32_30-Pin
OBJECTIVE: This project uses an ESP32 DevKit V1 with a PIR motion sensor to detect human movement. When motion is detected, the ESP32 activates an LED and buzzer while displaying "Motion Detected!" on a 16×2 LCD. If no motion is detected, the LCD shows "No Motion – Monitoring..." and the outputs remain OFF. This demonstrates digital sensor interfacing, GPIO control, and real-time embedded firmware development using Embedded C in the Arduino IDE.
✅🔰⬇️⬆️▫️▪️◾◽◼️◻️🔸🟡🔴♦️
Working Principle / Operation: 

🟡 The project uses an ESP32 DevKit V1 as the main controller and a PIR (Passive Infrared) motion sensor to detect human movement. The PIR sensor senses changes in infrared radiation emitted by a moving human body and sends a HIGH digital signal to the ESP32 whenever motion is detected.

The ESP32 continuously monitors the PIR sensor output. When motion is detected, it:

🔸Turns ON the LED as a visual indicator.
🔸Activates the buzzer as an audible alarm.
🔸Displays "Motion Detected" on the 16×2 I2C LCD.
🔸Prints the motion status on the Serial Monitor.

When no motion is detected, the ESP32:

◻️Turns OFF the LED.
◻️Turns OFF the buzzer.
◻️Displays "No Motion / Monitoring..." on the LCD.
◻️Continues monitoring the PIR sensor in real time.

This project demonstrates sensor interfacing, GPIO control, digital input processing, and real-time embedded system programming using the ESP32.

The PIR sensor detects human motion by sensing changes in infrared radiation. The ESP32 continuously reads the sensor output. If motion is detected, it switches ON the LED and buzzer, displays 'Motion Detected' on the LCD, and prints the status on the Serial Monitor. If no motion is detected, all outputs remain OFF while the system continuously monitors the surroundings.


Complete Firmware Working (Step-by-Step)
Step 1: 
Header Files:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Purpose:
These header files include the required libraries.

Wire.h:
Enables I2C communication.
ESP32 communicates with the LCD using only 2 wires:
SDA
SCL

Without this library, the ESP32 cannot communicate with the I2C LCD.

LiquidCrystal_I2C.h:
This library provides functions such as:
lcd.init()
lcd.print()
lcd.clear()
lcd.setCursor()
lcd.backlight()

These functions make controlling the LCD much easier.

Step 2: 
Define GPIO Pins:
#define PIR_PIN     27
#define LED_PIN     26
#define BUZZER_PIN  25
Purpose:
These are preprocessor macros.

Instead of writing ⬇️
          digitalRead(27);

we simply write ⬇️ 
          digitalRead(PIR_PIN);

Advantages:
✅Easy to modify
✅Easy to read
✅Professional coding practice

Step 3: Create LCD Object:
LiquidCrystal_I2C lcd(0x27,16,2);
Here we create an LCD object.

Meaning of each parameter:

0x27
LCD I2C Address

Most LCD modules use
0x27

Some use
0x3F
16

means
16 Columns

2
means
2 Rows

So the library now knows:

"I am controlling a 16×2 LCD at I2C address 0x27."

Step 4: setup()
void setup()
This function executes only once after powering the ESP32 or pressing RESET.

Purpose:
Initialize everything before the main program starts.

Step 5: Start Serial Communication
Serial.begin(115200);
This opens communication between

ESP32 ↔ Arduino IDE Serial Monitor

Speed:
115200 bits/sec

This allows messages like;
Motion Detected

to appear on the Serial Monitor.

Step 6: Configure GPIO Directions:
pinMode(PIR_PIN, INPUT);

GPIO27 becomes an Input Pin.
ESP32 now waits for signals from the PIR sensor.

pinMode(LED_PIN, OUTPUT);
GPIO26 becomes an Output.

ESP32 can:
ON
OFF
the LED.

pinMode(BUZZER_PIN, OUTPUT);
GPIO25 becomes an Output.
ESP32 can control the buzzer.

Step 7: Initialize LCD:
lcd.init();
Starts communication between
ESP32 ↔ LCD

lcd.backlight();
Turns ON the LCD backlight.
Without this, the LCD may appear blank even if it is working.

Step 8: Display Welcome Message:
lcd.setCursor(0,0);
Cursor Position ⬇️
              Column = 0
              Row = 0
Top-left corner.

lcd.print("ESP32 Security");
LCD displays ⬇️
       ESP32 Security

Next:

lcd.setCursor(0,1);
Moves cursor to ⬇️
             column 0
             row 1
Second line.

lcd.print("System Ready");

LCD becomes ⬇️
ESP32 Security
System Ready

Step 9: Wait:
delay(2000);

Wait
     2000 ms
     =
     2 seconds

So the welcome screen stays visible.

Step 10: Clear LCD:
lcd.clear();
Removes the welcome message.
Now the LCD is ready to display motion status.

Step 11: loop()
void loop()
This function runs forever.

Think of it as ⬇️
           while(1)
           {
            }
The ESP32 continuously checks for motion.

Step 12: Read PIR Sensor:
int motion = digitalRead(PIR_PIN);

ESP32 reads GPIO27.

Possible values

LOW

or

HIGH

Store it in variable

motion

If

motion == HIGH

means

PIR has detected motion.

If

motion == LOW

means

No motion.

Step 13: Decision Making
if(motion == HIGH)

ESP32 checks

"Has the PIR detected motion?"

If YES

execute the following block.

Step 14: Print on Serial Monitor
Serial.println("Motion Detected");

Serial Monitor shows

Motion Detected

Useful for debugging.

Step 15: Turn ON LED
digitalWrite(LED_PIN,HIGH);

GPIO26 outputs

3.3V

LED glows.

Visual indication.

Step 16: Turn ON Buzzer
digitalWrite(BUZZER_PIN,HIGH);

GPIO25 becomes HIGH.

Buzzer sounds.

Audible indication.

Step 17: Update LCD
lcd.clear();

Remove previous text.

lcd.setCursor(0,0);

Cursor

Top Row

lcd.print("Motion");

LCD

Motion

Next

lcd.setCursor(0,1);

Move to second row.

lcd.print("Detected!");

LCD becomes

Motion
Detected!
Step 18: Wait
delay(2000);

Keep

LED

Buzzer

LCD

ON for

2 seconds.

Step 19: Else Block

If

motion == LOW

means

No human movement.

Step 20: Serial Monitor
Serial.println("No Motion");

Displays

No Motion
Step 21: Turn OFF LED
digitalWrite(LED_PIN,LOW);

GPIO26 becomes LOW.

LED OFF.

Step 22: Turn OFF Buzzer
digitalWrite(BUZZER_PIN,LOW);

GPIO25 becomes LOW.

Buzzer OFF.

Step 23: LCD Status
lcd.clear();

Erase previous message.

lcd.setCursor(0,0);
lcd.print("No Motion");

LCD

No Motion
lcd.setCursor(0,1);
lcd.print("Monitoring...");

LCD

No Motion
Monitoring...
Step 24: Small Delay
delay(300);

Wait

300 milliseconds

This prevents the LCD and Serial Monitor from updating too rapidly, reducing flicker and unnecessary processing.
