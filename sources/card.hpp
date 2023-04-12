/*
File card.hpp 
In this file i will determine the value and the type of 
the card.

*/
#pragma once
#include <iostream>
#include <string>


using namespace std;
 namespace ariel{




enum Value{ace = 1 ,two  , three  , four , five  , six ,seven , eight  , nine  , ten , jack , queen , king  };
enum Type1{clubs, diamonds, hearts, spades};


    class card {

    public : 
		char suit;
		int value; 
		card();
        // card (Value faceValue=deuce, Type1 type1 = clubs):
		// type1(type1), faceValue(faceValue) {}
		card(Value val,Type1 typ);
		
		//card(char s, int v);

		
	    Type1 getSuit(char sui);
	    int getValue(string val);
	    string typename1(Type1 typ);
	    string valueName(Value val);
		Type1 type1;
		Value faceValue;
	    //string name();
    private:
       

            
    };
 }