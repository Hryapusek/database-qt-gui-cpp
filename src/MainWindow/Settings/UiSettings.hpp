/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *databaseLbl;
    QLineEdit *databaseLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *usernameLbl;
    QLineEdit *usernameLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passwordLbl;
    QLineEdit *passwordLine;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *applyBtn;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->setWindowModality(Qt::ApplicationModal);
        SettingsDialog->resize(272, 194);
        verticalLayout = new QVBoxLayout(SettingsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        databaseLbl = new QLabel(SettingsDialog);
        databaseLbl->setObjectName(QString::fromUtf8("databaseLbl"));

        horizontalLayout->addWidget(databaseLbl);

        databaseLine = new QLineEdit(SettingsDialog);
        databaseLine->setObjectName(QString::fromUtf8("databaseLine"));

        horizontalLayout->addWidget(databaseLine);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        usernameLbl = new QLabel(SettingsDialog);
        usernameLbl->setObjectName(QString::fromUtf8("usernameLbl"));

        horizontalLayout_2->addWidget(usernameLbl);

        usernameLine = new QLineEdit(SettingsDialog);
        usernameLine->setObjectName(QString::fromUtf8("usernameLine"));

        horizontalLayout_2->addWidget(usernameLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        passwordLbl = new QLabel(SettingsDialog);
        passwordLbl->setObjectName(QString::fromUtf8("passwordLbl"));

        horizontalLayout_3->addWidget(passwordLbl);

        passwordLine = new QLineEdit(SettingsDialog);
        passwordLine->setObjectName(QString::fromUtf8("passwordLine"));

        horizontalLayout_3->addWidget(passwordLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        applyBtn = new QPushButton(SettingsDialog);
        applyBtn->setObjectName(QString::fromUtf8("applyBtn"));

        horizontalLayout_4->addWidget(applyBtn);

        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Settings", nullptr));
        databaseLbl->setText(QCoreApplication::translate("SettingsDialog", "Database", nullptr));
        usernameLbl->setText(QCoreApplication::translate("SettingsDialog", "Username", nullptr));
        passwordLbl->setText(QCoreApplication::translate("SettingsDialog", "Password", nullptr));
        applyBtn->setText(QCoreApplication::translate("SettingsDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
