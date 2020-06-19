#include <QApplication>

#include "scurve/statisticcurve.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StatisticCurve curve("curve test", true);

    QVector<QString> cs;

    cs.push_back(QString("curve1"));
    cs.push_back(QString("curve2"));
    cs.push_back(QString("curve3"));
    cs.push_back(QString("curve4"));

    curve.setAxisTitle("time elaspe", "MBytes");
    curve.setCurvesNum(cs);
    curve.setAxisType(SscaleDraw::TIME);

    QVector<QPolygonF> data;
    data.resize(cs.size());

    for(int i = 0; i < cs.size(); ++i)
    {
        data[i] << QPointF( 0.0, 4.4 + i) << QPointF( 1.0, 3.0 + i)
                << QPointF( 2.0, 4.5 + i) << QPointF( 3.0, 6.8 + i)
                << QPointF( 4.0, 7.9 + i) << QPointF( 5.0, 7.1 + i);
    }

    curve.addData(data);

    data.clear();
    data.resize(cs.size());

    for(int i = 0; i < cs.size(); ++i)
    {
        data[i] << QPointF( 6.0, 4.4 + i) << QPointF( 7.0, 3.0 + i)
                << QPointF( 8.0, 4.5 + i) << QPointF( 9.0, 6.8 + i)
                << QPointF( 10.0, 7.9 + i) << QPointF( 11.0, 7.1 + i);
    }
    curve.addData(data);

    curve.resize(600, 400);
    curve.show();

    return a.exec();
}
