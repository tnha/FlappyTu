#include "OverLayer.h"
#include "ui/CocosGUI.h"
using namespace ui;
USING_NS_CC;
void OverLayer::setScore(int _score)
{
	score = _score;
	scoreLabel->setString(String::createWithFormat("%d", score)->getCString());
}

bool OverLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//Background gameover
	auto overPanel = Sprite::create("gameover.jpg");
	overPanel->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	this->addChild(overPanel);
	//Button
	auto menu = Button::create("menu.png");
	menu->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	menu->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto gotoMenuScene = MenuScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(3, gotoMenuScene));
			break;
		}
	});
	this->addChild(menu);
	auto replay = Button::create("replay.png");
	replay->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	replay->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto gotoPlayScene = PlayScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(3, gotoPlayScene));
			break;
		}
	});
	this->addChild(replay);

	return true;
}