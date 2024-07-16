#include "circlewidget.h"
#include <QPainter>
CircleWidget::CircleWidget(QWidget *parent)
    : QWidget(parent), m_radius(50) 
{
}

void CircleWidget::setRadius(int radius)
{
    m_radius = radius;
    update(); 
}

void CircleWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::yellow);
    int x = width() / 2;
    int y = height() / 2;
    painter.drawEllipse(QPoint(x, y), m_radius, m_radius);
}
