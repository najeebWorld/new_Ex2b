#include "game.hpp"
#include <iostream>
#include "player.hpp"
#include <stdexcept>
#include <string>
#include <random>
#include <time.h>
#include "card.hpp"
#include <cstdlib>

#define max_cards = 52;

using namespace std;
using namespace ariel;

//Game :: Game(){}

Game::Game(Player &p1,Player &p2) : playerP1(p1),playerP2(p2){
    
    playerP1.setstacksize(26);
    playerP2.setstacksize(26);
    
    try{
        std::cout <<"start" << std ::endl;
         Deck.clear();
         Deck = fulldeck();
         Deck= shuffle(Deck);
         shareCards();
         lastTurn ="";
         Winner = "";
         log = "";
         countGame=0; 
    }
    catch(const std::exception& e)
    {
        std::cerr<<"error during strating the game" <<e.what()<<'\n';
    }

 }

 

 

 void Game::shareCards(){
    std::vector<card>::size_type size = Deck.size();

    for(std::vector<card>::size_type i = 0; i < size / 2; i++){
        playerP1.cards.push_back(Deck[i]);
        Deck.pop_back();
        playerP2.cards.push_back(Deck[i + size / 2]);
        Deck.pop_back();
    }
}

Game::~Game(){
    cout<<"thr game has been deleted"<<std::endl;
}


void Game::playAll(){
    while(playerP1.stacksize() > 0)
    {
        playTurn();
    }
}
void Game::playTurn(){

    if(playerP1.stacksize() == 0 || playerP2.stacksize() == 0)
    {
        throw "the cards are over, please start new game";
    }
    
     if (&playerP1 == &playerP2)
     {
         throw "You cant play against yourself";
     }

    int flag = 1;
    int cardsWon = 0; 
    log = "";

     while (flag)
     {
        int size = playerP2.stacksize();
        int taken = playerP2.cardesTaken();

         countGame++;
         flag = 0;

         card turnCard1;
         card turnCard2;

        // first lets draw
        if(playerP1.stacksize() > 0 && playerP2.stacksize()>0){
            //each players have cards more than 0
            //take one cards from each player
             turnCard1 = this->playerP1.getcard();
             turnCard2 = playerP2.getcard();
            cardsWon +=2;
        }
        // if cant draw divide the cards
        else{
            playerP1.finishRound(cardsWon/2);
            playerP1.finishRound(cardsWon/2);
        }

            // now play the turn
            Value v = turnCard1.faceValue;
            Value v2 = turnCard2.faceValue;
            int num1 = turnCard1.getValue(turnCard1.valueName(v));
            int num2 = turnCard2.getValue(turnCard2.valueName(v2));

            log += playerP1.getName() + " played " + turnCard1.valueName(v) + " ";
            log += playerP2.getName() + " played " + turnCard2.valueName(v2) + ". ";
            
            
            // case draw
            if(num1 == num2)
            {
                flag =1;
                log += " draw.";
                war++;

                if(playerP1.stacksize() > 0 && playerP2.stacksize() > 0 )
                {   
                    // burning card
                    turnCard1 = playerP1.getcard();
                    turnCard2 = playerP2.getcard();
                    cardsWon +=2;
                    //and go for another round
                }
                else 
                {   //else  divide the points
                    playerP1.finishRound(cardsWon/2);
                    playerP2.finishRound(cardsWon/2);
                    flag = 0;
                }
            }
            // case player one win
            else if (num1 == 1 && num2 != 2 || num1 > num2)
            {   
                log += playerP1.getName() + " Wins this turn.";
                playerP1.finishRound(cardsWon);
                playerP2.finishRound(0);
                
               
            }
            // case player 2 win
            else
            {
                log += playerP2.getName() + " Wins this turn.";
                playerP1.finishRound(0);
                playerP2.finishRound(cardsWon);
            }     
     }
}
    
    
void Game :: printLastTurn(){
    cout << lastTurn << std ::endl;
}

void Game::printWiner(){
    try
    {
        std :: cout <<"The winner is :" +Winner <<std::endl;


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void Game::printLog(){
    try
    {
        std ::cout << log <<std ::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

vector <card> Game:: swapp(vector <card> deck, size_t i, size_t j) {
    card flag = deck[i];
    deck[i] = deck[j];
    deck[j] = flag;
    return deck;
}

vector <card> Game::shuffle(vector <card> deck) {
    srand(time(0));
    vector <card> flag;
    for (size_t i = 0; i < deck.size(); i++) {

        size_t j = i + ((unsigned long)rand() % (deck.size() - i));
        flag = deck;
        deck = swapp(flag,i,j);
        //swapp(deck[k], deck[r]);
    }
    return deck;
}



vector <card> Game::fulldeck(){
    std :: cout <<"full 1" << std::endl;
    // enum Value{ace = 1 ,two  , three  , four , five  , six ,seven , eight  , nine  , ten , jack , queen , king  };
    // enum Type1{clubs, diamonds, hearts, spades};

    for(int val= ace ; val<= king; val++){
        for(int typ =clubs ; typ<= spades ;typ++){

            Deck.emplace_back(card(Value(val),Type1(typ)));
        }
    }
    return Deck;

}

void Game::printStats(){
    try
    {
        std :: cout <<"the first player is : " << playerP1.getName()<<std ::endl;
        //std :: cout << "the first player wins is :" << + playerP1.cardsWin() <<std::endl;
        // double winRate = (double)(playerP1.getWins()/playerP1.getWins());
        // std::cout <<"The win rate is : "<< winRate<< std::endl;

        std::cout <<"the secound player is : "<<playerP2.getName()<<std::endl;
        //std::cout <<"the secound player wins is : " <<playerP2.()<<std::endl;


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}





