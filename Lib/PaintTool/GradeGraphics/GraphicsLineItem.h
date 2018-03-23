#pragma once
#include "prePaintToolHeader.h"
#include "GraphicsRectItem.h"

class GraphicsLineItem : public QGraphicsLineItem
{
public:
    GraphicsLineItem(const QLineF &line,QGraphicsItem * parent=0 );
    void setBorderColor(QColor color)
    {
        QPen pen =this->pen();
        pen.setColor(color);
        setPen(pen);
    }
};
