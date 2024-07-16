#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    circleWidget = new CircleWidget(this);
    scrollBar = new QScrollBar(Qt::Horizontal, this);
    scrollBar->setRange(10, 200); 
    scrollBar->setValue(50); 
    scrollBar->setFixedHeight(80); 
    scrollBar->setFixedWidth(400);
    scrollBar->setStyleSheet(
        "QScrollBar:horizontal {"
        "    background: green;"  
        "    height: 30px;"
        "}"
        "QScrollBar::handle:horizontal {"
        "    background: blue;"  
        "    min-width: 20px;"
        "}"
        "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
        "    background: #f0f0f0;"  
        "    width: 0px;"
        "}"
        );

    connect(scrollBar, &QScrollBar::valueChanged, this, &MainWindow::onScrollBarValueChanged);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(scrollBar);
    layout->addWidget(circleWidget);
    layout->addWidget(scrollBar);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onScrollBarValueChanged(int value)
{
    circleWidget->setRadius(value);
}
