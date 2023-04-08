/*
File card.hpp 
In this file i will determine the value and the type of 
the card.

*/
#pragma once
#include <iostream>
#include <string>


using namespace std;
using namespace ariel;




enum Value{two  , three  , four , five  , six ,seven , eight  , nine  , ten , jack , queen , king , ace };
enum Type1{clubs, diamonds, hearts, spades};


    class card {

    public : 
		char su;
		int va; 
		card();
        // card (Value faceValue=deuce, Type1 type1 = clubs):
		// type1(type1), faceValue(faceValue) {}
		card(Type1 t,Value v);
		
		card(char s, int v);

		
	    Type1 getSuit(char s);
	    int getValue(string s);
	    string typename1(Type1 s);
	    string valueName(Value v);
		Type1 type1;
		Value faceValue;
	    //string name();
    private:
       

            
    };
 