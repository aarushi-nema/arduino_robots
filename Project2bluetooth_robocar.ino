const int LeftForward=4;
const int LeftBackward=5;
const int RightForward=2;
const int RightBackward=3;
int ins;

void setup() {
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
  pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  while(Serial.available()>0){
    ins= Serial.read();
    Serial.print(ins);
    Serial.print("\n");

    if (ins==1){
      move_forward();
    } else if (ins==2){
      move_backward();
    } else if (ins==3){
      move_left();
    } else if (ins==4){
      move_right();
    } else if (ins==5){
      move_stop();
    }
  }
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
