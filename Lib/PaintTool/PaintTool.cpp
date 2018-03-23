#include "PaintTool.h"
#include "ui_Form.h"

#include <QtWidgets>
PaintTool::PaintTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}
PaintTool::~PaintTool()
{
    delete ui;
}
