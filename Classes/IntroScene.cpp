#include "IntroScene.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"

USING_NS_CC;

Scene* IntroScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = IntroScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;

}
void IntroScene::gotoMenuScene(float dt)
{
	 auto menuscene = MenuScene::createScene();
	 Director::getInstance()->replaceScene(TransitionFade::create(3, menuscene));
}

bool IntroScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//---------------------------------------------------------------
	auto introBackground = Sprite::create("logo.png");
	introBackground->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(introBackground);
	this->scheduleOnce(schedule_selector(IntroScene::gotoMenuScene), 4.0f);
    return true;
}
