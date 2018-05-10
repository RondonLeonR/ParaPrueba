#ifndef ESTRUCPARCIAL_H_INCLUDED
#define ESTRUCPARCIAL_H_INCLUDED
typedef struct{

int ID_Usuario;
char nombre[50];
char password[50];
int estado;

}eUsuario;
#endif // ESTRUCPARCIAL_H_INCLUDED
void eUsu_init(eUsuario[],int limite);
int eUsu_buscarPorId(eUsuario listado[] ,int limite, int id);
int eUsu_siguienteId(eUsuario listado[] ,int limite);
int eUsu_buscarLugarLibre(eUsuario listado[],int limite);

void eUsu_mostrarUno(eUsuario parametro);
void eUsu_mostrarListado(eUsuario listado[] ,int limite);           //void eProd_mostrarListado(eProducto listado[],eUsuario listadoUsuarios[],int limite,int limiteUsu);

void eUsu_alta(eUsuario listado[] ,int limite);
void eUsu_baja(eUsuario listado[] ,int limite);             //void eProd_baja(eProducto listado[],eUsuario listadoUsuarios[],int limite,int limiteUsu);
void eUsu_modificacion(eUsuario listado[] ,int limite);                 //void eProd_modificacion(eProducto listado[],eUsuario listadoUsuarios[] ,int limite,int limiteUsu);
