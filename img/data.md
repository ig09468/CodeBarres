# Descriptif

Notre ensemble de test est constitué des différentes images fournis par les différents groupes participants à l'UE - Traitement d'images
Nous avons pris le temps de les classés en différentes catégories de difficultés.

## DATA
Chacune des images sont accompagnées d'un fichier .data portant le même nom que son image associée.
Exemple du contenu du fichier :
```c
#
094856530001 //Contenu du code-barres
311 305 635 617 //Coordonnées du cadre extérieur du code-barres (cadre horizontal)
321 311 625 612 //Coordonnées du code-barres    (cadre horizonral)
#
```
 

### Etape 1
- Type d'image 
>Image d'un simple code-barres orienté sur fond **blanc**
- Qualité de l'image
> Propre sans défaut, code-barres parfait

### Etape 2
- Type d'images
> Photo d'un simple code-barres orientée dans n'importe quelle direction sur un produit plat
- Qualité de l'image
> Mauvais éclairage


### Etape 3
- Type d'images
> Photo d'un simple code-barres orienté dans n'importe quelle direction sur un produit incurvé
- Qualité de l'image
> Mauvais éclairage


### Etape 4
- Type d'images
> Photo contenant deux codes-barres dans l'image
- Qualité de l'image
>Propre éclairage normal et mauvais éclairage

### Sans
- Type d'images
>Photo ne contenant aucun code-barres
