#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inputValidator();
    connectButtonSignals(ui);
}

void MainWindow::inputValidator(){
    //set the LineEntey validator using regular expression
    //regular expression breakdown
    //the entry should expect
    //digits, 1 or more times...or
    //+ or minus or times or the equalto sign
    QRegularExpression rx(R"(\d+|\+|-|\*|=|\(|\))");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->inputEntry->setValidator(validator);
}

void MainWindow::connectButtonSignals(Ui::MainWindow *ui){
    //QObject::connect(ui->inputEntry, &QLineEdit::textEdited, this, &MainWindow::checkTextFromKeyBoard);
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
    QObject::connect(ui->leftShiftButton, &QPushButton::clicked, this, &MainWindow::leftShiftButtonClicked);
    QObject::connect(ui->rightShiftButton, &QPushButton::clicked, this, &MainWindow::rightShiftButtonClicked);
    //signal slot to handle pressing on the equal to sign
    QObject::connect(this, &MainWindow::displayAnswer, this, &MainWindow::displayAnswerClicked);
    //signal slot to clear the entry when a math operator button is clicked
    QObject::connect(ui->inputEntry, &QLineEdit::editingFinished, this, &MainWindow::mathOperatorButtonClicked);
}

void MainWindow::mathOperatorButtonClicked(){
    ui->userInputEntry->setText(inputList);
    entryList.clear();
}
void MainWindow::zeroButtonClicked(){
    updateEntry("0");
}
void MainWindow::oneButtonClicked(){
    updateEntry("1");
}
void MainWindow::twoButtonClicked(){
    updateEntry("2");
}
void MainWindow::threeButtonClicked(){
    updateEntry("3");
}
void MainWindow::fourButtonClicked(){
    updateEntry("4");
}
void MainWindow::fiveButtonClicked(){
    updateEntry("5");
}
void MainWindow::sixButtonClicked(){
    updateEntry("6");
}
void MainWindow::sevenButtonClicked(){
    updateEntry("7");
}
void MainWindow::eightButtonClicked(){
    updateEntry("8");
}
void MainWindow::nineButtonClicked(){
    updateEntry("9");
}
void MainWindow::plusButtonClicked(){
    updateEntry("+");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::minusButtonClicked(){
    updateEntry("-");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::timesButtonClicked(){
    updateEntry("*");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::divideButtonClicked(){
    updateEntry("/");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::equalToButtonClicked(){
    emit ui->inputEntry->editingFinished();
    emit MainWindow::displayAnswer();
}
void MainWindow::piButtonClicked(){
    updateEntry("π");
}
void MainWindow::radixPointButtonClicked(){
    updateEntry(".");
}
void MainWindow::answerButtonClicked(){
    emit MainWindow::displayAnswer();
}
void MainWindow::deleteButtonClicked(){
    updateEntry("clear");
}
void MainWindow::resetButtonClicked(){
    updateEntry({});
}
void MainWindow::openBracesButtonClicked(){
    updateEntry("(");
}
void MainWindow::closeBracesButtonClicked(){
    updateEntry(")");
}
void MainWindow::sinButtonClicked(){
    updateEntry("sin(");
}
void MainWindow::cosButtonClicked(){
    updateEntry("cos(");
}
void MainWindow::tanButtonClicked(){
    updateEntry("tan(");
}
void MainWindow::logButtonClicked(){
    updateEntry("log");
}
void MainWindow::naturalLogButtonClicked(){
    updateEntry("ln");
}
void MainWindow::inverseSinButtonClicked(){
    updateEntry("sin-1(");
}
void MainWindow::inverseCosButtonClicked(){
    updateEntry("cos-1(");
}
void MainWindow::inverseTanButtonClicked(){
    updateEntry("tan-1(");
}
void MainWindow::exponentButtonClicked(){
    updateEntry("^");
}
void MainWindow::squareButtonClicked(){
    updateEntry("^2");
}
void MainWindow::rootButtonClicked(){
    updateEntry("√");
}
void MainWindow::squareRootButtonClicked(){
    updateEntry("√");
}
void MainWindow::complexNumberButtonClicked(){
    updateEntry("j");
}
void MainWindow::bitORButtonClicked(){
    updateEntry("OR");
}
void MainWindow::bitANDButtonClicked(){
    updateEntry("AND");
}
void MainWindow::bitXORButtonClicked(){
    updateEntry("XOR");
}
void MainWindow::leftShiftButtonClicked(){
    updateEntry("<<");
}
void MainWindow::rightShiftButtonClicked(){
    updateEntry(">>");
}

void MainWindow::updateEntry(std::optional<QString> entry){
    if (entry.has_value()){
        if (*entry == "clear"){
            if (inputList.size() > 0){
                ui->inputEntry->backspace();
                entryList.clear();
                ui->userInputEntry->setText(entryList);
                inputList.clear();
            }
        }
        else{
            if (auto present = std::any_of(std::cbegin(operators), std::cend(operators), [entry](QString const& elem){
                                           return *entry == elem;}); !present){
                entryList += *entry;
                ui->inputEntry->setText(entryList);
            }
            inputList += *entry;
        }
    }
    else{
        inputList.clear();
    }
}

void MainWindow::displayAnswerClicked(){
    ui->answerLabel->setText(currentAnswer);
}


MainWindow::~MainWindow()
{
    delete ui;
}
