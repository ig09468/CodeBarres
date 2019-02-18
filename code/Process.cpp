//
// Created by meynadier on 18/02/19.
//

#include "Process.h"

/*
 * Fonction permettant de calculer un vecteur de valeurs correspondant aux
 */

bool isBlack(const int& value){
    return value > 0;
}

/*
 * Fonction permettant de trouver le début de lecture du code-barres
 * barCode : image centrée sur le code-barres
 */
int searchStart(const cv::Mat& barCode){
    for(int cols = 0 ; cols < barCode.cols ; cols++) {
        const int pixel = barCode.at<uchar>(cols);
        if (!isBlack(pixel)) {
            continue;
        }
        return cols+3;
    }
}

/*
 * TODO TERMINER LE CONVERTEUR DE BYTE VERS LA NOMMENCLATURE EAN
 */
int convertByteToEAN(const vector<int>& convert){
    int result=0;
    for( int value = 0; value < convert.size() ; value++){
        result+=convert.at(value)*(pow(10,convert.size()-value));
    }
    switch (result){
        case ean::ZERO:
        case ean::ZEROB:
            return 0;
        case ean::UN:
        case ean::UNB:
            return 1;
        case ean::DEUX:
        case ean::DEUXB:
            return 2;
        case ean::TROIS:
        case ean::TROISB:
            return 3;
        case ean::QUATRE:
        case ean::QUATREB:
            return 4;
        case ean::CINQ:
        case ean::CINQB:
            return 5;
        case ean::SIX:
        case ean::SIXB:
            return 6;
        case ean::SEPT:
        case ean::SEPTB:
            return 7;
        case ean::HUIT:
        case ean::HUITB:
            return 8;
        case ean::NEUF:
        case ean::NEUFB:
            return 9;
        default:
            cout << "Erreur de byte" << endl;
            return -1;
    }


}



/*
 * TODO Terminer la fonction de lecture pour qu'elle puisse prendre en compte le délimiteur central
 */
vector<int> readingEAN(const cv::Mat& barCode, const int& number){
    vector<int> convert;
    vector<int> valueBarCode;

    int start = searchStart(barCode);
    int stop = start+(number*14)+3;
    int skip = start+(number*7);
    int previous = barCode.at<uchar>(start);
    int value = 0;

    for(int cols = start ; cols < stop ; cols++){
        const int pixel = barCode.at<uchar>(cols);
        if(previous == pixel){
            value++;
        } else{
            convert.push_back(value);
            value=0;
        }
        if(cols%7-start){
            valueBarCode.push_back(convertByteToEAN(convert));
        }
        if(cols > skip && cols <= skip+3){
            continue;
        }
    }
    return valueBarCode;
}