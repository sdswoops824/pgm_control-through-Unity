//SWITCHING

// These constants won't change.  They're used to give names
// to the pins used:

//const int transistorPin0 = 4;
const int transistorPin1 = 12;
const int transistorPin2 = 10;
const int transistorPin3 = 8;
const int transistorPin4 = 6;
int data = 0;
int w = 0;
unsigned long now = millis ();

void setup() {
  Serial.begin(9600);
  //pinMode (transistorPin0, OUTPUT);
  pinMode (transistorPin1, OUTPUT);
  pinMode (transistorPin2, OUTPUT);
  pinMode (transistorPin3, OUTPUT);
  pinMode (transistorPin4, OUTPUT);

}

/*
 * 1 - extension
 * 2 - flexion
 */

void loop() {
  if(Serial.available()){
      data = Serial.read();

    if(data == '1'){     
      // Soft object - hand moves towards object
      digitalWrite(transistorPin2, HIGH);  
      delay(150);
      digitalWrite(transistorPin2, LOW); 
      delay(150);
      digitalWrite(transistorPin2, HIGH); 
      delay(150);
      digitalWrite(transistorPin2, LOW);
      //delay(1000);
  
    }

    if(data == '2'){
      // Hard object - hand repels from object
      digitalWrite(transistorPin1, HIGH);  
      delay(150);
      digitalWrite(transistorPin1, LOW); 
      delay(150);
      digitalWrite(transistorPin1, HIGH); 
      delay(150);
      digitalWrite(transistorPin1, LOW);
      //delay(5000);

    }

    if(data == '3'){
      // Repulsive object - hand repels strongly
      digitalWrite(transistorPin1, HIGH);  
      delay(500);
      digitalWrite(transistorPin1, LOW); 
      //delay(5000);
    
    }

    if(data == '4'){
      // Pass through - Magnetic feedback with audio
      digitalWrite(transistorPin1, HIGH);  
      delay(150);
      digitalWrite(transistorPin1, LOW); 
      digitalWrite(transistorPin2, HIGH);
      delay(150);   
      digitalWrite(transistorPin2, LOW);
      //delay(5000);
    
    }
       
  }
}
    
   /*if (Serial.available()) {
 
    
    /*if (data == '1'){
      //digitalWrite(transistorPin1,HIGH);
      //digitalWrite(transistorPin2, LOW);       
      digitalWrite(transistorPin1, HIGH);    
      
    }
    else {
      digitalWrite(transistorPin1, LOW);
      //digitalWrite(transistorPin2, HIGH); 
    }
    if (data == '2'){
      digitalWrite(transistorPin2, HIGH);
    }
    else {
      digitalWrite(transistorPin2, LOW);
    }
    if (data == '3'){
      digitalWrite(transistorPin3,HIGH);
    }
    else {
      digitalWrite(transistorPin3, LOW);
    }
    if (data == '4'){
      digitalWrite(transistorPin4,HIGH);
    }
    else {
      digitalWrite(transistorPin4, LOW);
    }*/
  /* }
    
}*/
