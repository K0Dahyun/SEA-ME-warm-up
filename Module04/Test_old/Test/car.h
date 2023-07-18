#ifndef CAR_H
#define CAR_H

#include <vector>

#include <QObject>
#include <QWidget>

class Car : public QObject
{
    Q_OBJECT
public:
    Car();
    ~Car();

    void update(bool keys[4]);
    void move();

    void change_Angle(float addition_angle);
    void change_Speed(float addition_speed);
    void setAngle(float input_angle);
    void setSpeed(float input_speed);
    void setX(float input_x);
    void setY(float input_y);
    float getCAITP();
    float getAngle();
    float getSpeed();
    float getX();
    float getY();
    void reverseDirection();
    void collisionCheck();

    float x;
    float y;

signals:
    void positionChanged();

private:
//    Caution with Variable Type!!
    float angle;
    float speed;
    float changed_angle_in_this_period;
    float max_speed;
    int out_border[14] = {0,680, 0,20, 330,20, 330,155, 540,155, 540,680, 0,680};
    int out_border_angle[6] = {90, 0, 90, 0, 90, 0};
    int in_border[14] = {95,620, 95,75, 230,75, 230,290, 430,290, 430,620, 95,620};
    int in_border_angle[6] = {90, 0, 90, 0, 90, 0};

};

#endif // CAR_H
