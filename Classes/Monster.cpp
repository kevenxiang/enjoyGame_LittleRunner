//
//  Monster.cpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/28.
//
//

#include "Monster.hpp"

Monster::Monster() {
    m_isAlive = false;
}

Monster::~Monster() {}

bool Monster::init() {
    return true;
}

void Monster::show() {
    if (getSprite() != NULL) {
        setVisible(true);  //设置可见
        m_isAlive = true;  //标记怪物为活动状态
    }
}

void Monster::hide() {
    if (getSprite() != NULL) {
        setVisible(false);  //设置不可见
        reset();  //重置怪物数据
        m_isAlive = false;  //标记怪物为非活动状态
    }
}

void Monster::reset() {
    if (getSprite() != NULL) {
        //初始化怪物坐标
        setPosition(Point(800+CCRANDOM_0_1()*2000, 200-CCRANDOM_0_1()*100));
    }
}

bool Monster::isAlive() {
    return m_isAlive;
}

bool Monster::isCollideWithPlayer(Player *player) {
    //获取碰撞检查对象的boundingBox
    Rect entityRect = player->getBoundingBox();
    
    Point monsterPos = getPosition();
    
    //判断boundingBox和怪物中心点是否有交集
    return entityRect.containsPoint(monsterPos);
    
}












