#ifndef BaseScene_hpp
#define BaseScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "audio/include/AudioEngine.h"
#include "audio/include/SimpleAudioEngine.h"
#include <iostream>
using namespace cocos2d;
using namespace std;
using namespace ui;
using namespace CocosDenshion;
using namespace cocos2d::experimental;

namespace GameSequence
{
    class BaseLayer:public Layer
    {
    public:
        virtual bool init();
        virtual void onEnter();
        
        virtual bool onTouchBegan(Touch* touch,Event* event)=0;
        virtual void onTouchMoved(Touch* touch,Event* event)=0;
        virtual void onTouchEnded(Touch* touch,Event* event)=0;
        virtual void onTouchCancelled(Touch* touch,Event* event)=0;
    protected:
        BaseLayer();
        //virtual ~BaseLayer();
        BaseLayer(const BaseLayer& );
        //BaseLayer operator=(const BaseLayer& );
    };
    
}

#endif /* BaseScene_hpp */
