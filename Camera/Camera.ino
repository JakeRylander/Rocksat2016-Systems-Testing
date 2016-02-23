void setup() {

  #define camera_trig 25
  #define camera_rec 27
  
  pinMode(camera_trig, OUTPUT);
  digitalWrite(camera_trig, LOW);
  pinMode(camera_rec, OUTPUT);
  digitalWrite(camera_rec, LOW);

  //Run Camera

      digitalWrite(camera_trig, HIGH);
      delay(250);
      digitalWrite(camera_trig, LOW);
      delay(1000);
      digitalWrite(camera_rec, HIGH);
      delay(250);
      digitalWrite(camera_rec, LOW);
  
}

void loop() {

}
