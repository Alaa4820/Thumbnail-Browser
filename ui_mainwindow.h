/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollAreaImages;
    QWidget *scrollAreaImagesWidgetContents;
    QScrollArea *scrollAreaCategories;
    QWidget *scrollAreaCategoriesWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(828, 446);
        MainWindow->setMinimumSize(QSize(180, 180));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollAreaImages = new QScrollArea(centralwidget);
        scrollAreaImages->setObjectName(QString::fromUtf8("scrollAreaImages"));
        scrollAreaImages->setMinimumSize(QSize(130, 130));
        scrollAreaImages->setWidgetResizable(true);
        scrollAreaImagesWidgetContents = new QWidget();
        scrollAreaImagesWidgetContents->setObjectName(QString::fromUtf8("scrollAreaImagesWidgetContents"));
        scrollAreaImagesWidgetContents->setGeometry(QRect(0, 0, 548, 422));
        scrollAreaImages->setWidget(scrollAreaImagesWidgetContents);

        horizontalLayout->addWidget(scrollAreaImages);

        scrollAreaCategories = new QScrollArea(centralwidget);
        scrollAreaCategories->setObjectName(QString::fromUtf8("scrollAreaCategories"));
        scrollAreaCategories->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaCategories->sizePolicy().hasHeightForWidth());
        scrollAreaCategories->setSizePolicy(sizePolicy);
        scrollAreaCategories->setMinimumSize(QSize(250, 0));
        scrollAreaCategories->setWidgetResizable(true);
        scrollAreaCategoriesWidgetContents = new QWidget();
        scrollAreaCategoriesWidgetContents->setObjectName(QString::fromUtf8("scrollAreaCategoriesWidgetContents"));
        scrollAreaCategoriesWidgetContents->setGeometry(QRect(0, 0, 248, 422));
        gridLayout_2 = new QGridLayout(scrollAreaCategoriesWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollAreaCategories->setWidget(scrollAreaCategoriesWidgetContents);

        horizontalLayout->addWidget(scrollAreaCategories);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
