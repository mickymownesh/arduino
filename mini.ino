const int pin = 7;
const int out = 12;
int ldrPin = A0; // select the input pin for LDR
int count = 0;
int sensorValue = 0;
int value[10];

void setup() {
  Serial.begin(9600);
  pinMode(pin,INPUT);
  pinMode(out,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(out,LOW);
}

void loop() {
 if(digitalRead(pin) == 0){
    delay(1000);
    count = 1;
    Serial.println(count);
    
    while(1){
      sensorValue = analogRead(ldrPin);
      delay(0);
      
      if(count == 1 && sensorValue < 250){
        digitalWrite(out,HIGH);
        digitalWrite(LED_BUILTIN,HIGH);
        
        }
      if(digitalRead(pin) == 0){
        delay(1000);
        count = 0;
        digitalWrite(out,LOW);
        digitalWrite(LED_BUILTIN,LOW);
        break;
        }
      //Serial.println(count);
      } 
  }

}


