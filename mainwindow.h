#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "endwindow.h"
#include "startwindow.h"
#include "startwindow.h"


#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QKeyEvent>
#include <QDialog>
#include <QPushButton>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

static int sizeField;
static int countMines;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void keyPressEvent(QKeyEvent * event);

private slots:
    void Init();

private:
    void Generate();
    void up();
    void down();
    void left();
    void right();
    void rotate();
    void changeColor(int x, int y);
    void endwind();
    void start_window();
    int score;
    void slotShortEscape();
    void GetRandonNumber(int min, int max);


    QComboBox *menu;
    QWidget *centralWidget;
    EndWindow *endWindow;
    QPushButton *newGame, *about, *cmd;
    QLabel *title, *title2;
    QLabel *scoreLabel;
    QGridLayout *grid;
    QLabel* labels[4][4];
    StartWindow *startWindow;

    QShortcut *keyEscape;

    //QShortcut key_esc1; //объект горячей клавишы Esc
};

#endif // MAINWINDOW_H
