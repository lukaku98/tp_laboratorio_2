#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define M 10


void cargarPersona (EPersona persona [], int tam)
{

    int banderaEncontro = 0, i;

    for (i=0; i < tam ; i++)
    {
        if (persona[i].estado==0)
        {
            printf("Ingrese nombre: \n");
            fflush(stdin);
            gets(persona[i].nombre);
            persona[i].estado=1;
            banderaEncontro=1;
            printf("Ingrese edad: \n");
            scanf("%d", &persona[i].edad);
            while (persona[i].edad > 99 )
            {
                fflush(stdin);
                printf("Edad ingresada invalida. Vuela a ingresar \n");
                scanf("%d", &persona[i].edad);
            }
            printf("Ingrese DNI: \n");
            scanf("%d", &persona[i].dni);
            break;
        }
    }
    if(!banderaEncontro)
    {
        printf("No hay espacio suficiente!!!");
    }
}
void eliminarPersona (EPersona persona [], int tam)
{
    int banderaEncontro=0, i;
    int auxInt;
    char respuesta;
    printf("Ingrese DNI: ");
    scanf("%d", &auxInt);
    while(fflush(stdin))
    {
        printf("Error. ingrese DNI correcto \n");
        scanf("%d", auxInt);
        system("pause");
    }
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado == 1)
        {
            if(auxInt == persona[i].dni)
            {
                printf("%s\t%d\t%d\n", persona[i].nombre, persona[i].dni,persona[i].edad);
                printf("¿Esta seguro de eliminar el dato? s/n: ");
                respuesta = getche();
                if(respuesta=='s')
                {
                    printf("\n Datos eliminados\n");
                    persona[i].estado = 0;
                    system("pause");
                }
                else if (respuesta=='n')
                {
                    printf("\n Accion cancelada por el usuario!!! \n");
                    system("pause");
                }
                else
                {
                    printf("\n La opcion ingresada no es valida. Reingrese \n");
                    system("pause");
                }

                banderaEncontro=1;
            }
        }
    }
}
void ordenarNombres (EPersona persona [], int tam)
{
    EPersona personaAux;
    int i, j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                personaAux = persona[i];
                persona[i] = persona[j];
                persona[j] =  personaAux;
            }

        }
    }
}

void graficoEdad (EPersona persona[], int tam)
{
    int i, j, hasta18=0, de19a35=0, mayorDe35=0, bandera=0, mayor;

    for(j=0; j<tam; j++)
    {
        if(persona[j].edad<18 && persona[j].edad>0)
        {
            hasta18++;

        }
        else if(persona[j].edad>35)
        {
            mayorDe35++;
        }
        else if( persona[j].edad > hasta18)
        {
            de19a35++;
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        printf("%02d|",i);

        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            bandera=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(bandera==0)
                printf("\t\t*");
            if(bandera==1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", hasta18, de19a35, mayorDe35);
}

void init(EPersona persona[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        persona[i].estado = 0;
        persona[i].edad = 0;
        persona[i].dni=0;
    }
}
