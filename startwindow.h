#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include <QDialog>
#include <QtWidgets>



class StartWindow : public QDialog
{
public:
    StartWindow(QWidget *parent = 0);
    ~StartWindow();

    QRadioButton *newg, *newg2;
    QPushButton *start, *exit, *about, *settings, *update;
    QGridLayout *startgame, *buttons;
    QVBoxLayout *full;
    QLabel *title2;
    QProgressBar progressBar;
    //QTimer *timer;
    QTimer timer;

    QIcon windowIcon;


public slots:
    void unlockingButton();
    int clicked_start();
    bool clicked_exit();
    int clicked_about();
    void settigs_clicked();
    void up_clicked();

private:

    //MainWindow2048 *game2;



};
#endif // STARTWINDOW_H
