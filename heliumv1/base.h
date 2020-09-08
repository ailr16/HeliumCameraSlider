

class Base{
  private:
    int deg;
    int dAct;
    int dPast;
  public:
    Base(){
      deg=0;
      dAct=0;
      dPast=0;
      servo.write(deg);
    }
    void moveServo(int d, int s){
      float n = 1;
      n = map(s,0,100,servoMaxDelay,servoMinDelay);
      if(d > dAct){
        for(deg=dAct;deg<=d;deg++){
          servo.write(180-deg);
          delay(n);
        }
        dAct = deg;
      }
      else if(d < dAct){
        for(deg=dAct;deg>=d;deg--){
          servo.write(180-deg);
          delay(n);
        }
        dAct = deg;
      }
      else dAct = dAct;
    }
};
