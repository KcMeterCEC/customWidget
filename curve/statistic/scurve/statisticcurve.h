#ifndef STATISTICCURVE_H
#define STATISTICCURVE_H

#include <QWidget>

class Splot;
class SplotCurve;
class Smarker;
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
    void resizeEvent(QResizeEvent *event) override;
private:
    Splot     *plot = nullptr;
    QVector<SplotCurve *> curves;
    QVector<QPolygonF> curvesData;
    Smarker *marker = nullptr;
    int mouseIdx = 0;

    void clearCurvesData(void);
    void deleteCurves(void);
    void refresh(void);
signals:

private slots:
    void mouseMovedInCanvas(const QPointF & p);
    void mouseRemovedOutCanvas(const QPointF & p);
};

#endif // STATISTICCURVE_H
