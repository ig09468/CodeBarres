//
// Created by meynadier on 14/02/19.
//

#ifndef CODEBARRES_EAN_H
#define CODEBARRES_EAN_H

/*
 * Enumération contenant les correspondances des chiffres par rapports aux barres du code
 */
namespace ean
{
    typedef enum
    {
        ZERO = 3211,
        ZEROB = 1123,
        UN = 2221,
        UNB = 1222,
        DEUX = 2122,
        DEUXB = 2212,
        TROIS = 1411,
        TROISB = 1141,
        QUATRE = 1132,
        QUATREB = 2311,
        CINQ = 1231,
        CINQB = 1321,
        SIX = 1114,
        SIXB = 4111,
        SEPT = 1312,
        SEPTB = 2131,
        HUIT = 1213,
        HUITB = 3121,
        NEUF = 3112,
        NEUFB = 2113
    }EnumEAN;
}


#endif //CODEBARRES_EAN_H
