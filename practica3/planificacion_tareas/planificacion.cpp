#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
struct tarea{
  int beneficio;
  int d;
  int key;
};
istream & operator >>(istream&is, tarea &t){
  is>>t.key>>t.beneficio>>t.d;
  return is;
}

/**
 * @brief compara dos tareas por beneficio
 * @param t1: tarea primera
 * @param t2: tarea segunda
 * @return true si la primera tiene un beneficio mayor que la segunda
 * */

bool compare(const tarea &t1,const tarea &t2){
    return t1.beneficio>t2.beneficio;
}  
  
/** 
 * @brief Lee del un flujo de entrada una serie de tareas
 * @param is: el flujo de entrada
 * @param T: vector de tareas. ES MODIFICADO
 * @return el flujo
 **/

istream & operator >>(istream&is, vector<tarea> &T){
  tarea t;
  while (is>>t){
     T.push_back(t);
  }
  return is;
}
/**
 * @brief Comprueba si se puede añadir un nuevo elemento a la solucion
 * @param T: conjunto de tareas
 * @param S: vector con la solucion hasta el momento. Si la nueva tarea se puede añadir S ES MODFIICADO con dicha nueva tarea
 * @param nueva: indice en T de la nueva tarea candidata a añadir
 * @param k: numero de tareas ya añadidas en S
 * @return true si la nueva tarea se ha añadido a S siendo esta nueva solucion factible. False en caso contrario
 *
 * */
bool Factible(const vector<tarea> &T,vector<int> &S,int nueva,int k){
  int n=S.size();
  vector<int> Saux(n,-1);
  int i =0;
  while (i<k && (i+1)<T[nueva].d){ //Mientra que el tiempo es menor que el plazo de la nueva tarea 
      Saux[i]=S[i];
      i++;
  }    
  Saux[i]=nueva; //Añadimos la nueva tarea a la solucion
  while(i<k){ //Anadimos el resto de S
      Saux[i+1]=S[i];
      i++;
  }   
  i=0;
  //Se comprueba si di>=i en otro caso la solucion construida no es factible
  while (i<=k && T[Saux[i]].d>=(i+1)) i++; 
  
  if (i>k) { //Es factible
    S=Saux; //Nos quedamos con la solucion construida
    return true;
  }
  else return false; //NO era factible
}
/** 
 * @brief Obtiene una planificacion de tareas realizar en el tiempo para maximizar el beneficio total
 * @pre Se supone que T esta ordenado por beneficio
 * @param T: vector con las tareas
 * @param S: vector con las indices en T de las tareas seleccionadas
 * @return el beneficio total obtenido
**/
int Planificacion(const vector<tarea> &T ,vector<int> &S){
  int tiempos=S.size();
  int n_tareas=T.size();
  int i=0,puestas=0;
  int bene_total=0;
  while (i<n_tareas && puestas<tiempos){
          int candidata=i;
	  if (Factible(T,S,candidata,puestas)){
	    bene_total+=T[candidata].beneficio;
	    puestas++;
	  }  
	  i++;
  }
  return bene_total;
}

int main( int argc, char* argv[]){
  if(argc !=3){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.-El fichero con las tareas"<<endl;
      cout<<"2.-El maximo tiempo"<<endl;
  }
  int max_time=atoi(argv[2]);
  ifstream f(argv[1]);
  if (!f){
      cout<<"No puedo abrir" <<argv[1]<<endl;
      return 0;
  }     
  vector<tarea> T;
  f>>T; //Leemos las tareas
  
  sort(T.begin(),T.end(),compare); //Ordenamos T por beneficio de mayor a menor
  
  vector<int> S(max_time,-1); //INiciamos el vector solucion con max_time elementos iniciados a -1
  
  int Bt=Planificacion(T, S); 
  
  //Imprimimos el resultado
  cout<<"Beneficio Total " <<Bt<<endl;
  cout<<"Los tiempos y tareas que se ejecutan:"<<endl;
  int i=0;
  while (i<max_time && S[i]!=-1){
    cout<<"Tiempo: "<<i+1<< "  Tarea :"<<T[S[i]].key<< " "<<T[S[i]].beneficio<<" d="<<T[S[i]].d<<endl;
    i++;
  }
  


  
  
}
