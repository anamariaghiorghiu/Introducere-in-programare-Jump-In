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
#include "fstream"

using std::cout;
using std::cin;


void run_program(){
    run_all_tests();

    int repository_piese[5][5] = {};
    int model_tabla_de_joc_goala[5][5] = {};

    initializeaza_tabla_goala(model_tabla_de_joc_goala);

    start_GUI(repository_piese, model_tabla_de_joc_goala);

}

