
#include <Servo.h> //используем библиотеку для работы с сервоприводом

#include <GyverMotor.h>
int trigBE = 9;      // trig pin bottom eye
int echoBE = 10;     // Echo pin bottom eye
int trigTE = 2;      // trig pin top eye
int echoTE = 3;     // Echo pin top eye
int rev = 4;       //REVerse motion
int fwd = 5;       //ForWarD motion
long du1,du2, d1,d2;
int zero = 60;
int rounds = 0;
bool finish = false;
int mcs = 720;
GMotor motor(DRIVER2WIRE, rev, fwd, HIGH);
Servo rule; 
Servo eye; 

void getD1(){
  digitalWrite(trigBE, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigBE, HIGH);     // передаем серию импульсов длительностью 10 мкс
  delayMicroseconds(10);
  du1 = pulseIn(echoBE, HIGH); // принимаем отраженные импульсы
  d1 = du1 / 58.2;   // рассчитываем расстояние в см
}

void getD2(){
  digitalWrite(trigTE, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigTE, HIGH);     // передаем серию импульсов длительностью 10 мкс
  delayMicroseconds(10);
  du2 = pulseIn(echoTE, HIGH); // принимаем отраженные импульсы
  d2 = du2 / 58.2;   // рассчитываем расстояние в см
}

void right(){
  motor.setSpeed(250);
  rule.write(zero-60);
  delay(100);
  getD1();
  if(d1 > 200){
    rule.write(zero);
    rounds++;
  }
}

void left(){
  motor.setSpeed(250);
  rule.write(zero+60);
  delay(50);
  getD1();
  if(d1 > 200){
    rule.write(zero);
    rounds++;
  }
  
}

void setup() {
  motor.setMode(AUTO);
  Serial.begin(9600); //для целей отладки, потом можно закомментировать
  pinMode(rev, OUTPUT);      // set Motor pins as output
  pinMode(fwd, OUTPUT);
  rule.attach(6);
  eye.attach(7);
  pinMode(trigBE, OUTPUT);         // set trig pin as output
  pinMode(echoBE, INPUT);          //echo pin в режим ввода данных
  pinMode(trigTE, OUTPUT);         // set trig pin as output
  pinMode(echoTE, INPUT);          //echo pin в режим ввода данных
  rule.write(zero);
  eye.write(180);
  delay(1000);   // задержка на случайное время
}
void loop() {
  getD1();
  getD2();
  delay(10);
  if(rounds >= 13){
    delay(350);
    rule.write(zero);
    delay(150);
      motor.setSpeed(0);
      delay(300000);
  } else {
  if (d1 > 60)  
  
  // no hurdles   
  {
    motor.setSpeed(250);   
    if(d2 > 25 && d2 < 70){
      rule.write(zero-10);
      delay(100);                                               
    }  
    if(d2 < 20){
      rule.write(zero+10);
      delay(100);                                               
    }
    rule.write(zero);
  }
  if (d1 < 60 && d1 != 0)         
  {
    motor.setSpeed(0); 
    delay(200);
    getD2();
    
    if(d2 < 150) {
      left();                                                    
    } else {
       right();
    }
  }
  }
}
