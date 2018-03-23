#include "GSPaintWgt.h"
#include "ui_GSPaintWgt.h"

GSPaintWgt::GSPaintWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GSPaintWgt)
{
    ui->setupUi(this);
}

GSPaintWgt::~GSPaintWgt()
{
    delete ui;
}
void GSPaintWgt::openFile(QString localPath)
{
    _mainPaintScene =new MainPaintScene(ui->graphicsView);
    ui->graphicsView->setScene(_mainPaintScene);
    ui->graphicsView->centerOn(0,0);
    _mainPaintScene->SetBackGroundImage(localPath);
    connect(this, SIGNAL(changeCurrentShape(DrawBaseShape)),
            _mainPaintScene, SLOT(SetCurrentShape(DrawBaseShape)));

    connect(ui->graphicsView,SIGNAL(uploadAssemblageItems(QString)),
            this,SIGNAL(uploadAssemblageItems(QString)));
    initToolBar();
}
void GSPaintWgt::set_local_save_dir(QString dir)
{
    ui->graphicsView->set_local_save_dir(dir);
}
QRect GSPaintWgt::getRect()
{
    return ui->graphicsView->rect();
}
void GSPaintWgt::onChangeGradeStyle(QPushButton* pushbutton,DrawBaseShape shape)
{
    if(_lastPushButton)
        _lastPushButton->setStyleSheet(_lastButtonStyleSheet);
    _lastPushButton =pushbutton;
    _lastButtonStyleSheet= pushbutton->styleSheet();
    pushbutton->setStyleSheet("background-color: #000000;");
    emit changeCurrentShape(shape);
}
void GSPaintWgt::setViewOnly()
{
    ui->toolbarWgt->hide();
    onChangeGradeStyle(ui->pbt_pen,DrawBaseShape::None);
}
bool GSPaintWgt::saveCurrentImage(QString localPath)
{
    QRect rect =ui->graphicsView->rect();
    QImage image(rect.width(),rect.height(),QImage::Format_ARGB32);
    image.fill(Qt::transparent);//用透明色填充

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->render(&painter);
    return image.save(localPath);
}

void GSPaintWgt::on_pbt_pen_clicked()
{
    onChangeGradeStyle(ui->pbt_pen,DrawBaseShape::penPath);
}
void GSPaintWgt::on_pbt_Arrow_clicked()
{
    onChangeGradeStyle(ui->pbt_Arrow,DrawBaseShape::arrowLine);
    initToolBar(); //将所有该隐藏的按钮隐藏；
    ui->pbt_line->show();
}

void GSPaintWgt::on_pbt_line_clicked()
{
    onChangeGradeStyle(ui->pbt_line,DrawBaseShape::line);
}

void GSPaintWgt::on_pbt_rect_clicked()
{
    onChangeGradeStyle(ui->pbt_rect,DrawBaseShape::rectangle);
    initToolBar(); //将所有该隐藏的按钮隐藏；
    ui->pbt_circle->show();
    ui->pbt_triangle->show();

}

void GSPaintWgt::on_pbt_triangle_clicked()
{
    onChangeGradeStyle(ui->pbt_triangle,DrawBaseShape::triangle);
}

void GSPaintWgt::on_pbt_circle_clicked()
{
    onChangeGradeStyle(ui->pbt_circle,DrawBaseShape::ellipse);
}
void GSPaintWgt::Rotate(int val)
{
    _mainPaintScene->setLastRotate(val);
    ui->graphicsView->rotate(val);
}
void GSPaintWgt::ZoomOut()
{
    ui->graphicsView->ZoomOut();
}
void GSPaintWgt::ZoomIn()
{
    ui->graphicsView->ZoomIn();
}
void GSPaintWgt::drawImg(QString filepath)
{
    MainPaintScene * scene =(MainPaintScene *)(ui->graphicsView->scene());
    if(scene)
        scene->InsertPicture(filepath);
}
void GSPaintWgt::on_pbt_picture_clicked()
{

    emit openPicSelectDlg();
    onChangeGradeStyle(ui->pbt_picture,DrawBaseShape::image);
}

void GSPaintWgt::on_pbt_red_clicked()
{
    MainPaintScene * scene =(MainPaintScene *)(ui->graphicsView->scene());
    if(scene)
        scene->setCurrentColor(QColor(255,88,80,255)); //红色

    initToolBar();
    ui->pbt_green->show();
    ui->pbt_black->show();
}

void GSPaintWgt::on_pbt_green_clicked()
{
    MainPaintScene * scene =(MainPaintScene *)(ui->graphicsView->scene());
    if(scene)
        scene->setCurrentColor(QColor(29,185,84,255)); //绿色
}
void GSPaintWgt::initToolBar()
{
    ui->pbt_black->hide();
    ui->pbt_green->hide();
    ui->pbt_line->hide();
    ui->pbt_circle->hide();
    ui->pbt_triangle->hide();
}
void GSPaintWgt::on_pbt_black_clicked()
{
    MainPaintScene * scene =(MainPaintScene *)(ui->graphicsView->scene());
    if(scene)
        scene->setCurrentColor(QColor(51,51,51,255)); //蓝色-》改为黑色
}

void GSPaintWgt::on_pbt_select_clicked()
{
    onChangeGradeStyle(ui->pbt_select,DrawBaseShape::selection);
}

void GSPaintWgt::on_pbt_text_clicked()
{
    onChangeGradeStyle(ui->pbt_text,DrawBaseShape::text);
}

//橡皮插
void GSPaintWgt::on_pbt_Rubber_clicked()
{
    onChangeGradeStyle(ui->pbt_Rubber,DrawBaseShape::rubber);
}
