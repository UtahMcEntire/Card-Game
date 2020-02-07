/*
Utah McEntire
CSCI 3110-001
Project #4
Due: 10/10/19
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include "deck.h"
#include "player.h"
using std::cout;
using std::endl;

int main(){
	string name1, name2;
	int x, hand=1;

	std::ifstream myIn;
	myIn.open("cardgame.txt"); //Input filename
	assert(myIn);

	myIn>>name1>>name2>>x; //Set player names & seed
	Player Player1(name1);
	Player Player2(name2);
	srand(x);

	Deck deck; //Instatiate deck, readout in order, shuffle, readout after shuffle
	cout<<deck<<endl;
	deck.Shuffle();
	cout<<deck<<endl;
	
	for(int z=0; z<3; z++){ //initial drawing of cards
		Player1.drawCard(deck);
		Player2.drawCard(deck);
	}
	
	while(!deck.isEmpty() || !Player2.emptyHand()){ //main play loop
		if(hand!=1)
			cout<<endl;
		//pre-play
		cout<<hand<<") "<<Player1.getName()<<"  "<<Player1<<" - "<<Player2.getName()<<"  "<<Player2<<endl;
		Card p1(Player1.playCard());
		Card p2(Player2.playCard());
		//post-play
		if(p1>p2){ //If player1 wins that hand
			Player1.addScore(p1);
			Player1.addScore(p2);
			cout<<hand<<") "<<Player1.getName()<<"* "<<Player1<<" - "<<Player2.getName()<<"  "<<Player2<<endl;
		}
		else if(p1<p2){ //if player2 wins that hand
			Player2.addScore(p1);
			Player2.addScore(p2);
			cout<<hand<<") "<<Player1.getName()<<"  "<<Player1<<" - "<<Player2.getName()<<"* "<<Player2<<endl;
		}
		else{
			cout<<hand<<") "<<Player1.getName()<<"  "<<Player1<<" - "<<Player2.getName()<<"  "<<Player2<<endl;
		}
		Player1.drawCard(deck);
		Player2.drawCard(deck);
		hand++;
	}	
	
	//output the winner + score or tie + score
	if(Player1.getScore()>Player2.getScore()){
		cout<<endl<<"Winner "<<Player1.getName()<<" "<<Player1.getScore();
	}
	if(Player2.getScore()>Player1.getScore()){
		cout<<endl<<"Winner "<<Player2.getName()<<" "<<Player2.getScore();
	}
	if(Player2.getScore()==Player1.getScore()){
		cout<<endl<<"Tie "<<Player1.getScore();
	}
	
	myIn.close();
	return 0;
}