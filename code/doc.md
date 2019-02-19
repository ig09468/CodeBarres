# Documentation

## PreProcess

Ensemble de fonctions permettants d'appliquer des transformations à une image


### cv::Mat openImg(string src)

Ouverture d'une image en couleur à partir d'un url source.
- arg : 

    
    `string src : chemin absolue vers l'image source`  
- retour :


    `Mat img : la matrice représentant l'image en RGB`
    
  
### cv::Mat greyscale(const cv::Mat& sourceImg)

Transformation d'une image en couleur vers une image en niveau de gris
- arg :


    `const cv::Mat& sourceImg : image en RGB`
- retour :


    `Mat img : image convertie en niveau de gris`
    
 
### cv::Mat thresholdAuto(const cv::Mat& sourceImg)

Binarisation détermine automatiquement par le seuillage OTSU ([Binarisation](https://sites.google.com/site/lizantchristopher/services/binarisation-1))
- arg :


`const cv::Mat& sourceImg : image en niveau de gris` 
- retour :

`Mat img : image après binarisation`
    
    
    
### cv::Mat rotation(const cv::Mat& sourceImg, int angle)

Rotation d'une image à partir d'un angle
- arg :


  `const cv::Mat& sourceImg : image de n'importe quel type`
  
  `int angle : angle de rotation en degré`

- retour :

    
    Mat img : image après transformation



### cv::Mat resize(const cv::Mat& sourceImg, const int& maxSize)


Redimension de l'image à partir d'une taille maximale en fonction de l'orientation (Portrait ou Paysage)

- arg :


    const cv::Mat& sourceImg : image de n'importe quel type
    const int& maxSize : nouvelle taille maximale

- retour


    Mat img : image redimensionnée à la taille "maxSize"
    
    
### cv::Mat rollingBall(const cv::Mat& sourceImg)


Harmonisation de l'éclairage d'une image
- arg :


    const cv::Mat& sourceImg : image en niveau de gris


- retour :


    Mat img : image dont le fond est harmonisé
    
    
###cv::Mat hough(const cv::Mat& sourceImg)
?
- arg :
    
    
    const cv::Mat& sourceImg : image en niveau de gris

- retour :


    Mat img : image de la transformée de Hough
    
    
    
####cv::Mat calculHistogram(const cv::Mat& sourceImg)



Détermine l'histogramme d'une image
- arg :


    const cv::Mat& sourceImg : 
- retour :


    Mat img :




####cv::Mat generateKernel(int radius)



Génère le noyau d'un filtre à partir de son rayon
- arg :


    int radius : Rayon du filtre
- retour :
    
    
    Mat kernel : Noyau du filtre