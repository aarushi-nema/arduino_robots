#include<Servo.h>

const int LeftForward=4;
const int LeftBackward=5;
const int RightForward=2;
const int RightBackward=3;

Servo myservo;
int servo_pin=6;

int trig_pin=10;
int echo_pin= 11;

float distance, duration;

int left_distance=0;
int right_distance=0;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
  pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  
  myservo.attach(servo_pin);
  myservo.write(90);
  delay(2000);
  distance= calc_distance();
}

void loop() {
  distance= calc_distance();
  if(distance<=20){
    move_stop();
    delay(500);
    move_backward();
    delay(500);
    move_stop();
    delay(500);
    
    left_distance= look_left();
    right_distance= look_right();

    if(left_distance>=right_distance){
      move_left();
    } else {
      move_right();
    }
  } else {
    move_forward();
  }
  
}

int calc_distance(){
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(10);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration=pulseIn(echo_pin, HIGH);
  distance= duration*(0.034/2);
  delay(25);
  Serial.println(distance);

  return distance;
}

int look_left(){
 for(int i=90; i<=165; i++){
    myservo.write(i);
    delay(10);
  } 
  left_distance= calc_distance();
  for(int i=165; i>=90; i--){
    myservo.write(i);
    delay(10);
  } 
  return left_distance;
}

int look_right(){
  for(int i=90; i>=15; i--){
    myservo.write(i);
    delay(10);
  }
  right_distance= calc_distance();
  for(int i=15; i<=90; i++){
    myservo.write(i);
    delay(10);
  }
  return right_distance;
}

void move_stop(){
  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, LOW);
}

void move_forward(){
  digitalWrite(LeftForward, HIGH);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);
}

void move_backward(){
  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);
}

void move_left(){
  digitalWrite(LeftForward, HIGH);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);
  delay(500);
}

void move_right(){
  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);
  delay(500);
}
