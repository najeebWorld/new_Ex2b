#include "card.hpp"
#include <iostream>

#include <string>


 namespace ariel{

	card :: card (Type1 t, Value v){// constractor that get the type& value of card.
		this->type1 = t; 
		this->faceValue = v ;
	}
	
	card :: card (char s, int v){
		this->su= s;
		this->va=v ; 
	}

	Type1 card::getSuit(char s) { 
		switch (s)
		{
			case 'S' : return spades;
			case 'C' : return clubs;
			case 'D' : return diamonds;
			case 'H' : return hearts;
		}
	 }//return type1; }

	int card::getValue(string s) { 
		if(s.compare("Ace") == 0 )
			return 1;
		if(s.compare("Two") == 0)
		 	return 2;
		if(s.compare("Three") == 0)
		 	return 3;
		if(s.compare("Foue") == 0)
		 	return 4;
		if(s.compare("Five") == 0)
		 	return 5;
		if(s.compare("Six") == 0)
		 	return 6;
		if(s.compare("Seven") == 0)
		 	return 7;
		if(s.compare("Eight") == 0)
		 	return 8;
		if(s.compare("Nine") == 0)
		 	return 9;
		if(s.compare("Ten") == 0)
		 	return 10;
		if(s.compare("Jack") == 0)
		 	return 11;
		if(s.compare("Queen") == 0)
		 	return 12;
		if(s.compare("King") == 0)
		 	return 13;
		return 0 ;

	 }// return faceValue; }
	
	string card::typename1 (Type1 s) { 
		switch (s)
		{
			case hearts : return "Hearts";
			case spades : return "Spades";
			case diamonds : return "Diamonds";
			case clubs : return "Clubs";

			default : throw std :: out_of_range("Type out of range");
		}
	 }
	
	string card::valueName (Value v){ //return value in string
		switch (v)
		{
			case two : return "Two";
			case three : return "Three";
			case four : return "Four";
			case five : return "Five";
			case six : return "Six";
			case seven : return "Seven";
			case eight : return "Eight";
			case nine : return "Nine";
			case ten : return "Ten";
			case jack : return "Jack";
			case queen : return "Queen";
			case king : return "King";
			case ace : return "Ace";

			default : throw std :: out_of_range("Value out of range");
		}
	 }
	
	// string card::name() { return valueName (faceValue) + " of " + typename1(type1);}
	//string card::name() { return "";}
}