#include "game.h"

#include <QKeyEvent>
#include <QDebug>

game::game() : m_timer(new QTimer(this))
{
    m_timer->start(1000.0f/60.0f);
    Car *C0 = new Car;
    Car *C1 = new Car;
    carList.append(C0);
    carList.append(C1);
}

void game::startRace()
{
    int i=0;
    foreach (Car *car, carList) {
        QThread *thread = new QThread();
        CarThread *carThread = new CarThread(car);
        carThread->moveToThread(thread);
        carThread->keymapping(&keys[i][0],&keys[i][1],&keys[i][2],&keys[i][3]);

        connect(car, &Car::positionChanged, carThread, &CarThread::run);
        connect(thread, &QThread::started, carThread, &CarThread::update);
        connect(carThread, &CarThread::finished, thread, &QThread::quit);
        connect(carThread, &CarThread::finished, carThread, &CarThread::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        threadList.append(thread);
//        carThread->start();
        thread->start();
        i++;
    }
}
