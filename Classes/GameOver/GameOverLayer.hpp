#ifndef GameOverLayer_hpp
#define GameOverLayer_hpp

#include "BaseLayer.hpp"

namespace GameSequence
{
    class GameOverLayer:public BaseLayer
    {
    public:
        static Scene* createScene();
        static GameOverLayer* create();
        bool init();
        void onEnter();
        
        void toStageSelect(Ref* sender);
        void toGame(Ref* sender);
        virtual bool onTouchBegan(Touch* touch,Event* event);
        virtual void onTouchMoved(Touch* touch,Event* event);
        virtual void onTouchEnded(Touch* touch,Event* event);
        virtual void onTouchCancelled(Touch* touch,Event* event);
    private:
        GameOverLayer();
        ~GameOverLayer();
        GameOverLayer(const GameOverLayer& );
        GameOverLayer operator=(const GameOverLayer& );
    };
}


#endif /* GameOverLayer_hpp */
