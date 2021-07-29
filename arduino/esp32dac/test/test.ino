
const int pressuresensor = 27; // Pressure sensor input
const int pot = 26; // Potentiometer/ stretch sensor input
int sensorvalue = 0;
int outputvalue = 0;


#define DAC1 25

void setup()
{
  Serial.begin(115200);
  //pinMode(DAC1, OUTPUT); // sets the pin as output
  
}

void loop()
{
  //sensorvalue = analogRead(pressuresensor);
  //outputvalue = map(sensorvalue, 0, 1023, 0, 500);
  //pressurevalue = (sensorvalue-107)*0.66;
  //delay(1000);
  //Serial.println(sensorvalue);
  //Serial.println("　");
  if (Serial.available()) {
  char ser = Serial.read(); //read serial as a character
  
   
  //NOTE because the serial is read as “char” and not “int”, the read value must be compared to character numbers
  //hence the quotes around the numbers in the case statement
  dacWrite(DAC1, ser);
  
   }
}
