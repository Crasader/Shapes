#include "CSVFileLoader.hpp"

#include <string>
#include <fstream>
#include <sstream>


using namespace std;

list<double> loadCSVFile(string csvFilename)
{
    string fullPath="/Users/sugiharayuukana/cocos2d-x/Game/Shapes_and_Beats/Resources/musicfiles/"+csvFilename;
    //ifstream ifs(fullPath);
    string path=cocos2d::FileUtils::getInstance()->fullPathForFilename(csvFilename);
    ifstream ifs(path);
    if(!ifs)
    {
        cout << fullPath << "は見つかりませんでした." <<endl;
        exit(1);
    }
    
    list<double> timingList;
    string line;
    while(getline(ifs,line))
    {
        string time;
        istringstream stream(line);
        while( getline(stream,time,',') )
              {
                  timingList.push_back(stod(time));
              }
    }
    
    return timingList;
}
