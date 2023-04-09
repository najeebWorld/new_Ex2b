// #pragma once
#include "player.hpp"
#include <iostream>
#include "card.hpp"
#include <vector>
#include <algorithm>
#include "game.hpp"


using namespace std;
using namespace ariel;
//vector <card> deck;

const int typs = 4;
const int val = 13; 

Player::Player(string name){
    this->name = name;
    this->cards_go = 0;//new player has no cards lose

 }
    


int Player::cardesTaken(){
    return this->cards_win;
}
int Player::cardsGo(){
    return this->cards_go;
}

void Player :: setCardsGo (int cards){
    this->cards_go = cards;
}

int Player::cardsWin(){
    return this->cards_win;
}
 
void Player::stacksize(int n){
     this->cards_go = n;
}

int Player :: stacksize(){

    return this->cards_go;
}

int Player :: cardsWin(){
    return this->cards_win;
}

card Player :: getcard(){
    card c1 = cards.front();
    cards.erase(cards.begin());
    return c1;

}

void Player :: setCardsWin(int cards){
    this->cards_win +=cards;
}

void Player::setName(string name){
    this->name = name;
}

vector <card> Player :: getDeck(){
    return this->cards;
}


string Player::getName(){
    
    return this->name;
}
void Player::setName(string name){
    this->name =name; 
}



 bool Player::isPlaying(){
    return this->playing;
 }

 void Player::setStatusPlay(bool turn ){
    this->playing = turn;
 }

 void Player :: setDeck(card c1){
    
        this->cards.push_back(c1);
    
 }

void Player::addWinCards(int win){
     this->cards_win += win;
}
int Player :: getWins()
{
    return this->wins;
}

void Player ::setWins()
{
    this->wins++;
}


