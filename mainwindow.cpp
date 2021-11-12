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
    QObject::connect(ui->factorialButton, &QPushButton::clicked, this, &MainWindow::factorialButtonClicked);
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
    if (entryList.size() > 0)
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
}
void MainWindow::squareButtonClicked(){
    updateEntry("^2");
}
void MainWindow::rootButtonClicked(){
    updateEntry("√");
}
void MainWindow::factorialButtonClicked(){
    updateEntry("!");
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
            if (entryList.size() > 0){
                entryList.pop_back();
                ui->inputEntry->setText(asString(entryList));
            }
            else{
                clearEntries();
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
                //if statememts are meant to prevent the user from clicking the math operators multiple times at once
                //also to prevent appending = sign in the operators list
                if (inputList.empty() || std::none_of(std::begin(operators), std::end(operators), [this](QString& op){return op == inputList.back();})){
                    if (*present != "="){
                        operation.push_back(*present);
                    }
                    goodInput = parseParameter(asString(entryList));
                    if (goodInput)
                        inputList.push_back(asString(entryList)+ *entry);
                }
            }
        }
    }
    else{//reset button clicked
        clearEntries();
    }
}

void MainWindow::clearEntries(){
    inputList.clear();
    ui->inputEntry->clear();
    ui->userInputEntry->clear();
    ui->inputEntry->setText(asString(entryList));
    parameters.clear();
    operation.clear();
    ui->answerLabel->setText("0");
    inputCounter = 0;
    currentAnswer = "0";
}

QString MainWindow::asString(std::vector<QString> const& str){
    QString temp{""};
    for (auto const& elem : str) temp += elem;
    return temp;
}

void MainWindow::displayAnswerClicked(){//clear the vectors holding values of the just completed operation
    if (parameters.size() > 0 && operation.size() > 0){
        parameters.clear();
        operation.clear();
        inputList.clear();
    }
}

bool MainWindow::parseParameter(QString const &entry){
    //checks to see if the user input can be converted to a floating point number...to enable solving
    //if false:
    //it checks to see if its a factorial operation instead
    //if false
    //it checks to see if, perhaps, the user entered a value containing PI
    //if also false
    //it check for an entry with √
    //if that's false again
    //if parses it to see if its a trigonometric parameter in the input
    //if thats not the case also...then it throws an exception.
    //return a boolean value to indicate correct or incorrect input
    //setAnswer() sets the currentAnswer parameter to the value of value;
    bool ok{false};
    float value{0.0};
    value = entry.toFloat(&ok);
    if (ok){
        setAnswer(value);
    }

    //factorial function
    else if (auto str = entry.toStdString(); str.find("!") != std::wstring::npos){
        auto r = std::regex{R"((\d+)(!))"};
        auto match = std::smatch{};
        if (std::regex_match(str, match, r)){
            if (auto s = match[1].str(); s.empty())
                showErrorMessage("Syntax Error");
            else{
                try{
                    std::function<int(int const&)> factorial = [&factorial](int const& n){
                         if (n==0) return 1;
                         if (n == 1 || n == 2) return n;
                         else return n * factorial(n - 1);
                    };
                    value = factorial(std::stoi(s));
                    setAnswer(value);
                    ok = true;
                }
                catch (std::invalid_argument const&){
                    showErrorMessage("Syntax Error");
                }
                catch (std::exception const&){
                    showErrorMessage("Math Error");
                }
            }
        }
        else{
            showErrorMessage("Syntax Error");
        }
    }

    //pi function
    else if (auto wstr = entry.toStdWString(); wstr.find(L"π") != std::wstring::npos){
        auto r = std::wregex{ L"(\\d*\\.?\\d*)(π)" };
        auto match = std::wsmatch{};
        if (std::regex_match(wstr, match, r)) {
            if (auto s = match[1].str(); s.empty()){
                value = M_PI;
                setAnswer(value);
                ok = true;
            }
            else{
                try{
                    value = std::stof(s) * M_PI;
                    setAnswer(value);
                    ok = true;
                }
                catch(std::invalid_argument const&){
                    showErrorMessage("Syntax Error");
                }
            }
        }
        else{
            showErrorMessage("Syntax Error");
        }
    }

    //root function
    else if (auto wstr = entry.toStdWString(); wstr.find(L"√") != std::wstring::npos){
        auto r = std::wregex{ L"(\\d*\\.?\\d*)(√)(\\d+\\.?\\d*)" };
        auto match = std::wsmatch{};
        if (std::regex_match(wstr, match, r)) {
            try{
                auto s1{0.0}, s2{0.0};
                if (match[1].str().empty())
                    s1 = 2;
                else
                    s1 = std::stof(match[1].str());
                s2 = std::stof(match[3].str());
                value = std::pow(s2, (1/s1));
                setAnswer(value);
                ok = true;
            }
            catch (std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else{
            showErrorMessage("Syntax Error");
        }
    }

    //trig function
    else{
        value = parseTrigOrLogInput(entry, ok);
        setAnswer(value);
    }
    if (!ok) ui->inputEntry->clear();
    return ok;
}

float MainWindow::parseTrigOrLogInput(QString const& entry, bool& ok){
    std::smatch match;
    auto str = entry.toStdString();
    auto patternPosition = std::find_if(std::begin(expectedPatterns), std::end(expectedPatterns),
                                        [&match, &str](std::string& pattern){
            return std::regex_match(str, match, std::regex{pattern});});
    if (patternPosition != std::end(expectedPatterns)){
        if (match[2].str() == "sin"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return s1 * std::sin(s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
        else if (match[2].str() == "cos"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return s1 * std::cos(s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
        else if (match[2].str() == "tan"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return s1 * std::tan(s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
        else if (match[2].str() == "sin-1"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return s1 * std::asin(s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
        else if (match[2].str() == "cos-1"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return s1 * std::acos(s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
        else if (match[2].str() == "tan-1"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return s1 * std::atan(s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
        else if (match[2].str() == "log"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return s1 * std::log10(s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else if (match[2].str() == "ln"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return s1 * std::log(s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else if (match[2].str() == "^"){
            try{
                auto [s1, s2] = std::pair(std::stof(match[1].str()), std::stof(match[3].str()));
                ok = true;
                return std::pow(s1, s2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else if (match[2].str() == "^2"){
            try{
                auto s1 = std::stof(match[1].str());
                ok = true;
                return s1 * std::pow(s1, 2);
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else if (match[2].str() == "OR"){
            try{
                auto [s1, s2] = std::pair(std::stoi(match[1].str()), std::stoi(match[3].str()));
                ok = true;
                return s1 | s2;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else if (match[2].str() == "AND"){
            try{
                auto [s1, s2] = std::pair(std::stoi(match[1].str()), std::stoi(match[3].str()));
                ok = true;
                return s1 & s2;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else if (match[2].str() == "XOR"){
            try{
                auto [s1, s2] = std::pair(std::stoi(match[1].str()), std::stoi(match[3].str()));
                ok = true;
                return s1 ^ s2;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else if (match[2].str() == "<<"){
            try{
                auto [s1, s2] = std::pair(std::stoi(match[1].str()), std::stoi(match[3].str()));
                ok = true;
                return s1 << s2;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
        else if (match[2].str() == ">>"){
            try{
                auto [s1, s2] = std::pair(std::stoi(match[1].str()), std::stoi(match[3].str()));
                ok = true;
                return s1 >> s2;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax Error");
            }
        }
    }
    else{
        showErrorMessage("Syntax Error");
    }
    return 0;
}

void MainWindow::setAnswer(float const& value){
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
        //update the state of the parameters using BODMAS
        //parameters and operation cannot have a size greater than 3
        //if the operator precedence is ascending:
        //it solves from right to left, the index parameter[1] is updated with (parameter[1] op paremater[2])
        //then the index parameter[2] is deleted
        //operation[1] is also deleted....as it contains the used up operator between (parameter[1] op parameter[2])
        //else
        //it solves from left to right
        //index parameter[1] is updated with (parameter[0] op parameter[1])
        //then index parameter[0] is deleted
        //operation[0] is also delete....as it contains the used up operator between (parameter[0] op parameter[1])
        if ((operation[0] == "+" || operation[0] == "-") && (operation[1] == "*" || operation[1] == "/")){
            if (operation[1] == "*")
                parameters[1] = parameters[1] * parameters[2];
            else if (operation[1] == "/")
                parameters[1] = parameters[1] / float(parameters[2]);
            operation.erase(std::begin(operation) + 1);
            parameters.erase(std::begin(parameters) + 2);
        }
        else{
            if (operation[0] == "+") parameters[1] = parameters[0] + parameters[1];
            else if (operation[0] == "-") parameters[1] = parameters[0] - parameters[1];
            else if (operation[0] == "*") parameters[1] = parameters[0] * parameters[1];
            else parameters[1] = parameters[0] / float(parameters[1]);
            parameters.pop_front();
            operation.pop_front();
        }
        --inputCounter;
    }
    ui->answerLabel->setText(currentAnswer);
}

float MainWindow::solve(float const& a, float const& b, QString& op1){
    if (op1 == "+") return a + b;
    else if (op1 == "-") return a - b;
    else if (op1 == "*") return a * b;
    else return a / float(b);
}

float MainWindow::solve(float const& a, float const& b, float const& c, QString& op1, QString& op2){
    if ((op1 == "+" || op1 == "-") && (op2 == "*" || op2 == "/"))
        return solve(a, solve(b, c, op2), op1);
    else
        return solve(solve(a, b, op1), c,op2);
}

void MainWindow::showErrorMessage(QString const& errorMessage){
    messageBox.setText("Error: " + errorMessage);
    messageBox.setWindowTitle("Error Message");
    messageBox.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
