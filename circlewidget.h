#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H
#include <QWidget>
class CircleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CircleWidget(QWidget *parent = nullptr);
    void setRadius(int radius);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int m_radius;
};
#endif // CIRCLEWIDGET_H
