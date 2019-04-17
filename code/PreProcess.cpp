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
    double aspectRatio = (double)sourceImg.rows/sourceImg.cols;
    double newSize;
    if(modePaysage(sourceImg)){
        newSize = maxSize / aspectRatio;
        cv::resize(sourceImg,resizeImg,cv::Size(maxSize, newSize));
    }else{
        newSize = ((double)maxSize * aspectRatio);
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
cv::Mat hough(const cv::Mat& sourceImg, const int thresh){

    cv::Mat dst, cdst;
    Canny(sourceImg, dst, 50, 200, 3);
    cvtColor(dst, cdst, cv::COLOR_GRAY2BGR);

    vector<cv::Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI/180, thresh, thresh, 4);
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
 * Fonction permettant de trouver le convexe hull des objets présents dans l'image
 * sourceImg : Image source dont on veut calculer la transformer
 */


cv::Mat convexeHull(const cv::Mat& sourceImage){

    cv::Mat gray = greyscale(sourceImage);
    cv::Mat canny_output;
    Canny(gray,canny_output, 50, 200, 3);
    vector<vector<cv::Point> > contours;
    findContours( canny_output, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE );
    vector<vector<cv::Point> >hull( contours.size() );
    for( size_t i = 0; i < contours.size(); i++ )
    {
        convexHull( contours[i], hull[i] );
    }
    cv::Mat drawing = cv::Mat::zeros( canny_output.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ )
    {
        cv::Scalar color = cv::Scalar(cv::theRNG().uniform(0,256),cv::theRNG().uniform(0,256),cv::theRNG().uniform(0,256));
        drawContours( drawing, contours, (int)i, color );
        drawContours( drawing, hull, (int)i, color );
    }

    return drawing;
}

cv::Mat gradient(const cv::Mat& gray){
    int ddepth = CV_16S;
    cv::Mat gradient;

    cv::Mat gradientX, abs_gradientX;
    //Calcul des gradients X
    cv::Sobel(gray,gradientX,ddepth,1,0,3,cv::BORDER_DEFAULT);
    cv::convertScaleAbs(gradientX,abs_gradientX);

    cv::Mat gradientY, abs_gradientY;
    //Calcul des gradients Y
    cv::Sobel(gray,gradientY,ddepth,0,1,3,cv::BORDER_DEFAULT);
    cv::convertScaleAbs(gradientY,abs_gradientY);

    cv::Mat abs_gradient;

    cv::subtract(abs_gradientX,abs_gradientY,abs_gradient);
    cv::convertScaleAbs(abs_gradient,gradient);

    cv::addWeighted(abs_gradientX,1,abs_gradientY,1,0,gradient);

    return gradient;
}

/*
 * Fonction de floutage permettant d'élargir les barres du code barres pour obtenir un seul bloque
 * gray : image en niveau de gris
 */
cv::Mat binaryBlur(const cv::Mat& gray){
    cv::Mat blur,binary_blur;

    cv::blur(gray,blur,cv::Size(9,9),cv::Point(-1,-1),cv::BORDER_DEFAULT);

    //TODO : Tester plusieurs tresholds et compter les composantes
    // into +> appliquer hough == test de detection (Trouver 100 - 125 - 150 - 175 - 200 )
    cv::threshold(blur,binary_blur,200,255,cv::THRESH_BINARY);
    cv::imshow("Binary Blur", binary_blur);

    return binary_blur;
}


/*
 * Fonction executant plusieurs Fermetures successives pour faire disparaitre les éléments n'étant pas des codes-barres
 * binary_blur : image binaire après traitement de floutage
 */
cv::Mat closeTraitement(const cv::Mat &binary_blur){
    cv::Mat close;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, binary_blur.rows < binary_blur.cols ? cv::Size(21,7) : cv::Size(7,21));
    cv::morphologyEx(binary_blur,close,cv::MORPH_CLOSE,kernel);

    cv::Mat kernel_second = cv::getStructuringElement(cv::MORPH_RECT, binary_blur.rows < binary_blur.cols ? cv::Size(21,7) : cv::Size(7,21)  );
    cv::erode(close,close,kernel_second,cv::Point(-1,-1),4);
    cv::dilate(close,close,kernel_second,cv::Point(-1,-1),4);

    return close;
}

/*
 * Fonction de détection des contours sur une image après application de fermetures sucessives
 * close : image après application de Fermetures
 */
cv::Mat detectContours(const cv::Mat &close){

    vector<vector<cv::Point>> contours;
    findContours(close, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE );
    cv::Mat drawing = cv::Mat::zeros(close.size(),CV_8UC3);
    for(size_t i = 0 ; i < contours.size(); i++){
        cv::Scalar color = cv::Scalar(0,0,255);
        cv::drawContours(drawing,contours,i,color,2,cv::LINE_8);
    }
    return drawing;
}


/*
 * Fonction permettant d'ajouter l'image d'origine avec l'image des contours
 * sourceImg : Image d'origine
 * drawing : Image des contours
 */
cv::Mat fusionImg(const cv::Mat &sourceImg, const cv::Mat &drawing){
    cv::Mat final_img;
    cv::addWeighted(sourceImg,1,drawing,1,0,final_img);
    return final_img;
}


/*
 * calculate the background of an image using rolling ball algorithm
 * @param : radius, size of the ball to apply
 * returns : background of the image
 */
cv::Mat getBackground(const cv::Mat& sourceImg,const int& radius) {
    cout << "1";
    int rows = sourceImg.cols, cols = sourceImg.rows;
    cv::Mat background = cv::Mat::zeros(sourceImg.size(), CV_8U);
    cv::Rect kernel;
    std::vector<std::vector<bool>> ball = std::vector<std::vector<bool>>(2 * (radius +1));
    for (int i = - radius ; i <= radius; i++) {
        cout << endl;
        ball[i+radius] = vector<bool>(2 * (radius+1), false);
        for (int j = - radius ; j <= radius; j++) {
            if (sqrt(i*i + j * j) <= radius) {
                ball[i + radius][j + radius] = true;

            }
        }
    }

    cout << "max row :" << rows << ", max cols : " << cols << endl;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            //Determinate the size of the box we are going to apply the ball on
            int a = max(0, row - 2 *radius);
            int b = max(0, col - 2* radius);
            int c = min(rows,row + 2* radius);
            int d = min(cols, col + 2* radius);

            int ball_row_inc, ball_row_dec, ball_col_inc, ball_col_dec;

            row - radius < 0 ? ball_row_inc = radius - row: ball_row_inc = 0;
            col - radius < 0 ? ball_col_inc = radius - col : ball_col_inc = 0;
            row + radius > rows ? ball_row_dec = (row + radius) - rows : ball_row_dec = 0;
            col + radius > rows ? ball_col_dec = (col + radius) - cols : ball_col_dec = 0;
            kernel = cv::Rect(cv::Point(a, b), cv::Point(c,d));
            int result = 0;
            int area_tmp = 0;

            for (int x = ball_row_inc; x < 2 * radius - ball_row_dec; x++) {
                for (int y = ball_col_inc; y < 2 * radius - ball_col_dec; y++) {
                    if (ball[x][y]) {
                        result += sourceImg(kernel).at<uchar>( x +radius, y +radius);
                        area_tmp++;
                    }
                }
            }

            result /= area_tmp;
            background.at<uchar>(col, row) = result;
        }
    }
    cv::imshow("background", background);
    return background;
}

cv::Mat rollingBall(const cv::Mat& sourceImg, const int& radius) {
    cv::Mat background = getBackground(sourceImg, radius);
    int rows = sourceImg.cols, cols = sourceImg.rows;

    int max = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int val = sourceImg.at<uchar>(col, row) + background.at<uchar>(col, row);
            if (val > max) {
                max = val;
            }
        }
    }
    cout << "MAX VAL = " << max;
    cv::Mat result = 255 * (sourceImg + background) / max;

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