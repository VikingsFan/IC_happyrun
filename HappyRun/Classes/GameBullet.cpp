#include "GameBullet.h"
#include "GameScene.h"
#include "GameEnemy.h"
#include "GameYou.h"

USING_NS_CC;

enum{
	tag_FlyTo_Action = 0
};
GameBullet* GameBullet::create(int w)
{
	GameBullet* bullet = new GameBullet();
	bullet->init(w);
	bullet->autorelease();
	return bullet;
}

bool GameBullet::init(int w)
{
	index = w;
	kind = 0;
	damage = 0;

	speedX = 0;
	speedY = 0;
	lastP = ccp(0, 0);
	flying = false;

	int fontSize = 20;
	CCString* fontName = CCString::create("");

	bulletTTF = CCLabelTTF::create("*", fontName->getCString(), fontSize);
	this->addChild(bulletTTF);
	this->setVisible(false);

	return true;
}

GameScene* GameBullet::getGameScene()
{
	return ((GameBulletLayer*)this->getParent())->getGameScene();
}

void GameBullet::attack(int kind, GameEnemy* enemy, char* string)
{
	if (CCRANDOM_0_1() * 10 > 9.0)
	{
		this->bulletTTF->setFontSize(100);
		this->damage = 5;
	}
	else
	{
		this->bulletTTF->setFontSize(20);
		this->damage = 1;
	}
	if (kind > 0)
	{
		this->bulletTTF->setColor(ccc3(0, 0, 0));
		this->bulletTTF->setAnchorPoint(ccp(1, 0.5));
	}
	else
	{
		this->bulletTTF->setColor(ccc3(255 , 0, 0));
		this->bulletTTF->setAnchorPoint(ccp(0, 0.5));
	}

	this->kind = kind;
	this->enemy = enemy;
	this->you = getGameScene()->gamePlayerLayer->gameYou;
	
	this->flying = true;
	
	float high = CCRANDOM_0_1() * 200  + (you->getPositionY() > enemy->getPositionY() ? you->getPositionY() : enemy->getPositionY());
	this->speedY = sqrt(2 * high * getGameScene()->game_g);

	if (kind > 0)
		this->setPosition(this->you->getPosition());
	else
		this->setPosition(this->enemy->getPosition());
	lastP = this->getPosition();
	this->bulletTTF->setString(string);
	this->bulletTTF->setOpacity(255);
	this->setRotation(0);
	this->setVisible(true);
}

void GameBullet::hurt()
{
	if (!damage)
		return;
	float x = this->getPositionX();
	float y = this->getPositionY();
	float tX, tY;
	float g = getGameScene()->game_g;
	if (kind > 0)
	{
		tX = enemy->getPositionX();
		tY = enemy->getPositionY();
	}
	else
	{
		tX = you->getPositionX();
		tY = you->getPositionY();
	}
	if ((abs(x - tX) < 15) && (abs(y - tY) < 15))
	{
		if (kind > 0)
		{
			enemy->hurt(damage);
		}
		else
		{
			you->life -= damage;
		}

	}
}
void GameBullet::recycle()
{
	this->setVisible(false);
	((GameBulletLayer*)this->getParent())->recycleBullet(this->index);
}

void GameBullet::refresh(float dt)
{
	if (!this->getGameScene()->isInView(this->getPosition()))
	{
		this->recycle();
		return;
	}
	if (this->flying)
	{
		float x = this->getPositionX();
		float y = this->getPositionY();
		float tX, tY;
		float g = getGameScene()->game_g;

		if (kind > 0)
		{
			tX = enemy->getPositionX();
			tY = enemy->getPositionY();
		}
		else
		{
			tX = you->getPositionX();
			//tY = you->getPositionY();
			tY = 215;
		}
		speedY -= g * dt;
		bool ret = false;
		if ((y > tY) && (speedY < 0) && ((tX - x) * kind > 0))
		{
			ret = true;
			speedX = (tX -x) / (sqrt(speedY*speedY / (g * g) + 2 * (y - tY) / g) + speedY / g);
		}
		x += speedX * dt;
		y += speedY * dt;
		if ((x != lastP.x) && ret)
		{
			this->setRotation(-atan((y - lastP.y) / (x - lastP.x)) / 3.14 * 180);
		}
		if (y <= 200)
		{
			y = 200;
			speedY = 0;
			speedX = 0;
			flying = false;
		}
		this->setPosition(ccp(x, y));
		
		hurt();
		
		lastP = this->getPosition();
	}
	else
	{
		this->bulletTTF->setOpacity(this->bulletTTF->getOpacity() - 51 * dt);
		if (this->bulletTTF->getOpacity() <= 0)
		{
			recycle();
			return;
		}
		if (!((GameBulletLayer*)this->getParent())->enough())
			recycle();
	}
}

void GameBullet::getSpeed()
{

}