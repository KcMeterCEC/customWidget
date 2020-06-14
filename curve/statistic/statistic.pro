QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

win32
{
    QWT_ROOT = C:/Qwt-6.1.4
}

unix
{

}

include ($${QWT_ROOT}/features/qwt.prf)

SOURCES += \
    main.cpp \
    scurve/slegend.cpp \
    scurve/smarker.cpp \
    scurve/splot.cpp \
    scurve/splotcurve.cpp \
    scurve/splotgrid.cpp \
    scurve/ssymbol.cpp \
    scurve/statisticcurve.cpp

HEADERS += \
    scurve/slegend.h \
    scurve/smarker.h \
    scurve/splot.h \
    scurve/splotcurve.h \
    scurve/splotgrid.h \
    scurve/ssymbol.h \
    scurve/statisticcurve.h
