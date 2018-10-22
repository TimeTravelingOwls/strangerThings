/**************************************************************************/
/*
  Stranger Things Message Board: spells out messages on a string of LEDs, one per letter. 
  by TimeTravelingOwls/burkmurray for TKTC
  
  v0.5 10/22/18 - Parsing works. Need to add Neopixels.   
  
  This is a halloween prop that spells out messages in the style of Joyce Beyers' living room.

  The list of messages will be displayed one after another, with a configurable pause 
  between messages and between words within a message.

*/
/**************************************************************************/


#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 0
#define PIXEL_COUNT 26

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// messages must be uppercase, ending with "*"
// message length [32] includes a null character, so subtract one for actual length
// including a "!" at the beginning of a message increases brightness to maxBright
char messages[][32] = {"HAPPY HALLOWEEN*",   // default messages
                        "RUN*",
                        "BOB IS THE NEW BARB*",
                        "BOO*"
                       }; 

// brightness controls
int defaultBright = 85; // 1/3 brightness
int maxBright = 255;    // full brightness - VERY BRIGHT

// delays are in milliseconds 1000 = 1 second
int letterDelay = 500;  // delay between letters default = 500
int wordDelay = 1000;   // delay between words default = 1000
int msgDelay = 2000;    // delay between messages default = 2000

int parseLetter;
int currentMessage = 0;


void setup() {

  Serial.begin(115200);    // for debug  

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
// Bluetooth setup

}

void loop() {

  strip.setBrightness(defaultBright); // reset brightness to default

  getMessage();

  parseMessage();
  delay(msgDelay);
}


// Checks whether there's a new message (via Bluetooth), else continues from the message queue
void getMessage() {


// MESSAGE COLLECTION

}


// Checks whether there's a new message (via Bluetooth), else continues from the message queue
void parseMessage() {

for(uint16_t i=0; messages[currentMessage][i]!=42; i++) {
           
           if(messages[currentMessage][i] == 32){
              Serial.println("space");    
              delay(wordDelay);     
              }

              else if (messages[currentMessage][i] == 33) {
                  Serial.println("maxBright");    
                  strip.setBrightness(maxBright); // reset brightness to max
                  strip.show(); // Initialize all pixels to 'off'
                  }

               else { 
                  parseLetter =  messages[currentMessage][i];
              
                  Serial.print(messages[currentMessage][i]);     
                  Serial.print("  ");     
                  Serial.print(parseLetter); 
                  Serial.print("  ");     
                  Serial.println(parseLetter - 65);     
                  }
                              
            delay(letterDelay);                
            }
            Serial.println("message end");    
            delay(msgDelay);                

}



// Single-Color Sparkles!
void oneColorSparks(uint32_t c, uint8_t wait) {

  for(uint16_t i=0; i< 5*(strip.numPixels()); i++) {
    
    uint8_t  p = random(strip.numPixels());
  
    strip.setPixelColor(p, c);
    strip.show();
    delay(10);
    strip.setPixelColor(p, 0);
    delay(wait);
  }
  strip.show(); // Initialize all pixels to 'off'

}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

/* ASCII Values

32  space
33  !

64 @
65  A
66  B
67  C
68  D
69  E
70  F
71  G
72  H
73  I
74  J
75  K
76  L
77  M
78  N
79  O
80  P
81  Q
82  R
83  S
84  T
85  U
86  V
87  W
88  X
89  Y
90  Z

 */


