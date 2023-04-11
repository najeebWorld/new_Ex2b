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
        std::cout <<"start" << std ::endl;
         Deck = fulldeck();
         Deck= shuffle(Deck);
         shareCards();
         lastTurn ="";
         Winner = "";
         log = "";
        
    
    //  p1.stacksize(26);
    //  p2.stacksize(26);

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
    if(playerP1.stacksize() == 0 || playerP2.stacksize() == 0)
    {
        throw std::runtime_error("game over");

    }
    if(playerP1.stacksize()==0 && playerP2.stacksize() != 0)
    {
        throw std::runtime_error(playerP1.getName() + "dont have cards");
    }
    if(playerP2.stacksize()==0 && playerP1.stacksize() != 0)
    {
        throw std :: runtime_error(playerP2.getName() + "dont have cards");
    }

    //need to add here defination if they both have the same size of cards
    //should try &playerp1 == &playerp2
    

    //if they both can play thr turn 

    try {

        card turnCard1 = playerP1.getcard();
        card turnCard2 = playerP2.getcard();
        
        Value v = turnCard1.faceValue;
        Value v2 = turnCard2.faceValue;
        int num1 = turnCard1.getValue(turnCard1.valueName(v));
        int num2 = turnCard2.getValue(turnCard2.valueName(v2));

        if(num1>num2){//its happen only when player1 has bigger card than player2
            
            lastTurn = playerP1.getName() +"played" + turnCard1.valueName(v) + ". "; 
            lastTurn += playerP2.getName() + "played" + turnCard2.valueName(v) + ". ";
            lastTurn += playerP1.getName()+ "win this turn";
        }
        if(num1< num2){

            lastTurn = playerP2.getName() + "played" + turnCard2.valueName(v)+ ". ";
            lastTurn += playerP1.getName() +  "played" + turnCard1.valueName(v) + ". ";
            lastTurn += playerP2.getName()+ "win this turn";

        }
        else if(num1 == num2){
            
            int war = 1;

            cout << " new war has begin"<< std::endl;
            for(int i =0 ; i <4 ; i++){
                turnCard1 = playerP1.getcard();
                turnCard2 = playerP2.getcard();

                Value v1 = turnCard1.faceValue;
                Value v3 = turnCard2.faceValue;
                int num2 = turnCard1.getValue(turnCard1.valueName(v1));
                int num3 = turnCard2.getValue(turnCard2.valueName(v3));

                if(i == 3 && num2==num3){
                    war++;
                    cout << " new war has begin"<< std::endl;

                }
            }

            if(turnCard1.getValue(turnCard1.valueName(turnCard1.faceValue)) > turnCard2.getValue(turnCard2.valueName(turnCard2.faceValue))){
                playerP1.setCardsWin(10*war);

                lastTurn = playerP1.getName() + "played" + turnCard2.valueName(v)+ ". ";
                lastTurn += playerP2.getName() +  "played" + turnCard1.valueName(v) + ". ";
                lastTurn += playerP1.getName()+ "win this war";
                cout << playerP1.getName() + "win this war" << std::endl;
            }

            else if(turnCard1.getValue(turnCard1.valueName(turnCard1.faceValue)) < turnCard2.getValue(turnCard1.valueName(turnCard2.faceValue))){
                
                playerP2.setCardsWin(10*war);

                lastTurn = playerP2.getName() + "played" + turnCard2.valueName(v)+ ". ";
                lastTurn += playerP1.getName() +  "played" + turnCard1.valueName(v) + ". ";
                lastTurn += playerP2.getName()+ "win this war";
                cout << playerP2.getName() + "win this war" << std::endl;
        }


    }

    }
    catch (const std:: exception& e){
        std::cerr<<"Somthing happen in the game : " <<e.what()<<std::endl;
        


}}

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
        while (playerP1.getDeck().size() || playerP2.getDeck().size())
        
        {
            playTurn();
            log += lastTurn +"\n";
        }
        
        if(playerP1.cardsWin() > playerP2.cardsWin())
        {
            playerP1.setWins();
            Winner =playerP1.getName();
        }
        if(playerP1.cardsWin() < playerP2.cardsWin())
        {
            playerP2.setWins();
            Winner = playerP2.getName();
        }

        playerP1.setCardsWin(0);
        playerP2.setCardsWin(0);

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

// void Game::createDeck() {
//     string Types [4] = {"Hart", "Diamond", "Spades", "Clubs"};
//     card temp;
//     for (int i = 0; i < 4; i++) {
//         for (int j = 2; j < 15; j++) {
//             // card temp(j, _shape[i]);
//             // Deck.push_back(temp);
//             char ch = Types[i].at(0);
//             temp(typ,j);
//             //temp(j,shape[i]);
//             Deck.emplace_back(temp);            
            
//         }
//     }
// }

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
        std :: cout << "the first player wins is :" << + playerP1.cardsWin() <<std::endl;
        // double winRate = (double)(playerP1.getWins()/playerP1.getWins());
        // std::cout <<"The win rate is : "<< winRate<< std::endl;

        std::cout <<"the secound player is : "<<playerP2.getName()<<std::endl;
        std::cout <<"the secound player wins is : " <<playerP2.cardsWin()<<std::endl;


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}





