#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

/*	N: número total de discrepancias.
	Candidatos: lista de numeros.
   	n:primer numero de la lista.
	sol: solucion,numero que suman las discrepancias de las parejas de enteros.
	m:numero de enteros de la solucion.
*/


istream & operator >>(istream&is, vector<int> &Conjunto){
  int numero;
  while (is>>numero){
     Conjunto.push_back(numero);
  }
  return is;
}
/*void MatrizDiscrepancia (int matriz [50][50],int personas,int actividades, int &matrizDiscrepancia[50][50]){
	for(int i=0; i<personas; i++){
		for(int j=0; j<personas


}*/
int main(int argc, char* argv[]){
	if(argc !=2){
      		cout<<"Los parametros son:"<<endl;
      		cout<<"1.-El fichero con los dato"<<endl;
	 }
	ifstream datos (argv[1]);

	int personas;
	int actividades;
	char comentario;
	
	
	datos>>personas>>actividades;
	


	cout<<"Las personas son :"<<personas<<endl;
	cout<<"Las actividades son :"<<actividades<<endl;

	int matriz [personas][actividades];
	int matrizDiscrepancia[personas][personas];
	int infinito=1;
	for(int i=0; i<personas; i++){
		for(int j=0; j<personas; j++){
			if(i==j){
				matrizDiscrepancia[i][j]=infinito;
			}else{
				matrizDiscrepancia[i][j]=0;
			}
		}
	}
	for(int i=0; i<personas; i++){
		for(int j=0; j<actividades; j++){
			int dato;
			datos>>dato;
			matriz[i][j]=dato;
		}
	}

	for(int i=0; i<personas; i++){
		for(int j=0; j<actividades; j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<personas; i++){
		
		for(int j=1; j<personas; j++){
			int numero=0;
			int valor=0;
			for(int l=0; l<actividades; l++){
						
				numero=(matriz[i][l]-matriz[j][l]);	
				numero=abs(numero);
				valor=valor+numero;
			}
			if(i!=j){
			
			matrizDiscrepancia[i][j]=valor;
			matrizDiscrepancia[j][i]=valor;	
			}	
		}
	}
		
	for(int i=0; i<personas; i++){
		for(int j=0; j<personas; j++){
			cout<<matrizDiscrepancia[i][j]<<" ";
		}
		cout<<endl;
	}
}
