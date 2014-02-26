#ifndef __GAME_PLAYER_LAYER_H__
#define __GAME_PLAYER_LAYER_H__
#include "cocos2d.h"
#include "GameYou.h"
#include "GameBullet.h"

class GameScene;

class GamePlayerLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(GamePlayerLayer);
	bool init();
	GameYou* getGameYou();
	GameScene* getGameScene();

	GameBullet* gameBullet;
	GameYou* gameYou;
};

#endif 
