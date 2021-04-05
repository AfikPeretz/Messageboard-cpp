
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Direction.hpp"
#include "Board.hpp"

using ariel::Direction;
using namespace std;

namespace ariel{
    Board::Board(){}

    string Board::read(unsigned int row,unsigned int colum, Direction direction,unsigned int len){
        string msg; 
        char sign='_';

        for (size_t i = 0; i < len; i++)
        {           
          if(msg_bd[make_pair(row,colum)] > 0){ 
              sign=msg_bd[make_pair(row,colum)];
          }
          else{
                sign='_'; //A place without a signal
            }
            msg+=sign;
            if(Direction::Horizontal==direction){  //Check the direction you need 
                colum++;
            }
            else{
                row++; 
            }   
        }       
        return msg;
    }
    
    void Board::post(unsigned int row,unsigned int colum,Direction direction,string st){
        for (size_t i = 0; i < st.length(); i++)
        {
            msg_bd[make_pair(row,colum)]=st.at(i); 
            
            //Check the direction you need to go
            if(Direction::Horizontal==direction){
                colum++;
            }
            else{
                row++;    
            }
        }
     cout<< "post" <<endl;
    }

    void Board::show(){
        unsigned int col=0;
        unsigned int i=0;
        for(auto elem : msg_bd){  // An iterator 
            
           // First condition for passing on the first element
            if(i==0){
                std::cout << elem.second<<endl;
                i++;
                col=elem.first.first; // Save the previous position (
            }
            else{
                if(col != elem.first.first){ 
                    std::cout<<endl;
                    std::cout << elem.second;
                    col=elem.first.first;
                }
                else{
                   std::cout << elem.second; //printing
                }         
            }    
        }
        cout<<endl;
        cout<< "show" <<endl;
    }
}
