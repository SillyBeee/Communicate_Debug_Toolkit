/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WIDGET2_H
#define WIDGET2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *down_type_editor;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QLineEdit *down_find_bool_editor;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QLineEdit *down_yaw_editor;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QLineEdit *down_pitch_editor;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *up_type_editor;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *up_yaw_editor;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *up_pitch_editor;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *up_enemy_color_editor;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *up_mode_editor;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *up_rune_flag_editor;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(679, 474);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 420, 100, 27));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 10, 211, 20));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 70, 121, 19));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 80, 121, 19));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(450, 70, 121, 19));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 105, 242, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        down_type_editor = new QLineEdit(layoutWidget);
        down_type_editor->setObjectName(QString::fromUtf8("down_type_editor"));

        horizontalLayout->addWidget(down_type_editor);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        down_find_bool_editor = new QLineEdit(layoutWidget);
        down_find_bool_editor->setObjectName(QString::fromUtf8("down_find_bool_editor"));

        horizontalLayout_2->addWidget(down_find_bool_editor);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        down_yaw_editor = new QLineEdit(layoutWidget);
        down_yaw_editor->setObjectName(QString::fromUtf8("down_yaw_editor"));

        horizontalLayout_3->addWidget(down_yaw_editor);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_4->addWidget(label_14);

        down_pitch_editor = new QLineEdit(layoutWidget);
        down_pitch_editor->setObjectName(QString::fromUtf8("down_pitch_editor"));

        horizontalLayout_4->addWidget(down_pitch_editor);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(340, 110, 321, 261));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        up_type_editor = new QLineEdit(layoutWidget1);
        up_type_editor->setObjectName(QString::fromUtf8("up_type_editor"));

        horizontalLayout_5->addWidget(up_type_editor);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        up_yaw_editor = new QLineEdit(layoutWidget1);
        up_yaw_editor->setObjectName(QString::fromUtf8("up_yaw_editor"));

        horizontalLayout_6->addWidget(up_yaw_editor);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        up_pitch_editor = new QLineEdit(layoutWidget1);
        up_pitch_editor->setObjectName(QString::fromUtf8("up_pitch_editor"));

        horizontalLayout_7->addWidget(up_pitch_editor);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        up_enemy_color_editor = new QLineEdit(layoutWidget1);
        up_enemy_color_editor->setObjectName(QString::fromUtf8("up_enemy_color_editor"));

        horizontalLayout_8->addWidget(up_enemy_color_editor);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        up_mode_editor = new QLineEdit(layoutWidget1);
        up_mode_editor->setObjectName(QString::fromUtf8("up_mode_editor"));

        horizontalLayout_9->addWidget(up_mode_editor);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        up_rune_flag_editor = new QLineEdit(layoutWidget1);
        up_rune_flag_editor->setObjectName(QString::fromUtf8("up_rune_flag_editor"));

        horizontalLayout_10->addWidget(up_rune_flag_editor);


        verticalLayout_2->addLayout(horizontalLayout_10);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Refresh", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Communicate\350\260\203\350\257\225\345\267\245\345\205\267", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("Widget", "\350\207\252\347\236\204\346\225\260\346\215\256\345\217\215\351\246\210", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\350\207\252\347\236\204\344\272\221\345\217\260\346\216\247\345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "type", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "find_bool", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "yaw", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "pitch", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "type", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "yaw", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "pitch", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "enemy_team_color", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "mode", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "rune_flag", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WIDGET2_H
