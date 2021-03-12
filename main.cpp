#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;
///LIBRERIA EXTERNAS
#include "gotoxy.h"
#include "color.h"
#include "cuadro.h"

#include "prototipos.h"
#include "funciones.h"



int main()
{

    char palabraP[20], palabraS[20],palabraPP[20];
    char letra;

    int x=0,valor=0,vida=5,contador=0,tampalabra=0,cuadroD=0;

    LimpieVector(palabraP);

    cout<<"Palabra magica:";
    cin.getline(palabraP,20);///INGRESO DE PALABRA

    strcpy(palabraPP,palabraP);///RESPALDAMOS EL CONTENIDO, REPLICANDOLO

    tampalabra=strlen(palabraP)-cantidadEspacios(palabraP);///CANTIDAD DE CARACTERES SIN ESPACIO
    cuadroD=strlen(palabraP);

    /// cout << tampalabra<<endl;CANTIDAD DE CARACTERES DE LA PALABRA

    system("cls");

    DibujoCuadro(cuadroD,palabraP);

    while (x<5)
    {
        gotoxy(5,5);cout<<"LOS CUADROS CON FONDO REGRO REPRESENTAN ESPACIO."<<endl;
        gotoxy(5,6);cout<<"#: PARA ESCRIBIT LA PALABRA COMPLETA."<<endl;
        color("",4);
        gotoxy(5,7);cout<<"Vidas "<< vida <<endl;
        color("",7);
        gotoxy(5,8);cout<<"LETRA:";
        cin>>letra;

        if(int(letra)!=35)
        {
        ///SE EJECUTA SI NO SE INGRESO #

        gotoxy(10,8);cout<<"  "<<endl;///limpia donde seecribe la letra

        valor=RecorrerPalabraM(palabraP,letra);
       if(valor==0)
        {
         vida-=1;
         x++;
        }
        else
        {
         contador+=valor;

         if(contador==tampalabra)
            {
               color("",11);
               gotoxy(45,13);cout<<"HAS GANADO"<<endl;
               color("",7);
               return 0;

            }
        }

        }
        else
        {
        ///SE EJECUTARA CUANDO SE PRESIONE #
        gotoxy(5,9);cout<<"RECORDA: SI ESCRIBES LA PALABRA INCORRECTAMENTE ABRAS PERDIDO LAS VIDAS QUE TE QUEDAN"<<endl;
        fflush(stdin);
        gotoxy(5,10);cout<<"INGRESE PALABAR:";
        cin.getline(palabraS,20);

        if(strcmp(palabraS,palabraPP)==0)
        {
            color("",11);
            gotoxy(45,13);cout<<"HAS GANADO"<<endl;
            color("",7);
            return 0;
        }
        else{
            x=5;
        }

        }



    }
    color("",11);
    gotoxy(45,13);cout<<"NO SE A PODIDO"<<endl;
    color("",7);

    system("pause");
    return 0;
}
