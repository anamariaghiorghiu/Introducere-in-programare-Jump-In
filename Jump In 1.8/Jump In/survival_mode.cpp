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
#include "thread"
#include "cstring"

int niveluri_rezolvate = 0;
bool timer_running = 1;
int limba_timer = 1;
void show_time_up(int latimea_ecranului, int inaltimea_ecranului, int limba){
    timer_running = false;
    if(limba_timer == 1)
        readimagefile("jpg/time_up/timesup_romana.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else if(limba_timer == 2)
        readimagefile("jpg/time_up/timesup_engleza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else if(limba_timer == 3)
        readimagefile("jpg/time_up/timesup_franceza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else
        readimagefile("jpg/time_up/timesup_japoneza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);

    double dimensiune_scris =  latimea_ecranului / 191.4;

    if(niveluri_rezolvate < 10){
        std::string s = std::to_string(niveluri_rezolvate);
        char *niv;
        strcpy(niv,(char*)s.c_str());
        double x1 = latimea_ecranului / 2.0986842105263157894736;
        double y1 = inaltimea_ecranului / 1.79658119658119658119;
        settextstyle(4, 0, dimensiune_scris);
        outtextxy(x1, y1, niv);
    }
    else{
        int prima_cifra = niveluri_rezolvate / 10;
        int a_doua_cifra = niveluri_rezolvate % 10;

        std::string s1 = std::to_string(prima_cifra);
        std::string s2 = std::to_string(a_doua_cifra);

        char niv_1[2], niv_2[2];
        niv_1[0] = s1[0], niv_2[0] = s2[0];
        niv_1[1] = '\0', niv_2[1] = '\0';

        //strcpy(niv_1, s1.c_str());
        //strcpy(niv_2, s2.c_str());

        double x1 = latimea_ecranului / 2.1986842105263157894736;
        double y1 = inaltimea_ecranului / 1.79658119658119658119;

        double x2 = latimea_ecranului / 1.8986842105263157894736;
        double y2 = inaltimea_ecranului / 1.79658119658119658119;

        settextstyle(4, 0, dimensiune_scris);
        outtextxy(x1, y1, niv_1);
        settextstyle(4, 0, dimensiune_scris);
        outtextxy(x2, y2, niv_2);
    }
    Sleep(5000);
}
void timer(vector<int> dimensiuni)
{
    int latimea_ecranului = dimensiuni[0];
    int inaltimea_ecranului = dimensiuni[1];
    int minute = dimensiuni[2];
    int secunde = dimensiuni[3];

    double x1 = latimea_ecranului / 16.312;
    double y1 = inaltimea_ecranului / 1.136216216216216216;
    double x2 = latimea_ecranului / 12.76;
    double y2 = inaltimea_ecranului / 1.136216216216216216;
    double x3 = latimea_ecranului / 10.9371428571428571428;
    double y3 = inaltimea_ecranului / 1.1362162162162162162;
    double dimensiune_scris =  latimea_ecranului / 382.8;
    settextstyle(4, 0, dimensiune_scris);

    while(timer_running)
    {
        std::string s = std::to_string(minute);
        char *chr_m;
        strcpy(chr_m,(char*)s.c_str());
        outtextxy(x1, y1, chr_m);

        outtextxy(x2, y2, ":");

        s = std::to_string(secunde);
        char *chr_s;
        strcpy(chr_s,(char*)s.c_str());
        if(secunde < 10)
            chr_s[1] = chr_s[0], chr_s[0] = '0';

        outtextxy(x3, y3, chr_s);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        secunde --;
        if(secunde == 0 && minute == 0)
        {
            show_time_up(latimea_ecranului, inaltimea_ecranului, limba_timer);
            exit_game();
        }

        if(secunde < 0)
        {
            secunde = 59;
            minute--;
        }
    }

}

void joaca_nivel_survival(int latimea_ecranului, int inaltimea_ecranului, bool sunet, int limba, int nivel, int& running, int minute, int secunde){
    if(limba == 1)
        readimagefile("jpg/fundal_tabla/survival_romana.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else if(limba == 2)
        readimagefile("jpg/fundal_tabla/survival_engleza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else if(limba == 3)
        readimagefile("jpg/fundal_tabla/survival_franceza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
    else
        readimagefile("jpg/fundal_tabla/survival_japoneza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);

    int tabla_de_joc[5][5] = {}, tabla_goala[5][5] = {};
    int nr_casute_sus = -1, nr_casute_jos = -1, nr_casute_stanga = -1, nr_casute_dreapta = -1;
    std::string s = "nivel";
    std::string k = std::to_string(nivel);
    std::string rez = s + "_" + k + ".in";

    initializeaza_tabla_de_joc(tabla_de_joc, rez.c_str());
    initializeaza_tabla_goala(tabla_goala);
    deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);

    limba_timer = limba;
    timer_running = true;
    vector<int> dimens;
    dimens.push_back(latimea_ecranului);
    dimens.push_back(inaltimea_ecranului);
    dimens.push_back(minute);
    dimens.push_back(secunde);
    std::thread t1(timer, dimens);

    while(!toti_iepurii_in_gropi(tabla_de_joc, tabla_goala) && timer_running){
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
        else if(tip_actiune_mouse_casual(latimea_ecranului, inaltimea_ecranului) == 1 && ismouseclick(WM_LBUTTONDOWN)){
            if(sunet)
                mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
            running = false;
            timer_running = false;
            t1.join();
            break;
        }
        else if(tip_actiune_mouse_casual(latimea_ecranului, inaltimea_ecranului) == 2 && ismouseclick(WM_LBUTTONDOWN)){
            exit_game();
        }
    }
    if(running){
        timer_running = false;
        t1.join();
        if(limba == 1)
            readimagefile("jpg/fundal_tabla/level_passed_survival_romana.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else if(limba == 2)
            readimagefile("jpg/fundal_tabla/level_passed_survival_engleza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else if(limba == 3)
            readimagefile("jpg/fundal_tabla/level_passed_survival_franceza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else
            readimagefile("jpg/fundal_tabla/level_passed_survival_japoneza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);

        Sleep(1000);
    }

}

void start_survival(int latimea_ecranului, int inaltimea_ecranului, bool sunet, int limba){
    niveluri_rezolvate = 0;
    int running = true;
    int secunde, minute;
    int nivel_de_rezolvat = 20;
    while(running){
        srand(time(NULL));
        if(nivel_de_rezolvat < 25)
            secunde = 30, minute = 0;
        else if(nivel_de_rezolvat < 30)
            secunde = 50, minute = 0;
        else if(nivel_de_rezolvat < 40)
            secunde = 20, minute = 1;
        else if(nivel_de_rezolvat < 50)
            secunde = 50, minute = 1;
        else if(nivel_de_rezolvat == 60)
            secunde = 10, minute = 3;
        else
            minute = 2, secunde = 10;
        joaca_nivel_survival(latimea_ecranului, inaltimea_ecranului, sunet, limba, nivel_de_rezolvat, running, minute, secunde);
        nivel_de_rezolvat ++;
        niveluri_rezolvate ++;
    }
}
