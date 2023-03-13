#include "graphics.h"
#include "tabla_de_joc.h"
#include "tabla_goala.h"
#include "gui_tabla.h"
#include "game_over_conditions.h"
#include "iostream"
#include "gui_tabla.h"
#include "iepure.h"
#include "vulpe.h"
#include "ciuperca.h"
#include "groapa.h"
#include "casute_libere.h"
#include "cstdlib"
#include "time.h"
#include "exit_game.h"
#include "aux_joaca_nivel.h"
#include "solver.h"


void joaca_nivel_choose(int tabla_de_joc[5][5], int tabla_goala[5][5], int latimea_ecranului, int inaltimea_ecranului, bool sunet, int limba, int nivel, int& running){
    deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
    int nr_casute_sus = -1, nr_casute_jos = -1, nr_casute_stanga = -1, nr_casute_dreapta = -1;
    int tabla_initiala[5][5];
    copy_tabla(tabla_de_joc, tabla_initiala);
    while(!toti_iepurii_in_gropi(tabla_de_joc, tabla_goala)){
        new_move:
        clearmouseclick(WM_LBUTTONDOWN);
        int i_start = -1, j_start = -1, i_dest = -1, j_dest = -1;
        get_casuta_tabla(latimea_ecranului, inaltimea_ecranului, i_start, j_start);
        if(valid_pozitie(i_start, j_start)){
            if(is_iepure(tabla_de_joc, i_start, j_start) && ismouseclick(WM_LBUTTONDOWN)){
                    if(sunet)
                        mciSendString("play sound/buton_selecteaza.mp3", NULL, 0, NULL);
                    if(tabla_goala[i_start][j_start] == 1)
                        glow_iepure_groapa(latimea_ecranului, inaltimea_ecranului, i_start, j_start);
                    else
                        glow_iepure(latimea_ecranului, inaltimea_ecranului, i_start, j_start);
                    nr_casute_sus = valideaza_iepure_sus(tabla_de_joc, i_start, j_start);
                    nr_casute_jos = valideaza_iepure_jos(tabla_de_joc, i_start, j_start);
                    nr_casute_stanga = valideaza_iepure_stanga(tabla_de_joc, i_start, j_start);
                    nr_casute_dreapta = valideaza_iepure_dreapta(tabla_de_joc, i_start, j_start);
                    if(nr_casute_jos != -1){
                        int candidat = i_start + nr_casute_jos;
                        if(tabla_goala[candidat][j_start] == 1)
                            glow_groapa(latimea_ecranului, inaltimea_ecranului, candidat, j_start);
                        else
                            glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, candidat, j_start);
                    }
                    if(nr_casute_sus != -1){
                        int candidat = i_start - nr_casute_sus;
                        if(tabla_goala[candidat][j_start] == 1)
                            glow_groapa(latimea_ecranului, inaltimea_ecranului, candidat, j_start);
                        else
                            glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, candidat, j_start);
                    }
                    if(nr_casute_dreapta != -1){
                        int candidat = j_start + nr_casute_dreapta;
                        if(tabla_goala[i_start][candidat] == 1)
                            glow_groapa(latimea_ecranului, inaltimea_ecranului, i_start, candidat);
                        else
                            glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start, candidat);
                    }

                    if(nr_casute_stanga != -1){
                        int candidat = j_start - nr_casute_stanga;
                        if(tabla_goala[i_start][candidat] == 1)
                            glow_groapa(latimea_ecranului, inaltimea_ecranului, i_start, candidat);
                        else
                            glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start, candidat);
                    }
                    clearmouseclick(WM_LBUTTONDOWN);
                    while(true){
                        clearmouseclick(WM_LBUTTONDOWN);
                        get_casuta_tabla(latimea_ecranului, inaltimea_ecranului, i_dest, j_dest);
                        if(ismouseclick(WM_LBUTTONDOWN) && valid_pozitie(i_dest, j_dest)){
                            if(is_jos(i_start, j_start, i_dest, j_dest)){
                                int numar_casute = nr_casute_jos;
                                if(numar_casute && (numar_casute == i_dest-i_start)){
                                    muta_iepure_jos(tabla_de_joc, tabla_goala, i_start, j_start, numar_casute);
                                    deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                    clearmouseclick(WM_LBUTTONDOWN);
                                    goto new_move;
                                }
                            }
                            else if(is_sus(i_start, j_start, i_dest, j_dest)){
                                int numar_casute = nr_casute_sus;
                                if(numar_casute && (numar_casute == i_start-i_dest)){
                                    muta_iepure_sus(tabla_de_joc, tabla_goala, i_start, j_start, numar_casute);
                                    deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                    clearmouseclick(WM_LBUTTONDOWN);
                                    goto new_move;
                                }
                            }
                            else if(is_stanga(i_start, j_start, i_dest, j_dest)){
                                int numar_casute = nr_casute_stanga;
                                if(numar_casute && (numar_casute == j_start-j_dest)){
                                    muta_iepure_stanga(tabla_de_joc, tabla_goala, i_start, j_start, numar_casute);
                                    deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                    clearmouseclick(WM_LBUTTONDOWN);
                                    goto new_move;
                                }
                            }
                            else if(is_dreapta(i_start, j_start, i_dest, j_dest)){
                                int numar_casute = nr_casute_dreapta;
                                if(numar_casute && (numar_casute == j_dest-j_start)){
                                    muta_iepure_dreapta(tabla_de_joc, tabla_goala, i_start, j_start, numar_casute);
                                    deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                    clearmouseclick(WM_LBUTTONDOWN);
                                    goto new_move;
                                }
                            }
                            else{
                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                break;
                            }
                        }
                    }
                }
                else if(is_vulpe(tabla_de_joc, i_start, j_start) && ismouseclick(WM_LBUTTONDOWN) ){
                        if(sunet)
                            mciSendString("play sound/buton_selecteaza.mp3", NULL, 0, NULL);
                        clearmouseclick(WM_LBUTTONDOWN);
                        if(is_vulpe_orizontala(tabla_de_joc, i_start, j_start)){
                            glow_vulpe_orizontala(tabla_de_joc, latimea_ecranului, inaltimea_ecranului, i_start, j_start);
                            vector<int> mutari_stanga = valideaza_vulpe_orizontala_stanga(tabla_de_joc, i_start, j_start);
                            vector<int> mutari_dreapta = valideaza_vulpe_orizontala_dreapta(tabla_de_joc, i_start, j_start);

                            for(unsigned int i=0, k=0 ; i< mutari_stanga.size() ; ++i, ++k)
                                if(mutari_stanga[k] != -1){
                                    if(j_start != 0 && tabla_de_joc[i_start][j_start] == tabla_de_joc[i_start][j_start-1])
                                        glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start, j_start - mutari_stanga[k] - 1);
                                    else
                                        glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start, j_start - mutari_stanga[k]);
                                }

                            for(unsigned int i=0, k=0 ; i< mutari_dreapta.size() ; ++i, ++k)
                                if(mutari_dreapta[k] != -1){
                                    if(j_start != 0 && tabla_de_joc[i_start][j_start] == tabla_de_joc[i_start][j_start-1])
                                        glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start, j_start + mutari_dreapta[k]);
                                    else
                                        glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start, j_start + mutari_dreapta[k] + 1);
                                }
                            clearmouseclick(WM_LBUTTONDOWN);
                            while(true){
                                clearmouseclick(WM_LBUTTONDOWN);
                                get_casuta_tabla(latimea_ecranului, inaltimea_ecranului, i_dest, j_dest);
                                if(ismouseclick(WM_LBUTTONDOWN) && valid_pozitie(i_dest, j_dest)){
                                    if(is_stanga(i_start, j_start, i_dest, j_dest)){
                                        if(j_start != 0 && (tabla_de_joc[i_start][j_start] == tabla_de_joc[i_start][j_start-1])){
                                            int numar_casute = j_start - j_dest -1;
                                            if(numar_casute && miscare_valida_vulpe(mutari_stanga, numar_casute)){
                                                muta_vulpe_orizontala_stanga(tabla_de_joc, i_start, j_start, numar_casute);
                                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                                clearmouseclick(WM_LBUTTONDOWN);
                                                goto new_move;
                                            }
                                        }
                                        else{
                                            int numar_casute = j_start - j_dest;
                                            if(numar_casute && miscare_valida_vulpe(mutari_stanga, numar_casute)){
                                                muta_vulpe_orizontala_stanga(tabla_de_joc, i_start, j_start, numar_casute);
                                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                                clearmouseclick(WM_LBUTTONDOWN);
                                                goto new_move;
                                            }
                                        }
                                    }
                                    else if(is_dreapta(i_start, j_start, i_dest, j_dest)){
                                        if(j_start != 4 &&(tabla_de_joc[i_start][j_start] == tabla_de_joc[i_start][j_start+1])){
                                            int numar_casute = j_dest - j_start - 1;
                                            if(numar_casute && miscare_valida_vulpe(mutari_dreapta, numar_casute)){
                                                muta_vulpe_orizontala_dreapta(tabla_de_joc, i_start, j_start, numar_casute);
                                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                                clearmouseclick(WM_LBUTTONDOWN);
                                                goto new_move;
                                            }
                                        }
                                        else{
                                            int numar_casute = j_dest - j_start;
                                            if(numar_casute && miscare_valida_vulpe(mutari_dreapta, numar_casute)){
                                                muta_vulpe_orizontala_dreapta(tabla_de_joc, i_start, j_start, numar_casute);
                                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                                clearmouseclick(WM_LBUTTONDOWN);
                                                goto new_move;
                                            }
                                        }
                                    }
                                    else{
                                        deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                        break;
                                    }
                                }
                            }
                        }
                        else{
                            glow_vulpe_verticala(tabla_de_joc, latimea_ecranului, inaltimea_ecranului, i_start, j_start);
                            vector<int> mutari_sus = valideaza_vulpe_verticala_sus(tabla_de_joc, i_start, j_start);
                            vector<int> mutari_jos = valideaza_vulpe_verticala_jos(tabla_de_joc, i_start, j_start);

                            for(unsigned int i=0, k=0 ; i< mutari_sus.size() ; ++i, ++k)
                                if(mutari_sus[k] != -1){
                                    if(i_start != 0 && tabla_de_joc[i_start][j_start] == tabla_de_joc[i_start-1][j_start])
                                        glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start - mutari_sus[k] - 1, j_start);
                                    else
                                        glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start - mutari_sus[k], j_start);
                                }

                            for(unsigned int i=0, k=0 ; i< mutari_jos.size() ; ++i, ++k)
                                if(mutari_jos[k] != -1){
                                    if(i_start != 0 && tabla_de_joc[i_start][j_start] == tabla_de_joc[i_start-1][j_start])
                                        glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start + mutari_jos[k], j_start);
                                    else
                                        glow_casuta_libera(latimea_ecranului, inaltimea_ecranului, i_start + mutari_jos[k] + 1, j_start);
                                }
                            clearmouseclick(WM_LBUTTONDOWN);
                            while(true){
                                clearmouseclick(WM_LBUTTONDOWN);
                                get_casuta_tabla(latimea_ecranului, inaltimea_ecranului, i_dest, j_dest);
                                if(ismouseclick(WM_LBUTTONDOWN) && valid_pozitie(i_dest, j_dest)){
                                    if(is_sus(i_start, j_start, i_dest, j_dest)){
                                        if(i_start != 0 && (tabla_de_joc[i_start][j_start] == tabla_de_joc[i_start-1][j_start])){
                                            int numar_casute = i_start - i_dest - 1;
                                            if(numar_casute && miscare_valida_vulpe(mutari_sus, numar_casute)){
                                                muta_vulpe_verticala_sus(tabla_de_joc, i_start, j_start, numar_casute);
                                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                                clearmouseclick(WM_LBUTTONDOWN);
                                                goto new_move;
                                            }
                                        }
                                        else{
                                            int numar_casute = i_start - i_dest;
                                            if(numar_casute && miscare_valida_vulpe(mutari_sus, numar_casute)){
                                                muta_vulpe_verticala_sus(tabla_de_joc, i_start, j_start, numar_casute);
                                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                                clearmouseclick(WM_LBUTTONDOWN);
                                                goto new_move;
                                            }
                                        }
                                    }
                                    else if(is_jos(i_start, j_start, i_dest, j_dest)){
                                        if(i_start != 4 &&(tabla_de_joc[i_start+1][j_start] == tabla_de_joc[i_start][j_start])){
                                            int numar_casute = i_dest - i_start - 1;
                                            if(numar_casute && miscare_valida_vulpe(mutari_jos, numar_casute)){
                                                muta_vulpe_verticala_jos(tabla_de_joc, i_start, j_start, numar_casute);
                                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                                clearmouseclick(WM_LBUTTONDOWN);
                                                goto new_move;
                                            }
                                        }
                                        else{
                                            int numar_casute = i_dest - i_start;
                                            if(numar_casute && miscare_valida_vulpe(mutari_jos, numar_casute)){
                                                muta_vulpe_verticala_jos(tabla_de_joc, i_start, j_start, numar_casute);
                                                deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                                clearmouseclick(WM_LBUTTONDOWN);
                                                goto new_move;
                                            }
                                        }
                                    }
                                    else{
                                        deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
                                        break;
                                    }
                                }
                            }
                        }
                }
        }
        else if(tip_actiune_mouse_choose(latimea_ecranului, inaltimea_ecranului) == 1 && ismouseclick(WM_LBUTTONDOWN)){
            if(sunet)
                mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
            running = false;
            break;
        }
        else if(tip_actiune_mouse_choose(latimea_ecranului, inaltimea_ecranului) == 2 && ismouseclick(WM_LBUTTONDOWN)){
            exit_game();
        }
    }
    if(running){
        if(limba == 1)
            readimagefile("jpg/fundal_tabla/level_passed_choose_romana.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else if(limba == 2)
            readimagefile("jpg/fundal_tabla/level_passed_choose.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else if(limba == 3)
            readimagefile("jpg/fundal_tabla/level_passed_choose_franceza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else
            readimagefile("jpg/fundal_tabla/level_passed_choose_japoneza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        Sleep(1000);
    }

}
void start_choose(int latimea_ecranului, int inaltimea_ecranului, bool sunet, int limba, int nivel){
    int tabla_de_joc[5][5] = {}, tabla_goala[5][5] = {};

    std::string s = "nivel";
    char buffer[100] = {};
    std::string k = itoa(nivel, buffer, 10);
    std::string rez = s + "_" + k + ".in";
    initializeaza_tabla_de_joc(tabla_de_joc, rez.c_str());
    initializeaza_tabla_goala(tabla_goala);

    int running = 1;
    if(limba == 1)
        readimagefile("jpg/fundal_tabla/choose_romana.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else if(limba == 2)
        readimagefile("jpg/fundal_tabla/choose_engleza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else if(limba == 3)
        readimagefile("jpg/fundal_tabla/choose_franceza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else
        readimagefile("jpg/fundal_tabla/choose_japoneza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);

    deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
    if(nivel < 10){
        char buff[2] = {};
        double x = latimea_ecranului / 2.12666666666666667;
        double y = inaltimea_ecranului / 17.5166666666666667;
        itoa(nivel, buff, 10);
        double dimensiune_scris = latimea_ecranului / 239.25;
        settextstyle(4, 0, dimensiune_scris);
        outtextxy(x, y, buff);
    }
    else{
        char buff_1[2] = {}, buff_2[2] = {};
        itoa(nivel/10, buff_1, 10);
        itoa(nivel%10, buff_2, 10);
        double dimensiune_scris = latimea_ecranului / 239.25;
        settextstyle(4, 0, dimensiune_scris);
        double x1 = latimea_ecranului / 2.22558139534883721;
        double y1 = inaltimea_ecranului / 17.5166666666666667;
        double x2 = latimea_ecranului / 2.036170212766;
        double y2 = inaltimea_ecranului / 17.5166666666666667;
        outtextxy(x1, y1, buff_1);
        outtextxy(x2, y2, buff_2);
    }
    while(running){
        clearmouseclick(WM_LBUTTONDOWN);
        if(ismouseclick(WM_LBUTTONDOWN)){
            if(tip_actiune_mouse_choose(latimea_ecranului, inaltimea_ecranului) == 3 && ismouseclick(WM_LBUTTONDOWN)){
                if(sunet)
                    mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                joaca_nivel_choose(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului, sunet, limba, nivel, running);
                break;
            }
            else if(tip_actiune_mouse_choose(latimea_ecranului, inaltimea_ecranului) == 4 && ismouseclick(WM_LBUTTONDOWN)){
                if(sunet)
                    mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                solve_game(tabla_de_joc, tabla_goala, nivel, latimea_ecranului, inaltimea_ecranului);
                break;
            }
            else if(tip_actiune_mouse_choose(latimea_ecranului, inaltimea_ecranului) == 1 && ismouseclick(WM_LBUTTONDOWN)){
                if(sunet)
                    mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                running = false;
                break;
            }
            else if(tip_actiune_mouse_choose(latimea_ecranului, inaltimea_ecranului) == 2 && ismouseclick(WM_LBUTTONDOWN)){
                exit_game();
            }
        }
    }
}
