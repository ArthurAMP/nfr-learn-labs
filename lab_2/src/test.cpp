#include <Arduino.h>

// Pin number for the LED
const int ledPin = GPIO_NUM_32;

// Setup function runs once when you press reset or power the board
void setup() {
    // Initialize the digital pin as an output
    pinMode(ledPin, OUTPUT);
}

// Loop function runs over and over again forever
void loop() {
    // Turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin, HIGH);
    // Wait for a second
    delay(1000);
    // Turn the LED off by making the voltage LOW
    digitalWrite(ledPin, LOW);
    // Wait for a second
    delay(1000);
}

void scopeExample(int x)
{
    if (x > 5)
    {
        int y = 20;
        // x and y are in scope here
    }
    int z = x + y; // error: y is not in scope here
}

// string examples
void tooManyStringTypes()
{
    // C-style string
    char cString[] = "Hello, World!";

    // C++ string
    // (Evan likes to use this one)
    std::string cppString = "Hello, World!";

    // Arduino String
    String arduinoString = "Hello, World!";
}

int simpleSearch(int data[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void stringIterate()
{
    std::string message = "Hello, World!";
    for (char c : message)
    {
        Serial.println(c);
    }
}