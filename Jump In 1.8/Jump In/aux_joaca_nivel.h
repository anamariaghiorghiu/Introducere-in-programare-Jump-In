#pragma once

bool is_jos(int i_start, int j_start, int i_dest, int j_dest);
bool is_sus(int i_start, int j_start, int i_dest, int j_dest);
bool is_dreapta(int i_start, int j_start, int i_dest, int j_dest);
bool is_stanga(int i_start, int j_start, int i_dest, int j_dest);
bool valid_pozitie(int i, int j);
bool miscare_valida_vulpe(vector<int> v, int val);
int tip_actiune_mouse_casual(int w, int h);
int tip_actiune_mouse_survival(int w, int h);
int tip_actiune_mouse_choose(int w, int h);
