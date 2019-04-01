//
// Created by meynadier on 18/02/19.
//

#include "Process.h"

/*
 * Fonction permettant de calculer un vecteur de valeurs correspondant aux
 */

bool isBlack(const int& value){
    return value < 255;
}

/*
 * Fonction permettant de trouver le début de lecture du code-barres
 * barCode : image centrée sur le code-barres
 */
int searchFirstDelimiter(const cv::Mat &barCode, const int &row){
    for(int cols = 0 ; cols < barCode.cols ; cols++) {
        const int pixel = barCode.at<uchar>(row, cols);
        if (isBlack(pixel))
            return cols;
    }
}

int searchStartBarCode(const cv::Mat &barCode, const int& row){
    int start = searchFirstDelimiter(barCode, row);
    int colsRoam = 0;
    bool colorColumnIsBlack = true;
    for(int  cols = start ; cols < barCode.cols/2 ; cols++){
        const int pixel = barCode.at<uchar>(row,cols);
        if(colsRoam == 3){
            return cols;
        }else{
            if(isBlack(pixel) != colorColumnIsBlack){
                colsRoam++;
            }
        }
    }
    return 0;
}
/*
 * Fonction permettant de trouver le ratio de grandeur de la barre de référence du code-barres, c'est à dire le premier délimiteur.
 * barCode : image centrée sur le code-barres
 */

double searchRatio(const cv::Mat& barCode, const int& row){
    int numberPixels=0;
    for(int cols = searchFirstDelimiter(barCode, row) ; cols < barCode.cols ; cols++) {
        const int pixel = barCode.at<uchar>(row, cols);
        if (isBlack(pixel)){
            numberPixels++;
        }else{
            break;
        }
    }
    return 1.0/numberPixels;
}

/*
 * Fonction permettant le tableau contenant les valeurs en binaire d'une barre
 * convert : vecteur des valeurs binaires d'une barre
 */
vector<int> convertByteToEAN(const vector<int>& bar){
    int result=0;
    vector<int> barCode;
    for(int nextvalue = 0 ; nextvalue < bar.size() ; nextvalue+=4){
        if(bar[nextvalue] == -1){
            nextvalue++;
            continue;
        }
        result=bar[nextvalue]*1000+bar[nextvalue+1]*100+bar[nextvalue+2]*10+bar[nextvalue+3];
        switch (result){
            case ean::ZERO:
            case ean::ZEROB:
                barCode.push_back(0);
                break;
            case ean::UN:
            case ean::UNB:
                barCode.push_back(1);
                break;
            case ean::DEUX:
            case ean::DEUXB:
                barCode.push_back(2);
                break;
            case ean::TROIS:
            case ean::TROISB:
                barCode.push_back(3);
                break;
            case ean::QUATRE:
            case ean::QUATREB:
                barCode.push_back(4);
                break;
            case ean::CINQ:
            case ean::CINQB:
                barCode.push_back(5);
                break;
            case ean::SIX:
            case ean::SIXB:
                barCode.push_back(6);
                break;
            case ean::SEPT:
            case ean::SEPTB:
                barCode.push_back(7);
                break;
            case ean::HUIT:
            case ean::HUITB:
                barCode.push_back(8);
                break;
            case ean::NEUF:
            case ean::NEUFB:
                barCode.push_back(9);
                break;
            default:
                barCode.push_back(-1);
                break;
        }
    }
    return barCode;
}

/*
 * TODO Terminer la fonction de lecture pour qu'elle puisse prendre en compte le délimiteur central
 */
vector<int> readingEAN(const cv::Mat& barCode, const int& row){

    vector<int> convert;
    //Taille de la colonne actuellement visitée
    double colSize = 0;

    double tailleBar;

    //Boolean vérifiant la couleur actuelle de la barre en cours
    bool colorColumnIsBlack = true;

    //Ratio par rapport à la taille des barres
    double ratio = searchRatio(barCode, row);



    for(int cols = searchStartBarCode(barCode,row) ; cols <  barCode.cols; cols++){
        const int pixel = barCode.at<uchar>(row, cols);
        if(convert.size() == 53){
            break;
        }
        if(convert.size() > 24 && convert.size() < 30){
            convert.push_back(-1);
            colorColumnIsBlack = true;
        }
        if(isBlack(pixel) != colorColumnIsBlack){
            tailleBar = (colSize*ratio);
            if((tailleBar-(int)tailleBar) > 0.5){
                convert.push_back(((int)(colSize*ratio)+1));
            } else{
                convert.push_back(((int)(colSize*ratio)));
            }
            colSize=1;
            colorColumnIsBlack=isBlack(pixel);
        } else{
            colSize++;
        }

    }
    std::cout << "Valeur du vecteur trouvé avant convert : ";
    for(int value : convert){
        std::cout << value << ",";
    }
    return convertByteToEAN(convert);
}