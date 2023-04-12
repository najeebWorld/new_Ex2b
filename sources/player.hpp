#pragma once
#include <string>
#include "card.hpp"
#include <vector>


using namespace std;
namespace ariel{

//using namespace ariel;
    class Player {
        public: 
            Player(string name);

            int cardesTaken();
            int stacksize();
            void setcardesTaken(int cards);
            void setstacksize(int number);           

            vector <card> getDeck();
            void addtoDeck(card card1);

            string getName();//return the name 
            void setName(string name);

            card getcard(vector <card> cardes);
            void setSuccess();

            bool isPlaying();
            void setStatusPlay(bool turn);//set if the player is playing or not
            vector <card> cards;
            void setWinNum(int num);
            int getWinNum();
        private:
            string name;
            bool playing;
            int cards_win , cards_left;
            int winNum;
            int success; 

    };

}
