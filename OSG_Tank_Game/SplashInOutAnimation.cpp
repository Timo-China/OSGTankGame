#include "SplashInOutAnimation.h"


SplashInOutAnimation::SplashInOutAnimation(void)
    :m_bFadeIn(false),
    m_bFadeOut(false)
{
    m_pFadeMotion = new osgAnimation::InOutCubicMotion;
}


SplashInOutAnimation::~SplashInOutAnimation(void)
{
}

void SplashInOutAnimation::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
    if (m_bFadeIn)
    {
        // ����

    }
    else if (m_bFadeOut)
    {
        // ����

    }

    traverse(node, nv);
}

