#include <QGridLayout>
#include <QMap>
#include <QPolygonF>
#include <QPoint>
#include <QDebug>
#include "statisticcurve.h"
#include "splot.h"
#include "splotcurve.h"
#include "smarker.h"

StatisticCurve::StatisticCurve(const QString &title, QWidget *parent) :
    QWidget(parent),
    plot(new Splot(title, this)),
    marker (new Smarker())
{
    marker->attach(plot);

    connect(plot, &Splot::mouseMoved, this, &StatisticCurve::mouseMovedInCanvas);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(plot, 0, 0);

    setLayout(layout);
}
void StatisticCurve::setCurvesNum(const QVector<QPair<QString, QColor>> &cs)
{
    deleteCurves();
    for(int i = 0; i < cs.size(); ++i)
    {
        SplotCurve *curve = new SplotCurve(cs[i].first);
        curve->setPen(cs[i].second);
        curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);

        curves.push_back(curve);
        curve->attach(plot);
    }

    curvesData.resize(cs.size());
}
void StatisticCurve::addData(const QVector<QPolygonF> &data)
{
    if(!curves.size())
    {
        return;
    }
    for(int i = 0; i < data.size(); ++i)
    {
        for(int j = 0; j < data[i].size(); ++j)
        {
            curvesData[i].push_back(data[i].at(j));
        }
        curves[i]->setSamples(curvesData[i]);
    }
}
void StatisticCurve::clearCurvesData(void)
{
    if(curvesData.size())
    {
        curvesData.clear();
    }
}
void StatisticCurve::deleteCurves(void)
{
    clearCurvesData();
    if(curves.size())
    {
        for(int i = 0; i < curves.size(); ++i)
        {
            curves[i]->detach();
        }
        curves.clear();
    }
}
void StatisticCurve::mouseMovedInCanvas(const QPointF & p)
{
    if(!curvesData.size() || !curvesData[0].size())
    {
        return;
    }
    qreal currentX = p.x();
    QPolygonF &curveData = curvesData[0];
    mouseIdx = curveData.size() - 1;
    for(int i = 0; i < curveData.size() - 1; ++i)
    {
        if(curveData[i + 1].rx() > currentX)
        {
            mouseIdx = i;

            if((curveData[i + 1].rx() - currentX) <
                    (currentX - curveData[i].rx()))
            {
                mouseIdx += 1;
            }
            break;
        }
    }

    qreal drawX = plot->canvasMap(Splot::xBottom).transform(curveData[mouseIdx].rx());
    marker->redraw(drawX);

    qDebug() << "mouse move : " << p << " -> " << curveData[mouseIdx].rx()
             << "map from >> " << plot->canvasMap(Splot::xBottom).transform(curveData[mouseIdx].rx())
             ;


}
