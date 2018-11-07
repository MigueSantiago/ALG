#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>


using namespace std;

void rellenarVector(vector <int> &datos);
int generarAleatorio();
void muestraVector(vector <int> datos);
void intercambiar(int a, int b, vector <int> &datos);
void pivote(vector <int> &datos,int i,int j);
int main(){

    
    int tamanio;

    cout<<"Introduce el tamanio del vector a examinar:";
    cin>>tamanio;

    vector <int> vectordatos(tamanio);
    rellenarVector(vectordatos);
    muestraVector(vectordatos);
    pivote(vectordatos,0,tamanio-1);
    
    	
}

void rellenarVector(vector <int> &datos){
	for (int i=0; i<datos.size(); i++)
		datos.at(i) = generarAleatorio();
}
int generarAleatorio(){
	return (rand()%30)+10;
}

void muestraVector(vector <int> datos){
	for (int i=0; i<datos.size(); i++)
		cout << ' ' << datos.at(i);
	cout << endl;
}

void intercambiar(int a, int b, vector <int> &datos){
	int temp = datos.at(a);
	datos.at(a) = datos.at(b);
	datos.at(b) = temp;
}

void pivote(vector <int> &datos,int i,int j) {
    
    int piv,k,l;
    k=i;
    piv=datos.at(i);
    l=j+1;
    
	
    do{
	
	k=k+1;
	
    }while(datos.at(k)<=piv && k<j);

    do{
	l=l-1;
    }while(datos.at(l)>piv);
	
    while(k<l){
	
	intercambiar(k,l,datos);
	muestraVector(datos);
	do{
		k=k+1;
	}while(datos.at(k)<=piv );
	do{
		
		intercambiar(k,l,datos);	    
		l=l-1;
	    
	}while(datos.at(l)<piv && datos.at(k)>piv  && datos.at(l)>datos.at(k));
	
	intercambiar(i,l-1,datos);
	muestraVector(datos);
    }
	cout<<"El pivote es:"<<piv<<endl;
	
	vector<int>ho;
	vector<int>he;

	for(int i=0; i<datos.size(); i++){
		if(datos.at(i)<piv || datos.at(i)>piv)
			he.push_back(datos.at(i));
		else
			ho.push_back(datos.at(i));
	}

	
}
    	
    
