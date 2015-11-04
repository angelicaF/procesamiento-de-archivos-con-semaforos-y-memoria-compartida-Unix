#ifndef TABLA_H
#define TABLA_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>

using namespace std;

class Tabla
{
    public:
        Tabla();
        virtual ~Tabla();
        void llenar(string,int );
        void vaciar();
        void setTamMax();
        void justificar();
        void limpiarTabla();
        void imprimir();
        vector<vector <pair<string, int> > >Tab;
        vector<vector<pair<string,int> > >::iterator it_Tab; //iterador de la columnas

        vector<pair<string,int> > Ope_Max;//vector que contiene los operadores y el tamano maximo de cada columna
        vector<pair<string,int> >::iterator it_Op_Max; //iterador de vector de operadores y  tamanos

    protected:
    private:



        vector<pair<string,int> >::iterator it_Fil; //iterador de las filas
};

#endif // TABLA_H
