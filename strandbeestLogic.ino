#include <SparkFun_TB6612.h>

const int offsetA = 1;
const int offsetB = 1;
const int AIN1 = 8;
const int BIN1 = 12;
const int AIN2 = 7;
const int BIN2 = 13;
const int PWMA = 5;
const int PWMB = 6;
const int STBY = 9;
#define PIR_AOUT A0  // PIR analog output on A0
#define PIR_DOUT 2   // PIR digital output on D2
#define LED_PIN  13  // LED to illuminate on motion
#define PRINT_TIME 100
#define LIGHT_SENSOR A2

volatile unsigned long lastPrint = 0;
volatile bool hasMotion = false;
volatile bool hostile = false;
volatile unsigned int analogLight = 0;
volatile float voltage = 0;
volatile int timesBothered = 0;

Motor leftLeg = Motor(AIN1,AIN2,PWMA,offsetA,STBY);
Motor rightLeg = Motor(BIN1,BIN2,PWMB,offsetB,STBY);

void setup() {
    Serial.begin(115200);  // Serial is used to view Analog out
    // Analog and digital pins should both be set as inputs:
    pinMode(PIR_AOUT, INPUT);
    pinMode(PIR_DOUT, INPUT);
    pinMode(LIGHT_SENSOR, INPUT);
    attachInterrupt(0,setMotion,RISING);
    delay(2000);
    Serial.println("Time to Dance!");
    dance();
}

void loop()
{
   if(timesBothered == 3){
      Serial.println("Hostile Mode!");
      hostile = true;
   }else if(timesBothered == 0){
      hostile = false;
      
   }
   
   if(hasMotion && hostile){ // attack mode!
      Serial.println("Attacking Mode");
      attack();
      hasMotion = false;
      timesBothered--;
      
   }else if(hasMotion){ //scared mode!
      Serial.println("Scared Mode");
      backAway();
      hasMotion = false;
      timesBothered++;
      
   }else{
      Serial.println("Chill Mode");
         
   }
  Serial.print(timesBothered);
  Serial.println(" Times Bothered");
  escapeFromLight();
}

void escapeFromLight(){
  analogLight = analogRead(LIGHT_SENSOR);
  voltage = (float) analogLight / 1024.0 * 5.0;
  Serial.print(voltage);
  Serial.println(" volts from light sensor");
  while(voltage <= 4.25 && voltage > 0){
    turnAndRun();
    analogLight = analogRead(LIGHT_SENSOR);
    voltage = (float) analogLight / 1024.0 * 5.0;
  }
}

void attack(){
  Serial.println("Attacking!!");
  moveForward(3500);
  brake(leftLeg,rightLeg);
}

void turnAndRun(){
  Serial.println("Turning and Running!!");
  spinLeft(3000);
  moveForward(3000);
  brake(leftLeg,rightLeg);
}

void setMotion(){
  hasMotion = true;
}

void dance(){
  spinLeft(1000);
  spinRight(1000);
  moveForward(1000);
  spinLeft(4000);
  spinRight(4000);
  backAway();
}

void moveForward(int duration){
  Serial.println("Moving Forward");
  forward(leftLeg,rightLeg,200);
  delay(duration);
}

void spinLeft(int duration){
  Serial.println("spinning left");
  left(leftLeg,rightLeg,255);
  delay(duration); 
}

void spinRight(int duration){
  Serial.println("spinning right");
  right(leftLeg,rightLeg,255);
  delay(duration); 
}


void backAway(){
  Serial.println("Backing Away!!");
  back(leftLeg,rightLeg,150);
  delay(1000);  
  brake(leftLeg,rightLeg); 
}


void readDigitalValue()
{
  // The OpenPIR's digital output is active high
  int motionStatus = digitalRead(PIR_DOUT);

  // If motion is detected, turn the onboard LED on:
  if (motionStatus == HIGH){
    Serial.println("DIG HIGH");
//    Serial.println('motionStatus');
    digitalWrite(LED_PIN, HIGH);
  }else{ // Otherwise turn the LED off:
    Serial.println("DIG LOW");
//    Serial.println('motionStatus');
    digitalWrite(LED_PIN, LOW);
  }
}

void printAnalogValue()
{
  if ( (lastPrint + PRINT_TIME) < millis() )
  {
    lastPrint = millis();
    // Read in analog value:
    unsigned int analogPIR = analogRead(PIR_AOUT);
//    // Convert 10-bit analog value to a voltage
//    // (Assume high voltage is 5.0V.)
    float voltage = (float) analogPIR / 1024.0 * 5.0;
//    // Print the reading from the digital pin.
//    // Mutliply by 5 to maintain scale with AOUT. 
    Serial.print(digitalRead(PIR_DOUT));
    Serial.print(',');    // Print a comma
    Serial.print(2.5);    // Print the upper limit
    Serial.print(',');    // Print a comma
    Serial.print(1.7);    // Print the lower limit
    Serial.print(',');    // Print a comma
    Serial.print(voltage); // Print voltage
    Serial.println();
//    return digitalRead(PIR_DOUT);
  }
}

void printLightValue()
{
  if ( (lastPrint + PRINT_TIME) < millis() )
  {
    lastPrint = millis();
    // Read in analog value:
    unsigned int analogPIR = analogRead(LIGHT_SENSOR);
//    // Convert 10-bit analog value to a voltage
//    // (Assume high voltage is 5.0V.)
    float voltage = (float) analogPIR / 1024.0 * 5.0;
//    // Print the reading from the digital pin.
//    // Mutliply by 5 to maintain scale with AOUT. 
    Serial.print(digitalRead(PIR_DOUT));
    Serial.print(',');    // Print a comma
    Serial.print(2.5);    // Print the upper limit
    Serial.print(',');    // Print a comma
    Serial.print(1.7);    // Print the lower limit
    Serial.print(',');    // Print a comma
    Serial.print(voltage); // Print voltage
    Serial.println();
//    return digitalRead(PIR_DOUT);
  }
}