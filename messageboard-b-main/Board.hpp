#include "Direction.hpp"
#include <string>
#include <map>
using namespace std;
using ariel::Direction;


namespace ariel{

    class Board
    {
    private:

        typedef pair <unsigned int,unsigned int> Location; 
        map < Location, char> msg_bd; 
        
    public:

        Board(/* args */);
        void post(unsigned int row,unsigned int colum,Direction direction,string st);
        string read(unsigned int row,unsigned int colum,Direction direction,unsigned int len);
        void show();

    };
    

}