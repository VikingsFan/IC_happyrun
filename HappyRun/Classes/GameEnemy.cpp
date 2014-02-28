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
	fullLife = 10;
	life = fullLife;
	this->addChild(enemySprite);
	this->setPosition(ccp(1015, 215));
	return true;
}

void GameEnemy::recycle()
{
	this->setVisible(false);
	((GameEnemyLayer*)this->getParent())->recycle(this);
}
void GameEnemy::hurt(int damage)
{
	life -= damage;
	if (life <= 0)
	{
		//this->setVisible(false);
		this->recycle();
	}
}

void GameEnemy::runAI(float dt)
{
	enemySprite->setOpacity(life * 255 / fullLife);
	float x = getPositionX();
	float y = getPositionY();
	if (life <= 0)
	{
		this->setVisible(false);
		return;
	}
	if (decisionCD > 200)
	{
		float ret = CCRANDOM_0_1() * 1000;
		getGameScene()->attackComand(-1, this);
		if (ret > 950)
		{
			//attackComand(-1, enemy);
		}
		else if (ret > 850)
		{
			// jump
		}
		else if (ret > 700)
		{
			dir = 0;
			decisionCD = 0;
		}
		else if (ret > 350)
		{
			dir = 1;
			decisionCD = 0;
		}
		else
		{
			dir = -1;
			decisionCD = 0;
		}
	}
	else
		decisionCD++;
	x += dir;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	if (x < getGameScene()->gamePlayerLayer->gameYou->getPositionX() + visibleSize.width / 5)
	{
		dir = 1;
		x += dir * 2;
	}
	else if (x - (-getGameScene()->gameViewOriginPoint.x) > visibleSize.width)
	{
		dir = -1;
		x += dir * 2;
	}
	this->setPosition(x, y);
}

GameScene* GameEnemy::getGameScene()
{
	return ((GameEnemyLayer*)this->getParent())->getGameScene();
}