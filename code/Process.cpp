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
vector<int> compareValue(vector<vector<int>> lines){

    vector<vector<int>> result= {{-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1,-1,-1,-1}
    };
    vector<int> finalResult;
    for(vector<int> line : lines){
        for(int number = 0; number < line.size();number++){
            if(line[number] > -1){
                result[number][line[number]]++;
            }
        }
    }

    for(vector<int> cols : result){
        int max=0;
        int max_number=-1;
        for(int number = 0 ; number < cols.size();number++){
            if(cols[number] > max){
                max=cols[number];
                max_number=number;
            }
        }
        finalResult.push_back(max_number);
    }
    return finalResult;
}


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
        img_block.push_back(openImg(src+to_string(nombre_image)+".jpg"));
    }
    for(cv::Mat img : img_block){
        cv::Mat grey =  greyscale(img);
        cv::Mat mat_gradient = gradient(grey);

        for(int seuil = 25; seuil <= 125; seuil+=25){
            cv::Mat binary_blur = binaryBlur(mat_gradient,100+seuil);
            cv::Mat close = closeTraitement(binary_blur);
            vector<vector<cv::Point>> contours = detectContours(close);
            vector<cv::Rect> rois;
            for(int i = 0 ; i < contours.size() ; i++){
                const vector<cv::Point> extremum = extremPoint(contours[i]);
                rois.push_back(cv::Rect(extremum[0],extremum[1]));
            }
            vector<cv::Mat> rois_mat;
            cv::Mat roi;
            for(int region = 0 ; region < rois.size() ; region++) {
                cv::Mat roi_binary;
                img(rois[region]).copyTo(roi);
                roi_binary=thresholdAuto(roi);
                vector<cv::Vec4i> roi_lines = hough(roi_binary,150);

                cv::Mat dst,copy;
                cv::Canny(roi_binary,dst,50,200,3);
                cv::cvtColor(dst,copy,cv::COLOR_GRAY2BGR);

                for(size_t i = 0 ; i < roi_lines.size(); i++ ){
                    float rho = roi_lines[i][0], theta = roi_lines[i][1];
                    cv::Point pt1, pt2;
                    double a = cos(theta), b=sin(theta), x0 = a*rho, y0 = b*rho;

                    pt1.x=cvRound(x0+1000*(-b));
                    pt1.y=cvRound(x0+1000*(a));
                    pt1.x=cvRound(y0-1000*(-b));
                    pt1.y=cvRound(y0-1000*(a));
                    cv::line(copy, pt1,pt2,cv::Scalar(0,0,255),3,cv::LINE_AA);
                }

                cv::imwrite("/home/meynadier/ProjectImg/img/result/hough/test"+to_string(enregistrement++)+".png",copy,param_compression);
                //const int angle = 180-(180-(90+roi_lines[0][1]));
                cv::imwrite(save+"/roi/roi"+std::to_string(enregistrement)+".png",roi,param_compression);
                vector<vector<int>> result_roi;
                for(int rows = 0 ; rows < roi.rows;rows++){
                    result_roi.push_back(readingEAN(roi_binary,rows));
                }
                vector<int> resultFinal = compareValue(result_roi);
                std::cout << endl << "---- Résultat ----" << endl;
                std::cout << "Valeurs :";
                for(int number = 0 ; number < resultFinal.size();number++){
                    std::cout << "  " << resultFinal[number];
                }

            }
        }
        std::cout << endl << "######################################################" << endl;
        std::cout << endl << "######################################################" << endl;
        std::cout << endl << "######################################################" << endl;

    }

}