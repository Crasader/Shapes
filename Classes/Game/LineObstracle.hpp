#ifndef LineObstracle_hpp
#define LineObstracle_hpp

#include "Obstracle.hpp"

namespace Game
{
    class LineObstracle:public Obstracle
    {
    public:
        LineObstracle();
        ~LineObstracle();
        
        static LineObstracle* create(Vec2 initPos);
        bool init(Vec2 initPos);
        void doAnimation();
        virtual void update();
        
    protected:
        float mWidth=30;
        float mHeight=mWidth;
    };
}

#endif /* LineObstracle_hpp */
