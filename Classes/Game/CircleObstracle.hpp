//
//  CIrcleObstracle.hpp
//  Shapes_and_Beats-mobile
//
#ifndef CIrcleObstracle_hpp
#define CIrcleObstracle_hpp

#include "Obstracle.hpp"

namespace Game
{
    class CircleObstracle:public Obstracle
    {
    public:
        CircleObstracle();
        ~CircleObstracle();
        
        static CircleObstracle* create(Vec2 initPos);
        bool init(Vec2 initPos);
        void doAnimation();
        virtual void update();
        bool isActive(Size windowSize) const ;
    protected:
        float mRadius=150;
        Color4F mColor;
        DrawNode* mCircle;
    };
}

#endif /* CIrcleObstracle_hpp */
