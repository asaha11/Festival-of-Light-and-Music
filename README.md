# Festival-of-Light-and-Music

// SW  refers to the Star Wars display
// HP refers to the Harry Potter display
// The code for notes was borrowed from https://github.com/NassimBouyacoub/Star-Wars-theme-Song-Arduino-/blob/master/arduino_star_wars.ino and https://www.instructables.com/Arduino-Harry-Potter-Theme-Song/
// Some of the code from those sources was interwoven with the code I wrote, leading to the final product

int ledBlueSW = 1;
int ledBlueSW2 = 9;
int ledRedSW = 2;
int ledRedSW2 = 4;
int ledWhiteSW = 3;
int ledWhiteSW2 = 0;
int ledRedHP = 5;
int ledBlueHP = 6;
int ledYellowHP = 7;
int ledGreenHP = 8;
int buttonSW = 12;
int buttonHP = 13;
int buzzer = 10;
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
int counter = 0;

struct MusicStruct {
  int A = 550;
  int As = 582;
  int B = 617;
  int C = 654;
  int Cs = 693;
  int D = 734;
  int Ds = 777;
  int E = 824;
  int F = 873;
  int Fs = 925;
  int G = 980;
  int Gs = 1003;
  int A2 = 1100;
  int A2s = 1165;
  int B2 = 1234;
  int C3 = 1308;
  int C3s = 1385;
  int D3 = 1555;
} Music;

struct LengthStruct {
  float half = 0.5;
  float one = 1.0;
  float one_half = 1.5;
  float two = 2.0;
  float two_half = 2.5;
} Length;

int tempo = 400;


void setup() {
  // put your setup code here, to run once:
  pinMode (ledBlueSW, OUTPUT);
  pinMode (ledBlueSW2, OUTPUT);
  pinMode (ledRedSW, OUTPUT);
  pinMode (ledRedSW2, OUTPUT);
  pinMode (ledWhiteSW, OUTPUT);
  pinMode (ledWhiteSW2, OUTPUT);
  pinMode (ledBlueHP, OUTPUT);
  pinMode (ledRedHP, OUTPUT);
  pinMode (ledYellowHP, OUTPUT);
  pinMode (ledGreenHP, OUTPUT);
  pinMode (buttonSW, INPUT_PULLUP);
  pinMode (buttonHP, INPUT_PULLUP);
  pinMode (buzzer, OUTPUT);
}

void setTone(int pin, int note, int duration) {
  tone(pin, note, duration);
  delay(duration);
  noTone(pin);
}

void loop() {
  // put your main code here, to run repeatedly:

 // Star Wars Display Code
  if (digitalRead(buttonSW) == LOW)
  { 
    digitalWrite(ledBlueSW, HIGH);
    beep(a, 500);
    delay(200);
    digitalWrite(ledBlueSW, LOW);
    beep(a, 500);
    delay(200);
    digitalWrite(ledRedSW, HIGH);
    beep(a, 500);
    delay(200);
    digitalWrite(ledRedSW, LOW);
    beep(f, 350);
    delay(200);
    digitalWrite(ledWhiteSW, HIGH);
    beep(cH, 150);
    delay(200);
    digitalWrite(ledWhiteSW, LOW);
    beep(a, 500);
    delay(200);
    digitalWrite(ledBlueSW2, HIGH);
    beep(f, 350);
    delay(200);
    digitalWrite(ledBlueSW2, LOW);
    beep(cH, 150);
    delay(200);
    digitalWrite(ledRedSW2, HIGH);
    beep(a, 650);
    delay(500);
    digitalWrite(ledRedSW2, LOW);
    beep(eH, 500);
    delay(200);
    digitalWrite(ledWhiteSW2, HIGH);
    beep(eH, 500);  
    delay(200);
    digitalWrite(ledWhiteSW2, LOW);
    beep(eH, 500);
    delay(200);
    digitalWrite(ledBlueSW, HIGH);
    beep(fH, 350);
    delay(200);
    digitalWrite(ledBlueSW, LOW);
    beep(cH, 150);
    delay(200);
    digitalWrite(ledRedSW, HIGH);
    beep(gS, 500);
    delay(200);
    digitalWrite(ledRedSW, LOW);
    beep(f, 350);
    delay(200);
    digitalWrite(ledWhiteSW, HIGH);
    beep(cH, 150);
    delay(200);
    digitalWrite(ledWhiteSW, LOW);
    beep(a, 650);
    delay(200);
  }

  // Harry Potter Display Code
  if (digitalRead(buttonHP) == LOW)
  {
    digitalWrite(ledYellowHP, HIGH);
    setTone(buzzer, Music.B, tempo * Length.one);
    delay(50);
    digitalWrite(ledYellowHP, LOW);
    setTone(buzzer, Music.E, tempo * Length.one_half);
    delay(50);
    digitalWrite(ledGreenHP, HIGH);
    setTone(buzzer, Music.G, tempo * Length.half);
    delay(50);
    digitalWrite(ledGreenHP, LOW);
    setTone(buzzer, Music.F, tempo * Length.one);
    delay(50);
    digitalWrite(ledRedHP, HIGH);
    setTone(buzzer, Music.E, tempo * Length.two);
    delay(50);
    digitalWrite(ledRedHP, LOW);
    setTone(buzzer, Music.B2, tempo * Length.one);
    delay(50);
    digitalWrite(ledBlueHP, HIGH);
    setTone(buzzer, Music.A2, tempo * Length.two_half);
    delay(50);
    digitalWrite(ledBlueHP, LOW);
    setTone(buzzer, Music.Fs, tempo * Length.two_half);
    delay(50);
    digitalWrite(ledYellowHP, HIGH);
    setTone(buzzer, Music.E, tempo * Length.one_half);
    delay(50);
    digitalWrite(ledYellowHP, LOW);
    setTone(buzzer, Music.G, tempo * Length.half);
    delay(50);
    digitalWrite(ledGreenHP, HIGH);
    setTone(buzzer, Music.F, tempo * Length.one);
    delay(50);
    digitalWrite(ledGreenHP, LOW);
    setTone(buzzer, Music.Ds, tempo * Length.two);
    delay(50);
    digitalWrite(ledRedHP, HIGH);
    setTone(buzzer, Music.F, tempo * Length.one);
    delay(50);
    digitalWrite(ledRedHP, LOW);
    setTone(buzzer, Music.B, tempo * Length.two_half);
    delay(50);
    digitalWrite(ledBlueHP, HIGH);
    delay(250);
    digitalWrite(ledBlueHP, LOW);
  }
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzer, note, duration);
  //Play different LED depending on value of 'counter'
  if (counter % 2 == 0)
  {
    //Stop tone on buzzerPin
    noTone(buzzer);
    delay(50);
    //Increment counter
    counter++;
  }
}
