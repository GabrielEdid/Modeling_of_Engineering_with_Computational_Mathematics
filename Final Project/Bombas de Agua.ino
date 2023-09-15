//Modelacion de la Ingenieria con Matematica Computacional
//Valentina González Hernández 
//Miranda Isabela Rodríguez Espinoza 
//Nicole Dávila Hernández
//Gabriel Edid Harari 
//Eduardo Dabbah Gindi
//09/03/2023

#define Enable1y2 8
#define Enable3y4 9

#define Motor1 2
#define Motor2 3
#define Motor3 4

#define SensTemp1 A0
#define SensTemp2 A1
#define SensTemp3 A2

#define SensAgua A3

#define Switch1 5
#define Switch2 6
#define Switch3 7

int Temp1, Temp2, Temp3;
int sensAgua;
int SW1, SW2, SW3;
int setMotorB, setMotorM, setMotorA;


void setup(){
  pinMode(Enable1y2, OUTPUT);
  pinMode(Enable3y4, OUTPUT);
  
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
  
  digitalWrite(Enable1y2, HIGH);
  digitalWrite(Enable3y4, HIGH);
  
  digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,LOW);
  digitalWrite(Motor3,LOW);
  
  Serial.begin(9600);
}

void loop(){
  Serial.println("");
  Serial.println("***LECTURAS***");
  
  //Sensor De Temperatura 1
  int valorArd1 = analogRead(A0);
  float volts1 = (valorArd1/1024.0) * 5.0;
  float temperature1 = (volts1 - 0.5) * 100;
  Serial.print("Temperatura 1: ");
  Serial.println(temperature1);
 
  
  if(temperature1 < 40){
    Temp1 = 1;
  } 
  else{
    Temp1 = 0;
  }
  
  //Sensor De Temperatura 2
  int valorArd2 = analogRead(A1);
  float volts2 = (valorArd2/1024.0) * 5.0;
  float temperature2 = (volts2 - 0.5) * 100;
  Serial.print("Temperatura 2: ");
  Serial.println(temperature2);
 
  
  if(temperature2 < 40){
    Temp2 = 1;
  } 
  else{
    Temp2 = 0;
  }
  
  //Sensor De Temperatura 3
  int valorArd3 = analogRead(A2);
  float volts3 = (valorArd3/1024.0) * 5.0;
  float temperature3 = (volts3 - 0.5) * 100;
  Serial.print("Temperatura 3: ");
  Serial.println(temperature3);
 
  
  if(temperature3 < 40){
    Temp3 = 1;
  } 
  else{
   	Temp3 = 0;
  }
  
  //Sensor De Nivel de Agua
  float nivelAgua = analogRead(A3);
  Serial.print("Nivel de Agua: ");
  Serial.println(nivelAgua);
 
  
  if(nivelAgua > 430){
   sensAgua = 1;
  } 
  else{
   sensAgua = 0;
  }
	delay(1000);
  
  //Switches  
  SW1=digitalRead(Switch1);
  SW2=digitalRead(Switch2);
  SW3=digitalRead(Switch3);

 
  //Funciones Booleanas
  setMotorB = (sensAgua  and Temp1  and (SW1  or SW2 or SW3));
  setMotorM = (sensAgua and Temp2 and (SW2 or SW3 or ((not Temp1) and SW1)));
  setMotorA = (sensAgua and Temp3 and (Temp1 and Temp2 and SW3 or (not Temp1 and not Temp2 and (SW1 or SW2 or SW3) or (SW2 or SW3) and (not Temp1 and Temp2 or Temp1 and not Temp2))));
  
  //Control de Motores
  if (setMotorB==1){      
	digitalWrite(Motor1,HIGH);
  }
  else{
    digitalWrite(Motor1,LOW);
  }
  if (setMotorM==1){
  	digitalWrite(Motor2,HIGH);
  }
  else
    digitalWrite(Motor2,LOW);{
  }
  if (setMotorA==1){
  	digitalWrite(Motor3,HIGH);
  }
  else{
  	digitalWrite(Motor3,LOW);
  }
}