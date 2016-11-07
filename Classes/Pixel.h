#ifndef __PIXEL_H__
#define __PIXEL_H__

#include "cocos2d.h"
#include "Definitions.h"

USING_NS_CC;

class Pixel
{
public:
	Pixel(Layer* layer);
	void Flap();
	void update(float dt);
	void Fall();
	bool isDead;

private:
	Sprite* FlappyBird;
	PhysicsBody* FlappyBody;

	Size visibleSize;
	Vec2 origin;

	bool isFalling;
	float velocityY;
	float rotation;
};

#endif //__PIXEL_H__