int ledBlueUSA = 1;
int ledRedUSA = 2;
int ledWhiteUSA = 3;
int ledRedHP = 5;
int ledBlueHP = 6;
int ledYellowHP = 7;
int ledGreenHP = 8;
int button = 12;
int buttonOff = 13;
int buzzer = 10;
int tracker = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode (ledBlueUSA, OUTPUT);
  pinMode (ledRedUSA, OUTPUT);
  pinMode (ledWhiteUSA, OUTPUT);
  pinMode (ledBlueHP, OUTPUT);
  pinMode (ledRedHP, OUTPUT);
  pinMode (ledYellowHP, OUTPUT);
  pinMode (ledGreenHP, OUTPUT);
  pinMode (button, INPUT_PULLUP);
  pinMode (buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button) == LOW)
  {
    if (tracker == 1) {
      digitalWrite(ledBlueUSA, HIGH);
      delay(250);
      digitalWrite(ledBlueUSA, LOW);
      delay(250);
      digitalWrite(ledRedUSA, HIGH);
      delay(250);
      digitalWrite(ledRedUSA, LOW);
      delay(250);
      digitalWrite(ledWhiteUSA, HIGH);
      delay(250);
      digitalWrite(ledWhiteUSA, LOW);
      delay(250);
      tracker = -tracker;
    }
    else
    {
      digitalWrite(ledYellowHP, HIGH);
      delay(250);
      digitalWrite(ledYellowHP, LOW);
      delay(250);
      digitalWrite(ledGreenHP, HIGH);
      delay(250);
      digitalWrite(ledGreenHP, LOW);
      delay(250);
      digitalWrite(ledRedHP, HIGH);
      delay(250);
      digitalWrite(ledRedHP, LOW);
      delay(250);
      digitalWrite(ledBlueHP, HIGH);
      delay(250);
      digitalWrite(ledBlueHP, LOW);
      delay(250);
    }
    delay(500);
  }
}
