// C++ code
//
#define LedN 5
#define LedA 4
#define LedV 3
#define boton 2

void setup()
{
  pinMode(LedN, OUTPUT);
  pinMode(LedA, OUTPUT);
  pinMode(LedV, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop(){
  int leo;
  leo = digitalRead(boton);
  
  if(leo==1){
  	digitalWrite(LedN,HIGH);
    delay(250); // Wait for 250 millisecond(s)
    digitalWrite(LedN,LOW);
    delay(250); // Wait for 250 millisecond(s)
    digitalWrite(LedA,HIGH);
    delay(250); // Wait for 250 millisecond(s)
    digitalWrite(LedA,LOW);
    delay(250); // Wait for 250 millisecond(s)
    digitalWrite(LedV,HIGH);
    delay(250); // Wait for 250 millisecond(s)
    digitalWrite(LedV,LOW);
    delay(250); // Wait for 250 millisecond(s)
  }
  else{
  	digitalWrite(LedN,LOW);
  	digitalWrite(LedA,LOW);
  	digitalWrite(LedV,LOW);
  }   
}