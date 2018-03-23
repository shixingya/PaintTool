#include "MainPaintScene.h"
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsRectItem>
#include <QDebug>
#include "PaintView.h"
const double initWidth =700.0;
const double initHeight =663.0;
MainPaintScene::MainPaintScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

MainPaintScene::~MainPaintScene()
{
    SafeDelete (textItem);
}
qreal MainPaintScene::getScaleValue()
{
    qreal val=1;

    PaintView* view = (PaintView*)this->views().first();
    if(view)
    {
        val =view->getScaleValue();
    }
    return val;
}
void MainPaintScene::InsertPicture(QString path)
{
    DrawTool * tool =DrawTool::findTool(image);
    if (tool)
    {
        tool->setPicture(path);
    }
}

void MainPaintScene::mouseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    switch( mouseEvent->type() ){
    case QEvent::GraphicsSceneMousePress:
        QGraphicsScene::mousePressEvent(mouseEvent);
        break;
    case QEvent::GraphicsSceneMouseMove:
        QGraphicsScene::mouseMoveEvent(mouseEvent);
        break;
    case QEvent::GraphicsSceneMouseRelease:
        QGraphicsScene::mouseReleaseEvent(mouseEvent);
        break;
    }
}


void MainPaintScene::SetBackGroundImage(QString path)
{
    this->clear();
    //this->addRect(0,0,initWidth,initHeight,QPen(Qt::green),QBrush(Qt::red));
    QImage image =QImage(path);
    QPixmap pixmap =QPixmap::fromImage(image);
    QGraphicsPixmapItem* _backGroundItem= this->addPixmap(pixmap);

    if(pixmap.width()>pixmap.height())
    {
        //匹配宽度
        _backGroundItem->setScale( initWidth/pixmap.width() );
    }
    else//匹配高度
    {
        _backGroundItem->setScale( initHeight /pixmap.height() );
    }
    _backGroundItem->setPos(0,0);

}

void MainPaintScene::keyPressEvent(QKeyEvent *event)
{

    QList<QGraphicsItem *> selectItems =  selectedItems();
    switch (event->key())
    {
    case Qt::Key_Delete:
        if(selectItems.count()>0)
        {
            while(selectItems.count()>0)
            {
                QGraphicsItem * item =selectItems.last();
                removeItem(item);
                selectItems.pop_back();
            }
        }
        break;
    }
    return QGraphicsScene::keyPressEvent(event);

}

void MainPaintScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    DrawTool * tool =DrawTool::findTool( DrawTool::c_drawShape );
    if( DrawTool::c_drawShape  ==text) //文字独立出来
    {
        textItem = new GraphicsTextItem();
        QFont myFont =textItem->font();
        myFont.setWeight(QFont::Bold);
        myFont.setFamily("Microsoft YaHei UI");

        qreal Rot =_lastRotate;
        qreal val =getScaleValue();
        myFont.setPixelSize(14/val);
        qDebug()<<"Rot is "<<Rot;
        textItem->setRotation(0-Rot);
        textItem->setDefaultTextColor(_color);
        textItem->setFont(myFont);
        textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
        textItem->setZValue(1000.0);
        addItem(textItem);
        textItem->setDefaultTextColor(Qt::red);
        textItem->setPos(mouseEvent->scenePos());
        this->views().first()->setCursor(Qt::ArrowCursor);
    }
    else if (tool)
    {
        tool->mousePressEvent(mouseEvent,this);
    }

}
void MainPaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    DrawTool * tool = DrawTool::findTool( DrawTool::c_drawShape );
    if( DrawTool::c_drawShape  ==text) //文字独立出来
    {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
    else if(tool)
        tool->mouseMoveEvent(mouseEvent,this);


}

void MainPaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    DrawTool * tool =DrawTool::findTool( DrawTool::c_drawShape );
    if( DrawTool::c_drawShape  ==text) //文字独立出来
    {

    }
    else if ( tool )
        tool->mouseReleaseEvent(mouseEvent,this);
}
void MainPaintScene::updateSelectedItemsColor()
{
    int count =selectedItems().count();

    for(int i=0; i<count ;i++)
    {
        //矩形 三角形 圆
        GraphicsItem *item = qgraphicsitem_cast<GraphicsItem*>(selectedItems().at(i));
        if(item)
        {
            item->setBorderColor(_color);
            item->update();
            continue;
        }
        //直线
        GraphicsLineItem *itemLine = qgraphicsitem_cast<GraphicsLineItem*>(selectedItems().at(i));
        if(itemLine)
        {
            itemLine->setBorderColor(_color);
            itemLine->update();
            continue;
        }
        //箭头
        GraphicsArrowItem *itemArrow = qgraphicsitem_cast<GraphicsArrowItem*>(selectedItems().at(i));
        if(itemArrow)
        {
            itemArrow->setBorderColor(_color);
            itemArrow->update();
            continue;
        }
        //文字
        GraphicsTextItem *itemText = qgraphicsitem_cast<GraphicsTextItem*>(selectedItems().at(i));
        if(itemText)
        {
            itemText->setBorderColor(_color);
            itemText->update();
            continue;
        }
        //手写箭头
        QGraphicsItem *tmp =selectedItems().at(i);
        GraphicsArrowItem * tmpArrow =(GraphicsArrowItem *)tmp;
        if(tmpArrow)
        {
            tmpArrow->setBorderColor(_color);
            tmpArrow->update();
        }
        GraphicsPathItem *itemPath =  (GraphicsPathItem*)tmp;
        if(itemPath)
        {
            itemPath->setBorderColor(_color);
            itemPath->update();
        }
    }

    update();
}
void MainPaintScene::setLastRotate(qreal value)
{
    _lastRotate +=value;
    if(_lastRotate>360)
    {
        _lastRotate -=360;
    }
    else if(_lastRotate < -360)
    {
        _lastRotate +=360;
    }
}
void MainPaintScene::setCurrentColor(QColor color)
{
    DrawTool * tool =DrawTool::findTool( DrawTool::c_drawShape );
    if ( tool )
        tool->setCurrentColor(color);
    _color =color;

    //如果当前有选中的图元，需要将他们的颜色更新为最新颜色
    updateSelectedItemsColor();
}
void MainPaintScene::SetCurrentShape(DrawBaseShape shape)
{
    QCursor cursor =QCursor(Qt::ArrowCursor);
    if ( shape == selection)
        DrawTool::c_drawShape = selection;
    else if ( shape == rotation)
        DrawTool::c_drawShape = rotation;
    else if ( shape == line)
    {
        DrawTool::c_drawShape = line;
    }
    else if ( shape == rectangle)
        DrawTool::c_drawShape = rectangle;
    else if ( shape == ellipse)
        DrawTool::c_drawShape = ellipse;
    else if ( shape == penPath)
    {
        DrawTool::c_drawShape = penPath;
        QPixmap pixmap(":/qrc/Resources/pencilTool.png");
        //定义大小
        QSize picSize(16, 16);
        //缩放图片，按比例
        if(!pixmap.isNull())
        {
            QPixmap scaledPixmap = pixmap.scaled(picSize, Qt::KeepAspectRatio);
            //设置样式
            cursor =QCursor(scaledPixmap, -1, -1);
        }
    }
    else if ( shape == rubber)
    {
        DrawTool::c_drawShape = rubber;
        QPixmap pixmap(":/qrc/Resources/rubberArrow.png");
        //定义大小
        QSize picSize(16, 16);
        //缩放图片，按比例
        if(!pixmap.isNull())
        {
            QPixmap scaledPixmap = pixmap.scaled(picSize, Qt::KeepAspectRatio);
            //设置样式
            cursor =QCursor(scaledPixmap, -1, -1);
        }
    }
    else if ( shape == text)
    {
        DrawTool::c_drawShape = text;
    }
    else if ( shape == image)
        DrawTool::c_drawShape = image;
    else if ( shape == arrowLine)
        DrawTool::c_drawShape = arrowLine;
    else if ( shape == triangle)
        DrawTool::c_drawShape = triangle;
    else if ( shape == None)
        DrawTool::c_drawShape = None;

    if(this->views().count()>0)
        this->views().first()->setCursor(cursor);

    DrawTool * tool =DrawTool::findTool( DrawTool::c_drawShape );
    if ( tool !=nullptr)
        tool->setCurrentColor(_color);
}
