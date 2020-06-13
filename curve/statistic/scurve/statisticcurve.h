#ifndef STATISTICCURVE_H
#define STATISTICCURVE_H

#include <QWidget>

class Splot;
class SplotCurve;
class StatisticCurve : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticCurve(const QString & title = "statistic curve",QWidget *parent = nullptr);
    //! set the name and color for each curve
    void setCurvesNum(const QVector<QPair<QString, QColor>> &cs);
    //! add data to each curve
    void addData(const QVector<QPolygonF> &data);
protected:

private:
    Splot     *plot = nullptr;
    QVector<SplotCurve *> curves;
    QVector<QPolygonF> curvesData;

    void clearCurvesData(void);
    void deleteCurves(void);
signals:

};

#endif // STATISTICCURVE_H
