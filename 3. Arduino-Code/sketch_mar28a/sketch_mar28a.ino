int motor1Pin1 = 4;
int motor1Pin2 = 5; 
int enable1Pin = 3; 
int motor2Pin1  = 12; 
int motor2Pin2 = 13;
int enable2Pin = 11; 
int state;
int flag=0;        
int stateStop=0;
void setup() {
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin,  OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    // sets enable1Pin and enable2Pin high so  that motor can turn on:
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin,  HIGH);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
    /*if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is 'F' the DC motor will  go forward
    if (state == 'F') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Go  Forward!");
          flag=1;
        }
    }
    
    // if the  state is 'R' the motor will turn left
    else if (state == 'R') {
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
    // if the state is 'S' the motor will Stop
    else if (state == 'S' || stateStop == 1) {
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
    // if the  state is 'L' the motor will turn right
    else if (state == 'L') {
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
    // if the state is 'B' the motor will Reverse
    else if (state == 'B') {
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
    Serial.println(state);*/
}