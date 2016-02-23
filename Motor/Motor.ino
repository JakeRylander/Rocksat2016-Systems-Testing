void setup() {

    // constants
    #define maxStepperSpeed 0.27 // inch/s
    #define minStepperSpeed 150 // inch/s
    #define travelPerStep 0.00015625 // @ full stepping
    #define railTravel 3.193
    #define maxPeriod 75
    #define minPeriod 44

    // Stepper driver 1
    #define motor1_ena 31
    #define motor1_stp 33
    #define motor1_dir 35 
    
    
    // Stepper driver 2
    #define motor2_ena 49
    #define motor2_stp 51
    #define motor2_dir 53

    // motor 1 
    pinMode(motor1_dir, OUTPUT);
    digitalWrite(motor1_dir, LOW);
    
    pinMode(motor1_stp, OUTPUT);
    digitalWrite(motor1_stp, LOW);
    
    pinMode(motor1_ena, OUTPUT);
    digitalWrite(motor1_ena, HIGH);

    // motor 2 
    pinMode(motor2_dir, OUTPUT);
    digitalWrite(motor2_dir, LOW);
    
    pinMode(motor2_stp, OUTPUT);
    digitalWrite(motor2_stp, LOW);
    
    pinMode(motor2_ena, OUTPUT);
    digitalWrite(motor2_ena, HIGH);


    unsigned long steps = (railTravel/travelPerStep)*16;
    int period = maxPeriod;                 // set initial speed

    //Run Motors

    digitalWrite(motor1_dir, 0);  // set direction outward
    digitalWrite(motor2_dir, 0);

    digitalWrite(motor1_ena, LOW);       // enable board
    digitalWrite(motor2_ena, LOW);

    while(steps > 0)
    {
        digitalWrite(motor1_stp, HIGH);
        digitalWrite(motor2_stp, HIGH);
        delayMicroseconds(2);
        digitalWrite(motor1_stp, LOW);
        digitalWrite(motor2_stp, LOW);
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
    digitalWrite(motor1_ena, HIGH);         // disable board
    digitalWrite(motor2_ena, HIGH);         // disable board

//Run Motors opposite direction

    digitalWrite(motor1_dir, 1);  // set direction outward
    digitalWrite(motor2_dir, 1);

    digitalWrite(motor1_ena, LOW);       // enable board
    digitalWrite(motor2_ena, LOW);

    while(steps > 0)
    {
        digitalWrite(motor1_stp, HIGH);
        digitalWrite(motor2_stp, HIGH);
        delayMicroseconds(2);
        digitalWrite(motor1_stp, LOW);
        digitalWrite(motor2_stp, LOW);
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
    digitalWrite(motor1_ena, HIGH);         // disable board
    digitalWrite(motor2_ena, HIGH);         // disable board

}

void loop() {}
