#ifndef OBSTRACLEFACTORY_HPP
#define OBSTRACLEFACTORY_HPP

#include "cocos2d.h"
#include <list>
using namespace cocos2d;
using namespace std;
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
        bool checkGenerateTiming(float passedTime);
        static void destroy();
    private:
        static ObstracleFactory* instance;
        list<double> mTimingList;
        list<double>::iterator mIt;
        
        ObstracleFactory();
        ~ObstracleFactory();
        ObstracleFactory(const ObstracleFactory& );
        ObstracleFactory operator=(const ObstracleFactory& );
        
        
    };
}

#endif //OBSTRACLEFACTORY_HPP
