// Left Board
int clockPinA = 13;
int latchPinA = 12;
int dataPinA = 11;

// Right Board
int clockPinB = 10;
int latchPinB = 9;
int dataPinB = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(clockPinA, OUTPUT);
  pinMode(latchPinA, OUTPUT);
  pinMode(dataPinA, OUTPUT);

  pinMode(clockPinB, OUTPUT);
  pinMode(latchPinB, OUTPUT);
  pinMode(dataPinB, OUTPUT);
}

// Square
byte moveGrounds[4] = {223, 239, 247, 251};
byte movePowers[4] =  {15, 9, 9, 15};


void loop() {
  // put your main code here, to run repeatedly:
  for (int j=0; j<75; j++)
  {
    for (int x=0; x<4; x++) 
    {
      digitalWrite(latchPinA, LOW);
      shiftOut(dataPinA, clockPinA, LSBFIRST, movePowers[x]);
      digitalWrite(latchPinA, HIGH);

      digitalWrite(latchPinB, LOW);
      shiftOut(dataPinB, clockPinB, LSBFIRST, moveGrounds[x]);
      digitalWrite(latchPinB, HIGH);

      delay(1);

      digitalWrite(latchPinA, LOW);
      shiftOut(dataPinA, clockPinA, LSBFIRST, B00000000);
      digitalWrite(latchPinA, HIGH);

      digitalWrite(latchPinB, LOW);
      shiftOut(dataPinB, clockPinB, LSBFIRST, B11111111);
      digitalWrite(latchPinB, HIGH);
    }
  }
  for (int i=0; i<4; i++) 
  {
    movePowers[i] = movePowers[i] * 2;
  }
  Serial.println(movePowers[3]);

  if (movePowers[3]==0) 
  {
    movePowers[0] = 15;
    movePowers[1] = 9;
    movePowers[2] = 9;
    movePowers[3] = 15;
  }
}
