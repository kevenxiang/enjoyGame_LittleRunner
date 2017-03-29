//
//  FlowWord.hpp
//  enjoyGame_LittleRunner
//
//  Created by xiang on 2017/3/28.
//
//

#ifndef FlowWord_hpp
#define FlowWord_hpp

#include "cocos2d.h"
USING_NS_CC;

class FlowWord : public Node {
public:
    CREATE_FUNC(FlowWord);
    virtual bool init();
    
public:
    void showWord(const char *text, Point pos);
    
private:
    Label *m_textLab;
};

#endif /* FlowWord_hpp */
