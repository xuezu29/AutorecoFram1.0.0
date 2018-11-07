/********************************************************************************
** Form generated from reading UI file 'AutorecoFram.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORECOFRAM_H
#define UI_AUTORECOFRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutorecoFramClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *configTab;
    QWidget *testTab;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AutorecoFramClass)
    {
        if (AutorecoFramClass->objectName().isEmpty())
            AutorecoFramClass->setObjectName(QStringLiteral("AutorecoFramClass"));
        AutorecoFramClass->resize(550, 379);
        centralWidget = new QWidget(AutorecoFramClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        configTab = new QWidget();
        configTab->setObjectName(QStringLiteral("configTab"));
        tabWidget->addTab(configTab, QString());
        testTab = new QWidget();
        testTab->setObjectName(QStringLiteral("testTab"));
        verticalLayout = new QVBoxLayout(testTab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(testTab);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        tabWidget->addTab(testTab, QString());

        verticalLayout_2->addWidget(tabWidget);

        AutorecoFramClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AutorecoFramClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AutorecoFramClass->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget, tableWidget);

        retranslateUi(AutorecoFramClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AutorecoFramClass);
    } // setupUi

    void retranslateUi(QMainWindow *AutorecoFramClass)
    {
        AutorecoFramClass->setWindowTitle(QApplication::translate("AutorecoFramClass", "AutorecoFram", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(configTab), QApplication::translate("AutorecoFramClass", "\350\260\203\350\257\225\345\217\202\346\225\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(testTab), QApplication::translate("AutorecoFramClass", "\345\215\225\346\234\272\346\265\213\350\257\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AutorecoFramClass: public Ui_AutorecoFramClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTORECOFRAM_H
