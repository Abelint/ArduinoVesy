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
#define DOUT  14
#define CLK  15
HX711 scale(DOUT, CLK);
float calibration_factor = -10000; //-5050;//для тензы лигера

 void motor (bool s) {
  if (s==1){
    digitalWrite( in1, HIGH ); 
    digitalWrite( in2, HIGH ); 
    digitalWrite( in3, LOW ); 
    digitalWrite( in4, LOW );
    delay(10);

    digitalWrite( in1, LOW ); 
    digitalWrite( in2, HIGH ); 
    digitalWrite( in3, HIGH ); 
    digitalWrite( in4, LOW );
    delay(10);

    digitalWrite( in1, LOW ); 
    digitalWrite( in2, LOW ); 
    digitalWrite( in3, HIGH ); 
    digitalWrite( in4, HIGH );
    delay(10);

    digitalWrite( in1, HIGH ); 
    digitalWrite( in2, LOW ); 
    digitalWrite( in3, LOW ); 
    digitalWrite( in4, HIGH );
    delay(10);}
    if (s==0) {
digitalWrite( in1, LOW); 
digitalWrite( in2,LOW ); 
digitalWrite( in3, LOW ); 
digitalWrite( in4, LOW );
delay (5);}
    }
void keep_fit () {
 scale.set_scale(calibration_factor); //Adjust to this calibration factor
 Serial.print("Reading: ");
 Serial.print(scale.get_units(), 1);
 Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
 Serial.print(" calibration_factor: ");
 Serial.print(calibration_factor);
 Serial.println();
 if(Serial.available())
 {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }}

    
void setup() {
  pinMode( pin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  
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

void loop() {
  keep_fit ();
  color= digitalRead (pin);
  Serial.println (color);
  Serial.print(i);
  if ( color==1 and flag==0){
    flag=1;
    i++;
  }
  delay (300);
  if ( color==0) {
   flag=0; }
   if ( i==12){i=0;}
   //-----------просто так пробник-----------
if (i<6) {
  motor(1);}   
if ( i ==6) {motor (0);}
}