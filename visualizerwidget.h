#ifndef VISUALIZERWIDGET_H
#define VISUALIZERWIDGET_H

#include <QWidget>
#include <QLabel>

class VisualizerWidget : public QLabel
{
    Q_OBJECT
public:
    explicit VisualizerWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    /* Drawing */
    void drawGrids(QPainter &p, int marks);

private:
    /* Pens */
    void setPenColorWidthStyle(QPainter& p, Qt::GlobalColor, double width, Qt::PenStyle = Qt::SolidLine);

    void setPenBlack(QPainter &p);
    void setPenRed(QPainter &p);

signals:

};

#endif // VISUALIZERWIDGET_H
