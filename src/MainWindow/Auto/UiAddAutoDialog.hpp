/********************************************************************************
** Form generated from reading UI file 'addAutoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAUTODIALOG_H
#define UI_ADDAUTODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddAutoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *numLbl;
    QLineEdit *numLine;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *colorLbl;
    QLineEdit *colorLine;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *markLbl;
    QLineEdit *markLine;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QLabel *personIdLbl;
    QLineEdit *personIdLine;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddAutoDialog)
    {
        if (AddAutoDialog->objectName().isEmpty())
            AddAutoDialog->setObjectName(QString::fromUtf8("AddAutoDialog"));
        AddAutoDialog->resize(272, 207);
        verticalLayout = new QVBoxLayout(AddAutoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        numLbl = new QLabel(AddAutoDialog);
        numLbl->setObjectName(QString::fromUtf8("numLbl"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numLbl->sizePolicy().hasHeightForWidth());
        numLbl->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(numLbl);

        numLine = new QLineEdit(AddAutoDialog);
        numLine->setObjectName(QString::fromUtf8("numLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(numLine->sizePolicy().hasHeightForWidth());
        numLine->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(numLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        colorLbl = new QLabel(AddAutoDialog);
        colorLbl->setObjectName(QString::fromUtf8("colorLbl"));
        sizePolicy.setHeightForWidth(colorLbl->sizePolicy().hasHeightForWidth());
        colorLbl->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(colorLbl);

        colorLine = new QLineEdit(AddAutoDialog);
        colorLine->setObjectName(QString::fromUtf8("colorLine"));
        sizePolicy1.setHeightForWidth(colorLine->sizePolicy().hasHeightForWidth());
        colorLine->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(colorLine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        markLbl = new QLabel(AddAutoDialog);
        markLbl->setObjectName(QString::fromUtf8("markLbl"));
        sizePolicy.setHeightForWidth(markLbl->sizePolicy().hasHeightForWidth());
        markLbl->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(markLbl);

        markLine = new QLineEdit(AddAutoDialog);
        markLine->setObjectName(QString::fromUtf8("markLine"));
        sizePolicy1.setHeightForWidth(markLine->sizePolicy().hasHeightForWidth());
        markLine->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(markLine);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        personIdLbl = new QLabel(AddAutoDialog);
        personIdLbl->setObjectName(QString::fromUtf8("personIdLbl"));
        sizePolicy.setHeightForWidth(personIdLbl->sizePolicy().hasHeightForWidth());
        personIdLbl->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(personIdLbl);

        personIdLine = new QLineEdit(AddAutoDialog);
        personIdLine->setObjectName(QString::fromUtf8("personIdLine"));
        sizePolicy1.setHeightForWidth(personIdLine->sizePolicy().hasHeightForWidth());
        personIdLine->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(personIdLine);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        pushButton = new QPushButton(AddAutoDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        buttonBox = new QDialogButtonBox(AddAutoDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(AddAutoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddAutoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddAutoDialog, SLOT(reject()));
        QObject::connect(pushButton, SIGNAL(clicked()), personIdLine, SLOT(clear()));
        QObject::connect(pushButton, SIGNAL(clicked()), markLine, SLOT(clear()));
        QObject::connect(pushButton, SIGNAL(clicked()), colorLine, SLOT(clear()));
        QObject::connect(pushButton, SIGNAL(clicked()), numLine, SLOT(clear()));

        QMetaObject::connectSlotsByName(AddAutoDialog);
    } // setupUi

    void retranslateUi(QDialog *AddAutoDialog)
    {
        AddAutoDialog->setWindowTitle(QCoreApplication::translate("AddAutoDialog", "Add Auto", nullptr));
        numLbl->setText(QCoreApplication::translate("AddAutoDialog", "Num", nullptr));
        colorLbl->setText(QCoreApplication::translate("AddAutoDialog", "Color", nullptr));
        markLbl->setText(QCoreApplication::translate("AddAutoDialog", "Mark", nullptr));
        personIdLbl->setText(QCoreApplication::translate("AddAutoDialog", "Person ID", nullptr));
        pushButton->setText(QCoreApplication::translate("AddAutoDialog", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddAutoDialog: public Ui_AddAutoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAUTODIALOG_H
