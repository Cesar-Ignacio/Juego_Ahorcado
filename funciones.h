#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int cantidadEspacios(char *palabra)
{
    int c=0;

    for(int x=0;x<20;x++)
    {
        if(int(palabra[x])==32)
        {
            c++;
        }

    }

    return c;
}

void LimpieVector(char *palabra)
{
    for(int x=0;x<20;x++)
    {
        palabra[x]='_';
    }
}

int RecorrerPalabraM(char *palabraM,char letra)
{
    ///POSI_CUADRO=30 36 42 48 54 60 66
    ///INDICE VECT=  0  1  2  3  4  5  6 .....19
    ///PALABRA    =  L  E  A  N  D  R  A
    ///LETRA      =     E  A           A
    ///ANULACION  =     _  _           _
    int con=0;
    for(int x=0;x<20;x++)
    {
        if(palabraM[x]==letra)
        {
          con++;
          gotoxy((30+(x*6)+1),2);cout<<palabraM[x]<<endl;///UBICACION DE A LA LETRA
          palabraM[x]='_';///CAMBIAMOS EL VALOR, PARA QUE YA NO SEA RECONOCIDO
        }
    }

    return con;
}

void DibujoCuadro(int tam, char *palabraM){

    int px=30;

    for(int x=0;x<tam;x++)
    {
      if(int(palabraM[x])==32)
      {
      cuadro(px,2,1,5,12,0);

      px+=6;
      }
      else
      {
      cuadro(px,2,1,5,12,154);

      px+=6;
      }

    }

}


#endif // FUNCIONES_H_INCLUDED
