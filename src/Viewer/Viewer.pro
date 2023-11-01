QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets

CONFIG += \
    c++17 \
    sdk_no_version_check \

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../s21_get_data_viewer.c \
    ../s21_matrix.c \
    main.cpp \
    mainwindow.cpp \
    objectviewer.cpp

HEADERS += \
    ../s21_get_data_viewer.h \
    ../s21_matrix.h \
    mainwindow.h \
    objectviewer.h

FORMS += \
    mainwindow.ui
include (../3rdParty/gifimage/qtgifimage.pri)
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Icons/angle-circle-in.png \
    ../Icons/angle-circle-left.png \
    ../Icons/angle-circle-out.png \
    ../Icons/angle-circle-right.png \
    ../Icons/angle-circle-up.png \
    ../Icons/angle-down.png \
    ../Icons/angle-in.png \
    ../Icons/angle-left.png \
    ../Icons/angle-out.png \
    ../Icons/angle-right.png \
    ../Icons/angle-up.png \
    ../Icons/camera.png \
    ../Icons/search.png \
    ../Icons/video-camera-alt.png \
    ../Icons/zoom-in.png \
    ../Icons/zoom-out.png

RESOURCES += \
    Viewer.qrc
