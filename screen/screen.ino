
byte segment[] = {2,3,4,5,6,7,8};
byte razr[] = {12,9,10};
int zadergka = 7;
void setup() {
   for(int i = 0; i<3; i++) {
    pinMode(razr[i], OUTPUT);
    
  }
  for(int i = 0; i<3; i++) {
    
    digitalWrite(razr[i], HIGH);
    
  }
   for(int i = 0; i<7; i++){ //
    pinMode(segment[i], OUTPUT);
   
  } 

 
 
}

void loop() {
 Show(123);

}
void clear(){
  for(int i = 0; i<sizeof(razr)/sizeof(razr[0]); i++) digitalWrite(razr[i], LOW);
  for(int i = 0; i<sizeof(segment)/sizeof(segment[0]); i++) digitalWrite(segment[i], LOW);
}

void Show(int n){
  int mas[3];
  mas[0] = n%10;
  n=n/10;
  mas[1] = n%10;  
  mas[2] = n/10;
  
  for(int i = 0; i<sizeof(razr)/sizeof(razr[0]); i++) digitalWrite(razr[i], LOW);
  for(int i = 0; i<sizeof(razr)/sizeof(razr[0]); i++){
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
