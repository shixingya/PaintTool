#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../RecordTool/SoundRecordWgt.h"
#include "GSPaintWgt.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wgt =new GSPaintWgt();

    wgt->openFile("E:\\genshuixue.bmp");
    ui->verticalLayout->addWidget(wgt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pushButton_4_clicked()
//{
//    wgt->ZoomIn();
//}

//void MainWindow::on_pushButton_clicked()
//{
//    wgt->ZoomOut();
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    wgt->Rotate(90);
//}

//void MainWindow::on_pushButton_3_clicked()
//{
//    wgt->Rotate(-90);
//}


void MainWindow::on_pushButton_5_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("选择图像"),"",tr("Images (*.png *.bmp *.jpg)"));
    if(filename.isEmpty())
        return;
    else
    {
         wgt->openFile(filename);
    }
}
