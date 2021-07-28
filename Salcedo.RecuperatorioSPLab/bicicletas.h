#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED


typedef struct
{
    int id;
    char nombre[20];
    char tipo[20];
    int tiempo;

}eBicicleta;


#endif // BICICLETAS_H_INCLUDED

eBicicleta* bicicletaNew();
eBicicleta* bicicletaNewParametros(char* id, char* nombre, char* tipo, char* tiempo);
void bicicletaDelete(eBicicleta* x);
int bicicletaSetId(eBicicleta* x, int id);
int bicicletaSetNombre(eBicicleta* x, char* nombre);
int bicicletaSetTipo(eBicicleta* x, char* tipo);
int bicicletaSetTiempo(eBicicleta* x, int tiempo);
int bicicletaGetId(eBicicleta* x, int* id);
int bicicletaGetNombre(eBicicleta* x, char* nombre);
int bicicletaGetTipo(eBicicleta* x, char* tipo);
int bicicletaGetTiempo(eBicicleta* x, int* tiempo);

int mostrarBicicleta(eBicicleta* x);
int mostrarBicicletas(LinkedList* this);
void* setTiempoAleatorio(void* bicicleta);
int getRandom(int x,int y);
int menuTipos();
int filtrarBmx(void* x);
int filtrarPlayera(void* x);
int filtrarMtb(void* x);
int filtrarPaseo(void* x);
LinkedList* filtrarPorTipo(LinkedList* this);

int ordenarBicicletas(void* a, void* b);

