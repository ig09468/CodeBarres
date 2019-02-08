//
// Created by meynadier on 07/02/19.
//

#include "PreProcess.h"



/*
 * Fonction permettant l'ouverture des images à partir d'une source
 */
cv::Mat openImg(string& src){
    cv::Mat img = cv::imread(src, CV_);
    return img;
}


/*
 * Fonction de binarisation classique à partir d'une seuille donner en argument ainsi
 * qu'une valeur maximale
 *
 */
cv::Mat thresholdConfig(const cv::Mat& srcImg, const int& seuillage, const int& maximumVal){
    cv::Mat destination;
    cv::threshold(srcImg, destination, seuillage, maximumVal, cv::THRESH_BINARY);
    return destination;
}

cv::Mat rotation(const cv::Mat& sourceImg){
    const int rows = sourceImg.rows;
    const int cols = sourceImg.cols;
    cv::Mat rotateImg;

    cv::getRotationMatrix2D(cv::Point(rows/2,cols/2),90,1);
    cv::warpAffine(sourceImg,rotateImg,cv::Point(cols,rows));
    return rotateImg;
}


bool modePaysage(const cv::Mat& sourceImg){
    return sourceImg.rows > sourceImg.cols;
}


cv::Mat resize(const cv::Mat& sourceImg, const int& maxSize){
    cv::Mat resizeImg;
    double aspectRatio = sourceImg.rows/sourceImg.cols;
    if(modePaysage(sourceImg)){
        int newSize = (int)((double)maxSize / aspectRatio);
        cv::resize(sourceImg,resizeImg,cv::Size(maxSize, newSize));
    }else{
        int newSize = (int)((double)maxSize * aspectRatio);
        cv::resize(sourceImg, resizeImg, cv::Size(newSize,maxSize));
    }
}



