//
// Created by meynadier on 29/03/19.
//


#include "TestProcess.h"



TestProcess::TestProcess() {
    this->img = cv::Mat(150,350,CV_8U,255);

    //Generation du délimiteur
    cv::rectangle(this->img,cv::Point(3,0),cv::Point(6,150),0,-1);
    cv::rectangle(this->img,cv::Point(11,0),cv::Point(14,150),0,-1);

    //Génération du 9
    cv::rectangle(this->img,cv::Point(27,0),cv::Point(30,130),0,-1);
    cv::rectangle(this->img,cv::Point(35,0),cv::Point(43,130),0,-1);
    //Génération du 0
    cv::rectangle(this->img,cv::Point(48,0),cv::Point(52,130),0,-1);
    cv::rectangle(this->img,cv::Point(42,0),cv::Point(50,130),0,-1);
    //Génération du 1
    cv::rectangle(this->img,cv::Point(57,0),cv::Point(64,130),0,-1);
    cv::rectangle(img,cv::Point(74,0),cv::Point(81,130),0,-1);
    //Génération du 2
    cv::rectangle(this->img,cv::Point(90,0),cv::Point(93,130),0,-1);
    cv::rectangle(this->img,cv::Point(98,0),cv::Point(101,130),0,-1);
    //Génération du 3
    cv::rectangle(this->img,cv::Point(106,0),cv::Point(119,130),0,-1);
    cv::rectangle(this->img,cv::Point(124,0),cv::Point(127,130),0,-1);
    //Génération du 4
    cv::rectangle(this->img,cv::Point(139,0),cv::Point(150,130),0,-1);
    cv::rectangle(this->img,cv::Point(64,0),cv::Point(65,130),0,-1);

    //Génération du délimiteur
    cv::rectangle(this->img,cv::Point(155,0),cv::Point(158,150),0,-1);
    cv::rectangle(this->img,cv::Point(163,0),cv::Point(166,150),0,-1);

    //Génération du 1
    cv::rectangle(this->img,cv::Point(171,0),cv::Point(178,130),0,-1);
    cv::rectangle(this->img,cv::Point(187,0),cv::Point(194,130),0,-1);

    //Génération du 2
    cv::rectangle(this->img,cv::Point(199,0),cv::Point(202,130),0,-1);
    cv::rectangle(this->img,cv::Point(211,0),cv::Point(218,130),0,-1);

    //Génération du 3
    cv::rectangle(this->img,cv::Point(223,0),cv::Point(234,130),0,-1);
    cv::rectangle(this->img,cv::Point(239,0),cv::Point(242,130),0,-1);

    //Génération du 4
    cv::rectangle(this->img,cv::Point(247,0),cv::Point(250,130),0,-1);
    cv::rectangle(this->img,cv::Point(262,0),cv::Point(269,130),0,-1);

    //Génération du 5
    cv::rectangle(this->img,cv::Point(274,0),cv::Point(281,130),0,-1);
    cv::rectangle(this->img,cv::Point(293,0),cv::Point(296,130),0,-1);

    //Génération du 7
    cv::rectangle(this->img,cv::Point(301,0),cv::Point(312,130),0,-1);
    cv::rectangle(this->img,cv::Point(316,0),cv::Point(323,130),0,-1);

    //Génération du délimiteur
    cv::rectangle(this->img,cv::Point(331,0),cv::Point(334,150),0,-1);
    cv::rectangle(this->img,cv::Point(339,0),cv::Point(342,150),0,-1);


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
    << "----- " << testConvertToEAN() << " -----" << endl
    << "----- " << testReadingEAN() << " -----" << endl;
}
