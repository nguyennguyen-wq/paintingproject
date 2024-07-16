#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QScrollBar>
#include "circlewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onScrollBarValueChanged(int value);

private:
    Ui::MainWindow *ui;
    CircleWidget *circleWidget;
    QScrollBar *scrollBar;
};

#endif // MAINWINDOW_H
