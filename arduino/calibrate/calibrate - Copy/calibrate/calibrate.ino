/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.
 // channel one on top two on bottom

 */

// These constants won't change.  They're used to give names
// to the pins used:
//const int analogIn = A2;
const int pot = 33;
int potvalue;
int minvalue = 600;
int maxvalue = 0;
int i = 0;
#define DAC1 25
/*const int analogInPin = A2;  
const int analogInPinpot = A7;
double pressurevalue;

int sensorValue;
const int onoff = 8;

int inst = 0;*/

void setup() {
  Serial.begin(9600);
  pinMode(pot, OUTPUT);
  //AutoCalibrate(minvalue, maxvalue);

  /*while (millis() < 5000)
  {
    potvalue = analogRead(pot);
    Serial.println(potvalue);
    if (potvalue>maxvalue){
      maxvalue = potvalue;
      }
    if(potvalue<minvalue){
      minvalue = potvalue;
      }
    } */
  
  //Serial.println(maxvalue);
}

void loop() {
  //Serial.println(analogRead(pot));
  if(Serial.available()){
    i = Serial.read();
    if(i == '1'){
      digitalWrite(pot, HIGH);
      delay(1000);
      digitalWrite(pot, LOW);
      }
      else if(i== '0'){
        digitalWrite(pot, LOW);
        }
    //int raw = Serial.parseInt();
    //dacWrite(DAC1, raw);
    }
}

  /*if(Serial.available()){
    inst = Serial.read();
    if(inst = '1'){
      digitalWrite(onoff, HIGH);
      }
      if(inst = '0'){
        digitalWrite(onoff, LOW);
        }
    }*/
    
  
  //sensorValue = analogRead(analogInPin);
  /*potvalue = analogRead(pot);
  //MdacWrite(25, 25);
  //Serial.print("\n sensor X = ");
  
  //pressurevalue = (sensorValue-107)*0.00063;
  Serial.println(potvalue);
  /*Serial.print(",");
  Serial.print(potvalue);
  Serial.println(",");
  //Serial.print("\n");
  //if (sensorValue>800)
  //{
  //  digitalWrite(10,HIGH);
   //delay(1000);
   // digitalWrite(10,LOW);
   // }
   //if (Serial.available()) {
  //inst = Serial.parseInt(); //read serial as a character  
  //Serial.print("I received: ") ;
  //Serial.println(inst);
  //NOTE because the serial is read as “char” and not “int”, the read value must be compared to character numbers
  //hence the quotes around the numbers in the case statement
  //dacWrite(DAC1, inst);  
  //}*/   
