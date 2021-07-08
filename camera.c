#include "camera.h"
#include <stdio.h>

float coos [6] [3] = {
    {3.5,1.3,2},
    {4,1.3,1},
    {0.5,1.3,0.5},
    {0.5,1.3,1.5},
    {-1.5,1.3,1.5},
    {-1,1.3,1},
};

int etape = 0 ;

void mouvement(){
    switch (etape)
    {
    case 0:
        offX+=3.5/300;
        offZ-=13./300;
        if(offX>=3.5 && offZ<=2) {etape+=1;}
        break;

    case 1:
        offX+=0.5/300;
        offZ-=1./300;
        longitude+=3.14159261/400;

        if(offX>=4 && offZ<=1) {etape+=1;}
        break;

    case 2:
        offX-=3.5/300;
        offZ-=0.5/300;
        longitude+=1.514159261/200;
        if(offX<=0.5 && offZ<=0.5) {etape+=1;}
        break;

    case 3:
        offZ+=1./300;
        if(offZ>=1.5) {etape+=1;}
        break;
    
    case 4:
        offX-=1./300;
        longitude-=3.14159261/400;
        if(offX<=-1.5) {etape+=1;}
        break;

    case 5:
        offX+=0.5/300;
        offZ-=2.5/300;
        longitude-=3.14159261/250;
        if(offX>=-1 && offZ<=1) {etape+=1;}
        break;

    default: 
        break;
    }
}
