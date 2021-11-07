#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <optional>

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
    void differentialButtonClicked();
    void onButtonClicked();
    void displayAnswerClicked();

signals:
    void displayAnswer();

private:
    Ui::MainWindow *ui;
    std::vector<QString> inputList;
    QString currentAnswer{""};

    void updateEntry(std::optional<QString>);
};
#endif // MAINWINDOW_H
