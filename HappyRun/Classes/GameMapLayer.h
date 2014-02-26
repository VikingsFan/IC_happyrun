#ifndef __GAME_MAP_LAYER_H__
#define __GAME_MAP_LAYER_H__
#include "cocos2d.h"

class GameScene;

class GameMapLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(GameMapLayer);
	bool init();
	GameScene* getGameScene();
};

#endif 