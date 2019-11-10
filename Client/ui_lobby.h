/********************************************************************************
** Form generated from reading UI file 'lobby.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBY_H
#define UI_LOBBY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lobby
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *nombre;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *cantJug;
    QPushButton *crear;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pista1;
    QPushButton *pista2;
    QPushButton *pista3;
    QPushButton *pista4;
    QPushButton *pista5;

    void setupUi(QWidget *Lobby)
    {
        if (Lobby->objectName().isEmpty())
            Lobby->setObjectName(QStringLiteral("Lobby"));
        Lobby->resize(583, 463);
        widget = new QWidget(Lobby);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 40, 467, 52));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        nombre = new QLineEdit(widget);
        nombre->setObjectName(QStringLiteral("nombre"));

        verticalLayout_2->addWidget(nombre);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        cantJug = new QLineEdit(widget);
        cantJug->setObjectName(QStringLiteral("cantJug"));

        verticalLayout->addWidget(cantJug);


        horizontalLayout->addLayout(verticalLayout);

        crear = new QPushButton(widget);
        crear->setObjectName(QStringLiteral("crear"));

        horizontalLayout->addWidget(crear);

        widget1 = new QWidget(Lobby);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(60, 170, 431, 271));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pista1 = new QPushButton(widget1);
        pista1->setObjectName(QStringLiteral("pista1"));

        verticalLayout_3->addWidget(pista1);

        pista2 = new QPushButton(widget1);
        pista2->setObjectName(QStringLiteral("pista2"));

        verticalLayout_3->addWidget(pista2);

        pista3 = new QPushButton(widget1);
        pista3->setObjectName(QStringLiteral("pista3"));

        verticalLayout_3->addWidget(pista3);

        pista4 = new QPushButton(widget1);
        pista4->setObjectName(QStringLiteral("pista4"));

        verticalLayout_3->addWidget(pista4);

        pista5 = new QPushButton(widget1);
        pista5->setObjectName(QStringLiteral("pista5"));

        verticalLayout_3->addWidget(pista5);


        horizontalLayout_2->addLayout(verticalLayout_3);


        retranslateUi(Lobby);

        QMetaObject::connectSlotsByName(Lobby);
    } // setupUi

    void retranslateUi(QWidget *Lobby)
    {
        Lobby->setWindowTitle(QApplication::translate("Lobby", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Lobby", "Nombre", Q_NULLPTR));
        label_2->setText(QApplication::translate("Lobby", "Cantidad maxima de jugadores", Q_NULLPTR));
        crear->setText(QApplication::translate("Lobby", "Crear Partida", Q_NULLPTR));
        label_3->setText(QApplication::translate("Lobby", "Pistas:", Q_NULLPTR));
        pista1->setText(QApplication::translate("Lobby", "Vacio", Q_NULLPTR));
        pista2->setText(QApplication::translate("Lobby", "Vacio", Q_NULLPTR));
        pista3->setText(QApplication::translate("Lobby", "Vacio", Q_NULLPTR));
        pista4->setText(QApplication::translate("Lobby", "Vacio", Q_NULLPTR));
        pista5->setText(QApplication::translate("Lobby", "Vacio", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lobby: public Ui_Lobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBY_H
