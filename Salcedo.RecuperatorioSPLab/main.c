#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "controller.h"
#include "LinkedList.h"
#include "bicicletas.h"


int menu();

int main()
{
    srand(time(NULL));
    char path[40];
    LinkedList* listaBicicletas = ll_newLinkedList();
    LinkedList* listaBicicletasActualizada = NULL;
    LinkedList* listaFiltradaPorTipo = ll_newLinkedList();

    int menuOption;
    int flagCarga = 0;
    int flagOrden=0;
   // char confirma = 's';

    if(listaBicicletas == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        system("cls");

        menuOption = menu();
        switch(menuOption)
        {

        case 1:

            if(!flagCarga)
            {
                printf("**Nombre del archivo: bicicletas.csv\n\n**");
                utn_getDescripcion(path,sizeof(path),"Ingrese nombre del archivo: ","Error.Reingrese el nombre del archivo: ",3);

                if(!cargarArchivoTexto(listaBicicletas,path))
                {
                    printf("Archivos cargados correctamente\n\n");
                    system("pause");

                    flagCarga = 1;
                }

            }
            else{
                printf("Ya fue cargado un archivo\n\n");
                system("pause");
            }
            break;

        case 2:
            system("cls");
            if(flagCarga)
            {
                mostrarBicicletas(listaBicicletas);
                system("pause");
            }
            else
            {
                printf("****Primero cargue los datos****\n");
                system("pause");
            }
            break;

        case 3:
            if(flagCarga)
            {
                listaBicicletasActualizada=ll_map(listaBicicletas,setTiempoAleatorio);
                printf("Asignaciones realizadas con exito\n\n");
                system("pause");
            }
            else
            {
                 printf("****Primero cargue los datos****\n");
                 system("pause");
            }
            break;

        case 4:
            if(flagCarga)
            {

                    listaFiltradaPorTipo = filtrarPorTipo(listaBicicletasActualizada);
                    mostrarBicicletas(listaFiltradaPorTipo);
                    printf("\nIngrese el nombre del archivo a guardar (debe incluir la extension del archivo): ");
                    fflush(stdin);
                    gets(path);
                    if(!guardarArchivoTexto(listaFiltradaPorTipo,path))
                    {
                        printf("\nArchivo guardado con exito.\n");
                    }
            }
            else
            {
                printf("****Primero cargue los datos****\n");
                system("pause");

            }
            break;

        case 5:
            if(listaBicicletasActualizada!= NULL)
            {
                ll_sort(listaBicicletasActualizada,ordenarBicicletas,1);
                printf("**Lista ordenada por tipo y tiempo**\n\n");
                mostrarBicicletas(listaBicicletasActualizada);
                system("pause");
                flagOrden = 1;

            }
            else
            {
                printf("\n\nPrimero realice las asignaciones\n\n");
                system("pause");
            }
            break;

        case 6:
            if(flagOrden)
            {
                printf("Ingrese el nombre con el cual desea guardar el archivo (ej: listaOrdenada.csv) : ");

                fflush(stdin);
                gets(path);
                if(!guardarArchivoTexto(listaBicicletasActualizada,path))
                {
                    printf("\n\n**Archivo guardado con exito**\n\n");
                }

            }
            else
            {
                printf("**Error.Primero debe ordenar la lista\n\n");
                system("pause");
            }
            break;

        case 7:
            exit(1);
            break;

        }




    }while(menuOption != 7);



    return 0;
}



int menu()
{
    int opcion;

    printf("1.Cargar archivo\n");
    printf("2.Imprimir lista\n");
    printf("3.Asignar tiempos\n");
    printf("4.Filtrar por tipo\n");
    printf("5.Mostrar posiciones\n");
    printf("6.Guardar posiciones\n");
    printf("7.Salir\n\n");


    utn_getNumero(&opcion,"Ingrese opcion: ","Error.Reingrese opcion: ",1,7,3);

    return opcion;
}
