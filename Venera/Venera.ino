/*
Mepкуpий – 0.З8 g – З,7 м/c² 
Beнepa – 0.906 g – 8,87 м/c² 
Зeмля – 1 g – 9,80665 м/c² 
Mapc – 0.З78 g – З,711 м/c² 
Юпитep – 2.442 g – 24,79 м/c² 
Caтуpн – 1.065 g – 10,44 м/c² 
Уpaн – 0.90З g – 8,87 м/c² 
Heптун – 1.1З1 g – 11,15 м/c² 
Плутoн – 0.06З g – 0,617 м/c² 
Лунa – 0.165 g – 1,62 м/c² 
Coлнцe – 27.85 g – 274,0 м/c²
*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        5 


#define NUMPIXELS 21 // Popular NeoPixel ring size


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int red =0;
int green = 150;
int blue = 0;

int pin=8;
int color;
int flag =0;
int i =0;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;

//-------про весы-------------
#include "HX711.h"
#define DT  14
#define SCK  15
//#define DT  9
//#define SCK  8
HX711 scale;
float calibration_factor = -25900; //-5050;//для тензы лигера


byte segment[] = {2,3,4,5,6,7,8};
byte razr[] = {12,9,10};
int zadergka = 1;

unsigned long deltaT = 250;
unsigned long lastTime=0;
float ves =888;

int minValue = 5;
 
void keep_fit () {
 scale.set_scale(calibration_factor); //Adjust to this calibration factor
 
 if(Serial.available())
 {
  char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 100;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 100;
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println(); 
  }
  
  }

    
void setup() {
   Serial.begin(9600);
    pixels.begin();
   Serial.println("HX711 calibration sketch");
 for(int i = 0; i<3; i++) {
    pinMode(razr[i], OUTPUT);
    digitalWrite(razr[i], HIGH);
  }
   for(int i = 0; i<7; i++){ //
    pinMode(segment[i], OUTPUT);
   digitalWrite(segment[i], HIGH);
  } 

  while(millis()<7000){
    Show(ves);
  }
   scale.begin(DT, SCK); 
   delay(100);
   Serial.println(scale.is_ready());
 //--------------- ВЕСЫ-------------
 Serial.println("HX711 calibration sketch");
 
 Serial.println("Remove all weight from scale");
 Serial.println("After readings begin, place known weight on scale");
 Serial.println("Press + or a to increase calibration factor");
 Serial.println("Press - or z to decrease calibration factor");
 scale.set_scale();
 scale.tare(); //Reset the scale to 0
 long zero_factor = scale.read_average(); 
 Serial.print("Zero factor: "); 
 Serial.println(zero_factor);
}

bool stand = false;
bool laststand = false;
void loop() {
  keep_fit ();
  ves = scale.get_units(), 1;
  ves = abs(ves)*1.1237;
  
  if(ves<2){
    ves =0;
    stand = false;
    laststand= false;
  }
  else stand = true;
  
  if(stand != laststand){
    laststand= stand;
    red = random(50,255);
    green = random(50,255);
    blue = random(50,255);
  }
  
  Serial.println(ves);
  unsigned long lookT = millis();
  while(millis() - lookT < 100)  Show(ves);
}
