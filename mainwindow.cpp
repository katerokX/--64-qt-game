#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startwindow.h"

#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    // Мэнюшкааа
    start_window();

     //keyEscape = new QShortcut(this);
     //keyEscape->setKey(Qt::Key_Escape);
     //connect(keyEscape, SIGNAL(activated()), this, SLOT(slotShortEscape()));


    //создаём окно
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    grid = new QGridLayout(centralWidget);

    newGame = new QPushButton();
    newGame->setText("New Game");
    QObject::connect(newGame, SIGNAL(clicked()), this, SLOT(Init()));
    grid->addWidget(newGame, 0, 0);




    //надпись 2048
    title = new QLabel("+-64", this);
    title->setAlignment(Qt::AlignCenter); //выравнивание
    title->setStyleSheet("QLabel { color: black; font:20pt; font-weight:500; }");
    grid->addWidget(title, 0, 1);

    //надпись game
    title2 = new QLabel("game", this);
    title2->setAlignment(Qt::AlignCenter);
    title2->setStyleSheet("QLabel { color: black; font:20pt; font-weight:300; }");
    grid->addWidget(title2, 0, 2);

    //создаём надпись счетчик
    score = 0;
    scoreLabel = new QLabel("Score: \n 0", this);
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setStyleSheet("QLabel { background-color: #bbae9e; color: white; font:15pt; font-weight:200; border-radius: 5px; }");
    grid->addWidget(scoreLabel, 0, 3);

    //создаём ячейки с цифрами
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            labels[i][j] = new QLabel("", this);
            grid->addWidget(labels[i][j], i+1, j);
            labels[i][j]->setAlignment(Qt::AlignCenter);
            changeColor(i, j);
        }
    labels[1][0]->setFocus();

    //параметры окна
    setWindowTitle("2048");
    setFixedSize(400, 400);
    Generate();



}

MainWindow::~MainWindow() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            delete labels[i][j];
}

void MainWindow::slotShortEscape(){
    start_window();
}




//менюшкаааааа
void MainWindow::start_window()
{

    // Show the first window and choose complexity.
    startWindow = new StartWindow;
    startWindow->exec();

    int complexity = startWindow->clicked_start();
    if (complexity == 1)
        {
            sizeField = 10;
            countMines = 8;
        }
    else
        std::exit(1);
}

//новая игра
void MainWindow::Init() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            labels[i][j]->setText("");
            changeColor(i, j);
        }
    newGame->clearFocus();
    Generate();
}

void MainWindow::GetRandonNumber(int min, int max){
    srand(time(NULL));

     // Получить случайное число - формула
     int num = min + rand() % (max - min + 1);

}



//генирируем  ячейки
void MainWindow::Generate() {
    bool hasPlace = false;
    for (int i = 0; i < 4; ++i)
         for (int j = 0; j < 4; ++j) {
             if (labels[i][j]->text() == "" || labels[i][j]->text() == "2") {
                 hasPlace = true;
                 break;
             }
             if ( labels[i][j]->text() == "64"){
                 endwind();
             }

         }

     if (!hasPlace) {
         QDialog* endDialog = new QDialog();
         endDialog->setMinimumWidth(200);
         endDialog->show();
     }
     GetRandonNumber(1, 2);
     int row = 0, column = 0;
     int r = 0;
     do {
         row = rand() % 4;
         column = rand() % 4;
     } while (labels[row][column]->text() != "" && labels[row][column]->text() != "2" && labels[row][column]->text() != "-2" );
    // labels[row][column]->setText(QString::number(labels[row][column]->text().toInt() + 2));
    // labels[row][column]->setText(QString::number(labels[row][column]->text().toInt() - 2));
    //changeColor(row,column);
     r = rand() % 2 +1;
     if(r ==
             1) {
         labels[row][column]->setText(+ "2");
     }
     if(r == 2) {
         labels[row][column]->setText(+ "-2");
     }

changeColor(row,column);


 }


//добавляем таблицу стилей setStyleSheet
void MainWindow::changeColor(int i, int j) {
    if(labels[i][j]->text().toStdString()!="O")
    {
        switch (labels[i][j]->text().toInt()) {
            case -64:
                labels[i][j]->setStyleSheet("QLabel { background-color: #2b00f7; color: white; font:20pt; font-weight:400; border-radius: 5px;}");
            break;
            case -32:
                labels[i][j]->setStyleSheet("QLabel { background-color: #717aff; color: white; font:20pt; font-weight:400;border-radius: 5px;}");
                break;
            case -16:
                labels[i][j]->setStyleSheet("QLabel { background-color: #4b5eff; color: white; font:20pt; font-weight:400;border-radius: 5px;}");
                break;
            case -8:
                labels[i][j]->setStyleSheet("QLabel { background-color: #717aff; color: white; font:20pt; font-weight:400;border-radius: 5px;}");
                break;
            case -4:
                labels[i][j]->setStyleSheet("QLabel { background-color: #85afff; color: black; font:20pt; font-weight:400; border-radius: 5px;}");
                break;
            case -2:
                labels[i][j]->setStyleSheet("QLabel { background-color: #a5b9ff; color: black; font:20pt; font-weight:400; border-radius: 5px;}");
                break;
            case 0:
                labels[i][j]->setStyleSheet("QLabel { background-color: #cdc1b5; color: black; font:20pt; font-weight:400; border-radius: 5px;}");
                break;
            case 2:
                labels[i][j]->setStyleSheet("QLabel { background-color: #eee4da; color: black; font:20pt; font-weight:400; border-radius: 5px;}");
                break;
            case 4:
                labels[i][j]->setStyleSheet("QLabel { background-color: #eddfc4; color: black; font:20pt; font-weight:400;border-radius: 5px;}");
                break;
            case 8:
                labels[i][j]->setStyleSheet("QLabel { background-color: #f4b17a; color: white; font:20pt; font-weight:400;border-radius: 5px;}");
                break;
            case 16:
                labels[i][j]->setStyleSheet("QLabel { background-color: #f79663; color: white; font:20pt; font-weight:400;border-radius: 5px;}");
                break;
            case 32:
                labels[i][j]->setStyleSheet("QLabel { background-color: #f67d62; color: white; font:20pt; font-weight:400;border-radius: 5px;}");
                break;
            case 64:
                labels[i][j]->setStyleSheet("QLabel { background-color: #f65e39; color: white; font:20pt; font-weight:400; border-radius: 5px;}");
                break;

        }
    }
    else
    {
        labels[i][j]->setStyleSheet("QLabel { background-color: #9a9a9a; color: black; font:20pt; font-weight:400; border-radius: 5px;}");
    }

}

//привязываем клавиши
void MainWindow::keyPressEvent(QKeyEvent * event) {
    QString* a[4][4];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            a[i][j] = new QString(labels[i][j]->text());

    switch (event->key()) {
        case Qt::Key_Up:
            up();
            break;
        case Qt::Key_Down:
            down();
            break;
        case Qt::Key_Left:
            left();
            break;
        case Qt::Key_Right:
            right();
            break;
        default:
          QMainWindow::keyPressEvent(event);
    }

    bool flag = false;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (a[i][j]->toStdString() != labels[i][j]->text().toStdString()){
                flag = true;

            }


    if (flag)
        Generate();
}

void MainWindow::down() {
    for (int j = 0; j < 4; ++j)
        for (int i = 3; i >= 0; --i)
            if (labels[i][j]->text() == "")
                for (int k = i-1; k >= 0; --k)
                    if (labels[k][j]->text() != "")
                    {
                        labels[i][j]->setText(labels[k][j]->text());
                        changeColor(i,j);
                        labels[k][j]->setText("");
                        changeColor(k,j);
                        if(labels[i][j]==0) labels[i][j]->setText("");
                        break;
                    }
    int k;

    //cчетчик
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 2; i >= 0; i--)
        {
            if (labels[i][j]->text().toStdString()!="O" && labels[i][j]->text() == labels[i+1][j]->text() && labels[i][j]->text() != "")
            {
                labels[i+1][j]->setText(QString::number(labels[i+1][j]->text().toInt() * 2));
                score += abs(labels[i+1][j]->text().toInt());
                scoreLabel->setText("Score: \n" + QString::number(score));
                changeColor(i+1, j);

                k = i;
                while (k > 0)
                {
                    k--;
                    labels[k+1][j]->setText(labels[k][j]->text());
                    changeColor(k+1, j);
                }
                if (k == 0)
                {
                    labels[0][j]->setText("");
                    changeColor(0, j);
                }
            }

            if (labels[i][j]->text().toInt()==-labels[i+1][j]->text().toInt() && labels[i][j]->text() != ""  )
            {
                labels[i+1][j]->setText("O");
                changeColor(i+1, j);
                k = i;
                while (k > 0)
                {
                    k--;
                    labels[k+1][j]->setText(labels[k][j]->text());
                    if(labels[k+1][j]==0) labels[k+1][j]->setText("");
                    changeColor(k+1, j);
                }
                if (k == 0)
                {
                    labels[0][j]->setText("");
                    changeColor(0, j);
                }
            }

            if (labels[i][j]->text() == labels[i+1][j]->text() && labels[i+1][j]->text().toStdString()=="O" && labels[i][j]->text() != "")
            {
                labels[i+1][j]->setText("O");

                changeColor(i+1, j);
                k = i;
                while (k > 0)
                {
                    k--;
                    labels[k+1][j]->setText(labels[k][j]->text());
                    if(labels[k+1][j]==0) labels[k+1][j]->setText("");
                    changeColor(k+1, j);
                }
                if (k == 0)
                {
                    labels[0][j]->setText("");
                    changeColor(0, j);
                }
            }
        }
    }
}

void MainWindow::up() {
    rotate();
    rotate();
    down();
    rotate();
    rotate();

}

void MainWindow::left() {
    rotate();
    down();
    rotate();
    rotate();
    rotate();

}

void MainWindow::right() {
    rotate();
    rotate();
    rotate();
    down();
    rotate();

}

//
void MainWindow::rotate() {
    int a[4][4];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            if(labels[i][j]->text().toStdString()!="O") a[4-j-1][i] = labels[i][j]->text().toInt();
            if(labels[i][j]->text().toStdString()=="O") a[4-j-1][i] = 11;
        }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (a[i][j] == 0) {labels[i][j]->setText("");}
            else
            {
                if(a[i][j]!=11) labels[i][j]->setText(QString::number(a[i][j]));
                if(a[i][j]==11) labels[i][j]->setText("O");
            }
            changeColor(i, j);
        }
    }
}

void MainWindow::endwind(){

    endWindow = new EndWindow;
             endWindow->win_lbl();
             endWindow->show();
             endWindow->exec();
             Init();
}
