# CodeBarres

## Résumé

Projet de reconnaissance des codes-barres dans le cadre de l'UE Traitement de l'image à Paris Descartes.
Le but du projet est de savoir lire un code-barres ainsi que détecter la zone où se situe le code-barres.

>Le premier objectif est de reconnaitre chacun des caractères dissimuler dans le code.
Type d'images : Présence unique du code-barres
>Le second objectif est de trouver un code-barres dans une image quelconque d'un produit vendu en super-marchée.
Type d'images : Présence d'un code-barres dans l'image

## Technologies

1. Langage C++ : https://devdocs.io/cpp/
2. Librairie OpenCV : https://docs.opencv.org/4.0.1/

## Objectifs

### Etape 1
1. Paramètres
- Type d'image > Image d'un simple code-barres orienté dans n'importe qu'elle direction
2. Techniques
- Application d'une transformée de Hough pour obtenir les lignes
- Application d'une rotation de l'image pour obtenir des lignes verticales ou horizontales
- Calcul du ratio de redimension de l'image par rapport à la bar minimal du code-barres
- Application du ratio à la redimension de l'image en fonction de l'orientation de l'image (Paysage ou Portrait)
- Récupération d'une portion du code-barres pour accélérer la lecture
- Lecture du code-barres en fonction de la nomenclature EAN

## Sources

### Web

1. Pré-traitements:
- https://sites.google.com/site/lizantchristopher/services/binarisation-1
- https://www.researchgate.net/publication/319985119_New_method_of_automated_statistical_analysis_of_polymer-stabilized_metal_nanoparticles_in_electron_microscopy_images?fbclid=IwAR19denWsMt2ku8asMTI8tl5yu2kpgI7JIgNsm5QD5_fOuUWfR5L21qJuq0
- https://www.pyimagesearch.com/2017/01/02/rotate-images-correctly-with-opencv-and-python/

2. Nomenclature Code-Barres:
- https://fr.wikipedia.org/wiki/Code-barres_EAN

### Livres

- Traitement de l'image et de la vidéo, Rachid Belaroussi (2010)
- Introduction au traitement d'images, Diane Lingrand (2004)
- Introduction au traitement mathématique des images - méthodes déterministes, Maïtine Bergounioux (2015)
