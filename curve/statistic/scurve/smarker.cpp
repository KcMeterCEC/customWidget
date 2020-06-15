#include <QDebug>
#include <qwt_plot.h>
#include "smarker.h"

Smarker::Smarker()
{
    setZ(1000);
}
int Smarker::rtti() const
{
    return QwtPlotItem::Rtti_PlotUserItem;
}
void Smarker::draw(QPainter *painter,
        const QwtScaleMap &xMap, const QwtScaleMap &yMap, const QRectF & canvasRect) const
{
    drawCenterLine(painter, canvasRect);
}
void Smarker::drawCenterLine(QPainter *painter, const QRectF & canvasRect) const
{
    qreal lineX = curveX;
    qreal lineY = canvasRect.y();
    qreal len = canvasRect.height();
    painter->save();
    painter->setPen(Qt::red);
    painter->drawLine(lineX, lineY,
                      lineX, lineY + len);
    painter->restore();
}
void  Smarker::redraw(qreal x)
{
    curveX = x;

}
