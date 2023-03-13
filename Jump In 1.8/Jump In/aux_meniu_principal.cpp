#include "graphics.h"

void schimba_limba_curenta(int& limba_curenta){
    if(limba_curenta == 4)
        limba_curenta = 1;
    else
        limba_curenta++;
}
bool click_limba_curenta(int w, int h){
    //1772 18
    //1854 100
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_limba = w / 1.08352;
    double x2_buton_limba = w / 1.0356;
    double y1_buton_limba = h / 60;
    double y2_buton_limba = h / 10.8;

    if(x1_buton_limba < indice_mouse_x && indice_mouse_x < x2_buton_limba && y1_buton_limba < indice_mouse_y && indice_mouse_y < y2_buton_limba
             && ismouseclick(WM_LBUTTONDOWN)){
             clearmouseclick(WM_LBUTTONDOWN);
             return 1;
    }
    return 0;
}
bool click_sunet(int w, int h){
    //1660 23
    //1738 100
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_sunet = w / 1.1566265;
    double x2_buton_sunet = w / 1.104718;
    double y1_buton_sunet = h / 47;
    double y2_buton_sunet = h / 10.8;

    if(x1_buton_sunet < indice_mouse_x && indice_mouse_x < x2_buton_sunet && y1_buton_sunet < indice_mouse_y && indice_mouse_y < y2_buton_sunet
             && ismouseclick(WM_LBUTTONDOWN)){
             clearmouseclick(WM_LBUTTONDOWN);
             return 1;
    }
    return 0;

}
int tip_actiune_mouse(int w, int h){
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_1 = w / 2.83;
    double x2_buton_1 = w / 1.63;
    double y1_buton_1 = h / 2.3;
    double y2_buton_1 = h / 1.78;

    double x1_buton_2 = w / 2.83;
    double x2_buton_2 = w / 1.63;
    double y1_buton_2 = h / 1.7;
    double y2_buton_2 = h / 1.42;

    double x1_buton_3 = w / 2.83;
    double x2_buton_3 = w / 1.63;
    double y1_buton_3 = h / 1.4;
    double y2_buton_3 = h / 1.2;

    if(x1_buton_1 < indice_mouse_x && indice_mouse_x < x2_buton_1 && y1_buton_1 < indice_mouse_y && indice_mouse_y < y2_buton_1)
        return 1;

    if(x1_buton_2 < indice_mouse_x && indice_mouse_x < x2_buton_2 && y1_buton_2 < indice_mouse_y && indice_mouse_y < y2_buton_2)
        return 2;

    if(x1_buton_3 < indice_mouse_x && indice_mouse_x < x2_buton_3 && y1_buton_3 < indice_mouse_y && indice_mouse_y < y2_buton_3)
        return 3;

    return 0;
}
