QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    employment_contract/degressivetaxfreeamount.cpp \
    employment_contract/yearwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    employment_contract/datamodel.cpp \
    employment_contract/month.cpp \
    third_party/qcustomplot.cpp

HEADERS += \
    employment_contract/degressivetaxfreeamount.hpp \
    employment_contract/itaxfreeamount.hpp \
    employment_contract/yearwidget.hpp \
    mainwindow.hpp \
    employment_contract/datamodel.hpp \
    employment_contract/month.hpp \
    third_party/qcustomplot.h

FORMS += \
    employment_contract/degressivetaxfreeamount.ui \
    employment_contract/yearwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
