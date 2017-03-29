//
//  Player.hpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/27.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Entity.hpp"

using namespace cocos2d;

#define JUMP_ACTION_TAG   1
class Player : public Entity {
public:
    Player();
    ~Player();
    CREATE_FUNC(Player);
    virtual bool init();
public:
    void jump();  //跳跃函数
    void hit();  //玩家受伤害
    int getiHP();
    void resetData();
private:
    bool m_isJumping; //标记主角是否正在跳跃
    int m_iHP;  //主角血量
};

#endif /* Player_hpp */
