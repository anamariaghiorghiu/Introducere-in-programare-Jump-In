bool is_iepure(int tabla[5][5], int poz_1, int poz_2){
/*functie bool care verifica daca un element dintr-o matrice este iepure,
input - ints: matricea si coordonatele elementului,
output - bool: 1 pentru adevarat, 0 pentru fals.
*/
    return tabla[poz_1][poz_2] == 3;
}

void muta_iepure_sus(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz){
/*functie care muta un iepure in sus cu un numar de casute dat,
input - ints: matricea initiala, matricea reprezentant tabla goala de joc, pozitiile elementului
si numarul de castute pe care iepurele le va sari.
*/
    tabla[poz_1-nr_poz][poz_2] = 3;
    tabla[poz_1][poz_2] = tabla_goala[poz_1][poz_2];
}

void muta_iepure_jos(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz){
/*functie care muta un iepure in jos cu un numar de casute dat,
input - ints: matricea initiala, matricea reprezentant tabla goala de joc, pozitiile elementului
si numarul de castute pe care iepurele le va sari
*/
    tabla[poz_1+nr_poz][poz_2] = 3;
    tabla[poz_1][poz_2] = tabla_goala[poz_1][poz_2];
}

void muta_iepure_stanga(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz){
/*functie care muta un iepure la stanga cu un numar de casute dat,
input - ints: matricea initiala, matricea reprezentant tabla goala de joc, pozitiile elementului
si numarul de castute pe care iepurele le va sari.
*/
    tabla[poz_1][poz_2-nr_poz] = 3;
    tabla[poz_1][poz_2] = tabla_goala[poz_1][poz_2];
}

void muta_iepure_dreapta(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz){
/*functie care muta un iepure la dreapta cu un numar de casute dat,
input - ints: matricea initiala, matricea reprezentant tabla goala de joc, pozitiile elementului
si numarul de castute pe care iepurele le va sari.
*/
    tabla[poz_1][poz_2+nr_poz] = 3;
    tabla[poz_1][poz_2] = tabla_goala[poz_1][poz_2];
}

int valideaza_iepure_sus(int tabla[5][5], int poz_1, int poz_2){
/*functie care valideaza cate casute se poate muta un iepure in susul tablei pentru a constitui o miscare legala,
input - ints: matricea si pozitiile la care se afla elementul,
output - int: returneaza numarul de casute.
*/
    if(poz_1 == 0)
        return -1;
    int mutare = 0;
    while(poz_1 > 0 && tabla[poz_1][poz_2] > 1)
        ++mutare, --poz_1;
    if(tabla[poz_1][poz_2] < 2 && mutare > 1)
        return mutare;
    else
        return -1;
}

int valideaza_iepure_jos(int tabla[5][5], int poz_1, int poz_2){
/*functie care valideaza cate casute se poate muta un iepure in josul tablei pentru a constitui o miscare legala,
input - ints: matricea si pozitiile la care se afla elementul,
output - int: returneaza numarul de casute.
*/
    if(poz_1 == 4)
        return -1;
    int mutare = 0;
    while(poz_1 < 4 && tabla[poz_1][poz_2] > 1)
        ++mutare, ++poz_1;
    if(tabla[poz_1][poz_2] < 2 && mutare > 1)
        return mutare;
    else
        return -1;
}

int valideaza_iepure_stanga(int tabla[5][5], int poz_1, int poz_2){
/*functie care valideaza cate casute se poate muta un iepure in stanga tablei pentru a constitui o miscare legala,
input - ints: matricea si pozitiile la care se afla elementul,
output - int: returneaza numarul de casute.
*/
    if(poz_2 == 0)
        return -1;
    int mutare = 0;
    while(poz_2 > 0 && tabla[poz_1][poz_2] > 1)
        ++mutare, --poz_2;
    if(tabla[poz_1][poz_2] < 2 && mutare > 1)
        return mutare;
    else
        return -1;
}

int valideaza_iepure_dreapta(int tabla[5][5], int poz_1, int poz_2){
/*functie care valideaza cate casute se poate muta un iepure in dreapta tablei pentru a constitui o miscare legala,
input - ints: matricea si pozitiile la care se afla elementul,
output - int: returneaza numarul de casute.
*/
    if(poz_2 == 4)
        return -1;
    int mutare = 0;
    while(poz_2 < 4 && tabla[poz_1][poz_2] > 1)
        ++mutare, ++poz_2;
    if(tabla[poz_1][poz_2] < 2 && mutare > 1)
        return mutare;
    else
        return -1;
}

