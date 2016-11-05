#include "Pixel.h"

Pixel::Pixel(Layer* layer)
{
	origin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();
//-------------------------------------------------------------------
	FlappyBird = Sprite::create("play.png");
	FlappyBird->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	auto birdPhysic = PhysicsBody::createBox(FlappyBird->getContentSize());
	FlappyBody = PhysicsBody::createBox(FlappyBird->getContentSize(), PhysicsMaterial(0, 0, 0));
	FlappyBody->setCollisionBitmask(4);
	FlappyBody->setContactTestBitmask(true);
	FlappyBird->setPhysicsBody(FlappyBody);
	layer->addChild(FlappyBird);


	//Các giá trị mặc định cho các biến
	isFalling = true;

	velocityY = 0.0f;
	rotation = 0.0f;

	isDead = false;
}

void Pixel::update(float dt)
{
	//Nếu mà nó đang rơi
	if (isFalling)
	{
		//Mà nó ở vị trí bên trên cạnh phía dưới
		if (FlappyBird->getPositionY() > FlappyBird->getContentSize().height / 2)
		{
			//Pixel đang rơi
			//Thì sẽ cộng thêm -1 (trừ đi 1) cho Y, tốc độ rơi ngày càng nhanh, và xoay cộng thêm 3
			velocityY += -1;
			rotation += 3;
		}
		//Nếu không
		else
		{
			//Nó sẽ không rơi nữa, không xoay luôn
			velocityY = 0;
			rotation = 0;

			//Cho pixel nằm ở dưới đáy
			FlappyBird->setPositionY(FlappyBird->getContentSize().height / 2);

			//Và ta sẽ chết
			isDead = true;
		}
	}
	//Nếu mà nó không có rơi
	else
	{
		//Mà nó ở dưới cái trần bên trên
		if (FlappyBird->getPositionY() < visibleSize.height - FlappyBird->getContentSize().height / 2)
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

	//Cuối cùng ta set vị trí và góc xoay cho Sprite thôi :D
	FlappyBird->setPosition(Point(FlappyBird->getPositionX(), FlappyBird->getPositionY() + velocityY));
	FlappyBird->setRotation(rotation);
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