#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <vector>
#include "game.h"
#include "track.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    game test_game;
    Track track;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    void trackCollision();
    int CAR_count = 2;
    int Track_count = 6;
    QLabel *CAR_ptr[2];
    bool isCarInTrack;

public slots:
    void gui_update();
    void start();

private:
    float CAR_ang[2];
    QPixmap CAR_img[2];
    QTransform CAR_rot[2];

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
