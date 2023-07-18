#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    Load Car Image
    CAR_img[0].load(":/images/images/car0.png");
    CAR_img[1].load(":/images/images/car1.png");

//    Set Pointer
    CAR_ptr[0] = ui->CAR0;
    CAR_ptr[1] = ui->CAR1;

//    Initialize Car's position by Label geometry
    for (int i=0; i<CAR_count; i++)
    {
        CAR_ang[i] = 90.0;
        CAR_rot[i].rotate(0);
        CAR_ptr[i]->setPixmap(CAR_img[i].transformed(CAR_rot[i]));
        test_game.carList[i]->setX(CAR_ptr[i]->geometry().x());
        test_game.carList[i]->setY(CAR_ptr[i]->geometry().y());
        CAR_ptr[i]->setGeometry(test_game.carList[i]->getX(),test_game.carList[i]->getY(),70,70);
    }

//    Update By Qtimer(60fps)
    connect(test_game.m_timer, SIGNAL(timeout()), this, SLOT(gui_update()));

    connect(ui->actionSTART,  SIGNAL(triggered()), this, SLOT(start()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    test_game.startRace();
}

void MainWindow::gui_update()
{
    for (int i=0; i<CAR_count; i++)
    {
        CAR_rot[i].rotate(-(test_game.carList[i]->getAngle()-CAR_ang[i]));
        qDebug() << "The angle is: " << test_game.carList[i]->getAngle()-CAR_ang[i];
        CAR_ang[i] = test_game.carList[i]->getAngle();
        CAR_ptr[i]->setPixmap(CAR_img[i].transformed(CAR_rot[i]));
        CAR_ptr[i]->setGeometry(test_game.carList[i]->getX(),test_game.carList[i]->getY(),70,70);
    }

    //trackCollision();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
//    For CAR0
    case Qt::Key_W:
        test_game.keys[0][0] = true;
        break;
    case Qt::Key_A:
        test_game.keys[0][1] = true;
        break;
    case Qt::Key_S:
        test_game.keys[0][2] = true;
        break;
    case Qt::Key_D:
        test_game.keys[0][3] = true;
        break;


//    For CAR1
    case Qt::Key_Up:
        test_game.keys[1][0] = true;
        break;
    case Qt::Key_Left:
        test_game.keys[1][1] = true;
        break;
    case Qt::Key_Down:
        test_game.keys[1][2] = true;
        break;
    case Qt::Key_Right:
        test_game.keys[1][3] = true;
        break;
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
//    For CAR0
    case Qt::Key_W:
        test_game.keys[0][0] = false;
        break;
    case Qt::Key_A:
        test_game.keys[0][1] = false;
        break;
    case Qt::Key_S:
        test_game.keys[0][2] = false;
        break;
    case Qt::Key_D:
        test_game.keys[0][3] = false;
        break;

//    For CAR1
    case Qt::Key_Up:
        test_game.keys[1][0] = false;
        break;
    case Qt::Key_Left:
        test_game.keys[1][1] = false;
        break;
    case Qt::Key_Down:
        test_game.keys[1][2] = false;
        break;
    case Qt::Key_Right:
        test_game.keys[1][3] = false;
        break;
    }
}

void MainWindow::trackCollision(){
    for(int i = 0; i < CAR_count; i++){
        isCarInTrack = test_game.track.isPointin(test_game.carList[i]->getX(), test_game.carList[i]->getY());
        if(!isCarInTrack) {
            int normalAngle = test_game.track.getNormalAngle(test_game.carList[i]->getX(), test_game.carList[i]->getY());
            if(normalAngle != -1) {
                float newAngle = 2*normalAngle - test_game.carList[i]->getAngle() + 180;
                test_game.carList[i]->setAngle(newAngle);
            }
        }
    }
}

/*
void MainWindow::trackCollision(){
    for(int i = 0; i < CAR_count; i++){
        isCarInTrack = test_game.track.isPointin(test_game.carList[i]->getX(), test_game.carList[i]->getY());
        if(!isCarInTrack) {
            test_game.carList[i]->reverseDirection();
        }
    }
}
*/




/*
void MainWindow::trackCollision(){
    for(int i = 0; i < CAR_count; i++){
        isCarInTrack = test_game.track.isPointin(test_game.carList[i]->getX(), test_game.carList[i]->getY());
        if(!isCarInTrack) {
            test_game.carList[i]->reverseDirection();
        }
    }
}
*/
/*
void MainWindow::trackCollision()
{
    for(int i = 0; i < CAR_count;i++)
    {
        for(int j=0; j< Track_count; j++)
        {
            if(track.isPointin(test_game.carList[i]->x, test_game.carList[i]->y) == false)
            {
                int dx=0, dy=0;
                int virtual_car_x
                while (dx*dx + dy*dy < 4* 7 * 7)
                {
                    m_game.car[i].x += dx/10.0;
                    m_game.car[i].y += dy/10.0;
                    m_game.car[j].x -= dx/10.0;
                    m_game.car[j].y -= dy/10.0;
                    dx = m_game.car[i].x - m_game.car[j].x;
                    dy = m_game.car[i].y - m_game.car[j].y;
                    if (!dx && !dy)
                    {
                        break;
                    }
                }
            }
        }
    }
}
*/

