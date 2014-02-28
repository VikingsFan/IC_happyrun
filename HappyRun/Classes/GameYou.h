#ifndef __GAME_YOU_H__
#define __GAME_YOU_H__
#include "cocos2d.h"

USING_NS_CC;

class GameScene;

class GameYou : public cocos2d::CCNode
{
public:
	static GameYou* create(int w);
	bool init(int w);
	GameScene* getGameScene();

	int life;

	int speed;
	int jumpSpeed;

	CCPoint getMoveTarget();
	void moveComand();
	void moveEnd();
	
	CCPoint getAttackTarget();
	void attackComand();

	void jumpComand();

	CCSprite* youSprite;
	CCPoint gamePosition;
	CCPoint screenPosition;
};

#endif 
