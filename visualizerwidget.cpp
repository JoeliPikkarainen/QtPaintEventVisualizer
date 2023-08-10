#include "visualizerwidget.h"
#include <QPainter>

VisualizerWidget::VisualizerWidget(QWidget *parent) : QLabel(parent)
{
    QString style_sheet = "border-width: 2px; border-style: solid; border-color: black;";
    setStyleSheet(style_sheet);
}

void VisualizerWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);

    QTransform tf = p.transform();
    QPoint origin1 = tf.map(QPoint(0,0));

    setPenBlack(p);
    drawGrids(p,10);

    p.translate(rect().center());
    tf = p.transform();
    QPoint origin2 = tf.inverted().map(QPoint(0,0));

    setPenRed(p);
    p.drawPoint(0,0);

    p.drawLine(origin1,origin2);

}

void VisualizerWidget::drawGrids(QPainter &p, int marks)
{
    double xpart = width() / marks;
    double yend = rect().bottomLeft().y();
    for (int x = 0; x < marks; x++) {
        p.drawLine(QPoint(xpart*x,0),QPoint(xpart*x,yend));
    }

    double ypart = height() / marks;
    double xend = rect().topRight().x();
    for (int y = 0; y < marks; y++) {
        /* Draw from top to bottom */
        /* Left to right */
        p.drawLine(QPoint(0,ypart*y),QPoint(xend,ypart*y));
    }
}

void VisualizerWidget::setPenColorWidthStyle(QPainter &p, Qt::GlobalColor color, double width, Qt::PenStyle style)
{
    QPen pen;
    pen.setColor(color);
    pen.setWidthF(width);
    pen.setStyle(style);

    p.setPen(pen);
}

void VisualizerWidget::setPenBlack(QPainter &p)
{
    setPenColorWidthStyle(p,Qt::black,1);
}

void VisualizerWidget::setPenRed(QPainter &p)
{
    setPenColorWidthStyle(p,Qt::red,1);
}
