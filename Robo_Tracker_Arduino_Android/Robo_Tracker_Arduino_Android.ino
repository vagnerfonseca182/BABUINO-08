#include <SoftwareSerial.h>
#include <Servo.h> 
 
Servo myServo;  

SoftwareSerial mySerial (10 , 11);

int logicki = 6; 
int inA1 = 7;
int inA2 = 8;

int logicka = 3;
int inB1 = 4;
int inB2 = 5;

String readString;

char dataIn, incomingByte;
int speed = 0;

int pinRemote   = 2;
int pinTracking = 9;

int readRemote;
int readTracking;

int setMode = 1; // IF 1 = Remote, 2 = Tracking

char speedFollow = 0; //Set Speed for tracking 

double readPosServo;

double x;

int scan = 0; // 1 = Kiri,  2 = Kanan

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  
  pinMode(logicki, OUTPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  
  pinMode(logicka, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  
  pinMode(pinRemote, INPUT_PULLUP);
  pinMode(pinTracking, INPUT_PULLUP);
  
  myServo.attach(13);
  myServo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  modeTracking();
  
  readRemote   = digitalRead(pinRemote);
  readTracking = digitalRead(pinTracking);
  
  if (readRemote == LOW){
     mySerial.println("R");
     delay(250);
     setMode = 1;
     modeRemote();
  }
  if (readTracking == LOW){
     mySerial.println("T");
     delay(250);
     setMode = 2;
     modeTracking();
  }
  if (setMode == 1){
     modeRemote();
  }
  if (setMode == 2){
     modeTracking();
  }
 
     
}
