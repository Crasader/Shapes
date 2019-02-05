#ifndef Obstracle_hpp
#define Obstracle_hpp

#include <iostream>
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

namespace Game
{
    class Obstracle:public Sprite
    {
    public:
        Obstracle();
        virtual ~Obstracle();
        virtual bool init();
        virtual void doAnimation()=0;
        virtual void update()=0;
        virtual bool isActive(Size windowSize) const;
    protected:
        bool mActive;
    };
}

#endif /* Obstracle_hpp */
