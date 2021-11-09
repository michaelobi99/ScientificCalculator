#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <optional>
#include <QRegularExpression>
#include <QValidator>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void connectButtonSignals(Ui::MainWindow*);
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
    void squareRootButtonClicked();
    void complexNumberButtonClicked();
    void bitORButtonClicked();
    void bitANDButtonClicked();
    void bitXORButtonClicked();
    void leftShiftButtonClicked();
    void rightShiftButtonClicked();
    void displayAnswerClicked();
    void mathOperatorButtonClicked();
    //void keyBoardClicked();

signals:
    void displayAnswer();

private:
    Ui::MainWindow *ui;
    QString inputList;//contains all the user input
    QString entryList;//contains the user present input
    QString currentAnswer{"0"};
    QString tempAnswer{"0"};
    QString currentInput{"0"};
    QString latterInput{"0"};
    QString previousInput{"0"};
    QString currentOperation{""};
    QString previousOperation{""};
    std::vector<QString> operators{"+", "-", "/", "*"};
    unsigned inputCounter{0};
    void updateEntry(std::optional<QString>);
    void inputValidator();
};
#endif // MAINWINDOW_H
