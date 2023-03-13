#include "graphics.h"
#include "cstdlib"
#include "iostream"
#include "cstring"
#include "choose_mode.h"

int tip_actiune_mouse_alege_nivel(int latimea_ecranului, int inaltimea_ecranului){
    int indice_mouse_x = mousex();
    int indice_mouse_y = mousey();

    double x1_buton_back = latimea_ecranului / 73.615384;
    double x2_buton_back = latimea_ecranului / 6.2345276873;
    double y1_buton_back = inaltimea_ecranului / 52.55;
    double y2_buton_back = inaltimea_ecranului / 7.561151;

    double x1_buton_1 = latimea_ecranului / 239.25;
    double x2_buton_1 = latimea_ecranului / 11.0636;
    double y1_buton_1 = inaltimea_ecranului / 5.68108;
    double y2_buton_1 = inaltimea_ecranului / 4.12157;

    double x1_buton_2 = latimea_ecranului / 9.9171;
    double x2_buton_2 = latimea_ecranului / 5.34637;
    double y1_buton_2 = inaltimea_ecranului / 5.68108;
    double y2_buton_2 = inaltimea_ecranului / 4.12157;

    double x1_buton_3 = latimea_ecranului / 5.06349;
    double x2_buton_3 = latimea_ecranului / 3.52486;
    double y1_buton_3 = inaltimea_ecranului / 5.68108;
    double y2_buton_3 = inaltimea_ecranului / 4.12157;

    double x1_buton_4 = latimea_ecranului / 3.39964;
    double x2_buton_4 = latimea_ecranului / 2.62912;
    double y1_buton_4 = inaltimea_ecranului / 5.68108;
    double y2_buton_4 = inaltimea_ecranului / 4.12157;

    double x1_buton_5 = latimea_ecranului / 2.55882;
    double x2_buton_5 = latimea_ecranului / 2.09639;
    double y1_buton_5 = inaltimea_ecranului / 5.68108;
    double y2_buton_5 = inaltimea_ecranului / 4.12157;

    double x1_buton_6 = latimea_ecranului / 2.05145;
    double x2_buton_6 = latimea_ecranului / 1.74317;
    double y1_buton_6 = inaltimea_ecranului / 5.68108;
    double y2_buton_6 = inaltimea_ecranului / 4.12157;

    double x1_buton_7 = latimea_ecranului / 1.71199;
    double x2_buton_7 = latimea_ecranului / 1.49182;
    double y1_buton_7 = inaltimea_ecranului / 5.68108;
    double y2_buton_7 = inaltimea_ecranului / 4.12157;

    double x1_buton_8 = latimea_ecranului / 1.46892;
    double x2_buton_8 = latimea_ecranului / 1.30381;
    double y1_buton_8 = inaltimea_ecranului / 5.68108;
    double y2_buton_8 = inaltimea_ecranului / 4.12157;

    double x1_buton_9 = latimea_ecranului / 1.28629;
    double x2_buton_9 = latimea_ecranului / 1.15789;
    double y1_buton_9 = inaltimea_ecranului / 5.68108;
    double y2_buton_9 = inaltimea_ecranului / 4.12157;

    double x1_buton_10 = latimea_ecranului / 1.14405;
    double x2_buton_10 = latimea_ecranului / 1.04135;
    double y1_buton_10 = inaltimea_ecranului / 5.68108;
    double y2_buton_10 = inaltimea_ecranului / 4.12157;

    double x1_buton_11 = latimea_ecranului / 239.25;
    double x2_buton_11 = latimea_ecranului / 11.0636;
    double y1_buton_11 = inaltimea_ecranului / 3.26398;
    double y2_buton_11 = inaltimea_ecranului / 2.68112;

    double x1_buton_12 = latimea_ecranului / 9.9171;
    double x2_buton_12 = latimea_ecranului / 5.34637;
    double y1_buton_12 = inaltimea_ecranului / 3.26398;
    double y2_buton_12 = inaltimea_ecranului / 2.68112;

    double x1_buton_13 = latimea_ecranului / 5.06349;
    double x2_buton_13 = latimea_ecranului / 3.52486;
    double y1_buton_13 = inaltimea_ecranului / 3.26398;
    double y2_buton_13 = inaltimea_ecranului / 2.68112;

    double x1_buton_14 = latimea_ecranului / 3.39964;
    double x2_buton_14 = latimea_ecranului / 2.62912;
    double y1_buton_14 = inaltimea_ecranului / 3.26398;
    double y2_buton_14 = inaltimea_ecranului / 2.68112;

    double x1_buton_15 = latimea_ecranului / 2.55882;
    double x2_buton_15 = latimea_ecranului / 2.09639;
    double y1_buton_15 = inaltimea_ecranului / 3.26398;
    double y2_buton_15 = inaltimea_ecranului / 2.68112;

    double x1_buton_16 = latimea_ecranului / 2.05145;
    double x2_buton_16 = latimea_ecranului / 1.74317;
    double y1_buton_16 = inaltimea_ecranului / 3.26398;
    double y2_buton_16 = inaltimea_ecranului / 2.68112;

    double x1_buton_17 = latimea_ecranului / 1.71199;
    double x2_buton_17 = latimea_ecranului / 1.49182;
    double y1_buton_17 = inaltimea_ecranului / 3.26398;
    double y2_buton_17 = inaltimea_ecranului / 2.68112;

    double x1_buton_18 = latimea_ecranului / 1.46892;
    double x2_buton_18 = latimea_ecranului / 1.30381;
    double y1_buton_18 = inaltimea_ecranului / 3.26398;
    double y2_buton_18 = inaltimea_ecranului / 2.68112;

    double x1_buton_19 = latimea_ecranului / 1.28629;
    double x2_buton_19 = latimea_ecranului / 1.15789;
    double y1_buton_19 = inaltimea_ecranului / 3.26398;
    double y2_buton_19 = inaltimea_ecranului / 2.68112;

    double x1_buton_20 = latimea_ecranului / 1.14405;
    double x2_buton_20 = latimea_ecranului / 1.04135;
    double y1_buton_20 = inaltimea_ecranului / 3.26398;
    double y2_buton_20 = inaltimea_ecranului / 2.68112;

    double x1_buton_21 = latimea_ecranului / 239.25;
    double x2_buton_21 = latimea_ecranului / 11.0636;
    double y1_buton_21 = inaltimea_ecranului / 2.28976;
    double y2_buton_21 = inaltimea_ecranului / 1.98677;

    double x1_buton_22 = latimea_ecranului / 9.9171;
    double x2_buton_22 = latimea_ecranului / 5.34637;
    double y1_buton_22 = inaltimea_ecranului / 2.28976;
    double y2_buton_22 = inaltimea_ecranului / 1.98677;

    double x1_buton_23 = latimea_ecranului / 5.06349;
    double x2_buton_23 = latimea_ecranului / 3.52486;
    double y1_buton_23 = inaltimea_ecranului / 2.28976;
    double y2_buton_23 = inaltimea_ecranului / 1.98677;

    double x1_buton_24 = latimea_ecranului / 3.39964;
    double x2_buton_24 = latimea_ecranului / 2.62912;
    double y1_buton_24 = inaltimea_ecranului / 2.28976;
    double y2_buton_24 = inaltimea_ecranului / 1.98677;

    double x1_buton_25 = latimea_ecranului / 2.55882;
    double x2_buton_25 = latimea_ecranului / 2.09639;
    double y1_buton_25 = inaltimea_ecranului / 2.28976;
    double y2_buton_25 = inaltimea_ecranului / 1.98677;

    double x1_buton_26 = latimea_ecranului / 2.05145;
    double x2_buton_26 = latimea_ecranului / 1.74317;
    double y1_buton_26 = inaltimea_ecranului / 2.28976;
    double y2_buton_26 = inaltimea_ecranului / 1.98677;

    double x1_buton_27 = latimea_ecranului / 1.71199;
    double x2_buton_27 = latimea_ecranului / 1.49182;
    double y1_buton_27 = inaltimea_ecranului / 2.28976;
    double y2_buton_27 = inaltimea_ecranului / 1.98677;

    double x1_buton_28 = latimea_ecranului / 1.46892;
    double x2_buton_28 = latimea_ecranului / 1.30381;
    double y1_buton_28 = inaltimea_ecranului / 2.28976;
    double y2_buton_28 = inaltimea_ecranului / 1.98677;

    double x1_buton_29 = latimea_ecranului / 1.28629;
    double x2_buton_29 = latimea_ecranului / 1.15789;
    double y1_buton_29 = inaltimea_ecranului / 2.28976;
    double y2_buton_29 = inaltimea_ecranului / 1.98677;

    double x1_buton_30 = latimea_ecranului / 1.14405;
    double x2_buton_30 = latimea_ecranului / 1.04135;
    double y1_buton_30 = inaltimea_ecranului / 2.28976;
    double y2_buton_30 = inaltimea_ecranului / 1.98677;

    double x1_buton_31 = latimea_ecranului / 239.25;
    double x2_buton_31 = latimea_ecranului / 11.0636;
    double y1_buton_31 = inaltimea_ecranului / 1.76342;
    double y2_buton_31 = inaltimea_ecranului / 1.57808;

    double x1_buton_32 = latimea_ecranului / 9.9171;
    double x2_buton_32 = latimea_ecranului / 5.34637;
    double y1_buton_32 = inaltimea_ecranului / 1.76342;
    double y2_buton_32 = inaltimea_ecranului / 1.57808;

    double x1_buton_33 = latimea_ecranului / 5.06349;
    double x2_buton_33 = latimea_ecranului / 3.52486;
    double y1_buton_33 = inaltimea_ecranului / 1.76342;
    double y2_buton_33 = inaltimea_ecranului / 1.57808;

    double x1_buton_34 = latimea_ecranului / 3.39964;
    double x2_buton_34 = latimea_ecranului / 2.62912;
    double y1_buton_34 = inaltimea_ecranului / 1.76342;
    double y2_buton_34 = inaltimea_ecranului / 1.57808;

    double x1_buton_35 = latimea_ecranului / 2.55882;
    double x2_buton_35 = latimea_ecranului / 2.09639;
    double y1_buton_35 = inaltimea_ecranului / 1.76342;
    double y2_buton_35 = inaltimea_ecranului / 1.57808;

    double x1_buton_36 = latimea_ecranului / 2.05145;
    double x2_buton_36 = latimea_ecranului / 1.74317;
    double y1_buton_36 = inaltimea_ecranului / 1.76342;
    double y2_buton_36 = inaltimea_ecranului / 1.57808;

    double x1_buton_37 = latimea_ecranului / 1.71199;
    double x2_buton_37 = latimea_ecranului / 1.49182;
    double y1_buton_37 = inaltimea_ecranului / 1.76342;
    double y2_buton_37 = inaltimea_ecranului / 1.57808;

    double x1_buton_38 = latimea_ecranului / 1.46892;
    double x2_buton_38 = latimea_ecranului / 1.30381;
    double y1_buton_38 = inaltimea_ecranului / 1.76342;
    double y2_buton_38 = inaltimea_ecranului / 1.57808;

    double x1_buton_39 = latimea_ecranului / 1.28629;
    double x2_buton_39 = latimea_ecranului / 1.15789;
    double y1_buton_39 = inaltimea_ecranului / 1.76342;
    double y2_buton_39 = inaltimea_ecranului / 1.57808;

    double x1_buton_40 = latimea_ecranului / 1.14405;
    double x2_buton_40 = latimea_ecranului / 1.04135;
    double y1_buton_40 = inaltimea_ecranului / 1.76342;
    double y2_buton_40 = inaltimea_ecranului / 1.57808;

    double x1_buton_41 = latimea_ecranului / 239.25;
    double x2_buton_41 = latimea_ecranului / 11.0636;
    double y1_buton_41 = inaltimea_ecranului / 1.43383;
    double y2_buton_41 = inaltimea_ecranului / 1.30884;

    double x1_buton_42 = latimea_ecranului / 9.9171;
    double x2_buton_42 = latimea_ecranului / 5.34637;
    double y1_buton_42 = inaltimea_ecranului / 1.43383;
    double y2_buton_42 = inaltimea_ecranului / 1.30884;

    double x1_buton_43 = latimea_ecranului / 5.06349;
    double x2_buton_43 = latimea_ecranului / 3.52486;
    double y1_buton_43 = inaltimea_ecranului / 1.43383;
    double y2_buton_43 = inaltimea_ecranului / 1.30884;

    double x1_buton_44 = latimea_ecranului / 3.39964;
    double x2_buton_44 = latimea_ecranului / 2.62912;
    double y1_buton_44 = inaltimea_ecranului / 1.43383;
    double y2_buton_44 = inaltimea_ecranului / 1.30884;

    double x1_buton_45 = latimea_ecranului / 2.55882;
    double x2_buton_45 = latimea_ecranului / 2.09639;
    double y1_buton_45 = inaltimea_ecranului / 1.43383;
    double y2_buton_45 = inaltimea_ecranului / 1.30884;

    double x1_buton_46 = latimea_ecranului / 2.05145;
    double x2_buton_46 = latimea_ecranului / 1.74317;
    double y1_buton_46 = inaltimea_ecranului / 1.43383;
    double y2_buton_46 = inaltimea_ecranului / 1.30884;

    double x1_buton_47 = latimea_ecranului / 1.71199;
    double x2_buton_47 = latimea_ecranului / 1.49182;
    double y1_buton_47 = inaltimea_ecranului / 1.43383;
    double y2_buton_47 = inaltimea_ecranului / 1.30884;

    double x1_buton_48 = latimea_ecranului / 1.46892;
    double x2_buton_48 = latimea_ecranului / 1.30381;
    double y1_buton_48 = inaltimea_ecranului / 1.43383;
    double y2_buton_48 = inaltimea_ecranului / 1.30884;

    double x1_buton_49 = latimea_ecranului / 1.28629;
    double x2_buton_49 = latimea_ecranului / 1.15789;
    double y1_buton_49 = inaltimea_ecranului / 1.43383;
    double y2_buton_49 = inaltimea_ecranului / 1.30884;

    double x1_buton_50 = latimea_ecranului / 1.14405;
    double x2_buton_50 = latimea_ecranului / 1.04135;
    double y1_buton_50 = inaltimea_ecranului / 1.43383;
    double y2_buton_50 = inaltimea_ecranului / 1.30884;

    double x1_buton_51 = latimea_ecranului / 239.25;
    double x2_buton_51 = latimea_ecranului / 11.0636;
    double y1_buton_51 = inaltimea_ecranului / 1.20805;
    double y2_buton_51 = inaltimea_ecranului / 1.11809;

    double x1_buton_52 = latimea_ecranului / 9.9171;
    double x2_buton_52 = latimea_ecranului / 5.34637;
    double y1_buton_52 = inaltimea_ecranului / 1.20805;
    double y2_buton_52 = inaltimea_ecranului / 1.11809;

    double x1_buton_53 = latimea_ecranului / 5.06349;
    double x2_buton_53 = latimea_ecranului / 3.52486;
    double y1_buton_53 = inaltimea_ecranului / 1.20805;
    double y2_buton_53 = inaltimea_ecranului / 1.11809;

    double x1_buton_54 = latimea_ecranului / 3.39964;
    double x2_buton_54 = latimea_ecranului / 2.62912;
    double y1_buton_54 = inaltimea_ecranului / 1.20805;
    double y2_buton_54 = inaltimea_ecranului / 1.11809;

    double x1_buton_55 = latimea_ecranului / 2.55882;
    double x2_buton_55 = latimea_ecranului / 2.09639;
    double y1_buton_55 = inaltimea_ecranului / 1.20805;
    double y2_buton_55 = inaltimea_ecranului / 1.11809;

    double x1_buton_56 = latimea_ecranului / 2.05145;
    double x2_buton_56 = latimea_ecranului / 1.74317;
    double y1_buton_56 = inaltimea_ecranului / 1.20805;
    double y2_buton_56 = inaltimea_ecranului / 1.11809;

    double x1_buton_57 = latimea_ecranului / 1.71199;
    double x2_buton_57 = latimea_ecranului / 1.49182;
    double y1_buton_57 = inaltimea_ecranului / 1.20805;
    double y2_buton_57 = inaltimea_ecranului / 1.11809;

    double x1_buton_58 = latimea_ecranului / 1.46892;
    double x2_buton_58 = latimea_ecranului / 1.30381;
    double y1_buton_58 = inaltimea_ecranului / 1.20805;
    double y2_buton_58 = inaltimea_ecranului / 1.11809;

    double x1_buton_59 = latimea_ecranului / 1.28629;
    double x2_buton_59 = latimea_ecranului / 1.15789;
    double y1_buton_59 = inaltimea_ecranului / 1.20805;
    double y2_buton_59 = inaltimea_ecranului / 1.11809;

    double x1_buton_60 = latimea_ecranului / 1.14405;
    double x2_buton_60 = latimea_ecranului / 1.04135;
    double y1_buton_60 = inaltimea_ecranului / 1.20805;
    double y2_buton_60 = inaltimea_ecranului / 1.11809;





    if(x1_buton_1 < indice_mouse_x && indice_mouse_x < x2_buton_1 && y1_buton_1 < indice_mouse_y && indice_mouse_y < y2_buton_1)
	return 1;

    if(x1_buton_2 < indice_mouse_x && indice_mouse_x < x2_buton_2 && y1_buton_2 < indice_mouse_y && indice_mouse_y < y2_buton_2)
        return 2;

    if(x1_buton_3 < indice_mouse_x && indice_mouse_x < x2_buton_3 && y1_buton_3 < indice_mouse_y && indice_mouse_y < y2_buton_3)
        return 3;

    if(x1_buton_4 < indice_mouse_x && indice_mouse_x < x2_buton_4 && y1_buton_4 < indice_mouse_y && indice_mouse_y < y2_buton_4)
        return 4;

    if(x1_buton_5 < indice_mouse_x && indice_mouse_x < x2_buton_5 && y1_buton_5 < indice_mouse_y && indice_mouse_y < y2_buton_5)
        return 5;

    if(x1_buton_6 < indice_mouse_x && indice_mouse_x < x2_buton_6 && y1_buton_6 < indice_mouse_y && indice_mouse_y < y2_buton_6)
        return 6;

    if(x1_buton_7 < indice_mouse_x && indice_mouse_x < x2_buton_7 && y1_buton_7 < indice_mouse_y && indice_mouse_y < y2_buton_7)
        return 7;

    if(x1_buton_8 < indice_mouse_x && indice_mouse_x < x2_buton_8 && y1_buton_8 < indice_mouse_y && indice_mouse_y < y2_buton_8)
        return 8;

    if(x1_buton_9 < indice_mouse_x && indice_mouse_x < x2_buton_9 && y1_buton_9 < indice_mouse_y && indice_mouse_y < y2_buton_9)
        return 9;

    if(x1_buton_10 < indice_mouse_x && indice_mouse_x < x2_buton_10 && y1_buton_10 < indice_mouse_y && indice_mouse_y < y2_buton_10)
        return 10;

    if(x1_buton_11 < indice_mouse_x && indice_mouse_x < x2_buton_11 && y1_buton_11 < indice_mouse_y && indice_mouse_y < y2_buton_11)
        return 11;

    if(x1_buton_12 < indice_mouse_x && indice_mouse_x < x2_buton_12 && y1_buton_12 < indice_mouse_y && indice_mouse_y < y2_buton_12)
        return 12;

    if(x1_buton_13 < indice_mouse_x && indice_mouse_x < x2_buton_13 && y1_buton_13 < indice_mouse_y && indice_mouse_y < y2_buton_13)
        return 13;

    if(x1_buton_14 < indice_mouse_x && indice_mouse_x < x2_buton_14 && y1_buton_14 < indice_mouse_y && indice_mouse_y < y2_buton_14)
        return 14;

    if(x1_buton_15 < indice_mouse_x && indice_mouse_x < x2_buton_15 && y1_buton_15 < indice_mouse_y && indice_mouse_y < y2_buton_15)
        return 15;

    if(x1_buton_16 < indice_mouse_x && indice_mouse_x < x2_buton_16 && y1_buton_16 < indice_mouse_y && indice_mouse_y < y2_buton_16)
        return 16;

    if(x1_buton_17 < indice_mouse_x && indice_mouse_x < x2_buton_17 && y1_buton_17 < indice_mouse_y && indice_mouse_y < y2_buton_17)
        return 17;

    if(x1_buton_18 < indice_mouse_x && indice_mouse_x < x2_buton_18 && y1_buton_18 < indice_mouse_y && indice_mouse_y < y2_buton_18)
        return 18;

    if(x1_buton_19 < indice_mouse_x && indice_mouse_x < x2_buton_19 && y1_buton_19 < indice_mouse_y && indice_mouse_y < y2_buton_19)
        return 19;

    if(x1_buton_20 < indice_mouse_x && indice_mouse_x < x2_buton_20 && y1_buton_20 < indice_mouse_y && indice_mouse_y < y2_buton_20)
        return 20;

    if(x1_buton_21 < indice_mouse_x && indice_mouse_x < x2_buton_21 && y1_buton_21 < indice_mouse_y && indice_mouse_y < y2_buton_21)
        return 21;

    if(x1_buton_22 < indice_mouse_x && indice_mouse_x < x2_buton_22 && y1_buton_22 < indice_mouse_y && indice_mouse_y < y2_buton_22)
        return 22;

    if(x1_buton_23 < indice_mouse_x && indice_mouse_x < x2_buton_23 && y1_buton_23 < indice_mouse_y && indice_mouse_y < y2_buton_23)
        return 23;

    if(x1_buton_24 < indice_mouse_x && indice_mouse_x < x2_buton_24 && y1_buton_24 < indice_mouse_y && indice_mouse_y < y2_buton_24)
        return 24;

    if(x1_buton_25 < indice_mouse_x && indice_mouse_x < x2_buton_25 && y1_buton_25 < indice_mouse_y && indice_mouse_y < y2_buton_25)
        return 25;

    if(x1_buton_26 < indice_mouse_x && indice_mouse_x < x2_buton_26 && y1_buton_26 < indice_mouse_y && indice_mouse_y < y2_buton_26)
        return 26;

    if(x1_buton_27 < indice_mouse_x && indice_mouse_x < x2_buton_27 && y1_buton_27 < indice_mouse_y && indice_mouse_y < y2_buton_27)
        return 27;

    if(x1_buton_28 < indice_mouse_x && indice_mouse_x < x2_buton_28 && y1_buton_28 < indice_mouse_y && indice_mouse_y < y2_buton_28)
        return 28;

    if(x1_buton_29 < indice_mouse_x && indice_mouse_x < x2_buton_29 && y1_buton_29 < indice_mouse_y && indice_mouse_y < y2_buton_29)
        return 29;

    if(x1_buton_30 < indice_mouse_x && indice_mouse_x < x2_buton_30 && y1_buton_30 < indice_mouse_y && indice_mouse_y < y2_buton_30)
        return 30;

    if(x1_buton_31 < indice_mouse_x && indice_mouse_x < x2_buton_31 && y1_buton_31 < indice_mouse_y && indice_mouse_y < y2_buton_31)
        return 31;

    if(x1_buton_32 < indice_mouse_x && indice_mouse_x < x2_buton_32 && y1_buton_32 < indice_mouse_y && indice_mouse_y < y2_buton_32)
        return 32;

    if(x1_buton_33 < indice_mouse_x && indice_mouse_x < x2_buton_33 && y1_buton_33 < indice_mouse_y && indice_mouse_y < y2_buton_33)
        return 33;

    if(x1_buton_34 < indice_mouse_x && indice_mouse_x < x2_buton_34 && y1_buton_34 < indice_mouse_y && indice_mouse_y < y2_buton_34)
        return 34;

    if(x1_buton_35 < indice_mouse_x && indice_mouse_x < x2_buton_35 && y1_buton_35 < indice_mouse_y && indice_mouse_y < y2_buton_35)
        return 35;

    if(x1_buton_36 < indice_mouse_x && indice_mouse_x < x2_buton_36 && y1_buton_36 < indice_mouse_y && indice_mouse_y < y2_buton_36)
        return 36;

    if(x1_buton_37 < indice_mouse_x && indice_mouse_x < x2_buton_37 && y1_buton_37 < indice_mouse_y && indice_mouse_y < y2_buton_37)
        return 37;

    if(x1_buton_38 < indice_mouse_x && indice_mouse_x < x2_buton_38 && y1_buton_38 < indice_mouse_y && indice_mouse_y < y2_buton_38)
        return 38;

    if(x1_buton_39 < indice_mouse_x && indice_mouse_x < x2_buton_39 && y1_buton_39 < indice_mouse_y && indice_mouse_y < y2_buton_39)
        return 39;

    if(x1_buton_40 < indice_mouse_x && indice_mouse_x < x2_buton_40 && y1_buton_40 < indice_mouse_y && indice_mouse_y < y2_buton_40)
        return 40;

    if(x1_buton_41 < indice_mouse_x && indice_mouse_x < x2_buton_41 && y1_buton_41 < indice_mouse_y && indice_mouse_y < y2_buton_41)
        return 41;

    if(x1_buton_42 < indice_mouse_x && indice_mouse_x < x2_buton_42 && y1_buton_42 < indice_mouse_y && indice_mouse_y < y2_buton_42)
        return 42;

    if(x1_buton_43 < indice_mouse_x && indice_mouse_x < x2_buton_43 && y1_buton_43 < indice_mouse_y && indice_mouse_y < y2_buton_43)
        return 43;

    if(x1_buton_44 < indice_mouse_x && indice_mouse_x < x2_buton_44 && y1_buton_44 < indice_mouse_y && indice_mouse_y < y2_buton_44)
        return 44;

    if(x1_buton_45 < indice_mouse_x && indice_mouse_x < x2_buton_45 && y1_buton_45 < indice_mouse_y && indice_mouse_y < y2_buton_45)
        return 45;

    if(x1_buton_46 < indice_mouse_x && indice_mouse_x < x2_buton_46 && y1_buton_46 < indice_mouse_y && indice_mouse_y < y2_buton_46)
        return 46;

    if(x1_buton_47 < indice_mouse_x && indice_mouse_x < x2_buton_47 && y1_buton_47 < indice_mouse_y && indice_mouse_y < y2_buton_47)
        return 47;

    if(x1_buton_48 < indice_mouse_x && indice_mouse_x < x2_buton_48 && y1_buton_48 < indice_mouse_y && indice_mouse_y < y2_buton_48)
        return 48;

    if(x1_buton_49 < indice_mouse_x && indice_mouse_x < x2_buton_49 && y1_buton_49 < indice_mouse_y && indice_mouse_y < y2_buton_49)
        return 49;

    if(x1_buton_50 < indice_mouse_x && indice_mouse_x < x2_buton_50 && y1_buton_50 < indice_mouse_y && indice_mouse_y < y2_buton_50)
        return 50;

    if(x1_buton_51 < indice_mouse_x && indice_mouse_x < x2_buton_51 && y1_buton_51 < indice_mouse_y && indice_mouse_y < y2_buton_51)
        return 51;

    if(x1_buton_52 < indice_mouse_x && indice_mouse_x < x2_buton_52 && y1_buton_52 < indice_mouse_y && indice_mouse_y < y2_buton_52)
        return 52;

    if(x1_buton_53 < indice_mouse_x && indice_mouse_x < x2_buton_53 && y1_buton_53 < indice_mouse_y && indice_mouse_y < y2_buton_53)
        return 53;

    if(x1_buton_54 < indice_mouse_x && indice_mouse_x < x2_buton_54 && y1_buton_54 < indice_mouse_y && indice_mouse_y < y2_buton_54)
        return 54;

    if(x1_buton_55 < indice_mouse_x && indice_mouse_x < x2_buton_55 && y1_buton_55 < indice_mouse_y && indice_mouse_y < y2_buton_55)
        return 55;

    if(x1_buton_56 < indice_mouse_x && indice_mouse_x < x2_buton_56 && y1_buton_56 < indice_mouse_y && indice_mouse_y < y2_buton_56)
        return 56;

    if(x1_buton_57 < indice_mouse_x && indice_mouse_x < x2_buton_57 && y1_buton_57 < indice_mouse_y && indice_mouse_y < y2_buton_57)
        return 57;

    if(x1_buton_58 < indice_mouse_x && indice_mouse_x < x2_buton_58 && y1_buton_58 < indice_mouse_y && indice_mouse_y < y2_buton_58)
        return 58;

    if(x1_buton_59 < indice_mouse_x && indice_mouse_x < x2_buton_59 && y1_buton_59 < indice_mouse_y && indice_mouse_y < y2_buton_59)
        return 59;

    if(x1_buton_60 < indice_mouse_x && indice_mouse_x < x2_buton_60 && y1_buton_60 < indice_mouse_y && indice_mouse_y < y2_buton_60)
        return 60;

    if(x1_buton_back < indice_mouse_x && indice_mouse_x < x2_buton_back && y1_buton_back < indice_mouse_y && indice_mouse_y < y2_buton_back)
        return 61;

    return 0;
}
void alege_nivel(int latimea_ecranului, int inaltimea_ecranului, bool sunet, int limba){
        if(limba == 1)
            readimagefile("jpg/alege_nivel/60_romana.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else if(limba == 2)
            readimagefile("jpg/alege_nivel/60_engleza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else if(limba == 3)
            readimagefile("jpg/alege_nivel/60_franceza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);
        else
            readimagefile("jpg/alege_nivel/60_japoneza.jpg", 0, 0, latimea_ecranului, inaltimea_ecranului);

        while(1){
            clearmouseclick(WM_LBUTTONDOWN);
            if(ismouseclick(WM_LBUTTONDOWN)){
                if(sunet)
                    mciSendString("play sound/butoane_meniu.mp3", NULL, 0, NULL);
                int tip = tip_actiune_mouse_alege_nivel(latimea_ecranului, inaltimea_ecranului);
                if(tip == 61)
                    break;
                if(tip){
                    start_choose(latimea_ecranului, inaltimea_ecranului, sunet, limba, tip);
                    break;
                }
            }
        }
}




