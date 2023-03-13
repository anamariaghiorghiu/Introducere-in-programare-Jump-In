#include "graphics.h"

bool instructiuni_back_glow(int w, int h){
    //22 27
    //78 61
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_back = w / 87.272727;
    double x2_buton_back = w / 24.61538;
    double y1_buton_back = h / 40;
    double y2_buton_back = h / 17.7;

    return (x1_buton_back < indice_mouse_x && indice_mouse_x < x2_buton_back && y1_buton_back < indice_mouse_y && indice_mouse_y < y2_buton_back);
}

void show_instructiuni_romana(int w, int h, bool sunet){
    while(true){
        clearmouseclick(WM_LBUTTONDOWN);
        if(instructiuni_back_glow(w, h)){
            readimagefile("jpg/instructiuni/instructiuni_romana_glow_back.jpg", 0, 0, w, h);
            if(ismouseclick(WM_LBUTTONDOWN)){
                if(sunet)
                    mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                break;
            }
        }
        else
            readimagefile("jpg/instructiuni/instructiuni_romana.jpg", 0, 0, w, h);
    }

}
void show_instructiuni_engleza(int w, int h, bool sunet){
    while(true){
        clearmouseclick(WM_LBUTTONDOWN);
        if(instructiuni_back_glow(w, h)){
            readimagefile("jpg/instructiuni/instructiuni_engleza_glow_back.jpg", 0, 0, w, h);
            if(ismouseclick(WM_LBUTTONDOWN)){
                if(sunet)
                    mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                break;
            }
        }
        else
            readimagefile("jpg/instructiuni/instructiuni_engleza.jpg", 0, 0, w, h);
    }
}
void show_instructiuni_franceza(int w, int h, bool sunet){
    while(true){
        clearmouseclick(WM_LBUTTONDOWN);
        if(instructiuni_back_glow(w, h)){
            readimagefile("jpg/instructiuni/instructiuni_franceza_glow_back.jpg", 0, 0, w, h);
            if(ismouseclick(WM_LBUTTONDOWN)){
                if(sunet)
                    mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                break;
            }
        }
        else
            readimagefile("jpg/instructiuni/instructiuni_franceza.jpg", 0, 0, w, h);
    }
}
void show_instructiuni_japoneza(int w, int h, bool sunet){
    while(true){
        clearmouseclick(WM_LBUTTONDOWN);
        if(instructiuni_back_glow(w, h)){
            readimagefile("jpg/instructiuni/instructiuni_japoneza_glow_back.jpg", 0, 0, w, h);
            if(ismouseclick(WM_LBUTTONDOWN)){
                if(sunet)
                    mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                break;
            }
        }
        else
            readimagefile("jpg/instructiuni/instructiuni_japoneza.jpg", 0, 0, w, h);
    }
}
