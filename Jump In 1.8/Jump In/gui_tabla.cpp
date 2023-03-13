#include "iepure.h"
#include "vulpe.h"
#include "groapa.h"
#include "ciuperca.h"
#include "casute_libere.h"
#include "graphics.h"
#include "iostream"


void get_casuta_tabla(int latimea_ecranului, int inaltimea_ecranului, int& poz_1, int& poz_2){

    double start_x = latimea_ecranului / 3;
    double latura_casuta = start_x / 5;
    double start_y = (inaltimea_ecranului - start_x) / 2;
    double x1 = start_x, y1 = start_y, x2 = start_x + latura_casuta, y2 = start_y+latura_casuta;

    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    for(int i=0 ; i< 5 ; ++i){
        for(int j=0 ; j< 5 ; ++j){
            if(x1 <= indice_mouse_x && indice_mouse_x <= x2 && y1 <= indice_mouse_y && indice_mouse_y <= y2){
                poz_1 = i, poz_2 = j;
                return;
            }
            x1 += latura_casuta, x2 += latura_casuta;
        }
        x1 = start_x, x2 = start_x+latura_casuta;
        y1 += latura_casuta, y2 += latura_casuta;
    }
}
void get_coordonate(int latimea_ecranului, int inaltimea_ecranului, int poz_1, int poz_2, double& x1, double& y1, double& x2, double& y2){
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double start_x = latimea_ecranului / 3;
    double latura_casuta = start_x / 5;
    double start_y = (inaltimea_ecranului - start_x) / 2;
    x1 = start_x, y1 = start_y, x2 = start_x + latura_casuta, y2 = start_y+latura_casuta;

    for(int i=0 ; i< 5 ; ++i){
        for(int j=0 ; j< 5 ; ++j){
            if(x1 <= indice_mouse_x && indice_mouse_x <= x2 && y1 <= indice_mouse_y && indice_mouse_y <= y2){
                return;
            }
            x1 += latura_casuta, x2 += latura_casuta;
        }
        x1 = start_x, x2 = start_x+latura_casuta;
        y1 += latura_casuta, y2 += latura_casuta;
    }
}
void get_coordonate_valoare(int latimea_ecranului, int inaltimea_ecranului, int poz_1, int poz_2, double& x1, double& y1, double& x2, double& y2){
    double start_x = latimea_ecranului / 3;
    double latura_casuta = start_x / 5;
    double start_y = (inaltimea_ecranului - start_x) / 2;
    x1 = start_x, y1 = start_y, x2 = start_x + latura_casuta, y2 = start_y+latura_casuta;

    for(int i=0 ; i< 5 ; ++i){
        for(int j=0 ; j< 5 ; ++j){
            if(poz_1 == i && poz_2 == j){
                return;
            }
            x1 += latura_casuta, x2 += latura_casuta;
        }
        x1 = start_x, x2 = start_x+latura_casuta;
        y1 += latura_casuta, y2 += latura_casuta;
    }
}
double get_coordonate_vulpe_orizontala(int tabla_de_joc[5][5], int latimea_ecranului, int inaltimea_ecranului, int poz_1, int poz_2, double& x1, double& y1, double& x2, double& y2){
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double start_x = latimea_ecranului / 3;
    double latura_casuta = start_x / 5;
    double start_y = (inaltimea_ecranului - start_x) / 2;
    x1 = start_x, y1 = start_y, x2 = start_x + latura_casuta, y2 = start_y+latura_casuta;

    for(int i=0 ; i< 5 ; ++i){
        for(int j=0 ; j< 5 ; ++j){
            if(x1 <= indice_mouse_x && indice_mouse_x <= x2 && y1 <= indice_mouse_y && indice_mouse_y <= y2){
                if(poz_2 != 0 && tabla_de_joc[poz_1][poz_2-1] == tabla_de_joc[poz_1][poz_2]){
                    x1 -= latura_casuta;
                    x2 -= latura_casuta;
                }


                goto returneaza;
            }
            x1 += latura_casuta, x2 += latura_casuta;
        }
        x1 = start_x, x2 = start_x+latura_casuta;
        y1 += latura_casuta, y2 += latura_casuta;
    }
    returneaza:
    return latura_casuta;
}
double get_coordonate_vulpe_verticala(int tabla_de_joc[5][5], int latimea_ecranului, int inaltimea_ecranului, int poz_1, int poz_2, double& x1, double& y1, double& x2, double& y2){
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double start_x = latimea_ecranului / 3;
    double latura_casuta = start_x / 5;
    double start_y = (inaltimea_ecranului - start_x) / 2;
    x1 = start_x, y1 = start_y, x2 = start_x + latura_casuta, y2 = start_y+latura_casuta;

    for(int i=0 ; i< 5 ; ++i){
        for(int j=0 ; j< 5 ; ++j){
            if(x1 <= indice_mouse_x && indice_mouse_x <= x2 && y1 <= indice_mouse_y && indice_mouse_y <= y2){
                if(poz_1 != 0 && tabla_de_joc[poz_1-1][poz_2] == tabla_de_joc[poz_1][poz_2]){
                    y1 -= latura_casuta;
                    y2 -= latura_casuta;
                }
                goto returneaza;
            }
            x1 += latura_casuta, x2 += latura_casuta;
        }
        x1 = start_x, x2 = start_x+latura_casuta;
        y1 += latura_casuta, y2 += latura_casuta;
    }
    returneaza:
    return latura_casuta;
}
void glow_iepure(int latimea_ecranului, int inaltimea_ecranului, int i, int j){
    double x1, y1, x2, y2;
    get_coordonate(latimea_ecranului, inaltimea_ecranului, i, j, x1, y1, x2, y2);
    readimagefile("jpg/tabla/iepure_glow.jpg", x1, y1, x2, y2);
}
void glow_iepure_groapa(int latimea_ecranului, int inaltimea_ecranului, int i, int j){
    double x1, y1, x2, y2;
    get_coordonate(latimea_ecranului, inaltimea_ecranului, i, j, x1, y1, x2, y2);
    readimagefile("jpg/tabla/iepure_in_groapa_glow.jpg", x1, y1, x2, y2);
}
void glow_casuta_libera(int latimea_ecranului, int inaltimea_ecranului, int i, int j){
    double x1, y1, x2, y2;
    get_coordonate_valoare(latimea_ecranului, inaltimea_ecranului, i, j, x1, y1, x2, y2);
    readimagefile("jpg/tabla/liber_glow.jpg", x1, y1, x2, y2);
}
void glow_groapa(int latimea_ecranului, int inaltimea_ecranului, int i, int j){
    double x1, y1, x2, y2;
    get_coordonate_valoare(latimea_ecranului, inaltimea_ecranului, i, j, x1, y1, x2, y2);
    readimagefile("jpg/tabla/groapa_glow.jpg", x1, y1, x2, y2);
}
void glow_vulpe_orizontala(int tabla_de_joc[5][5], int latimea_ecranului, int inaltimea_ecranului, int i, int j){
    double x1, y1, x2, y2;
    double latura = get_coordonate_vulpe_orizontala(tabla_de_joc, latimea_ecranului, inaltimea_ecranului, i, j, x1, y1, x2, y2);
    readimagefile("jpg/tabla/vulpe_orizontala_glow.jpg", x1, y1, x2+latura, y2);
}
void glow_vulpe_verticala(int tabla_de_joc[5][5], int latimea_ecranului, int inaltimea_ecranului, int i, int j){
    double x1, y1, x2, y2;
    double latura = get_coordonate_vulpe_verticala(tabla_de_joc, latimea_ecranului, inaltimea_ecranului, i, j, x1, y1, x2, y2);
    readimagefile("jpg/tabla/vulpe_verticala_glow.jpg", x1, y1, x2, y2+latura);
}
/*
638 765.6 206.5 334.1

765.6 893.2 206.5 334.1

893.2 1020.8 206.5 334.1

1020.8 1148.4 206.5 334.1

1148.4 1276 206.5 334.1

638 765.6 334.1 461.7

765.6 893.2 334.1 461.7

893.2 1020.8 334.1 461.7

1020.8 1148.4 334.1 461.7

1148.4 1276 334.1 461.7

638 765.6 461.7 589.3

765.6 893.2 461.7 589.3

893.2 1020.8 461.7 589.3

1020.8 1148.4 461.7 589.3

1148.4 1276 461.7 589.3

638 765.6 589.3 716.9

765.6 893.2 589.3 716.9

893.2 1020.8 589.3 716.9

1020.8 1148.4 589.3 716.9

1148.4 1276 589.3 716.9

638 765.6 716.9 844.5

765.6 893.2 716.9 844.5

893.2 1020.8 716.9 844.5

1020.8 1148.4 716.9 844.5

1148.4 1276 716.9 844.5
*/
void deseneaza_tabla(int tabla[5][5], int tabla_goala[5][5], int latimea_ecranului, int inaltimea_ecranului){
    double start_x = latimea_ecranului / 3;
    double latura_casuta = start_x / 5;
    double start_y = (inaltimea_ecranului - start_x) / 2;
    double x1 = start_x, y1 = start_y, x2 = start_x + latura_casuta, y2 = start_y+latura_casuta;
    int vulpea_curenta[15] = {};

    for(int i=0 ; i< 5 ; ++i){
        for(int j=0 ; j< 5 ; ++j){
            //std::cout << '\n'<< x1 << ' '<<x2 <<' '<< y1 <<' '<<y2<<'\n';
            if(is_groapa(tabla, i, j))
                readimagefile("jpg/tabla/groapa.jpg", x1, y1, x2, y2);
            else if(is_ciuperca(tabla, i, j))
                readimagefile("jpg/tabla/ciuperca.jpg", x1, y1, x2, y2);
            else if(is_iepure(tabla, i, j)){
                if(tabla_goala[i][j] == 1)
                    readimagefile("jpg/tabla/iepure_in_groapa.jpg", x1, y1, x2, y2);
                else
                    readimagefile("jpg/tabla/iepure.jpg", x1, y1, x2, y2);
            }
            else if(is_vulpe(tabla, i, j)){
                if(vulpea_curenta[tabla[i][j]] == 0){
                    if(is_vulpe_orizontala(tabla, i, j)){
                        readimagefile("jpg/tabla/vulpe_orizontala.jpg", x1, y1, x2+latura_casuta, y2);
                    }
                    else{
                        readimagefile("jpg/tabla/vulpe_verticala.jpg", x1, y1, x2, y2+latura_casuta);
                    }
                vulpea_curenta[tabla[i][j]] = 1;
            }

            }
            else if(is_free(tabla, i, j))
                readimagefile("jpg/tabla/liber.jpg", x1, y1, x2, y2);
            x1 += latura_casuta, x2 += latura_casuta;
        }
        x1 = start_x, x2 = start_x+latura_casuta;
        y1 += latura_casuta, y2 += latura_casuta;

    }

}
