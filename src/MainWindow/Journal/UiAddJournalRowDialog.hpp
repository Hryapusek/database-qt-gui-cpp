/********************************************************************************
** Form generated from reading UI file 'addJournalRowDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDJOURNALROWDIALOG_H
#define UI_ADDJOURNALROWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddJournalRowDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QLabel *idLbl;
    QLineEdit *idLine;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *timeOutLbl;
    QLineEdit *timeOutLine;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *timeInLbl;
    QLineEdit *timeInLine;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *autoIdLbl;
    QLineEdit *autoIdLine;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QLabel *routeIdLbl;
    QLineEdit *routeIdLine;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddJournalRowDialog)
    {
        if (AddJournalRowDialog->objectName().isEmpty())
            AddJournalRowDialog->setObjectName(QString::fromUtf8("AddJournalRowDialog"));
        AddJournalRowDialog->resize(196, 234);
        verticalLayout = new QVBoxLayout(AddJournalRowDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        idLbl = new QLabel(AddJournalRowDialog);
        idLbl->setObjectName(QString::fromUtf8("idLbl"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(idLbl->sizePolicy().hasHeightForWidth());
        idLbl->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(idLbl);

        idLine = new QLineEdit(AddJournalRowDialog);
        idLine->setObjectName(QString::fromUtf8("idLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(idLine->sizePolicy().hasHeightForWidth());
        idLine->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(idLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        timeOutLbl = new QLabel(AddJournalRowDialog);
        timeOutLbl->setObjectName(QString::fromUtf8("timeOutLbl"));
        sizePolicy.setHeightForWidth(timeOutLbl->sizePolicy().hasHeightForWidth());
        timeOutLbl->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(timeOutLbl);

        timeOutLine = new QLineEdit(AddJournalRowDialog);
        timeOutLine->setObjectName(QString::fromUtf8("timeOutLine"));
        sizePolicy1.setHeightForWidth(timeOutLine->sizePolicy().hasHeightForWidth());
        timeOutLine->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(timeOutLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        timeInLbl = new QLabel(AddJournalRowDialog);
        timeInLbl->setObjectName(QString::fromUtf8("timeInLbl"));
        sizePolicy.setHeightForWidth(timeInLbl->sizePolicy().hasHeightForWidth());
        timeInLbl->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(timeInLbl);

        timeInLine = new QLineEdit(AddJournalRowDialog);
        timeInLine->setObjectName(QString::fromUtf8("timeInLine"));
        sizePolicy1.setHeightForWidth(timeInLine->sizePolicy().hasHeightForWidth());
        timeInLine->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(timeInLine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        autoIdLbl = new QLabel(AddJournalRowDialog);
        autoIdLbl->setObjectName(QString::fromUtf8("autoIdLbl"));
        sizePolicy.setHeightForWidth(autoIdLbl->sizePolicy().hasHeightForWidth());
        autoIdLbl->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(autoIdLbl);

        autoIdLine = new QLineEdit(AddJournalRowDialog);
        autoIdLine->setObjectName(QString::fromUtf8("autoIdLine"));
        sizePolicy1.setHeightForWidth(autoIdLine->sizePolicy().hasHeightForWidth());
        autoIdLine->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(autoIdLine);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        routeIdLbl = new QLabel(AddJournalRowDialog);
        routeIdLbl->setObjectName(QString::fromUtf8("routeIdLbl"));
        sizePolicy.setHeightForWidth(routeIdLbl->sizePolicy().hasHeightForWidth());
        routeIdLbl->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(routeIdLbl);

        routeIdLine = new QLineEdit(AddJournalRowDialog);
        routeIdLine->setObjectName(QString::fromUtf8("routeIdLine"));
        sizePolicy1.setHeightForWidth(routeIdLine->sizePolicy().hasHeightForWidth());
        routeIdLine->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(routeIdLine);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(AddJournalRowDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(AddJournalRowDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddJournalRowDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddJournalRowDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddJournalRowDialog);
    } // setupUi

    void retranslateUi(QDialog *AddJournalRowDialog)
    {
        AddJournalRowDialog->setWindowTitle(QCoreApplication::translate("AddJournalRowDialog", "Add Journal Row", nullptr));
        idLbl->setText(QCoreApplication::translate("AddJournalRowDialog", "ID", nullptr));
        timeOutLbl->setText(QCoreApplication::translate("AddJournalRowDialog", "Time OUT", nullptr));
        timeInLbl->setText(QCoreApplication::translate("AddJournalRowDialog", "Time IN", nullptr));
        autoIdLbl->setText(QCoreApplication::translate("AddJournalRowDialog", "Auto ID", nullptr));
        routeIdLbl->setText(QCoreApplication::translate("AddJournalRowDialog", "Route ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddJournalRowDialog: public Ui_AddJournalRowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDJOURNALROWDIALOG_H
