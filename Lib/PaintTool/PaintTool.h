#ifndef PAINTTOOL_H
#define PAINTTOOL_H

#include "painttool_global.h"
#include <QtWidgets>
namespace Ui {
class Form;
}
class PAINTTOOLSHARED_EXPORT PaintTool: public QWidget
{
    Q_OBJECT

public:
    explicit PaintTool(QWidget *parent = 0);
    ~PaintTool();

private:
    Ui::Form *ui;
};

#endif // PAINTTOOL_H
