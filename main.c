#include "distance.h"
#include "operationTab.h"


int main(int argc, char* argv[])
{

    //On commence par ouvrir le fichier 
    FILE *fichier = fopen("AirBnbDonnes.csv","r");
    logement TabLogement[TAILLEMAX];
    srand(time(NULL)); // initialisation de la seed
    int l;
    int i;
    int m;
    char premiereLigne[255];
    if(fichier != NULL)
    {
        fgets(premiereLigne, 255, fichier); //on enleve la premiere ligne du tableau 
        for(l=0;l < TAILLEMAX; l++) //on remplie le tableau TabLogement (d'elements de type logement) avec les valeurs du fichier.csv
        {
            fscanf(fichier, "%d,%d,%f,%f,%f,%f,%d,%d,%d " , &TabLogement[l].numeroLogement,
                                                        &TabLogement[l].accomodates, 
                                                        &TabLogement[l].bedrooms,
                                                        &TabLogement[l].bathrooms,
                                                        &TabLogement[l].beds,
                                                        &TabLogement[l].price,
                                                        &TabLogement[l].minimumNights,
                                                        &TabLogement[l].maximumNights,
                                                        &TabLogement[l].numberOfReviews);
            TabLogement[l].distanceAdaptee = 0; //on initialise toutes les distances a 0    
        }
    }
    else
    {
        printf("impossible d'ouvrir le fichier"); //message d'erreur si l'ouverture ne se fait pas
    }

    // on demane a l'utilisateur de saisir les carracteristiques du logement et un entier k (nombre de logements auquel son logements sera compare). 
    int k;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    logement A;
    printf("\nDéfinissez les carrarcteristiques que vous voulez prendre en compte pour calculer le prix de votre logement.\n" );
    printf("Pour cela, vous repondrez par oui (en tapant 1) ou pas non (en tapant 0) aux questions suivantes :\n");

    printf("\nVoulez vous prendre en compte le nombre de personne pouvant acceuillir votre logement ?\n" );
    scanf("%d",&a);
    if (a == 1)
    {
        printf("Saisissez le nombre de personnes pouvant acceuilir votre logement :\n" );
        scanf("%d",&A.accomodates);
    }
    if (a != 0 && a !=1)
    {
        printf("vous n'avez pas respecté la seconde consigne de départ, veuillez réesayer.\n");
        exit(0);
    }

    printf("Voulez vous prendre en compte le nombre de chambres ? \n" );
    scanf("%d",&b);

    if (b == 1)
    {
        printf("Saisissez le nombre de chambres :\n" );
        scanf("%f",&A.bedrooms);
    }
    if (b != 0 && b !=1)
    {
        printf("vous n'avez pas respecté la seconde consigne de départ, veuillez réesayer.\n");
        exit(0);
    }

    printf("Voulez vous prendre en compte le nombre de salles de bains? \n" );
    scanf("%d",&c);

    if (c == 1)
    {
        printf("Saisissez le nombre de salles de bains de votre logement :\n" );
        scanf("%f",&A.bathrooms);
    }
    if (c != 0 && c !=1)
    {
        printf("vous n'avez pas respecté la seconde consigne de départ, veuillez réesayer.\n");
        exit(0);
    }
    
    printf("Voulez vous prendre en compte le nombre total de lit ? \n" );
    scanf("%d",&d);
    if (d == 1)
    {
        printf("Saisissez le nombre total de lit dans votre logement :\n" );
        scanf("%f",&A.beds);
    }
    if (d != 0 && d !=1)
    {
        printf("vous n'avez pas respecté la seconde consigne de départ, veuillez réesayer.\n");
        exit(0);
    }

    printf("Voulez vous prendre en compte le minimun de nuits necessaire pour une reservation ?  \n" );
    scanf("%d",&e);

    if (e == 1)
    {
        printf("Saisissez le minimun de nuits necessaire pour reserver votre logement :\n" );
        scanf("%d",&A.minimumNights);
    }
     if (e != 0 && e !=1)
    {
        printf("vous n'avez pas respecté la seconde consigne de départ, veuillez réesayer.\n");
        exit(0);
    }


    printf("Voulez vous prendre en compte le maximum de nuits necessaire pour une reservation ? \n" );
    scanf("%d",&f);

    if (f == 1)
    {
        printf("Saisissez le maximum de nuits necessaire pour reserver votre logement :\n" );
        scanf("%d",&A.maximumNights);
    }
    if (f != 0 && f !=1)
    {
        printf("vous n'avez pas respecté la seconde consigne de départ, veuillez réesayer.\n");
        exit(0);
    }

    printf("Voulez vous prendre en compte le nombre de visite des annonce ? \n" );
    scanf("%d",&g);

    if (g == 1)
    {
        printf("Saisissez le nombre de personne ayant vu votre annonce:\n" );
        scanf("%d",&A.numberOfReviews);
    }
     if (g != 0 && g !=1)
    {
        printf("vous n'avez pas respecté la seconde consigne de départ, veuillez réesayer.\n");
        exit(0);
    }


    printf("Choisissez un entier k correspondant au nombre de logements auquels votre logement sera compare :\n" );
    scanf("%d",&k);

    //assigne les distances entre le logement A de l'utilisateuret le logement en question pour tous les logements.
    for(i=0; i<TAILLEMAX;i++)
    {  
        TabLogement[i].distanceAdaptee = distanceEntreLogements(A, TabLogement[i],a,b,c,d,e,f,g);
    }
        
    randomise(TabLogement, TAILLEMAX);
    triTableau(TabLogement, TAILLEMAX);
    predictionDuPrix(TabLogement,k); // determine le prix final du logement.
    return 0;
}