void setup() {
  #define Proximity_sensor A3
  pinMode(Proximity_sensor, INPUT);
  Serial.begin(9600);
  Serial.print("Test run");
  while(true){
      int value = analogRead(Proximity_sensor);
      Serial.print("Proximity Sensor Data Value at:");
      Serial.println(value);
      delay(100);
  }
}

void loop() {
}


