#include <Servo.h>

Servo myservo;

int pos=120;

#define trigPin 7 //trigger1
#define echoPin 6 //echo 1
#define trigPin1 4 //trigger2
#define echoPin1 5 //echo2

int led1=13; //led verde
int led2=8; //led rosu
int duration, duration1, distance, distance1,count = 0,locuriLibere = 0;

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
   digitalWrite(led2,HIGH);
  Serial.begin(9600);
  myservo.attach(10);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  Serial.println(0);

  //Serial.println("Bine ati venit la PARCARE");
}

long toCentimeters(long microseconds){
  return microseconds / 29 / 2;
}


void loop(){
 

  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH); // durara ->input de la echo
  distance = toCentimeters(duration);

  digitalWrite(trigPin1,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  duration1 = pulseIn(echoPin1,HIGH); // durara ->input de la echo
  distance1 = toCentimeters(duration1);
  //Serial.println(distance1);

  if(distance != 0 && distance < 7 && count < 6){
    digitalWrite(led2,LOW);//stingem ledu rosu
    delay(200);
    count+=1;
    Serial.println(count);
    //Serial.println(" / 6");
   // Serial.println("S-a ridicat bariera");
    locuriLibere = 6 - count;
    //Serial.print("Mai sunt");
    //Serial.print(locuriLibere);
    //Serial.println(" locuri libere in parcare");
    pos = 50;
    myservo.write(pos);
    digitalWrite(led1,HIGH);//aprindem ledu verde
    delay(3000);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    
  }
  pos = 120;
  myservo.write(pos);
  if(count == 6)
  {
   // Serial.println("nu mai sunt locuri in parcare");
  }
 // digitalWrite(led1,LOW);
  //digitalWrite(led2,HIGH);

if(distance1 != 0 && distance1 < 7){
    digitalWrite(led2,LOW);//stingem ledu rosu
    delay(200);
    count-=1;
    //Serial.println(distance1);
    Serial.println(count);
    //Serial.println(" / 6");
    //Serial.println("S-a ridicat bariera");
    locuriLibere = 6 - count;
   // Serial.print("Mai sunt");
    //Serial.print(locuriLibere);
   // Serial.println(" locuri libere in parcare");
    pos = 50;
    myservo.write(pos);
    digitalWrite(led1,HIGH);//aprindem ledu verde
    delay(3000);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);  
  }


























}
