#include "operationTab.h"


//On permute aleatoirement 2 a 2 les elements d'un tableau.
void randomise (logement Tablo[], int tailleTableau) 
{
    logement tmp;
    int i;
    int a;
    for(i=0; i<tailleTableau;i++)
    {
        a = rand()%tailleTableau;
        tmp = Tablo[a];
        Tablo[a]= Tablo[i];
        Tablo[i]= tmp;
    }
}

 //On trie les distances du tableau par ordre croissant avec un tri selection.
void triTableau(logement Tablo[], int tailleTableau)
{
    logement tmp;
    int j;
    int i;
    for(i=0;i<tailleTableau; i++)
    {  
        for (j=i+1; j<tailleTableau ;j++)
        {
            if (Tablo[i].distanceAdaptee> Tablo[j].distanceAdaptee)
            {  
                tmp = Tablo[i];
                Tablo[i] = Tablo[j];
                Tablo[j] = tmp;
            }
        
        }
    }

}