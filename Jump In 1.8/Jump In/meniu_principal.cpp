#include "graphics.h"
#include "aux_meniu_principal.h"
#include "controller_meniu_principal.h"
#include "gui_meniu_principal.h"


void meniu_in_romana(int latimea_ecranului, int inaltimea_ecranului, bool& sunet, int& limba_curenta){
    while(!click_limba_curenta(latimea_ecranului, inaltimea_ecranului)){
    clearmouseclick(WM_LBUTTONDOWN);
    int tipul_curent = tip_actiune_mouse(latimea_ecranului, inaltimea_ecranului);
    if(sunet == true){
        show_romana_sound_on(latimea_ecranului, inaltimea_ecranului, tipul_curent);
        menu_controller(latimea_ecranului, inaltimea_ecranului, tipul_curent, limba_curenta, 1);
    }
    else{
        show_romana_sound_off(latimea_ecranului, inaltimea_ecranului, tipul_curent);
        menu_controller(latimea_ecranului, inaltimea_ecranului, tipul_curent, limba_curenta, 0);
    }
    if(click_sunet(latimea_ecranului, inaltimea_ecranului)){
        if(sunet == true){
            sunet = false;
            mciSendString("pause sound/tema_background.mp3", NULL, 0, NULL);
        }
        else{
            sunet = true;
            mciSendString("resume sound/tema_background.mp3", NULL, 0, NULL);
        }
    }
    }
    schimba_limba_curenta(limba_curenta);
    clearmouseclick(WM_LBUTTONDOWN);
}
void meniu_in_engleza(int latimea_ecranului, int inaltimea_ecranului, bool& sunet, int& limba_curenta){
    while(!click_limba_curenta(latimea_ecranului, inaltimea_ecranului)){

    clearmouseclick(WM_LBUTTONDOWN);
    int tipul_curent = tip_actiune_mouse(latimea_ecranului, inaltimea_ecranului);
    if(sunet == true){
        show_engleza_sound_on(latimea_ecranului, inaltimea_ecranului, tipul_curent);
        menu_controller(latimea_ecranului, inaltimea_ecranului, tipul_curent, limba_curenta, 1);
    }
    else{
        show_engleza_sound_off(latimea_ecranului, inaltimea_ecranului, tipul_curent);
        menu_controller(latimea_ecranului, inaltimea_ecranului, tipul_curent, limba_curenta, 0);
    }

    if(click_sunet(latimea_ecranului, inaltimea_ecranului)){
        if(sunet == true){
            sunet = false;
            mciSendString("pause sound/tema_background.mp3", NULL, 0, NULL);
        }
        else{
            sunet = true;
            mciSendString("resume sound/tema_background.mp3", NULL, 0, NULL);
        }
    }
    }
    schimba_limba_curenta(limba_curenta);
    clearmouseclick(WM_LBUTTONDOWN);
}
void meniu_in_franceza(int latimea_ecranului, int inaltimea_ecranului, bool& sunet, int& limba_curenta){
    while(!click_limba_curenta(latimea_ecranului, inaltimea_ecranului)){
    clearmouseclick(WM_LBUTTONDOWN);
    int tipul_curent = tip_actiune_mouse(latimea_ecranului, inaltimea_ecranului);
    if(sunet == true){
        show_franceza_sound_on(latimea_ecranului, inaltimea_ecranului, tipul_curent);
        menu_controller(latimea_ecranului, inaltimea_ecranului, tipul_curent, limba_curenta, 1);
    }
    else{
        show_franceza_sound_off(latimea_ecranului, inaltimea_ecranului, tipul_curent);
        menu_controller(latimea_ecranului, inaltimea_ecranului, tipul_curent, limba_curenta, 0);
    }
    if(click_sunet(latimea_ecranului, inaltimea_ecranului)){
        if(sunet == true){
            sunet = false;
            mciSendString("pause sound/tema_background.mp3", NULL, 0, NULL);
        }
        else{
            sunet = true;
            mciSendString("resume sound/tema_background.mp3", NULL, 0, NULL);
        }
    }
    }
    schimba_limba_curenta(limba_curenta);
    clearmouseclick(WM_LBUTTONDOWN);
}
void meniu_in_japoneza(int latimea_ecranului, int inaltimea_ecranului, bool& sunet, int& limba_curenta){
    while(!click_limba_curenta(latimea_ecranului, inaltimea_ecranului)){
    clearmouseclick(WM_LBUTTONDOWN);
    int tipul_curent = tip_actiune_mouse(latimea_ecranului, inaltimea_ecranului);
    if(sunet == true){
        show_japoneza_sound_on(latimea_ecranului, inaltimea_ecranului, tipul_curent);
        menu_controller(latimea_ecranului, inaltimea_ecranului, tipul_curent, limba_curenta, 1);
    }
    else{
        show_japoneza_sound_off(latimea_ecranului, inaltimea_ecranului, tipul_curent);
        menu_controller(latimea_ecranului, inaltimea_ecranului, tipul_curent, limba_curenta, 0);
    }
    if(click_sunet(latimea_ecranului, inaltimea_ecranului)){
        if(sunet == true){
            sunet = false;
            mciSendString("pause sound/tema_background.mp3", NULL, 0, NULL);
        }
        else{
            sunet = true;
            mciSendString("resume sound/tema_background.mp3", NULL, 0, NULL);
        }
    }
    }
    schimba_limba_curenta(limba_curenta);
    clearmouseclick(WM_LBUTTONDOWN);
}
