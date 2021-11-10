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
    QObject::connect(this, &MainWindow::displayAnswer, this, &MainWindow::displayAnswerClicked);
    //signal slot to clear the entry when a math operator button is clicked
    QObject::connect(ui->inputEntry, &QLineEdit::editingFinished, this, &MainWindow::mathOperatorButtonClicked);
}

void MainWindow::mathOperatorButtonClicked(){
    ui->userInputEntry->setText(asString(inputList));
    ui->answerLabel->setText(currentAnswer);
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
    updateEntry("=");
    emit ui->inputEntry->editingFinished();
    emit MainWindow::displayAnswer();
    inputList.clear();
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
    updateEntry("log(");
}
void MainWindow::naturalLogButtonClicked(){
    updateEntry("ln(");
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
    emit ui->inputEntry->editingFinished();
}
void MainWindow::squareButtonClicked(){
    updateEntry("^2");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::rootButtonClicked(){
    updateEntry("√");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::squareRootButtonClicked(){
    updateEntry("sqrt(");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::complexNumberButtonClicked(){
    updateEntry("j");
}
void MainWindow::bitORButtonClicked(){
    updateEntry("OR");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::bitANDButtonClicked(){
    updateEntry("AND");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::bitXORButtonClicked(){
    updateEntry("XOR");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::leftShiftButtonClicked(){
    updateEntry("<<");
    emit ui->inputEntry->editingFinished();
}
void MainWindow::rightShiftButtonClicked(){
    updateEntry(">>");
    emit ui->inputEntry->editingFinished();
}

void MainWindow::updateEntry(std::optional<QString> entry){
    if (entry.has_value()){
        if (*entry == "clear"){
            if (entryList.size() > 0){
                entryList.pop_back();
                ui->inputEntry->setText(asString(entryList));
            }
            else{
                ui->inputEntry->clear();
                ui->userInputEntry->clear();
            }
        }
        else{
            bool goodInput{true};
            //check if the user pressed a mathematical operator button
            //if false:
            //it just keeps on updating the entry with the user input
            //else:
            //it calls parseParameter....which tries to solve the input and update the answer
            auto present = std::find_if(std::cbegin(operators), std::cend(operators), [entry](QString const& elem){
                                                       return *entry == elem;});
            if (present == std::cend(operators)){
                entryList.push_back(*entry);
                ui->inputEntry->setText(asString(entryList));
            }
            else{
                operation.push_back(*present);
                goodInput = parseParameter(asString(entryList));
                if (goodInput)
                    inputList.push_back(asString(entryList)+ *entry);
            }
        }
    }
    else{//reset button clicked
        inputList.clear();
        entryList.clear();
        ui->userInputEntry->setText(asString(inputList));
        ui->inputEntry->setText(asString(entryList));
    }
}

QString MainWindow::asString(std::vector<QString> const& str){
    QString temp{""};
    for (auto const& elem : str) temp += elem;
    return temp;
}

void MainWindow::displayAnswerClicked(){
    parameters.clear();
    operation.clear();
}

bool MainWindow::parseParameter(QString const &entry){
    //checks to see if the user input can be converted to a floating point number...to enable solving
    //if false:
    //if parses it to see  if its because of a trigonometric parameter in the input
    //if thats not the case also...then it throws an exception.
    //return a boolean value to indicate correct or incorrect input
    //setAnswer() sets the currentAnswer parameter to the value of value;
    bool ok{false};
    float value{0.0};
    value = entry.toFloat(&ok);
    if (ok){
        parameters.push_back(value);
        setAnswer(value);
    }
    else{
        value = parseTrigOrLogInput(entry, ok);
        setAnswer(value);
    }
    if (!ok) ui->inputEntry->clear();
    return ok;
}

float MainWindow::parseTrigOrLogInput(QString const& entry, bool& ok){
    auto patternPosition = std::find_if(std::begin(expectedPatterns), std::end(expectedPatterns),
                                        [&entry](std::string& pattern){
            return std::regex_match(entry.toStdString(), std::regex{pattern});});
    if (patternPosition != std::end(expectedPatterns)){
        //.....
        ok = true;
    }
    else{
        ok = false;
        messageBox.setText("parser error: can't parse input");
        messageBox.setWindowTitle("ERROR");
        messageBox.exec();
    }
    return 0;
}

void MainWindow::setAnswer(float &value){
    parameters.push_back(value);
    ++inputCounter;
    if (inputCounter==1){
        currentAnswer = QString::number(parameters[0]);
    }
    else if (inputCounter==2){
        currentAnswer = QString::number(solve(parameters[0], parameters[1], operation[0]));
    }
    else if (inputCounter==3){
        currentAnswer = QString::number(solve(parameters[0], parameters[1], parameters[2], operation[0], operation[1]));
        parameters.pop_front();
        operation.pop_front();
        parameters[0] = currentAnswer.toFloat();
    }
    ui->answerLabel->setText(currentAnswer);
}

//ultimate recursion....feeling like a god now
float MainWindow::solve(float const& a, float const& b, QString& op1){
    if (op1 == "+") return a + b;
    else if (op1 == "-") return a - b;
    else if (op1 == "*") return a * b;
    else return a / b;
}
float MainWindow::solve(float const& a, float const& b, float const& c, QString& op1, QString& op2){
    if ((op1 == "*" || op1 == "/") && (op1 == "+" || op2 == "-"))
        return solve(a, solve(b, c, op1), op2);
    else
        return solve(solve(a, b, op1), c,op2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
