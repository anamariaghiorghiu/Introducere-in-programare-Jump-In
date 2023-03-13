#include "vector"

using std::vector;

bool is_vulpe(int tabla[5][5], int poz_1, int poz_2){
/*functie care verifica daca un element este vulpe,
input - ints: matricea si pozitia elementului,
output - bool: 1 pentru adevarat si 0 pentru fals.
*/
    return tabla[poz_1][poz_2] > 3;
}

bool is_vulpe_orizontala(int tabla[5][5], int poz_1, int poz_2){
/*functie care verifica daca un element de tip vulpe este pus pe tabla
pe orizontala,
input - ints: matricea si pozitia elementului,
output - bool: 1 pentru adevarat si 0 pentru fals.
*/
    if(poz_2 > 0)
        if(tabla[poz_1][poz_2-1] == tabla[poz_1][poz_2])
            return true;
    if(poz_2 < 4)
        if(tabla[poz_1][poz_2+1] == tabla[poz_1][poz_2])
            return true;
    return false;

}

bool is_vulpe_verticala(int tabla[5][5], int poz_1, int poz_2){
/*functie care verifica daca un element de tip vulpe este pus pe tabla
pe verticala,
input - ints: matricea si pozitia elementului,
output - bool: 1 pentru adevarat si 0 pentru fals.
*/
    if(poz_1 > 0)
        if(tabla[poz_1-1][poz_2] == tabla[poz_1][poz_2])
            return true;
    if(poz_1 < 4)
        if(tabla[poz_1+1][poz_2] == tabla[poz_1][poz_2])
            return true;
    return false;
}

void muta_vulpe_orizontala_dreapta(int tabla[5][5], int poz_1, int poz_2, int nr_poz){
/*functie care muta un element de tip vulpe la dreapta cu un numar dat de casute,
input - ints: matricea de joc, pozitia elementului si numarul de casute.
*/
        if(poz_2 == 0 || tabla[poz_1][poz_2+1] == tabla[poz_1][poz_2])
            ++poz_2;
        tabla[poz_1][poz_2+nr_poz] = tabla[poz_1][poz_2];
        tabla[poz_1][poz_2+nr_poz-1] = tabla[poz_1][poz_2];
        for(int i=0 ; i< nr_poz ; ++i)
            tabla[poz_1][poz_2+i-1] = 0;
}

void muta_vulpe_orizontala_stanga(int tabla[5][5], int poz_1, int poz_2, int nr_poz){
/*functie care muta un element de tip vulpe la stanga cu un numar dat de casute,
input - ints: matricea de joc, pozitia elementului si numarul de casute.
*/
        if(poz_2 == 4 || tabla[poz_1][poz_2-1] == tabla[poz_1][poz_2])
            --poz_2;
        tabla[poz_1][poz_2-nr_poz] = tabla[poz_1][poz_2];
        tabla[poz_1][poz_2-nr_poz+1] = tabla[poz_1][poz_2];
        for(int i=0 ; i< nr_poz ; ++i)
            tabla[poz_1][poz_2-i+1] = 0;
}

void muta_vulpe_verticala_jos(int tabla[5][5], int poz_1, int poz_2, int nr_poz){
/*functie care muta un element de tip vulpe in jos cu un numar dat de casute,
input - ints: matricea de joc, pozitia elementului si numarul de casute.
*/
        if(poz_1 == 0 || tabla[poz_1+1][poz_2] == tabla[poz_1][poz_2])
            ++poz_1;
        tabla[poz_1+nr_poz][poz_2] = tabla[poz_1][poz_2];
        tabla[poz_1+nr_poz-1][poz_2] = tabla[poz_1][poz_2];
        for(int i=0 ; i< nr_poz ; ++i)
            tabla[poz_1+i-1][poz_2] = 0;
}

void muta_vulpe_verticala_sus(int tabla[5][5], int poz_1, int poz_2, int nr_poz){
/*functie care muta un element de tip vulpe in sus cu un numar dat de casute,
input - ints: matricea de joc, pozitia elementului si numarul de casute.
*/
        if(poz_1 == 4 || tabla[poz_1-1][poz_2] == tabla[poz_1][poz_2])
           --poz_1;
        tabla[poz_1-nr_poz][poz_2] = tabla[poz_1][poz_2];
        tabla[poz_1-nr_poz+1][poz_2] = tabla[poz_1][poz_2];
        for(int i=0 ; i< nr_poz ; ++i)
            tabla[poz_1-i+1][poz_2] = 0;
}

vector<int> valideaza_vulpe_orizontala_dreapta(int tabla[5][5], int poz_1, int poz_2){
/*functie care returneaza numarul de casute posibile cu care putem muta o vulpe orizontala la dreapta,
input - ints: matricea de joc si pozitia elementului,
output - un vector de ints: o multime de numere, reprezentand valorile posibile.
*/
    vector<int> valori;
    int mutari = 0;
    for(int i=poz_2+1 ; i< 5 ; ++i)
        if(tabla[poz_1][i] == tabla[poz_1][poz_2])
            mutari = 0;
        else if(tabla[poz_1][i] == 0)
            mutari++, valori.push_back(mutari);
        else
            break;
    if(valori.size() == 0)
        valori.push_back(-1);
    return valori;
}

vector<int> valideaza_vulpe_orizontala_stanga(int tabla[5][5], int poz_1, int poz_2){
/*functie care returneaza numarul de casute posibile cu care putem muta o vulpe orizontala la stanga,
input - ints: matricea de joc si pozitia elementului,
output - un vector de ints: o multime de numere, reprezentand valorile posibile.
*/
    vector<int> valori;
    int mutari = 0;
    for(int i=poz_2-1 ; i>=0 ; --i)
        if(tabla[poz_1][i] == tabla[poz_1][poz_2])
            mutari = 0;
        else if(tabla[poz_1][i] == 0)
            mutari++, valori.push_back(mutari);
        else
            break;
    if(valori.size() == 0)
        valori.push_back(-1);
    return valori;
}

vector<int> valideaza_vulpe_verticala_jos(int tabla[5][5], int poz_1, int poz_2){
/*functie care returneaza numarul de casute posibile cu care putem muta o vulpe verticala in jos,
input - ints: matricea de joc si pozitia elementului,
output - un vector de ints: o multime de numere, reprezentand valorile posibile.
*/
    vector<int> valori;
    int mutari = 0;
    for(int i=poz_1+1 ; i< 5 ; ++i)
        if(tabla[i][poz_2] == tabla[poz_1][poz_2])
            mutari = 0;
        else if(tabla[i][poz_2] == 0)
            mutari++, valori.push_back(mutari);
        else
            break;
    if(valori.size() == 0)
        valori.push_back(-1);
    return valori;
}

vector<int> valideaza_vulpe_verticala_sus(int tabla[5][5], int poz_1, int poz_2){
/*functie care returneaza numarul de casute posibile cu care putem muta o vulpe verticala in sus,
input - ints: matricea de joc si pozitia elementului,
output - un vector de ints: o multime de numere, reprezentand valorile posibile.
*/
    vector<int> valori;
    int mutari = 0;
    for(int i=poz_1-1 ; i>=0 ; --i)
        if(tabla[i][poz_2] == tabla[poz_1][poz_2])
            mutari = 0;
        else if(tabla[i][poz_2] == 0)
            mutari++, valori.push_back(mutari);
        else
            break;
    if(valori.size() == 0)
        valori.push_back(-1);
    return valori;
}
