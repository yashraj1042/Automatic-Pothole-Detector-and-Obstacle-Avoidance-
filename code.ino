#include <SoftwareSerial.h>
#include <TinyGPS.h>

float gpslat, gpslon;
TinyGPS gps;
SoftwareSerial sgps(12, 13);
SoftwareSerial mySerial(11, 10);

const int in1=6;
const int in2=7;
const int in3=4;
const int in4=5;
const int ena-2;
const int enb=3;
int obstacle;
const int trig=8;
const int echo=9;
float duration_us, distance_cm;

void setup() {
pinMode(in1, OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(ena, OUTPUT);
pinMode(enb, OUTPUT);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
delay(1200);
Serial.begin(9600);
mySerial.begin(9600);
sgps.begin(9600);
}

void loop() {
UL();
sgps.listen();

while (sgps.available())
{
int csgps.read();
if (gps.encode(c))
{
gps.f_get_position(&gpslat, &gpslon);
}
}

analogWrite(ena, 130);
analogWrite(enb, 130);
digitalWrite(in1, HIGH);
digitalWrite(in3,HIGH);
obstacle digitalRead(12);

if(obstacle-0)
{
digitalWrite(in1,LOW);
digitalWrite(in3,LOW);
delay(1000);
digitalWrite(in2, HIGH);
digitalWrite(in4,HIGH);
delay(600);
digitalWrite(in2,LOW);
digitalWrite(in4,LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3,HIGH);
delay(800);
digitalWrite(in2,LOW);
digitalWrite(in4,LOW);
digitalWrite(in 1, HIGH);
digitalWrite(in3,HIGH);
delay(50);
}
}

void UL()
{
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration_us pulseIn(echo, HIGH);
distance_cm = 0.017 duration_us;
Serial.print("distance: ");
Serial.print(distance_cm);
Serial.println(" cm");

if(distance_cm>=7)
{
digitalWrite(in1,LOW);
digitalWrite(in3,LOW);
delay(1000);
SendMessage();
delay(400);
digitalWrite(in1,HIGH);
digitalWrite(in3,HIGH);

}

delay(100);

void SendMessage()
{
Serial.println("I am in send");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"‪xxxxxxxxxx‬\"\r"); // Replace x with mobile number
delay(1000);
mySerial.println("Pot Hole detected");
mySerial.print("Latitude:");
mySerial.println(gpslat, 6);
mySerial.print("Longitude:");
mySerial.println(gpslon, 6);
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
}