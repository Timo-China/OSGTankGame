#ifndef _OSG_VIEW_WIDGET_H__
#define _OSG_VIEW_WIDGET_H__

#include <QWidget>
#include <osgViewer/Viewer>
#include <osgQt/GraphicsWindowQt>
#include <osg/Group>
#include <QTimer>

#include <osgQt/GraphicsWindowQt>
#include <osgViewer/Viewer>

class OSGViewWidget : public osgQt::GLWidget, public osgViewer::Viewer
{
    Q_OBJECT

public:
    OSGViewWidget(QWidget* parent = 0);
    ~OSGViewWidget(void);

protected:
    virtual void resizeEvent( QResizeEvent* event );
    virtual void paintEvent(QPaintEvent* event);

};
#endif //_OSG_VIEW_WIDGET_H__