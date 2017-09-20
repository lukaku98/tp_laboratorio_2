#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define M 10


int main()
{
    char seguir='s';
    int opcion=0, i;
    EPersona persona [M];
    init (persona, M);

    do
    {
        system("cls");
        printf("---------------------------------------------------------------\n");
        printf("----------------------**INFORME DE DATOS**----------------------\n");
        printf( "---------------------------------------------------------------\n");
        printf("\n");
        printf("                     Seleccione una opcion: \n");
        printf("                      1- Agregar persona\n");
        printf("                      2- Borrar persona\n");
        printf("              3- Imprimir lista ordenada por  nombre\n");
        printf("                4- Imprimir grafico de edades\n\n");
        printf("                           5- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            fflush(stdin);
            cargarPersona (persona, M);
            fflush(stdin);
            break;
        case 2:
            eliminarPersona (persona, M);
            break;
        case 3:
            ordenarNombres (persona, M);
            printf("nombre\tEdad\tDNI\n");
            for(i=0; i<M; i++)
            {
                if(persona[i].estado !=0)
                    printf("%s\t%d\t%d\n", persona[i].nombre, persona[i].edad,persona[i].dni);
            }
            system("pause");
            break;
        case 4:
            graficoEdad(persona, M);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            fflush(stdin);
            printf("Error. ingrese una de las opciones validas. \n");
            system("pause");
            break;
        }
    }
    while (seguir=='s');
    return 0;
}
