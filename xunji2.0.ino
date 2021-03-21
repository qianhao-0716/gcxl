int speed = 90, unspeed = 205; //  电机速度
int motor6_front = speed, motor3_front = speed, motor9_front = speed, motor5_front = speed,
    motor6_back = unspeed, motor3_back = unspeed, motor9_back = unspeed, motor5_back = unspeed;
int direction = 0;                            //小车移动方向，1为前，2为后，-1左，-2为右，0为停车
int x = 0, y = 0; //用于计数
int val[5];

void stop()
{
  direction = 0;
  analogWrite(3, 0);
  digitalWrite(2, LOW);
  analogWrite(5, 0);
  digitalWrite(4, LOW);
  analogWrite(6, 0);
  digitalWrite(7, LOW);
  analogWrite(9, 0);
  digitalWrite(8, LOW);
}
void forward()
{
  direction = 1;
  analogWrite(3, 0);
  digitalWrite(2, LOW);
  analogWrite(5, motor5_front);
  digitalWrite(4, LOW);
  analogWrite(6, motor6_front);
  digitalWrite(7, LOW);
  analogWrite(9, 0);
  digitalWrite(8, LOW);
}
void back()
{
  direction = 2;
  analogWrite(3, 0);
  digitalWrite(2, LOW);
  analogWrite(5, motor5_back);
  digitalWrite(4, HIGH);
  analogWrite(6, motor6_back);
  digitalWrite(7, HIGH);
  analogWrite(9, 0);
  digitalWrite(8, LOW);
}
void left()
{
  direction = -1;
  analogWrite(3, motor3_back);
  digitalWrite(2, HIGH);
  analogWrite(5, 0);
  digitalWrite(4, LOW);
  analogWrite(6, 0);
  digitalWrite(7, LOW);
  analogWrite(9, motor9_back);
  digitalWrite(8, HIGH);
}
void right()
{
  direction = -2;
  analogWrite(3, motor3_front);
  digitalWrite(2, LOW);
  analogWrite(5, 0);
  digitalWrite(4, LOW);
  analogWrite(6, 0);
  digitalWrite(7, LOW);
  analogWrite(9, motor9_front);
  digitalWrite(8, LOW);
}

void forwardd()//更改速度
{
  motor5_front = speed;
  motor6_front = speed;
}
void backd()
{
  motor5_back = unspeed;
  motor6_back = unspeed;
}
void leftd()
{
  motor3_back = unspeed;
  motor9_back = unspeed;
}
void rightd()
{
  motor3_front = speed;
  motor9_front = speed;
}
void forward_right()
{
  motor5_front = speed - 25;
  motor6_front = speed + 25;
}
void forward_left()
{
  motor5_front = speed + 25;
  motor6_front = speed - 25;
}
void right_left()
{
  motor3_front = speed - 25;
  motor9_front = speed + 25;
}
void right_right()
{
  motor3_front = speed + 25;
  motor9_front = speed - 25;
}
void back_right()
{
  motor5_back = unspeed - 10;
  motor6_back = unspeed + 10;
}
void back_left()
{
  motor5_back = unspeed + 10;
  motor6_back = unspeed - 10;
}
void left_right()
{
  motor3_back = unspeed + 10;
  motor9_back = unspeed - 10;
}
void left_left()
{
  motor3_back = unspeed - 10;
  motor9_back = unspeed + 10;
}

void stright_line() //走直线
{
  if (direction == 1) //前
  {
    if (digitalRead(22) == 0 && digitalRead(23) == 0 && digitalRead(24) == 0)
    {
      forwardd();
    }
    else if (digitalRead(22) == 0 && digitalRead(23) == 1 && digitalRead(24) == 0)
    {
      forwardd();
    }
    else if (digitalRead(22) == 1 && digitalRead(23) == 1 && digitalRead(24) == 1)
    {
      forwardd();
    }
    else if (digitalRead(22) == 0 && digitalRead(23) == 1 && digitalRead(24) == 1)
    {
      forward_right();
    }
    else if (digitalRead(22) == 0 && digitalRead(23) == 0 && digitalRead(24) == 1)
    {
      forward_right();
    }
    else if (digitalRead(22) == 1 && digitalRead(23) == 1 && digitalRead(24) == 0)
    {
      forward_left();
    }
    else if (digitalRead(22) == 1 && digitalRead(23) == 0 && digitalRead(24) == 0)
    {
      forward_left();
    }
  }
  else if (direction == -2) //右
  {
    if (digitalRead(27) == 0 && digitalRead(28) == 0 && digitalRead(29) == 0)
    {
      rightd();
    }
    else if (digitalRead(27) == 0 && digitalRead(28) == 1 && digitalRead(29) == 0)
    {
      rightd();
    }
    else if (digitalRead(27) == 1 && digitalRead(28) == 1 && digitalRead(29) == 1)
    {
      rightd();
    }
    else if (digitalRead(27) == 0 && digitalRead(28) == 1 && digitalRead(29) == 1)
    {
      right_right();
    }
    else if (digitalRead(27) == 0 && digitalRead(28) == 0 && digitalRead(29) == 1)
    {
      right_right();
    }
    else if (digitalRead(27) == 1 && digitalRead(28) == 1 && digitalRead(29) == 0)
    {
      right_left();
    }
    else if (digitalRead(27) == 1 && digitalRead(28) == 0 && digitalRead(29) == 0)
    {
      right_left();
    }
  }
  else if (direction == 2) //后
  {
    if (digitalRead(19) == 0 && digitalRead(18) == 0 && digitalRead(17) == 0)
    {
      backd();
    }
    else if (digitalRead(19) == 0 && digitalRead(18) == 1 && digitalRead(17) == 0)
    {
      backd();
    }
    else if (digitalRead(19) == 1 && digitalRead(18) == 1 && digitalRead(17) == 1)
    {
      backd();
    }
    else if (digitalRead(19) == 0 && digitalRead(18) == 1 && digitalRead(17) == 1)
    {
      back_left();
    }
    else if (digitalRead(19) == 0 && digitalRead(18) == 0 && digitalRead(17) == 1)
    {
      back_left();
    }
    else if (digitalRead(19) == 1 && digitalRead(18) == 1 && digitalRead(17) == 0)
    {
      back_right();
    }
    else if (digitalRead(19) == 1 && digitalRead(18) == 0 && digitalRead(17) == 0)
    {
      back_right();
    }
  }
  else if (direction == -1) //左
  {
    if (digitalRead(32) == 0 && digitalRead(33) == 0 && digitalRead(34) == 0)
    {
      leftd();
    }
    else if (digitalRead(32) == 0 && digitalRead(33) == 1 && digitalRead(34) == 0)
    {
      leftd();
    }
    else if (digitalRead(32) == 1 && digitalRead(33) == 1 && digitalRead(34) == 1)
    {
      leftd();
    }
    else if (digitalRead(32) == 0 && digitalRead(33) == 1 && digitalRead(34) == 1)
    {
      left_right();
    }
    else if (digitalRead(32) == 0 && digitalRead(33) == 0 && digitalRead(34) == 1)
    {
      left_right();
    }
    else if (digitalRead(32) == 1 && digitalRead(33) == 1 && digitalRead(34) == 0)
    {
      left_left();
    }
    else if (digitalRead(32) == 1 && digitalRead(33) == 0 && digitalRead(34) == 0)
    {
      left_left();
    }
  }
}
void go_to(int X, int Y)
{
  if (Y > y)
  {
    while (1)
    {
      forward();
      direction = 1;
      stright_line();
      count_xy();
      if (y == Y)
        break;
    }
    if (X > x)
    {
      while (1)
      {
        right();
        direction = -2;
        stright_line();
        count_xy();
        if (X == x)
          break;
      }
    }
    else if (X < x)
    {
      while (1)
      {
        left();
        direction = -1;
        stright_line();
        count_xy();
        if (x == X)
          break;
      }
    }
    else
    {
      stop();
    }
  }
  else if (y == Y)
  {
    if (X > x)
    {
      while (1)
      {
        right();
        direction = -2;
        stright_line();
        count_xy();
        if (X == x)
          break;
      }
    }
    else if (X < x)
    {
      while (1)
      {
        left();
        direction = -1;
        stright_line();
        count_xy();
        if (x == X)
          break;
      }
    }
    else
    {
      stop();
    }
  }
  else
  {
    while (1)
    {
      back();
      direction = 2;
      stright_line();
      count_xy();
      if (y == Y)
        break;
    }
    if (X > x)
    {
      while (1)
      {
        right();
        direction = -2;
        stright_line();
        count_xy();
        if (X == x)
          break;
      }
    }
    else if (X < x)
    {
      while (1)
      {
        left();
        direction = -1;
        stright_line();
        count_xy();
        if (x == X)
          break;
      }
    }
    else
    {
      stop();
    }
  }
}
void count_xy() //计数
{
  if (direction = 1)
  {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
      val[i] = digitalRead(21 + i);
      sum += val[i];
    }
    if (sum >= 3)
    {
      while (1)
      {
        forward();
        stright_line();
        if (digitalRead(28) == 1)
        {
          y = y + 1;
          break;
        }
      }
    }
  }
  else if (direction = 2)
  {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
      val[i] = digitalRead(21 + i);
      sum += val[i];
    }
    if (sum >= 3)
    {

      while (1)
      {
        back();
        stright_line();
        if (digitalRead(28) == 1)
        {
          y = y - 1;
          break;
        }
      }
    }
  }
  if (direction = -2) //右
  {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
      val[i] = digitalRead(26 + i);
      sum += val[i];
    }
    if (sum >= 3)
    {
      while (1)
      {
        right();
        stright_line();
        if (digitalRead(23) == 1)
        {
          x = x + 1;
          break;
        }
      }
    }
  }
  if (direction = -1)
  {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
      val[i] = digitalRead(21 + i);
      sum += val[i];
    }
    if (sum >= 3)
    {
      while (1)
      {
        left();
        stright_line();
        if (digitalRead(23) == 1)
        {
          x = x - 1;
          break;
        }
      }
    }
  }
}

void way1()
{
  go_to(2, 1);
  stop();
  delay(500);
  go_to(6, 1);
  stop();
  delay(500);
  go_to(4, 6);
  stop();
  delay(500);
  go_to(7, 4);
  stop();
  delay(500);
  go_to(7, 0);
  stop();
  delay(500);
}

void setup()
{
  pinMode(2, OUTPUT); //电机
  pinMode(4, OUTPUT); //  3   5
  pinMode(7, OUTPUT); //  6   9
  pinMode(8, OUTPUT);

  pinMode(21, INPUT); //循迹灯
  pinMode(22, INPUT); //    21  22  23  24  25
  pinMode(23, INPUT); // 31                    26
  pinMode(24, INPUT); // 32                    27
  pinMode(25, INPUT); // 33                    28
                      // 34                    29
  pinMode(26, INPUT); // 35                    30
  pinMode(27, INPUT); //    20  19  18  17  16
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(30, INPUT);

  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);

  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
}

void loop()
{
  stop();
  delay(1000);
  while (1)
  {
    stright_line();
    back();
  }
}
