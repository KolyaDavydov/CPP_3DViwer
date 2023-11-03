/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <objectviewer.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_open;
    QLabel *label_scale;
    QLineEdit *lineEdit_scale;
    QPushButton *pushButton_scale_minus;
    QPushButton *pushButton_scale_plus;
    QLabel *label_move;
    QLineEdit *lineEdit_move;
    QPushButton *pushButton_moveX_plus;
    QPushButton *pushButton_moveX_minus;
    QLabel *label_rotate;
    QPushButton *pushButton_rotateX_minus;
    QLineEdit *lineEdit_rotate;
    QPushButton *pushButton_rotateX_plus;
    QPushButton *pushButton_moveY_minus;
    QPushButton *pushButton_moveY_plus;
    QPushButton *pushButton_moveZ_minus;
    QPushButton *pushButton_moveZ_plus;
    QPushButton *pushButton_rotateY_minus;
    QPushButton *pushButton_rotateY_plus;
    QPushButton *pushButton_rotateZ_minus;
    QPushButton *pushButton_rotateZ_plus;
    ObjectViewer *widget;
    QPushButton *pushButton_scale;
    QLabel *label_readOnly_1;
    QLabel *label_readOnly_2;
    QLabel *label_readOnly_3;
    QLabel *label_fileName;
    QLabel *label_countV;
    QLabel *label_countF;
    QLabel *label_color;
    QPushButton *pushButton_color_background;
    QPushButton *pushButton_color_v;
    QPushButton *pushButton_color_f;
    QLabel *label_color_2;
    QLabel *label_sizeV;
    QLabel *label_sizeF;
    QLineEdit *lineEdit_sizeV;
    QLineEdit *lineEdit_sizeF;
    QPushButton *pushButton_sizeV_ok;
    QPushButton *pushButton_sizeF_ok;
    QCheckBox *checkBox_drawV;
    QCheckBox *checkBox_drawF;
    QPushButton *pushButton_take_screenshoot;
    QPushButton *pushButton_screencast;
    QCheckBox *checkBox_dotted;
    QCheckBox *checkBox_central_projection;
    QCheckBox *checkBox_circle_vertex;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1020, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 80);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(840, 10, 90, 30));
        pushButton_open->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  color: white;\n"
"  background-color: rgb(200, 150, 50);\n"
"  border: 1px solid black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(150, 100, 0);\n"
"}"));
        label_scale = new QLabel(centralwidget);
        label_scale->setObjectName(QString::fromUtf8("label_scale"));
        label_scale->setGeometry(QRect(860, 120, 60, 30));
        label_scale->setStyleSheet(QString::fromUtf8("color: white;"));
        lineEdit_scale = new QLineEdit(centralwidget);
        lineEdit_scale->setObjectName(QString::fromUtf8("lineEdit_scale"));
        lineEdit_scale->setGeometry(QRect(840, 160, 130, 30));
        lineEdit_scale->setStyleSheet(QString::fromUtf8("color: darkgreen;\n"
"background-color: white;\n"
"border:1px solid black"));
        lineEdit_scale->setAlignment(Qt::AlignCenter);
        pushButton_scale_minus = new QPushButton(centralwidget);
        pushButton_scale_minus->setObjectName(QString::fromUtf8("pushButton_scale_minus"));
        pushButton_scale_minus->setGeometry(QRect(940, 120, 30, 30));
        pushButton_scale_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/zoom-out.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        pushButton_scale_plus = new QPushButton(centralwidget);
        pushButton_scale_plus->setObjectName(QString::fromUtf8("pushButton_scale_plus"));
        pushButton_scale_plus->setGeometry(QRect(980, 120, 30, 30));
        pushButton_scale_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/zoom-in.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        label_move = new QLabel(centralwidget);
        label_move->setObjectName(QString::fromUtf8("label_move"));
        label_move->setGeometry(QRect(860, 200, 60, 30));
        label_move->setStyleSheet(QString::fromUtf8("color: white;"));
        lineEdit_move = new QLineEdit(centralwidget);
        lineEdit_move->setObjectName(QString::fromUtf8("lineEdit_move"));
        lineEdit_move->setGeometry(QRect(880, 240, 90, 30));
        lineEdit_move->setStyleSheet(QString::fromUtf8("color: darkgreen;\n"
"background-color: white;\n"
"border:1px solid black"));
        lineEdit_move->setAlignment(Qt::AlignCenter);
        pushButton_moveX_plus = new QPushButton(centralwidget);
        pushButton_moveX_plus->setObjectName(QString::fromUtf8("pushButton_moveX_plus"));
        pushButton_moveX_plus->setGeometry(QRect(980, 240, 30, 30));
        pushButton_moveX_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-right.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        pushButton_moveX_minus = new QPushButton(centralwidget);
        pushButton_moveX_minus->setObjectName(QString::fromUtf8("pushButton_moveX_minus"));
        pushButton_moveX_minus->setGeometry(QRect(840, 240, 30, 30));
        pushButton_moveX_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-left.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        label_rotate = new QLabel(centralwidget);
        label_rotate->setObjectName(QString::fromUtf8("label_rotate"));
        label_rotate->setGeometry(QRect(860, 320, 70, 30));
        label_rotate->setStyleSheet(QString::fromUtf8("color: white;"));
        pushButton_rotateX_minus = new QPushButton(centralwidget);
        pushButton_rotateX_minus->setObjectName(QString::fromUtf8("pushButton_rotateX_minus"));
        pushButton_rotateX_minus->setGeometry(QRect(880, 400, 30, 30));
        pushButton_rotateX_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-circle-down.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        lineEdit_rotate = new QLineEdit(centralwidget);
        lineEdit_rotate->setObjectName(QString::fromUtf8("lineEdit_rotate"));
        lineEdit_rotate->setGeometry(QRect(880, 360, 90, 30));
        lineEdit_rotate->setStyleSheet(QString::fromUtf8("color: darkgreen;\n"
"background-color: white;\n"
"border:1px solid black"));
        lineEdit_rotate->setAlignment(Qt::AlignCenter);
        pushButton_rotateX_plus = new QPushButton(centralwidget);
        pushButton_rotateX_plus->setObjectName(QString::fromUtf8("pushButton_rotateX_plus"));
        pushButton_rotateX_plus->setGeometry(QRect(940, 320, 30, 30));
        pushButton_rotateX_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-circle-up.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        pushButton_moveY_minus = new QPushButton(centralwidget);
        pushButton_moveY_minus->setObjectName(QString::fromUtf8("pushButton_moveY_minus"));
        pushButton_moveY_minus->setGeometry(QRect(880, 280, 30, 30));
        pushButton_moveY_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-down.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        pushButton_moveY_plus = new QPushButton(centralwidget);
        pushButton_moveY_plus->setObjectName(QString::fromUtf8("pushButton_moveY_plus"));
        pushButton_moveY_plus->setGeometry(QRect(940, 200, 30, 30));
        pushButton_moveY_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-up.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        pushButton_moveZ_minus = new QPushButton(centralwidget);
        pushButton_moveZ_minus->setObjectName(QString::fromUtf8("pushButton_moveZ_minus"));
        pushButton_moveZ_minus->setGeometry(QRect(840, 280, 30, 30));
        pushButton_moveZ_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-in.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        pushButton_moveZ_plus = new QPushButton(centralwidget);
        pushButton_moveZ_plus->setObjectName(QString::fromUtf8("pushButton_moveZ_plus"));
        pushButton_moveZ_plus->setGeometry(QRect(980, 200, 30, 30));
        pushButton_moveZ_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-out.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        pushButton_rotateY_minus = new QPushButton(centralwidget);
        pushButton_rotateY_minus->setObjectName(QString::fromUtf8("pushButton_rotateY_minus"));
        pushButton_rotateY_minus->setGeometry(QRect(840, 360, 30, 30));
        pushButton_rotateY_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-circle-left.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        pushButton_rotateY_plus = new QPushButton(centralwidget);
        pushButton_rotateY_plus->setObjectName(QString::fromUtf8("pushButton_rotateY_plus"));
        pushButton_rotateY_plus->setGeometry(QRect(980, 360, 30, 30));
        pushButton_rotateY_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-circle-right.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        pushButton_rotateZ_minus = new QPushButton(centralwidget);
        pushButton_rotateZ_minus->setObjectName(QString::fromUtf8("pushButton_rotateZ_minus"));
        pushButton_rotateZ_minus->setGeometry(QRect(840, 400, 30, 30));
        pushButton_rotateZ_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-circle-in.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        pushButton_rotateZ_plus = new QPushButton(centralwidget);
        pushButton_rotateZ_plus->setObjectName(QString::fromUtf8("pushButton_rotateZ_plus"));
        pushButton_rotateZ_plus->setGeometry(QRect(980, 320, 30, 30));
        pushButton_rotateZ_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/angle-circle-out.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        widget = new ObjectViewer(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 820, 760));
        widget->setStyleSheet(QString::fromUtf8(""));
        pushButton_scale = new QPushButton(centralwidget);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));
        pushButton_scale->setGeometry(QRect(980, 160, 30, 30));
        pushButton_scale->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(://Icons/search.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        label_readOnly_1 = new QLabel(centralwidget);
        label_readOnly_1->setObjectName(QString::fromUtf8("label_readOnly_1"));
        label_readOnly_1->setGeometry(QRect(20, 20, 120, 20));
        QFont font;
        font.setPointSize(8);
        label_readOnly_1->setFont(font);
        label_readOnly_1->setAutoFillBackground(false);
        label_readOnly_1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  	color: white; \n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_readOnly_2 = new QLabel(centralwidget);
        label_readOnly_2->setObjectName(QString::fromUtf8("label_readOnly_2"));
        label_readOnly_2->setGeometry(QRect(20, 40, 120, 20));
        label_readOnly_2->setFont(font);
        label_readOnly_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  	color: white; \n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_readOnly_3 = new QLabel(centralwidget);
        label_readOnly_3->setObjectName(QString::fromUtf8("label_readOnly_3"));
        label_readOnly_3->setGeometry(QRect(20, 60, 120, 20));
        label_readOnly_3->setFont(font);
        label_readOnly_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  	color: white; \n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_fileName = new QLabel(centralwidget);
        label_fileName->setObjectName(QString::fromUtf8("label_fileName"));
        label_fileName->setGeometry(QRect(140, 20, 680, 20));
        label_fileName->setFont(font);
        label_fileName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  	color: white; \n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_countV = new QLabel(centralwidget);
        label_countV->setObjectName(QString::fromUtf8("label_countV"));
        label_countV->setGeometry(QRect(140, 40, 200, 20));
        label_countV->setFont(font);
        label_countV->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  	color: white; \n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_countF = new QLabel(centralwidget);
        label_countF->setObjectName(QString::fromUtf8("label_countF"));
        label_countF->setGeometry(QRect(140, 60, 200, 20));
        label_countF->setFont(font);
        label_countF->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  	color: white; \n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_color = new QLabel(centralwidget);
        label_color->setObjectName(QString::fromUtf8("label_color"));
        label_color->setGeometry(QRect(860, 50, 60, 30));
        label_color->setStyleSheet(QString::fromUtf8("color: white;"));
        pushButton_color_background = new QPushButton(centralwidget);
        pushButton_color_background->setObjectName(QString::fromUtf8("pushButton_color_background"));
        pushButton_color_background->setGeometry(QRect(840, 80, 50, 30));
        pushButton_color_background->setStyleSheet(QString::fromUtf8(""));
        pushButton_color_v = new QPushButton(centralwidget);
        pushButton_color_v->setObjectName(QString::fromUtf8("pushButton_color_v"));
        pushButton_color_v->setGeometry(QRect(900, 80, 50, 30));
        pushButton_color_v->setStyleSheet(QString::fromUtf8(""));
        pushButton_color_f = new QPushButton(centralwidget);
        pushButton_color_f->setObjectName(QString::fromUtf8("pushButton_color_f"));
        pushButton_color_f->setGeometry(QRect(960, 80, 50, 30));
        pushButton_color_f->setStyleSheet(QString::fromUtf8(""));
        label_color_2 = new QLabel(centralwidget);
        label_color_2->setObjectName(QString::fromUtf8("label_color_2"));
        label_color_2->setGeometry(QRect(860, 520, 70, 30));
        label_color_2->setStyleSheet(QString::fromUtf8("color: white;"));
        label_sizeV = new QLabel(centralwidget);
        label_sizeV->setObjectName(QString::fromUtf8("label_sizeV"));
        label_sizeV->setGeometry(QRect(840, 560, 50, 30));
        label_sizeV->setStyleSheet(QString::fromUtf8("color: white;"));
        label_sizeF = new QLabel(centralwidget);
        label_sizeF->setObjectName(QString::fromUtf8("label_sizeF"));
        label_sizeF->setGeometry(QRect(840, 600, 50, 30));
        label_sizeF->setStyleSheet(QString::fromUtf8("color: white;"));
        lineEdit_sizeV = new QLineEdit(centralwidget);
        lineEdit_sizeV->setObjectName(QString::fromUtf8("lineEdit_sizeV"));
        lineEdit_sizeV->setGeometry(QRect(890, 560, 80, 30));
        lineEdit_sizeV->setStyleSheet(QString::fromUtf8("color: darkgreen;\n"
"background-color: white;\n"
"border:1px solid black"));
        lineEdit_sizeV->setAlignment(Qt::AlignCenter);
        lineEdit_sizeF = new QLineEdit(centralwidget);
        lineEdit_sizeF->setObjectName(QString::fromUtf8("lineEdit_sizeF"));
        lineEdit_sizeF->setGeometry(QRect(890, 600, 80, 30));
        lineEdit_sizeF->setStyleSheet(QString::fromUtf8("color: darkgreen;\n"
"background-color: white;\n"
"border:1px solid black"));
        lineEdit_sizeF->setAlignment(Qt::AlignCenter);
        pushButton_sizeV_ok = new QPushButton(centralwidget);
        pushButton_sizeV_ok->setObjectName(QString::fromUtf8("pushButton_sizeV_ok"));
        pushButton_sizeV_ok->setGeometry(QRect(980, 560, 30, 30));
        pushButton_sizeV_ok->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        pushButton_sizeF_ok = new QPushButton(centralwidget);
        pushButton_sizeF_ok->setObjectName(QString::fromUtf8("pushButton_sizeF_ok"));
        pushButton_sizeF_ok->setGeometry(QRect(980, 600, 30, 30));
        pushButton_sizeF_ok->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}"));
        checkBox_drawV = new QCheckBox(centralwidget);
        checkBox_drawV->setObjectName(QString::fromUtf8("checkBox_drawV"));
        checkBox_drawV->setGeometry(QRect(840, 450, 150, 30));
        checkBox_drawV->setStyleSheet(QString::fromUtf8("color: white;"));
        checkBox_drawV->setChecked(false);
        checkBox_drawF = new QCheckBox(centralwidget);
        checkBox_drawF->setObjectName(QString::fromUtf8("checkBox_drawF"));
        checkBox_drawF->setGeometry(QRect(840, 480, 150, 30));
        checkBox_drawF->setStyleSheet(QString::fromUtf8("color: white;"));
        checkBox_drawF->setChecked(false);
        pushButton_take_screenshoot = new QPushButton(centralwidget);
        pushButton_take_screenshoot->setObjectName(QString::fromUtf8("pushButton_take_screenshoot"));
        pushButton_take_screenshoot->setGeometry(QRect(940, 10, 30, 30));
        pushButton_take_screenshoot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(:/Icons/camera.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        pushButton_screencast = new QPushButton(centralwidget);
        pushButton_screencast->setObjectName(QString::fromUtf8("pushButton_screencast"));
        pushButton_screencast->setGeometry(QRect(980, 10, 30, 30));
        pushButton_screencast->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(200, 200, 200);\n"
"  border: 1px solid black;\n"
"  qproperty-icon: url(:/Icons/video-camera-alt.png)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(100, 100, 100);\n"
"}\n"
""));
        checkBox_dotted = new QCheckBox(centralwidget);
        checkBox_dotted->setObjectName(QString::fromUtf8("checkBox_dotted"));
        checkBox_dotted->setGeometry(QRect(840, 680, 150, 30));
        checkBox_dotted->setStyleSheet(QString::fromUtf8("color: white;"));
        checkBox_dotted->setChecked(false);
        checkBox_central_projection = new QCheckBox(centralwidget);
        checkBox_central_projection->setObjectName(QString::fromUtf8("checkBox_central_projection"));
        checkBox_central_projection->setGeometry(QRect(840, 710, 150, 30));
        checkBox_central_projection->setStyleSheet(QString::fromUtf8("color: white;"));
        checkBox_central_projection->setChecked(false);
        checkBox_circle_vertex = new QCheckBox(centralwidget);
        checkBox_circle_vertex->setObjectName(QString::fromUtf8("checkBox_circle_vertex"));
        checkBox_circle_vertex->setGeometry(QRect(840, 650, 150, 30));
        checkBox_circle_vertex->setStyleSheet(QString::fromUtf8("color: white;"));
        checkBox_circle_vertex->setChecked(false);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3DViewer_v1.0", nullptr));
        pushButton_open->setText(QApplication::translate("MainWindow", "Open", nullptr));
        label_scale->setText(QApplication::translate("MainWindow", "Scale:", nullptr));
        lineEdit_scale->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_scale_minus->setText(QString());
        pushButton_scale_plus->setText(QString());
        label_move->setText(QApplication::translate("MainWindow", "Move:", nullptr));
        lineEdit_move->setText(QApplication::translate("MainWindow", "0.2", nullptr));
        pushButton_moveX_plus->setText(QString());
        pushButton_moveX_minus->setText(QString());
        label_rotate->setText(QApplication::translate("MainWindow", "Rotate:", nullptr));
        pushButton_rotateX_minus->setText(QString());
        lineEdit_rotate->setText(QApplication::translate("MainWindow", "0.2", nullptr));
        pushButton_rotateX_plus->setText(QString());
        pushButton_moveY_minus->setText(QString());
        pushButton_moveY_plus->setText(QString());
        pushButton_moveZ_minus->setText(QString());
        pushButton_moveZ_plus->setText(QString());
        pushButton_rotateY_minus->setText(QString());
        pushButton_rotateY_plus->setText(QString());
        pushButton_rotateZ_minus->setText(QString());
        pushButton_rotateZ_plus->setText(QString());
        pushButton_scale->setText(QString());
        label_readOnly_1->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        label_readOnly_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        label_readOnly_3->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\263\321\200\320\260\320\275\320\265\320\271:", nullptr));
        label_fileName->setText(QString());
        label_countV->setText(QString());
        label_countF->setText(QString());
        label_color->setText(QApplication::translate("MainWindow", "Color:", nullptr));
        pushButton_color_background->setText(QApplication::translate("MainWindow", "BG", nullptr));
        pushButton_color_v->setText(QApplication::translate("MainWindow", "V", nullptr));
        pushButton_color_f->setText(QApplication::translate("MainWindow", "F", nullptr));
        label_color_2->setText(QApplication::translate("MainWindow", "Size of:", nullptr));
        label_sizeV->setText(QApplication::translate("MainWindow", "vertex", nullptr));
        label_sizeF->setText(QApplication::translate("MainWindow", "facets", nullptr));
        lineEdit_sizeV->setText(QString());
        lineEdit_sizeF->setText(QString());
        pushButton_sizeV_ok->setText(QApplication::translate("MainWindow", "ok", nullptr));
        pushButton_sizeF_ok->setText(QApplication::translate("MainWindow", "ok", nullptr));
        checkBox_drawV->setText(QApplication::translate("MainWindow", "Vertex draw", nullptr));
        checkBox_drawF->setText(QApplication::translate("MainWindow", "Facets draw", nullptr));
        pushButton_take_screenshoot->setText(QString());
        pushButton_screencast->setText(QString());
        checkBox_dotted->setText(QApplication::translate("MainWindow", "Dotted facets", nullptr));
        checkBox_central_projection->setText(QApplication::translate("MainWindow", "Central projection", nullptr));
        checkBox_circle_vertex->setText(QApplication::translate("MainWindow", "Circle vertex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
