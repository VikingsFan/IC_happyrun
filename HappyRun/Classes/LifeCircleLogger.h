#ifndef __LIFECIRCLELOGGER_H__
#define __LIFECIRCLELOGGER_H__

#include "cocos2d.h"
class LifeCircleLogger
{
	std::string m_msg;
public:
	LifeCircleLogger();
	LifeCircleLogger(const std::string& msg);
	~LifeCircleLogger();
};
#define LOG_FUNCTION_LIFE LifeCircleLogger(__FUNCTION__);
#endif