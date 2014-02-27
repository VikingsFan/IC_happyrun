#include "GameEnemy.h"
#include "GameScene.h"

GameEnemy* GameEnemy::create(int w)
{
	GameEnemy* enemy = new GameEnemy();
	enemy->init(w);
	enemy->autorelease();
	return enemy;
}

bool GameEnemy::init(int w)
{
	enemySprite = CCSprite::create("enemy.png");
	dir = 0;
	decisionCD = 300;
	life = 1;
	this->addChild(enemySprite);
	this->setPosition(ccp(1015, 215));
	return true;
}

GameScene* GameEnemy::getGameScene()
{
	return ((GameEnemyLayer*)this->getParent())->getGameScene();
}