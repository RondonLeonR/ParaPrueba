#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Autos.h"
#include "Propietarios.h"
#include "SalidaAutos.h"

#define ALPHA_ROMEO 11
#define FERRARI 22
#define AUDI 33
#define OTROS 44

void eSal_MostrarAutosPorPropietario(ePropietario listadoPropi[], eAutosEstacionados listaAutos[],int limiteUsu, int limiteAut)
{
    int idUsu;
    int indice;

    ePro_mostrarListado(listadoPropi,limiteUsu);

    printf("\n\n        Ingrese el ID del usuario que desea ver: ");
    scanf("%d",&idUsu);

}

void eSal_EgresoHardcodeo(eSalidaAuto egresos[])
{
    int marca[]= {11,11,22,33,22,22,33,44,11,11};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};

    for(int i=0;i<=10;i++)
    {
        egresos[i].marca=marca[i];
        egresos[i].importe=importe[i];
    }
}

void eSal_EgresoAuto(eAutosEstacionados lista[],ePropietario listado[] , eSalidaAuto egresos[], int limiteAut, int limiteUsu)
{
    eSal_PrecioPorEstadia(egresos,limiteAut);
    eSal_GraficoDePrecios();

    printf("\n\t\tTicket\n\nPropietario\t Patente\t Marca\tImporte\n");

    for(int i=0;i<limiteAut;i++)
    {
        if(listado[i].estado==1)
        {
            printf("%s",listado[i].nombre);

                for(int j=0;j<limiteAut;j++)
                {
                    if(listado[i].ID_Propietario==lista[j].ID_Propietario)
                    {
                        if(lista[j].estado!=-1){
                            printf("    %s    %d",lista[j].patente, lista[j].marca);
                            for(int l=0;l<limiteAut;l++)
                            {
                                if(lista[j].marca==egresos[l].marca)
                                {
                                    printf("    $%.2f\n",egresos[l].importe);
                                    break;
                                }
                            }
                        }
                    }

                }
        }
    }

    getch();


}

void eSal_PrecioPorEstadia(eSalidaAuto egresos[],int limite)
{
    int resul;
    int horaRandom= devolverHorasEstadia();

    for(int i=0;i<limite;i++)
    {
        if(egresos[i].marca==11)
        {
            resul=horaRandom*150;
            egresos[i].importe=resul;
        }
        else if(egresos[i].marca==22)
        {
            resul=horaRandom*175;
            egresos[i].importe=resul;
        }
        else if(egresos[i].marca==33)
        {
            resul=horaRandom*200;
            egresos[i].importe=resul;
        }
        else if(egresos[i].marca==44)
        {
            resul=horaRandom*250;
            egresos[i].importe=resul;
        }
    }
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas;
}

void eSal_GraficoDePrecios(void)
{
    printf("\nMarca\t\t\tPrecio Por Hora\n\n");
    printf("ALPHA_ROMEO\t\t     $150\n");
    printf("FERRARI\t\t\t     $175\n");
    printf("AUDI\t\t\t     $200\n");
    printf("OTROS\t\t\t     $250\n");
}
