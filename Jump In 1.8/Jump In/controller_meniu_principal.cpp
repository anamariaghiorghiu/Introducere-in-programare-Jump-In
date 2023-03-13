#include "graphics.h"
#include "instructiuni.h"
#include "exit_game.h"
#include "meniu_mod_de_joc.h"

void menu_controller(int w, int h, int tip, int limba, bool sunet){
    if(tip == 1 && ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        if(sunet)
            mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
        alege_mod(w, h, sunet, limba);
    }
    else if(tip == 2 && ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        if(sunet)
            mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
        switch(limba){
        case 1:
            show_instructiuni_romana(w, h, sunet);
            break;
        case 2:
            show_instructiuni_engleza(w, h, sunet);
            break;
        case 3:
            show_instructiuni_franceza(w, h, sunet);
            break;
        default:
            show_instructiuni_japoneza(w, h, sunet);
            break;
        }
    }
    else if(tip == 3 && ismouseclick(WM_LBUTTONDOWN))
        exit_game();
}
