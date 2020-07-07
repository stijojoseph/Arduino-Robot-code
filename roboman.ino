
#include <Servo.h>
Servo ser; Servo ser1;Servo ser2; 
Servo ser13;Servo ser8;Servo ser5;
Servo ser10; Servo ser7;

const int t=4; int du;
float dis;
const int e=3;
char p;
int i=0;
int j=0;
char y=-1;
void setup()
{ser1.attach(3);
 
    pinMode(t,OUTPUT);
    pinMode(e,INPUT);
     
    ser13.attach(13);

    ser10.attach(10);
    ser7.attach(7);
    ser8.attach(8);
    ser10.write(0);
    ser7.write(0);
 ser13.write(55);
    ser8.write(45);
    Serial.begin(9600);
}
void loop(){
if(Serial.available())
    p=Serial.read();
    Serial.print(p);
   delay(10);
   char c=p;

  
   delay(1000);
    if(p=='9' )
   {
   distance(); 
   if (dis>10)
   left();
   distance();
   if (dis>10)
   right();
Serial.print(dis);
}
  
    if(p=='5' )
   {
    ser8.write(45);
        delay(1000);}
      if(p=='6' )
   {
    ser8.write(125);
        delay(1000);}








        
    
    if(p=='3' )
   {
    ser7.write(75);
        delay(1000);}
      if(p=='4' )
   {
    ser7.write(0);
        delay(1000);}


  
    if(p=='7' )
   {
    ser10.write(0);
        delay(1000);}
      if(p=='8' )
   {
    ser10.write(55);
        delay(1000);}


  if(p=='1' )
   {
    ser13.write(0);
        delay(1000);}
      if(p=='2' )
   {
    ser13.write(55);
        delay(1000);}


         
        
        
        }
 
 void right()
 {
  ser7.write(65);
        delay(1000);
            ser13.write(0);
        delay(1000);
ser7.write(0);
        delay(1000);   
ser13.write(55);
        delay(1000);

     
        
 }
void left()
{  ser8.write(125);
        delay(1000);
         ser10.write(55);
        delay(1000);
        ser8.write(45);
        delay(1000);
        ser10.write(0);
        delay(1000);}
 void distance()
        {digitalWrite(t,LOW);
    delay(1);
    digitalWrite(t,HIGH);
    delay(1);
    digitalWrite(t,LOW);
    du=pulseIn(e,HIGH);
    dis=du*0.0168;}        
