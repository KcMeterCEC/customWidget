#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include "splot.h"

Splot::Splot(const QwtText &title, QWidget *parent):
    QwtPlot(title, parent)
{
    mousePicker = new QwtPlotPicker(this->xBottom, this->yLeft,
                                    QwtPlotPicker::NoRubberBand,
                                    QwtPicker::AlwaysOff,
                                    this->canvas());
    mousePicker->setStateMachine(new QwtPickerTrackerMachine());

    connect(mousePicker, &QwtPlotPicker::moved, this, &Splot::mouseMoved);
}
