#ifndef StateSelectLayer_hpp
#define StateSelectLayer_hpp

#include "BaseLayer.hpp"

namespace GameSequence
{
    
    class StageSelectLayer:public BaseLayer
    {
    public:
        static Scene* createScene();
        static StageSelectLayer* create();
        bool init();
        void onEnter();
        
        void toTitle(Ref* sender);
        void toGame(Ref* sender);
        virtual bool onTouchBegan(Touch* touch,Event* event);
        virtual void onTouchMoved(Touch* touch,Event* event);
        virtual void onTouchEnded(Touch* touch,Event* event);
        virtual void onTouchCancelled(Touch* touch,Event* event);
    private:
        StageSelectLayer();
        ~StageSelectLayer();
        StageSelectLayer(const StageSelectLayer& );
        StageSelectLayer operator=(const StageSelectLayer& );
    };
}


#endif /* StateSelectLayer_hpp */
