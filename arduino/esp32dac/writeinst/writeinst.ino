
const int analogPin_read = A3;
int sensorvalue = 0;
double pressurevalue;
int outputvalue = 0;
#define DAC1 25
int inst = 0;

void setup()
{
  Serial.begin(115200); 
}

void loop()
{
  //sensorvalue = analogRead(analogPin_read);
  //outputvalue = map(sensorvalue, 0, 1023, 0, 500);
  //pressurevalue = (sensorvalue-107)*0.66;
  //delay(1000);
  //Serial.println(pressurevalue);
  //Serial.println("　");
  if (Serial.available()) {
  inst = Serial.parseInt(); //read serial as a characters 
  Serial.print("I received: ") ;
  Serial.println(inst);
  //NOTE because the serial is read as “char” and not “int”, the read value must be compared to character numbers
  //hence the quotes around the numbers in the case statement
  //dacWrite(DAC1, inst);
  
  }
}
