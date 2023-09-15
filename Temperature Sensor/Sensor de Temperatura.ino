// C++ code
//
#define LedA 2
float temperature;

void setup()
{
  pinMode(LedA, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int valorArd = analogRead(A0);
  float volts = (valorArd/1023.0) * 5.0;
  temperature = (volts) * 100;
  Serial.print("Lectura del Arduino: ");
  Serial.println(valorArd);
  Serial.print("Voltaje: ");
  Serial.println(volts);
  Serial.print("Temperatura: ");
  Serial.println(temperature);
  delay(1000);

  if(temperature > 24){
    digitalWrite(LedA, HIGH);
  } 
  else{
    digitalWrite(LedA, LOW);
  }
}   
