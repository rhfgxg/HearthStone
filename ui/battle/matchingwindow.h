#ifndef MATCHINGWINDOW_H
#define MATCHINGWINDOW_H

#include <QWidget>

// 匹配等待界面

namespace Ui {
class MatchingWindow;
}

class MatchingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MatchingWindow(QWidget *parent = nullptr);
    ~MatchingWindow();

private slots:
    void on_pushButton_exit_clicked();

private:
    Ui::MatchingWindow *ui;
};

#endif // MATCHINGWINDOW_H
