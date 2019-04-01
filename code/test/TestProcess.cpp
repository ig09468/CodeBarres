//
// Created by meynadier on 29/03/19.
//


#include "TestProcess.h"



TestProcess::TestProcess() {
    this->img = cv::Mat(150,400,CV_8U,255);

    //Generation du délimiteur
    cv::rectangle(this->img,cv::Point(3,0),cv::Point(6,150),0,-1);
    cv::rectangle(this->img,cv::Point(11,0),cv::Point(14,150),0,-1);

    //Génération du 9 (3 1 1 2)
    cv::rectangle(this->img,cv::Point(27,0),cv::Point(30,130),0,-1);
    cv::rectangle(this->img,cv::Point(35,0),cv::Point(43,130),0,-1);
    //Génération du 0 (1 1 2 3)
    cv::rectangle(this->img,cv::Point(48,0),cv::Point(51,130),0,-1);
    cv::rectangle(this->img,cv::Point(60,0),cv::Point(71,130),0,-1);
    //Génération du 1 (1 2 2 2)
    cv::rectangle(this->img,cv::Point(76,0),cv::Point(83,130),0,-1);
    cv::rectangle(img,cv::Point(93,0),cv::Point(100,130),0,-1);
    //Génération du 2 (2 1 2 2)
    cv::rectangle(this->img,cv::Point(108,0),cv::Point(111,130),0,-1);
    cv::rectangle(this->img,cv::Point(120,0),cv::Point(127,130),0,-1);
    //Génération du 3 (1 4 1 1)
    cv::rectangle(this->img,cv::Point(132,0),cv::Point(147,130),0,-1);
    cv::rectangle(this->img,cv::Point(152,0),cv::Point(155,130),0,-1);
    //Génération du 4 (2 3 1 1)
    cv::rectangle(this->img,cv::Point(164,0),cv::Point(175,130),0,-1);
    cv::rectangle(this->img,cv::Point(180,0),cv::Point(183,130),0,-1);

    //Génération du délimiteur (1 1 1 1 1)
    cv::rectangle(this->img,cv::Point(188,0),cv::Point(191,150),0,-1);
    cv::rectangle(this->img,cv::Point(196,0),cv::Point(199,150),0,-1);

    //Génération du 1 (2 2 2 1)
    cv::rectangle(this->img,cv::Point(204,0),cv::Point(211,130),0,-1);
    cv::rectangle(this->img,cv::Point(220,0),cv::Point(227,130),0,-1);

    //Génération du 2 (2 1 2 2)
    cv::rectangle(this->img,cv::Point(232,0),cv::Point(239,130),0,-1);
    cv::rectangle(this->img,cv::Point(244,0),cv::Point(251,130),0,-1);

    //Génération du 3 (1 4 1 1)
    cv::rectangle(this->img,cv::Point(260,0),cv::Point(263,130),0,-1);
    cv::rectangle(this->img,cv::Point(280,0),cv::Point(283,130),0,-1);

    //Génération du 4 (1 1 3 2)
    cv::rectangle(this->img,cv::Point(288,0),cv::Point(291,130),0,-1);
    cv::rectangle(this->img,cv::Point(296,0),cv::Point(307,130),0,-1);

    //Génération du 5 (1 2 3 1)
    cv::rectangle(this->img,cv::Point(316,0),cv::Point(319,130),0,-1);
    cv::rectangle(this->img,cv::Point(328,0),cv::Point(339,130),0,-1);

    //Génération du 7 (1 3 1 2)
    cv::rectangle(this->img,cv::Point(344,0),cv::Point(347,130),0,-1);
    cv::rectangle(this->img,cv::Point(362,0),cv::Point(365,130),0,-1);

    //Génération du délimiteur
    cv::rectangle(this->img,cv::Point(374,0),cv::Point(377,150),0,-1);
    cv::rectangle(this->img,cv::Point(382,0),cv::Point(385,150),0,-1);


    cv::imshow("Test 1",img);
    cv::waitKey(0);

}


TestProcess::~TestProcess() {

}


/*
 * Fonction de test de searchRation
 * Résultat connu : O.25
 */
bool TestProcess::testSearchRatio() {
    std::cout << "Test de searchRatio() : ";
    double result = searchRatio(this->img,1);
    return result == 0.25;
}


/*
 * Fonction de test de IsBlack
 */
bool TestProcess::testIsBlack(){
    std::cout << "Test de isBlack() : ";
    return isBlack(img.at<uchar>(0,3));
}

/*
 * Fonction de test de searchFirstDelimiter
 * Résultat attendu : 3
 */
bool TestProcess::testSearchFirstDelimiter() {
    std::cout << "Test de searchFirstDelimiter() : ";
    int colStart = searchFirstDelimiter(this->img, 1);
    return colStart == 3;
}

bool TestProcess::testSearchStartBarCode(){
    std::cout << "Test de searchStartBarCode() : ";
    int startDelimiter = searchFirstDelimiter(this->img,1);
    double ratio = searchRatio(this->img, 1);
    int test = searchStartBarCode(this->img,1,startDelimiter,ratio);
    return 15 == test;
}

bool TestProcess::testConvertToEAN(){
    vector<int> result = vector<int>({9,0,1,2,3,4,1,2,3,4,5,7});
    vector<int> base = vector<int>({3,1,1,2,1,1,2,3,1,2,2,2,2,1,2,2,1,4,1,1,2,3,1,1,-1,-1,-1,-1,-1,2,2,2,1,2,1,2,2,1,4,1,1,1,1,3,2,1,2,3,1,1,3,1,2});
    vector<int> test = convertByteToEAN(base);
    std::cout << "Test de convertToEAN : ";
    if(result.size() != test.size()){
        return false;
    }
    for(int value = 0 ; value < result.size() ;value++){
        if(result[value] != test[value]){
            return false;
        }
    }
    return true;
}

bool TestProcess::testReadingEAN() {
    std::cout << "Test de readingEAN() : " << endl;
    vector<int> result = vector<int>({9,0,1,2,3,4,1,2,3,4,5,7});
    vector<int> barCode;
    barCode = readingEAN(this->img,1);
    std::cout << "Valeurs trouvées : ";
    for(int value : barCode){
        std::cout << value << ",";
    }
    std::cout << endl;
    if(result.size() != barCode.size()){
        return false;
    }
    for(int roam = 0 ; roam < barCode.size() ; roam++){
        if(result[roam]!=barCode[roam]){
            return false;
        }
    }
    return true;
}

void TestProcess::start() {
    std::cout << "----- " << testIsBlack() << " -----" <<  endl
    << "----- " << testSearchRatio() << " -----" << endl
    << "----- " << testSearchFirstDelimiter() << " -----" << endl
    << "----- " << testSearchStartBarCode() << " -----"<< endl
    << "----- " << testConvertToEAN() << " -----" << endl
    << "----- " << testReadingEAN() << " -----" << endl;
}
