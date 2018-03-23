#-------------------------------------------------
#
# Project created by QtCreator 2018-02-26T14:03:34
#
#-------------------------------------------------

QT       += widgets

TARGET = PaintTool
TEMPLATE = lib

DEFINES += PAINTTOOL_LIBRARY \
           QT_MESSAGELOGCONTEXT   # release 版本下 记录代码所在行
PRECOMPILED_HEADER = prePaintToolHeader.h
CONFIG+=PRECOMPILED_HEADER
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GSPaintWgt.cpp \
    GradeGraphics/drawtool.cpp \
    GradeGraphics/GraphicsArrowItem.cpp \
    GradeGraphics/GraphicsEllipseItem.cpp \
    GradeGraphics/GraphicsItem.cpp \
    GradeGraphics/GraphicsItemGroup.cpp \
    GradeGraphics/GraphicsLineItem.cpp \
    GradeGraphics/GraphicsPathItem.cpp \
    GradeGraphics/GraphicsPixmapItem.cpp \
    GradeGraphics/GraphicsRectItem.cpp \
    GradeGraphics/GraphicsTextItem.cpp \
    GradeGraphics/GraphicsTriangleItem.cpp \
    GradeGraphics/MainPaintScene.cpp \
    GradeGraphics/PaintView.cpp \
    GradeGraphics/ShapeMimeData.cpp \
    GradeGraphics/sizehandle.cpp

HEADERS += \
        painttool_global.h \  
    GSPaintWgt.h \
    GradeGraphics/drawtool.h \
    GradeGraphics/GraphicsArrowItem.h \
    GradeGraphics/GraphicsEllipseItem.h \
    GradeGraphics/GraphicsItem.h \
    GradeGraphics/GraphicsItemGroup.h \
    GradeGraphics/GraphicsLineItem.h \
    GradeGraphics/GraphicsPathItem.h \
    GradeGraphics/GraphicsPixmapItem.h \
    GradeGraphics/GraphicsRectItem.h \
    GradeGraphics/GraphicsTextItem.h \
    GradeGraphics/GraphicsTriangleItem.h \
    GradeGraphics/MainPaintScene.h \
    GradeGraphics/PaintView.h \
    GradeGraphics/ShapeMimeData.h \
    GradeGraphics/sizehandle.h \
    prePaintToolHeader.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    qrc.qrc

FORMS += \
    GSPaintWgt.ui \
    GradeGraphics/PaintWidget.ui
