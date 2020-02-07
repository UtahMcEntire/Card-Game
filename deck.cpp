/*
Utah McEntire
CSCI 3110-001
Project #4
Due: 10/10/19
*/

#include <iostream>
#include <algorithm>
#include "card.h"
#include "deck.h"
using std::ostream;
using std::string;

// default constructor
Deck::Deck(){
	for(int i=0; i<52; i++){//52 cards
		int faceValue=(i%13)+1; //cycles through 1-13 four times
		if(i<13)
			theDeck[i]=Card(faceValue, clubs);
		else if(i<26)
			theDeck[i]=Card(faceValue, hearts);
		else if(i<39)
			theDeck[i]=Card(faceValue, spades);
		else
			theDeck[i]=Card(faceValue, diamonds);
	}
	topCard=51; //index of the top to draw from card
}

// Remove the top card from the deck and return it.
Card Deck::dealCard(){
	if(!isEmpty())
		return theDeck[topCard--];
}

// Shuffle the cards in the deck
void Deck::Shuffle(){
	std::random_shuffle(std::begin(theDeck), std::end(theDeck));
}

// return true if there are no more cards in the deck, false otherwise
bool Deck::isEmpty(){
	return(topCard==-1);
}

//overload << operator to display the deck
ostream& operator<<(ostream& os, const Deck& dk){
	for (int i=52; i>=0; i--){
		string suit;
		int gotSuit=dk.theDeck[i].getSuit(); //only has to retrieve these values once per loop
		int gotFaceValue=dk.theDeck[i].getFaceValue();
		int gotPointValue=dk.theDeck[i].getPointValue();
		if(gotSuit==0){
			suit="H";
		}
		else if(gotSuit==1){
			suit="S";
		}
		else if(gotSuit==2){
			suit="D";
		}
		else if(gotSuit==3){
			suit="C";
		}
		//output the deck
		if(gotFaceValue==1){
			os<<"A"<<suit<<"["<<gotPointValue<<"]";
		}
		else if(gotFaceValue>1 && gotFaceValue<=10){
			os<<gotFaceValue<<suit<<"["<<gotPointValue<<"]";
		}
		else if(gotFaceValue==11){
			os<<"J"<<suit<<"["<<gotPointValue<<"]";
		}
		else if(gotFaceValue==12){
			os<<"Q"<<suit<<"["<<gotPointValue<<"]";
		}
		else if(gotFaceValue==13){
			os<<"K"<<suit<<"["<<gotPointValue<<"]";
		}
		if(i%13==0 && i!=52){
			os<<std::endl;
		}
		else if(i!=52){
			os<<"  ";
		}
	}
	return os;
}
