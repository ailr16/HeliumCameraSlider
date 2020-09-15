#include <Servo.h>
//#include <SoftwareSerial.h>

Servo servo;

#define servoMaxDelay 50 
#define servoMinDelay 15

#include "base.h"

//SoftwareSerial serie1(2,3);

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
  //serie1.begin(9600);
  pinMode(13,OUTPUT);
  servo.attach(9);
}

void loop() {
  if(Serial.available()){
    sI = Serial.readString();
    sI.toCharArray(serialInput,13);
    for(int i=0;i<3;i++){
      comArray[i] = serialInput[i];
      int1Array[i] = serialInput[i+4];
      int2Array[i] = serialInput[i+8];
    }
    /*Serial.print("Comando: ");
    Serial.print(comArray);
    Serial.print("\t Parametro1: ");
    Serial.print(int1Array);
    Serial.print("\t Parametro2: ");
    Serial.print(int2Array);
    Serial.print("\n");
*/
    com = String(comArray);
    if(com.equals("fwd") == true){
      l = atoi(int1Array);
      s = atoi(int2Array);
      Serial.println("OK");
      /*Serial.print("Moviendo hacia adelante al ");
      Serial.print(l);
      Serial.print("% de longitud y velocidad de ");
      Serial.print(s);
      Serial.print("%\n");*/
    }
    else if(com.equals("rvr") == true){
      l = atoi(int1Array);
      s = atoi(int2Array);
      Serial.println("OK");
      /*Serial.print("Moviendo hacia atras ");
      Serial.print(l);
      Serial.print("% de longitud y velocidad de ");
      Serial.print(s);
      Serial.print("%\n");*/
    }
    else if(com.equals("rtt") == true){
      d = atoi(int1Array);
      s = atoi(int2Array);
      if(d >= 0 && d <=180){
        /*Serial.print("Girando a la posicion ");
        Serial.print(d);
        Serial.print(" grados con velocidad de ");
        Serial.print(s);
        Serial.print("%\n");*/
        Serial.println("OK");
        if(s!=0)  base.moveServo(d,s);
        else;
      }
      else{
        //Serial.print("El angulo esta fuera del intervalo!!!\n");
        Serial.println("NO");
      }
    }
    else if(com.equals("fxp") == true){
      //Serial.println("Se ha fijado la posicion :-)");
      Serial.println("OK");
    }
    else if(com.equals("hom") == true){
      //Serial.print("Regresando al origen :-)");
      //Serial.print("\n");
      Serial.println("OK");
      homing();
    }
    else{
      //Serial.println("No se reconoce el comando :-(");
      Serial.println("NO");
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
