#ifndef _SPLASH_IN_OUT_ANIMATION_H__
#define _SPLASH_IN_OUT_ANIMATION_H__

/************************************************************************/
/*                       ��ʼ���潥��                                    */
/************************************************************************/
#include <osg/NodeCallback>
#include <osgAnimation/EaseMotion>
#include <osg/Node>
#include <osg/NodeVisitor>

class SplashInOutAnimation : public osg::NodeCallback
{
public:
    SplashInOutAnimation(void);
    ~SplashInOutAnimation(void);

public:
    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);

public:
    void SetFadeInOut(bool fade_in, bool fade_out) {m_bFadeIn = fade_in; m_bFadeOut = fade_out;}

private:
    osg::ref_ptr<osgAnimation::InOutCubicMotion> m_pFadeMotion;
    bool m_bFadeIn; // ����
    bool m_bFadeOut; // ����

};

#endif // _SPLASH_IN_OUT_ANIMATION_H__