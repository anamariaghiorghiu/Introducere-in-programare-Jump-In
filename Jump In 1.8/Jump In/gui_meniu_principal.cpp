#include "graphics.h"

void show_romana_sound_on(int w, int h, int tip){
    switch(tip){
    case 1:
        readimagefile("jpg/meniu/soundon_romana_glow_1.jpg", 0, 0, w, h);
        break;
    case 2:
        readimagefile("jpg/meniu/soundon_romana_glow_2.jpg", 0, 0, w, h);
        break;
    case 3:
        readimagefile("jpg/meniu/soundon_romana_glow_3.jpg", 0, 0, w, h);
        break;
    default:
        readimagefile("jpg/meniu/soundon_romana.jpg", 0, 0, w, h);
        break;
    }
}
void show_romana_sound_off(int w, int h, int tip){
    switch(tip){
    case 1:
        readimagefile("jpg/meniu/soundoff_romana_glow_1.jpg", 0, 0, w, h);
        break;
    case 2:
        readimagefile("jpg/meniu/soundoff_romana_glow_2.jpg", 0, 0, w, h);
        break;
    case 3:
        readimagefile("jpg/meniu/soundoff_romana_glow_3.jpg", 0, 0, w, h);
        break;
    default:
        readimagefile("jpg/meniu/soundoff_romana.jpg", 0, 0, w, h);
        break;
    }
}
void show_engleza_sound_on(int w, int h, int tip){
    switch(tip){
    case 1:
        readimagefile("jpg/meniu/soundon_engleza_glow_1.jpg", 0, 0, w, h);
        break;
    case 2:
        readimagefile("jpg/meniu/soundon_engleza_glow_2.jpg", 0, 0, w, h);
        break;
    case 3:
        readimagefile("jpg/meniu/soundon_engleza_glow_3.jpg", 0, 0, w, h);
        break;
    default:
        readimagefile("jpg/meniu/soundon_engleza.jpg", 0, 0, w, h);
        break;
    }
}
void show_engleza_sound_off(int w, int h, int tip){
    switch(tip){
    case 1:
        readimagefile("jpg/meniu/soundoff_engleza_glow_1.jpg", 0, 0, w, h);
        break;
    case 2:
        readimagefile("jpg/meniu/soundoff_engleza_glow_2.jpg", 0, 0, w, h);
        break;
    case 3:
        readimagefile("jpg/meniu/soundoff_engleza_glow_3.jpg", 0, 0, w, h);
        break;
    default:
        readimagefile("jpg/meniu/soundoff_engleza.jpg", 0, 0, w, h);
        break;
    }
}
void show_franceza_sound_on(int w, int h, int tip){
    switch(tip){
    case 1:
        readimagefile("jpg/meniu/soundon_franceza_glow_1.jpg", 0, 0, w, h);
        break;
    case 2:
        readimagefile("jpg/meniu/soundon_franceza_glow_2.jpg", 0, 0, w, h);
        break;
    case 3:
        readimagefile("jpg/meniu/soundon_franceza_glow_3.jpg", 0, 0, w, h);
        break;
    default:
        readimagefile("jpg/meniu/soundon_franceza.jpg", 0, 0, w, h);
        break;
    }
}
void show_franceza_sound_off(int w, int h, int tip){
    switch(tip){
    case 1:
        readimagefile("jpg/meniu/soundoff_franceza_glow_1.jpg", 0, 0, w, h);
        break;
    case 2:
        readimagefile("jpg/meniu/soundoff_franceza_glow_2.jpg", 0, 0, w, h);
        break;
    case 3:
        readimagefile("jpg/meniu/soundoff_franceza_glow_3.jpg", 0, 0, w, h);
        break;
    default:
        readimagefile("jpg/meniu/soundoff_franceza.jpg", 0, 0, w, h);
        break;
    }
}
void show_japoneza_sound_on(int w, int h, int tip){
    switch(tip){
    case 1:
        readimagefile("jpg/meniu/soundon_japoneza_glow_1.jpg", 0, 0, w, h);
        break;
    case 2:
        readimagefile("jpg/meniu/soundon_japoneza_glow_2.jpg", 0, 0, w, h);
        break;
    case 3:
        readimagefile("jpg/meniu/soundon_japoneza_glow_3.jpg", 0, 0, w, h);
        break;
    default:
        readimagefile("jpg/meniu/soundon_japoneza.jpg", 0, 0, w, h);
        break;
    }
}
void show_japoneza_sound_off(int w, int h, int tip){
    switch(tip){
    case 1:
        readimagefile("jpg/meniu/soundoff_japoneza_glow_1.jpg", 0, 0, w, h);
        break;
    case 2:
        readimagefile("jpg/meniu/soundoff_japoneza_glow_2.jpg", 0, 0, w, h);
        break;
    case 3:
        readimagefile("jpg/meniu/soundoff_japoneza_glow_3.jpg", 0, 0, w, h);
        break;
    default:
        readimagefile("jpg/meniu/soundoff_japoneza.jpg", 0, 0, w, h);
        break;
    }
}
