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

int searchStartBarCode(const cv::Mat &barCode, const int& row, const int& start, const double& ratio){
    int colsRoam = 1;
    int taille = (((1.0/ratio))-(int)(1.0/ratio)) > 0.5 ? ((int)(1.0/ratio))+1 : (int)(1.0/ratio);
    bool colorColumnIsBlack = true;
    for(int  cols = start ; cols < barCode.cols/2 ; cols+=taille){
        const int pixel = barCode.at<uchar>(row,cols);
        if(colsRoam == 3){
            return cols;
        }else{
            if(isBlack(pixel) != colorColumnIsBlack){
                colsRoam++;
                colorColumnIsBlack=isBlack(pixel);
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
 * Fonction permettant la lecture d'un code-barre horizontal
 * barCode : image centrée sur le code-barres
 * row : ligne de lecture du code-barres
 */
vector<int> readingEAN(const cv::Mat& barCode, const int& row){

    vector<int> convert;
    //Taille de la colonne actuellement visitée
    double colSize = 1;

    double tailleBar=0;

    //Boolean vérifiant la couleur actuelle de la barre en cours
    bool colorColumnIsBlack = false;

    //Ratio par rapport à la taille des barres

    double ratio = searchRatio(barCode, row);
    std::cout << "Ratio : " << ratio << endl;



    for(int cols = searchStartBarCode(barCode,row, searchFirstDelimiter(barCode, row),ratio) ; cols <  barCode.cols; cols++){
        const int pixel = barCode.at<uchar>(row, cols);

        if(convert.size() == 53){
            break;
        }
        if(isBlack(pixel) != colorColumnIsBlack){
            if(convert.size() > 23 && convert.size() < 29){
                convert.push_back(-1);
                colSize=1;
                colorColumnIsBlack=isBlack(pixel);
                continue;
            }
            tailleBar = colSize*ratio;
            if((tailleBar-(int)tailleBar) > 0.5){
                convert.push_back((int)(tailleBar+1));
            } else{
                convert.push_back((int)(tailleBar));
            }
            colSize=1;
            colorColumnIsBlack=isBlack(pixel);
        } else{
            colSize++;
        }

    }
    return convertByteToEAN(convert);
}



/*
 * Fonction permettant de comparer 2 vecteurs d'entier pour retourner le nombre de chiffre identique
 *
 */
int compareVector(vector<int> &vector1,vector<int> &vector2 ){
    int result=0;
    for(int value = 0; value<vector1.size();value++){
        if(vector1[value]==vector2[value] && (vector2[value]!=-1 || vector1[value]!=-1))
            result++;
    }
    return result;
}


/*
 * Fonction permettant de comparer les lectures d'une image
 */



/*
 * Fonction lançant les processus pour déterminer si un code barres est présent où non dans l'ensemble d'images donné
 * src : lien où se trouvent les images
 * save : lien pour sauvegarder les images résultats
 * dim : taille de redimension des images traitées
 */
void start(string src, string save, int dim){

    int enregistrement = 1;
    vector<int> param_compression;
    param_compression.push_back(cv::IMWRITE_PNG_COMPRESSION);
    param_compression.push_back(9);

    vector<cv::Mat> img_block;
    for(int nombre_image=1;nombre_image<17;nombre_image++){
        string src_copy=src;
        img_block.push_back(openImg(src_copy+=std::to_string(nombre_image)+".jpg"));
    }


    for(cv::Mat img : img_block){
        cv::Mat img_copy;
        img = resize(img,dim);
        img.copyTo(img_copy);


        img_copy = greyscale(img_copy);
        img_copy = gradient(img_copy);

        for(int seuil = 25; seuil <= 125; seuil+=25){
            img_copy = binaryBlur(img_copy,100+seuil);
            cv::imwrite(save+"blur"+std::to_string(enregistrement)+".png",img_copy,param_compression);
            img_copy = closeTraitement(img_copy);
            cv::imwrite(save+"fermeture"+std::to_string(enregistrement)+".png",img_copy,param_compression);
            vector<vector<cv::Point>> contours = detectContours(img_copy);
            vector<cv::Rect> rois;
            for(int i = 0 ; i < contours.size() ; i++){
                const vector<cv::Point> extremum = extremPoint(contours[i]);
                rois.push_back(cv::Rect(extremum[0],extremum[1]));
            }

            vector<cv::Mat> rois_mat;
            cv::Mat roi;
            for(int region = 0 ; region < rois.size() ; region++) {
                img(rois[region]).copyTo(roi);
                cv::Mat roi_binary=thresholdAuto(roi);
                vector<cv::Vec4i> roi_hough = hough(roi_binary,20);
                if(roi_hough.size()>40){
                    const int angle = 180-(180-(90+roi_hough[0][2]));
                    roi_binary=rotation(roi, angle);
                    break;
                }
            }
            vector<vector<int>> result_roi;
            for(int rows = 0 ; rows < roi.rows;rows++){
                result_roi.push_back(readingEAN(roi,rows));
            }
            for(vector<int> vecteur : result_roi){
                cout << "result  : ";
                for(int affiche = 0 ; affiche< vecteur.size(); affiche++){
                    cout << vecteur[affiche] << " ";
                }
                cout << endl;
            }
        }

    }

}