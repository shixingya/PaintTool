#pragma once
#include "prePaintToolHeader.h"

#include "drawtool.h"
#include "GraphicsTextItem.h"
#include "GraphicsLineItem.h"

class DrawTool;

class MainPaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MainPaintScene(QObject *parent = 0);
    ~MainPaintScene();

    void mouseEvent(QGraphicsSceneMouseEvent *mouseEvent );
    void InsertPicture(QString path);
    void SetBackGroundImage(QString path);

    void setCurrentColor(QColor);
    void setLastRotate(qreal);

    qreal getLastRotation()
    {
        return _lastRotate;
    }
    qreal getScaleValue();
public slots:
    void SetCurrentShape(DrawBaseShape shape);
    void editorLostFocus(GraphicsTextItem *item)
    {
        QTextCursor cursor = item->textCursor();
        cursor.clearSelection();
        item->setTextCursor(cursor);

        if (item->toPlainText().isEmpty()) {
            removeItem(item);
            item->deleteLater();
        }
    }

signals:
    void itemSelected(QGraphicsItem *item);
    void textInserted(GraphicsTextItem *item);

private:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void updateSelectedItemsColor();


    qreal _lastRotate=0; //初始化转角为0;
    QColor _color=QColor(255,88,80,255);
    GraphicsTextItem *textItem=nullptr;
};
