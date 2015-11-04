#ifndef FILE_H
#define FILE_H


#include <fstream>
#include <iostream>
#include "tabla.h"
#include <vector>
#include <string>
using namespace std;


class File
{
    public:
        File();
        virtual ~File();
        void leer();
        string escribir();
        bool verOperador(string);
        Tabla tab;
        ofstream fich_salida;

        void imprimeResu();
    protected:
    private:
        int totalCol;
        int totalTab;
        int totalFil;
};

#endif // FILE_H
