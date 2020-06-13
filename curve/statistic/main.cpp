#include <QApplication>

#include "scurve/statisticcurve.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StatisticCurve curve("curve test");

    QVector<QPair<QString, QColor>> cs;

    cs.push_back(QPair<QString, QColor>("curve1", Qt::red));
    cs.push_back(QPair<QString, QColor>("curve2", Qt::yellow));
    cs.push_back(QPair<QString, QColor>("curve3", Qt::blue));
    cs.push_back(QPair<QString, QColor>("curve4", Qt::green));

    curve.setCurvesNum(cs);

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
