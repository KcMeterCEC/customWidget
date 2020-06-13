#include <QGridLayout>
#include <QMap>
#include <QPolygonF>
#include "statisticcurve.h"
#include "splot.h"
#include "splotcurve.h"

StatisticCurve::StatisticCurve(const QString &title, QWidget *parent) :
    QWidget(parent),
    plot(new Splot(title, this))
{
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
