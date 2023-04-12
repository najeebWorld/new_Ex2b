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

void Game::playTurn(){

    bool flag = true;
    card c1,c2;

   // while(flag)
    
        if(playerP1.stacksize() == 0 || playerP2.stacksize() == 0)
    {
        throw std::runtime_error("game over");
        GameOver();
        

    }
    if(playerP1.stacksize()==0 && playerP2.stacksize() != 0)
    {
        throw std::runtime_error(playerP1.getName() + "dont have cards");
        
    }
    if(playerP2.stacksize()==0 && playerP1.stacksize() != 0)
    {
        throw std :: runtime_error(playerP2.getName() + "dont have cards");
    }

    try {

        card turnCard1 = playerP1.getcard(playerP1.cards);
        card turnCard2 = playerP2.getcard(playerP2.cards);
        
        Value v = turnCard1.faceValue;
        Value v2 = turnCard2.faceValue;
        int num1 = turnCard1.getValue(turnCard1.valueName(v));
        int num2 = turnCard2.getValue(turnCard2.valueName(v2));


        if(num1>num2){//its happen only when player1 has bigger card than player2
            
            playerP1.setWinNum(2);
            lastTurn = playerP1.getName() +" played " + turnCard1.valueName(v) + ". "; 
            lastTurn += playerP2.getName() + " played " + turnCard2.valueName(v2) + ". ";
            lastTurn += playerP1.getName()+ " win this turn ";
        }
        if(num1< num2){
            
            playerP2.setWinNum(2);
            lastTurn = playerP2.getName() + " played " + turnCard2.valueName(v2) + " . ";
            lastTurn += playerP1.getName() +  " played " + turnCard1.valueName(v) + " . ";
            lastTurn += playerP2.getName()+ " win this turn ";

        }
        else if(num1 == num2){
            
            int war = 1;

            for(int i =0 ; i < 4 ; i++){
                turnCard1 = playerP1.getcard(playerP1.cards);
                turnCard2 = playerP2.getcard(playerP2.cards);

                Value v1 = turnCard1.faceValue;
                Value v3 = turnCard2.faceValue;
                int num2 = turnCard1.getValue(turnCard1.valueName(v1));
                int num3 = turnCard2.getValue(turnCard2.valueName(v3));

                if(i == 3 && num2==num3){
                    i=0;
                    war++;

                }
            }
            //player 1 win the war 
            if(turnCard1.getValue(turnCard1.valueName(turnCard1.faceValue)) > turnCard2.getValue(turnCard2.valueName(turnCard2.faceValue))){
                
                playerP1.setWinNum(10*war);
                lastTurn = playerP1.getName() + " played " + turnCard2.valueName(v)+ ". ";
                lastTurn += playerP2.getName() +  " played " + turnCard1.valueName(v) + ". ";
                lastTurn += playerP1.getName()+ " win this war ";
                cout << playerP1.getName() + " win this war " << std::endl;
            }
            //player 2 win the war
            else if(turnCard1.getValue(turnCard1.valueName(turnCard1.faceValue)) < turnCard2.getValue(turnCard1.valueName(turnCard2.faceValue))){
                
                playerP2.setWinNum(10*war);
                lastTurn = playerP2.getName() + " played " + turnCard2.valueName(v)+ ". ";
                lastTurn += playerP1.getName() +  " played " + turnCard1.valueName(v) + ". ";
                lastTurn += playerP2.getName()+ " win this war ";
                cout << playerP2.getName() + " win this war " << std::endl;
        }


    }

    }
    
    
        catch (const std:: exception& e){
        std::cerr<<"Somthing happen in the game : " <<e.what()<<std::endl;
    }


}


void Game::printLastTurn(){

    try{
        std :: cout << lastTurn << std::endl;
    }

    catch (std::exception& e){
        throw std::runtime_error ("somthing happen with the last turn");
    }


    }
    
    


void Game::playAll(){

    try{
        while (playerP1.getDeck().size() > 0 || playerP2.getDeck().size() > 0)
        
        {
            playTurn();
            log += lastTurn +"\n";
        }
        
        if(playerP1.getWinNum() > playerP2.getWinNum())
        {
            playerP1.setSuccess();
            Winner =playerP1.getName();
        }
        if(playerP1.getWinNum() < playerP2.getWinNum())
        {
            playerP2.setSuccess();
            Winner = playerP2.getName();
        }

        playerP1.setcardesTaken(0);
        playerP2.setcardesTaken(0);

    }
    catch (std ::exception& e)
    {
        throw std ::runtime_error("error happen durring the game" + std::string (e.what()));
    }
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





