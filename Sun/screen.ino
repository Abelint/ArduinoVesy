//экран на адресных

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
