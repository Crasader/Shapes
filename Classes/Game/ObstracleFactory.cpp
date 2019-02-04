#include "ObstracleFactory.hpp"
#include "LineObstracle.hpp"

using namespace Game;

ObstracleFactory* ObstracleFactory::instance=0;

ObstracleFactory::ObstracleFactory(){}
ObstracleFactory::~ObstracleFactory(){}
ObstracleFactory::ObstracleFactory(const ObstracleFactory& ){}
ObstracleFactory ObstracleFactory::operator=(const ObstracleFactory& ){}

ObstracleFactory* ObstracleFactory::getInstance()
{
    if(instance==nullptr) instance=new ObstracleFactory();
    return instance;
}

Obstracle* ObstracleFactory::generateObstracle(Obstracles type,Vec2 initPos)
{
    Obstracle* obst=nullptr;
    switch (type)
    {
        case O_Line:
            obst=LineObstracle::create(initPos);
            break;
        case O_Circle:
            //obst=new
            break;
        default:
            cerr << "generateObstracleの引数が違います" << endl;
            break;
    }
    
    return obst;
}

void ObstracleFactory::destroy()
{
    delete instance;
    instance=nullptr;
}
