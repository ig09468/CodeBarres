# CodeBarres

## Résumé

Projet de reconnaissance des codes-barres dans le cadre de l'UE Traitement de l'image à Paris Descartes.
Le but du projet est de savoir lire un code-barres ainsi que détecter la zone où se situe le code-barres.

>Le premier objectif est de reconnaitre chacun des caractères dissimuler dans le code.
Type d'images : Présence unique du code-barres


>Le second objectif est de trouver un code-barres dans une image quelconque d'un produit vendu en super-marchée.
Type d'images : Présence d'un code-barres dans l'image

## Technologies

1. [Langage C++](https://devdocs.io/cpp/)
2. [Librairie OpenCV](https://docs.opencv.org/4.0.1/)

## Objectifs

### Type 1
- Type d'image 
>Image d'un simple code-barres orienté sur fond **blanc**
- Qualité de l'image
> Propre sans défaut, code-barres parfait

### Type 2
- Type d'images
> Photo d'un simple code-barres orientée dans n'importe quelle direction sur un produit plat
- Qualité de l'image
> Mauvais éclairage


### Type 3
- Type d'images
> Photo d'un simple code-barres orienté dans n'importe quelle direction sur un produit incurvé
- Qualité de l'image
> Mauvais éclairage


### Type 4
- Type d'images
> Photo contenant deux codes-barres dans l'image
- Qualité de l'image
>Propre éclairage normal et mauvais éclairage

### Type 5
- Type d'images
>Photo ne contenant aucun code-barres
 

## Techniques

1. Filtre de Sobel
2. Filtre Moyenneur
3. Binarisation (filtre variant)
4. Fermture
5. Transformée de Hough
6. Binarisation locale OSTU

## Sources

### Web

1. Pré-traitements:
- [Egalisation d'un histogramme](https://docs.opencv.org/2.4/doc/tutorials/imgproc/histograms/histogram_equalization/histogram_equalization.html)
- [Binarisation](https://sites.google.com/site/lizantchristopher/services/binarisation-1)
- [Rolling Ball](https://www.researchgate.net/publication/319985119_New_method_of_automated_statistical_analysis_of_polymer-stabilized_metal_nanoparticles_in_electron_microscopy_images?fbclid=IwAR19denWsMt2ku8asMTI8tl5yu2kpgI7JIgNsm5QD5_fOuUWfR5L21qJuq0) 
- Rotation : [Image Search](https://www.pyimagesearch.com/2017/01/02/rotate-images-correctly-with-opencv-and-python/) - [OpenCV Tuto C++](https://www.opencv-srf.com/2010/09/rotating-images.html) - [Geometric Transformations of Image](https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html)
- [Transformée de Hough](https://docs.opencv.org/3.4.0/d9/db0/tutorial_hough_lines.html)
2. Nomenclature Code-Barres:
- [EAN](https://fr.wikipedia.org/wiki/Code-barres_EAN)

### Livres

- Traitement de l'image et de la vidéo, Rachid Belaroussi (2010)
- Introduction au traitement d'images, Diane Lingrand (2004)
- Introduction au traitement mathématique des images - méthodes déterministes, Maïtine Bergounioux (2015)
