//
//  MonsterManager.hpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/28.
//
//

#ifndef MonsterManager_hpp
#define MonsterManager_hpp

#include "cocos2d.h"
#include "Monster.hpp"
USING_NS_CC;

#define MAX_MONSTER_NUM  10 //怪物最大数量
class MonsterManager : public Node {
public:
    CREATE_FUNC(MonsterManager);
    virtual bool init();
    virtual void update(float dt);  //重写update函数
    
public:
    //绑定玩家对象
    void bindPlayer(Player *player);
    
private:
    void createMonsters();  //创建怪物对象
    
    //玩家对象
    Player *m_player;
    
private:
    Vector<Monster *> m_monsterArr;  //存放怪物对象列表
};

#endif /* MonsterManager_hpp */





















