#ifndef CreditScene_hpp
#define CreditScene_hpp

#include "BaseLayer.hpp"

namespace GameSequence
{
    class CreditLayer:public BaseLayer
    {
    public:
        static Scene* createScene();
        static CreditLayer* create();
        bool init();
        void onEnter();
        
        void changeScene();
        void createLabels();
        
        virtual bool onTouchBegan(Touch* touch,Event* event);
        virtual void onTouchMoved(Touch* touch,Event* event);
        virtual void onTouchEnded(Touch* touch,Event* event);
        virtual void onTouchCancelled(Touch* touch,Event* event);
    private:
        CreditLayer();
        ~CreditLayer();
        CreditLayer(const CreditLayer& );
        CreditLayer operator=(const CreditLayer& );
    };
}

#endif /* CreditScene_hpp */
