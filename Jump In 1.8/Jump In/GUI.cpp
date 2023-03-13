#include "graphics.h"
#include "winbgim.h"
#include "iostream"
#include "string"
#include "windows.h"
#include "iepure.h"
#include "vulpe.h"
#include "ciuperca.h"
#include "groapa.h"
#include "casute_libere.h"
#include "meniu_principal.h"
#include "instructiuni.h"
#include "exit_game.h"

using std::cout;

void initializeaza_GUI(int w, int h){
    initwindow(w, h);
}
void start_GUI(int tabla[5][5], int tabla_goala[5][5]){
    int latimea_ecranului = getmaxwidth();
    int inaltimea_ecranului = getmaxheight();

    initializeaza_GUI(latimea_ecranului, inaltimea_ecranului);
    bool running = true;
    int limba_curenta = 1;
    bool sunet = 1;

    mciSendString("play sound/tema_background.mp3 repeat", NULL, 0, NULL);
    while(running)
        if(limba_curenta == 1)
            meniu_in_romana(latimea_ecranului, inaltimea_ecranului, sunet, limba_curenta);
        else if(limba_curenta == 2)
            meniu_in_engleza(latimea_ecranului, inaltimea_ecranului, sunet, limba_curenta);
        else if(limba_curenta == 3)
            meniu_in_franceza(latimea_ecranului, inaltimea_ecranului, sunet, limba_curenta);
        else if(limba_curenta == 4)
            meniu_in_japoneza(latimea_ecranului, inaltimea_ecranului, sunet, limba_curenta);
}
