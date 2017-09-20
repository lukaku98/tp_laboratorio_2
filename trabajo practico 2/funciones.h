#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    char nombre[50];
    int edad;
    int estado;
    int dni;

} EPersona;

void cargarPersona (EPersona [], int);
void eliminarPersona (EPersona [], int);
void ordenarNombres (EPersona [], int);
void graficoEdad (EPersona[], int);
void init (EPersona[], int);
void validarCaracter (EPersona [], int);
void validarNumero (int);


#endif
