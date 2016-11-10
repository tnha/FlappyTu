#include "Pixel.h"

Pixel::Pixel(Layer* layer)
{
	//Mình sẽ lấy các giá trị của màn hình
	origin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

	//Tạo sprite cho Pixel, và set vị trí cho nó
	flappyBird = Sprite::create("bird.png");
	flappyBird->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	flappyBody = PhysicsBody::createBox(flappyBird->getContentSize());
	flappyBody->setCategoryBitmask(eObjectBitmask::PIXEL);
	//flappyBody->setCollisionBitmask(eObjectBitmask::PIPE);
	flappyBody->setContactTestBitmask(eObjectBitmask::PIPE | eObjectBitmask::LINE);
	flappyBird->setPhysicsBody(flappyBody);
	layer->addChild(flappyBird, 100);

	//Các giá trị mặc định cho các biến
	isFalling = true;

	velocityY = 0.0f;
	rotation = 0.0f;

	isDead = false;
}

void Pixel::update()
{
	//Nếu mà nó đang rơi
	if (isFalling)
	{
		//Mà nó ở vị trí bên trên cạnh phía dưới
		if (flappyBird->getPositionY() > flappyBird->getContentSize().height/2)
		{
			velocityY += -1;
			rotation += 3;
		}
		else
		{
			//Nó sẽ không rơi nữa, không xoay luôn
			velocityY = 0;
			rotation = 0;

			//Cho pixel nằm ở dưới đáy
			flappyBird->setPositionY(flappyBird->getContentSize().height / 2);

		}
	}
	else
	{
		//Mà nó ở dưới cái trần bên trên
		if (flappyBird->getPositionY() < visibleSize.height - flappyBird->getContentSize().height / 2)
		{
			//Pixel đang bay lên
			//Thì mới tăng bay lên (tăng Y)
			velocityY = 10;
			rotation += -10;
		}
		//Nếu nó đụng trần bên trên
		else
		{
			//Thì sẽ không bay lên được
			velocityY = 0;
			rotation = 0;
		}
	}

	
	flappyBird->setPosition(Point(flappyBird->getPositionX(), flappyBird->getPositionY() + velocityY));
	flappyBird->setRotation(rotation);
}

void Pixel::Flap()
{
	//Bay
	isFalling = false;
}

void Pixel::Fall()
{
	//Rơi
	isFalling = true;
}