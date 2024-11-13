/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *workArea;
    QLabel *label;
    QLabel *label_2;
    QLabel *x_coordinate;
    QLabel *y_coordinate;
    QPushButton *showAxis;
    QPushButton *gridlines;
    QSpinBox *gridOffset;
    QSpinBox *axisWidth;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *Reset_Screen_Button;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QSpinBox *Circle_Radius;
    QPushButton *Polar_Circle_Button;
    QLabel *Polar_Circle_Time;
    QPushButton *Bresenham_Circle_Button;
    QLabel *Bresenham_Circle_Time;
    QPushButton *Cartesian_Circle_Button;
    QLabel *Cartesian_Circle_Time;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QSpinBox *ellipse_axis_1;
    QLabel *label_7;
    QSpinBox *ellipse_axis_2;
    QPushButton *Polar_Ellipse_Button;
    QLabel *Polar_Ellipse_Time;
    QPushButton *Bresenham_Ellipse_Button;
    QLabel *Bresenham_Ellipse_Time;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *Bresenham_Button;
    QLabel *Bresenham_Time;
    QPushButton *DDA_Button;
    QLabel *DDA_Time;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *Polygon_Button;
    QSpinBox *Polygon_Side_Count;
    QLabel *label_8;
    QPushButton *Polygon_Scanline_Fill;
    QSpinBox *Polygon_Scanline_R;
    QSpinBox *Polygon_Scanline_G;
    QSpinBox *Polygon_Scanline_B;
    QLabel *label_11;
    QLabel *Polygon_Label;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QPushButton *Boundary_Fill;
    QSpinBox *Connected;
    QSpinBox *Seed_Color_G;
    QLabel *label_12;
    QPushButton *Flood_Fill;
    QLabel *label_16;
    QSpinBox *Seed_Color_B;
    QLabel *label_13;
    QLabel *Boundary_Fill_Time;
    QSpinBox *Seed_Color_R;
    QLabel *Flood_Fill_Time;
    QLabel *label_15;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_4;
    QSpinBox *Translate_Y;
    QPushButton *Reflect_Y;
    QLabel *label_21;
    QPushButton *Shear_Button;
    QPushButton *Scale_Button;
    QLabel *label_20;
    QPushButton *Translate_Button;
    QLabel *label_23;
    QSpinBox *Translate_X;
    QPushButton *Reflect_X;
    QLabel *label_22;
    QSpinBox *Rotate_Degrees;
    QDoubleSpinBox *Scale_X;
    QDoubleSpinBox *Scale_Y;
    QPushButton *Rotate_AC_Button;
    QDoubleSpinBox *Shear_X;
    QDoubleSpinBox *Shear_Y;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *Scale_Y_AP;
    QPushButton *Rotate_AC_Button_AP;
    QDoubleSpinBox *Scale_X_AP;
    QPushButton *Scale_Button_AP;
    QLabel *label_24;
    QLabel *label_25;
    QSpinBox *Rotate_Degrees_AP;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *Reflect_AL;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout;
    QPushButton *Clip_Line;
    QPushButton *Clip_Polygon;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1579, 988);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        workArea = new QLabel(centralwidget);
        workArea->setObjectName("workArea");
        workArea->setGeometry(QRect(20, 20, 741, 621));
        workArea->setFrameShape(QFrame::Shape::Box);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(770, 20, 91, 20));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(950, 21, 91, 21));
        label_2->setFont(font);
        x_coordinate = new QLabel(centralwidget);
        x_coordinate->setObjectName("x_coordinate");
        x_coordinate->setGeometry(QRect(880, 20, 63, 31));
        x_coordinate->setFont(font);
        x_coordinate->setFrameShape(QFrame::Shape::Box);
        y_coordinate = new QLabel(centralwidget);
        y_coordinate->setObjectName("y_coordinate");
        y_coordinate->setGeometry(QRect(1060, 20, 63, 31));
        y_coordinate->setFont(font);
        y_coordinate->setFrameShape(QFrame::Shape::Box);
        showAxis = new QPushButton(centralwidget);
        showAxis->setObjectName("showAxis");
        showAxis->setGeometry(QRect(770, 70, 83, 29));
        showAxis->setFont(font);
        gridlines = new QPushButton(centralwidget);
        gridlines->setObjectName("gridlines");
        gridlines->setGeometry(QRect(860, 70, 111, 29));
        gridlines->setFont(font);
        gridOffset = new QSpinBox(centralwidget);
        gridOffset->setObjectName("gridOffset");
        gridOffset->setGeometry(QRect(870, 110, 91, 29));
        gridOffset->setFont(font);
        gridOffset->setMinimum(0);
        gridOffset->setSingleStep(10);
        axisWidth = new QSpinBox(centralwidget);
        axisWidth->setObjectName("axisWidth");
        axisWidth->setGeometry(QRect(870, 150, 91, 29));
        axisWidth->setFont(font);
        axisWidth->setMinimum(1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(770, 110, 81, 20));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Shape::NoFrame);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(770, 160, 81, 20));
        label_4->setFont(font);
        Reset_Screen_Button = new QPushButton(centralwidget);
        Reset_Screen_Button->setObjectName("Reset_Screen_Button");
        Reset_Screen_Button->setGeometry(QRect(980, 70, 141, 29));
        Reset_Screen_Button->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(900, 190, 151, 291));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        groupBox->setFont(font1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        Circle_Radius = new QSpinBox(groupBox);
        Circle_Radius->setObjectName("Circle_Radius");

        verticalLayout->addWidget(Circle_Radius);

        Polar_Circle_Button = new QPushButton(groupBox);
        Polar_Circle_Button->setObjectName("Polar_Circle_Button");

        verticalLayout->addWidget(Polar_Circle_Button);

        Polar_Circle_Time = new QLabel(groupBox);
        Polar_Circle_Time->setObjectName("Polar_Circle_Time");
        Polar_Circle_Time->setFrameShape(QFrame::Shape::Box);

        verticalLayout->addWidget(Polar_Circle_Time);

        Bresenham_Circle_Button = new QPushButton(groupBox);
        Bresenham_Circle_Button->setObjectName("Bresenham_Circle_Button");

        verticalLayout->addWidget(Bresenham_Circle_Button);

        Bresenham_Circle_Time = new QLabel(groupBox);
        Bresenham_Circle_Time->setObjectName("Bresenham_Circle_Time");
        Bresenham_Circle_Time->setFrameShape(QFrame::Shape::Box);

        verticalLayout->addWidget(Bresenham_Circle_Time);

        Cartesian_Circle_Button = new QPushButton(groupBox);
        Cartesian_Circle_Button->setObjectName("Cartesian_Circle_Button");

        verticalLayout->addWidget(Cartesian_Circle_Button);

        Cartesian_Circle_Time = new QLabel(groupBox);
        Cartesian_Circle_Time->setObjectName("Cartesian_Circle_Time");
        Cartesian_Circle_Time->setFont(font1);
        Cartesian_Circle_Time->setFrameShape(QFrame::Shape::Box);

        verticalLayout->addWidget(Cartesian_Circle_Time);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(1050, 190, 161, 291));
        groupBox_2->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);

        verticalLayout_2->addWidget(label_6);

        ellipse_axis_1 = new QSpinBox(groupBox_2);
        ellipse_axis_1->setObjectName("ellipse_axis_1");
        ellipse_axis_1->setFont(font1);

        verticalLayout_2->addWidget(ellipse_axis_1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setFont(font1);

        verticalLayout_2->addWidget(label_7);

        ellipse_axis_2 = new QSpinBox(groupBox_2);
        ellipse_axis_2->setObjectName("ellipse_axis_2");
        ellipse_axis_2->setFont(font1);

        verticalLayout_2->addWidget(ellipse_axis_2);

        Polar_Ellipse_Button = new QPushButton(groupBox_2);
        Polar_Ellipse_Button->setObjectName("Polar_Ellipse_Button");
        Polar_Ellipse_Button->setFont(font1);

        verticalLayout_2->addWidget(Polar_Ellipse_Button);

        Polar_Ellipse_Time = new QLabel(groupBox_2);
        Polar_Ellipse_Time->setObjectName("Polar_Ellipse_Time");
        Polar_Ellipse_Time->setFont(font1);
        Polar_Ellipse_Time->setFrameShape(QFrame::Shape::Box);

        verticalLayout_2->addWidget(Polar_Ellipse_Time);

        Bresenham_Ellipse_Button = new QPushButton(groupBox_2);
        Bresenham_Ellipse_Button->setObjectName("Bresenham_Ellipse_Button");
        Bresenham_Ellipse_Button->setFont(font1);

        verticalLayout_2->addWidget(Bresenham_Ellipse_Button);

        Bresenham_Ellipse_Time = new QLabel(groupBox_2);
        Bresenham_Ellipse_Time->setObjectName("Bresenham_Ellipse_Time");
        Bresenham_Ellipse_Time->setFont(font1);
        Bresenham_Ellipse_Time->setFrameShape(QFrame::Shape::Box);

        verticalLayout_2->addWidget(Bresenham_Ellipse_Time);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(760, 190, 141, 291));
        groupBox_3->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        Bresenham_Button = new QPushButton(groupBox_3);
        Bresenham_Button->setObjectName("Bresenham_Button");
        Bresenham_Button->setFont(font);

        verticalLayout_3->addWidget(Bresenham_Button);

        Bresenham_Time = new QLabel(groupBox_3);
        Bresenham_Time->setObjectName("Bresenham_Time");
        Bresenham_Time->setFont(font);

        verticalLayout_3->addWidget(Bresenham_Time);

        DDA_Button = new QPushButton(groupBox_3);
        DDA_Button->setObjectName("DDA_Button");
        DDA_Button->setFont(font);

        verticalLayout_3->addWidget(DDA_Button);

        DDA_Time = new QLabel(groupBox_3);
        DDA_Time->setObjectName("DDA_Time");
        DDA_Time->setFont(font);

        verticalLayout_3->addWidget(DDA_Time);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(1210, 190, 151, 291));
        groupBox_4->setFont(font);
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName("gridLayout");
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 5, 0, 1, 1);

        Polygon_Button = new QPushButton(groupBox_4);
        Polygon_Button->setObjectName("Polygon_Button");
        Polygon_Button->setFont(font);

        gridLayout->addWidget(Polygon_Button, 2, 0, 1, 2);

        Polygon_Side_Count = new QSpinBox(groupBox_4);
        Polygon_Side_Count->setObjectName("Polygon_Side_Count");
        Polygon_Side_Count->setFont(font);

        gridLayout->addWidget(Polygon_Side_Count, 1, 0, 1, 2);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 0, 0, 1, 2);

        Polygon_Scanline_Fill = new QPushButton(groupBox_4);
        Polygon_Scanline_Fill->setObjectName("Polygon_Scanline_Fill");
        Polygon_Scanline_Fill->setFont(font);

        gridLayout->addWidget(Polygon_Scanline_Fill, 9, 0, 1, 2);

        Polygon_Scanline_R = new QSpinBox(groupBox_4);
        Polygon_Scanline_R->setObjectName("Polygon_Scanline_R");
        Polygon_Scanline_R->setFont(font);

        gridLayout->addWidget(Polygon_Scanline_R, 3, 1, 1, 1);

        Polygon_Scanline_G = new QSpinBox(groupBox_4);
        Polygon_Scanline_G->setObjectName("Polygon_Scanline_G");
        Polygon_Scanline_G->setFont(font);

        gridLayout->addWidget(Polygon_Scanline_G, 5, 1, 1, 1);

        Polygon_Scanline_B = new QSpinBox(groupBox_4);
        Polygon_Scanline_B->setObjectName("Polygon_Scanline_B");
        Polygon_Scanline_B->setFont(font);

        gridLayout->addWidget(Polygon_Scanline_B, 6, 1, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        Polygon_Label = new QLabel(groupBox_4);
        Polygon_Label->setObjectName("Polygon_Label");
        Polygon_Label->setFont(font);
        Polygon_Label->setFrameShape(QFrame::Shape::Box);

        gridLayout->addWidget(Polygon_Label, 10, 0, 1, 2);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(1360, 190, 161, 291));
        groupBox_5->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setObjectName("gridLayout_2");
        Boundary_Fill = new QPushButton(groupBox_5);
        Boundary_Fill->setObjectName("Boundary_Fill");
        Boundary_Fill->setFont(font);

        gridLayout_2->addWidget(Boundary_Fill, 9, 0, 1, 2);

        Connected = new QSpinBox(groupBox_5);
        Connected->setObjectName("Connected");
        Connected->setFont(font);

        gridLayout_2->addWidget(Connected, 4, 1, 1, 1);

        Seed_Color_G = new QSpinBox(groupBox_5);
        Seed_Color_G->setObjectName("Seed_Color_G");
        Seed_Color_G->setFont(font);

        gridLayout_2->addWidget(Seed_Color_G, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        Flood_Fill = new QPushButton(groupBox_5);
        Flood_Fill->setObjectName("Flood_Fill");
        Flood_Fill->setFont(font);

        gridLayout_2->addWidget(Flood_Fill, 6, 0, 1, 2);

        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName("label_16");

        gridLayout_2->addWidget(label_16, 4, 0, 1, 1);

        Seed_Color_B = new QSpinBox(groupBox_5);
        Seed_Color_B->setObjectName("Seed_Color_B");
        Seed_Color_B->setFont(font);

        gridLayout_2->addWidget(Seed_Color_B, 3, 1, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName("label_13");

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        Boundary_Fill_Time = new QLabel(groupBox_5);
        Boundary_Fill_Time->setObjectName("Boundary_Fill_Time");
        Boundary_Fill_Time->setFont(font);
        Boundary_Fill_Time->setFrameShape(QFrame::Shape::Box);

        gridLayout_2->addWidget(Boundary_Fill_Time, 10, 0, 1, 2);

        Seed_Color_R = new QSpinBox(groupBox_5);
        Seed_Color_R->setObjectName("Seed_Color_R");
        Seed_Color_R->setFont(font);

        gridLayout_2->addWidget(Seed_Color_R, 0, 1, 1, 1);

        Flood_Fill_Time = new QLabel(groupBox_5);
        Flood_Fill_Time->setObjectName("Flood_Fill_Time");
        Flood_Fill_Time->setFont(font);
        Flood_Fill_Time->setFrameShape(QFrame::Shape::Box);

        gridLayout_2->addWidget(Flood_Fill_Time, 7, 0, 1, 2);

        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName("label_15");

        gridLayout_2->addWidget(label_15, 3, 0, 1, 1);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(760, 480, 751, 181));
        groupBox_6->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox_6);
        gridLayout_4->setObjectName("gridLayout_4");
        Translate_Y = new QSpinBox(groupBox_6);
        Translate_Y->setObjectName("Translate_Y");
        Translate_Y->setMinimum(-99);

        gridLayout_4->addWidget(Translate_Y, 1, 1, 1, 1);

        Reflect_Y = new QPushButton(groupBox_6);
        Reflect_Y->setObjectName("Reflect_Y");

        gridLayout_4->addWidget(Reflect_Y, 2, 4, 1, 1);

        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName("label_21");

        gridLayout_4->addWidget(label_21, 0, 1, 1, 1);

        Shear_Button = new QPushButton(groupBox_6);
        Shear_Button->setObjectName("Shear_Button");

        gridLayout_4->addWidget(Shear_Button, 2, 2, 1, 1);

        Scale_Button = new QPushButton(groupBox_6);
        Scale_Button->setObjectName("Scale_Button");

        gridLayout_4->addWidget(Scale_Button, 3, 2, 1, 1);

        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName("label_20");

        gridLayout_4->addWidget(label_20, 0, 0, 1, 1);

        Translate_Button = new QPushButton(groupBox_6);
        Translate_Button->setObjectName("Translate_Button");

        gridLayout_4->addWidget(Translate_Button, 1, 2, 1, 1);

        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName("label_23");

        gridLayout_4->addWidget(label_23, 1, 5, 1, 1);

        Translate_X = new QSpinBox(groupBox_6);
        Translate_X->setObjectName("Translate_X");
        Translate_X->setMinimum(-99);

        gridLayout_4->addWidget(Translate_X, 1, 0, 1, 1);

        Reflect_X = new QPushButton(groupBox_6);
        Reflect_X->setObjectName("Reflect_X");

        gridLayout_4->addWidget(Reflect_X, 1, 4, 1, 1);

        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName("label_22");

        gridLayout_4->addWidget(label_22, 1, 3, 1, 1);

        Rotate_Degrees = new QSpinBox(groupBox_6);
        Rotate_Degrees->setObjectName("Rotate_Degrees");
        Rotate_Degrees->setMinimum(-360);
        Rotate_Degrees->setMaximum(360);

        gridLayout_4->addWidget(Rotate_Degrees, 1, 6, 1, 1);

        Scale_X = new QDoubleSpinBox(groupBox_6);
        Scale_X->setObjectName("Scale_X");
        Scale_X->setMinimum(-99.000000000000000);
        Scale_X->setMaximum(99.000000000000000);

        gridLayout_4->addWidget(Scale_X, 3, 0, 1, 1);

        Scale_Y = new QDoubleSpinBox(groupBox_6);
        Scale_Y->setObjectName("Scale_Y");
        Scale_Y->setMinimum(-99.000000000000000);
        Scale_Y->setMaximum(99.000000000000000);

        gridLayout_4->addWidget(Scale_Y, 3, 1, 1, 1);

        Rotate_AC_Button = new QPushButton(groupBox_6);
        Rotate_AC_Button->setObjectName("Rotate_AC_Button");

        gridLayout_4->addWidget(Rotate_AC_Button, 2, 6, 1, 1);

        Shear_X = new QDoubleSpinBox(groupBox_6);
        Shear_X->setObjectName("Shear_X");
        Shear_X->setMinimum(-99.000000000000000);

        gridLayout_4->addWidget(Shear_X, 2, 0, 1, 1);

        Shear_Y = new QDoubleSpinBox(groupBox_6);
        Shear_Y->setObjectName("Shear_Y");
        Shear_Y->setMinimum(-99.000000000000000);

        gridLayout_4->addWidget(Shear_Y, 2, 1, 1, 1);

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(760, 660, 751, 111));
        groupBox_7->setFont(font1);
        gridLayout_5 = new QGridLayout(groupBox_7);
        gridLayout_5->setObjectName("gridLayout_5");
        Scale_Y_AP = new QDoubleSpinBox(groupBox_7);
        Scale_Y_AP->setObjectName("Scale_Y_AP");
        Scale_Y_AP->setMinimum(-99.000000000000000);
        Scale_Y_AP->setMaximum(99.000000000000000);

        gridLayout_5->addWidget(Scale_Y_AP, 1, 4, 1, 1);

        Rotate_AC_Button_AP = new QPushButton(groupBox_7);
        Rotate_AC_Button_AP->setObjectName("Rotate_AC_Button_AP");

        gridLayout_5->addWidget(Rotate_AC_Button_AP, 2, 5, 1, 1);

        Scale_X_AP = new QDoubleSpinBox(groupBox_7);
        Scale_X_AP->setObjectName("Scale_X_AP");
        Scale_X_AP->setMinimum(-99.000000000000000);
        Scale_X_AP->setMaximum(99.000000000000000);

        gridLayout_5->addWidget(Scale_X_AP, 1, 2, 1, 1);

        Scale_Button_AP = new QPushButton(groupBox_7);
        Scale_Button_AP->setObjectName("Scale_Button_AP");

        gridLayout_5->addWidget(Scale_Button_AP, 1, 5, 1, 1);

        label_24 = new QLabel(groupBox_7);
        label_24->setObjectName("label_24");

        gridLayout_5->addWidget(label_24, 1, 1, 1, 1);

        label_25 = new QLabel(groupBox_7);
        label_25->setObjectName("label_25");

        gridLayout_5->addWidget(label_25, 1, 3, 1, 1);

        Rotate_Degrees_AP = new QSpinBox(groupBox_7);
        Rotate_Degrees_AP->setObjectName("Rotate_Degrees_AP");
        Rotate_Degrees_AP->setMinimum(-360);
        Rotate_Degrees_AP->setMaximum(360);

        gridLayout_5->addWidget(Rotate_Degrees_AP, 2, 4, 1, 1);

        label_26 = new QLabel(groupBox_7);
        label_26->setObjectName("label_26");
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setUnderline(true);
        label_26->setFont(font2);

        gridLayout_5->addWidget(label_26, 1, 0, 1, 1);

        label_27 = new QLabel(groupBox_7);
        label_27->setObjectName("label_27");
        label_27->setFont(font2);

        gridLayout_5->addWidget(label_27, 2, 3, 1, 1);

        label_28 = new QLabel(groupBox_7);
        label_28->setObjectName("label_28");
        label_28->setFont(font2);

        gridLayout_5->addWidget(label_28, 2, 0, 1, 1);

        Reflect_AL = new QPushButton(groupBox_7);
        Reflect_AL->setObjectName("Reflect_AL");

        gridLayout_5->addWidget(Reflect_AL, 2, 1, 1, 1);

        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(220, 680, 268, 80));
        groupBox_8->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox_8);
        horizontalLayout->setObjectName("horizontalLayout");
        Clip_Line = new QPushButton(groupBox_8);
        Clip_Line->setObjectName("Clip_Line");
        Clip_Line->setFont(font);

        horizontalLayout->addWidget(Clip_Line);

        Clip_Polygon = new QPushButton(groupBox_8);
        Clip_Polygon->setObjectName("Clip_Polygon");
        Clip_Polygon->setFont(font);

        horizontalLayout->addWidget(Clip_Polygon);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1579, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        workArea->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "X Coordinate", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y Coordinate", nullptr));
        x_coordinate->setText(QString());
        y_coordinate->setText(QString());
        showAxis->setText(QCoreApplication::translate("MainWindow", "Show Axes", nullptr));
        gridlines->setText(QCoreApplication::translate("MainWindow", "Show Gridlines", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "GridOffset", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Axis Width", nullptr));
        Reset_Screen_Button->setText(QCoreApplication::translate("MainWindow", "Reset Screen", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "CIRCLE", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        Polar_Circle_Button->setText(QCoreApplication::translate("MainWindow", "Polar Circle", nullptr));
        Polar_Circle_Time->setText(QString());
        Bresenham_Circle_Button->setText(QCoreApplication::translate("MainWindow", "Bresenham Circle", nullptr));
        Bresenham_Circle_Time->setText(QString());
        Cartesian_Circle_Button->setText(QCoreApplication::translate("MainWindow", "Cartesian Circle", nullptr));
        Cartesian_Circle_Time->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "ELLIPSE", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Semi Axis Length 1", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Semi Axis Length 2", nullptr));
        Polar_Ellipse_Button->setText(QCoreApplication::translate("MainWindow", "Polar Ellipse", nullptr));
        Polar_Ellipse_Time->setText(QString());
        Bresenham_Ellipse_Button->setText(QCoreApplication::translate("MainWindow", "Bresenham Ellipse", nullptr));
        Bresenham_Ellipse_Time->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "STRAIGHT LINE", nullptr));
        Bresenham_Button->setText(QCoreApplication::translate("MainWindow", "Bresenham Line", nullptr));
        Bresenham_Time->setText(QString());
        DDA_Button->setText(QCoreApplication::translate("MainWindow", "DDA Line", nullptr));
        DDA_Time->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "POLYGON", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        Polygon_Button->setText(QCoreApplication::translate("MainWindow", "Draw Polygon", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Number of Sides", nullptr));
        Polygon_Scanline_Fill->setText(QCoreApplication::translate("MainWindow", "Scanline Fill", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        Polygon_Label->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "SEED FILLING", nullptr));
        Boundary_Fill->setText(QCoreApplication::translate("MainWindow", "Boundary Fill", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        Flood_Fill->setText(QCoreApplication::translate("MainWindow", "Flood Fill", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Connected", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        Boundary_Fill_Time->setText(QString());
        Flood_Fill_Time->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "TRANSFORMATION", nullptr));
        Reflect_Y->setText(QCoreApplication::translate("MainWindow", "Reflect Along Y Axis", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Along Y Axis       ", nullptr));
        Shear_Button->setText(QCoreApplication::translate("MainWindow", "Shear", nullptr));
        Scale_Button->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Along X Axis       ", nullptr));
        Translate_Button->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        label_23->setText(QString());
        Reflect_X->setText(QCoreApplication::translate("MainWindow", "Reflect Along X Axis", nullptr));
        label_22->setText(QString());
        Rotate_AC_Button->setText(QCoreApplication::translate("MainWindow", "Rotate Anti-Clockwise", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "ARBITRARY REFERENCE TRANSFORMATION", nullptr));
        Rotate_AC_Button_AP->setText(QCoreApplication::translate("MainWindow", "Rotate Anti-Clockwise", nullptr));
        Scale_Button_AP->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Along X axis", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Along Y Axis", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Scaling wrt point", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Rotation wrt point", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Reflect wrt line", nullptr));
        Reflect_AL->setText(QCoreApplication::translate("MainWindow", "Reflect", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "CLIPPING", nullptr));
        Clip_Line->setText(QCoreApplication::translate("MainWindow", "Clip Line", nullptr));
        Clip_Polygon->setText(QCoreApplication::translate("MainWindow", "Clip Polygon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
