#ifndef __GAME_BULLET_H__
#define __GAME_BULLET_H__
#include "cocos2d.h"

USING_NS_CC;

class GameScene;
class GameEnemy;
class GameYou;

class GameBullet : public cocos2d::CCNode
{
public:
	//CREATE_FUNC(GameEnemy);
	static GameBullet* create(int w);
	bool init(int w);
	GameScene* getGameScene();

	CCLabelTTF* bulletTTF;

	int index;
	int kind;

	float speedX;
	float speedY;
	bool flying;

	void getSpeed();

	GameEnemy* enemy;
	GameYou* you;

	CCPoint lastP;

	void attack(int kind, GameEnemy* enemy, char* string);

	void refresh(float dt);
};

#endif 