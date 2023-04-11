
#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "vector"

#include "player.hpp"

 namespace ariel{
    class Game {
        
        public : 
            Game();//default constructor.
            Game(Player & p1,Player & p2) ;
            void playTurn();//play the game.
            vector <card> fulldeck();
            void printLastTurn();
            vector <card> shuffle(vector <card> deck);
            vector <card> swapp(vector <card> deck,size_t i,size_t j) ;
            void createDeck();
            void playAll(); //playes the game untill the end
            void printWiner(); // prints the name of the winning player
            void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
            void printStats();
            //vector <string> players();//retuen the players
            
            //int playerSize();//return the size of players
           // Player playerP1,playerP2;
            int rounds; //maybe I will not use them 
            int Max_rounds;
           


        private:

            Player & playerP1;
            Player & playerP2;
            string lastTurn;
            string log; 
            string Winner;
           // string p1,p2;
           vector <card> Deck;
           



        



    };
 }
 