#include "GameBulletLayer.h"
#include "GameBullet.h"
#include "GameScene.h"
#include "GameEnemy.h"

bool GameBulletLayer::init()
{
	if (CCLayer::init())
	{
		l = 1000;
		h = 0;
		t = 999;
		list = new int[l];
		bullets = CCArray::createWithCapacity(l);
		CC_SAFE_RETAIN(bullets);
		for (int i = 0; i < l; i++)
		{
			list[i] = i;
			GameBullet* bullet = GameBullet::create(i);
			this->addChild(bullet);
			bullets->insertObject(bullet, i);
		}
		return true;
	}
	return false;
}

GameScene* GameBulletLayer::getGameScene()
{
	return (GameScene*)this->getParent();
}

bool GameBulletLayer::attack(int kind, GameEnemy* enemy, char* string)
{
	GameBullet* bullet = (GameBullet*)bullets->objectAtIndex(list[h++]);
	bullet->attack(kind, enemy, string);
	return true;
}

void GameBulletLayer::refresh(float dt)
{
	CCObject* pObject = NULL;
	CCARRAY_FOREACH(bullets, pObject)
	{
		GameBullet* bullet = (GameBullet*)pObject;
		if (bullet->isVisible())
			bullet->refresh(dt);
	}
}

GameBulletLayer::~GameBulletLayer()
{
	delete(list);
	CC_SAFE_RELEASE(bullets);
}