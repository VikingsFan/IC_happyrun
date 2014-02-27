#include "GameYou.h"
#include "GameScene.h"
#include "GameEnemy.h"
enum{
	tag_moveTo_Action = 0
};
GameYou* GameYou::create(int w)
{
	GameYou* you = new GameYou();
	you->init(w);
	you->autorelease();
	return you;
}

bool GameYou::init(int w)
{
	youSprite = CCSprite::create("man.png");
	speed = 200;
	this->addChild(youSprite);
	this->setPosition(ccp(15,215));
	return true;
}

GameScene* GameYou::getGameScene()
{
	return ((GamePlayerLayer*)this->getParent())->getGameScene();
}
void GameYou::moveComand()
{
	CCMoveTo* moveTo = CCMoveTo::create(2, this->getPosition() + ccp(400, 0));
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(GameYou::moveEnd));

	CCFiniteTimeAction* seq = CCSequence::create(moveTo, callFunc, NULL);
	seq->setTag(tag_moveTo_Action);
	this->runAction(seq);
}

void GameYou::moveEnd()
{
	this->stopActionByTag(tag_moveTo_Action);
}

CCPoint GameYou::getAttackTarget()
{
	return CCPointMake(1015, 215);
}

void GameYou::attackComand()
{
	bool ret = false;
	CCObject* pObject = NULL;
	CCARRAY_FOREACH(getGameScene()->gameEnemyLayer->enemys, pObject)
	{
		GameEnemy* enemy = (GameEnemy*)pObject;
		if (enemy->life > 0)
		{
			ret = true;
			getGameScene()->attackComand(1, enemy);
			return;
		}
	}
	if (!ret)
	{
	}
}

void GameYou::jumpComand()
{
	this->jumpSpeed = 600;
}