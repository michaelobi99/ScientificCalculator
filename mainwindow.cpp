#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectButtonSignals(ui);
}

void MainWindow::connectButtonSignals(Ui::MainWindow *ui){
    QObject::connect(ui->zeroButton, &QPushButton::clicked, this, &MainWindow::zeroButtonClicked);
    QObject::connect(ui->oneButton, &QPushButton::clicked, this, &MainWindow::oneButtonClicked);
    QObject::connect(ui->twoButton, &QPushButton::clicked, this, &MainWindow::twoButtonClicked);
    QObject::connect(ui->threeButton, &QPushButton::clicked, this, &MainWindow::threeButtonClicked);
    QObject::connect(ui->fourButton, &QPushButton::clicked, this, &MainWindow::fourButtonClicked);
    QObject::connect(ui->fiveButton, &QPushButton::clicked, this, &MainWindow::fiveButtonClicked);
    QObject::connect(ui->sixButton, &QPushButton::clicked, this, &MainWindow::sixButtonClicked);
    QObject::connect(ui->sevenButton, &QPushButton::clicked, this, &MainWindow::sevenButtonClicked);
    QObject::connect(ui->eightButton, &QPushButton::clicked, this, &MainWindow::eightButtonClicked);
    QObject::connect(ui->nineButton, &QPushButton::clicked, this, &MainWindow::nineButtonClicked);
    QObject::connect(ui->plusButton, &QPushButton::clicked, this, &MainWindow::plusButtonClicked);
    QObject::connect(ui->minusButton, &QPushButton::clicked, this, &MainWindow::minusButtonClicked);
    QObject::connect(ui->timesButton, &QPushButton::clicked, this, &MainWindow::timesButtonClicked);
    QObject::connect(ui->divideButton, &QPushButton::clicked, this, &MainWindow::divideButtonClicked);
    QObject::connect(ui->equalToButton, &QPushButton::clicked, this, &MainWindow::equalToButtonClicked);
    QObject::connect(ui->piButton, &QPushButton::clicked, this, &MainWindow::piButtonClicked);
    QObject::connect(ui->radixPointButton, &QPushButton::clicked, this, &MainWindow::radixPointButtonClicked);
    QObject::connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::deleteButtonClicked);
    QObject::connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetButtonClicked);
    QObject::connect(ui->openBracesButton, &QPushButton::clicked, this, &MainWindow::openBracesButtonClicked);
    QObject::connect(ui->closeBracesButton, &QPushButton::clicked, this, &MainWindow::closeBracesButtonClicked);
    QObject::connect(ui->sineButton, &QPushButton::clicked, this, &MainWindow::sinButtonClicked);
    QObject::connect(ui->cosineButton, &QPushButton::clicked, this, &MainWindow::cosButtonClicked);
    QObject::connect(ui->tangentButton, &QPushButton::clicked, this, &MainWindow::tanButtonClicked);
    QObject::connect(ui->logButton, &QPushButton::clicked, this, &MainWindow::logButtonClicked);
    QObject::connect(ui->naturalLogButton, &QPushButton::clicked, this, &MainWindow::naturalLogButtonClicked);
    QObject::connect(ui->inverseSinButton, &QPushButton::clicked, this, &MainWindow::inverseSinButtonClicked);
    QObject::connect(ui->inverseCosButton, &QPushButton::clicked, this, &MainWindow::inverseCosButtonClicked);
    QObject::connect(ui->inverseTanButton, &QPushButton::clicked, this, &MainWindow::inverseTanButtonClicked);
    QObject::connect(ui->exponentButton, &QPushButton::clicked, this, &MainWindow::exponentButtonClicked);
    QObject::connect(ui->squareButton, &QPushButton::clicked, this, &MainWindow::squareButtonClicked);
    QObject::connect(ui->rootButton, &QPushButton::clicked, this, &MainWindow::rootButtonClicked);
    QObject::connect(ui->squareRootButton, &QPushButton::clicked, this, &MainWindow::squareRootButtonClicked);
    QObject::connect(ui->complexNumberButton, &QPushButton::clicked, this, &MainWindow::complexNumberButtonClicked);
    QObject::connect(ui->bitORButton, &QPushButton::clicked, this, &MainWindow::bitORButtonClicked);
    QObject::connect(ui->bitANDButton, &QPushButton::clicked, this, &MainWindow::bitANDButtonClicked);
    QObject::connect(ui->bitXORButton, &QPushButton::clicked, this, &MainWindow::bitXORButtonClicked);
    QObject::connect(ui->differentialButton, &QPushButton::clicked, this, &MainWindow::differentialButtonClicked);
    QObject::connect(ui->onButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}
void MainWindow::zeroButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "0");
}
void MainWindow::oneButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "1");
}
void MainWindow::twoButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "2");
}
void MainWindow::threeButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "3");
}
void MainWindow::fourButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "4");
}
void MainWindow::fiveButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "5");
}
void MainWindow::sixButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "6");
}
void MainWindow::sevenButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "7");
}
void MainWindow::eightButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "8");
}
void MainWindow::nineButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "9");
}
void MainWindow::plusButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "+");
}
void MainWindow::minusButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "-");
}
void MainWindow::timesButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "*");
}
void MainWindow::divideButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "/");
}
void MainWindow::equalToButtonClicked(){
    //ui->inputEntry->setText("9");
}
void MainWindow::piButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "π");
}
void MainWindow::radixPointButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + ".");
}
void MainWindow::answerButtonClicked(){
    //ui->inputEntry->setText(".");
}
void MainWindow::deleteButtonClicked(){
    ui->inputEntry->backspace();
}
void MainWindow::resetButtonClicked(){
    ui->inputEntry->setText("0");
}
void MainWindow::openBracesButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "(");
}
void MainWindow::closeBracesButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + ")");
}
void MainWindow::sinButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "sin(");
}
void MainWindow::cosButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "cos(");
}
void MainWindow::tanButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "tan(");
}
void MainWindow::logButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "log");
}
void MainWindow::naturalLogButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "ln");
}
void MainWindow::inverseSinButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "sin-1(");
}
void MainWindow::inverseCosButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "cos-1(");
}
void MainWindow::inverseTanButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "tan-1(");
}
void MainWindow::exponentButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "^");
}
void MainWindow::squareButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "^2");
}
void MainWindow::rootButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "√");
}
void MainWindow::squareRootButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "2√");
}
void MainWindow::complexNumberButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "j");
}
void MainWindow::bitORButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "OR");
}
void MainWindow::bitANDButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "AND");
}
void MainWindow::bitXORButtonClicked(){
    ui->inputEntry->setText(ui->inputEntry->text() + "XOR");
}
void MainWindow::differentialButtonClicked(){
    //ui->inputEntry->setText(ui->inputEntry->text() + "(");
}
void MainWindow::onButtonClicked(){
    //......
}


MainWindow::~MainWindow()
{
    delete ui;
}

