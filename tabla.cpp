#include "tabla.h"


Tabla::Tabla()
{

}

Tabla::~Tabla()
{
    //dtor
}
void Tabla::llenar(string tira, int fila){
//recibe una tira que leyo del archivo de texto y y la fila que le corresponde a dicha tira,
//la descomprime en las columnas correspondientes y las agrega a la matriz de manera ordenada segun la fila que recibio
//cada celda de la matriz se compone de una hilera y un int, la hlera representa lo el contenido de cada columna y el int el largo de esa hilera
    char caract;
    string hilera_celda=""; //hlera que se va a almacenar en cada celda
    int cantidad=0; //cantidad de caracteres que tiene la celda
    pair <string ,int> datos;
    vector<pair<string, int> > Fil;

    if(fila==0){
        for(unsigned int j=0; j<tira.length();j++){
            caract=tira.at(j);
            hilera_celda+=caract;
            datos= make_pair(hilera_celda,1);
            Ope_Max.push_back(datos);
            //cout<<"\n METE----hilera de operadores";
            hilera_celda.clear();
        }
    }else{
        //cout<<"largo 0   es:"<<tira.length();

        for(unsigned int i=0; i<tira.length();i++){
            caract=tira.at(i);
            if(caract!='&'){//si son iguales
                hilera_celda+=caract;

            }else{
                cantidad=hilera_celda.length();
                datos=make_pair(hilera_celda,cantidad);
                Fil.push_back(datos);
                hilera_celda.clear();
            }
        }
        cantidad=hilera_celda.length();
        datos=make_pair(hilera_celda,cantidad);
        Fil.push_back(datos);
       Tab.push_back(Fil);
    }

}

void Tabla::setTamMax(){
//se crea un vector de pares qur contiene en cada celda el operador de indentacion de cada colunmna y el tamano maximo de cada columna
//agrega en el campo int del vector de tamanos el tamano maximo de la columna correspondente.
pair<string, int> ope_Tam;
vector<pair<string, int> > Fil;
int val=0;
int val1=0;
for(it_Tab=Tab.begin(); it_Tab!=Tab.end();it_Tab++ ){
    vector<pair<string,int> > v;
    Fil=*it_Tab;
    it_Op_Max= Ope_Max.begin();
    for(it_Fil=Fil.begin(); it_Fil!=Fil.end();it_Fil++ ){
        val=it_Fil->second;
        val1=it_Op_Max->second;
        if(val> val1){
            ope_Tam= make_pair(it_Op_Max->first,val);
            v.push_back(ope_Tam);
        }else{
            ope_Tam=make_pair(it_Op_Max->first,val1);
            v.push_back(ope_Tam);
        }
    it_Op_Max++;
    }
    Ope_Max.swap(v);
}
}
void Tabla::justificar(){
//lee la tabla y agrega los espacios necesarios a cada celda para que quede justificado segun el operador de la columna
//agrega los espacios y vuelve a dejar la hilera en la celda correspondiente
string op="";
string op1 (">");
string op2 ("<");
string op3 ("=");
string hil;
int maxi=0;//tama;o maximo de la columna
int tamAct=0;//tama;o de la hilera en la celda actual
int espRest=0; //cantidad de espacios que se deben agregar para justificar una hilera
int lado1=0;
int lado2=0;
int der=0;
int izq=0;
pair<string, int> datos;

vector<pair<string, int> > Fil_aux;
vector<pair<string, int> > Fil;
 vector<vector <pair<string, int> > >Tab_aux;

for(it_Tab=Tab.begin(); it_Tab!=Tab.end();it_Tab++ ){
    Fil=*it_Tab;
    it_Op_Max= Ope_Max.begin();
    for(it_Fil=Fil.begin(); it_Fil!=Fil.end();it_Fil++ ){
            //justifica
            maxi=it_Op_Max->second;//longitud de la hilera mas grande de la columna
            maxi+=2;
            tamAct=it_Fil->second;
            espRest=maxi-tamAct;
            op=it_Op_Max->first;
            it_Op_Max++;

            if(op.compare(op1)==0)
            {
                //justificacio a la derecha con >
                for(int i=0; i<espRest;i++){
                    hil+=" ";
                }

                hil+=it_Fil->first;

            }else
            {
                if(op.compare(op2)==0){

                    //justificacion a la izquierda con <
                    hil+=it_Fil->first;
                    for(int j=0; j<espRest;j++){
                        hil+=" ";
                    }
                }else
                {
                    if(op.compare(op3)==0){
                        //justificacion al centro
                        if((espRest % 2)==0){
                            //se puede repartir en partes iguales a ambos lados de la hilera
                            for(int k=0;k<(espRest/2);k++){
                                hil+=" ";
                            }
                            hil+=it_Fil->first;
                            for(int v=0;v<(espRest/2);v++){
                                hil+=" ";
                            }
                        }else{
                            lado1=espRest/2;
                            lado2=espRest-lado1;
                            if(lado1>lado2){
                                der=lado1;
                                izq=lado2;
                            }else{
                                izq=lado1;
                                der=lado2;
                            }

                            for(int w=0; w<izq;w++){
                                hil+=" ";
                            }
                            hil+=it_Fil->first;
                            for(int x=0; x<der;x++){
                                hil+=" ";
                            }
                        }
                    }
                }
            }
    datos=make_pair(hil,hil.size());
    Fil_aux.push_back(datos);//ingresa la nueva hilera justificada
    hil.clear();
    }
    Tab_aux.push_back(Fil_aux);
    Fil_aux.clear();
}

    Tab.swap(Tab_aux);
}
void Tabla::imprimir(){
vector<pair<string, int> > Fil;
string hil="";
for(it_Tab=Tab.begin(); it_Tab!=Tab.end();it_Tab++ ){
    Fil=*it_Tab;
    for(it_Fil=Fil.begin(); it_Fil!=Fil.end();it_Fil++ ){
        hil=it_Fil->first;
        cout<<hil;
        hil.clear();
    }
    cout<<"\n";
}
}
void Tabla::limpiarTabla(){
Tab.clear();
Ope_Max.clear();

}


