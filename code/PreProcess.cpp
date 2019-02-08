//
// Created by meynadier on 07/02/19.
//

#include "PreProcess.h"



/*
 * Fonction permettant l'ouverture des images à partir d'une source
 */
cv::Mat openImg(string src){
    cv::Mat img = cv::imread(src, cv::IMREAD_ANYCOLOR);
    return img;
}


/*
 * Fonction de binarisation classique à partir d'une seuille donner en argument ainsi
 * qu'une valeur maximale
 *
 */
cv::Mat thresholdAuto(const cv::Mat& srcImg){
    cv::Mat destination;
    const int maximumVal = 255;
    int seuillage = determinateThreshold(srcImg);
    cv::threshold(srcImg, destination, seuillage, maximumVal, cv::THRESH_BINARY);
    return destination;
}

/*
 * Fonction déterminant le meilleurs seuillage pour l'image
 */
int determinateThreshold(const cv::Mat& srcImg){
    cv::Mat histogram;
    int channels[] = { 0 };
    int histSize[] = { 256 };
    float range[] = { 0, 256 };
    const float* ranges[] = { range };

    calcHist(&srcImg, 1, channels, cv::Mat(), histogram, 1, histSize, ranges, true, false);

    long numberOfPixels = srcImg.rows*srcImg.cols;
    int threshold, bestThreshold=0;
    double numb=0, numf=0, sumb=0, sumf=0, bestValue=0, wb, wf, mb, mf, current;
    for(int i=0; i<histogram.rows;i++)
    {
        numf += histogram.at<uchar>(i);
        sumf += i*histogram.at<uchar>(i);
    }
    for(threshold=1; threshold<256;threshold++)
    {
        numb+=histogram.at<uchar>(threshold-1);
        numf-=histogram.at<uchar>(threshold-1);
        sumb+=(threshold-1)*histogram.at<uchar>(threshold-1);
        sumf-=(threshold-1)*histogram.at<uchar>(threshold-1);

        wb = numb/numberOfPixels;
        wf = numf/numberOfPixels;
        mb = numb != 0 ? sumb/numb : 0;
        mf = numf != 0 ? sumf/numf : 0;

        current = wb*wf*(mb-mf)*(mb-mf);

        if(current >= bestValue)
        {
            bestValue=current;
            bestThreshold=threshold;
        }


    }
    return bestThreshold;

}

/*

cv::Mat rotation(const cv::Mat& sourceImg){
    const int rows = sourceImg.rows;
    const int cols = sourceImg.cols;
    cv::Mat rotateImg;
    if(modePaysage(sourceImg)){
        return sourceImg;
    }else{
        cv::getRotationMatrix2D(cv::Point(rows/2,cols/2),90,1);
        cv::warpAffine(sourceImg,rotateImg,cv::Point(cols,rows));
        return rotateImg;
    }

}
 */


cv::Mat greyscale(const cv::Mat& sourceImg){
    cv::Mat greyImg;
    cv::cvtColor(sourceImg,greyImg,cv::COLOR_RGB2GRAY);
    return greyImg;
}

bool modePaysage(const cv::Mat& sourceImg){
    return sourceImg.rows > sourceImg.cols;
}


cv::Mat resize(const cv::Mat& sourceImg, const int& maxSize){
    cv::Mat resizeImg;
    double aspectRatio = (double)sourceImg.rows/(double)sourceImg.cols;
    int newSize;
    if(modePaysage(sourceImg)){
         newSize = (int)((double)maxSize / aspectRatio);
        cv::resize(sourceImg,resizeImg,cv::Size(maxSize, newSize));
    }else{
        newSize = (int)((double)maxSize * aspectRatio);
        cv::resize(sourceImg, resizeImg, cv::Size(newSize,maxSize));
    }
    return resizeImg;
}



