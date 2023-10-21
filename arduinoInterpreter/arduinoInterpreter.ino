#include<Servo.h>

Servo serX;
Servo serY;

String serialData;
const int laserPin = 10;  

void setup() {

  serX.attach(11);
  serY.attach(10);
  Serial.begin(9600);
  Serial.setTimeout(10);

  //laser outputPin
  pinMode(laserPin, OUTPUT);
}

void loop() {
  //laser on
  digitalWrite(laserPin, HIGH);
}

void serialEvent() {
  serialData = Serial.readString();
  serX.write(parseDataX(serialData));
  serY.write(parseDataY(serialData));
}

int parseDataX(String data){
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);
  return data.toInt();
}

int parseDataY(String data){
  data.remove(0,data.indexOf("Y") + 1);
  return data.toInt();
}

