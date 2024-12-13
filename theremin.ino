/*
    DIY Theremin Synthesizer
    Theremin Synthesizer that works with photoresistor. Changes frequency
    based on the luminosity.
    
    The circuit:
    * Arduino
    * Photoresistor
    * LM386
    * JST-PH2.0 Speaker
    * Capacitors
    * Resistors

    Created: December 12th, 2024
    Daniel Vera, Aidan Evans
    ENGR-200
*/
const int ldrPin = A0;      // Photoresistor connected to analog pin A0
const int speakerPin = 9;    // PWM output pin to generate sound
int ldrValue = 0;            // Variable to store the light value
int frequency = 500;         // Default frequency for theremin sound

void setup() {
  pinMode(speakerPin, OUTPUT);  // Set speaker pin to output
  Serial.begin(9600);           // Start serial monitor for debugging
}

void loop() {
  // Read the value of the photoresistor (LDR)
  ldrValue = analogRead(ldrPin);
  
  // Map the LDR value to a frequency range (light = higher frequency)
  frequency = map(ldrValue, 0, 1023, 100, 2000);  // Map light to frequency between 100Hz and 2000Hz
  
  // Output the tone to the speaker pin based on the LDR input
  tone(speakerPin, frequency);
  
  // Debugging: print the LDR value and frequency to the serial monitor
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" Frequency: ");
  Serial.println(frequency);
  
  delay(50);  // Small delay to stabilize the reading
}
