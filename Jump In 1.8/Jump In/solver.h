#pragma once

bool returneaza_iepure_sus(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz, int &poz_1_new, int &poz_2_new);
bool returneaza_iepure_jos(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz, int &poz_1_new, int &poz_2_new);
bool returneaza_iepure_stanga(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz, int &poz_1_new, int &poz_2_new);
bool returneaza_iepure_dreapta(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz, int &poz_1_new, int &poz_2_new);
void copy_tabla(int tabla_originala[5][5], int tabla_copie[5][5]);
void repara_tabla(int tabla_de_joc[5][5], int tabla_goala[5][5], int i_old, int j_old, int i_new, int j_new);
vector<int> pozitii_vulpe(int tabla[5][5]);
bool table_egale(int tabla1[5][5], int tabla2[5][5]);
void next_move(int tabla_de_joc[5][5], int tabla_goala[5][5], int nivel, int latimea_ecranului, int inaltimea_ecranului);
void solve_game(int tabla_de_joc[5][5], int tabla_goala[5][5], int nivel, int latimea_ecranului, int inaltimea_ecranului);




