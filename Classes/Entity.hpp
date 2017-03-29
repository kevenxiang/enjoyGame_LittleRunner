//
//  Entity.hpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/27.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Entity : public Node {
public:
    Entity();
    ~Entity();
    Sprite *getSprite();              //获取精灵对象
    void bindSprite(Sprite *sprite);  //绑定精灵对象
private:
    Sprite *m_sprite;

};


#endif /* Entity_hpp */
