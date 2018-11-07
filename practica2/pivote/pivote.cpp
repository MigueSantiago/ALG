#include <iostream>
#include <vector>

#include <cstdlib>
#include <time.h>

#include <math.h>

#include "pivote.h"

using namespace std;

Pivote::Pivote(){
    tam = tam_defecto;
    inicializa_parametros();
}

Pivote::Pivote(int t){
    tam = t;
    inicializa_parametros();
}

void Pivote::inicializa_parametros(){
    srand(time(NULL));
    A.resize(tam);
    particion = ceil(tam/2);
}

int Pivote::generarAleatorio(){
	return (rand()%90)+10;
}

void Pivote::rellenarVector(){
	for (vector<int>::iterator it=A.begin(); it!=A.end(); it++)
		*it = generarAleatorio();
}

void Pivote::intercambiar(int a, int b){
	int temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

void Pivote::muestraVector(){
	for (vector<int>::iterator it=A.begin(); it!=A.end(); it++)
		cout << ' ' << *it;
	cout << endl;
}

void Pivote::pivote(int i, int j, int &l) {

    int k;
	int p = A[i];

	k = i;
	l = j+1;

	do{
        k++;
	}while(!(A[k]>p || k>=j));

	do{
        l--;
	}while(!(A[l]<=p));

	while(k<l){
		intercambiar(k,l);
		do{
            k++;
		}while(!(A[k]>p));

		do{
            l--;
		}while(!(A[l]<=p));
	}
	intercambiar(i, l);
}

int Pivote::get_mediana(){
	int i = 0;
	int j = A.size()-1;
	int l = 0;
	do {
		pivote(i, j, l);
		muestraVector();
		if (particion<l)
			j = l-1;
		else if (particion>l)
			i = l+1;
	}while (!(l==particion));

	return A[l];
}

