#ifndef PIVOTE_H_INCLUDED
#define PIVOTE_H_INCLUDED

#include <vector>


class Pivote{

public:
    Pivote();
    Pivote(int t);

    void muestraVector();
    void rellenarVector();
    int get_mediana();

    inline int get_tam(){return tam;}

private:
    void inicializa_parametros();

    int generarAleatorio();
    void intercambiar(int a, int b);
    void pivote(int i, int j, int &l);

    std::vector<int> A;

    const static int tam_defecto = 9;
    int tam;
    int particion;
};

#endif // PIVOTE_H_INCLUDED
