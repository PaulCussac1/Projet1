#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAILLEMAX 7917 //7917 est le nombre total de logements dans le fichier Airbnb.csv

//on definit le type logement avec les differentes carracteristiques
typedef struct logement logement; 
struct logement
{
    int numeroLogement;
    int accomodates;
    float bedrooms;
    float bathrooms;
    float beds;
    float price;
    int minimumNights;
    int maximumNights;
    int numberOfReviews;
    float distanceAdaptee; //cette variable est la distances entre les carracteristiques selectionees par l'utilisateur
};


float distanceEntreLogements(logement A, logement B,int a, int b, int c, int d, int e, int f, int g);
void predictionDuPrix(logement tab[], float k);