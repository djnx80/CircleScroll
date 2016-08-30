// wykorzystanie klasy napis
//    napis abc;
//    abc.init("tahoma.ttf", 20);

/*
        al_clear_to_color(al_map_rgb(0,0,0));
        abc.napisz(100,100,"jajko");
        abc.napisz(110,130,"bleble ble", rr,rr,rr);
        abc.wypisz();
        rr++;
        if(rr>200) rr=0;
*/

#include <iostream>
#include <allegro5/allegro_ttf.h>
#include "napis.h"

using namespace std;


void napis::init(char const *fontname, int fontsize)    {
    cout <<"aa";
    fontttf = al_load_ttf_font(fontname,fontsize,0 );
}

int napis::getDlugosc() {
    return dlugosc;
}

void napis::setTekst(const char *abc)   {
    tekst = abc;
}

void napis::setTekstlitery(char *abc, int ile)  {
    dlugosc = ile;
    tekstlitery = abc;
    if (ile == 0) dlugosc = strlen(abc);

}

void napis::setXY(int ktory, float xx, float yy)   {
    pozX[ktory] = xx;
    pozY[ktory] = yy;
}

float napis::getX(int ktory) {   return pozX[ktory]; }
float napis::getY(int ktory) {   return pozY[ktory]; }


void napis::wypisz()    {
    int rgb;
    for (int i=0; i<dlugosc; i++)   {
//        rgb = (int) pozY[i]/2;
        rgb=-240 + (int) pozY[i];
        rgb=rgb*3;
        if (rgb<0) rgb=0;
        if (rgb>255) rgb=255;
        al_draw_textf (fontttf,al_map_rgb(rgb,rgb,rgb), pozX[i], pozY[i], 0 ,"%3c", tekstlitery[i]);
 //       al_draw_textf (fontttf,al_map_rgb(250,250,250), pozX[i], pozY[i], 0 ,"%3c", tekstlitery[i]);
    }
}

void napis::napisz(float xx, float yy, const char *abc) {
    tekst = abc;
    al_draw_textf (fontttf,al_map_rgb(250,250,250), xx, yy, 0 ,"%s", tekst);
}

void napis::napisz(float xx, float yy, const char *abc, unsigned char r, unsigned char g, unsigned char b)  {
    tekst = abc;
    al_draw_textf (fontttf,al_map_rgb(r,g,b), xx, yy, 0 ,"%s", tekst);
}
