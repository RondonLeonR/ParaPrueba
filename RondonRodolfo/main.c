#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Propietarios.h"
#include "Autos.h"
#define CANTIDAD 20

int main()
{
    ePropietario listados[CANTIDAD];
    ePro_init(listados,CANTIDAD);

    eAutosEstacionados listadosDeAutos[CANTIDAD];
    eAutE_init(listadosDeAutos,CANTIDAD);

    ePro_inicializarUsuariosHardCode(listados);
    eAutE_inicializarUsuariosHardCode(listadosDeAutos);

    int opcion;
    char resp='s';

    do{
        system("cls");//                    Alta al producto.
        printf("1-Alta\n2-Modificacion\n3-Dar de baja\n4-Ingreso de Automovil\n7-Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:{

                    ePro_alta(listados,CANTIDAD);
                    break;
                }
            case 2:{
                    ePro_modificacion(listados,CANTIDAD);
            break;
                }
            case 3:{
                    ePro_baja(listados,CANTIDAD);
                    break;
                }
            case 4:
                {
                    eAutE_alta(listados,CANTIDAD,listadosDeAutos,CANTIDAD);
                    break;
                }
            /*case 5:
                {
                    eProd_modificacion(listadoProductos,listadoUsuarios,CANTIDAD,CANTIDAD);
                    break;

                }
            case 6:
                {
                    eProd_baja(listadoProductos,listadoUsuarios,CANTIDAD,CANTIDAD);
                    break;
                }*/
            case 7:
                {
                    resp='n';
                    break;
                }
            }
    }while(resp=='s');
    return 0;
}
