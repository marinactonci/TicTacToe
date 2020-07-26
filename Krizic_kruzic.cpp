/*
	00 01 02		1 2 3
	10 11 12		4 5 6
	20 21 22		7 8 9
*/
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//Varijable
//--------------------------------------------------------------------
char polje[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}, pozicija, provjera, igrac = 'X', odgovor;
int brojacPoteza = 0, rezultatX = 0, rezultatO = 0;
bool pobjeda = false, zauzetaPozicija = false;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Konstruktori
//---------------------------------
void PrikazPolja();
void Unos();
void IzmjenaIgraca();
void ProvjeraPobjede();
int Ponavljanje();

//Main funkcija, pozivanje svih ostalih funkcija
int main(){
	cout<<"Dobrodosli u igru krizic-kruzic!\nIgra se tako da se unese broj zeljene pozicije u ispod prikazanom polju.\n";
	cout<<"Rezultat: \tX : O\n";
	cout<<"\t\t"<<rezultatX<<" : "<<rezultatO<<"\n";
	PrikazPolja();
	cout<<"\nPrvo zapocinje igrac X.\n";
	while(pobjeda == false){
		Unos();
		PrikazPolja();
		IzmjenaIgraca();
		ProvjeraPobjede();
	}
	return 0;
}

void PrikazPolja(){ //Prikazuje se polje s obzirom na stanje igre
	system("color 70");
	cout<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<polje[i][j]<<"   ";
		}
		cout<<endl<<endl;
	}
}
void Unos(){ //Unosi se pozicija i azurira polje
	cout<<"Igrac "<<igrac<<" unesite poziciju: ";
	cin>>pozicija;
	zauzetaPozicija = false;
//-------------------------------------------------------------------------------------		
	if(pozicija == '1'){     //Ako je odabrana pozicija u nizu oznacena sa brojem, a ne sa x ili o onda je slobodna
		if(polje[0][0] == '1'){
			polje[0][0] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;  //Inace se ponavlja unos *
		}
	}
	else if(pozicija == '2'){
		if(polje[0][1] == '2'){
			polje[0][1] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;
		}
	}
	else if(pozicija == '3'){
		if(polje[0][2] == '3'){
			polje[0][2] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;
		}
	}
	else if(pozicija == '4'){
		if(polje[1][0] == '4'){
			polje[1][0] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;
		}
	}
	else if(pozicija == '5'){
		if(polje[1][1] == '5'){
			polje[1][1] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;
		}
	}
	else if(pozicija == '6'){
		if(polje[1][2] == '6'){
			polje[1][2] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;
		}
	}
	else if(pozicija == '7'){
		if(polje[2][0] == '7'){
			polje[2][0] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;
		}
	}
	else if(pozicija == '8'){
		if(polje[2][1] == '8'){
			polje[2][1] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;
		}
	}
	else if(pozicija == '9'){
		if(polje[2][2] == '9'){
			polje[2][2] = igrac;
			brojacPoteza++;
		}
		else{
			zauzetaPozicija = true;
		}
	}
	else{ //Ako je uneseno nesto osima znaka 0-9, ponavlja se unos
		cout<<"Pogresan unos. Ponovno upisite zeljenu poziciju.\n";
		Unos();
	}
	if(zauzetaPozicija == true){ // *
		cout<<"Polje je zauzeto! Ponovite unos.\n";
		Unos();
	}
}
void IzmjenaIgraca(){ //Nakon sto je igrac x unio poziciju, izmjenjuje se na igraca o i obrnuto
	if(igrac == 'X'){
		igrac = 'O';
	}
	else{
		igrac = 'X';
	}
}
void ProvjeraPobjede(){
	//Provjeravanje ako je X pobjedio u nekom od redova
	//-------------------------------------------------------------------------------------------------------------
	if(polje[0][0]== 'X' && polje[0][1]== 'X' && polje[0][2]== 'X'){
		pobjeda = true;
		cout<<"Igrac X je pobjedio!";
		rezultatX++;
		Ponavljanje();
	}
	else if(polje[1][0]== 'X' && polje[1][1]== 'X' && polje[1][2]== 'X'){
		pobjeda = true;
		cout<<"Igrac X je pobjedio!";
		rezultatX++;
		Ponavljanje();
	}
	else if(polje[2][0]== 'X' && polje[2][1]== 'X' && polje[2][2]== 'X'){
		pobjeda = true;
		cout<<"Igrac X je pobjedio!";
		rezultatX++;
		Ponavljanje();
	}
	
	//provjeravanje ako je X pobjedio u nekom od stupaca
	//-------------------------------------------------------------------------------------------------------------
	else if(polje[0][0]== 'X' && polje[1][0]== 'X' && polje[2][0]== 'X'){
		pobjeda = true;
		cout<<"Igrac X je pobjedio!";
		rezultatX++;
		Ponavljanje();
	}
	else if(polje[0][1]== 'X' && polje[1][1]== 'X' && polje[2][1]== 'X'){
		pobjeda = true;
		cout<<"Igrac X je pobjedio!";
		rezultatX++;
		Ponavljanje();
	}
	else if(polje[0][2]== 'X' && polje[1][2]== 'X' && polje[2][2]== 'X'){
		pobjeda = true;
		cout<<"Igrac X je pobjedio!";
		rezultatX++;
		Ponavljanje();
	}
	
	//provjeravanje ako je X pobjedio u nekom od dijagonala
	//-------------------------------------------------------------------------------------------------------------
	else if(polje[0][0]== 'X' && polje[1][1]== 'X' && polje[2][2]== 'X'){
		pobjeda = true;
		cout<<"Igrac X je pobjedio!";
		rezultatX++;
		Ponavljanje();
	}
	else if(polje[2][0]== 'X' && polje[1][1]== 'X' && polje[0][2]== 'X'){
		pobjeda = true;
		cout<<"Igrac X je pobjedio!";
		rezultatX++;
		Ponavljanje();
	}
	
	//provjeravanje ako je O pobjedio u nekom od redova
	//-------------------------------------------------------------------------------------------------------------
	else if(polje[0][0]== 'O' && polje[0][1]== 'O' && polje[0][2]== 'O'){
		pobjeda = true;
		cout<<"Igrac O je pobjedio!";
		rezultatO++;
		Ponavljanje();
	}
	else if(polje[1][0]== 'O' && polje[1][1]== 'O' && polje[1][2]== 'O'){
		pobjeda = true;
		cout<<"Igrac O je pobjedio!";
		rezultatO++;
		Ponavljanje();
	}
	else if(polje[2][0]== 'O' && polje[2][1]== 'O' && polje[2][2]== 'O'){
		pobjeda = true;
		cout<<"Igrac O je pobjedio!";
		rezultatO++;
		Ponavljanje();
	}
	
	//provjeravanje ako je O pobjedio u nekom od stupaca
	//-------------------------------------------------------------------------------------------------------------
	else if(polje[0][0]== 'O' && polje[1][0]== 'O' && polje[2][0]== 'O'){
		pobjeda = true;
		cout<<"Igrac O je pobjedio!";
		rezultatO++;
		Ponavljanje();
	}
	else if(polje[0][1]== 'O' && polje[1][1]== 'O' && polje[2][1]== 'O'){
		pobjeda = true;
		cout<<"Igrac O je pobjedio!";
		rezultatO++;
		Ponavljanje();
	}
	else if(polje[0][2]== 'O' && polje[1][2]== 'O' && polje[2][2]== 'O'){
		pobjeda = true;
		cout<<"Igrac O je pobjedio!";
		rezultatO++;
		Ponavljanje();
	}
	
	//provjeravanje ako je O pobjedio u nekom od dijagonala
	//-------------------------------------------------------------------------------------------------------------
	else if(polje[0][0]== 'O' && polje[1][1]== 'O' && polje[2][2]== 'O'){
		pobjeda = true;
		cout<<"Igrac O je pobjedio!";
		rezultatO++;
		Ponavljanje();
	}
	else if(polje[2][0]== 'O' && polje[1][1]== 'O' && polje[0][2]== 'O'){
		pobjeda = true;
		cout<<"Igrac O je pobjedio!";
		rezultatO++;
		Ponavljanje();
	}
	if(brojacPoteza == 9){
		cout<<"Igra je nerjesena!";
		Ponavljanje();
	}
}
int Ponavljanje(){
	cout<<"\nZelite li ponovno igrati?(Y/N)    " ;
	cin>>odgovor;
	if(odgovor == 'Y' || odgovor == 'y'){ //U slucaju da korisnik zeli ponoviti igru, sve vrijednosti
		pobjeda = false; 				 //se vracaju na pocetno stanje
		brojacPoteza = 0;
		igrac = 'X';
		polje[0][0] = '1';
		polje[0][1] = '2';
		polje[0][2] = '3';
		polje[1][0] = '4';
		polje[1][1] = '5';
		polje[1][2] = '6';
		polje[2][0] = '7';
		polje[2][1] = '8';
		polje[2][2] = '9';
		system("cls");
		main();
	}
	else if(odgovor == 'N' || odgovor == 'n'){ //Ako je korisnik odgovorio ne, program se zatvara i o tome obavjestava
		cout<<"\nZatvaranje...";               //korisnika
		return 0;
	}
}
