#include <iostream>

#include <cstdlib>
#include <math.h>

#include "pivote.h"

using namespace std;


int main(){

    int mediana;

    Pivote p1;
    Pivote p2(5);
    Pivote p3(7);
    Pivote p4 (10);

    cout << "Calculo de la mediana aplicando pivote \n"<<endl;
    cout << " -----------------------------------------------" <<endl;


    //cout << "Vector de dimension 9 \n"<<endl;
    //cout << endl << "Valores del vector 1: ";
    //p1.rellenarVector();
    //p1.muestraVector();

    //cout << endl << " Pasos de la busqueda \n" << endl;
    //mediana = p1.get_mediana();
    //cout << " El valor de la mediana es " << mediana  << endl;
    //cout << " -----------------------------------------------" <<endl;

    cout << "Vector de dimension 5 \n"<<endl;
    cout << endl << "Valores del vector 2: ";
    p2.rellenarVector();
    p2.muestraVector();

    cout << endl << "Pasos ejecutados \n " << endl;
    mediana = p2.get_mediana();
    cout << " La mediana es " << mediana  << endl;
     cout << " -----------------------------------------------" <<endl;
    cout << "Vector de dimension 7 \n"<<endl;
    cout << endl << "Valores del vector 3: ";
    p3.rellenarVector();
    p3.muestraVector();

    cout << endl << "Pasos ejecutados \n " << endl;
    mediana = p3.get_mediana();
    cout << " La mediana es " << mediana  << endl;
     cout << " -----------------------------------------------" <<endl;

    cout << "Vector de dimension 10 \n"<<endl;
    cout << endl << "Valores del vector 4 ";
    p4.rellenarVector();
    p4.muestraVector();

    cout << endl << "Pasos ejecutados \n " << endl;
    mediana = p4.get_mediana();
    cout << " La mediana es " << mediana  << endl;
    cout << " -----------------------------------------------" <<endl;

	return 0;
}
