#pragma once
#include "prePaintToolHeader.h"
#include "GraphicsItem.h"
class GraphicsArrowItem : public QGraphicsPathItem
{
public:
    enum { Type = UserType + 4 };
    GraphicsArrowItem(const QPainterPath &painterPath ,
                      QGraphicsItem * parent=0);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *w) Q_DECL_OVERRIDE;
    QPointF startPos,endPos;
    void setBorderColor(QColor color)
    {
        _color =color;
    }
    void setBorderWidth(qreal width)
    {
        _borderWidth =width;
    }
    QPainterPath shape() const
    {
        QPainterPath path;
        path.addRect(boundingRect());
        return path;
    }
private:
    QPainterPath getArrowsPath(const QPointF &start,
                               const QPointF &end,
                               qreal len) const;


private:
    qreal   len;
    qreal   _borderWidth=1;
    QColor _color =Qt::red;
};
