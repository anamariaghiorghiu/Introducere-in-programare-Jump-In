#pragma once

bool is_iepure(int tabla[5][5], int poz_1, int poz_2);

void muta_iepure_sus(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz);
void muta_iepure_jos(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz);
void muta_iepure_stanga(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz);
void muta_iepure_dreapta(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz);

int valideaza_iepure_sus(int tabla[5][5], int poz_1, int poz_2);
int valideaza_iepure_jos(int tabla[5][5], int poz_1, int poz_2);
int valideaza_iepure_stanga(int tabla[5][5], int poz_1, int poz_2);
int valideaza_iepure_dreapta(int tabla[5][5], int poz_1, int poz_2);

