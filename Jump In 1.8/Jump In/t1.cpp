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

using std::cout;
using std::cin;


void afisare_tabla(int tabla[5][5])
{
    for(int i=0 ; i< 5 ; ++i)
    {
        for(int j=0 ; j< 5 ; ++j)
            cout << tabla[i][j] <<' ';
        cout << '\n';
    }
    cout << '\n';
}


bool returneaza_iepure_sus(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz, int &poz_1_new, int &poz_2_new){
    if(nr_poz == -1)
        return 0;
    tabla[poz_1-nr_poz][poz_2] = 3;
    tabla[poz_1][poz_2] = tabla_goala[poz_1][poz_2];
    poz_1_new = poz_1-nr_poz;
    poz_2_new = poz_2;
    return 1;
}
bool returneaza_iepure_jos(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz, int &poz_1_new, int &poz_2_new)
{
    if(nr_poz ==-1)
        return 0;
    tabla[poz_1+nr_poz][poz_2] = 3;
    tabla[poz_1][poz_2] = tabla_goala[poz_1][poz_2];
    poz_1_new = poz_1+nr_poz;
    poz_2_new = poz_2;
    return 1;
}
bool returneaza_iepure_stanga(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz, int &poz_1_new, int &poz_2_new)
{
    if(nr_poz ==-1)
        return 0;
    tabla[poz_1][poz_2-nr_poz] = 3;
    tabla[poz_1][poz_2] = tabla_goala[poz_1][poz_2];
    poz_1_new = poz_1;
    poz_2_new = poz_2-nr_poz;
    return 1;
}
bool returneaza_iepure_dreapta(int tabla[5][5], int tabla_goala[5][5], int poz_1, int poz_2, int nr_poz, int &poz_1_new, int &poz_2_new)
{
    if(nr_poz ==-1)
        return 0;
    tabla[poz_1][poz_2+nr_poz] = 3;
    tabla[poz_1][poz_2] = tabla_goala[poz_1][poz_2];
    poz_1_new = poz_1;
    poz_2_new = poz_2+nr_poz;
    return 1;
}

void copy_tabla(int tabla_originala[5][5], int tabla_copie[5][5])
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            tabla_copie[i][j]=tabla_originala[i][j];
}

/*
vector<int> pozitie_curenta_iepure(int tabla[5][5])
{
    vector<int> pozitii;
    for(int i=0 ; i< 5 ; ++i)
     for(int j=0 ; j< 5 ; ++j)
     {
         if (is_iepure(tabla,i,j))
         {
             pozitii.push_back(i);
             pozitii.push_back(j);
         }
     }
     return pozitii;
}

bool is_final(int tabla_goala[5][5], int i_iepure, int j_iepure)
{
    return is_groapa(tabla_goala, i_iepure, j_iepure);
}
*/void repara_tabla(int tabla_de_joc[5][5], int tabla_goala[5][5], int i_old, int j_old, int i_new, int j_new)
{
    tabla_de_joc[i_old][j_old] = tabla_goala[i_old][j_old];
    tabla_de_joc[i_new][j_new] = 3;
}

vector<int> pozitii_vulpe(int tabla[5][5])
{
    vector<int> pozitii;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(tabla[i][j] > 3)
            {

                //una dintre pozitiile vulpii
                pozitii.push_back(i);
                pozitii.push_back(j);
                //adaugam in vectorul de pozitii si numarul reprezentativ al vulpii (4,5,6..etc)
                pozitii.push_back(tabla[i][j]);

            }
    return pozitii;
}
/*
vector<int> iepuri_mutati;

bool verificare_mutare_deja_facuta(vector<int> mutare)
{
    for(int i=0; i<hint.size(); i++)
        if((hint[i][0]==mutare[2] && hint[i][1]==mutare[3]) || (hint[i][2] == mutare[2] && hint[i][3] == mutare[3]))
            return true;
    return false;
}

bool exista_mutari_posibile(int tabla_de_joc[5][5], int poz_i, int poz_j)
{
    if(valideaza_iepure_sus(tabla_de_joc, poz_i, poz_j) != -1)
        return true;
    if(valideaza_iepure_jos(tabla_de_joc, poz_i, poz_j) != -1)
        return true;
    if(valideaza_iepure_stanga(tabla_de_joc, poz_i, poz_j) != -1)
        return true;
    if(valideaza_iepure_dreapta(tabla_de_joc, poz_i, poz_j) != -1)
        return true;
    return false;
}

vector<int> get_mutari_posibile(int tabla_de_joc[5][5], int tabla_goala[5][5], int poz_i, int poz_j)
{
    int temp_newi = 0;
    int temp_newj = 0;
    vector<int> mutari;
    int copy_tabla_de_joc[5][5];
    copy_tabla(tabla_de_joc, copy_tabla_de_joc);
    if(returneaza_iepure_sus(copy_tabla_de_joc, tabla_goala, poz_i, poz_j, valideaza_iepure_sus(copy_tabla_de_joc, poz_i, poz_j),temp_newi,temp_newj))
    {
        mutari.push_back(temp_newi);
        mutari.push_back(temp_newj);
    }
    copy_tabla(tabla_de_joc, copy_tabla_de_joc);
    if(returneaza_iepure_jos(copy_tabla_de_joc, tabla_goala, poz_i, poz_j, valideaza_iepure_jos(copy_tabla_de_joc, poz_i, poz_j),temp_newi,temp_newj))
    {
        mutari.push_back(temp_newi);
        mutari.push_back(temp_newj);
    }
    copy_tabla(tabla_de_joc, copy_tabla_de_joc);
    if(returneaza_iepure_stanga(copy_tabla_de_joc, tabla_goala, poz_i, poz_j, valideaza_iepure_stanga(copy_tabla_de_joc, poz_i, poz_j),temp_newi,temp_newj))
    {
        mutari.push_back(temp_newi);
        mutari.push_back(temp_newj);
    }
    copy_tabla(tabla_de_joc, copy_tabla_de_joc);
    if(returneaza_iepure_dreapta(copy_tabla_de_joc, tabla_goala, poz_i, poz_j, valideaza_iepure_dreapta(copy_tabla_de_joc, poz_i, poz_j),temp_newi,temp_newj))
    {
        mutari.push_back(temp_newi);
        mutari.push_back(temp_newj);
    }
    return mutari;
}

int create_solution (int tabla_de_joc[5][5], int tabla_goala[5][5], int i_iepure, int j_iepure)
{

    int i_iepure_new = 0;
    int j_iepure_new = 0;

    if (is_final(tabla_goala, i_iepure, j_iepure))
    {
        iepuri_mutati.push_back(i_iepure);
        iepuri_mutati.push_back(j_iepure);
        return 1;
    }

    int copy_tabla_de_joc[5][5];
    copy_tabla(tabla_de_joc, copy_tabla_de_joc);
    if (returneaza_iepure_sus(copy_tabla_de_joc, tabla_goala, i_iepure, j_iepure, valideaza_iepure_sus(copy_tabla_de_joc, i_iepure, j_iepure),i_iepure_new,j_iepure_new))
    {
        vector<int> hint_curent;
        hint_curent.push_back(i_iepure);
        hint_curent.push_back(j_iepure);
        hint_curent.push_back(i_iepure_new);
        hint_curent.push_back(j_iepure_new);
        if(verificare_mutare_deja_facuta(hint_curent)==false)
        {

            hint.push_back(hint_curent);
            cout << hint_curent[0] << " " << hint_curent[1] << " " << hint_curent[2] << " " << hint_curent[3] << std::endl;
            afisare_tabla(copy_tabla_de_joc);
            if (create_solution(copy_tabla_de_joc, tabla_goala, i_iepure_new, j_iepure_new)==1)
                return 1;
        }
    }
    copy_tabla(tabla_de_joc, copy_tabla_de_joc);
    if (returneaza_iepure_stanga(copy_tabla_de_joc, tabla_goala, i_iepure, j_iepure, valideaza_iepure_stanga(copy_tabla_de_joc, i_iepure, j_iepure),i_iepure_new,j_iepure_new))
    {
        vector<int> hint_curent;
        hint_curent.push_back(i_iepure);
        hint_curent.push_back(j_iepure);
        hint_curent.push_back(i_iepure_new);
        hint_curent.push_back(j_iepure_new);
        if(verificare_mutare_deja_facuta(hint_curent)==false)
        {

            hint.push_back(hint_curent);
            cout << hint_curent[0] << " " << hint_curent[1] << " " << hint_curent[2] << " " << hint_curent[3] << std::endl;
            afisare_tabla(copy_tabla_de_joc);
            if (create_solution(copy_tabla_de_joc, tabla_goala, i_iepure_new, j_iepure_new)==1)
                return 1;
        }
    }
    copy_tabla(tabla_de_joc, copy_tabla_de_joc);
    if (returneaza_iepure_jos(copy_tabla_de_joc, tabla_goala, i_iepure, j_iepure, valideaza_iepure_jos(copy_tabla_de_joc, i_iepure, j_iepure),i_iepure_new,j_iepure_new))
    {
        vector<int> hint_curent;
        hint_curent.push_back(i_iepure);
        hint_curent.push_back(j_iepure);
        hint_curent.push_back(i_iepure_new);
        hint_curent.push_back(j_iepure_new);
        if(verificare_mutare_deja_facuta(hint_curent)==false)
        {

            hint.push_back(hint_curent);
            cout << hint_curent[0] << " " << hint_curent[1] << " " << hint_curent[2] << " " << hint_curent[3] << std::endl;
            afisare_tabla(copy_tabla_de_joc);
            if (create_solution(copy_tabla_de_joc, tabla_goala, i_iepure_new, j_iepure_new)==1)
                return 1;
        }
    }
    copy_tabla(tabla_de_joc, copy_tabla_de_joc);
    if (returneaza_iepure_dreapta(copy_tabla_de_joc, tabla_goala, i_iepure, j_iepure, valideaza_iepure_dreapta(copy_tabla_de_joc, i_iepure, j_iepure),i_iepure_new,j_iepure_new))
    {
        vector<int> hint_curent;
        hint_curent.push_back(i_iepure);
        hint_curent.push_back(j_iepure);
        hint_curent.push_back(i_iepure_new);
        hint_curent.push_back(j_iepure_new);
        if(verificare_mutare_deja_facuta(hint_curent)==false)
        {
            hint.push_back(hint_curent);
            cout << hint_curent[0] << " " << hint_curent[1] << " " << hint_curent[2] << " " << hint_curent[3] << std::endl;
            afisare_tabla(copy_tabla_de_joc);
            if (create_solution(copy_tabla_de_joc, tabla_goala, i_iepure_new, j_iepure_new)==1)
                return 1;
        }

    }
    if(hint.size())
        hint.pop_back();
    vector<int> iepuri_ramasi = pozitie_curenta_iepure(tabla_de_joc);

    //in cazul in care nu am reusit sa mutam iepurele curent intr-o groapa
    //dar avem alti iepuri pe tabla
    //incercam sa folosim ceilalti iepuri ca obstacole pentru a muta iepurele curent.
    bool solutie_gasita = 0;
    for(int i=0; i<iepuri_ramasi.size(); i+=2)
    {
        if(iepuri_ramasi[0] == i_iepure && iepuri_ramasi[1] == j_iepure)
            continue; //iepurele curent deci dam skip
        int copie_tabla_de_joc[5][5];
        copy_tabla(tabla_de_joc, copie_tabla_de_joc);
        while(exista_mutari_posibile(copie_tabla_de_joc, iepuri_ramasi[i], iepuri_ramasi[i+1]))
        {
            //to_do: salvare mutari deja facute
            vector<int> mutari_posibile = get_mutari_posibile(copie_tabla_de_joc, tabla_goala, iepuri_ramasi[i], iepuri_ramasi[i+1]);
            for(int j=0; j<mutari_posibile.size(); j+=2)
            {
                repara_tabla(copie_tabla_de_joc, tabla_goala, iepuri_ramasi[i], iepuri_ramasi[i+1], mutari_posibile[j], mutari_posibile[j+1]);
                if(create_solution(copie_tabla_de_joc, tabla_goala, i_iepure, j_iepure)==1)
                {
                    solutie_gasita = 1;
                    //to_do: salveaza solutia pentru indicii
                    break;
                }
            }
            if(solutie_gasita)
                break;
        }
        if(solutie_gasita)
                break;
    }
    return 0;
}
void solutie_toti_iepurii(int tabla_de_joc[5][5], int tabla_goala[5][5])
{
    vector<int> pozitii_iepure = pozitie_curenta_iepure(tabla_de_joc);
    for(int i=0; i<pozitii_iepure.size(); i++)
        cout << pozitii_iepure[i] << " ";
    cout << std::endl;
    //while(pozitii_iepure.size()>0)
        for(int i=0; i<pozitii_iepure.size(); i+=2)
        {
            afisare_tabla(tabla_de_joc);
            if(create_solution(tabla_de_joc, tabla_goala, pozitii_iepure[i], pozitii_iepure[i+1])==1)
            {
                repara_tabla(tabla_de_joc,tabla_goala, pozitii_iepure[i], pozitii_iepure[i+1], iepuri_mutati[iepuri_mutati.size()-2], iepuri_mutati[iepuri_mutati.size()-1]);
                pozitii_iepure.erase(pozitii_iepure.begin()+i, pozitii_iepure.begin()+i+1);
            }
        }
}*/
//ALGORITM CARE ITI ARATA URMATOARELE MUTARI (next move-hint/ solve game-solve)
bool table_egale(int tabla1[5][5], int tabla2[5][5])
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
           if(tabla1[i][j]!=tabla2[i][j])
                return false;
    return true;
}

void next_move(char nivel[], int tabla_de_joc[5][5], int tabla_goala[5][5])
 {

        int matrice_fis[5][5];
        int matrice_next[5][5];
        char blank[50];
        char file_name[] = "nivel_solutie_";

        strcat(file_name,nivel);
        strcat(file_name,".in");

        std::ifstream file_in(file_name);
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
        afisare_tabla(tabla_de_joc);
        file_in.close();
}

void solve_game(char nivel[], int tabla_de_joc[5][5], int tabla_goala[5][5])
{
    int matrice_solutie[5][5];
    char blank[50];
    char file_name[] = "nivel_solutie_";
    strcat(file_name,nivel);
    strcat(file_name,".in");
    std::ifstream file_in(file_name);
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
        Sleep(0);
        next_move(nivel, tabla_de_joc, tabla_goala);

    }
    while(table_egale(tabla_de_joc,matrice_solutie) == false);
}
//next move o apelam in test_UI cu next_move("2", tabla_de_joc, tabla_goala); unde 2 e nr niv
//la fel la solve game;

void test_UI()
{
    int tabla_de_joc[5][5] = {}, tabla_goala[5][5] = {};
    initializeaza_tabla_de_joc(tabla_de_joc, "test.in");
    initializeaza_tabla_goala(tabla_goala);
    afisare_tabla(tabla_de_joc);
   // next_move("1", tabla_de_joc,tabla_goala);
   // next_move("1", tabla_de_joc,tabla_goala);
    //solve_game("59", tabla_de_joc,tabla_goala);

   //ALGORITM CARE ITI DUCE MISCARILE INAPOI
    int tabla_initiala[5][5];
    copy_tabla(tabla_de_joc, tabla_initiala);
    vector<int> istoric;
    int i_iepure_new = 0;
    int j_iepure_new = 0;
    //executare comanda de mutare
    returneaza_iepure_sus(tabla_de_joc, tabla_goala, 2, 3, valideaza_iepure_sus(tabla_de_joc, 2, 3),i_iepure_new,j_iepure_new);
    //adaugam in vectorul de istoric mutarea:
    //adauga i_iepure_vechi
    istoric.push_back(2);
    //adauga j_iepure_vechi
    istoric.push_back(3);
    //adauga i_iepure_nou (pozitia unde a ajuns iepurele dupa mutare)
    istoric.push_back(i_iepure_new);
    //adauga j_iepure_nou
    istoric.push_back(j_iepure_new);
    //adaugam -1 in vector pentru iepure
    istoric.push_back(-1);
    int newi = i_iepure_new;
    int newj = j_iepure_new;
    afisare_tabla(tabla_de_joc);

    returneaza_iepure_stanga(tabla_de_joc, tabla_goala, newi, newj, valideaza_iepure_stanga(tabla_de_joc, newi, newj),i_iepure_new,j_iepure_new);
    istoric.push_back(newi);
    istoric.push_back(newj);
    istoric.push_back(i_iepure_new);
    istoric.push_back(j_iepure_new);
    istoric.push_back(-1);
    afisare_tabla(tabla_de_joc);

    //inainte de fiecare mutare a vulpii trebuie facut:
    //pozitii old
    vector<int> poz_vulpe;
    poz_vulpe.clear();
    poz_vulpe = pozitii_vulpe(tabla_de_joc);
    //specificam ca am adaugat vulpea in istoric (-2)
    istoric.push_back(-2);
    for(int i=0; i<poz_vulpe.size(); i++)
        istoric.push_back(poz_vulpe[i]);
    //mutare vulpe
    muta_vulpe_verticala_jos(tabla_de_joc, 2, 0, 1);
    //golim vectorul
    poz_vulpe.clear();
    //pozitii new
    poz_vulpe = pozitii_vulpe(tabla_de_joc);
    //specificam ca am adaugat vulpea in istoric (-2) -- pozitii noi
    istoric.push_back(-2);
    for(int i=0; i<poz_vulpe.size(); i++)
        istoric.push_back(poz_vulpe[i]);
    //specificam ca am adaugat vulpea in istoric (-2) -- finalul secventei din istoric unde gasim detaliile despre mutarea vulpii
    istoric.push_back(-2);
    afisare_tabla(tabla_de_joc);

    //inainte de fiecare mutare a vulpii trebuie facut:
    //pozitii old
    //vector<int> poz_vulpe;
    poz_vulpe.clear();
    poz_vulpe = pozitii_vulpe(tabla_de_joc);
    //specificam ca am adaugat vulpea in istoric (-2)
    istoric.push_back(-2);
    for(int i=0; i<poz_vulpe.size(); i++)
        istoric.push_back(poz_vulpe[i]);
    //mutare vulpe
    muta_vulpe_orizontala_stanga(tabla_de_joc, 1, 1, 1);
    //golim vectorul
    poz_vulpe.clear();
    //pozitii new
    poz_vulpe = pozitii_vulpe(tabla_de_joc);
    //specificam ca am adaugat vulpea in istoric (-2) -- pozitii noi
    istoric.push_back(-2);
    for(int i=0; i<poz_vulpe.size(); i++)
        istoric.push_back(poz_vulpe[i]);
    //specificam ca am adaugat vulpea in istoric (-2) -- finalul secventei din istoric unde gasim detaliile despre mutarea vulpii
    istoric.push_back(-2);
    afisare_tabla(tabla_de_joc);


    //vrem sa incepem parcurgea istoricului de la coada, adica de la ultima mutare facuta.
    int poz_curenta = istoric.size()-1;
    while(table_egale(tabla_de_joc,tabla_initiala) == false) //verificare tabla pas curent = tabla initiala
    {
        //press hint to show last move (and to move)

        //iepure
        if(istoric[poz_curenta]==-1)
        {
            poz_curenta--; //pozitia curenta ne indica ca avem in istoric o mutare de a iepurelui, trecem la mutarea propriu zisa

            //se muta iepurele de pe pozitia actuala pe ultima pozitie pe care a fost
            repara_tabla(tabla_de_joc, tabla_goala, istoric[poz_curenta-1], istoric[poz_curenta], istoric[poz_curenta-3], istoric[poz_curenta-2]);

            poz_curenta -=4; //se trece la mutarea precedenta.
        }
        else //vulpe
        {
            poz_curenta--; //pozitia curenta ne indica ca avem in istoric o mutare de a vulpii - POZITII NOI, trecem la mutarea propriu zisa

            //eliminam vulpile vechi
            while(istoric[poz_curenta]!=-2)
            {
                poz_curenta--; //trecem de pozitia din istoric unde avem stocat numarul vulpii (4/5/6..)

                tabla_de_joc[istoric[poz_curenta-1]][istoric[poz_curenta]] = 0;
                poz_curenta -= 2; //trecem la urmatoarea vulpe (daca mai exista) - pozitii de unde mutam

            }
            poz_curenta--; //trecem de -2 din istoric care indica trecerea la pozitiile catre care vom muta vulpile
            while(istoric[poz_curenta]!=-2)
            {
                int vulpe = istoric[poz_curenta]; //retinem ce vulpe e
                poz_curenta--; //trecem de pozitia din istoric unde avem stocat numarul vulpii (4/5/6..)
                tabla_de_joc[istoric[poz_curenta-1]][istoric[poz_curenta]] = vulpe;
                poz_curenta -= 2; //trecem la urmatoarea vulpe (daca mai exista) - pozitii unde vom muta vulpea
            }
            poz_curenta--; //trecem de al doilea -2 din istoric care indica ca am terminat cu vulpile
        }


        afisare_tabla(tabla_de_joc);
    }
}
void run()
{
    test_UI();
    int a[5][5] =
    {
        {3, 0, 0, 4, 1},
        {2, 3, 0, 4, 0},
        {3, 2, 1, 0, 5},
        {0, 3, 2, 0, 5},
        {1, 0, 6, 6, 1},
    };
    int b[5][5] = {};
    initializeaza_tabla_goala(b);
    run_all_tests();
    afiseaza_tabla_de_joc(a, b);
}



