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

#include "HX711.h"               // Подключаем библиотеку HX711
HX711 scale;       
uint8_t dataPin = 14;
uint8_t clockPin = 15;
float ounces;                      // Задаём переменную для измерений в унциях
float units;                       // Задаём переменную для измерений в граммах

byte segment[] = {2,3,4,5,6,7,8};
byte razr[] = {12,9,10};
int zadergka = 7;

unsigned long deltaT = 250;
unsigned long lastTime=0;
int ves =123;
void setup() {
   for(int i = 0; i<3; i++) {
    pinMode(razr[i], OUTPUT);
    digitalWrite(razr[i], HIGH);
  }
   for(int i = 0; i<7; i++){ //
    pinMode(segment[i], OUTPUT);
   digitalWrite(segment[i], HIGH);
  } 

   Serial.begin(9600);
 // Serial.println(__FILE__);

  Serial.println();

  scale.begin(dataPin, clockPin);

  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));

  Serial.println("\nEmpty the scale, press a key to continue");
  delay(1000);

  scale.tare();
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));

  int count = 9;
  unsigned long start = millis();
  while(count >0){
    
    Show(count);
    if(millis() - start >= 1000) count--;
  }
  scale.tare();

}

void loop() {
  unsigned long nowT=millis();
  
  if(nowT-lastTime>= deltaT){
    lastTime = nowT;
    
    ves = meassure();
    float mass= 2.442 * ves;
    ves = mass;
    Serial.println(ves);
  }
  if(ves < 0) ves = 0;
  Show(ves);
}

int meassure(){
  
    
  
// Serial.print("UNITS: ");
  int zamerov = 1;
  //Serial.println(scale.get_units(10));
    for (int i = 0; i < zamerov; i ++) {    // Усредняем показания, считав значения датчика 10 раз
    units = + scale.get_units(), zamerov; // Суммируем показания 10 замеров
  }
  units = units / zamerov;                // Усредняем показания, разделив сумму значений на 10
  ounces = (units * 0.035274)*10;    // Переводим вес из унций в граммы
  //Serial.print(ounces);              // Выводим в монитор последовательного порта вес в граммах
 // Serial.println(" grams");          // Выводим текст в монитор последовательного порта

  
  return ounces;//1000;
}

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

