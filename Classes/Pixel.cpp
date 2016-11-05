#include "Pixel.h"

Pixel::Pixel(Layer* layer)
{
	origin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

	pixelTexture = Sprite::create("bird.png");
	pixelTexture->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

	pixelBody->setCategoryBitmask(eObjectBitmask::PIXEL);
	
	pixelBody->setContactTestBitmask(eObjectBitmask::PIPE | eObjectBitmask::LINE);


	pixelTexture->setPhysicsBody(pixelBody);

	
	layer->addChild(pixelTexture, 100);

	//Các giá trị mặc định cho các biến
	isFalling = true;

	velocityY = 0.0f;
	rotation = 0.0f;

	isDead = false;
}

void Pixel::Update()
{
	//Nếu đang rơi
	if (isFalling)
	{
		//vị trí cạnh dưới
		if (pixelTexture->getPositionY() > pixelTexture->getContentSize().height / 2)
		{
			//Thì sẽ cộng thêm -1 (trừ đi 1) cho Y, tốc độ rơi ngày càng nhanh, và xoay cộng thêm 3
			velocityY += -1;
			rotation += 3;
		}
		else
		{
			//giữ nguyên
			velocityY = 0;
			rotation = 0;

			//để pixel ở cạnh dưới
			pixelTexture->setPositionY(pixelTexture->getContentSize().height / 2);
			isDead = true;
		}
	}
	//Nếu k rơi
	else
	{
		//Mà ở vị trí cạnh trên
		if (pixelTexture->getPositionY() < visibleSize.height - pixelTexture->getContentSize().height / 2)
		{
			//giá trị sẽ thay đổi
			velocityY = 10;
			rotation += -10;
		}
		//Nếu chạm cạnh trên
		else
		{
			//không thể bay qua
			velocityY = 0;
			rotation = 0;
		}
	}

	//góc xoay của sprite
	pixelTexture->setPosition(Point(pixelTexture->getPositionX(), pixelTexture->getPositionY() + velocityY));
	pixelTexture->setRotation(rotation);
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