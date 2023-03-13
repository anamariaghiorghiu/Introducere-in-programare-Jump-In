#include "vulpe.h"
#include "tabla_de_joc.h"
#include "cassert"

void test_is_vulpe(){
    int tabla_de_joc_2[5][5] = {
            {1, 0, 0, 4, 1},
            {2, 3, 0, 4, 0},
            {3, 2, 1, 0, 5},
            {0, 3, 2, 0, 5},
            {1, 0, 6, 6, 1},
    };
    assert(is_vulpe_verticala(tabla_de_joc_2, 0, 3)==1);
    assert(is_vulpe_verticala(tabla_de_joc_2, 1, 3)==1);
    assert(is_vulpe_orizontala(tabla_de_joc_2, 0, 3)==0);
    assert(is_vulpe_orizontala(tabla_de_joc_2, 1, 3)==0);
    assert(is_vulpe_verticala(tabla_de_joc_2, 2, 4)==1);
    assert(is_vulpe_verticala(tabla_de_joc_2, 3, 4)==1);
    assert(is_vulpe_orizontala(tabla_de_joc_2, 2, 4)==0);
    assert(is_vulpe_orizontala(tabla_de_joc_2, 3, 4)==0);
    assert(is_vulpe_verticala(tabla_de_joc_2, 4, 2)==0);
    assert(is_vulpe_verticala(tabla_de_joc_2, 4, 3)==0);
    assert(is_vulpe_orizontala(tabla_de_joc_2, 4, 2)==1);
    assert(is_vulpe_orizontala(tabla_de_joc_2, 4, 3)==1);
}
void test_muta_vulpe(){
    int tabla_de_joc_2[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_verticala_sus(tabla_de_joc_2, 1, 1, 1);
    assert(tabla_de_joc_2[1][1]==5);
    assert(tabla_de_joc_2[0][1]==5);
    assert(tabla_de_joc_2[2][1]==0);

    int tabla_de_joc_3[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_verticala_sus(tabla_de_joc_3, 1, 3, 1);
    assert(tabla_de_joc_3[1][3]==6);
    assert(tabla_de_joc_3[0][3]==6);
    assert(tabla_de_joc_3[2][3]==0);

    int tabla_de_joc_4[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_verticala_jos(tabla_de_joc_4, 2, 4, 1);
    assert(tabla_de_joc_4[2][4]==8);
    assert(tabla_de_joc_4[3][4]==8);
    assert(tabla_de_joc_4[1][4]==0);

    int tabla_de_joc_5[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_verticala_jos(tabla_de_joc_5, 2, 0, 1);
    assert(tabla_de_joc_5[2][0]==9);
    assert(tabla_de_joc_5[3][0]==9);
    assert(tabla_de_joc_5[1][0]==0);

    int tabla_de_joc_6[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_verticala_jos(tabla_de_joc_6, 2, 3, 1);
    assert(tabla_de_joc_6[2][3]==6);
    assert(tabla_de_joc_6[3][3]==6);
    assert(tabla_de_joc_6[1][3]==0);

    int tabla_de_joc_7[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_orizontala_stanga(tabla_de_joc_7, 4, 2, 1);
    assert(tabla_de_joc_7[4][2]==7);
    assert(tabla_de_joc_7[4][1]==7);
    assert(tabla_de_joc_7[4][3]==0);

    int tabla_de_joc_8[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_orizontala_stanga(tabla_de_joc_8, 3, 1, 1);
    assert(tabla_de_joc_8[3][1]==4);
    assert(tabla_de_joc_8[3][0]==4);
    assert(tabla_de_joc_8[3][2]==0);

    int tabla_de_joc_9[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_orizontala_dreapta(tabla_de_joc_9, 3, 2, 1);
    assert(tabla_de_joc_9[3][2]==4);
    assert(tabla_de_joc_9[3][3]==4);
    assert(tabla_de_joc_9[3][1]==0);

    int tabla_de_joc_10[5][5] = {
            {1, 0, 0, 0, 1},
            {9, 5, 0, 6, 8},
            {9, 5, 1, 6, 8},
            {0, 4, 4, 0, 0},
            {1, 0, 7, 7, 1},
    };
    muta_vulpe_orizontala_dreapta(tabla_de_joc_10, 3, 2, 2);
    assert(tabla_de_joc_10[3][4]==4);
    assert(tabla_de_joc_10[3][3]==4);
    assert(tabla_de_joc_10[3][2]==0);

     int tabla_de_joc_11[5][5] = {
                {1, 0, 0, 4, 1},
                {7, 7, 0, 4, 0},
                {3, 2, 1, 0, 5},
                {0, 3, 2, 0, 5},
                {1, 0, 6, 6, 1}
    };
    muta_vulpe_verticala_sus(tabla_de_joc_11, 2, 4, 1);
    assert(tabla_de_joc_11[2][4]==5);
    assert(tabla_de_joc_11[1][4]==5);
    assert(tabla_de_joc_11[3][4]==0);

    int tabla_de_joc_12[5][5] = {
                {1, 0, 0, 4, 1},
                {7, 7, 0, 4, 0},
                {3, 2, 1, 0, 5},
                {0, 3, 2, 0, 5},
                {1, 0, 6, 6, 1}
    };
    muta_vulpe_verticala_jos(tabla_de_joc_12, 1, 3, 1);
    assert(tabla_de_joc_12[1][3]==4);
    assert(tabla_de_joc_12[2][3]==4);
    assert(tabla_de_joc_12[0][3]==0);

    int tabla_de_joc_13[5][5] = {
                {1, 0, 0, 4, 1},
                {7, 7, 0, 4, 0},
                {3, 2, 1, 0, 5},
                {0, 3, 2, 0, 5},
                {1, 0, 6, 6, 1}
    };
    muta_vulpe_verticala_jos(tabla_de_joc_13, 1, 3, 2);
    assert(tabla_de_joc_13[2][3]==4);
    assert(tabla_de_joc_13[3][3]==4);
    assert(tabla_de_joc_13[1][3]==0);

    int tabla_de_joc_14[5][5] = {
                {1, 0, 0, 4, 1},
                {7, 7, 0, 4, 0},
                {3, 2, 1, 0, 5},
                {0, 3, 2, 0, 5},
                {1, 0, 6, 6, 1}
    };
    muta_vulpe_orizontala_stanga(tabla_de_joc_14, 4, 2, 1);
    assert(tabla_de_joc_14[4][2]==6);
    assert(tabla_de_joc_14[4][1]==6);
    assert(tabla_de_joc_14[4][3]==0);

    int tabla_de_joc_15[5][5] = {
                {1, 0, 0, 4, 1},
                {7, 7, 0, 4, 0},
                {3, 2, 1, 0, 5},
                {0, 3, 2, 0, 5},
                {1, 0, 6, 6, 1}
    };
    muta_vulpe_orizontala_dreapta(tabla_de_joc_15, 1, 1, 1);
    assert(tabla_de_joc_15[1][1]==7);
    assert(tabla_de_joc_15[1][2]==7);
    assert(tabla_de_joc_15[1][0]==0);
}
void test_valideaza_vulpe(){
    int tabla_de_joc[5][5] = {
            {1, 7, 0, 0, 1},
            {0, 7, 0, 4, 4},
            {6, 0, 1, 0, 0},
            {6, 5, 5, 0, 0},
            {1, 0, 0, 0, 1}
    };

    vector<int> mutari_vulpe_dreapta_1 = valideaza_vulpe_orizontala_dreapta(tabla_de_joc, 3, 1);
    vector<int> test_1;
    test_1.push_back(1);
    test_1.push_back(2);
    assert(mutari_vulpe_dreapta_1 == test_1);

    vector<int> mutari_vulpe_dreapta_2 = valideaza_vulpe_orizontala_dreapta(tabla_de_joc, 1, 4);
    vector<int> test_2;
    test_2.push_back(-1);
    assert(mutari_vulpe_dreapta_2 == test_2);

    vector<int> mutari_vulpe_stanga_1 = valideaza_vulpe_orizontala_stanga(tabla_de_joc, 1, 3);
    vector<int> test_3;
    test_3.push_back(1);
    assert(mutari_vulpe_stanga_1 == test_3);

    vector<int> mutari_vulpe_stanga_2 = valideaza_vulpe_orizontala_stanga(tabla_de_joc, 3, 1);
    vector<int> test_4;
    test_4.push_back(-1);
    assert(mutari_vulpe_stanga_2 == test_4);

    vector<int> mutari_vulpe_sus_1 = valideaza_vulpe_verticala_sus(tabla_de_joc, 0, 1);
    vector<int> test_5;
    test_5.push_back(-1);
    assert(mutari_vulpe_sus_1 == test_5);

    vector<int> mutari_vulpe_sus_2 = valideaza_vulpe_verticala_sus(tabla_de_joc, 2, 0);
    vector<int> test_6;
    test_6.push_back(1);
    assert(mutari_vulpe_sus_2 == test_6);

    vector<int> mutari_vulpe_jos_1 = valideaza_vulpe_verticala_jos(tabla_de_joc, 0, 1);
    vector<int> test_7;
    test_7.push_back(1);
    assert(mutari_vulpe_jos_1 == test_7);

    vector<int> mutari_vulpe_jos_2 = valideaza_vulpe_verticala_jos(tabla_de_joc, 3, 0);
    vector<int> test_8;
    test_8.push_back(-1);
    assert(mutari_vulpe_jos_2 == test_8);


    int tabla_de_joc_2[5][5] = {
            {1, 2, 6, 6, 1},
            {4, 4, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 5, 5},
            {1, 7, 7, 3, 1},
    };
    vector<int> mutari_vulpe_dreapta_3 = valideaza_vulpe_orizontala_dreapta(tabla_de_joc_2, 1, 1);
    vector<int> test_9;
    test_9.push_back(1);
    test_9.push_back(2);
    test_9.push_back(3);
    assert(mutari_vulpe_dreapta_3 == test_9);

    vector<int> mutari_vulpe_dreapta_4 = valideaza_vulpe_orizontala_dreapta(tabla_de_joc_2, 0, 3);
    vector<int> test_10;
    test_10.push_back(-1);
    assert(mutari_vulpe_dreapta_4 == test_10);

    vector<int> mutari_vulpe_dreapta_5 = valideaza_vulpe_orizontala_dreapta(tabla_de_joc_2, 3, 4);
    vector<int> test_11;
    test_11.push_back(-1);
    assert(mutari_vulpe_dreapta_5 == test_11);

    vector<int> mutari_vulpe_dreapta_6 = valideaza_vulpe_orizontala_dreapta(tabla_de_joc_2, 4, 1);
    vector<int> test_12;
    test_12.push_back(-1);
    assert(mutari_vulpe_dreapta_6 == test_12);

    vector<int> mutari_vulpe_stanga_3 = valideaza_vulpe_orizontala_stanga(tabla_de_joc_2, 3, 3);
    vector<int> test_13;
    test_13.push_back(1);
    test_13.push_back(2);
    test_13.push_back(3);
    assert(mutari_vulpe_stanga_3 == test_13);

    vector<int> mutari_vulpe_stanga_4 = valideaza_vulpe_orizontala_stanga(tabla_de_joc_2, 0, 3);
    vector<int> test_14;
    test_14.push_back(-1);
    assert(mutari_vulpe_stanga_4 == test_14);

    vector<int> mutari_vulpe_stanga_5 = valideaza_vulpe_orizontala_stanga(tabla_de_joc_2, 1, 0);
    vector<int> test_15;
    test_15.push_back(-1);
    assert(mutari_vulpe_stanga_5 == test_15);

    vector<int> mutari_vulpe_stanga_6 = valideaza_vulpe_orizontala_stanga(tabla_de_joc_2, 4, 1);
    vector<int> test_16;
    test_16.push_back(-1);
    assert(mutari_vulpe_stanga_6 == test_16);


    int tabla_de_joc_3[5][5] = {
            {1, 4, 0, 0, 1},
            {0, 4, 0, 0, 3},
            {0, 0, 1, 0, 6},
            {0, 0, 0, 5, 6},
            {1, 0, 0, 5, 1}
    };
    vector<int> mutari_vulpe_sus_3 = valideaza_vulpe_verticala_sus(tabla_de_joc_3, 0, 1);
    vector<int> test_17;
    test_17.push_back(-1);
    assert(mutari_vulpe_sus_3 == test_17);

    vector<int> mutari_vulpe_sus_4 = valideaza_vulpe_verticala_sus(tabla_de_joc_3, 3, 3);
    vector<int> test_18;
    test_18.push_back(1);
    test_18.push_back(2);
    test_18.push_back(3);
    assert(mutari_vulpe_sus_4 == test_18);

    vector<int> mutari_vulpe_sus_5 = valideaza_vulpe_verticala_sus(tabla_de_joc_3, 2, 4);
    vector<int> test_19;
    test_19.push_back(-1);
    assert(mutari_vulpe_sus_3 == test_19);

    vector<int> mutari_vulpe_jos_3 = valideaza_vulpe_verticala_jos(tabla_de_joc_3, 0, 1);
    vector<int> test_20;
    test_20.push_back(1);
    test_20.push_back(2);
    test_20.push_back(3);
    assert(mutari_vulpe_jos_3 == test_20);

    vector<int> mutari_vulpe_jos_5 = valideaza_vulpe_verticala_jos(tabla_de_joc_3, 3, 3);
    vector<int> test_22;
    test_22.push_back(-1);
    assert(mutari_vulpe_jos_5 == test_22);

    vector<int> mutari_vulpe_jos_6 = valideaza_vulpe_verticala_jos(tabla_de_joc_3, 2, 4);
    vector<int> test_23;
    test_23.push_back(-1);
    assert(mutari_vulpe_jos_6 == test_23);
}
