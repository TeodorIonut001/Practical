#include <iostream>
#include <math.h>
using namespace std;

//lista liniara dublu inlantuita
struct elem{int x; elem *urm, *ant;}*inc, *sf, *aux, *aux2;

int main() {


	//se creaza lista
	aux = new elem;
	aux->urm = aux->ant = NULL;
	sf = inc = aux;
	cout << "1: ";
	cin >> aux->x;
	//se adauga urmatoarele 6 elemente (de la 2 la 7)
	for(int i=2; i<=7; i++){
		aux = new elem;
		cout << i << ": ";
		cin >> aux->x;
		sf->urm = aux;
		aux->ant = sf;
		aux->urm = NULL;
		sf=aux;

	}

	//afisare
	aux=inc;
	while(aux != NULL){
		cout << aux->x << " ";
		aux = aux->urm;
	}
	cout << endl;

	//se adauga element la inceputul listei
	aux = new elem;
	cout << "Primul element: ";
	cin >> aux->x;
	aux->urm = inc;
	inc->ant = aux;
	inc = aux;

	//afisare
	aux = inc;
	while(aux != NULL){
		cout << aux->x << " ";
		aux = aux->urm;
	}

	//se sterge un element (oarecare)
	bool amGasit = false;
	//se citeste elementul
	int deSters;
	cout << endl;
	cout << "De sters: ";
	cin >> deSters;
	//se testeaza daca este la inceput
	if(inc->x == deSters){
		aux = inc;
		inc = inc->urm;
		aux->urm = inc->ant = NULL;
		delete(aux);
	}//se testeaza la sfarsit
	else if(sf->x == deSters){
		aux = sf;
		sf = sf->ant;
		sf->urm = aux->ant = NULL;
		delete(aux);
	}//se testeaza la mijloc
	else{
		aux = inc;
		while(aux != NULL){
			if(aux->x == deSters){
				cout << "Am gasit.\n";
				amGasit = true;
				//stergerea tuturor elementelor gasite se face aici si se elimina "break"-ul.
				break;
			}
			aux = aux->urm;
		}
		//stergerea se face doar pentru primul element gasit.
		//algoritmul de stergere
		if(amGasit){
			aux2 = aux->ant;
			aux2->urm = aux->urm;
			aux2 = aux->urm;
			aux2->ant = aux->ant;
			delete(aux);
		}else cout << "Nu am gasit.\n";
	}

	//afisare si numarare elemente ramase:
	int counter = 0;
	aux = inc;
		while(aux != NULL){
			cout << aux->x << " ";
			aux = aux->urm;
			counter++;
		}
	cout << endl;
	cout << "Au ramas " << counter << " elemente in lista.\n";


	//se ordoneaza lista crescator
	cout << "Se ordoneaza crescator lista: ";
	int c;
	for(int i=0; i<counter;i++){
		aux = inc;
		while(aux->urm != NULL){
			//swap(a,b)  c=a; a=b; b=c;
			if(aux->x >= aux->urm->x){
				c = aux->urm->x;
				aux->urm->x = aux->x;
				aux->x = c;
			}
			aux = aux->urm;
		}
	}

	//afisare
	aux = inc;
	while(aux != NULL){
		cout << aux->x << " ";
		aux = aux->urm;
	}
	cout << endl;

	//implementare stiva
	cout << "-Implementare Stiva-\n";
	cout << "Numarul de elemente ce vor fi sterse: ";
	cin >> c;
	for(int i=0; i<c; i++){
		aux = inc;
		aux2 = aux->urm;
		aux2->ant = aux->urm = NULL;
		inc = aux2;
		delete(aux);
	}

	//afisare
	aux = inc;
	while(aux != NULL){
		cout << aux->x << " ";
		aux = aux->urm;
	}
	cout << endl;

	cout << "Numarul de elemente ce vor fi introduse: ";
	cin >> c;
	for(int i=0; i<c; i++){
		cout << "Introduceti element: ";
		aux = new elem;
		cin>>aux->x;
		inc->ant = aux;
		aux->urm = inc;
		inc = aux;
	}

	//afisare
	aux = inc;
	while(aux != NULL){
		cout << aux->x << " ";
		aux = aux->urm;
	}
	cout << endl;

	//implementare coada
	cout << "-Implementare Coada-\n";
	cout << "Numarul de elemente ce vor fi sterse: ";
	cin >> c;
	for(int i=0; i<c; i++){
		aux = inc;
		aux2 = aux->urm;
		aux2->ant = aux->urm = NULL;
		inc = aux2;
		delete(aux);
	}

	//afisare
	aux = inc;
	while(aux != NULL){
		cout << aux->x << " ";
		aux = aux->urm;
	}
	cout << endl;

	cout << "Numarul de elemente ce vor fi introduse: ";
	cin >> c;
	for(int i=0; i<c; i++){
		aux = new elem;
		cout << "Introduceti element: ";
		cin >> aux->x;
		sf->urm=aux;
		aux->ant=sf;
		sf=aux;
	}

	//afisare
	aux = inc;
	while(aux != NULL){
		cout << aux->x << " ";
		aux = aux->urm;
	}
	cout << endl;

//endOfMain
}

