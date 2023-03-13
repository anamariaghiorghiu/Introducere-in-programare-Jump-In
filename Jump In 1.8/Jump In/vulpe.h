#pragma once
#include "vector"
using std::vector;

bool is_vulpe(int tabla[5][5], int poz_1, int poz_2);
bool is_vulpe_orizontala(int tabla[5][5], int poz_1, int poz_2);
bool is_vulpe_verticala(int tabla[5][5], int poz_1, int poz_2);

void muta_vulpe_orizontala_dreapta(int tabla[5][5], int poz_1, int poz_2, int nr_poz);
void muta_vulpe_orizontala_stanga(int tabla[5][5], int poz_1, int poz_2, int nr_poz);
void muta_vulpe_verticala_sus(int tabla[5][5], int poz_1, int poz_2, int nr_poz);
void muta_vulpe_verticala_jos(int tabla[5][5], int poz_1, int poz_2, int nr_poz);


vector<int> valideaza_vulpe_orizontala_dreapta(int tabla[5][5], int poz_1, int poz_2);
vector<int> valideaza_vulpe_orizontala_stanga(int tabla[5][5], int poz_1, int poz_2);
vector<int> valideaza_vulpe_verticala_sus(int tabla[5][5], int poz_1, int poz_2);
vector<int> valideaza_vulpe_verticala_jos(int tabla[5][5], int poz_1, int poz_2);


