#include <Servo.h> 
#include <IRremote.h>

// sets up servo pins
int RightServoPin 11;
int LeftServoPin 12;
// sets up servos
Servo RightServo;
Servo LeftServo;

// sets up IR Reciver
const int IR_Reciver_Pin = 4;
// Defines IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

// button ints
int forwardbutton = 2154666368; // robosapien remotes forward button
int backwardbutton = 2137888751; // robosapien remotes backward button
int left button;
int rightbutton;
int stopbutton = 136551224; // robosapien remotes stop button

void setup() {
  // set up the servos
  RightServo.attach(RightServoPin);
  LeftServo.attach(LeftServoPin);

  // set up the IR Receiver
  irrecv.enableIRIn();
}

void loop() {
  // Run ir remote command
  if (irrecv.decode(&results)){
    // Print Code in HEX
    Serial.println(results.value, HEX);
    irrecv.resume();
    // switch to make diffrent things happen with diffrent buttons
    switch(results.value){
      case backwardbutton:
      Stop();
      break;
      
      
      case forwardbutton:
      Forward();
      break;
      
      
      case backwardbutton:
      Backward();
      break;
    }
  }

}

// Moves robot forward
void Forward(){
 RightServo.write(180); //rotate counterclockwise at medium speed
 delay(1);
 LeftServo.write(180); //rotate counterclockwise at medium speed
 delay(1);
}

// Moves robot backward
void Backward(){
RightServo.write(0); //rotate clockwise at medium speed
delay(1);
LeftServo.write(0); //rotate clockwise at medium speed
delay(1);
}

void TurnLeft(){
RightServo.write(180); //rotate counterclockwise at medium speed
delay(1);
LeftServo.write(0); //rotate clockwise at medium speed
delay(1);
}

void TurnRight(){
RightServo.write(0); //rotate clockwise at medium speed
delay(1);
LeftServo.write(180); //rotate counterclockwise at medium speed
delay(1);
}

// stops robot movement
void Stop(){
RightServo.write(90); // 90 stops continuios rotation servo
delay(1);
LeftServo.write(90); // 90 stops continuios rotation servo
delay(1);
}