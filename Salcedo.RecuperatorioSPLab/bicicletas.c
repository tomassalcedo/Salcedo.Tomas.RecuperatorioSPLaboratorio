#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "bicicletas.h"



eBicicleta* bicicletaNew()
{
    return (eBicicleta*) malloc(sizeof(eBicicleta));
}


eBicicleta* bicicletaNewParametros(char* id, char* nombre, char* tipo, char* tiempo)
{
    eBicicleta* newBicicleta = NULL;

    newBicicleta = bicicletaNew();

    if(bicicletaSetId(newBicicleta,atoi(id))
            ||  bicicletaSetNombre(newBicicleta,nombre)
            ||  bicicletaSetTipo(newBicicleta,tipo)
            ||  bicicletaSetTiempo(newBicicleta,atoi(tiempo)))
    {
        bicicletaDelete(newBicicleta);
    }

    return newBicicleta;
}


void bicicletaDelete(eBicicleta* x)
{
    free(x);
    x = NULL;
}



int bicicletaSetId(eBicicleta* x, int id)
{
    int todoOk = 1;

    if(x != NULL && id > 0)
    {
        x->id = id;
        todoOk = 0;
    }

    return todoOk;
}

int bicicletaSetNombre(eBicicleta* x, char* nombre)
{
    int todoOk = 1;

    if(x != NULL && nombre != NULL)
    {
        strcpy(x->nombre,nombre);
        todoOk = 0;
    }

    return todoOk;
}

int bicicletaSetTipo(eBicicleta* x, char* tipo)
{
    int todoOk = 1;

    if(x != NULL && tipo != NULL)
    {
        strcpy(x->tipo,tipo);
        todoOk = 0;
    }

    return todoOk;
}

int bicicletaSetTiempo(eBicicleta* x, int tiempo)
{
    int todoOk = 1;

    if(x != NULL && tiempo >= 0)
    {
        x->tiempo = tiempo;
        todoOk = 0;
    }

    return todoOk;
}


int bicicletaGetId(eBicicleta* x, int* id)
{
    int todoOk = 1;

    if(x != NULL && id != NULL)
    {
        *id = x->id;
        todoOk = 0;
    }

    return todoOk;
}


int bicicletaGetNombre(eBicicleta* x, char* nombre)
{
    int todoOk = 1;

    if(x != NULL && nombre != NULL)
    {
        strcpy(nombre,x->nombre);
        todoOk = 0;
    }

    return todoOk;
}


int bicicletaGetTipo(eBicicleta* x, char* tipo)
{
    int todoOk = 1;

    if(x != NULL && tipo != NULL)
    {
        strcpy(tipo,x->tipo);
        todoOk = 0;
    }

    return todoOk;
}

int bicicletaGetTiempo(eBicicleta* x, int* tiempo)
{
    int todoOk = 1;

    if(x != NULL && tiempo != NULL)
    {
        *tiempo = x->tiempo;
        todoOk = 0;
    }

    return todoOk;
}


int mostrarBicicleta(eBicicleta* x)
{
     int todoOk = 1;

    int id;
    char nombre[21];
    char tipo[21];
    int tiempo;

    if(x != NULL)
    {
        if(!(bicicletaGetId(x,&id)
                || bicicletaGetNombre(x,nombre)
                || bicicletaGetTipo(x,tipo)
                || bicicletaGetTiempo(x,&tiempo)))
        {
            printf("%2d  %15s %8s  %6d\n",id,nombre,tipo,tiempo);
            todoOk = 0;
        }
    }

    return todoOk;
}

int mostrarBicicletas(LinkedList* this)
{
    int todoOk = 1;
    int len;
    eBicicleta* auxBicicleta;

    system("cls");

    if(this != NULL)
    {
        len = ll_len(this);
        printf("------------------------------------------------------------------------\n");
        printf("   Id        Nombre      Tipo    Tiempo  \n");
        printf("------------------------------------------------------------------------\n");

        for(int i = 0; i < len; i++)
        {
            auxBicicleta = (eBicicleta*) ll_get(this,i);

            if(auxBicicleta != NULL)
            {
                mostrarBicicleta(auxBicicleta);
                todoOk = 0;
            }
        }

        if(todoOk)
        {
            printf("\nNo hay bicicletas para mostrar\n");
        }
    }
    return todoOk;
}


int getRandom(int x,int y)
{
    int aleatorio;

    aleatorio = rand()%(x)+y;

    return aleatorio;
}


void* setTiempoAleatorio(void* bicicleta)
{
    eBicicleta* auxBicicleta;
    void* pElement;
    int aleatorioTiempo;

    if(bicicleta != NULL)
    {
        auxBicicleta = (eBicicleta*) bicicleta;
        aleatorioTiempo = getRandom(71,50);

        if(bicicletaSetTiempo(auxBicicleta,aleatorioTiempo))
        {
            pElement = NULL;
        }
        else
        {
            pElement = (void*) auxBicicleta;
        }
    }

    return pElement;
}



int menuTipos()
{
    int opcion;

    printf("1)Bmx\n");
    printf("2)Playera\n");
    printf("3)Mtb\n");
    printf("4)Paseo\n\n");
    utn_getNumero(&opcion,"Ingrese opcion: ","Error.Reingrese opcion: ",1,4,3);

    return opcion;
}


int filtrarBmx(void* x)
{
    int returnAux = 0;
    eBicicleta* auxBicicleta;
    char tipo[12];

    if(x != NULL)
    {
        auxBicicleta = (eBicicleta*) x;
        bicicletaGetTipo(auxBicicleta,tipo);
        if(!strcmp(tipo,"BMX"))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

int filtrarPlayera(void* x)
{
    int returnAux = 0;
    eBicicleta* auxBicicleta;
    char tipo[12];

    if(x != NULL)
    {
        auxBicicleta = (eBicicleta*) x;
        bicicletaGetTipo(auxBicicleta,tipo);
        if(!strcmp(tipo,"PLAYERA"))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

int filtrarMtb(void* x)
{
    int returnAux = 0;
    eBicicleta* auxBicicleta;
    char tipo[12];

    if(x != NULL)
    {
        auxBicicleta = (eBicicleta*) x;
        bicicletaGetTipo(auxBicicleta,tipo);
        if(!strcmp(tipo,"MTB"))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

int filtrarPaseo(void* x)
{
    int returnAux = 0;
    eBicicleta* auxBicicleta;
    char tipo[12];

    if(x != NULL)
    {
        auxBicicleta = (eBicicleta*) x;
        bicicletaGetTipo(auxBicicleta,tipo);
        if(!strcmp(tipo,"PASEO"))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

LinkedList* filtrarPorTipo(LinkedList* this)
{
    system("cls");
    LinkedList* listaFiltrada = NULL;
    printf("Seleccione un tipo de bicicleta:\n");

    switch(menuTipos())
    {
    case 1:
        listaFiltrada = ll_filter(this,filtrarBmx);
        break;
    case 2:
        listaFiltrada = ll_filter(this,filtrarPlayera);
        break;
    case 3:
        listaFiltrada = ll_filter(this,filtrarMtb);
        break;
    case 4:
        listaFiltrada = ll_filter(this,filtrarPaseo);
        break;
    }

    return listaFiltrada;
}


int ordenarBicicletas(void* a, void* b)
{
    int retorno;
    eBicicleta* bicicleta1;
    eBicicleta* bicicleta2;
    char tipoB1[12];
    char tipoB2[12];
    int tiempoB1;
    int tiempoB2;

    if(a != NULL && b != NULL)
    {
        bicicleta1 = (eBicicleta*) a;
        bicicleta2 = (eBicicleta*) b;

        if(!(bicicletaGetTipo(bicicleta1,tipoB1)
                || bicicletaGetTipo(bicicleta2,tipoB2)
                || bicicletaGetTiempo(bicicleta1,&tiempoB1)
                || bicicletaGetTiempo(bicicleta2,&tiempoB2)))
        {
            if(strcmp(tipoB1,tipoB2) > 0)
            {
                retorno = 0;
            }
            else if(strcmp(tipoB1,tipoB2) == 0 && tiempoB1 < tiempoB2)
            {
                retorno = 0;
            }
        }

    }

    return retorno;
}
