void setup() {

    // constants
    #define maxStepperSpeed 0.27 // inch/s
    #define minStepperSpeed 150 // inch/s
    #define travelPerStep 0.00015625 // @ full stepping
    #define railTravel 3.193
    #define maxPeriod 75
    #define minPeriod 44

    // Stepper Motor Definitions
    #define motor1_ena 31
    #define motor1_stp 33
    #define motor1_dir 35 

    //Actuator Definitons

    #define stand 24
    #define PWMA 7
    #define AIN1 26
    #define AIN2 28

    // Stepper Motor Pin Definitions
    pinMode(motor1_dir, OUTPUT);
    digitalWrite(motor1_dir, LOW);
    
    pinMode(motor1_stp, OUTPUT);
    digitalWrite(motor1_stp, LOW);
    
    pinMode(motor1_ena, OUTPUT);
    digitalWrite(motor1_ena, HIGH);
  
    //Actuator Motor Pin Definitions
    pinMode (stand, OUTPUT);
    digitalWrite(stand, LOW);
    
    pinMode (PWMA, OUTPUT);
    digitalWrite(PWMA, LOW);
    
    pinMode (AIN1, OUTPUT);
    digitalWrite(AIN1, LOW);
    
    pinMode (AIN2, OUTPUT);
    digitalWrite(AIN2, LOW);
}

void loop() {
  
  movedoor(1);
  delay(2000);
  movedoor(0);
  delay(2000);
  
  
}

void movedoor(int direction) {

    //More Constants
    unsigned long steps = (railTravel/travelPerStep)*16;
    int period = maxPeriod;                 // set initial speed


    //Opening Obi
    if (direction == 1){

      digitalWrite(motor1_dir, 1);  // Set Direction Outward
      digitalWrite(motor1_ena, LOW); //Enable Motor

      digitalWrite(stand, HIGH); //Enable Actuator
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);

      //Actuator Movement

      analogWrite (PWMA, 90);
      delay(2000);
      analogWrite (PWMA, 0);

      //Motor Movement
  
      while(steps > 0)
      {
          digitalWrite(motor1_stp, HIGH);
          delayMicroseconds(2);
          digitalWrite(motor1_stp, LOW);
          delayMicroseconds(period);
  
          if( steps >= 3200)
          {
              if(period > minPeriod && steps % 400 == 0)       // on the first revolutions
                  period--;           // the period of the pulse is decrease to accelerate
          }
          else if( steps < 200)
          {
              period++;               // increase to decelerate
          }
          else{}
          steps--;
      }
      digitalWrite(motor1_ena, HIGH); //Disable Motor
      digitalWrite(stand, LOW); //Disable Actuator
    
    }

  //Closing Obi
  else if (direction == 0) {
  

    digitalWrite(motor1_dir, 0);  // Set Direction Inward
    digitalWrite(motor1_ena, LOW); //Enable Motor

    digitalWrite(stand, HIGH); //Enable Actuator
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);

    while(steps > 0)
    {
        digitalWrite(motor1_stp, HIGH);
        delayMicroseconds(2);
        digitalWrite(motor1_stp, LOW);
        delayMicroseconds(period);

        if( steps >= 3200)
        {
            if(period > minPeriod && steps % 400 == 0)       // on the first revolutions
                period--;           // the period of the pulse is decrease to accelerate
        }
        else if( steps < 200)
        {
            period++;               // increase to decelerate
        }
        else{}
        steps--;
    }

  //actuator movement

   analogWrite (PWMA, 90);
      delay(2000);
      analogWrite (PWMA, 0);

    digitalWrite(motor1_ena, HIGH); //Disable Motor
    digitalWrite(stand, LOW); //Disable Actuator
  }
}
