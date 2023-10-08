/********************************************************************************
** Form generated from reading UI file 'addRouteDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDROUTEDIALOG_H
#define UI_ADDROUTEDIALOG_H

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

class Ui_AddRouteDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *nameLbl;
    QLineEdit *nameLine;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddRouteDialog)
    {
        if (AddRouteDialog->objectName().isEmpty())
            AddRouteDialog->setObjectName(QString::fromUtf8("AddRouteDialog"));
        AddRouteDialog->resize(272, 110);
        verticalLayout = new QVBoxLayout(AddRouteDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        nameLbl = new QLabel(AddRouteDialog);
        nameLbl->setObjectName(QString::fromUtf8("nameLbl"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameLbl->sizePolicy().hasHeightForWidth());
        nameLbl->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(nameLbl);

        nameLine = new QLineEdit(AddRouteDialog);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameLine->sizePolicy().hasHeightForWidth());
        nameLine->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(nameLine);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        pushButton = new QPushButton(AddRouteDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        buttonBox = new QDialogButtonBox(AddRouteDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(AddRouteDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddRouteDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddRouteDialog, SLOT(reject()));
        QObject::connect(pushButton, SIGNAL(clicked()), nameLine, SLOT(clear()));

        QMetaObject::connectSlotsByName(AddRouteDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRouteDialog)
    {
        AddRouteDialog->setWindowTitle(QCoreApplication::translate("AddRouteDialog", "Add Route", nullptr));
        nameLbl->setText(QCoreApplication::translate("AddRouteDialog", "Name", nullptr));
        pushButton->setText(QCoreApplication::translate("AddRouteDialog", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddRouteDialog: public Ui_AddRouteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDROUTEDIALOG_H
