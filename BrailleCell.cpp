class Switch
{ 
  public:
  int state;  
  int prevState;
  int pinNum1;
  int pinNum2;
//Constructor
  Switch(int pinNum1_, int pinNum2_)
  {
    pinNum1 = pinNum1_;
    pinNum2 = pinNum2_;
    pinMode(pinNum1, INPUT);
    pinMode(pinNum2, INPUT);
    }
//Functions
  void Update()
  {
    int upSwitch;
    int downSwitch;

    upSwitch = digitalRead(pinNum1);
    downSwitch = digitalRead(pinNum2);
    prevState = state;
    if(upSwitch == 1 && downSwitch == 0){
      state = 1;
    }
    else if(upSwitch == 0 && downSwitch == 1){
      state = -1;
    }
    else{
      state = 0;
    }
    }
};

class Motor{
  public:
  int motorNum;
  int motorState;
  int portDTNum1; //PORTD TOGGLE NUM 1
  int portDTNum2; //PORTD TOGGLE NUM 2
  int portBTNum1; //PORTB TOGGLE NUM 1
  int portBTNum2; //PORTB TOGGLE NUM 2

  Motor(int motorNum_){
    DDRD = DDRD | B11111100;
    DDRB = B111111;
    motorNum = motorNum_;
    motorState = 100; //Initialize to random number
    if(motorNum_ == 1){
      portDTNum1 = PORTD | 0;
      portDTNum2 = PORTD | 4;
      portBTNum1 = 0;
      portBTNum2 = 1;
    }

    else if(motorNum_ == 2){
      portDTNum1 = PORTD | 8;
      portDTNum2 = PORTD | 12;
      portBTNum1 = 2;
      portBTNum2 = 3;
    }

    else if(motorNum_ == 3){
      portDTNum1 = PORTD | 16;
      portDTNum2 = PORTD | 20;
      portBTNum1 = 4;
      portBTNum2 = 5;
    }

    else if(motorNum_ == 4){
      portDTNum1 = PORTD | 40;
      portDTNum2 = PORTD | 44;
      portBTNum1 = 10;
      portBTNum2 = 11; 
    }

    else if(motorNum_ == 5){
      portDTNum1 = PORTD | 32;
      portDTNum2 = PORTD | 36;
      portBTNum1 = 8;
      portBTNum2 = 9;
    }

    else if(motorNum_ == 6){
      portDTNum1 = PORTD | 24;
      portDTNum2 = PORTD | 28;
      portBTNum1 = 6;
      portBTNum2 = 7;
    }
    
  }

  void DriveUp(int steps){
    if(motorState != 1){    
      for(int i = 0; i < steps; i++){
        if(PORTD == portDTNum1){
          PORTD = portDTNum2; 
        }
        else{
          PORTD = portDTNum1;
        }
        delayMicroseconds(500);
        if(PORTB == portBTNum1){
          PORTB = portBTNum2;
        }
        else{
          PORTB = portBTNum1;
        }
        delayMicroseconds(500);
      }
      motorState = 1;
    }
   else{
    return; 
   }
  }

  void DriveDown(int steps){
    if(motorState != 0){    
      for(int i = 0; i < steps; i++){
        if(PORTB == portBTNum1){
          PORTB = portBTNum2;
        }
        else{
          PORTB = portBTNum1;
        }
        delayMicroseconds(500);
        if(PORTD == portDTNum1){
          PORTD = portDTNum2; 
        }
        else{
          PORTD = portDTNum1;
        }
        delayMicroseconds(500);     
      }
      motorState = 0;
    }
    else{
      return;
    }
  } 
};
