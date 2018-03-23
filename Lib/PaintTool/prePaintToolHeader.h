#ifndef PREPAINTTOOLHEADER_H
#define PREPAINTTOOLHEADER_H
#include <QtWidgets>
#define SafeDelete(p) if (nullptr != p) { delete p; p = nullptr; }

enum DrawBaseShape
{
    selection ,
    rotation  ,
    line ,
    rectangle ,  //矩形
    roundrect ,
    ellipse ,
    poly,
    arrowLine, //箭头线段
    text, //文字
    penPath, //铅笔
    image, //图片
    triangle, //三角形
    rubber,//橡皮擦
    None
};
#endif // PREPAINTTOOLHEADER_H
