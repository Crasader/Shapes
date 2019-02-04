#ifndef OBSTRACLEFACTORY_HPP
#define OBSTRACLEFACTORY_HPP

#include "cocos2d.h"
using namespace cocos2d;

namespace Game
{
    class Obstracle;
    
    enum Obstracles
    {
        O_Line,
        O_Circle
    };
    
    class ObstracleFactory:public Ref
    {
    public:
        static ObstracleFactory* getInstance();
        Obstracle* generateObstracle(Obstracles type,Vec2 initPos);
        
        static void destroy();
    private:
        static ObstracleFactory* instance;
        
        ObstracleFactory();
        ~ObstracleFactory();
        ObstracleFactory(const ObstracleFactory& );
        ObstracleFactory operator=(const ObstracleFactory& );
    };
}

#endif //OBSTRACLEFACTORY_HPP
