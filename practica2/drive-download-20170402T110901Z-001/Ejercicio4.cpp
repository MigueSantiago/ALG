// Ejercicio 4 : Orden para compilar : g++ -o Ejercicio4 Ejercicio4.cpp 


#include <iostream>
#include <ctime> 
#include <cstdlib> 
#include <algorithm> 


// Algoritmo clásico que ordena tornillos y tuercas en rango de [i,j]
void algoritmoClasicoTornilloTuerca(int* A, int* B, const int& i, const int& j) {
    for (int x=i; x<j-1; ++x) {       
        for (int y=i; y<j; ++y) {    
            if (A[x]==B[y]) {         
                std::swap(B[x],B[y]); 
                break;
            }
        }
    }
}

// reordenamos los elementos colocando los menores a la izquierda del pivote y los mayores a la derecha del pivote.

int reordenar(int* AB, int i, int d, int pivote) {
    do {
        std::swap(AB[i],AB[d]);
        while ( AB[i] < pivote  ) ++i;
        while ( AB[d] > pivote  ) --d;
    } while (i<d);
    return i;
}

// Buscamos un pivote tornillo/tuerca en el vector que encaje con el pivote tuerca/tornillo dado por parámetro.

int buscarPivoteTornilloTuerca(int* AB, int i, int j, int pivote) {
    for (int x=i; x<j; ++x) {
        if (AB[x]==pivote) {
            return x;
        }
    }
    return -1;
}

// Aplicamos el algoritmo de ordenación Quicksort aplicando a tornillos y tuercas.

template<int n0>
void quickSortTornilloTuerca(int* A, int* B, const int& i, const int& j) {
    if ((j-i)<=n0) { 

        algoritmoClasicoTornilloTuerca(A,B,i,j);
    } else { 

        int pivoteTornillo = A[((i+j)>>1)];
        
 
        int pos = buscarPivoteTornilloTuerca(B, i,j, pivoteTornillo);
        if (pos != -1) {
            
            int pivoteTuerca = B[pos];

           
            int k1=reordenar(A,i,j-1,pivoteTuerca); 
            int k2=reordenar(B,i,j-1,pivoteTornillo); 
         
            if (k1==k2) {
                quickSortTornilloTuerca<n0>(A,B,i,k1);
                quickSortTornilloTuerca<n0>(A,B,k2+1,j); 

            }
        }
    }
};


int main(int argc, char** argv) {
    const int n = 1000;
    int tornillos[n];
    int tuercas[n];

    
    for(int i=0; i<n; ++i) tornillos[i] = tuercas[i] = i;
    

    std::srand(std::time(NULL));
    std::random_shuffle(tornillos,tornillos+n); 
    std::random_shuffle(tuercas,tuercas+n);
    
    
 
    quickSortTornilloTuerca<10>(tornillos,tuercas,0,n);

  
    int c=0;
    for (int i=0; i<n; ++i) {
        std::cout << tornillos[i] << ":" << tuercas[i] << std::endl;
        if (tornillos[i]==tuercas[i]) ++c;
    }
    if (c==n) std::cout << "Todos los tornillos y tuercas están emparejados." << std::endl;
    
    return 0;
}



