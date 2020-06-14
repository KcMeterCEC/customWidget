#ifndef SMARKER_H
#define SMARKER_H

#include <qwt_plot_item.h>

class Smarker : public QwtPlotItem
{
public:
    Smarker();

    virtual int rtti() const;

    virtual void draw( QPainter *painter, const QwtScaleMap &xMap,
                       const QwtScaleMap &yMap, const QRectF & canvasRect) const;
    void redraw(qreal x);
private:
    qreal curveX = 0;

    void drawCenterLine(QPainter *painter, const QRectF & canvasRect) const;
};

#endif // SMARKER_H
