//Arduino基板ピン配置設定  Board pin arrangement setting
//evaluate solenoid pwm switching
//int yamahasensor = 0;
//int pressuresensor = 5;
//int pwm = 11;
//int onoff = 2;
//int off = 2;
//int INTERVAL = 5000;
//int DAC1 = 3; // output pin supporting PWM
//int inPin = 3; // voltage connected to analog pin 3, e.g. a potentiometer
//int val = 0; // variable to store the read value
//float volt = 0; // variable to hold the voltage read
const int analogPin_read = A3;
int sensorvalue = 0;
double pressurevalue;
int outputvalue = 0;
#define DAC1 25

void setup()
{
  Serial.begin(115200);
  //pinMode(DAC1, OUTPUT); // sets the pin as output
  
}

void loop()
{
  sensorvalue = analogRead(analogPin_read);
  outputvalue = map(sensorvalue, 0, 1023, 0, 500);
  pressurevalue = (sensorvalue-107)*0.66;
  delay(1000);
  Serial.println(pressurevalue);
  Serial.println("　");
  if (Serial.available()) {
  char ser = Serial.read(); //read serial as a character
  
   
  //NOTE because the serial is read as “char” and not “int”, the read value must be compared to character numbers
  //hence the quotes around the numbers in the case statement
  //dacWrite(DAC1, ser);
  switch (ser)
  {
    case '0':
    dacWrite(DAC1, 0);
    break;

    case '1':
    dacWrite(DAC1, 10);
    break;

    case '2':
    dacWrite(DAC1, 20);
    break;
    
    case '3':
    dacWrite(DAC1, 30);
    break;

    case '4':
    dacWrite(DAC1, 40);
    break;
    
    case '5':
    dacWrite(DAC1, 50);
    break;

    case '6':
    dacWrite(DAC1, 60);
    break;
    
    case '7':
    dacWrite(DAC1, 70);
    break;

    case '8':
    dacWrite(DAC1, 80);
    break;

    case '9':
    dacWrite(DAC1, 90);
    break;

    case 'a':
    dacWrite(DAC1, 100);
    break;
    
    case 'b':
    dacWrite(DAC1, 110);
    break;

    case 'c':
    dacWrite(DAC1, 120);
    break;
    
    case 'd':
    dacWrite(DAC1, 130);
    break;

    case 'e':
    dacWrite(DAC1, 140);
    break;
    
    case 'f':
    dacWrite(DAC1, 150);
    break;

    case 'g':
    dacWrite(DAC1, 160);
    break;
    
    case 'h':
    dacWrite(DAC1, 170);
    break;

    case 'i':
    dacWrite(DAC1, 180);
    break;
    
    case 'j':
    dacWrite(DAC1, 190);
    break;

    case 'k':
    dacWrite(DAC1, 200);
    break;

    case 'l':
    dacWrite(DAC1, 210);
    break;

    case 'm':
    dacWrite(DAC1, 220);
    break;
    
    case 'n':
    dacWrite(DAC1, 230);
    break;

    case 'o':
    dacWrite(DAC1, 240);
    break;

    case 'p':
    dacWrite(DAC1, 250);
    break;

/*    case 'q':
    dacWrite(DAC1, 202);
    break;
    case 'r':
    dacWrite(DAC1, 203);
    break;

    case 's':
    dacWrite(DAC1, 204);
    break;

    case 't':
    dacWrite(DAC1, 205);
    break;

    case 'u':
    dacWrite(DAC1, 206);
    break;

    case 'v':
    dacWrite(DAC1, 207);
    break;

    case 'x':
    dacWrite(DAC1, 208);
    break;

    case 'y':
    dacWrite(DAC1, 209);
    break;

    case 'z':
    dacWrite(DAC1, 210);
    break;*/
    //default:
    
    //Serial.println("Invalid entry");

   }
}
}
  /*val = analogRead(inPin); // read the input pin
  volt =(5.0 * val) / 1023;
  val = 255 * (volt / 5);
  dacWrite(pwmPin, val);*/
