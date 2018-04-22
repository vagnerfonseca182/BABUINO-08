void modeRemote(){
 a:   
    incomingByte = check();   
    
    while (incomingByte == 'T') {
          stop(0);
          myServo.write(90);
          modeTracking(); 
    }
    
    while (incomingByte == 'F') {
          maju(speed);
          incomingByte = check();  
    }
    
    while (incomingByte == 'B') {
          mundur(speed);
          incomingByte = check(); 
    }
  
    while (incomingByte == 'L') {
          sikuki(speed);
          incomingByte = check();
    }
    
    while (incomingByte == 'R') {  
          sikuka(speed);
          incomingByte = check();
    }
  
    while (incomingByte == 'S'){
          stop(0);
          incomingByte = check();
    } 
    
  goto a;
}

int check()
{
  if (mySerial.available() > 0)    //Check for data on the serial lines.
  {
    dataIn = mySerial.read();  //Get the character sent by the phone and store it in 'dataIn'.
   
     if (dataIn == '0') 
        {
          speed = 0; 
        }
        else if (dataIn == '1') 
        {
          speed = 25;
        }
        else if (dataIn == '2') 
        {
          speed = 50;
        }
        else if (dataIn == '3') 
        {
          speed = 75;
        }
        else if (dataIn == '4') 
        {
          speed = 100;
        }
        else if (dataIn == '5') 
        {
          speed = 125;
        }
        else if (dataIn == '6') 
        {
          speed = 150;
        }
        else if (dataIn == '7') 
        {
          speed = 175;
        }
        else if (dataIn == '8') 
        {
          speed = 200;
        }
        else if (dataIn == '9') 
        {
          speed = 255;
        }  
  } 
}

void maju(int kec){
  //Kanan
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
  analogWrite(logicka, kec);
  //Kiri
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  analogWrite(logicki, (kec + 35));
}
void mundur(int kec){
  //Kanan
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
  analogWrite(logicka, kec);
  //Kiri
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
  analogWrite(logicki, (kec + 35)); 
}
void sikuka(int kec){
  //Kanan
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
  analogWrite(logicka, kec);
  //Kiri
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  analogWrite(logicki, (kec + 35));
}
void sikuki(int kec){
  //Kanan
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
  analogWrite(logicka, kec);
  //Kiri
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
  analogWrite(logicki, (kec + 35)); 
}
void stop(int kec){
  //Kanan
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
  analogWrite(logicka, kec);
  //Kiri
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);
  analogWrite(logicki, kec);
}
