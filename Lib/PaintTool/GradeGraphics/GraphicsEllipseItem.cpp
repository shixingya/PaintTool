#include "GraphicsEllipseItem.h"



GraphicsEllipseItem::GraphicsEllipseItem(const QRect &rect, QGraphicsItem *parent)
    :GraphicsRectItem(rect,parent)
{

}

QPainterPath GraphicsEllipseItem::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return qt_graphicsItem_shapeFromPath(path,_pen);
}

void GraphicsEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rc = rect();
    QPen pen =painter->pen();
    pen.setWidth(_borderWidth);
    pen.setColor(_color);
    painter->setPen(pen);
    painter->drawEllipse(rc);
}

