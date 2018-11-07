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
void MatrizDiscrepancia (int matriz[50][50],int personas,int actividades, int matrizDiscrepancia[50][50]){
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


}

void ImprimeMatrizDis(int matrizDiscrepancia[50][50],int personas){
for(int i=0; i<personas; i++){
		for(int j=0; j<personas; j++){
			cout<<matrizDiscrepancia[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Solucion(vector<pair<int,int> > parejas,vector <int> valores){
	int valor=0;
	for(int i=0; i<valores.size(); i++){
		valor=valor+valores[i];
		cout<<"El valor en i es "<<valores[i]<<endl;
		cout<<"El valor es: "<<valor<<endl;
	}
	valor=valor*2;
	cout<<"Discrepancia total:"<<valor<<endl;
	for(int i=0; i< parejas.size(); i++){
		cout<<"Persona "<<parejas[i].first<<" con Persona "<<parejas[i].second<<endl;
		cout<<"Persona "<<parejas[i].second<<" con Persona "<<parejas[i].first<<endl;
	}
}
bool factible(int dato,vector<bool>disponible){
	//cout<<"EN factible hay un "<<disponible[dato]<<endl;
	return disponible[dato];
}
void Seleccion(int matrizDiscrepancia[50][50], int personas,vector<bool>&disponible ){
	vector<pair<int,int> > parejas;
	vector<int>valores;
	pair<int,int> pareja;
	for(int i=0; i<personas; i++){
		bool posible;
		//cout<<"Miro el dato "<<i<<endl;
		posible=factible(i,disponible);
		
		if(posible){
			int posicion;
			disponible[i]=false;
			int number,number_pos;
			for(int j=0;j<personas;j++){
				//cout<<"Compruebo el dato "<<j<<endl;
				bool posible=factible(j,disponible);
				if(posible){
					number_pos=matrizDiscrepancia[i][j];
					}if(number>number_pos){
						number=number_pos;
						posicion=j;
					}
			}
			
			pareja=make_pair(i,posicion);
			//cout<<"El primer valor de la pareja es "<<pareja.first<<"y el segundo es "<<pareja.second<<endl;
			parejas.push_back(pareja);
			cout<<"Se almacena el valor" <<number<<endl;
			valores.push_back(number);
			disponible[posicion]=false;
		}
	}

	Solucion(parejas,valores);
	
}

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

	int matriz[50][50];
	int matrizDiscrepancia[50][50];
	int infinito=1;
	vector<bool>disponible (personas,true);	
	for(int i=0; i<personas; i++){
		for(int j=0; j<personas; j++){
			if(i==j){
				matrizDiscrepancia[i][j]=infinito;
			}else{
				matrizDiscrepancia[i][j]=0;
			}
		}
	}
	/*for(unsigned i=0; i<personas; i++){
		cout<<"hay un "<<disponible[i]<<endl;
	}*/
	
	for(int i=0; i<personas; i++){
		for(int j=0; j<actividades; j++){
			int dato;
			datos>>dato;
			matriz[i][j]=dato;
		}
	}

	/*for(int i=0; i<personas; i++){
		for(int j=0; j<actividades; j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
		

	MatrizDiscrepancia(matriz,personas,actividades,matrizDiscrepancia);
	ImprimeMatrizDis(matrizDiscrepancia,personas);
	Seleccion(matrizDiscrepancia,personas,disponible);
	
}
