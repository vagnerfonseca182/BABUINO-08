void modeTracking(){
  b:
 
   if (mySerial.available() >0 )  {
    char c = mySerial.read();  //gets one byte from serial buffer
    //Serial.println(c);
    
    if (c == 'M'){
       stop(0);
       myServo.write(90);
       modeRemote();
    } 
    if (c == 'Z'){
       stop(0);
    }
    
    if (c == 's') {
       if (readString.length() >1) {
          double n = readString.toInt();  //convert readString into a number  
          if (readString.indexOf('a') >0){ //Servo
             x = map(n, 0, 450, 60, 120);
             readPosServo = myServo.read();
             if (readPosServo > 120){
                x = 120;
             }
             if (readPosServo < 60){
                x = 60;
             } 
             Serial.println(x);
             //--------Coding no PID-----
             
             //--------------------------
             
             //myServo.write(Output);
             
             //---- Motor Calculation---
             if (x >= 10 && x <= 180){
                maju(speedFollow); 
                scan = 0;
             }
             if (x >= 100 && x <= 120){
                myServo.write(79);
                sikuka(speedFollow);
                scan = 2; 
             }
             if (x >= 60 && x <= 79){                 
                myServo.write(100);
                sikuki(speedFollow); 
                scan = 1;
             }
             //-------------------------      
          }
          if (readString.indexOf('b') >0){ //sizeObject >> 200 Stop
             if (n >= 300 && n < 350){
                stop(0);
             }
             if (n >= 350){
                mundur(100);
             }
             if (n <= 250){
                speedFollow = map(n, 250, 0, 100, 200);
             }
          }
          if (readString.indexOf('c') >0){ //No Object >> Scan             
             if (scan == 0){
                sikuki(130);
             }
             if (scan == 1){
                sikuki(130);
             }
             if (scan == 2){
                sikuka(130);
             }
          }
          
          if (readString.indexOf('d') >0){ //modeRemote
              stop(0);
              myServo.write(90);
              modeRemote();
          }
          
          readString=""; //clears variable for new input
       }
    }
    else {     
      readString += c; //makes the string readString
    }
  }
 goto b; 
}
