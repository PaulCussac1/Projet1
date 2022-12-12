# Prédiction du prix d'une habitation qu'un utilisateur souhaite mettre en location sur la plateforme Airbnb.

Le but du projet est de prédire le prix d’un logement que mettra en ligne un utilateur de Airbnb.
Ce prix sera calculé en faisant la moyenne arithmetique des prix des k plus proches logements.
La distance entre deux logements sera calculée par la distance euclidienne des differentes caracteristique des logements en question. 
Et l'utilisateur aura la possibilité de choisir les caracteristique de son logement qui seront comparées avec celles de logements du fichier Airbnb.csv.
Il est important de préciser que le logement de l'utilisateur sera comparé à une base de donnée de 7917 logements.

## Précisions sur les diffèrentes fonctions.
Avant de comencer à écrire les différentes fonctions qui constituent notre programme, il fallait créer un type de variable appelé logement qui comporte 10 caractéristiques, 5 entiers et 5 floats.

#### 1) distanceEntreLogements
Cette fonction prend en entrée 2 logements et 7 entiers.
Ces entiers, saisis par l'utilisateur vont prendre les valeurs 0 ou 1.
Cette fonction calcule donc la distance euclidienne entre deux logements seulement pour les carracteristiques que l'utilisateur aura choisi.

#### 2) predictionDuPrix
Cette fonction a pour but de faire la moyenne des prix des k premiers éléments d'un tableau d'éléments de type logement.
Et d'afficher ce prix (avec printf()).

#### 3) randomise
Cette fonction ordonne de facon aléatoire les éléments d'un tableau de type logement.

#### 4) triTableau
Cette fonction tri un tableau d'éléments de type logement de façon croissante en fonction de la caractéristique appellée "distanceAdaptée".

#### 5) main
Aprés avoir reccupéré et stocké les données du fichier CSV contenant toutes les informations sur les logements dans un tableau (de type logement), on demande à l'utilisateur de saisir un entier k et les carractéristique de son choix pour qu'elles soient comparées à celles des autres logements.
Aprés cela, on calcul une à une les distance entre le logements de l'utilisateur et les autres logements du fichier CSV.
Une fois les distances calculées, chaque distance est assignée au logement correspondant dans le tableau.
Le tableau de logement est ensuite randomisé et trié à l'aide des fonctions "randomise" et "triTableau".
Et on fini par appliqué la fonction predictionDuPrix à ce tableau.

## Compilation et éxécution.

Pour compiler ce projet, allez dans le terminal et tapez la commande 

```bash
  make all
```
Puis pour éxécuter, tapez
```bash
  ./prog
```
## Auteurs.

- [@PaulCussac1](https://www.github.com/PaulCussac1)
- [@Aminachib](https://www.github.com/Aminachib)

