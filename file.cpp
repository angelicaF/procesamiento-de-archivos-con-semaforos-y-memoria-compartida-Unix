#include "file.h"
#include "tabla.h"
#include <string>


File::File()
{
    Tabla tab;
}

File::~File()
{
    //dtor
}

void File::leer(){
    totalFil=0;
    totalCol=0;
    totalTab=0;
bool operador=false;
string hilera="";
int numFila=0;
    ofstream fich_salida("salida.txt", ios::out);
	//verificar si se abrio el archivo con exitp
	ifstream fich_entrada("entrada.txt");
    	if(!fich_entrada)
        	cout<<"No se pudo abrir el fichero\n";
    	else{
		//cout<<"el archivo se abrio correctamente\n";
		string fin ("#");
		getline(fich_entrada,hilera);
		while(fin.compare(hilera)!=0){ //mientras no 	encuentre un #
		tab.llenar(hilera,numFila);
		numFila++;
		getline(fich_entrada,hilera);
		//verifico si lo que leyo fueron operadores
			operador=verOperador(hilera);
			while(!operador && (fin.compare(hilera)!=0)){//mientras no encuentre un operador

				//va obteniendo la tira hasta cambio de linea
				tab.llenar(hilera, numFila);
	 			getline(fich_entrada,hilera);
				numFila++;
				operador=verOperador(hilera);
			}
        tab.setTamMax();
        tab.justificar();

         string hileraS=escribir();
         fich_salida<<hileraS<<"\n";

		numFila=0;
		tab.limpiarTabla();
		totalTab++;

		}
		imprimeResu();
		tab.setTamMax();
        tab.justificar();
        string hileraSi=escribir();
        fich_salida<<hileraSi<<"\n";

	}


}

bool File::verOperador(string hil){
//recibe un hilera y determina si el primer caracter en un operador, entonces se trata de una hilera de operadores
bool esOper=false;
int i=0;
string op1 (">");
string op2 ("<");
string op3 ("=");
string caract ("");
caract =hil.at(i);
	if(caract.compare(op1)==0)
	{
		esOper=true;
	}else
	{
		if(caract.compare(op2)==0){
			esOper=true;
		}else
		{
			if(caract.compare(op3)==0){
				esOper=true;
			}
		}
	}

return esOper;

}

string File::escribir(){
int longitud=0; //longitud de las filas
int cont=0;
int cantCelda=0;
int cantCol=tab.Ope_Max.size();
totalCol+=cantCol;
int col=0;
vector<pair<string, int> > Fil;
vector<pair<string,int> >::iterator it_Fil; //iterador de las filas
string hil;
string lineaS;


tab.it_Tab=tab.Tab.begin();
Fil=*tab.it_Tab;
    for(it_Fil=Fil.begin(); it_Fil!=Fil.end();it_Fil++ ){
        longitud+= it_Fil->second;
        longitud+=2;
    }
//#-------------------------#
lineaS="#";
for(int i=0; i<longitud;i++){
    lineaS+="-";
}
lineaS+="#\n";

for(tab.it_Tab=tab.Tab.begin(); tab.it_Tab!=tab.Tab.end();tab.it_Tab++ ){
    Fil=*tab.it_Tab;
    for(it_Fil=Fil.begin(); it_Fil!=Fil.end();it_Fil++ ){
        hil+="| ";
        hil+=it_Fil->first;
    }
     totalFil++;
    hil+=" |";
    hil+="\n";
    if (cont==0){
        hil+="|";
        for(tab.it_Op_Max=tab.Ope_Max.begin(); tab.it_Op_Max!=tab.Ope_Max.end(); tab.it_Op_Max++){
            cantCelda=tab.it_Op_Max->second;
            cantCelda+=3;
            for(int i=0; i<cantCelda;i++){
                hil+="-";
            }
            col++;
            if(col!=cantCol){
                hil+="+";
            }
        }
        hil+="-|";
        hil+="\n";

    }
    cont++;
}

lineaS+=hil;
//#-------------------------#
lineaS+="#";
for(int i=0; i<longitud;i++){
    lineaS+="-";
}
lineaS+="#\n";
totalFil--;
return lineaS;
}
void File::imprimeResu(){
    stringstream stream;
     stringstream stream1;
      stringstream stream2;
    string hil="<=";
    string hile;
    tab.llenar(hil,0);
    hil="Resultados&Finales";
    tab.llenar(hil,1);
    stream << totalTab;
    hile=stream.str();
    hil="Total de tablas&";
    hil+=hile;
    tab.llenar(hil,2);
    stream1 << totalCol;
    hile=stream1.str();
    hil="Total de columnas&";
    hil+=hile;
    tab.llenar(hil,3);
    stream2 << totalFil;
    hile=stream2.str();
    hil="Total de filas&";
    hil+=hile;
    tab.llenar(hil,4);

}
