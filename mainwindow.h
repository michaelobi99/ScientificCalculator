#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QValidator>
#include <QMessageBox>
#include <vector>
#include <deque>
#include <optional>
#include <algorithm>
#include <cmath>
#include <functional>
#include <regex>
#include "numbersystem.h"
#include "number.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void connectButtonSignals(Ui::MainWindow*);
    //void setButtonClickedColor(Ui::MainWindow*);
    ~MainWindow();

public slots:
    void zeroButtonClicked();
    void oneButtonClicked();
    void twoButtonClicked();
    void threeButtonClicked();
    void fourButtonClicked();
    void fiveButtonClicked();
    void sixButtonClicked();
    void sevenButtonClicked();
    void eightButtonClicked();
    void nineButtonClicked();
    void plusButtonClicked();
    void minusButtonClicked();
    void timesButtonClicked();
    void divideButtonClicked();
    void equalToButtonClicked();
    void piButtonClicked();
    void radixPointButtonClicked();
    void answerButtonClicked();
    void deleteButtonClicked();
    void resetButtonClicked();
    void openBracesButtonClicked();
    void closeBracesButtonClicked();
    void sinButtonClicked();
    void cosButtonClicked();
    void tanButtonClicked();
    void logButtonClicked();
    void naturalLogButtonClicked();
    void inverseSinButtonClicked();
    void inverseCosButtonClicked();
    void inverseTanButtonClicked();
    void exponentButtonClicked();
    void squareButtonClicked();
    void rootButtonClicked();
    void factorialButtonClicked();
    void complexNumberButtonClicked();
    void bitORButtonClicked();
    void bitANDButtonClicked();
    void bitXORButtonClicked();
    void leftShiftButtonClicked();
    void rightShiftButtonClicked();
    void displayAnswerClicked();
    void mathOperatorButtonClicked();

signals:
    void displayAnswer();

private:
    //private variables
    stl::NumberSystem numberSystem;
    Ui::MainWindow *ui;
    std::vector<QString> inputList;//contains all the user input
    std::vector<QString> entryList;//contains the user present input
    QString currentAnswer{"0"};
    QMessageBox messageBox;
    std::deque<QString> operation;//deque to hold the current and previous mathematical operations
    std::deque<Number> parameters;//container to hold the last three inputs(if available) so that BODMAS can be applied
    unsigned inputCounter{0};
    //operators that triggers the updating of both full expression entry and final answer
    std::vector<QString> operators{"+", "-", "/", "*", "="};
    std::vector<std::string> expectedPatterns{//patterns to expect if the input is trig or logarithm.
        //(\d\.?\d*)->first capture group i.e the number just before the trig or log word
        //(sin or cos or log or ...)-> second capture group
        //(\d+\.?\d*)-> the third capture group i.e the angle or number
        R"((\d*\.?\d*)\(*(sin)\((\d+\.?\d*)\)\)*)",
        R"((\d*\.?\d*)\(*(cos)\((\d+\.?\d*)\)\)*)",
        R"((\d*\.?\d*)\(*(tan)\((\d+\.?\d*)\)\)*)",
        R"((\d*\.?\d*)\(*(sin-1)\((\d+\.?\d*)\)\)*)",
        R"((\d*\.?\d*)\(*(cos-1)\((\d+\.?\d*)\)\)*)",
        R"((\d*\.?\d*)\(*(tan-1)\((\d+\.?\d*)\)\)*)",
        R"((\d*\.?\d*)\(*(log)\((\d+\.?\d*)\)\)*)",
        R"((\d*\.?\d*)\(*(ln)\((\d+\.?\d*)\)\)*)",
        R"((\d*\.?\d*)(\^)(\d+\.?\d*))",
        R"((\d*\.?\d*)(\^)(2))",
        R"((\d+)(XOR)(\d+))",
        R"((\d+)(OR)(\d+))",
        R"((\d+)(AND)(\d+))",
        R"((\d+)(<<)(\d+))",
        R"((\d+)(>>)(\d+))"
    };

    //private functons
    void updateEntry(std::optional<QString>);
    QString asString(std::vector<QString> const&);
    bool parseParameter(QString const& entry);
    Number parseTrigOrLogInput(QString const& entry, bool&);
    void setAnswer(Number const&);
    Number solve(Number, Number, QString&);
    Number solve(Number, Number, Number, QString&, QString&);
    void clearEntries();
    void showErrorMessage(QString const&);
    void inputValidator();
};
#endif // MAINWINDOW_H
