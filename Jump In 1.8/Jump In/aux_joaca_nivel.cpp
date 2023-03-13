#include "vector"
#include "graphics.h"

using std::string;

bool is_jos(int i_start, int j_start, int i_dest, int j_dest){
    return (j_start == j_dest && i_start < i_dest);
}
bool is_sus(int i_start, int j_start, int i_dest, int j_dest){
    return (j_start == j_dest && i_start > i_dest);
}
bool is_dreapta(int i_start, int j_start, int i_dest, int j_dest){
    return (j_start < j_dest && i_start == i_dest);
}
bool is_stanga(int i_start, int j_start, int i_dest, int j_dest){
    return (j_start > j_dest && i_start == i_dest);
}
bool valid_pozitie(int i, int j){
    if(i > 4 || j > 4)
        return false;
    if(i < 0 || j < 0)
        return false;
    return true;
}
bool miscare_valida_vulpe(std::vector<int> v, int val){
    for(unsigned int i=0 ; i< v.size() ; ++i)
        if(v[i] == val)
            return true;
    return false;
}
int tip_actiune_mouse_casual(int w, int h){
    //26 20
    //307 139
    //1584 20
    //1882 139

    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_1 = w / 73.615384;
    double x2_buton_1 = w / 6.2345276873;
    double y1_buton_1 = h / 52.55;
    double y2_buton_1 = h / 7.561151;

    double x1_buton_2 = w / 2.83;
    double x2_buton_2 = w / 1.0170031881;
    double y1_buton_2 = h / 52.55;
    double y2_buton_2 = h / 7.561151;


    if(x1_buton_1 < indice_mouse_x && indice_mouse_x < x2_buton_1 && y1_buton_1 < indice_mouse_y && indice_mouse_y < y2_buton_1)
        return 1;

    if(x1_buton_2 < indice_mouse_x && indice_mouse_x < x2_buton_2 && y1_buton_2 < indice_mouse_y && indice_mouse_y < y2_buton_2)
        return 2;

    return 0;
}
int tip_actiune_mouse_survival(int w, int h){
    //26 20
    //307 139
    //1584 20
    //1882 139

    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_1 = w / 73.615384;
    double x2_buton_1 = w / 6.2345276873;
    double y1_buton_1 = h / 52.55;
    double y2_buton_1 = h / 7.561151;

    double x1_buton_2 = w / 2.83;
    double x2_buton_2 = w / 1.0170031881;
    double y1_buton_2 = h / 52.55;
    double y2_buton_2 = h / 7.561151;


    if(x1_buton_1 < indice_mouse_x && indice_mouse_x < x2_buton_1 && y1_buton_1 < indice_mouse_y && indice_mouse_y < y2_buton_1)
        return 1;

    if(x1_buton_2 < indice_mouse_x && indice_mouse_x < x2_buton_2 && y1_buton_2 < indice_mouse_y && indice_mouse_y < y2_buton_2)
        return 2;

    return 0;
}
int tip_actiune_mouse_choose(int w, int h){
    //26 20
    //307 139
    //1584 20
    //1882 139

    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_1 = w / 73.615384;
    double x2_buton_1 = w / 6.2345276873;
    double y1_buton_1 = h / 52.55;
    double y2_buton_1 = h / 7.561151;

    double x1_buton_2 = w / 2.83;
    double x2_buton_2 = w / 1.0170031881;
    double y1_buton_2 = h / 52.55;
    double y2_buton_2 = h / 7.561151;

    //36 889
    //326 1010
    //1594 894
    //1886 1008

    double x1_buton_3 = w / 53.16666666666667;
    double x2_buton_3 = w / 5.87116564417178;
    double y1_buton_3 = h / 1.1808988764;
    double y2_buton_3 = h / 1.0416253716551;

    double x1_buton_4 = w / 1.200752823;
    double x2_buton_4 = w / 1.01484623541887592788;
    double y1_buton_4 = h / 1.1808988764;
    double y2_buton_4 = h / 1.0416253716551;


    if(x1_buton_1 < indice_mouse_x && indice_mouse_x < x2_buton_1 && y1_buton_1 < indice_mouse_y && indice_mouse_y < y2_buton_1)
        return 1;

    if(x1_buton_2 < indice_mouse_x && indice_mouse_x < x2_buton_2 && y1_buton_2 < indice_mouse_y && indice_mouse_y < y2_buton_2)
        return 2;

    if(x1_buton_3 < indice_mouse_x && indice_mouse_x < x2_buton_3 && y1_buton_3 < indice_mouse_y && indice_mouse_y < y2_buton_3)
        return 3;

    if(x1_buton_4 < indice_mouse_x && indice_mouse_x < x2_buton_4 && y1_buton_4 < indice_mouse_y && indice_mouse_y < y2_buton_4)
        return 4;

    return 0;
}
/*
char* itos(int numar){
    string sir =
    return sir.c_str();
}*/
