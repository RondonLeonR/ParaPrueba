#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10//Esto modificar segun el ejercicio.

int main()
{
    eAUX listado;
    listado aux_init(listado,CANTIDAD);

    int opcion;
    char resp='s';

    do{
        system("cls");//                    Alta al producto.
        printf("1-Alta\n2-Baja\n3-Modificar\n4-Publicar Producto\n5-Modificar Producto de Usuario\n6-Listado\n7-Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:{
            break;
            }
            case 2:{
            break;
            }
            case 3:
                {
                    eUsu_baja(listadoUsuarios, CANTIDAD);
                    break;
                }
            case 4:
                {
                    eProd_alta(listadoProductos,CANTIDAD);
                    getch();
                    break;
                }
            case 5:
                {
                    eProd_modificacion(listadoProductos,listadoUsuarios,CANTIDAD,CANTIDAD);
                    break;

                }
            case 6:
                {
                    eProd_baja(listadoProductos,listadoUsuarios,CANTIDAD,CANTIDAD);
                    break;
                }
            case 7:
                {
                    resp='n';
                    break;
                }
            }
    }while(resp=='s');

        }

    }
    return 0;
}
