#ifndef TitleScene_hpp
#define TitleScene_hpp

#include "BaseLayer.hpp"

namespace GameSequence
{
    class TitleLayer:public BaseLayer
    {
    public:
        static Scene* createScene();
        static TitleLayer* create();
        bool init();
        void onEnter();
        
      
        void createMenu();
        void toCredit(Ref* sender);
        void toTitleOption(Ref* sender);
        void toStageSelect(Ref* sender);
        
        virtual bool onTouchBegan(Touch* touch,Event* event);
        virtual void onTouchMoved(Touch* touch,Event* event);
        virtual void onTouchEnded(Touch* touch,Event* event);
        virtual void onTouchCancelled(Touch* touch,Event* event);
    private:
        TitleLayer();
        ~TitleLayer();
        TitleLayer(const TitleLayer& );
        TitleLayer operator=(const TitleLayer& );
    };
}

#endif /* TitleScene_hpp */
