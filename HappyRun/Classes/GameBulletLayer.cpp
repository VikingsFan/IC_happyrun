#include "GameBulletLayer.h"
#include "GameBullet.h"
#include "GameScene.h"
#include "GameEnemy.h"

bool GameBulletLayer::init()
{
	if (CCLayer::init())
	{
		l = 100;
		h = 0;
		t = l - 1;
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

bool GameBulletLayer::enough()
{
	return ((t + l - h + 1) % l) > (l / 10);
}
void GameBulletLayer::recycleBullet(int index)
{
	if (++t == l)
		t = 0;
	int ret = list[t];
	GameBullet* bullet = (GameBullet*)bullets->objectAtIndex(list[t]);
	list[t] = list[index];
	bullet->index = index;
	bullet = (GameBullet*)bullets->objectAtIndex(list[index]);
	list[index] = ret;
	bullet->index = t;
}

bool GameBulletLayer::attack(int kind, GameEnemy* enemy, char* string)
{
	GameBullet* bullet = (GameBullet*)bullets->objectAtIndex(list[h]);
	bullet->attack(kind, enemy, string);
	if (++h == l)
		h = 0;
	return true;
}

void GameBulletLayer::refresh(float dt)
{
	int ret = (t + 1) % l;
	while (ret != h)
	{
		GameBullet* bullet = (GameBullet*)bullets->objectAtIndex(list[ret]);
		if (bullet->isVisible())
			bullet->refresh(dt);
		ret = (ret + 1) % l;
	}
}

GameBulletLayer::~GameBulletLayer()
{
	delete(list);
	CC_SAFE_RELEASE(bullets);
}