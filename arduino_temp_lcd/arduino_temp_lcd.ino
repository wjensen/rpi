/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */
// We'll use analog input 0 to measure the temperature sensor's
// signal pin.

const int temperaturePin = 0;

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
   // The speed is measured in bits per second, also known as
  // "baud rate". 9600 is a very commonly used baud rate,
  // and will transfer about 10 characters per second.
  
  //Serial.begin(9600);
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temperature:");
}

void loop() {
   // We'll declare three floating-point variables
  // (We can declare multiple variables of the same type on one line:)

  float voltage, degreesF, degreesC;
  
    // First we'll measure the voltage at the analog pin. Normally
  // we'd use analogRead(), which returns a number from 0 to 1023.
  // Here we've written a function (further down) called
  // getVoltage() that returns the true voltage (0 to 5 Volts)
  // present on an analog input pin.

  voltage = getVoltage(temperaturePin);
  
   // Now we'll convert the voltage to degrees Celsius.
  // This formula comes from the temperature sensor datasheet:

  degreesC = (voltage - 0.5) * 100.0;
  
  // While we're at it, let's convert degrees Celsius to Fahrenheit.
  // This is the classic C to F conversion formula:
  
  degreesF = (degreesC * (9.0/5.0) + 32.0)/2;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
   lcd.print(degreesF);
   delay(3000); // repeat once per second (change as you wish!)
}

float getVoltage(int pin)
{
  // This function has one input parameter, the analog pin number
  // to read. You might notice that this function does not have
  // "void" in front of it; this is because it returns a floating-
  // point value, which is the true voltage on that pin (0 to 5V).
  
  // You can write your own functions that take in parameters
  // and return values. Here's how:
  
    // To take in parameters, put their type and name in the
    // parenthesis after the function name (see above). You can
    // have multiple parameters, separated with commas.
    
    // To return a value, put the type BEFORE the function name
    // (see "float", above), and use a return() statement in your code
    // to actually return the value (see below).
  
    // If you don't need to get any parameters, you can just put
    // "()" after the function name.
  
    // If you don't need to return a value, just write "void" before
    // the function name.

  // Here's the return statement for this function. We're doing
  // all the math we need to do within this statement:
  
  return (analogRead(pin) * 0.004882814);
  
  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value that is the true voltage
  // being read at that pin.
}
