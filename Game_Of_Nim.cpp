//============================================================================
// Name        : Lab4_Lomsomboot.cpp
// Author      : On-uma  Lomsomboot
// Description : create a game of Nim playing with a robot
// using random number to choose the size of pile of marbles
// a computer mode, and the side to take the first turn
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;


//define the function
void greetingMessage(string name){
	cout<< "----------The Game Of NIM--------------"<<endl;
	cout << "Hello " << name << "!" << endl;
	cout<<  "How are you today? " <<endl;
}

void rules()
{
	cout<< "\nWe are going to play a NIM game."<<endl;
	cout<< "The computer will generate the number of the pile of marbles"
		<< "at first to start between 10-100, inclusive."
		<< "You are going to play against a computer.\n"<<endl;
	cout<< "**The rule is ***\n"<<endl;
	cout<<"You can take a number of marbles off from the pile at least 1 up to half of the a number of marbles. "<<endl;
	cout<< "who takes off the last marble loses!!!\n"<<endl;
}

int marbleSize(){
	return rand()%91+10;
}
int firstTurner(){
	return rand() % 2;
}

int compMode(){
	return rand() % 2;
}

int oneToHalfNum(int num){
	int last = floor(num/2);
	return rand()%last+1;
}

int main() {
	srand( time(0));// set the random seed

	cout<<"Enter your name "<<endl;
	string username;
	cin>> username;

	// call the function
	greetingMessage(username);
	rules();

	int cMarble = marbleSize();
	int turner = firstTurner();
	int comp = compMode();
	if(comp == 1){
		cout<<"The computer is dumb.****"<<endl;
	}
	else{
		cout<<"The computer is smart.****"<<endl;
	}
	if (turner ==1){
		cout<<"You go first !!!\n"<<endl;
	}
	else{
		cout<<"The computer goes first!!\n"<<endl;
	}

		cout<< "*****There are "<< cMarble<< " marbles on the table.******\n"<<endl;

			int choice, choice_smrtComp, choice_dmbComp;
			int numMarble;

			while(numMarble>= 1 or cMarble>1){
				//call more functions

			int takeTurn;
			// player moves the first move
			if (turner ==1 and takeTurn !=1){
				cout<<"Enter a number of marble 1- half of current marble size"<<endl;
				cin >> choice;

				while (choice<1 or choice> floor(cMarble/2)){
				cout<<"Enter a number of marble 1- half of current marble size"<<endl;
				cin >> choice;
				}
				numMarble = cMarble-choice;


				cout<<"\nThere are "<< numMarble<< " marbles left now." << endl;
			takeTurn = 0;
			}
			// player moves another move that is not the first move
			if (takeTurn == 1) {
				cout<<"Enter a number of marble 1- half of current marble size"<<endl;
				cin >> choice;

				while (choice<1 or choice> floor(numMarble/2)){
					cout<<"Enter a number of marble 1- half of current marble size"<<endl;
					cin >> choice;
				}
				numMarble -=choice;

				cout<<"\nThere are "<< numMarble << " marbles left now." << endl;

				if (numMarble <=1){
					cout<<"*****The player won*****"<<endl;

						break;
				}
			takeTurn =0;
			}
		// for a smart computer mode's turn at the first move
			if (turner == 0 and comp==0 and takeTurn !=0){
				if (cMarble>63){
					choice_smrtComp = cMarble-63;
				}
				else if (cMarble>31 and cMarble<63){
					choice_smrtComp = cMarble-31;
				}
				else if (cMarble>15 and cMarble<31){
					choice_smrtComp = cMarble-15;
				}
				else if (cMarble>=10 and cMarble<15){
					choice_smrtComp = cMarble-7;
				}
				else{
					choice_smrtComp = oneToHalfNum(cMarble);
				}
				cout<< "The computer chose "<<choice_smrtComp<< " marbles"<<endl;
				numMarble = cMarble-choice_smrtComp;
				cout<< "\nThere are "<< numMarble<< " marbles left on the table."<<endl;
			takeTurn =1;
			}

		// for a stupid computer mode's turn at the first move
			if (turner == 0 and comp==1 and takeTurn !=0){
				choice_dmbComp = oneToHalfNum(cMarble);
				cout << "The computer chose "<<choice_dmbComp<<" marbles."<<endl;
				numMarble = cMarble-choice_dmbComp ;
				cout<< "\nThere are "<< numMarble<< " marbles left on the table."<<endl;
			takeTurn =1;
			}
		// for a smart computer mode's turn at another move that not first
			if (takeTurn==0 and comp==0){
				cout<<"first turner"<< turner<<endl;
				cout<< "comp mode"<< comp<<endl;
				if (numMarble>63){
					choice_smrtComp = numMarble-63;
				}
				else if (numMarble>31 and numMarble<63){
					choice_smrtComp = numMarble-31;
				}
				else if (numMarble>15 and numMarble<31){
					choice_smrtComp = numMarble-15;
				}
				else if (numMarble>7 and numMarble<15){
					choice_smrtComp = numMarble-7;
				}
				else if (numMarble>3 and numMarble<7){
					choice_smrtComp = numMarble-3;
				}
				else{
					choice_smrtComp = oneToHalfNum(numMarble);
				}
				cout<< "The computer chose "<<choice_smrtComp<< " marbles"<<endl;
				numMarble -= choice_smrtComp;
				cout<< "\nThere are "<< numMarble<< " marbles left on the table."<<endl;
				if (numMarble <=1){
					cout<<"*****The computer won*****"<<endl;

					break;
				}
			takeTurn =1;
			}

		// for a stupid computer mode's turn at another move that not first
			if (takeTurn==0 and comp==1){
				choice_dmbComp = oneToHalfNum(numMarble);
				cout << "The computer chose "<<choice_dmbComp<<" marbles."<<endl;

				numMarble -= choice_dmbComp ;
				cout<< "\nThere are "<< numMarble<< " marbles left on the table."<<endl;
				if (numMarble <=1){
					cout<<"*****The computer won*****"<<endl;

					break;
				}
			takeTurn =1;
			}


		}



	    return 0;
	}

