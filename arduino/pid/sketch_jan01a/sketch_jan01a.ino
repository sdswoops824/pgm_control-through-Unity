#include <PID_v1.h>

//define the constants

const int pressuresensor = 27; // Pressure sensor input
const int pot = 26; // Potentiometer/ stretch sensor input
const int pwmout = 5; // PWM output
# define DAC1 25
int potvalue = 0;
int maxvalue = 0;
int minvalue = 5000;
int minpotvalue, maxpotvalue;
int pressureLevel;
const int onoff = 33;

// Tuning parameters
float Kp=5; //Initial Proportional Gain
float Ki=5; //Initial Integral Gain
float Kd=0; //Initial Differential Gain
double Setpoint, Input, Output; //These are just variables for storingvalues
double pressurevalue;


PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
// This sets up our PDID Loop
//Input is our PV
//Output is our u(t)
//Setpoint is our SP

const int sampleRate = 1; // Variable that determines how fast our PID loop runs

// Communication setup
const long serialPing = 10; //This determines how often we ping our loop

// Serial pingback interval in milliseconds
unsigned long now = 0; //This variable is used to keep track of time

// placehodler for current timestamp
unsigned long lastMessage = 0; //This keeps track of when our loop last spoke to serial

// last message timestamp.

void setup(){
  
  pinMode(onoff, OUTPUT);

  //begin calibration 
  
  while (millis() < 3000)
  {
    //set the min max value
    potvalue = analogRead(pot);    
    
    if (potvalue>maxvalue){
      maxvalue = potvalue;
    }
    if(potvalue<minvalue){
      minvalue = potvalue;
    }
  }
  minpotvalue = minvalue;
  maxpotvalue = maxvalue;

  digitalWrite(onoff, HIGH);
  delay(150);
  digitalWrite(onoff, LOW);
      
  pressureLevel = analogRead(pressuresensor); //Read in light level
  
  Input = map(pressureLevel, 752, 3280, 20, 230); //Change read scale to analog out scale
  Setpoint = map(analogRead(pot), minpotvalue, maxpotvalue, 20, 230); //get our setpoint from our pot
  Serial.begin(115200); //Start a serial session
  myPID.SetMode(AUTOMATIC); //Turn on the PID loop
  myPID.SetSampleTime(sampleRate); //Sets the sample rate
  //Serial.println("Begin"); // Hello World!
  lastMessage = millis(); // timestamp  
}

void loop(){
  Setpoint = map(analogRead(pot), minpotvalue, maxpotvalue, 20, 230); //Read our setpoint
  pressureLevel = analogRead(pressuresensor); //Get the pressure level
  pressurevalue = (0.0001*pressureLevel) - 0.0452;
  Input = map(pressureLevel, 752, 3280, 20, 230); //Map it to the right scale
  myPID.Compute(); //Run the PID loop
  
  dacWrite(DAC1, Output); //Write out the output from the PID loop to our LED pin
  
  if(Serial.available()){
    int data = Serial.read();

    if(data == '1'){      
      digitalWrite(onoff, HIGH);
      dacWrite(DAC1, 0);
      delay(300);
      digitalWrite(onoff, LOW);
      dacWrite(DAC1, 0);
      delay(300);
      digitalWrite(onoff, HIGH);
      dacWrite(DAC1, 0);
      delay(300);
      digitalWrite(onoff, LOW); 
      dacWrite(DAC1, Output);        
      }       
  
    if(data == '2'){        
      dacWrite(DAC1, Output+80);
      delay(1000);
      dacWrite(DAC1, Output);
      delay(1000);
      dacWrite(DAC1, Output+80);
      delay(1000);
      dacWrite(DAC1, Output);          
    }  

    if(data == '3'){    
      dacWrite(DAC1, Output+80);     
      delay(2000);
      dacWrite(DAC1, Output);        
    }

    if(data == '4'){   
      dacWrite(DAC1, Output+80);      
      delay(500);
      dacWrite(DAC1, Output);  
      digitalWrite(onoff, HIGH);
      delay(300);
      digitalWrite(onoff, LOW);
    }  

    else{
      dacWrite(DAC1, Output);
      digitalWrite(onoff, LOW);  
    }
  }


  now = millis(); //Keep track of time
  if(now - lastMessage > serialPing) { //If it has been long enough give us some info on serial
  // this should execute less frequently
  // send a message back to the mother ship
  //Serial.print("Setpoint = ");
  Serial.print(Setpoint);
  Serial.print (",");
  //Serial.print(" Input = ");
  Serial.print(Input);
  Serial.print (",");
  //Serial.print(" Output = ");
  //Serial.print(Output);
  //Serial.print(" Pressure sensor value = ");
  Serial.print(pressurevalue);
  //Serial.print (",");
  /*Serial.print(" Kp = ");
  Serial.print(Kp);
  Serial.print(" Ki = ");
  Serial.print(Ki);
  Serial.print(" Kd = ");
  Serial.print(Kd);*/
  //Serial.print("\n");
  Serial.println("");

  /*if (Serial.available() > 0) { //If we sent the program a command deal with it
  for (int x = 0; x < 4; x++) {
  switch (x) {
  case 0:
  Kp = Serial.parseFloat();
  break;
  case 1:
  Ki = Serial.parseFloat();
  break;
  case 2:
  Kd = Serial.parseFloat();
  break;
  case 3:
  for (int y = Serial.available(); y == 0; y--) {
  //Serial.read(); //Clear out any residual junk
  }
  break;
  }
  }
  Serial.print(" Kp,Ki,Kd = ");
  Serial.print(Kp);
  Serial.print(",");
  Serial.print(Ki);
  Serial.print(",");
  Serial.println(Kd); //Let us know what we just received
  myPID.SetTunings(Kp, Ki, Kd); //Set the PID gain constants and start running
  }*/
  lastMessage = now;
  //update the time stamp.
  }
}
