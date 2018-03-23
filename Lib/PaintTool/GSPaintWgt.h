#pragma once
#include "prePaintToolHeader.h"

#include "painttool_global.h"
#include <QtWidgets>
#include "GradeGraphics/MainPaintScene.h"
namespace Ui {
class GSPaintWgt;
}

class PAINTTOOLSHARED_EXPORT GSPaintWgt : public QWidget
{
    Q_OBJECT

public:
    explicit GSPaintWgt(QWidget *parent = 0);
    ~GSPaintWgt();

    void openFile(QString path);
    //设置本地保存目录
    void set_local_save_dir(QString dir);

    void setViewOnly();
    bool saveCurrentImage(QString localPath); //保存当前图片批改截图；
    QRect getRect();
    void drawImg(QString path);
    void ZoomIn();
    void ZoomOut();
    void Rotate(int);
signals:
    void uploadAssemblageItems(QString);
    void changeCurrentShape(DrawBaseShape shape);
    void openPicSelectDlg();
private slots:
    void on_pbt_pen_clicked();
    void on_pbt_Arrow_clicked();
    void on_pbt_line_clicked();
    void on_pbt_rect_clicked();
    void on_pbt_triangle_clicked();
    void on_pbt_circle_clicked();
    void on_pbt_picture_clicked();
    void on_pbt_red_clicked();
    void on_pbt_green_clicked();
    void on_pbt_black_clicked();
    void on_pbt_select_clicked();
    void on_pbt_text_clicked();

    void on_pbt_Rubber_clicked();

private:
    Ui::GSPaintWgt *ui;
    MainPaintScene *_mainPaintScene =nullptr;
    QPushButton * _lastPushButton=nullptr;
    QString _lastButtonStyleSheet;

    void initToolBar();
    void onChangeGradeStyle(QPushButton* pushbutton,DrawBaseShape shape);
};
