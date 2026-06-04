#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
/*Utilizzando il file .csv dell'esercizio precedente, realizzare un programma che effettui le seguenti operazioni:
Inserimento di un nuovo record
Visualizzazione dei file
modifica di un record
cancellazione di un recod
Le operazioni dovranno essere effettuate utilizzando un file d'appoggio.
*/
struct location{
		double x;
		double y;
	};
//Non si può usare array di struct	
struct numcivica{
		string tipovia;
		string nomevia;
		string numero;
		string subalterno;
		string cap;
		string istat;
		double latitudine;
		double longitudine;
		location z;
		
	};
	
	
	
	
	void inserimento(numcivica x){
		//string y;
	//	int cont=0;
		ofstream scrivi("dati.csv",ios::app);
		
	if(scrivi.is_open()){
	//	while (getline(leggi,y)){
	
	//	while(getline(leggi,y)){
			scrivi<<x.tipovia<<",";
			scrivi<<x.nomevia<<",";
			scrivi<<x.numero<<",";
			scrivi<<x.subalterno<<",";
			scrivi<<x.cap<<",";
			scrivi<<x.istat<<",";
			scrivi<<x.latitudine<<",";
		    scrivi<<x.longitudine<<",";	
		    scrivi<<x.z.x<<",";
		    scrivi<<x.z.y<<endl;
	
	}
	else{
		cout<<"Errore apertura file"<<endl;
	}	
		scrivi.close();
	}
	
	
	
	
	void visualizza(){
		string y;
		ifstream leggi("dati.csv");
		if(leggi.is_open()){
			while(getline(leggi,y)){
				cout<<y<<endl;
			}
			//leggi.close();
		}
		leggi.close();
	}
	
	
void modifica(string cerca,string nuovariga){
	string riga;
ifstream leggi("dati.csv");
ofstream scrivi("Appoggio.csv");
if(leggi.is_open()&&scrivi.is_open()){
	while(getline(leggi,riga)){
		
	if(riga.find(cerca) != -1){
		
    scrivi << nuovariga << endl;
    
} 

    else {
    	
    scrivi << riga << endl;
    
	}
	}
}
    leggi.close();
    scrivi.close();
    
    remove("dati.csv");
    rename("Appoggio.csv", "dati.csv");	
	
}	


void cancellazione(string cerca){
string riga;
ifstream leggi("dati.csv");
ofstream scrivi("Appoggio.csv");
if(leggi.is_open()&&scrivi.is_open()){

	while(getline(leggi,riga)){
		
	if(riga.find(cerca) != -1){
		
    continue;
    
} 

    else {
    	
    scrivi << riga << endl;
    
	}
	}
}
    leggi.close();
    scrivi.close();
    
    remove("dati.csv");
    rename("Appoggio.csv", "dati.csv");	
}

	
int main(int argc, char** argv) {
	numcivica x1;
	
	int scelta;
	string cerca,nuovariga;
	do{
	cout<<"--------------------MENU'---------------------"<<endl;	
	cout<<"0 - FINE PROGRAMMA"<<endl;
	cout<<"1 - INSERIMENTO DI UN NUOVO RECORD"<<endl;
    cout<<"2 - VISUALIZZA"<<endl;
    cout<<"3 - MODIFICA DI UN RECORD"<<endl;
    cout<<"4 - CANCELLAZIONE DI UN RECORD"<<endl;
    
    cout<<"Scegli cosa vuoi fare"<<endl;
	cin>>scelta;
	fflush(stdin);
	
	switch(scelta){
	
	
	//INSERIMENTO
	case 1: 
	
	cout << "Inserisci tipo via: ";
    cin >> x1.tipovia;
    cout << "Inserisci nome via: ";
    cin >> x1.nomevia;
    cout << "Inserisci numero: ";
    cin >> x1.numero;
    cout << "Inserisci subalterno: ";
    cin >> x1.subalterno;
    cout << "Inserisci CAP: ";
    cin >> x1.cap;
    cout << "Inserisci ISTAT: ";
    cin >> x1.istat;
    cout << "Inserisci latitudine: ";
    cin >> x1.latitudine;
    cout << "Inserisci longitudine: ";
    cin >> x1.longitudine;
    cout << "Inserisci coordinata X: ";
    cin >> x1.z.x;
    cout << "Inserisci coordinata Y: ";
    cin >> x1.z.y;
	
	inserimento(x1);
	break;
	
	//VISUALIZZA
	case 2: 
	visualizza();
	break;
	
	//MODIFICA
	case 3:
	cout<<"Inserisci la latitudine della via che vuoi modificare "<<endl;
	cin>>cerca;
	cout << "Inserisci la nuova riga: ";
    cin >> nuovariga;
    modifica(cerca,nuovariga);
	break;
	
	//CANCELLAZIONE
	case 4:
	cout<<"Inserisci la latitudine della via che vuoi cancellare "<<endl;
	cin>>cerca;
	cancellazione(cerca);
	break;	
	
}
	
	}while(scelta!=0);
	
	return 0;
}