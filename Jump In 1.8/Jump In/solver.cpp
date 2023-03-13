#include "iostream"
#include "tabla_de_joc.h"
#include "tabla_goala.h"
#include "casute_libere.h"
#include "groapa.h"
#include "iepure.h"
#include "ciuperca.h"
#include "vulpe.h"
#include "assert.h"
#include "all_tests.h"
#include "time.h"
#include "cstdlib"
#include "utility"
#include "windows.h"
#include "game_over_conditions.h"
#include "GUI.h"
#include "vector"
#include "fstream"


void copy_tabla(int tabla_originala[5][5], int tabla_copie[5][5])
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            tabla_copie[i][j]=tabla_originala[i][j];
}
bool table_egale(int tabla1[5][5], int tabla2[5][5])
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
           if(tabla1[i][j]!=tabla2[i][j])
                return false;
    return true;
}

void next_move(int tabla_de_joc[5][5], int tabla_goala[5][5], int nivel, int latimea_ecranului, int inaltimea_ecranului)
 {
        int matrice_fis[5][5];
        int matrice_next[5][5];

        std::string s = "nivel_solutie";
        char buffer[100] = {};
        std::string k = itoa(nivel, buffer, 10);
        std::string file_name = s + "_" + k + ".in";

        char blank[50];
        std::ifstream file_in(file_name.c_str());
        file_in.clear();
        file_in.seekg(0, file_in.beg);

        while(table_egale(tabla_de_joc,matrice_fis) == false)
        {
            for(int i=0 ; i< 5 ; ++i)
                for(int j=0 ; j< 5 ; ++j)
                    file_in >> matrice_fis[i][j];
            file_in>>blank;
        }

        for(int i=0 ; i< 5 ; ++i)
                for(int j=0 ; j< 5 ; ++j)
                    file_in >> matrice_next[i][j];

        copy_tabla(matrice_next, tabla_de_joc);
        deseneaza_tabla(tabla_de_joc, tabla_goala, latimea_ecranului, inaltimea_ecranului);
        file_in.close();
}

void solve_game(int tabla_de_joc[5][5], int tabla_goala[5][5], int nivel, int latimea_ecranului, int inaltimea_ecranului)
{
    int matrice_solutie[5][5];
    char blank[50];

    std::string s = "nivel_solutie";
    char buffer[100] = {};
    std::string k = itoa(nivel, buffer, 10);
    std::string file_name = s + "_" + k + ".in";

    std::ifstream file_in(file_name.c_str());
    file_in.clear();
    file_in.seekg(0, file_in.beg);
    //retine solutia in matrice_solutie
    while(strcmp(blank, "end") != 0)
    {
        for(int i=0 ; i< 5 ; ++i)
            for(int j=0 ; j< 5 ; ++j)
                file_in >> matrice_solutie[i][j];
        file_in>>blank;
    }
    file_in.close();

    do
    {
        Sleep(500);
        next_move(tabla_de_joc, tabla_goala, nivel, latimea_ecranului, inaltimea_ecranului);

    }
    while(table_egale(tabla_de_joc,matrice_solutie) == false);
    Sleep(1000);
}

