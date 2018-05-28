//built in arduino ide for nano v3
//runs the l239d chip from pots
//by julio @ youtube/djd14d
//Please, live the creative life


int pot1 = A0;
int pot2 = A1;

int motpot = A3;

int input1 = 2;
int input2 = 3;

int enable = 5;
int limit = 0;
int limit2 = 0;



bool flag = true;
bool json = true;

void setup() {
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(motpot, INPUT);

  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(enable, OUTPUT);

}


void loop() {


  digitalWrite(enable, HIGH);

  while (flag) {
    limit = analogRead(pot1);
    limit2 = analogRead(pot2);

    if (analogRead(motpot) >= (limit + 1)) {  //left side
      digitalWrite(input2, HIGH);
      digitalWrite(input1, LOW);
    } else {
      json = false;
    }
    while (json == false){
      if (analogRead(motpot) <= (limit2 - 1)) {  //right side
      digitalWrite(input2, LOW);
      digitalWrite(input1, HIGH);
    } else {
      json = true;
    }
    }
  }
  
}
