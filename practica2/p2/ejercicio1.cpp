#include <iostream>
#include <vector>


using namespace std;

pair<int,int> Max_Min(const vector<int> & v);

int main(){
	int tamanio=10;
	int tope=0;
	vector<int> v;
	while(tope!=tamanio){
		int dato;		
		
		cout<<"Introduce el conjunto de datos a analizar:";
		cin>>dato;
		
		v.push_back(dato);
		tope++;
	}	

	
	std::pair <int,int> pareja;
	pareja=Max_Min(v);
	
	cout<<"El minimo es "<<pareja.first<<" y el maximo es "<<pareja.second<<"."<<endl;
	
	return 0;

}
pair<int,int> Max_Min(const vector<int> & v){
	
	
	std::pair<int,int> p;
	std::pair<int,int> resultado;
	
	if(v.size()==1){
		p.first=v.at(0);
		p.second=v.at(0);

		return p;
	}else{
	
	vector <int> izquierda;
	vector <int> derecha;
	int mitad;	
	mitad=v.size()/2;
	for(int i=0; i<mitad; i++){
    		
		izquierda.push_back(v.at(i));
		derecha.push_back(v.at(v.size()-mitad+i));
			
	}
	std::pair<int,int> izq=Max_Min(izquierda);
	std::pair<int,int> der=Max_Min(derecha);
	
	if(izq.first<der.first)
		resultado.first=izq.first;
	else
		resultado.first=der.first;
	if(izq.second<der.second)
		resultado.second=der.second;
	else
		resultado.second=izq.second;
	}

	
	return resultado;

}
