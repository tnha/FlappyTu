#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__
#include "MenuScene.h"
#include "cocos2d.h"
USING_NS_CC;
class IntroScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
private:
	void IntroScene::gotoMenuScene(float dt);
	CREATE_FUNC(IntroScene);
};

#endif // __INTRO_SCENE_H__
