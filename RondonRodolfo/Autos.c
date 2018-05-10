#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autos.h"
#define TAMANIO 10
#define OCUP 1
#define LIB  -1
#define  ALPHA_ROMEO 65
#define  FERRARI    66
#define  AUDI       67
#define  COTRO      68
void eAutE_init( eAutosEstacionados listado[],int limite)
{
    int i;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIB;
            listado[i].ID_Auto= 0;
        }
}
//Busco lugar libre, devuelvo el primero encontrado.
int eAutE_buscarLugarLibre(eAutosEstacionados listado[],int limite)
{
    int retorno = -1;
    int i;

        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIB)
            {
                retorno = i;
                break;
            }
        }
    return retorno;
}
//Devuelvo la siguiente posicion en el array, que este libre.
int eAutE_siguienteId(eAutosEstacionados listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUP)
            {
                if(listado[i].ID_Auto>retorno)
                {
                    retorno=listado[i].ID_Auto;
                }
            }
        }
    }

    return retorno+1;
}

//Devulvo la posicion del id con los datos guardados en el.
int eAutE_buscarPorId(eAutosEstacionados listado[] ,int limite, int id)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(listado[i].ID_Auto==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void eAutE_mostrarUno(eAutosEstacionados parametro)
{
     printf("ID: %d -- Marca: %s -- Patente: %d \n",parametro.ID_Auto,parametro.marca,parametro.patente);
}
//Muestro todos el listado, usando la funcion mostrar uno.
void eAutE_mostrarListado(eAutosEstacionados listado[],ePropietario listadoUsuarios[],int limite,int limiteUsu)
{
    int i;
    int j;
    for(i=0; i<limiteUsu; i++)
        {
        if(listado[i].estado!=LIB)
        {
            printf("ID: %d Usuario: %s",listadoUsuarios[i].ID_Propietario,listadoUsuarios[i].nombre);
            for(j=0;j<limite;j++)
            {
                if(listadoUsuarios[i].ID_Propietario==listado[j].ID_Auto)
                {
                    eAutE_mostrarUno(listado[i]);
                }
                }
            }
        }
}

void eAutE_inicializarUsuariosHardCode(eAutosEstacionados listados[])
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char paten[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    int i;

    for(i=0;i<=10;i++){
        if(marca[i]==1){
           strcpy(listados[i].marca,65);
        }
        if(marca[i]==2){
            strcpy(listados[i].marca,66);
        }
        if(marca[i]==3){
            strcpy(listados[i].marca,67);
        }
        else{
            strcpy(listados[i].marca,68);
        }
    }
    int j;

    for(j=0;j<=10;j++)
    {
        listados[j].ID_Auto=id[j];
        listados[j].estado = 1;
        strcpy(listados[j].patente,paten[j]);
        if(AAAAAA)
    }



}

void eAutE_alta(eAutosEstacionados listado[] ,int limite,ePropietario listaUsu, int limiteUsu)
{
    int idIngresado;
    int idEncontrado;
    int i;
    int indice;
        indice = eAutE_buscarLugarLibre(listado,limite);
        printf("Ingrese ID de Propietario: ");
        scanf("%d",&idIngresado);


        if(indice==-1)
        {
            printf("No hay mas lugar.");
            getch();
        }
        else{
            printf("Ingrese Patente: ");
            fflush(stdin);
            gets(listado[indice].patente);
            printf("Ingrese marca: ");
            fflush(stdin);
            gets(listado[indice].marca);
            system("cls");
            printf("\nAuto ingresado con exito.");
            getch();
            system("cls");
        }
            id=ePro_siguienteId(listado,limite);//importante
            listado[indice].ID_Propietario = id;
            listado[indice].estado = OCUP;

         ePro_mostrarListado(listado,limite);
         getch();

}
