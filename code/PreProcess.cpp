//
// Created by meynadier on 07/02/19.
//

#include "PreProcess.h"



/*
 * Fonction permettant l'ouverture des images à partir d'une source
 *
 * src : lien direct vers l'image
 */
cv::Mat openImg(string src){
    cv::Mat img = cv::imread(src, cv::IMREAD_ANYCOLOR);
    if(img.empty()){
        std::cerr << "Erreur d'ouverture de l'image" << endl;
    }
    return img;
}


/*
 * Fonction de binarisation classique à partir d'une seuille donner en argument ainsi
 * qu'une valeur maximale
 *
 */
cv::Mat thresholdAuto(const cv::Mat& sourceImg){
    cv::Mat destination;
    const int maximumVal = 255;
    int seuillage = determinateThreshold(sourceImg);
    cv::threshold(sourceImg, destination, seuillage, maximumVal, cv::THRESH_BINARY);
    //cv::adaptiveThreshold(sourceImg,destination,255,cv::ADAPTIVE_THRESH_GAUSSIAN_C,cv::THRESH_BINARY,11,2);
    return destination;
}



/*
 * Fonction déterminant le meilleurs seuillage pour l'image.
 * Elle se base sur la moyenne inter-classe de l'histogramme de l'image.
 *
 * srcImg : l'image que l'on souhaite binariser
 */
int determinateThreshold(const cv::Mat& sourceImg){
    cv::Mat histogram = calculHistogram(sourceImg);
    long numberOfPixels = sourceImg.rows*sourceImg.cols;
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





cv::Mat rotation(const cv::Mat& sourceImg, int angle){

    const int rows = sourceImg.rows;
    const int cols = sourceImg.cols;

    cv::Mat rotateImg;
    cv::Mat matRotation = cv::getRotationMatrix2D(cv::Point(rows/2,cols/2),angle,1);
    cv::warpAffine(sourceImg,rotateImg,matRotation,sourceImg.size());

    return rotateImg;
}

/*
 * Fonction permettant de transformer une image en couleur vers une image en niveau de gris
 * sourceImg : l'image que l'on souhaite transformer
 */
cv::Mat greyscale(const cv::Mat& sourceImg){
    cv::Mat greyImg;
    cv::cvtColor(sourceImg,greyImg,cv::COLOR_RGB2GRAY);
    return greyImg;
}


/*
 * Fonction permettant de déterminer, le type d'orientation de l'image (Paysage ou Portrait)
 * sourceImg : l'image dont on souhaite déterminer l'orientation
 */
bool modePaysage(const cv::Mat& sourceImg){
    return sourceImg.rows > sourceImg.cols;
}

/*
 * Fonction pour modifier la taille d'une image en fonction d'une valeur maximal donner.
 * Calcul la nouvelle dimension en fonction de l'ancienne taille de l'image.
 * sourceImg : l'image que l'on souhaite modifier
 * maxSize : la taille maximal en fonction de la position de l'image (Portrait ou Paysage)
 *
 */
cv::Mat resize(const cv::Mat& sourceImg, const int& maxSize){
    cv::Mat resizeImg;
    double aspectRatio = sourceImg.rows/sourceImg.cols;
    int newSize;
    if(modePaysage(sourceImg)){
         newSize = maxSize / aspectRatio;
        cv::resize(sourceImg,resizeImg,cv::Size(maxSize, newSize));
    }else{
        newSize = (maxSize * aspectRatio);
        cv::resize(sourceImg, resizeImg, cv::Size(newSize,maxSize));
    }
    return resizeImg;
}


cv::Mat calculHistogram(const cv::Mat& sourceImg){
    cv::Mat histogram, eqHist;
    int channels[] = { 0 };
    int histSize[] = { 256 };
    float range[] = { 0, 256 };
    const float* ranges[] = { range };
    cv::calcHist(&sourceImg, 1, channels, cv::Mat(), histogram, 1, histSize, ranges, true, false);

    //cv::equalizeHist(histogram,eqHist);

    return histogram;
}


/*
 * Fonction permettant de calculer la transformer de Hough
 * sourceImg : Image source dont on veut calculer la transformer
 * TODO Appliquer la méthode de la transformer de Hough et retourner une image de cette transformer
 */
cv::Mat hough(const cv::Mat& sourceImg){

    cv::Mat dst, cdst;
    Canny(sourceImg, dst, 50, 200, 3);
    cvtColor(dst, cdst, cv::COLOR_GRAY2BGR);

    vector<cv::Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI/90, 100, 100, 2 );
    for( size_t i = 0; i < lines.size(); i++ )
    {
        cv::Vec4i l = lines[i];
        line( cdst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0,0,255), 3);
    }
    imshow("source", sourceImg);
    imshow("detected lines", cdst);
    return cdst;
}


/*
 * calculate the background of an image using rolling ball algorithm
 * @param : radius, size of the ball to apply
 * returns : background of the image
 */
cv::Mat getBackground(const cv::Mat& sourceImg, int radius) {

	int rows = sourceImg.cols, cols = sourceImg.rows;
	cv::Mat background = cv::Mat::zeros(sourceImg.size(), sourceImg.type());
	cv::Rect kernel;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			kernel = cv::Rect(cv::Point(max(0, row - radius/2), max(0, col - radius / 2)), cv::Point(min( rows, row + radius / 2), min(cols, col + radius)));
			string name = col + ", " + row;
			int result = cv::sum(sourceImg(kernel))[0];
			result /= kernel.area();
			background.at<uchar>(col, row) = result;
		}
	}
	cv::imshow("background", background);
	cv::waitKey(0);
    return background;
}

cv::Mat rollingBall(const cv::Mat& sourceImg, const int& radius) {
	cv::Mat background = getBackground(sourceImg, radius);

	cv::Mat result = sourceImg + background;
    cv::imshow("Result", result);
    cv::waitKey(0);
	return result;
}

/*
 * Fonction permettant de réctifier les valeurs optimales qui sont au delà de 255 et inférieur à 0
 * sourceImg : Imagesource auquel on veut appliquer la modification
 * TODO Vérifier que dans la matrice les valeurs sont bien comprises entre 255 et 0
 */

cv::Mat rectifValue(cv::Mat sourceImg){
    return sourceImg;
}