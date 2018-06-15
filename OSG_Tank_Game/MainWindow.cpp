#include "MainWindow.h"
#include <osg/Texture2D>
#include <osg/MatrixTransform>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_pOSGWidget(NULL),
    m_pSplashWidgetImage(NULL),
    m_pWidget(NULL)
{
    ui.setupUi(this);

    m_pOSGWidget = new OSGViewWidget(this);
    ui.gridLayout->addWidget(m_pOSGWidget);
    m_pWidget = new GameSplashWidget();
    InitOSGViewWidget();
    CreateConnect();
}

MainWindow::~MainWindow()
{

}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    QMainWindow::resizeEvent(event);

}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);

    CreateSplash();
}

QWidget* MainWindow::CreateSplash()
{
    m_pSplashWidgetImage = new osgQt::QWidgetImage(m_pWidget);
    m_pSplashWidgetImage->getQWidget()->setAttribute(Qt::WA_TranslucentBackground);
    m_pSplashWidgetImage->getQGraphicsViewAdapter()->setBackgroundColor(QColor(0, 0, 0, 0));
    QGraphicsScene graphics_scenes = m_pSplashWidgetImage->getQGraphicsViewAdapter()->getQGraphicsScene();

    // 创建二维纹理
    osg::MatrixTransform* mt = new osg::MatrixTransform;
    osg::Geometry* geom = osg::createTexturedQuadGeometry(osg::Vec3(0,0,0), osg::Vec3(1,0,0), osg::Vec3(0,1,0), 1, 1);
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D(m_pSplashWidgetImage);
    texture->setResizeNonPowerOfTwoHint(false);
    texture->setFilter(osg::Texture::MIN_FILTER,osg::Texture::LINEAR);
    texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
    texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);

    mt->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
    geode->addDrawable(geom);

    // 创建HUD
    osg::ref_ptr<osg::Camera> camera = new osg::Camera;

    camera->setProjectionResizePolicy(osg::Camera::FIXED);
    // camera->setProjectionMatrix(osg::Matrix::ortho2D(0,1,0,1));
    camera->setProjectionMatrixAsOrtho2D(0,1,0,1);
    camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
    camera->setViewMatrix(osg::Matrix::identity());
    camera->setClearMask(GL_DEPTH_BUFFER_BIT);
    camera->setRenderOrder(osg::Camera::POST_RENDER);
    camera->addChild(geode);

    camera->setViewport(0, 0, this->width(), this->height());

    mt->addChild(camera);
    osgViewer::InteractiveImageHandler* handler = new osgViewer::InteractiveImageHandler(m_pSplashWidgetImage.get(), texture, camera);

    mt->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
    mt->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
    mt->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
    mt->getOrCreateStateSet()->setAttribute(new osg::Program);

    osg::Group* overlay = new osg::Group;
    overlay->addChild(mt);

    // 
    m_RootNode->addChild(overlay);

    geom->setEventCallback(handler);
    geom->setCullCallback(handler);

    return m_pWidget;
}

void MainWindow::InitOSGViewWidget()
{
    if (m_pOSGWidget)
    {
        m_pOSGWidget->addEventHandler(new osgViewer::ScreenCaptureHandler);
        m_pOSGWidget->addEventHandler(new osgViewer::HelpHandler);
        m_RootNode = new osg::Group;
        m_RootNode->setName("root");
        m_pOSGWidget->setSceneData(m_RootNode);
    }
}

void MainWindow::StartGameSlot()
{
    // 开始游戏
    // 后期添加渐变淡出动画
    m_RootNode->getChild(0)->setNodeMask(0);
}

void MainWindow::CreateConnect()
{
    connect(m_pWidget, &GameSplashWidget::StartGameSignal, this, &MainWindow::StartGameSlot);
}
