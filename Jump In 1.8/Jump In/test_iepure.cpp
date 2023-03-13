#include "iepure.h"
#include "tabla_goala.h"
#include "cassert"

void test_muta_iepure(){
    int tabla_de_joc_2[5][5] = {
    //double brackets ca sa nu am warning-uri
            {1, 0, 0, 4, 1},
            {2, 0, 0, 4, 0},
            {0, 2, 1, 0, 3},
            {0, 0, 2, 0, 0},
            {1, 0, 3, 0, 1}
    };
    int tabla_goala_2[5][5] = {};
    initializeaza_tabla_goala(tabla_goala_2);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 4, 2, 2);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[2][2]== 3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 2, 2, 1);
    assert(tabla_de_joc_2[2][2]==tabla_goala_2[2][2]);
    assert(tabla_de_joc_2[1][2]== 3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 2, 2, 1);
    assert(tabla_de_joc_2[2][2]==tabla_goala_2[2][2]);
    assert (tabla_de_joc_2[1][2]== 3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 4, 2, 4);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[0][2]==3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 4, 2, 3);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[1][2]==3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 4, 2, 4);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[0][2]==3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 4, 2, 4);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[0][2]==3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 2, 4, 1);
    assert(tabla_de_joc_2[2][4]==tabla_goala_2[2][4]);
    assert(tabla_de_joc_2[1][4]==3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 1, 4, 1);
    assert(tabla_de_joc_2[1][4]==tabla_goala_2[1][4]);
    assert(tabla_de_joc_2[0][4]==3);

    muta_iepure_sus(tabla_de_joc_2, tabla_goala_2, 2, 4, 2);
    assert(tabla_de_joc_2[2][4]==tabla_goala_2[2][4]);
    assert(tabla_de_joc_2[0][4]==3);

    muta_iepure_jos(tabla_de_joc_2, tabla_goala_2, 2, 4, 2);
    assert(tabla_de_joc_2[2][4]==tabla_goala_2[2][4]);
    assert(tabla_de_joc_2[4][4]==3);

    muta_iepure_jos(tabla_de_joc_2, tabla_goala_2, 2, 4, 1);
    assert(tabla_de_joc_2[2][4]==tabla_goala_2[2][4]);
    assert(tabla_de_joc_2[3][4]==3);

    muta_iepure_jos(tabla_de_joc_2, tabla_goala_2, 2, 2, 2);
    assert(tabla_de_joc_2[2][2]==tabla_goala_2[2][2]);
    assert(tabla_de_joc_2[4][2]==3);

    muta_iepure_stanga(tabla_de_joc_2, tabla_goala_2, 4, 2, 1);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[4][1]==3);

    muta_iepure_stanga(tabla_de_joc_2, tabla_goala_2, 4, 2, 2);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[4][0]==3);

    muta_iepure_stanga(tabla_de_joc_2, tabla_goala_2, 2, 4, 4);
    assert(tabla_de_joc_2[2][4]==tabla_goala_2[2][4]);
    assert(tabla_de_joc_2[2][0]==3);

    muta_iepure_dreapta(tabla_de_joc_2, tabla_goala_2, 4, 2, 2);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[4][4]==3);

    muta_iepure_dreapta(tabla_de_joc_2, tabla_goala_2, 4, 2, 1);
    assert(tabla_de_joc_2[4][2]==tabla_goala_2[4][2]);
    assert(tabla_de_joc_2[4][3]==3);


}
void test_valideaza_iepure(){
    int tabla_de_joc_3[5][5] = {
    //double brackets ca sa nu am warning-uri
            {1, 0, 0, 4, 1},
            {2, 3, 0, 4, 0},
            {3, 2, 1, 0, 3},
            {0, 3, 2, 0, 0},
            {1, 0, 3, 3, 1}
    };
    assert(valideaza_iepure_sus(tabla_de_joc_3, 1, 1)==-1);
    assert(valideaza_iepure_sus(tabla_de_joc_3, 2, 0)==2);
    assert(valideaza_iepure_sus(tabla_de_joc_3, 3, 1)==3);
    assert(valideaza_iepure_sus(tabla_de_joc_3, 4, 2)==2);
    assert(valideaza_iepure_sus(tabla_de_joc_3, 2, 4)==-1);
    assert(valideaza_iepure_sus(tabla_de_joc_3, 4, 3)==-1);

    assert(valideaza_iepure_jos(tabla_de_joc_3, 1, 1)==3);
    assert(valideaza_iepure_jos(tabla_de_joc_3, 2, 0)==-1);
    assert(valideaza_iepure_jos(tabla_de_joc_3, 3, 1)==-1);
    assert(valideaza_iepure_jos(tabla_de_joc_3, 4, 2)==-1);
    assert(valideaza_iepure_jos(tabla_de_joc_3, 2, 4)==-1);
    assert(valideaza_iepure_jos(tabla_de_joc_3, 4, 3)==-1);

    assert(valideaza_iepure_stanga(tabla_de_joc_3, 1, 1)==-1);
    assert(valideaza_iepure_stanga(tabla_de_joc_3, 2, 0)==-1);
    assert(valideaza_iepure_stanga(tabla_de_joc_3, 3, 1)==-1);
    assert(valideaza_iepure_stanga(tabla_de_joc_3, 4, 2)==-1);
    assert(valideaza_iepure_stanga(tabla_de_joc_3, 2, 4)==-1);
    assert(valideaza_iepure_stanga(tabla_de_joc_3, 4, 3)==2);

    assert(valideaza_iepure_dreapta(tabla_de_joc_3, 1, 1)==-1);
    assert(valideaza_iepure_dreapta(tabla_de_joc_3, 2, 0)==2);
    assert(valideaza_iepure_dreapta(tabla_de_joc_3, 3, 1)==2);
    assert(valideaza_iepure_dreapta(tabla_de_joc_3, 4, 2)==2);
    assert(valideaza_iepure_dreapta(tabla_de_joc_3, 2, 4)==-1);
    assert(valideaza_iepure_dreapta(tabla_de_joc_3, 4, 3)==-1);

}
