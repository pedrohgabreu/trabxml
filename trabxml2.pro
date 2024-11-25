QT += core gui widgets xml

CONFIG += c++17

SOURCES += \
    XmlProcessor.cpp \
    XmlValidator.cpp \
    dashboard.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    XmlProcessor.h \
    XmlValidator.h \
    dashboard.h \
    mainwindow.h

FORMS += \
    dashboard.ui \
    mainwindow.ui


DISTFILES += \
    exemplo.xml \
    exemplo.xsd

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /usr/include/libxml2
LIBS += -lxml2
