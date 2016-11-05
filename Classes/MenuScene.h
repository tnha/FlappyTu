#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__
#include "PlayScene.h"
#include "cocos2d.h"
USING_NS_CC;
class MenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
private:
	void MenuScene::gotoPlayScene(float dt);
    // implement the "static create()" method manually
	CREATE_FUNC(MenuScene);
};

#endif // __MENU_SCENE_H__
