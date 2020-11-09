const int motor1pin = 5;
const int powerpin = 11;
char junk;
String inputString="";

void setup() {
  // put your setup code here, to run once:
pinMode(motor1pin,OUTPUT);
pinMode(powerpin,OUTPUT);
Serial.begin(9600);
digitalWrite(motor1pin, HIGH);
digitalWrite(powerpin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    while(Serial.available()){
      char inChar = (char)Serial.read();
      inputString += inChar;
      }
       Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
      digitalWrite(powerpin,LOW);
      
      if(inputString == "f"){
        digitalWrite(motor1pin,LOW);
        delay(500);
        digitalWrite(motor1pin,HIGH);
        }else{
          digitalWrite(motor1pin,HIGH);
          }
       
       inputString = "";
    }
}
