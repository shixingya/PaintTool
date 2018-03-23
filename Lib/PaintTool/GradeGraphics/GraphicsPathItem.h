#pragma once
#include "prePaintToolHeader.h"
#include "GraphicsItem.h"
#include <QPen>
class GraphicsPathItem : public QGraphicsPathItem
{

public:
    GraphicsPathItem(const QPainterPath &painterPath ,GraphicsItem * parent);
    void setBorderColor(QColor color)
    {
        QPen pen =this->pen();
        pen.setColor(color);
        setPen(pen);
    }
};

