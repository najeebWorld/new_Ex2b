// #pragma once
#include "player.hpp"
#include <iostream>
#include "card.hpp"
#include <vector>
#include <algorithm>
#include "game.hpp"


using namespace std;
using namespace ariel;

Player::Player(string name):name(name),cards_left(0),cards_Taken(0){}
    
 
    

void Player :: setcardesTaken(int cards){
    this->cards_Taken +=cards;
}

int Player::cardesTaken(){
    return this->cards_Taken;
}
int Player::stacksize(){
    return this->cards_left;
}

void Player :: setstacksize (int cards){
    this->cards_left = cards;
}

card Player::getcard(vector <card> cardes){
    if(cardes.empty())
    {
        throw std::out_of_range("there is no more cards");
    }
    card c1 = cardes.front();
    cards.erase(cardes.begin());
    return c1;

}//get thr firsr card and remove it from the vector



void Player::setName(string name){
    this->name = name;
}

vector <card> Player :: getDeck(){
    return this->cards;
}

void Player::setWinNum(int num)
{
    winNum +=num;
}

int Player::getWinNum()
{
    return winNum;
}


string Player::getName(){
    
    return this->name;
}
void Player::setSuccess()
{
    success++;
}


 bool Player::isPlaying(){
    return this->playing;
 }

 void Player::setStatusPlay(bool turn ){
    this->playing = turn;
 }

 void Player :: addtoDeck(card c1){
    
        this->cards.push_back(c1);
    
 }




