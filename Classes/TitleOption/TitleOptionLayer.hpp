//
//  TitleOptionLayer.hpp
//  Shapes_and_Beats-mobile
//
//  Created by 杉原悠哉 on 2019/02/02.
//

#ifndef TitleOptionLayer_hpp
#define TitleOptionLayer_hpp

#include "BaseLayer.hpp"

namespace GameSequence
{
    class TitleOptionLayer:public BaseLayer
    {
    public:
        static Scene* createScene();
        static TitleOptionLayer* create();
        bool init();
        void onEnter();
        
        void changeScene();
        virtual bool onTouchBegan(Touch* touch,Event* event);
        virtual void onTouchMoved(Touch* touch,Event* event);
        virtual void onTouchEnded(Touch* touch,Event* event);
        virtual void onTouchCancelled(Touch* touch,Event* event);
    private:
        TitleOptionLayer();
        ~TitleOptionLayer();
        TitleOptionLayer(const TitleOptionLayer& );
        TitleOptionLayer operator=(const TitleOptionLayer& );
    };
}


#endif /* TitleOptionLayer_hpp */
