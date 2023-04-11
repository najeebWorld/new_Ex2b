#pragma once
#include <string>
#include "card.hpp"
#include <vector>


using namespace std;
namespace ariel{

//using namespace ariel;
    class Player {
        public: 
            Player();//default constractor
            Player(string name);
            // Player(char* name) : name(name){} 
            void stacksize(int n);
            int stacksize();

            //Player fullSize();//creat player with full cards
            //void shuffle();//Mixes the cards
            int cardesTaken();
            int cardsGo();
            //void setCardsGo(int cards);
            int cardsWin();
            void setCardsWin(int cards);
            
            vector <card> getDeck();
            void setDeck(card c1);
          //  int cardsTaken();//prints the cards that this player won. 
            string getName();//return the name 
            void setName(string name);
            card getcard();
            int getWins();
            void setWins();
            void addWinCards(int win);
            void setCardsGo(int number);           
            bool isPlaying();
            void setStatusPlay(bool turn);//set if the player is playing or not
            vector <card> cards;

        private:
            string name;
            bool playing;
            int cards_win , cards_go;
            int wins;
    };

}
