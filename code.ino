int Echo1 = A4;
int Trig1 = A5;
int Echo2 = A2;
int Trig2 = A3;
int Echo3 = A0;
int Trig3 = A1;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int LeftDistance = 0;
int RightDistance = 0;
int MiddleDistance = 0;
char d = 0;
void Forward()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void Back()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
void Left()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
void Right()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void Stop()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
void obstacle()
{
    if (MiddleDistance ≤ 30)
    {
        if (RightDistance > LeftDistance)
        {
            if ((RightDistance ≤ 20) && (Lef tDistance ≤ 20))
            {
                Stop();
                delay(200);
                Back();
                delay(1000);
                Right();
                delay(500);
                Forward();
            }
            else
            {
                Right();
                delay(500);
                Forward();
            }
        }
        else if (RightDistance < LeftDistance)
        {
            if ((RightDistance ≤ 20) && (Lef tDistance ≤ 20))
            {
                Stop();
                delay(200);
                Back();
                delay(1000);
                Left();
                delay(500);
                Forward();
            }
            else
            {
                Left();
                delay(500);
                Forward();
            }
        }
    }
    else if (RightDistance ≤ 15)
    {
        Left();
        delay(100);
    }
    else if (LeftDistance ≤ 15)
    {
        Right();
        delay(100);
    }
    else
    {
        Forward();
    }
}
int LeftDistanceTest()
{
    digitalWrite(Trig1, HIGH);
    delayMicroseconds(20);
    digitalWrite(Trig1, LOW);
    float distance = pulseIn(Echo1, HIGH);
    delay(10);
    distance = (distance * 0.034) / 2;
    return (int)distance;
}
int MiddleDistanceTest()
{
    digitalWrite(Trig2, HIGH);
    delayMicroseconds(20);
    digitalWrite(Trig2, LOW);
    float distance = pulseIn(Echo2, HIGH);
    delay(10);
    distance = (distance * 0.034) / 2;
    return (int)distance;
}
int RightDistanceTest()
{
    digitalWrite(Trig3, HIGH);
    delayMicroseconds(20);
    digitalWrite(Trig3, LOW);
    float distance = pulseIn(Echo3, HIGH);
    delay(10);
    distance = (distance * 0.034) / 2;
    return (int)distance;
}
void setup()
{
    Serial.begin(9600);
    pinMode(Echo1, INPUT);
    pinMode(Trig1, OUTPUT);
    pinMode(Echo2, INPUT);
    pinMode(Trig2, OUTPUT);
    pinMode(Echo3, INPUT);
    pinMode(Trig3, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}
void loop()
{
    MiddleDistance = MiddleDistanceTest();
    RightDistance = RightDistanceTest();
    LeftDistance = LeftDistanceTest();
    if (Serial.available() > 0)
    {
        d = Serial.read();
        if (d == ’F’)
        {
            Forward();
            obstacle();
        }
        else if (d == ’B’)
        {
            Right();
            delay(2000);
            obstacle();
        }
        else if (d == ’L’)
        {
            Left();
            delay(500);
            obstacle();
        }
        else if (d == ’R’)
        {
            Right();
            delay(500);
            obstacle();
        }
        else if (d == ’S’)
        {
            Stop();
        }
        else
        {
            Stop();
            delay(5000);
        }
    }
    else
    {
        obstacle();
    }
}
