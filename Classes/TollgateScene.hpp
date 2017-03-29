//
//  TollgateScene.hpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/27.
//
//

#ifndef TollgateScene_hpp
#define TollgateScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace cocos2d::ui;
USING_NS_CC_EXT;

class Player;
class TollgateScene : public Layer {
public:
    static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(TollgateScene);
    
    virtual void update(float delta);
private:
    void initBG();   //初始化关卡背景
    
    void loadUI(); //加载UI
    void jumpEvent(Ref *, TouchEventType type);
private:
    Sprite *m_bgSprite1;  //背景精灵1
    Sprite *m_bgSprite2;  //背景精灵2
    
    Player *m_player;  //主角
    
    //分数
    int m_iScore;
    //分数标签
    Text *m_scoreLab;
    //血量条
    LoadingBar *m_hpBar;

};

#endif /* TollgateScene_hpp */
