/*
Utah McEntire
CSCI 3110-001
Project #4
Due: 10/10/19
*/

#include <iostream>
#include "player.h"
using std::ostream;
using std::string;

Player::Player(string nm){
	name=nm;
	score=0;
	for(int z=0; z<Max_Cards; z++){
		hand[z]=*(new Card); //Initializes player deck with all -1 card values
		hasPlayed[z]=true;
	}
}
// Simulates player removing one card from hand and playing it - returns the card
// Play the card with the highest value, per the rules in the specification 
Card Player::playCard(){
	Card picked;
	int pick=0;
	if(!emptyHand()){
		for(int z=1; z<Max_Cards; z++){
			if(hand[z].getPointValue()>hand[pick].getPointValue()){ //Pick higher point value
				pick=z;
			}
			else if(hand[z].getPointValue()==hand[pick].getPointValue()){
				if(hand[z].getFaceValue()>hand[pick].getFaceValue()){ //Pick higher face value
					pick=z;
				}
				else if(hand[z].getFaceValue()==hand[pick].getFaceValue()){
					if(hand[z].getSuit()<hand[pick].getSuit()){ //Pick higher suit value
						pick=z;
					}
				}
			}
		}
		picked=hand[pick];
		hasPlayed[pick]=true;
		hand[pick]=*(new Card); //Couldn't get some functions to work soley with hasPlayed so created this
	}
	return picked;
}

// draw top card from the deck to replace played card in hand
void Player::drawCard(Deck& dk){
	if(!dk.isEmpty()){
		for(int z=0; z<Max_Cards; z++){
			if(hasPlayed[z]){
				hand[z]=dk.dealCard();
				hasPlayed[z]=false;
				return;
			}
		}
	}
}

// add the point value of the card to the player"s score
void Player::addScore(Card cd){
	score+=cd.getPointValue();
}

// return the score the player has earned so far
int Player::getScore() const{
	return score;
}

// return the name of the player
string Player::getName() const{
	return name;
} 

// return true if the player"s hand is out of cards
bool Player::emptyHand() const{
	int y=0;
	for(int z=0; z<Max_Cards; z++){
		if(hasPlayed[z]){
			y++;
		}
	}
	return y==3;
}

// overload the << operator to display cards in player"s hand (or _____ if no card)
ostream& operator<<(ostream& os, const Player& pl){
	for (int i=0; i<pl.Max_Cards; i++){
		string suit;
		int gotSuit=pl.hand[i].getSuit(); //only has to retrieve these values once per loop
		int gotFaceValue=pl.hand[i].getFaceValue();
		int gotPointValue=pl.hand[i].getPointValue();
		if(i%13==12 && i!=52){
			std::cout<<std::endl;
		}
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
		//cout the deck
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
		else{ // if card values are -1: slot in hand is empty
			os<<"_____";
		}
		os<<" ";
	}
	os<<"("<<pl.score<<")";
	return os;
}
