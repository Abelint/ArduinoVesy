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
