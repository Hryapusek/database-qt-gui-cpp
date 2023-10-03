/********************************************************************************
** Form generated from reading UI file 'removeJournalRowDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEJOURNALROWDIALOG_H
#define UI_REMOVEJOURNALROWDIALOG_H

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

class Ui_RemoveJournalRowDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QLabel *idLbl;
    QLineEdit *idLine;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *RemoveJournalRowDialog)
    {
        if (RemoveJournalRowDialog->objectName().isEmpty())
            RemoveJournalRowDialog->setObjectName(QString::fromUtf8("RemoveJournalRowDialog"));
        RemoveJournalRowDialog->resize(184, 106);
        verticalLayout = new QVBoxLayout(RemoveJournalRowDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        idLbl = new QLabel(RemoveJournalRowDialog);
        idLbl->setObjectName(QString::fromUtf8("idLbl"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(idLbl->sizePolicy().hasHeightForWidth());
        idLbl->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(idLbl);

        idLine = new QLineEdit(RemoveJournalRowDialog);
        idLine->setObjectName(QString::fromUtf8("idLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(idLine->sizePolicy().hasHeightForWidth());
        idLine->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(idLine);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(RemoveJournalRowDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(RemoveJournalRowDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RemoveJournalRowDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RemoveJournalRowDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RemoveJournalRowDialog);
    } // setupUi

    void retranslateUi(QDialog *RemoveJournalRowDialog)
    {
        RemoveJournalRowDialog->setWindowTitle(QCoreApplication::translate("RemoveJournalRowDialog", "Remove Journa lRow", nullptr));
        idLbl->setText(QCoreApplication::translate("RemoveJournalRowDialog", "ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoveJournalRowDialog: public Ui_RemoveJournalRowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEJOURNALROWDIALOG_H
