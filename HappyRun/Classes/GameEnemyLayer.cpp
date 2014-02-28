#include "GameEnemyLayer.h"
#include "GameEnemy.h"
#include "GameScene.h"

USING_NS_CC;

bool GameEnemyLayer::init()
{
	if (CCLayer::init())
	{
		enemys = CCArray::create();
		CC_SAFE_RETAIN(enemys);
		return true;
	}
	return false;
}

GameScene* GameEnemyLayer::getGameScene()
{
	return (GameScene*)this->getParent();
}

void GameEnemyLayer::recycle(GameEnemy* enemy)
{
	enemys->removeObject(enemy);
}

void GameEnemyLayer::refresh(float dt)
{
	theBadIsComing();
	setEnemyAI(dt);
}

void GameEnemyLayer::theBadIsComing()
{
	if (enemys->count() == 0)
	{
		float ret = CCRANDOM_0_1() * 5 + 1;
		for (int i = 0; i < ret; i++)
		{
			GameEnemy* gameEnemy = GameEnemy::create(1);
			this->addChild(gameEnemy);
			enemys->addObject(gameEnemy);
		}
	}
}

void GameEnemyLayer::setEnemyAI(float dt)
{
	CCObject* pObject = NULL;
	CCARRAY_FOREACH(enemys, pObject)
	{
		GameEnemy* enemy = (GameEnemy*)pObject;
		enemy->runAI(dt);
	}
}

GameEnemyLayer::~GameEnemyLayer()
{
	CC_SAFE_RELEASE(enemys);
}