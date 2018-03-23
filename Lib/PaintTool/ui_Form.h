/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QPushButton *pbt_pen;
    QPushButton *obt_text;
    QPushButton *pbt_Arrow;
    QPushButton *pbt_line;
    QPushButton *pbt_rect;
    QPushButton *pbt_triangle;
    QPushButton *pbt_round;
    QPushButton *pbt_picture;
    QPushButton *pbt_red;
    QPushButton *pbt_green;
    QPushButton *pbt_black;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QLatin1String("Form"));
        Form->resize(686, 603);
        Form->setStyleSheet(QLatin1String("background-color: rgb(109, 109, 110);\n"
"border: 1px solid #6D6D6E;\n"
"background: #343434;"));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QLatin1String("horizontalLayout"));
        graphicsView = new QGraphicsView(Form);
        graphicsView->setObjectName(QLatin1String("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QLatin1String("verticalLayout"));
        pbt_pen = new QPushButton(Form);
        pbt_pen->setObjectName(QLatin1String("pbt_pen"));
        pbt_pen->setMinimumSize(QSize(47, 47));
        pbt_pen->setMaximumSize(QSize(47, 47));
        QIcon icon;
        icon.addFile(QLatin1String(":/qrc/Resources/ic_sidebar_pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_pen->setIcon(icon);

        verticalLayout->addWidget(pbt_pen);

        obt_text = new QPushButton(Form);
        obt_text->setObjectName(QLatin1String("obt_text"));
        obt_text->setMinimumSize(QSize(47, 47));
        obt_text->setMaximumSize(QSize(47, 47));
        QIcon icon1;
        icon1.addFile(QLatin1String(":/qrc/Resources/ic_sidebar_text.png"), QSize(), QIcon::Normal, QIcon::Off);
        obt_text->setIcon(icon1);

        verticalLayout->addWidget(obt_text);

        pbt_Arrow = new QPushButton(Form);
        pbt_Arrow->setObjectName(QLatin1String("pbt_Arrow"));
        pbt_Arrow->setMinimumSize(QSize(47, 47));
        pbt_Arrow->setMaximumSize(QSize(47, 47));
        QIcon icon2;
        icon2.addFile(QLatin1String(":/qrc/Resources/ic_sidebar_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_Arrow->setIcon(icon2);

        verticalLayout->addWidget(pbt_Arrow);

        pbt_line = new QPushButton(Form);
        pbt_line->setObjectName(QLatin1String("pbt_line"));
        pbt_line->setMinimumSize(QSize(47, 47));
        pbt_line->setMaximumSize(QSize(47, 47));
        QIcon icon3;
        icon3.addFile(QLatin1String(":/qrc/Resources/ic_drawing_beeline.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_line->setIcon(icon3);

        verticalLayout->addWidget(pbt_line);

        pbt_rect = new QPushButton(Form);
        pbt_rect->setObjectName(QLatin1String("pbt_rect"));
        pbt_rect->setMinimumSize(QSize(47, 47));
        pbt_rect->setMaximumSize(QSize(47, 47));
        QIcon icon4;
        icon4.addFile(QLatin1String(":/qrc/Resources/ic_drawing_square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_rect->setIcon(icon4);

        verticalLayout->addWidget(pbt_rect);

        pbt_triangle = new QPushButton(Form);
        pbt_triangle->setObjectName(QLatin1String("pbt_triangle"));
        pbt_triangle->setMinimumSize(QSize(47, 47));
        pbt_triangle->setMaximumSize(QSize(47, 47));
        QIcon icon5;
        icon5.addFile(QLatin1String(":/qrc/Resources/ic_drawing_triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_triangle->setIcon(icon5);

        verticalLayout->addWidget(pbt_triangle);

        pbt_round = new QPushButton(Form);
        pbt_round->setObjectName(QLatin1String("pbt_round"));
        pbt_round->setMinimumSize(QSize(47, 47));
        pbt_round->setMaximumSize(QSize(47, 47));
        QIcon icon6;
        icon6.addFile(QLatin1String(":/qrc/Resources/ic_drawing_round.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_round->setIcon(icon6);

        verticalLayout->addWidget(pbt_round);

        pbt_picture = new QPushButton(Form);
        pbt_picture->setObjectName(QLatin1String("pbt_picture"));
        pbt_picture->setMinimumSize(QSize(47, 47));
        pbt_picture->setMaximumSize(QSize(47, 47));
        QIcon icon7;
        icon7.addFile(QLatin1String(":/qrc/Resources/ic_sidebar_image.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_picture->setIcon(icon7);

        verticalLayout->addWidget(pbt_picture);

        pbt_red = new QPushButton(Form);
        pbt_red->setObjectName(QLatin1String("pbt_red"));
        pbt_red->setMinimumSize(QSize(47, 47));
        pbt_red->setMaximumSize(QSize(47, 47));
        QIcon icon8;
        icon8.addFile(QLatin1String(":/qrc/Resources/ic_sidebar_color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_red->setIcon(icon8);

        verticalLayout->addWidget(pbt_red);

        pbt_green = new QPushButton(Form);
        pbt_green->setObjectName(QLatin1String("pbt_green"));
        pbt_green->setMinimumSize(QSize(47, 47));
        pbt_green->setMaximumSize(QSize(47, 47));
        QIcon icon9;
        icon9.addFile(QLatin1String(":/qrc/Resources/green Selected.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_green->setIcon(icon9);

        verticalLayout->addWidget(pbt_green);

        pbt_black = new QPushButton(Form);
        pbt_black->setObjectName(QLatin1String("pbt_black"));
        pbt_black->setMinimumSize(QSize(47, 47));
        pbt_black->setMaximumSize(QSize(47, 47));
        QIcon icon10;
        icon10.addFile(QLatin1String(":/qrc/Resources/black Selected.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_black->setIcon(icon10);

        verticalLayout->addWidget(pbt_black);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        pbt_pen->setText(QString());
        obt_text->setText(QString());
        pbt_Arrow->setText(QString());
        pbt_line->setText(QString());
        pbt_rect->setText(QString());
        pbt_triangle->setText(QString());
        pbt_round->setText(QString());
        pbt_picture->setText(QString());
        pbt_red->setText(QString());
        pbt_green->setText(QString());
        pbt_black->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
