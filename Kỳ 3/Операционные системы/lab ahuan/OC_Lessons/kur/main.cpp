#include<cstdlib>
#include<graphics.h>
#include "desk.h"

void *ptr = NULL;

int main(void){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    Desk dsk;
    dsk.Go();
    system("pause");
    closegraph();
    return 0;
}
