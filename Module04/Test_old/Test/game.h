#ifndef GAME_H
#define GAME_H

#include "car.h"
#include "carthread.h"
#include "track.h"

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QThread>

class game : public QGraphicsScene
{
    Q_OBJECT
public:
    game();
    QTimer* m_timer;
//    Car car[2];
    QList<Car*> carList;
    QList<QThread*> threadList;
    bool keys[2][4] = {false};
    Track track;

public:
    void startRace();
//    void pauseRace();
//    void exitRace();
};

#endif // GAME_H
