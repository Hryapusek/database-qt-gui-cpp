/********************************************************************************
** Form generated from reading UI file 'addPersonDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSONDIALOG_H
#define UI_ADDPERSONDIALOG_H

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

class Ui_AddPersonDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *firstNameLbl;
    QLineEdit *firstNameLine;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lastNameLbl;
    QLineEdit *lastNameLine;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *fatherNameLbl;
    QLineEdit *fatherNameLine;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddPersonDialog)
    {
        if (AddPersonDialog->objectName().isEmpty())
            AddPersonDialog->setObjectName(QString::fromUtf8("AddPersonDialog"));
        AddPersonDialog->setWindowModality(Qt::NonModal);
        AddPersonDialog->resize(217, 168);
        verticalLayout = new QVBoxLayout(AddPersonDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        firstNameLbl = new QLabel(AddPersonDialog);
        firstNameLbl->setObjectName(QString::fromUtf8("firstNameLbl"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(firstNameLbl->sizePolicy().hasHeightForWidth());
        firstNameLbl->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(firstNameLbl);

        firstNameLine = new QLineEdit(AddPersonDialog);
        firstNameLine->setObjectName(QString::fromUtf8("firstNameLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(firstNameLine->sizePolicy().hasHeightForWidth());
        firstNameLine->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(firstNameLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        lastNameLbl = new QLabel(AddPersonDialog);
        lastNameLbl->setObjectName(QString::fromUtf8("lastNameLbl"));
        sizePolicy.setHeightForWidth(lastNameLbl->sizePolicy().hasHeightForWidth());
        lastNameLbl->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lastNameLbl);

        lastNameLine = new QLineEdit(AddPersonDialog);
        lastNameLine->setObjectName(QString::fromUtf8("lastNameLine"));
        sizePolicy1.setHeightForWidth(lastNameLine->sizePolicy().hasHeightForWidth());
        lastNameLine->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lastNameLine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        fatherNameLbl = new QLabel(AddPersonDialog);
        fatherNameLbl->setObjectName(QString::fromUtf8("fatherNameLbl"));
        sizePolicy.setHeightForWidth(fatherNameLbl->sizePolicy().hasHeightForWidth());
        fatherNameLbl->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(fatherNameLbl);

        fatherNameLine = new QLineEdit(AddPersonDialog);
        fatherNameLine->setObjectName(QString::fromUtf8("fatherNameLine"));
        sizePolicy1.setHeightForWidth(fatherNameLine->sizePolicy().hasHeightForWidth());
        fatherNameLine->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(fatherNameLine);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(AddPersonDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(AddPersonDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddPersonDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddPersonDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddPersonDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPersonDialog)
    {
        AddPersonDialog->setWindowTitle(QCoreApplication::translate("AddPersonDialog", "Add Person", nullptr));
        firstNameLbl->setText(QCoreApplication::translate("AddPersonDialog", "First name", nullptr));
        lastNameLbl->setText(QCoreApplication::translate("AddPersonDialog", "Last name", nullptr));
        fatherNameLbl->setText(QCoreApplication::translate("AddPersonDialog", "Father name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPersonDialog: public Ui_AddPersonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSONDIALOG_H
