#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo;

#define servoMaxDelay 50 
#define servoMinDelay 15

#include "base.h"

SoftwareSerial serie1(2,3);

//for parse
String sI;
String com;
char comArray[4];
char int1Array[4];
char int2Array[4];
char serialInput[13];
int l = 0;
int s = 0;
int d = 0;
int d2 = 0;

Base base;

void setup(){
  Serial.begin(9600);
  serie1.begin(9600);
  pinMode(13,OUTPUT);
  servo.attach(9);
}

void loop() {
  if(serie1.available()){
    sI = serie1.readString();
    sI.toCharArray(serialInput,13);
    for(int i=0;i<3;i++){
      comArray[i] = serialInput[i];
      int1Array[i] = serialInput[i+4];
      int2Array[i] = serialInput[i+8];
    }
    Serial.print("Comando: ");
    Serial.print(comArray);
    Serial.print("\t Parametro1: ");
    Serial.print(int1Array);
    Serial.print("\t Parametro2: ");
    Serial.print(int2Array);
    Serial.print("\n");

    com = String(comArray);
    if(com.equals("fwd") == true){
      l = atoi(int1Array);
      s = atoi(int2Array);
      serie1.print("Moviendo hacia adelante al ");
      serie1.print(l);
      serie1.print("% de longitud y velocidad de ");
      serie1.print(s);
      serie1.print("%\n");
    }
    else if(com.equals("rvr") == true){
      l = atoi(int1Array);
      s = atoi(int2Array);
      serie1.print("Moviendo hacia atras ");
      serie1.print(l);
      serie1.print("% de longitud y velocidad de ");
      serie1.print(s);
      serie1.print("%\n");
    }
    else if(com.equals("rtt") == true){
      d = atoi(int1Array);
      s = atoi(int2Array);
      if(d >= 0 && d <=180){
        serie1.print("Girando a la posicion ");
        serie1.print(d);
        serie1.print(" grados con velocidad de ");
        serie1.print(s);
        serie1.print("%\n");
        if(s!=0)  base.moveServo(d,s);
        else;
      }
      else  serie1.print("El angulo esta fuera del intervalo!!!\n");
    }
    else if(com.equals("fxp") == true){
      serie1.println("Se ha fijado la posicion :-)");
    }
    else if(com.equals("hom") == true){
      serie1.print("Regresando al origen :-)");
      serie1.print("\n");
      homing();
    }
    else{
      serie1.println("No se reconoce el comando :-(");
    }
  }
}

void homing(void){
  base.moveServo(0,100);
}

void fwd(int l, int s){
}
void rvr(int l, int s){
}
