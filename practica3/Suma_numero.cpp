#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
//#include <chrono>
#include <cmath>
#include <vector>
//using namespace std::chrono;

//inline static void SumaAnumero(const vector <int> datos,const int M);
/*static void Imprimir(int datos[],tamanio){

		for(int i=0; i<datos.size(); i++){
			cout<<"Valor sumado: "<<datos[i]<<endl;
		}
}*/
//bool Factible(
static void SumaAnumero(vector <int> datos,int M){

	int n= 8;
	vector <int> conjunto_suma;
	int conjunto_formado [][];
	int contador1=0;

	for(int i=0; i<n;i++){
		
		int numero=datos[i];
		int contador2=0;
			cout<<"AQUI ESTOY"<<endl;
		if(numero==M){

			cout<<"LLEGO AQUI"<<endl;

			conjunto_suma[contador1]=numero;
			//conjunto_formado.push_back(contador2)=numero;
			conjunto_formado[contador1][contador2]=numero;			
			contador1++;
		}else if(numero<M){
			cout<<"HOOLAAAAAAAAA"<<endl;
			conjunto_suma[contador1]=numero;
			//conjunto_formado.push_back(contador2)=numero;
			conjunto_formado[contador1][contador2]=numero;
			for(int j=i; j<n; j++){
				
				cout<<"NUMERO:"<<numero<<endl;
				if(i==j)
					j++;
				

				cout<<"IUGUITTUBGUT"<<endl;
					numero+=datos[j];
					if((M-numero)>=0){
					 	conjunto_suma[contador1]=numero;
						contador2++;
						//conjunto_formado.push_back(contador2)=datos.at(j);
						conjunto_formado[contador1][contador2]=numero;
					}else
						numero-=datos[j];
					
			}
			cout<<"NUMERO2:"<<numero<<endl;
			contador1++;
		}

	}
	//Imprimir(conjunto_suma);				
}

int main(){

	vector <int> datos (4);
	int numero=8;

	int cont=0;

	while(cont<4){
		int dato;
		cout<<"introduce un dato: "<<endl;
		cin>>dato;

		datos[cont]=dato;
		//datos[cont]=dato;
		cont++;
	}
	
	SumaAnumero(datos,numero);

}
	

	
