/*
Utah McEntire
CSCI 3110-001
Project #4
Due: 10/10/19
*/

#include <iostream>
#include "card.h"
using std::ostream;

Card::Card(){ //used comparison to default -1 values instead of hasPlayed;
	pointValue=-1;
	cardFace=-1;
}

Card::Card(int face, suit st){
	if(face==1){
		pointValue=15;
		cardFace=1;
	}
	else if(face>=10){
		pointValue=10;
		cardFace=face;
	}
	else{
		pointValue=face;
		cardFace=face;
	}
	cardSuit=st;
}

// overload the << operator to display the card
ostream& operator<<(ostream& os, const Card& cd){
	os<<cd.getFaceValue()<<cd.getSuit()<<"["<<cd.getPointValue()<<"] ";
	return os;
}

// compare and return true if *this has a lesser point value than cd, false otherwise
bool Card::operator<(const Card& cd) const{
	return (pointValue<cd.getPointValue());
}

// compare and return true if *this has a larger point value than cd, false otherwise
bool Card::operator>(const Card& cd) const{
	return (pointValue>cd.getPointValue());
}

// compare and return true if *this has the same point value as cd, false otherwise
bool Card::operator==(const Card& cd) const{
	return (pointValue==cd.getPointValue());
}

// return the point value of the card: Ace: 15, Faces: 10, Numbers: the number
int Card::getPointValue() const{
	return pointValue;
}

// return the face value of the card: Ace: 0, 2: 1, 3:2, .... Queen:11, King:12
int Card::getFaceValue() const{
	return cardFace;
}

// return the card's suit: clubs, hearts, spades, diamonds
suit Card::getSuit() const{
	return cardSuit;
}

