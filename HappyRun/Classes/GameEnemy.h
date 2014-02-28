#ifndef __GAME_ENEMY_H__
#define __GAME_ENEMY_H__
#include "cocos2d.h"

USING_NS_CC;

class GameScene;

class GameEnemy : public cocos2d::CCNode
{
public:
	//CREATE_FUNC(GameEnemy);
	static GameEnemy* create(int w);
	bool init(int w);
	GameScene* getGameScene();

	int decisionCD;
	int dir;

	int fullLife;
	int life;

	void hurt(int damage);
	void runAI(float dt);

	void recycle();

	CCSprite* enemySprite;
};

#endif 