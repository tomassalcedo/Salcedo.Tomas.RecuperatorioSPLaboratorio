#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>
#include "controller.h"
#include "bicicletas.h"


int cargarArchivoTexto(LinkedList* lista, char* path)
{
    int todoOk = 1;
    char header[4][128];
    char buffer[4][128];
    int cantidad;
    eBicicleta* newBicicleta;
    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",header[0],header[1],header[2],header[3]);

        while(!(feof(pFile)))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cantidad == 4)
            {
                todoOk = 0;
                newBicicleta = bicicletaNewParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(newBicicleta != NULL)
                {
                    ll_add(lista,newBicicleta);
                }
            }
            else
            {
                break;
            }
        }
    }
    return todoOk;
}

int guardarArchivoTexto(LinkedList* this, char* path)
{
    int todoOk = 1;
    int len;
    eBicicleta* auxBicicleta;
    int id;
    char nombre[21];
    char tipo[12];
    int tiempo;

    FILE* pFile = fopen(path,"w");

    if(pFile != NULL && this != NULL)
    {
        fprintf(pFile,"id_bike,nombre,tipo,tiempo\n");
        len = ll_len(this);
        for(int i = 0; i < len; i++)
        {
            auxBicicleta = (eBicicleta*) ll_get(this, i);
            if(auxBicicleta != NULL)
            {
                if(!(bicicletaGetId(auxBicicleta,&id)
                        || bicicletaGetNombre(auxBicicleta,nombre)
                        || bicicletaGetTipo(auxBicicleta,tipo)
                        || bicicletaGetTiempo(auxBicicleta,&tiempo)))
                    {
                        fprintf(pFile,"%d,%s,%s,%d\n",id,nombre,tipo,tiempo);
                        todoOk = 0;
                    }
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
