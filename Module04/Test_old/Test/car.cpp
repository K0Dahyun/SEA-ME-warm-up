#include "car.h"
#include <math.h>
#include <QDebug>
#include <cmath>

const double rad2deg = 3.14159265358979/180;

Car::Car()
{
    angle = 90;
    speed = 0;
    max_speed = 5;
}

Car::~Car(){}

void Car::update(bool keys[4])
{
    if (keys[0])
    {
        change_Speed(0.1);
    }
    else if (keys[2])
    {
        change_Speed(-0.1);
    }
    else
    {
        setSpeed(speed*0.95);
    }

    if (keys[1])
    {
        change_Angle(2);
        changed_angle_in_this_period = 2;
    }
    else if (keys[3])
    {
        change_Angle(-2);
        changed_angle_in_this_period = -2;
    }
    else
    {
        changed_angle_in_this_period = 0;
    }
    //    Just use as signal
    emit positionChanged();
}

void Car::move()
{
//    Calculate location(x,y)
    x += speed*cos(angle*rad2deg);
    y -= speed*sin(angle*rad2deg);
    collisionCheck();
}

void Car::change_Angle(float addition_angle)
{
    setAngle(angle + addition_angle);
}

void Car::change_Speed(float addition_speed)
{
    setSpeed(speed + addition_speed);
}

void Car::setAngle(float input_angle)
{
//    Angle Limitation
    while (input_angle<0){input_angle = input_angle+360;};
    while (input_angle>360) {input_angle = input_angle-360;};
    angle = input_angle;
}

void Car::setSpeed(float input_speed)
{
//    Speed Limitation
    if (-max_speed<input_speed && input_speed<max_speed){
        speed = input_speed;
    }
}

void Car::setX(float input_x)
{
    x = input_x;
}

void Car::setY(float input_y)
{
    y = input_y;
}

float Car::getCAITP()
{
    return changed_angle_in_this_period;
}

float Car::getAngle()
{
    return angle;
}

float Car::getSpeed()
{
    return speed;
}

float Car::getX()
{
    return x;
}

float Car::getY()
{
    return y;
}

void Car::reverseDirection()
{
    setAngle(angle + 90);
}


void Car::collisionCheck()
{
//    return;
//    qDebug()<<1;
    for (int i=0; i<12; i+=2)
    {
        int a = out_border[i];
        int b = out_border[i+1];
        int c = out_border[i+2];
        int d = out_border[i+3];
        float ABCD = (b-d)*x+(c-a)*y+a*d-b*c;
        float AB = (b-d)*(b-d) + (c-a)*(c-a);
        float dis = ABCD/std::sqrt(AB);
        if((-2<dis) && (dis<2))
        {
//            setAngle(180-angle);
            setAngle(2*out_border_angle[i/2]-angle);
            qDebug()<<1;
            return;
        }
    }
    for (int i=0; i<12; i+=2)
    {
        int a = in_border[i];
        int b = in_border[i+1];
        int c = in_border[i+2];
        int d = in_border[i+3];
        float ABCD = (b-d)*x+(c-a)*y+a*d-b*c;
        float AB = (b-d)*(b-d) + (c-a)*(c-a);
        float dis = ABCD/std::sqrt(AB);
        if((-2<dis) && (dis<2))
        {
//            setAngle(180-angle);
            setAngle(2*in_border_angle[i/2]-angle);
            qDebug()<<1;
            return;
        }
    }
}
