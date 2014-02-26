#include "LifeCircleLogger.h"

USING_NS_CC;

LifeCircleLogger::LifeCircleLogger(){}
LifeCircleLogger::LifeCircleLogger(const std::string& msg) : m_msg(msg) {
	CCLog("%s BEGINS!", m_msg.c_str());
}
LifeCircleLogger::	~LifeCircleLogger() {
	CCLog("%s END!", m_msg.c_str());
}