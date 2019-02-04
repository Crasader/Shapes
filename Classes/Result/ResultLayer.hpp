#ifndef ResultLayer_hpp
#define ResultLayer_hpp

#include "BaseLayer.hpp"

namespace GameSequence
{
    class ResultLayer:public BaseLayer
    {
    public:
        static Scene* createScene();
        static ResultLayer* create();
        bool init();
        void onEnter();
        
        void toGame(Ref* sender);
        void toStageSelect(Ref* sender);
        virtual bool onTouchBegan(Touch* touch,Event* event);
        virtual void onTouchMoved(Touch* touch,Event* event);
        virtual void onTouchEnded(Touch* touch,Event* event);
        virtual void onTouchCancelled(Touch* touch,Event* event);
    private:
        ResultLayer();
        ~ResultLayer();
        ResultLayer(const ResultLayer& );
        ResultLayer operator=(const ResultLayer& );
    };
}


#endif /* ResultLayer_hpp */
