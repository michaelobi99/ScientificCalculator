#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inputValidator();
    connectButtonSignals(ui);
    //setButtonClickedColor(ui);
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

//void MainWindow::setButtonClickedColor(Ui::MainWindow*){
//    ui->zeroButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->oneButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->twoButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->threeButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->fourButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->fiveButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->sixButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->sevenButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->eightButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->nineButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->plusButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->minusButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->timesButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->divideButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->equalToButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->piButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->radixPointButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->answerButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->deleteButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->resetButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->openBracesButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->closeBracesButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->sineButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->cosineButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->tangentButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->logButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->naturalLogButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->inverseSinButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->inverseCosButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->inverseTanButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->exponentButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->squareButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->rootButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->factorialButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->complexNumberButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->bitORButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->bitANDButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->bitXORButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->leftShiftButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//    ui->rightShiftButton->setStyleSheet("QPushButton:pressed{background-color: gray}");
//}

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
                if (!entryList.empty()){//ignore an empty entry
                    //to prevent appending = sign in the operators list
                    if (*present != "="){
                        operation.push_back(*present);
                    }
                    goodInput = parseParameter(asString(entryList));
                    if (goodInput){
                        inputList.push_back(asString(entryList));
                        inputList.push_back(*entry);
                    }
                    else
                        clearEntries();
                }
            }
        }
    }
    else{//reset button clicked
        if (entryList.size() > 0){
            entryList.clear();
            ui->inputEntry->setText(asString(entryList));
        }
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
    ui->hexResult->setText("0");
    ui->decResult->setText("0");
    ui->octResult->setText("0");
    ui->binResult->setText("0");
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
    Number value;
    if (entry.toFloat(&ok); ok){
        value = entry.toStdString();
        setAnswer(value);
    }

    //factorial function
    else if (auto str = entry.toStdString(); str.find("!") != std::string::npos){
        auto r = std::regex{R"((\d+)(!))"};
        auto match = std::smatch{};
        if (std::regex_match(str, match, r)){
            if (auto s = match[1].str(); s.empty())
                showErrorMessage("Syntax Error");
            else{
                try{
                    Number number{s};
                    value = !number;
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
        std::string pi = "3.141592654";
        if (std::regex_match(wstr, match, r)) {
            if (auto s = match[1].str(); s.empty()){
                value = Number{pi};
                setAnswer(value);
            }
            else{
                std::string num = std::to_string(std::stof(s));
                value = Number{num} * Number{pi};
                setAnswer(value);
            }
            ok = true;
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
                value = std::to_string(std::pow(s2, (1/s1)));
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
    //clear the entry if parsing the input failed
    if (!ok){
        ui->inputEntry->clear();
    }
    return ok;
}


Number MainWindow::parseTrigOrLogInput(QString const& entry, bool& ok){
    std::smatch match;
    auto str = entry.toStdString();
    unsigned counter{0};
    auto patternPosition = std::find_if(std::begin(expectedPatterns), std::end(expectedPatterns),
                                        [&match, &str, &counter](std::string& pattern){
        ++counter;
        return std::regex_match(str, match, std::regex{pattern});
    });

    if (patternPosition != std::end(expectedPatterns)){
        std::optional<Number> s1;
        float s2{0.0};
        switch (counter){
        case 1:{
            try{
                if (match[1].str().empty())
                    s1 = std::nullopt;
                else
                    s1 = Number(match[1].str());
                s2 = std::stof(match[3].str());
                ok = true;
                return s1.value_or(Number("1")) * Number(QString::number(std::sin([&s2](){return ((s2 * M_PI)/float(180));}())).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 2:{
            try{
                if (match[1].str().empty())
                    s1 = std::nullopt;
                else
                    s1 = Number(match[1].str());
                s2 = std::stof(match[3].str());
                ok = true;
                return s1.value_or(Number("1")) * Number(QString::number(std::cos([&s2](){return ((s2 * M_PI)/float(180));}())).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 3:{
            try{
                if (match[1].str().empty())
                    s1 = std::nullopt;
                else
                    s1 = Number(match[1].str());
                s2 = std::stof(match[3].str());
                ok = true;
                return s1.value_or(Number("1")) * Number(QString::number(std::tan([&s2](){return ((s2 * M_PI)/float(180));}())).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 4:{
            try{
                if (match[1].str().empty())
                    s1 = std::nullopt;
                else
                    s1 = Number(match[1].str());
                s2 = std::stof(match[3].str());
                ok = true;
                return s1.value_or(Number("1")) * Number(QString::number([&s2](){ return (std::asin(s2) * 180) / M_PI;}()).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 5:{
            try{
                if (match[1].str().empty())
                    s1 = std::nullopt;
                else
                    s1 = Number(match[1].str());
                s2 = std::stof(match[3].str());
                ok = true;
                return s1.value_or(Number("1")) * Number(QString::number([&s2](){ return (std::acos(s2) * 180) / M_PI;}()).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 6:{
            try{
                if (match[1].str().empty())
                    s1 = std::nullopt;
                else
                    s1 = Number(match[1].str());
                s2 = std::stof(match[3].str());
                ok = true;
                return s1.value_or(Number("1")) * Number(QString::number([&s2](){ return (std::tan(s2) * 180) / M_PI;}()).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 7:{
            try{
                if (match[1].str().empty())
                    s1 = std::nullopt;
                else
                    s1 = Number(match[1].str());
                s2 = std::stof(match[3].str());
                ok = true;
                return s1.value_or(Number("1")) * Number(QString::number(std::log10(s2)).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 8:{
            try{
                if (match[1].str().empty())
                    s1 = std::nullopt;
                else
                    s1 = Number(match[1].str());
                s2 = std::stof(match[3].str());
                ok = true;
                return s1.value_or(Number("1")) * Number(QString::number(std::log(s2)).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 9:{
            try{
                ok = true;
                return Number(QString::number(std::pow(std::stof(match[1].str()), std::stof(match[3].str()))).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 10:{
            try{
                ok = true;
                return Number(QString::number(std::pow(std::stof(match[1].str()), std::stof(match[3].str()))).toStdString());
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 11:{
            try{
                s1 = match[1].str();
                Number s2 = QString::number(std::stoull(match[3].str())).toStdString();
                ok = true;
                Number result = s1.value() ^ s2;
                return result;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 12:{
            try{
                s1 = match[1].str();
                Number s2 = QString::number(std::stoull(match[3].str())).toStdString();
                ok = true;
                Number result = s1.value() | s2;
                return result;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 13:{
            try{
                s1 = match[1].str();
                Number s2 = QString::number(std::stoull(match[3].str())).toStdString();
                ok = true;
                Number result = s1.value() & s2;
                return result;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 14:{
            try{
                s1 = match[1].str();
                Number s2 = QString::number(std::stoull(match[3].str())).toStdString();
                ok = true;
                Number result = s1.value() << s2;
                return result;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
        }
            break;
        case 15:{
            try{
                s1 = match[1].str();
                Number s2 = QString::number(std::stoull(match[3].str())).toStdString();
                ok = true;
                Number result = s1.value() >> s2;
                return result;
            }
            catch(std::invalid_argument const&){
                showErrorMessage("Syntax ERROR");
            }
            catch(std::exception const&){
                showErrorMessage("Math ERROR");
            }
            break;
        }
        }
    }
    showErrorMessage("Syntax Error");
    return "0";
}

void MainWindow::setAnswer(Number const& value){
    parameters.push_back(value);
    ++inputCounter;
    if (inputCounter==1){
        currentAnswer = QString::fromStdString(parameters[0].GetValue());
    }
    else if (inputCounter==2){
        currentAnswer = QString::fromStdString(solve(parameters[0], parameters[1], operation[0]).GetValue());
    }
    else if (inputCounter==3){
        currentAnswer = QString::fromStdString(solve(parameters[0], parameters[1], parameters[2], operation[0], operation[1]).GetValue());
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
                parameters[1] = parameters[1] / parameters[2];
            operation.erase(std::begin(operation) + 1);
            parameters.erase(std::begin(parameters) + 2);
        }
        else{
            if (operation[0] == "+") parameters[1] = parameters[0] + parameters[1];
            else if (operation[0] == "-") parameters[1] = parameters[0] - parameters[1];
            else if (operation[0] == "*") parameters[1] = parameters[0] * parameters[1];
            else parameters[1] = parameters[0] / parameters[1];
            parameters.pop_front();
            operation.pop_front();
        }
        --inputCounter;
    }
    std::string result{currentAnswer.toStdString()};
    if (result.size() > 45){
        size_t s = result.size();
        result = result.substr(0, 30);
        result.insert(1, ".");
        result += "e+" + std::to_string(s-1);
        currentAnswer = QString::fromStdString(result);
    }
    ui->answerLabel->setText(currentAnswer);
    numberSystem.setValue(currentAnswer.toStdString());
    ui->decResult->setText(currentAnswer);
    ui->hexResult->setText(QString::fromStdString(numberSystem.hexNotation()));
    ui->octResult->setText(QString::fromStdString(numberSystem.octalNotation()));
    ui->binResult->setText(QString::fromStdString(numberSystem.binaryNotation()));
}

Number MainWindow::solve(Number a, Number b, QString& op1){
    if (op1 == "+") return a + b;
    else if (op1 == "-") return a - b;
    else if (op1 == "*") return a * b;
    else return a / b;
}

Number MainWindow::solve(Number a, Number b, Number c, QString& op1, QString& op2){
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
