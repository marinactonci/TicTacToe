#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//Variables
//-------------------------------------------------------------------------------------------------------
char field[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}, position, check, player = 'X', answer;
int moveCounter = 0, scoreX = 0, scoreO = 0;
bool victory = false, positionTaken = false;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Constructors
//----------------------
void ShowField();
void Input();
void PlayerSwitch();
void VictoryCheck();
int Repeat();

//Main function
//-----------------------------------------------------------------------------------------------------------------------------------------------
int main(){
	cout<<"Welcome to the cross-circle game!\nThe game is played by entering the number of the desired position in the field shown below.";
	cout<<"\nScore: \nX : O\n";
	cout<<scoreX<<" : "<<scoreO<<"\n";
	ShowField();
	cout<<"\nPlayer X starts first.\n";
	while(victory == false){
		Input();
		ShowField();
		PlayerSwitch();
		VictoryCheck();
	}
	return 0;
}

void ShowField(){ //The field is displayed according to the state of the game.
	system("color 70");
	cout<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<field[i][j]<<"   ";
		}
		cout<<endl<<endl;
	}
}
void Input(){  //The position is entered and the field is updated
	cout<<"Player "<<player<<", enter your position: ";
	cin>>position;
	positionTaken = false;
	//---------------------------------------------------------------------------------------------------------------	
	if(position == '1'){ //If the selected position in the field is marked with a number and not with x or o then it is free
		if(field[0][0] == '1'){
			field[0][0] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;  //Otherwise, the input is repeated *
		}
	}
	else if(position == '2'){
		if(field[0][1] == '2'){
			field[0][1] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;
		}
	}
	else if(position == '3'){
		if(field[0][2] == '3'){
			field[0][2] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;
		}
	}
	else if(position == '4'){
		if(field[1][0] == '4'){
			field[1][0] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;
		}
	}
	else if(position == '5'){
		if(field[1][1] == '5'){
			field[1][1] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;
		}
	}
	else if(position == '6'){
		if(field[1][2] == '6'){
			field[1][2] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;
		}
	}
	else if(position == '7'){
		if(field[2][0] == '7'){
			field[2][0] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;
		}
	}
	else if(position == '8'){
		if(field[2][1] == '8'){
			field[2][1] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;
		}
	}
	else if(position == '9'){
		if(field[2][2] == '9'){
			field[2][2] = player;
			moveCounter++;
		}
		else{
			positionTaken = true;
		}
	}
	else{ //If something other than the 0-9 character is entered, the input is repeated
		cout<<"Incorrect input. Please repeat your input.\n";
		Input();
	}
	if(positionTaken == true){ // *
		cout<<"Position is taken! Please repeat your input.\n";
		Input();
	}
}
void PlayerSwitch(){ //After player x entered his position, we swap to player o and vice versa
	if(player == 'X'){
		player = 'O';
	}
	else{
		player = 'X';
	}
}
void VictoryCheck(){
	//Checking if player x won in any of the rows
	//-------------------------------------------------------------------------------------------------------------
	if(field[0][0]== 'X' && field[0][1]== 'X' && field[0][2]== 'X'){
		victory = true;
		cout<<"Player X won!";
		scoreX++;
		Repeat();
	}
	else if(field[1][0]== 'X' && field[1][1]== 'X' && field[1][2]== 'X'){
		victory = true;
		cout<<"Player X won!";
		scoreX++;
		Repeat();
	}
	else if(field[2][0]== 'X' && field[2][1]== 'X' && field[2][2]== 'X'){
		victory = true;
		cout<<"Player X won!";
		scoreX++;
		Repeat();
	}
	
	//Checking if player X won in any of the columns
	//-------------------------------------------------------------------------------------------------------------
	else if(field[0][0]== 'X' && field[1][0]== 'X' && field[2][0]== 'X'){
		victory = true;
		cout<<"Player X won!";
		scoreX++;
		Repeat();
	}
	else if(field[0][1]== 'X' && field[1][1]== 'X' && field[2][1]== 'X'){
		victory = true;
		cout<<"Player X won!";
		scoreX++;
		Repeat();
	}
	else if(field[0][2]== 'X' && field[1][2]== 'X' && field[2][2]== 'X'){
		victory = true;
		cout<<"Player X won!";
		scoreX++;
		Repeat();
	}
	
	//Checking if player X won in any of the diagonals
	//-------------------------------------------------------------------------------------------------------------
	else if(field[0][0]== 'X' && field[1][1]== 'X' && field[2][2]== 'X'){
		victory = true;
		cout<<"Player X won!";
		scoreX++;
		Repeat();
	}
	else if(field[2][0]== 'X' && field[1][1]== 'X' && field[0][2]== 'X'){
		victory = true;
		cout<<"Player X won!";
		scoreX++;
		Repeat();
	}
	
	//Checking if player O won in any of the rows
	//-------------------------------------------------------------------------------------------------------------
	else if(field[0][0]== 'O' && field[0][1]== 'O' && field[0][2]== 'O'){
		victory = true;
		cout<<"Player O won!";
		scoreO++;
		Repeat();
	}
	else if(field[1][0]== 'O' && field[1][1]== 'O' && field[1][2]== 'O'){
		victory = true;
		cout<<"Player O won!";
		scoreO++;
		Repeat();
	}
	else if(field[2][0]== 'O' && field[2][1]== 'O' && field[2][2]== 'O'){
		victory = true;
		cout<<"Player O won!";
		scoreO++;
		Repeat();
	}
	
	//Checking if player O won in any of the columns
	//-------------------------------------------------------------------------------------------------------------
	else if(field[0][0]== 'O' && field[1][0]== 'O' && field[2][0]== 'O'){
		victory = true;
		cout<<"Player O won!";
		scoreO++;
		Repeat();
	}
	else if(field[0][1]== 'O' && field[1][1]== 'O' && field[2][1]== 'O'){
		victory = true;
		cout<<"Player O won!";
		scoreO++;
		Repeat();
	}
	else if(field[0][2]== 'O' && field[1][2]== 'O' && field[2][2]== 'O'){
		victory = true;
		cout<<"Player O won!";
		scoreO++;
		Repeat();
	}
	
	//Checking if player O won in any of the diagonals
	//-------------------------------------------------------------------------------------------------------------
	else if(field[0][0]== 'O' && field[1][1]== 'O' && field[2][2]== 'O'){
		victory = true;
		cout<<"Player O won!";
		scoreO++;
		Repeat();
	}
	else if(field[2][0]== 'O' && field[1][1]== 'O' && field[0][2]== 'O'){
		victory = true;
		cout<<"Player O won!";
		scoreO++;
		Repeat();
	}
	if(moveCounter == 9){
		cout<<"Draw!";
		Repeat();
	}
}
int Repeat(){
	cout<<"\nDo you want to play again?(Y/N):    " ;
	cin>>answer;
	if(answer == 'Y' || answer == 'y'){ //In case the user wants to play again, all variables are reset
		victory = false;
		moveCounter = 0;
		player = 'X';
		field[0][0] = '1';
		field[0][1] = '2';
		field[0][2] = '3';
		field[1][0] = '4';
		field[1][1] = '5';
		field[1][2] = '6';
		field[2][0] = '7';
		field[2][1] = '8';
		field[2][2] = '9';
		system("cls");
		main();
	}
	else if(answer == 'N' || answer == 'n'){ //If the user answered 'no', program closes and notifies user about it
		cout<<"\nExiting...";
		return 0;
	}
}
