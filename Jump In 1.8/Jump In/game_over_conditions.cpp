#include "iepure.h"
#include "groapa.h"

bool toti_iepurii_in_gropi(int tabla[5][5], int tabla_goala[5][5]){
/*functie care verifica daca toti iepurii de pe tabla se afla in gropi,
input - ints: matricea de joc si matricea initiala goala
output -  bool: returneaza 1 pentru adevarat si 0 pentru fals
*/
    for(int i=0 ; i< 5 ; ++i)
     for(int j=0 ; j< 5 ; ++j)
        if(is_iepure(tabla,i,j) && !is_groapa(tabla_goala,i,j))
            return false;
    return true;
}



