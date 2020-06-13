#ifndef SPLOT_H
#define SPLOT_H

#include <qwt_plot.h>

class Splot : public QwtPlot
{
    Q_OBJECT
public:
    explicit Splot(const QwtText &title, QWidget *parent = nullptr);
};

#endif // SPLOT_H
