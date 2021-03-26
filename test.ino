#define zuoqian 2      //左前轮使能
#define zuohou 3      //左后轮使能
#define youhou 4     //右后轮使能
#define youqian 5     //右前轮使能、
#define zqIn1 37
#define zqIn2 36
#define zhIn1 35
#define zhIn2 34
#define yhIn1 33
#define yhIn2 32
#define yqIn1 31
#define yqIn2 30

void forward()
{
    analogWrite(5,255);
    digitalWrite(yqIn1,LOW);
    digitalWrite(yqIn2,HIGH);
    analogWrite(3,255);
    digitalWrite(zhIn1,HIGH);
    digitalWrite(zhIn2,LOW);
    analogWrite(zuoqian,LOW);
    analogWrite(youhou,LOW);
}
void setup() {

    pinMode(A15,INPUT);
    pinMode(A14,INPUT);
    pinMode(A13,INPUT); //  15 14 13
    pinMode(A12,INPUT); //7          6
    pinMode(A11,INPUT); //8          5
    pinMode(A10,INPUT); //9          4
    pinMode(A9,INPUT);  //  12 11 10
    pinMode(A8,INPUT);
    pinMode(A7,INPUT);
    pinMode(A6,INPUT);
    pinMode(A5,INPUT);
    pinMode(A4,INPUT); 

    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(37,OUTPUT);
    pinMode(36,OUTPUT);
    pinMode(35,OUTPUT);
    pinMode(34,OUTPUT);
    pinMode(33,OUTPUT);
    pinMode(32,OUTPUT);
    pinMode(31,OUTPUT);
    pinMode(30,OUTPUT);
}

void loop() {
  while(1){
    forward();
  }
}
