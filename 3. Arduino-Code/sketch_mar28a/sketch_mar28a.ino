#include <HC05.h>

int motor1Pin1 = 4;
int motor1Pin2 = 5; 
int enable1Pin = 3; 
int motor2Pin1  = 12; 
int motor2Pin2 = 13;
int enable2Pin = 11; 
int state;
int flag = 0;        
int stateStop = 0;
bool autonomousMode = true; // Flag to indicate autonomous mode
int autonomousDelay = 5000; // Delay time in autonomous mode (in milliseconds)

void setup() {
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin,  OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    // sets enable1Pin and enable2Pin high so that motor can turn on:
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {     
        state = Serial.read();   
        flag = 0;
    }

    // Handling autonomous mode
    if (state == 'A') {
        autonomousMode = true;
    } else if (state == 'M') {
        autonomousMode = false;
        stateStop = 1; // Stop the robot when exiting autonomous mode
    }

    // If in autonomous mode, move back and forth
    if (autonomousMode) {
        if (flag == 0) {
            Serial.println("Autonomous mode active");
            flag = 1;
        }

        // Move forward
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        delay(autonomousDelay);

        // Stop
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        delay(1000);

        // Move backward
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        delay(autonomousDelay);

        // Stop
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        delay(1000);
    } else {
        // Manual control mode
        if (state == 'F') {
            Serial.println("Go Forward!");
            digitalWrite(motor1Pin1, HIGH);
            digitalWrite(motor1Pin2, LOW); 
            digitalWrite(motor2Pin1, LOW);
            digitalWrite(motor2Pin2, HIGH);
            if (flag == 0) {
                Serial.println("Go Forward!");
                flag = 1;
            }
        }
        else if (state == 'R') {
            Serial.println("Turn  LEFT");
            digitalWrite(motor1Pin1,  HIGH); 
            digitalWrite(motor1Pin2, LOW); 
            digitalWrite(motor2Pin1,  LOW);
            digitalWrite(motor2Pin2, LOW);
            if(flag == 0){
              Serial.println("Turn  LEFT");
              flag=1;
            }
            delay(1000);
            state=3;
            stateStop=1;
        }
        else if (state == 'S' || stateStop == 1) {
            Serial.println("STOP!");
            digitalWrite(motor1Pin1,  LOW); 
            digitalWrite(motor1Pin2, LOW); 
            digitalWrite(motor2Pin1,  LOW);
            digitalWrite(motor2Pin2, LOW);
            if(flag == 0){
              Serial.println("STOP!");
              flag=1;
            }
            stateStop=0;
        }
        else if (state == 'L') {
            Serial.println("Turn  RIGHT");
            digitalWrite(motor1Pin1,  LOW); 
            digitalWrite(motor1Pin2, LOW); 
            digitalWrite(motor2Pin1,  LOW);
            digitalWrite(motor2Pin2, HIGH);
            if(flag == 0){
              Serial.println("Turn  RIGHT");
              flag=1;
            }
            delay(1000);
            state=3;
            stateStop=1;
        }
        else if (state == 'B') {
            Serial.println("Reverse!");
            digitalWrite(motor1Pin1, LOW); 
            digitalWrite(motor1Pin2,  HIGH);
            digitalWrite(motor2Pin1, HIGH);
            digitalWrite(motor2Pin2,  LOW);
            if(flag == 0){
              Serial.println("Reverse!");
              flag=1;
            }
        }
        //For debugging purpose
        //Serial.println(state);
    }
}
