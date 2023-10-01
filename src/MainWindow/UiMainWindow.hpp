/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabs;
    QWidget *personnelTab;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *personnelTable;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addPersonBtn;
    QPushButton *removePersonBtn;
    QSpacerItem *verticalSpacer_5;
    QPushButton *refreshPerson;
    QSpacerItem *verticalSpacer_2;
    QWidget *autoTab;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *autoTable;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *addAutoBtn;
    QPushButton *removeAutoBtn;
    QSpacerItem *verticalSpacer_6;
    QPushButton *refreshAuto;
    QSpacerItem *verticalSpacer;
    QWidget *routeTab;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *routeTable;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addRouteBtn;
    QPushButton *removeRouteBtn;
    QSpacerItem *verticalSpacer_7;
    QPushButton *refreshRoute;
    QSpacerItem *verticalSpacer_3;
    QWidget *journalTab;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *journalTable;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addTripBtn;
    QPushButton *removeTripBtn;
    QSpacerItem *verticalSpacer_8;
    QPushButton *refreshJournal;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(978, 667);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabs = new QTabWidget(centralwidget);
        tabs->setObjectName(QString::fromUtf8("tabs"));
        personnelTab = new QWidget();
        personnelTab->setObjectName(QString::fromUtf8("personnelTab"));
        horizontalLayout_5 = new QHBoxLayout(personnelTab);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        personnelTable = new QTableWidget(personnelTab);
        if (personnelTable->columnCount() < 4)
            personnelTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        personnelTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        personnelTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        personnelTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        personnelTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        personnelTable->setObjectName(QString::fromUtf8("personnelTable"));

        horizontalLayout_5->addWidget(personnelTable);

        groupBox_2 = new QGroupBox(personnelTab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        addPersonBtn = new QPushButton(groupBox_2);
        addPersonBtn->setObjectName(QString::fromUtf8("addPersonBtn"));

        verticalLayout_2->addWidget(addPersonBtn);

        removePersonBtn = new QPushButton(groupBox_2);
        removePersonBtn->setObjectName(QString::fromUtf8("removePersonBtn"));

        verticalLayout_2->addWidget(removePersonBtn);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        refreshPerson = new QPushButton(groupBox_2);
        refreshPerson->setObjectName(QString::fromUtf8("refreshPerson"));

        verticalLayout_2->addWidget(refreshPerson);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_5->addWidget(groupBox_2);

        tabs->addTab(personnelTab, QString());
        autoTab = new QWidget();
        autoTab->setObjectName(QString::fromUtf8("autoTab"));
        horizontalLayout_2 = new QHBoxLayout(autoTab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        autoTable = new QTableWidget(autoTab);
        if (autoTable->columnCount() < 5)
            autoTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        autoTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        autoTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        autoTable->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        autoTable->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        autoTable->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        autoTable->setObjectName(QString::fromUtf8("autoTable"));

        horizontalLayout_2->addWidget(autoTable);

        groupBox = new QGroupBox(autoTab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addAutoBtn = new QPushButton(groupBox);
        addAutoBtn->setObjectName(QString::fromUtf8("addAutoBtn"));

        verticalLayout->addWidget(addAutoBtn);

        removeAutoBtn = new QPushButton(groupBox);
        removeAutoBtn->setObjectName(QString::fromUtf8("removeAutoBtn"));

        verticalLayout->addWidget(removeAutoBtn);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        refreshAuto = new QPushButton(groupBox);
        refreshAuto->setObjectName(QString::fromUtf8("refreshAuto"));

        verticalLayout->addWidget(refreshAuto);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(groupBox);

        tabs->addTab(autoTab, QString());
        routeTab = new QWidget();
        routeTab->setObjectName(QString::fromUtf8("routeTab"));
        horizontalLayout_4 = new QHBoxLayout(routeTab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        routeTable = new QTableWidget(routeTab);
        if (routeTable->columnCount() < 2)
            routeTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        routeTable->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        routeTable->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        routeTable->setObjectName(QString::fromUtf8("routeTable"));

        horizontalLayout_4->addWidget(routeTable);

        groupBox_3 = new QGroupBox(routeTab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        addRouteBtn = new QPushButton(groupBox_3);
        addRouteBtn->setObjectName(QString::fromUtf8("addRouteBtn"));

        verticalLayout_3->addWidget(addRouteBtn);

        removeRouteBtn = new QPushButton(groupBox_3);
        removeRouteBtn->setObjectName(QString::fromUtf8("removeRouteBtn"));

        verticalLayout_3->addWidget(removeRouteBtn);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_7);

        refreshRoute = new QPushButton(groupBox_3);
        refreshRoute->setObjectName(QString::fromUtf8("refreshRoute"));

        verticalLayout_3->addWidget(refreshRoute);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_4->addWidget(groupBox_3);

        tabs->addTab(routeTab, QString());
        journalTab = new QWidget();
        journalTab->setObjectName(QString::fromUtf8("journalTab"));
        horizontalLayout_3 = new QHBoxLayout(journalTab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        journalTable = new QTableWidget(journalTab);
        if (journalTable->columnCount() < 5)
            journalTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        journalTable->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        journalTable->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        journalTable->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        journalTable->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        journalTable->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        journalTable->setObjectName(QString::fromUtf8("journalTable"));

        horizontalLayout_3->addWidget(journalTable);

        groupBox_4 = new QGroupBox(journalTab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        addTripBtn = new QPushButton(groupBox_4);
        addTripBtn->setObjectName(QString::fromUtf8("addTripBtn"));

        verticalLayout_4->addWidget(addTripBtn);

        removeTripBtn = new QPushButton(groupBox_4);
        removeTripBtn->setObjectName(QString::fromUtf8("removeTripBtn"));

        verticalLayout_4->addWidget(removeTripBtn);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_8);

        refreshJournal = new QPushButton(groupBox_4);
        refreshJournal->setObjectName(QString::fromUtf8("refreshJournal"));

        verticalLayout_4->addWidget(refreshJournal);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout_3->addWidget(groupBox_4);

        tabs->addTab(journalTab, QString());

        horizontalLayout->addWidget(tabs);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 978, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = personnelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = personnelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "FIRST_NAME", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = personnelTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "SECOND_NAME", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = personnelTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "FATHER_NAME", nullptr));
        groupBox_2->setTitle(QString());
        addPersonBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removePersonBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        refreshPerson->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        tabs->setTabText(tabs->indexOf(personnelTab), QCoreApplication::translate("MainWindow", "PERSONNEL", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = autoTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = autoTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "NUM", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = autoTable->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "COLOR", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = autoTable->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "MARK", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = autoTable->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "PERSONNEL_ID", nullptr));
        groupBox->setTitle(QString());
        addAutoBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeAutoBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        refreshAuto->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        tabs->setTabText(tabs->indexOf(autoTab), QCoreApplication::translate("MainWindow", "AUTO", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = routeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = routeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "NAME", nullptr));
        groupBox_3->setTitle(QString());
        addRouteBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeRouteBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        refreshRoute->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        tabs->setTabText(tabs->indexOf(routeTab), QCoreApplication::translate("MainWindow", "ROUTE", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = journalTable->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = journalTable->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "TIME_OUT", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = journalTable->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "TIME_IN", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = journalTable->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "AUTO_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = journalTable->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "ROUTE_ID", nullptr));
        groupBox_4->setTitle(QString());
        addTripBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeTripBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        refreshJournal->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        tabs->setTabText(tabs->indexOf(journalTab), QCoreApplication::translate("MainWindow", "JOURNAL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
