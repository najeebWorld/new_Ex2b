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
    playerP1.setcardesTaken(0);
    playerP2.setcardesTaken(0);
    try{
        std::cout <<"start" << std ::endl;
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

 Game :: ~Game(){
    cout <<"the game has been deleted"<< std:: endl;
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
        countGame++;
        flag = 0;

        card turnCard1;
        card turnCard2;


        if(playerP1.stacksize() > 0 && playerP2.stacksize()>0){
            //each players have cards more than 0
            //take one cards from each player
            turnCard1 = playerP1.getcard(playerP1.cards);
            turnCard2 = playerP2.getcard(playerP2.cards);
            cardsWon +=2;
        }

        else{
            if(cardsWon ==0 )
            {
                throw "the cards finished";
            }

           
            if(cardsWon)
            {   
                countGame++;
                playerP1.setcardesTaken(cardsWon/2);
                playerP1.setWinNum(1);
                playerP2.setcardesTaken(cardsWon/2);
                playerP2.setWinNum(1);
                break;
            }

            
            Value v = turnCard1.faceValue;
            Value v2 = turnCard2.faceValue;
            int num1 = turnCard1.getValue(turnCard1.valueName(v));
            int num2 = turnCard2.getValue(turnCard2.valueName(v2));

            log += playerP1.getName() + " played " + turnCard1.valueName(v) + " ";
            log += playerP2.getName() + " played " + turnCard2.valueName(v2) + ". ";
            
            

            if(num1 == num2)
            {
                flag =1;
                log += " new war";
                war++;

                if(playerP1.stacksize() > 0 && playerP2.stacksize() > 0 )
                {
                    turnCard1 = playerP1.getcard(playerP1.cards);
                    turnCard2 = playerP2.getcard(playerP2.cards);
                    cardsWon +=2;
                }
                else if(cardsWon)
                {//no more cards for war
                    countGame++;
                    playerP1.setcardesTaken(cardsWon/2);
                    playerP1.setWinNum(1);
                    playerP2.setcardesTaken(cardsWon/2);
                    playerP2.setWinNum(1);
                    flag=0;
                }
            }

            else if (num1 == 1 && num2 != 2 || num1 > num2)
            {
                log += playerP1.getName() + " Wins this turn.";
                countGame++;
                if(cardsWon){
                     playerP1.setcardesTaken(cardsWon);
                     playerP1.setWinNum(1);
                     playerP2.setWinNum(1);  
                }
               
            }
            else
            {
                log += playerP2.getName() + " Wins this turn.";
                playerP2.setcardesTaken(cardsWon);
                playerP2.setWinNum(1);
                playerP1.setWinNum(1);
            } 
        }
        
     }}
    
    
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
void Game::GameOver(){
    cout<<"reset the game"<<std::endl;
    playerP1.setstacksize(0);
    playerP2.setcardesTaken(0);
 };





