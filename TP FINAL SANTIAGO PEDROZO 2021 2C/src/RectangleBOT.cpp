#include "RectangleBOT.h"
#include"Random.h"


RectangleBOT::RectangleBOT()
{
    _Rshape.setPosition(740, 0);
}


void RectangleBOT::updateBOT(float y, float x, int dir){
    float res;
    int Numbers=3;
    res = Random(Numbers); ///CUANTO MAS NUMEROS MENOS POSIBILIDAD DE QUE SEA IGUAL A 1 Y QUE REACCIONE

    if(x>350 && dir==1){
        if(res<=1){
            y = _Rshape.getPosition().y;
        }
        else{
           _Rshape.setPosition(_Rshape.getPosition().x , y );
        }
    }

    checkcolitionborder();
}

