
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        5 


#define NUMPIXELS 21 // Popular NeoPixel ring size


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
 
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}
 bool first = true;
void loop() {
 

  for(int i=0; i<1000; i++) { // For each pixel...
    if(first) {
      i =850;
      first = false;
    }
    // pixels.green() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green green:
   Show(i);
    

    delay(DELAYVAL); // Pause before next pass through loop
  }
}
int red =0;
int green = 150;
int blue = 0;

void Show(int num){
pixels.clear(); // Set all pixel greens to 'off'
  int one = -1;
  int two = -1;
  int three = -1;
  int four = -1;
  if(num > 999){
    one = num%10;
    two = (num/10)%10;
    three =(num/100)%10;
    four  =(num/1000)%10;
  } 
  else if(num > 99){
    one = num%10;
    two = (num/10)%10;
    three =(num/100)%10;
  } 
  else if(num > 9){
    one = num%10;
    two = (num/10)%10;
  } 
  else if(num > -1) one = num%10; 

  if(four > -1){
    Switch(four,3);
    Switch(three,2);
    Switch(two,1);
    Switch(one,0);
  }
  else if(three > -1){
    Switch(three,2);
    Switch(two,1);
    Switch(one,0);
  }
  else if(two > -1){
    Switch(two,1);
    Switch(one,0);
  }
  else if(one > -1){
    Switch(one,0);
  }


  pixels.show();   // Send the updated pixel greens to the hardware.
}

void Switch(int num, int razryad){
  if(num == 0) Zero(razryad);
  else if(num == 1) One(razryad);
  else if(num == 2) Two(razryad);
  else if(num == 3) Three(razryad);
  else if(num == 4) Four(razryad);
  else if(num == 5) Five(razryad);
  else if(num == 6) Six(razryad);
  else if(num == 7) Seven(razryad);
  else if(num == 8) Eight(razryad);
  else if(num == 9) Nine(razryad);
}

void One(int razryd){
  pixels.setPixelColor(1 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
}
void Two(int razryd){
  pixels.setPixelColor(0 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(1 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(3 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(4 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(6 + razryd*7, pixels.Color(red, green, blue));
}
void Three(int razryd){
  pixels.setPixelColor(0 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(1 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(3 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(6 + razryd*7, pixels.Color(red, green, blue));
}
void Four(int razryd){
  pixels.setPixelColor(5 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(1 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(6 + razryd*7, pixels.Color(red, green, blue));
}
void Five(int razryd){
  pixels.setPixelColor(0 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(5 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(3 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(6 + razryd*7, pixels.Color(red, green, blue));
}
void Six(int razryd){
 pixels.setPixelColor(0 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(5 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(3 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(4 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(6 + razryd*7, pixels.Color(red, green, blue));
}
void Seven(int razryd){
  pixels.setPixelColor(0 + razryd*7, pixels.Color(red, green, blue));
 pixels.setPixelColor(1 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
}
void Eight(int razryd){
  pixels.setPixelColor(0 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(1 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(5 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(3 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(4 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(6 + razryd*7, pixels.Color(red, green, blue));
}
void Nine(int razryd){
 pixels.setPixelColor(0 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(1 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(5 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(3 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(6 + razryd*7, pixels.Color(red, green, blue));
}
void Zero(int razryd){
pixels.setPixelColor(0 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(1 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(5 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(2 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(3 + razryd*7, pixels.Color(red, green, blue));
  pixels.setPixelColor(4 + razryd*7, pixels.Color(red, green, blue));
}
