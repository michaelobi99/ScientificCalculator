#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QValidator>
#include <QMessageBox>
#include <vector>
#include <deque>
#include <unordered_map>
#include <optional>
#include <algorithm>
#include <cmath>
#include <regex>

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

signals:
    void displayAnswer();

private:
    Ui::MainWindow *ui;
    std::vector<QString> inputList;//contains all the user input
    std::vector<QString> entryList;//contains the user present input
    QString currentAnswer{"0"};
    QMessageBox messageBox;
    std::optional<QString> currentOperation;
    std::optional<QString> previousOperation;
    std::vector<QString> operators{"+", "-", "/", "*", "^", "^2", "XOR", "OR", "AND", "<<", ">>", "√", "="};
    std::unordered_map<QString, unsigned> operatorValueMap{{"+", 0}, {"-", 0}, {"*", 1}, {"/", 1}};
    std::vector<std::string> expectedPatterns{//patterns to expect if the input is trig or logarithm.
        R"(\d*\.?\d*\(*sin\(\d+\.?\d*\)\)*)",
        R"(\d*\.?\d*\(*cos\(\d+\.?\d*\)\)*)",
        R"(\d*\.?\d*\(*tan\(\d+\.?\d*\)\)*)",
        R"(\d*\.?\d*\(*sin-1\(\d+\.?\d*\)\)*)",
        R"(\d*\.?\d*\(*cos-1\(\d+\.?\d*\)\)*)",
        R"(\d*\.?\d*\(*tan-1\(\d+\.?\d*\)\)*)",
        R"(\d*\.?\d*\(*log\(\d+\.?\d*\)\)*)",
        R"(\d*\.?\d*\(*ln\(\d+\.?\d*\)\)*)"
    };
    std::deque<float> parameters;//container to hold the last three inputs(if available) so that BODMAS can be applied
    unsigned inputCounter{0};
    void updateEntry(std::optional<QString>);
    QString asString(std::vector<QString> const&);
    bool parseParameter(QString const& entry);
    float parseTrigOrLogInput(QString const& entry, bool&);
    void setAnswer(float&);
    void inputValidator();
};
#endif // MAINWINDOW_H
