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
		GameEnemy* gameEnemy = GameEnemy::create(1);
		this->addChild(gameEnemy);
		enemys->addObject(gameEnemy);
		gameEnemy = GameEnemy::create(1);
		this->addChild(gameEnemy);
		enemys->addObject(gameEnemy);
		return true;
	}
	return false;
}

GameScene* GameEnemyLayer::getGameScene()
{
	return (GameScene*)this->getParent();
}

GameEnemyLayer::~GameEnemyLayer()
{
	CC_SAFE_RELEASE(enemys);
}