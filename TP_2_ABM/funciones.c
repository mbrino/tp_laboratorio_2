#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int  inicializarArray(EPersona lista[], int lenght)
{
    int i;
    if(lista!=NULL && MAXCANT>0)
    {
       for(i=0; i<MAXCANT; i++)
        {
            lista[i].estado=1;
        }
        return 0;
    }
    return -1;
}

int obtenerEspacioLibre(EPersona lista[], int length)
{
    int i;
    if(lista!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            if(lista[i].estado==1)
            {
                return i;
            }
        }
    }
    return -1;
}

EPersona* buscarPorDni(EPersona lista[], int dni)
{
    int i;
    if(lista!=NULL && MAXCANT>0)
    {
        for(i=0; i<MAXCANT; i++)
        {
            if(lista[i].dni==dni)
            {
                return &lista[i];
            }
        }
    }
    return NULL;
}

int altaPersonas(EPersona lista[], int lenght, int dni, int edad, char nombre[])
{
    int i;
    if(lista!=NULL && lenght>0)
    {
        for(i=0; i<lenght; i++)
        {
          if(lista[i].estado==1)
           {
               lista[i].dni=dni;
               lista[i].edad=edad;
               lista[i].estado=0;
               strcpy(lista[i].nombre,nombre);
               return 0;
           }
        }
    }
    return -1;
}

int bajaPersonas(EPersona lista[], int dni)
{
    int i;
    if(lista!=NULL && MAXCANT>0)
    {
        for(i=0; i<MAXCANT; i++)
        {
            if(lista[i].dni==dni)
            {
                lista[i].estado=1;
                return 0;
            }
        }
    }
    return -1;
}

void listarOrdenado(EPersona lista[], int length)
{
    int i, j;
    EPersona auxList[length];
    EPersona aux;
    for(i=0; i<length; i++)
    {
        auxList[i]=lista[i];
    }
    for(i=0; i<length-1; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(auxList[i].estado==0)
            {
                if(strcmp(auxList[i].nombre, auxList[j].nombre)>0)
                {
                    aux=auxList[i];
                    auxList[i]=auxList[j];
                    auxList[j]=aux;
                }
            }
        }
    }
    for(i=0; i<length; i++)
    {
        if(auxList[i].estado==0)
        {
            printf("Persona:\n\tNombre: %s\n\tDNI: %d\n\tEdad: %d\n", auxList[i].nombre, auxList[i].dni, auxList[i].edad);
        }
    }
    printf("\n\n");
}
void graficarEdades(EPersona lista[], int length)
{
    int i;
    int menos18=0;
    int de18a35=0;
    int mayores35=0;
    int ejeY=0;

    for(i=0; i<length; i++)
    {
        if(lista[i].estado==0)
        {
            if(lista[i].edad<18)
            {
                menos18=menos18+1;
            }else if(lista[i].edad>=18 && lista[i].edad<=35)
            {
                de18a35=de18a35+1;
            }else
            {
                mayores35=mayores35+1;
            }
        }

    }

    if(menos18>=de18a35 && menos18>=mayores35)
    {
        ejeY=ejeY+menos18;
    }else if(de18a35>=menos18 && de18a35>=mayores35)
    {
        ejeY=ejeY+de18a35;
    }else
    {
        ejeY=ejeY+mayores35;
    }

    for(i=ejeY; i>0; i--)
    {
        printf("%02d|", i);
        if(menos18>=i)
        {
            printf("*");
        }
        printf("\t");
        if(de18a35>=i)
        {
            printf("*");
        }
        printf("\t");
        if(mayores35>=i)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n");
    //printf("\n   %d\t%d\t%d\n", menos18, de18a35, mayores35);
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;
    char opcion='s';

    while(tolower(opcion)=='s')
    {
        printf("%s\n", message);
        fflush(stdin);
        scanf("%d", &aux);
        if(aux>=lowLimit && aux<=hiLimit)
        {
            *input=aux;
            return 0;
        }

        printf(eMessage);
        printf("Desea volver a ingresar el valor (s/n)");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    return -1;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[2000];
    int auxLenght;
    char opcion='s';

    while(tolower(opcion)=='s')
    {
        printf("%s\n", message);
        fflush(stdin);
        scanf("%s",aux);
        auxLenght=strlen(aux);
        if(auxLenght>lowLimit && auxLenght<hiLimit)
        {
            strcpy(input, aux);
            return 0;
        }
        printf(eMessage);
        printf("Desea volver a ingresar el valor (s/n)");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    return -1;
}
