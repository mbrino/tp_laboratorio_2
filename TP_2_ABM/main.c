#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    char nombre[51];
    int dni;
    int edad;
    EPersona listaP[MAXCANT];
    inicializarArray(listaP, MAXCANT);

    while(seguir=='s')
    {
        system("cls");
        printf("*****************************************\n*                                       *\n");
        printf("* 1- Agregar persona                    *\n");
        printf("* 2- Borrar persona                     *\n");
        printf("* 3- Imprimir lista ordenada por  nombre*\n");
        printf("* 4- Imprimir grafico de edades         *\n");
        printf("* 5- Salir                              *\n");
        printf("*                                       *\n");
        printf("*****************************************\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(obtenerEspacioLibre(listaP, MAXCANT)!=-1)
                {
                    if(!getInt(&dni, "Ingrese un dni", "El dni ingresado no es valido", 0, 50000000) && !getString(nombre, "Ingrese un nombre", "El nombre ingresado debe tener entre 2 y 50 caracteres", 2, 50) && !getInt(&edad, "Ingrese la edad de la persona", "La edad ingresada no es valida", 1, 150))
                    {
                        if(altaPersonas(listaP, MAXCANT, dni, edad, nombre))
                        {
                            printf("Ocurrio un problema al procesar el alta, por favor comuniquese con el administrador\n");
                        }
                    }
                }else
                {
                    printf("No hay espacio para agrergar nuevas personas.\nPor favor dar de baja una persona antes\n");
                }
                system("pause");
                break;
            case 2:
                if(MAXCANT>0)
                {
                    if(!getInt(&dni, "Ingrese el dni de la persona que desea dar de baja", "El dni ingresado no es valido", 0, 50000000))
                    {
                        if(bajaPersonas(listaP, dni))
                        {
                            printf("Ocurrio un problema al procesar la baja, por favor comuniquese con el administrador\n");
                        }
                    }else
                    {
                        printf("Debe ingresar un DNI para poder realizar la baja\n");
                    }

                }else
                {
                    printf("No hay personas dadas de alta\n");
                }
                system("pause");
                break;
            case 3:
                listarOrdenado(listaP, MAXCANT);
                system("pause");
                break;
            case 4:
                graficarEdades(listaP, MAXCANT);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}


