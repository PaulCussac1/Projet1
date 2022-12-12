
#include "distance.h"

//on calcul la distance euclidienne entre deux logements.
float distanceEntreLogements(logement A, logement B, int a, int b, int c, int d, int e, int f, int g) 
{  

    float distance;
    float resultat;
    distance = (A.accomodates - B.accomodates)*(A.accomodates - B.accomodates)*a
            + (A.bedrooms - B.bedrooms)*(A.bedrooms - B.bedrooms)*b
            + (A.bathrooms - B.bathrooms)*(A.bathrooms - B.bathrooms)*c
            + (A.beds - B.beds)*(A.beds - B.beds)*d
            + (A.minimumNights - B.minimumNights)*(A.minimumNights - B.minimumNights)*e
            + (A.maximumNights - B.maximumNights)*(A.maximumNights - B.maximumNights)*f
            + (A.numberOfReviews - B.numberOfReviews)*(A.numberOfReviews - B.numberOfReviews)*g;
    resultat = sqrtf(distance);
    
    return resultat;
}

void predictionDuPrix(logement tab[], float k)
{
    int o;
    float somme = 0;
    float moyenne;
    for(o= 0; o< k; o++)
    {
        somme += tab[o].price;
    }
    moyenne = somme/k;
    printf(" \n\nle prix de votre logement doit etre : %f euros \n", moyenne);
}