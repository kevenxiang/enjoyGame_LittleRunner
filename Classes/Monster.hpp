//
//  Monster.hpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/28.
//
//

#ifndef Monster_hpp
#define Monster_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Entity.hpp"
#include "Player.hpp"

class Monster : public Entity {
public:
    Monster();
    ~Monster();
    CREATE_FUNC(Monster);
    virtual bool init();
    
public:
    void show();  //显示怪物
    void hide();  //隐藏怪物
    void reset();  //重置怪物数据
    bool isAlive();  //是否活动状态
    
    //检查碰撞
    bool isCollideWithPlayer(Player *player);
    
private:
    bool m_isAlive;

};

#endif /* Monster_hpp */
