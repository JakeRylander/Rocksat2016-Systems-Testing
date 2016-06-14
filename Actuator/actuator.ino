  int stand = 24;
  int PWMA = 7;
  int AIN1 = 26;
  int AIN2 = 28;
  
void setup() {
  pinMode (stand, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);

}

void loop() {
  movement (1,255,1);
  delay(5000);
  movement (1,255,0);
  delay(5000);
  stopga();
}

void movement (int motor, int spd, int dir){

  digitalWrite(stand, HIGH);

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (dir == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
}

  else{
    inPin1 = LOW;
    inPin2 = HIGH;
  }
  if (motor == 1){
      digitalWrite(AIN1, inPin1);
      digitalWrite(AIN2, inPin2);
      analogWrite (PWMA, spd);
    }
}

void stopga(){digitalWrite(stand, LOW);}
