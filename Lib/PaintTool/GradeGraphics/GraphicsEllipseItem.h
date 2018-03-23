#pragma once
#include "prePaintToolHeader.h"
#include "GraphicsRectItem.h"


class GraphicsEllipseItem : public GraphicsRectItem
{
public:
    GraphicsEllipseItem(const QRect & rect ,QGraphicsItem * parent);
    QPainterPath shape() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
