#include "GraphicsTextItem.h"


GraphicsTextItem::GraphicsTextItem(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}
QVariant GraphicsTextItem::itemChange(GraphicsItemChange change,
                     const QVariant &value)
{
    return value;
}
void GraphicsTextItem::focusOutEvent(QFocusEvent *event)
{
    setTextInteractionFlags(Qt::NoTextInteraction);
    isDuringEdit =false;
    QGraphicsTextItem::focusOutEvent(event);
}
void GraphicsTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    isDuringEdit =true;
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}
