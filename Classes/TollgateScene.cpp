//
//  TollgateScene.cpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/27.
//
//

#include "TollgateScene.hpp"
#include "Player.hpp"
#include "MonsterManager.hpp"

Scene *TollgateScene::createScene() {
    auto scene = Scene::create();
    
    auto layer = TollgateScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool TollgateScene::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //游戏标题图片
    auto titleSprite = Sprite::create("title.png");
    titleSprite->setPosition(Point(visibleSize.width/2, visibleSize.height-50));
    this->addChild(titleSprite, 2);
    
    //创建主角
    m_player = Player::create();
    m_player->bindSprite(Sprite::create("sprite.png"));
    m_player->setPosition(Point(200, visibleSize.height/4));
    this->addChild(m_player, 3);
    
    //初始化背景图片
    initBG();
    
    //加载UI
    loadUI();
    
    this->scheduleUpdate();
    
    //创建怪物管理器
    MonsterManager *monsterMgr = MonsterManager::create();
    this->addChild(monsterMgr, 4);
    monsterMgr->bindPlayer(m_player);
    
    m_iScore = 0;
    
    return true;
}

void TollgateScene::initBG() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    m_bgSprite1 = Sprite::create("bg.jpg");
    m_bgSprite1->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(m_bgSprite1, 0);
    
    m_bgSprite2 = Sprite::create("bg.jpg");
    m_bgSprite2->setPosition(Point(visibleSize.width+visibleSize.width/2, visibleSize.height/2));
    m_bgSprite2->setFlippedX(true);   //水平翻转精灵
    this->addChild(m_bgSprite2, 0);
}

void TollgateScene::update(float delta) {
    
    int posX1 = m_bgSprite1->getPositionX(); //背景地图1的X坐标
    int posX2 = m_bgSprite2->getPositionX(); //背景地图2的X坐标
    
    int iSpeed = 1;  //地图滚动速度
    
    //两张地图向左滚动（两张地图是相邻的，所以要一起滚动，否则会出现间隙）
    posX1 -= iSpeed;
    posX2 -= iSpeed;
    
    
    //地图大小
    Size mapSize = m_bgSprite1->getContentSize();
    
    //当第一个地图完全离开屏幕时，第二个地图刚好完全出现在屏幕上，这时候就让第一个地图紧贴在第二个地图后面
    if (posX1 <= -mapSize.width/2) {
        posX1 = mapSize.width + mapSize.width/2;
    }
    
    //同理，当第二个地图完全离开屏幕时，第一个地图刚好完全出现在屏幕上，这时候就让第二个地图紧贴在第一个地图后面
    if (posX2 <= -mapSize.width/2) {
        posX2 = mapSize.width + mapSize.width/2;
    }
    
//    m_bgSprite1->setPositionX(posX1);
//    m_bgSprite2->setFlippedX(posX2);
    
    //增加分数
    m_iScore += 1;
    
    //修改分数标签
    m_scoreLab->setText(Value(m_iScore).asString());
    
    //修改血量进度
    m_hpBar->setPercent(m_player->getiHP() / 1000.0f * 100);
    
}

void TollgateScene::loadUI() {
    //加载UI
    auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("LitterRunnerUI_1.ExportJson");
    this->addChild(UI);
    
    //获取控件对象
    auto jumpBtn = (Button *)Helper::seekWidgetByName(UI, "JumpBtn");
    m_scoreLab = (Text *)Helper::seekWidgetByName(UI, "scoreLab");
    m_hpBar = (LoadingBar *)Helper::seekWidgetByName(UI, "hpProgress");
    
    //添加点击监听
    jumpBtn->addTouchEventListener(this, toucheventselector(TollgateScene::jumpEvent));
    
}

void TollgateScene::jumpEvent(Ref *, TouchEventType type) {
    switch (type) {
        case cocos2d::ui::TOUCH_EVENT_ENDED:
            m_player->jump();
            break;
            
        default:
            break;
    }
}
























