#include "GameScene.h"
#include "GameEnemy.h"

USING_NS_CC;

bool GameScene::init()
{
	//preloadResources();
	if (CCScene::init()){
		gameBackgroundLayer = GameBackgroundLayer::create();
		this->addChild(gameBackgroundLayer);

		gameMapLayer = GameMapLayer::create();
		this->addChild(gameMapLayer);

		gameControlLayer = GameControlLayer::create();
		this->addChild(gameControlLayer);
		
		gameBulletLayer = GameBulletLayer::create();
		this->addChild(gameBulletLayer);

		gameEnemyLayer = GameEnemyLayer::create();
		this->addChild(gameEnemyLayer);

		gamePlayerLayer = GamePlayerLayer::create();
		this->addChild(gamePlayerLayer);

		game_g = 600;

		for (int i = 0; i < 1000000; i++)
		gameViewOriginPoint = CCPointZero;
		this->scheduleUpdate();

		return true;
	}
	return false;
}

void GameScene::attackComand(int kind, GameEnemy* targetNode)
{
	gameBulletLayer->attack(kind, targetNode, "Fuck");
}

void GameScene::moveComand()
{
	gamePlayerLayer->getGameYou()->moveComand();
}

void GameScene::jumpComand()
{
	gamePlayerLayer->gameYou->jumpComand();
}

void GameScene::update(float dt)
{
	this->refreshPlayer(dt);
	this->refreshBullet(dt);
	this->refreshEnemy(dt);
	this->setView(dt);
}

void GameScene::refreshPlayer(float dt)
{
	this->setPlayerJump(dt);
}

void GameScene::refreshEnemy(float dt)
{
	this->setEnemyAI(dt);
}

void GameScene::refreshBullet(float dt)
{
	gameBulletLayer->refresh(dt);
}

void GameScene::setPlayerJump(float dt)
{
	if ((gamePlayerLayer->gameYou->getPositionY() > 215) || (gamePlayerLayer->gameYou->jumpSpeed != 0))
	{
		float y = gamePlayerLayer->gameYou->getPositionY();
		y += gamePlayerLayer->gameYou->jumpSpeed * dt;
		if (y <= 215)
		{
			gamePlayerLayer->gameYou->jumpSpeed = 0;
			y = 215;
		}
		else
			gamePlayerLayer->gameYou->jumpSpeed -= dt * game_g;
		gamePlayerLayer->gameYou->setPositionY(y);
	}
}

void GameScene::setEnemyAI(float dt)
{
	CCObject* pObject = NULL;
	CCARRAY_FOREACH(gameEnemyLayer->enemys, pObject)
	{
		GameEnemy* enemy = (GameEnemy*)pObject;
		if (enemy->isVisible())
		{
			float x = enemy->getPositionX();
			float y = enemy->getPositionY();
			if (enemy->life <= 0)
			{
				enemy->setVisible(false);
				return;
			}
			if (enemy->decisionCD > 200)
			{
				float ret = CCRANDOM_0_1() * 1000;
				attackComand(-1, enemy);
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
					enemy->dir = 0;
					enemy->decisionCD = 0;
				}
				else if (ret > 350)
				{
					enemy->dir = 1;
					enemy->decisionCD = 0;
				}
				else
				{
					enemy->dir = -1;
					enemy->decisionCD = 0;
				}
			}
			else
				enemy->decisionCD++;
			x += enemy->dir;
			CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
			if (x < gamePlayerLayer->gameYou->getPositionX() + visibleSize.width / 5)
			{
				enemy->dir = 1;
				x += enemy->dir * 2;
			}
			else if (x - (-gameViewOriginPoint.x) > visibleSize.width)
			{
				enemy->dir = -1;
				x += enemy->dir * 2;
			}
			enemy->setPosition(x, y);
		}
	}
}

void GameScene::setView(float dt)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	int x = gamePlayerLayer->gameYou->getPositionX()-(-gameViewOriginPoint.x) - visibleSize.width / 3;
	//CCLog("%d %d", x, gamePlayerLayer->getGameYou()->getPositionX());
	if (x >= 0)
	{
		gameViewOriginPoint.x -= x;
		gamePlayerLayer->setPosition(gameViewOriginPoint);
		gameEnemyLayer->setPosition(gameViewOriginPoint);
		gameBulletLayer->setPosition(gameViewOriginPoint);
	}
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}

GameScene::~GameScene()
{
	this->unscheduleUpdate();
}