#ifndef GameLayer_hpp
#define GameLayer_hpp

#include "BaseLayer.hpp"
#include "LineObstracle.hpp"
#include <list>

namespace Game
{
    class Obstracle;
}

namespace GameSequence
{
    
    class GameLayer:public BaseLayer
    {
    public:
        static Scene* createScene();
        static GameLayer* create();
        bool init();
        void onEnter();
        void update(float dt);
        
        void toStageSelect(Ref* sender);
        void toResult(Ref* sender);
        void toGameOver(Ref* sender);
            
        virtual bool onTouchBegan(Touch* touch,Event* event);
        virtual void onTouchMoved(Touch* touch,Event* event);
        virtual void onTouchEnded(Touch* touch,Event* event);
        virtual void onTouchCancelled(Touch* touch,Event* event);
    private:
        float mPassedTime;
        list<Game::Obstracle*> mObstracleList;
        
        GameLayer();
        ~GameLayer();
        GameLayer(const GameLayer& );
        GameLayer operator=(const GameLayer& );
    };
}


#endif /* GameLayer_hpp */
