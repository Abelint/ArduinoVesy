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
float calibration_factor = -10000; //-5050;//для тензы лигера


byte segment[] = {2,3,4,5,6,7,8};
byte razr[] = {12,9,10};
int zadergka = 1;

unsigned long deltaT = 250;
unsigned long lastTime=0;
float ves =123;

int minValue = 5;
 
void keep_fit () {
 scale.set_scale(calibration_factor); //Adjust to this calibration factor
 
 if(Serial.available())
 {
  char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
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
    Show(123);
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
  ves = abs(ves)*0.45*2.53;
  
  if(ves<5){
    ves =0;
    stand = false;
    laststand= false;
  }
  else stand = true;
  
  if(stand != laststand){
    laststand= stand;
    red = random(255);
    green = random(255);
    blue = random(255);
  }
  
  Serial.println(ves);
  unsigned long lookT = millis();
  while(millis() - lookT < 100)  Show(ves);
}
/* экран на обычной ленте 12В
void clear(){
  for(int i = 0; i<sizeof(razr)/sizeof(razr[0]); i++) digitalWrite(razr[i], LOW);
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
}

void Show(int n){
  int mas[3];
  mas[0] = n%10;
  int m=n/10;
  mas[1] = m%10;  
  mas[2] = m/10;
  
  for(int i = 0; i<sizeof(razr)/sizeof(razr[0]); i++) digitalWrite(razr[i], LOW);
  for(int i = 0; i<sizeof(razr)/sizeof(razr[0]); i++){
    if(n <100 && i == 2) continue;
    if(n <10 && i == 1) continue;
    digitalWrite(razr[i], HIGH);
    Num(mas[i]);
    delay(zadergka);
    clear();
    //digitalWrite(razr[i], LOW);
  }
 
  
}

void Num(int n){
  if(n==0) zero();
  else if(n==1) one();
  else if(n==2) two();
  else if(n==3) three();
  else if(n==4) four();
  else if(n==5) five();
  else if(n==6) six();
  else if(n==7) seven();
  else if(n==8) eight();
  else if(n==9) nine();
}
void one(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[1], HIGH);
  digitalWrite(segment[2], HIGH);
}
void two(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[0], HIGH);
  digitalWrite(segment[1], HIGH);
  digitalWrite(segment[3], HIGH);
  digitalWrite(segment[4], HIGH);
  digitalWrite(segment[6], HIGH);
}
void three(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[0], HIGH);
  digitalWrite(segment[1], HIGH);
  digitalWrite(segment[3], HIGH);
  digitalWrite(segment[2], HIGH);
  digitalWrite(segment[6], HIGH);
}
void four(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[1], HIGH);
  digitalWrite(segment[5], HIGH);
  digitalWrite(segment[2], HIGH);
  digitalWrite(segment[6], HIGH);
}
void five(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[0], HIGH);
  digitalWrite(segment[5], HIGH);
  digitalWrite(segment[3], HIGH);
  digitalWrite(segment[2], HIGH);
  digitalWrite(segment[6], HIGH);
}
void six(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[0], HIGH);
  digitalWrite(segment[5], HIGH);
  digitalWrite(segment[3], HIGH);
  digitalWrite(segment[2], HIGH);
  digitalWrite(segment[4], HIGH);
  digitalWrite(segment[6], HIGH);
}

void seven(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[0], HIGH);
  digitalWrite(segment[1], HIGH);
  digitalWrite(segment[2], HIGH);
}
void eight(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[0], HIGH);
  digitalWrite(segment[1], HIGH);
  digitalWrite(segment[5], HIGH);
  digitalWrite(segment[3], HIGH);
  digitalWrite(segment[2], HIGH);
  digitalWrite(segment[4], HIGH);
  digitalWrite(segment[6], HIGH);
}
void nine(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[0], HIGH);
  digitalWrite(segment[1], HIGH);
  digitalWrite(segment[5], HIGH);
  digitalWrite(segment[3], HIGH);
  digitalWrite(segment[2], HIGH);
  digitalWrite(segment[6], HIGH);
}
void zero(){
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
  digitalWrite(segment[0], HIGH);
  digitalWrite(segment[1], HIGH);
  digitalWrite(segment[5], HIGH);
  digitalWrite(segment[3], HIGH);
  digitalWrite(segment[2], HIGH);
  digitalWrite(segment[4], HIGH);
}
*/
