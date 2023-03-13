#include "test_iepure.h"
#include "test_vulpe.h"

void run_all_tests(){
    test_muta_iepure();
    test_valideaza_iepure();
    test_is_vulpe();
    test_muta_vulpe();
    test_valideaza_vulpe();
}
