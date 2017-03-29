//
//  MonsterManager.cpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/28.
//
//

#include "MonsterManager.hpp"
#include "Player.hpp"
#include "Monster.hpp"

bool MonsterManager::init() {
    createMonsters();   //创建怪物缓存
    this->scheduleUpdate();  //开启update函数调用
    return true;
}

void MonsterManager::createMonsters() {
    Monster *monster = NULL;
    Sprite *sprite = NULL;
    
    for (int i = 0; i < MAX_MONSTER_NUM; i++) {
        //创建怪物对象
        monster = Monster::create();
        monster->bindSprite(Sprite::create("monster.png"));
        monster->reset();
        
        //添加怪物对象
        this->addChild(monster);
        
        //保存怪物对象到列表中，方便管理
        m_monsterArr.pushBack(monster);
    }
}

void MonsterManager::update(float dt) {
    for (auto monster : m_monsterArr) {
        if (monster->isAlive()) {
            //如果怪物处于活动状态
            monster->setPositionX(monster->getPositionX() - 4);
            
            //如果怪物X坐标小于0， 则表示已经超出屏幕范围，隐藏怪物
            if (monster->getPositionX() < 0) {
                monster->hide();
            }
            //判断怪物是否碰撞玩家
            else if (monster->isCollideWithPlayer(m_player)) {
                m_player->hit();
                monster->hide();
            }
            
            
            
        } else {
            //怪物处于非活动状态，让怪物出场吧
            monster->show();
        }
    }
}

void MonsterManager::bindPlayer(Player *player) {
    m_player = player;
}





































