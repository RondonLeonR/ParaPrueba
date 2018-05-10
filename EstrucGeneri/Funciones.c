#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define TAMANIO 10
#define OCUP 1
#define LIB  -1

//Inicializo todas las posiciones con el valor ingresado = -1.
void eUsu_init( eUsuario listado[],int limite)
{
    int i;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIB;
            listado[i].ID_Usuario= 0;
        }
}
//Busco lugar libre, devuelvo el primero encontrado.
int eUsu_buscarLugarLibre(eUsuario listado[],int limite)
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
int eUsu_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUP)
            {
                if(listado[i].ID_Usuario>retorno)
                {
                    retorno=listado[i].ID_Usuario;
                }
            }
        }
    }

    return retorno+1;
}

//Devulvo la posicion del id con los datos guardados en el.
int eUsu_buscarPorId(eUsuario listado[] ,int limite, int id)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(listado[i].ID_Usuario==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


//Muestro a un solo usuario.
void eUsu_mostrarUno(eUsuario parametro)
{
     printf("ID: %d ---- Nombre: %s \n",parametro.ID_Usuario,parametro.nombre);
     //mostrar la otra estructura .2f
     //

}
//Muestro todos el listado, usando la funcion mostrar uno.
void eUsu_mostrarListado(eUsuario listado[],int limite)
{
    int i;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUP)
            {
                eUsu_mostrarUno(listado[i]);
            }
        }
        /*for(i=0; i<limiteUsu; i++)
        {
        if(listado[i].estado!=LIB)
        {
            printf("ID: %d Usuario: %s",listadoUsuarios[i].ID_Usuario,listadoUsuarios[i].nombre);
            for(j=0;j<limite;j++)
            {
                if(listadoUsuarios[i].ID_Usuario==listado[j].ID_Produc)
                {
                    eProd_mostrarUno(listado[i]);
                }
                }
            }
        }*/
}

void eUsu_alta(eUsuario  listado[],int limite)
{

    int id;
    int indice;

        indice = eUsu_buscarLugarLibre(listado,limite);
        if(indice==-1)
        {
            printf("No hay mas lugar.");
            getch();
        }
        else{
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(listado[indice].nombre);
            printf("Ingrese password: ");
            scanf("%d",&listado[indice].password);
            system("cls");
            printf("\nUsuario %s ingresado con exito.",listado[indice].nombre);
            getch();
            system("cls");
        }
            id=eUsu_siguienteId(listado,limite);//importante
            listado[indice].ID_Usuario = id;
            listado[indice].estado = OCUP;
}

void eUsu_modificacion(eUsuario listado[] ,int limite)
{
    int idIngresado;
    int idEncontrado;

    eUsu_mostrarListado(listado,limite);            //eProd_mostrarListado(listado,listadoUsuarios,limite,limiteUsu);2 struc
    printf("Ingrese el ID del usuario a modificar: ");
    scanf("%d",&idIngresado);

    idEncontrado = eUsu_buscarPorId(listado,limite,idIngresado);
    if(idEncontrado==-1)
        {
            printf("El ID ingresado es inexistente.");
            getch();
        }
    else{
            //Validar con un if y switch
            printf("Usuario a modificar: %s",listado[idEncontrado].nombre);
            printf("\nIngrese Nuevo Nombre: ");
            fflush(stdin);
            gets(listado[idEncontrado].nombre);
            printf("Ingrese Nueva Password: ");
            scanf("%s",&listado[idEncontrado].password);
            printf("\n \nModificacion realizada con exito.");
            getch();
        }
}

void eUsu_baja(eUsuario listado[] ,int limite)
{
    int i;
    int idIngresado;
    int idEncontrado;
    int opc;

    eUsu_mostrarListado(listado,limite);            //eProd_mostrarListado(listado,listadoUsuarios,limite,limiteUsu);
    printf("Ingrese el ID del usuario que desea dar de baja:");
    scanf("%d",&idIngresado);
    idEncontrado = eUsu_buscarPorId(listado,limite,idIngresado);
    if(idEncontrado==-1)
    {
        printf("El ID ingresado no existe.");
        getch();
    }
    else{
        printf("El usuario que desea borrar es %s?",listado[idEncontrado].nombre);
        printf("\nOpcion 1) SI\nOpcion 2) NO");
        scanf("%d",&opc);
            switch(opc){
            case 1:{
                listado[idEncontrado].estado=-1;
                printf("El usuario ha sido eliminado.");
                getch();
                break;
                }
            case 2:{
                printf("La baja ha sido cancelada.");
                getch();
                break;
                }
            }
        }
}
