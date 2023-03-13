#pragma once

void get_casuta_tabla(int latimea_ecranului, int inaltimea_ecranului, int& poz_1, int& poz_2);
void get_coordonate(int latimea_ecranului, int inaltimea_ecranului, int poz_1, int poz_2, double& x1, double& y1, double& x2, double& y2);
void deseneaza_tabla(int tabla[5][5], int tabla_goala[5][5], int latimea_ecranului, int inaltimea_ecranului);
void glow_iepure(int latimea_ecranului, int inaltimea_ecranului, int i, int j);
void glow_iepure_groapa(int latimea_ecranului, int inaltimea_ecranului, int i, int j);
void glow_casuta_libera(int latimea_ecranului, int inaltimea_ecranului, int i, int j);
void glow_groapa(int latimea_ecranului, int inaltimea_ecranului, int i, int j);
void glow_vulpe_orizontala(int tabla_de_joc[5][5], int latimea_ecranului, int inaltimea_ecranului, int i, int j);
void glow_vulpe_verticala(int tabla_de_joc[5][5], int latimea_ecranului, int inaltimea_ecranului, int i, int j);
