#include "graphics.h"
#include "alege_nivel.h"
#include "casual_mode.h"
#include "survival_mode.h"

int tip_actiune_mouse_mod(int w, int h){
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_1 = w / 8.8888888;
    double x2_buton_1 = w / 2.29116;
    double y1_buton_1 = h / 4;
    double y2_buton_1 = h / 2.59;

    double x1_buton_2 = w / 8.8888888;
    double x2_buton_2 = w / 2.29116;
    double y1_buton_2 = h / 1.953;
    double y2_buton_2 = h / 1.52112676;

    double x1_buton_3 = w / 8.8888888;
    double x2_buton_3 = w / 2.29116;
    double y1_buton_3 = h / 1.2811388;
    double y2_buton_3 = h / 1.085427;

    double x1_buton_back = w / 192;
    double x2_buton_back = w / 24;
    double y1_buton_back = h / 47;
    double y2_buton_back = h / 21.5;

    if(x1_buton_1 < indice_mouse_x && indice_mouse_x < x2_buton_1 && y1_buton_1 < indice_mouse_y && indice_mouse_y < y2_buton_1)
        return 1;

    if(x1_buton_2 < indice_mouse_x && indice_mouse_x < x2_buton_2 && y1_buton_2 < indice_mouse_y && indice_mouse_y < y2_buton_2)
        return 2;

    if(x1_buton_3 < indice_mouse_x && indice_mouse_x < x2_buton_3 && y1_buton_3 < indice_mouse_y && indice_mouse_y < y2_buton_3)
        return 3;

    if(x1_buton_back < indice_mouse_x && indice_mouse_x < x2_buton_back && y1_buton_back < indice_mouse_y && indice_mouse_y < y2_buton_back)
        return 4;

    return 0;
}
void alege_mod(int latimea_ecranului, int inaltimea_ecranului, bool sunet, int limba){
    while(true){
        clearmouseclick(WM_LBUTTONDOWN);
        if(tip_actiune_mouse_mod(latimea_ecranului, inaltimea_ecranului) == 1){
            switch(limba){
            case 1:
                readimagefile("jpg/alege_mod/mode_romana_casual_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    start_casual(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            case 2:
                readimagefile("jpg/alege_mod/mode_engleza_casual_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    start_casual(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            case 3:
                readimagefile("jpg/alege_mod/mode_franceza_casual_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    start_casual(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            default:
                readimagefile("jpg/alege_mod/mode_japoneza_casual_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    start_casual(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            }
        }
        else if(tip_actiune_mouse_mod(latimea_ecranului, inaltimea_ecranului) == 2){
            switch(limba){
            case 1:
                readimagefile("jpg/alege_mod/mode_romana_survival_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    start_survival(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            case 2:
                readimagefile("jpg/alege_mod/mode_engleza_survival_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    start_survival(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            case 3:
                readimagefile("jpg/alege_mod/mode_franceza_survival_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    start_survival(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            default:
                readimagefile("jpg/alege_mod/mode_japoneza_survival_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    start_survival(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            }
        }
        else if(tip_actiune_mouse_mod(latimea_ecranului, inaltimea_ecranului) == 3){
            switch(limba){
            case 1:
                readimagefile("jpg/alege_mod/mode_romana_choose_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                        alege_nivel(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            case 2:
                readimagefile("jpg/alege_mod/mode_engleza_choose_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                        alege_nivel(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            case 3:
                readimagefile("jpg/alege_mod/mode_franceza_choose_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                        alege_nivel(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            default:
                readimagefile("jpg/alege_mod/mode_japoneza_choose_glow.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                        alege_nivel(latimea_ecranului, inaltimea_ecranului, sunet, limba);
                }
                break;
            }
        }
        else if(tip_actiune_mouse_mod(latimea_ecranului, inaltimea_ecranului) == 4){
            if(limba == 1){
                readimagefile("jpg/alege_mod/mode_romana_glow_back.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                break;
                }
            }
            else if(limba == 2){
                readimagefile("jpg/alege_mod/mode_engleza_glow_back.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    break;
                }
            }
            else if(limba == 3){
                readimagefile("jpg/alege_mod/mode_franceza_glow_back.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    break;
                }
            }
            else {
                readimagefile("jpg/alege_mod/mode_japoneza_glow_back.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                if(ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                    break;
                }
            }
        }
        else{
            switch(limba){
            case 1:
                readimagefile("jpg/alege_mod/mode_romana.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                break;
            case 2:
                readimagefile("jpg/alege_mod/mode_engleza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                break;
            case 3:
                readimagefile("jpg/alege_mod/mode_franceza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                break;
            default:
                readimagefile("jpg/alege_mod/mode_japoneza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
                break;
            }
        }
    }
}
