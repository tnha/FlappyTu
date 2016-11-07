#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "PlayScene.h"
#include "ui/CocosGUI.h"
using namespace ui;
USING_NS_CC;
Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
void MenuScene::gotoPlayScene(float dt)
{
	auto playscene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playscene);
}
bool MenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//----------------------Tạo background-----------------------
	auto menuBackground = Sprite::create("PlayBackground.png");
	menuBackground->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(menuBackground);
	//------------tên game hiển thị menuscene-------------
	auto titleGame = Sprite::create("Title.png");
	titleGame->setScale(2);
	titleGame->setPosition(origin.x + visibleSize.width / 2, origin.y + (visibleSize.height / 4) * 3);
	this->addChild(titleGame);
	//Button bắt đầu game
	auto playgame = Button::create("play.png");
	playgame->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	playgame->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto gotoPlayScene = PlayScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(1, gotoPlayScene));
			break;
		}
	});
	this->addChild(playgame);
    return true;
}
