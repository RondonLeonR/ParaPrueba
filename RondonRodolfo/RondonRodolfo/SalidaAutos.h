#include "Propietarios.h"
#include "Autos.h"

#ifndef SALIDAAUTOS_H_INCLUDED
#define SALIDAAUTOS_H_INCLUDED

typedef struct{
    float importe;
    int marca;
}eSalidaAuto;

#endif // SALIDAAUTOS_H_INCLUDED

void eSal_MostrarAutosPorPropietario(ePropietario listadoPropi[], eAutosEstacionados listaAutos[],int limiteUsu, int limiteAut);
void eSal_EgresoHardcodeo(eSalidaAuto egresos[]);
void eSal_GraficoDePrecios(void);
void eSal_EgresoAuto(eAutosEstacionados lista[],ePropietario listado[] , eSalidaAuto egresos[], int limiteAut, int limiteUsu);
void eSal_PrecioPorEstadia(eSalidaAuto egresos[],int limite);
int devolverHorasEstadia();
void eSal_RecaudacionTotal(eSalidaAuto egresos[],int limiteAut);
void eSal_RecaudacionTotalPorMarca(eSalidaAuto egresos[],int limiteAut);
void eSal_MostrarPropietariosAudi(ePropietario listado[],eAutosEstacionados lista[],int limiteUsu, int limiteAut);
void eSal_ListadoDeAutosEstacionadosOrdenados(ePropietario listado[], eAutosEstacionados lista[],int limiteUsu, int limiteAut);
