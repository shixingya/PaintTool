#pragma once
#include "prePaintToolHeader.h"

class GraphicsTextItem : public QGraphicsTextItem
{
    Q_OBJECT

public:
    enum { Type = UserType + 3 };

    GraphicsTextItem(QGraphicsItem *parent = 0);

    int type() const override { return Type; }

    bool isDuringEdit=true; //是否正在编辑
    void setBorderColor(QColor color)
    {
        setDefaultTextColor(color);
    }
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void focusOutEvent(QFocusEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

};
