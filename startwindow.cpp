#include "startwindow.h"



StartWindow::StartWindow(QWidget *parent) : QDialog(parent, Qt::WindowCloseButtonHint)
{
    this->setStyleSheet(
        " QDialog {                   "
        " background-color: #eee4da; "
        " }                           "
        "                             "
        " QRadioButton {              "
        " font-size: 15px;  "

        " }                           "
        "                             "
        " QPushButton {               "
        " font-size: 20px;  "
        "background-color: #cdc1b5   "
        " }                           "
);

    setWindowTitle("2048");
    setFixedSize(400, 400);



    newg = new QRadioButton("&+-64" );
    newg2 = new QRadioButton("&2048");
    start = new QPushButton ("&Start" );
    exit = new QPushButton ("&Exit" );
    settings = new QPushButton("&Settings");
    update = new QPushButton("Update");

    about = new QPushButton("About QT");

    title2 = new QLabel("+-64", this);
    title2->setAlignment(Qt::AlignCenter); //выравнивание
    title2->setStyleSheet("QLabel { color: black; font:30pt; font-weight:500; }");


    startgame = new QGridLayout;
    startgame->addWidget(newg,  1, 1 );
    //startgame->addWidget(newg2, 2, 1);

    buttons = new QGridLayout;
    buttons->addWidget(start, 2 , 0);
    buttons->addWidget(exit, 6, 0 );
    buttons->addWidget(about, 3, 0);
    buttons->addWidget(title2, 0, 0);
    buttons->addWidget(settings, 4, 0);
    buttons->addWidget(update,5, 0);

    full = new QVBoxLayout;
    full->addLayout(startgame);
    full->addLayout(buttons);

    setLayout(full);

    this->setWindowIcon(windowIcon);
    connect(start, &QRadioButton::clicked, this, &StartWindow::unlockingButton);
    connect(start, &QPushButton ::clicked, this, &StartWindow::clicked_start );
    connect(exit, &QPushButton ::clicked, this, &StartWindow::clicked_exit );
    connect(about, &QPushButton::clicked, this, &StartWindow::clicked_about);
    connect(settings, &QPushButton::clicked, this, &StartWindow::settigs_clicked);
    connect(update, &QPushButton::clicked, this, &StartWindow::up_clicked);

    }

StartWindow::~StartWindow()
    {}

void StartWindow::unlockingButton()
    {
        start->setEnabled(true);
    }

int StartWindow::clicked_start()
    {

        this->close();
        int complexity = newg->isChecked();
        return complexity;
    }

int StartWindow::clicked_about()
    {
        qApp->aboutQt();
        return 1;
    }

void StartWindow::settigs_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        QApplication::setFont(font);
        QSettings settings(this);
         settings.setValue("VIEWF", font);

    } else return;

}

bool StartWindow::clicked_exit()
    {
        std::exit(1);
    }

void StartWindow::up_clicked()  {

    progressBar.setMinimum(0);
    progressBar.setMaximum(100);

    progressBar.show();

    // or as alternative to the two above, you could call
    // progressBar.setRange(0,100);

    for( int i = 0; i <10000; ++i ) {
       progressBar.setValue(i);
    }
     // updateWind = new updatewind;
    //updateWind->win_lbl();
    //updateWind->show();
    //updateWind->exec();

    //updatewind();
    //game2 = new MainWindow2048();
    //game2->show();
     //qApp->aboutQt();
    //поthis->close();




}
