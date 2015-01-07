/*
 Candle Lights
 
 This application is based on the example "Fade".
 */

int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by
int nextTarget = 128;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  analogWrite(led, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount * random(1, 6);

  // reverse the direction of the fading at the ends of the fade: 
  if (fadeAmount < 0 && brightness < nextTarget) {
    brightness = nextTarget;
    nextTarget = random(32, 48);
    fadeAmount = 1;
  }
  if (fadeAmount > 0 && brightness > nextTarget) {
    brightness = nextTarget;
    nextTarget = random(16, 32);
    fadeAmount = -1;
  }
  
  delay(10);
}

