class Switch
{ 
  public:
  int state;  
  int prevState;
  int pinNum;
//Constructor
  Switch(int pinNum_)
  {
    pinNum = pinNum_;
    pinMode(pinNum, INPUT);
    }
//Functions
  void Update()
  {
    int upSwitch;
    int downSwitch;

    upSwitch = digitalRead(7);
    downSwitch = digitalRead(6);
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

class Motor
{
  public:
  int state;

  //Constructor
  Motor()
  {
    //Configure Data direction register and reset PORTB
    DDRB = B111111;
    PORTB = B000000;
    }

  //Step motor forward n steps
  void forward(int n){
   if(state != 1){
    for(int i = 0; i < n; i++){
        PORTB = (PORTB) ^ B100000;
        delayMicroseconds(500);
        PORTB = (PORTB) ^ B000001;
        delayMicroseconds(500);
      }
    state = 1;
   }
  }
  
  //Step motor backward n steps
  void backward(int n){
    if(state != 0){
      for(int i = 0; i < n; i++){
        PORTB = (PORTB) ^ B000001;
        delayMicroseconds(500);
        PORTB = (PORTB) ^B100000;
        delayMicroseconds(500);
      }
    state = 0;
    }
  } 
};

class BrailleCell
{
  public:
  Motor Motors[6];
  
  };


Switch but1(7);
Motor motor1;

void setup() {  
}

void loop() {
  but1.Update();
  if(but1.state == 1 && but1.prevState != 1){
    motor1.forward(100);
  }
  else if(but1.state == -1 && but1.prevState != -1){
    motor1.backward(100);
  }
  else{ /*chill*/ }
}







