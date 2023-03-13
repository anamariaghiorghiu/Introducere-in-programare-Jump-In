#include "fstream"

void initializeaza_tabla_de_joc(int tabla[5][5], const char* file_name){
    std::ifstream file_in(file_name);
    file_in.clear();
    file_in.seekg(0, file_in.beg);
    for(int i=0 ; i< 5 ; ++i)
     for(int j=0 ; j< 5 ; ++j)
        file_in >> tabla[i][j];
    file_in.close();
}
