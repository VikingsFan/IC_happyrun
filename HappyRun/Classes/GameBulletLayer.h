#ifndef __GAME_BULLET_LAYER_H__
#define __GAME_BULLET_LAYER_H__
#include "cocos2d.h"
USING_NS_CC;

class GameScene;
class GameEnemy;

class GameBulletLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(GameBulletLayer);
	bool init();
	int h, t, l;
	int* list;
	CCArray* bullets;
	GameScene* getGameScene();

	bool attack(int kind, GameEnemy* enemy, char* string);
	
	void refresh(float dt);

	~GameBulletLayer();
};

#endif 