// obracający sie napis

//#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include "allegroStart.h"
#include "napis.h"
#include "flash.h"
#include <stdio.h>      /* printf */
#include <math.h>       /* sin */
#include <string>

#define PI 3.14159265

using namespace std;

void circleScroll();

allegroStart mA(800,600);
ALLEGRO_DISPLAY *okno = mA.openWindow();
ALLEGRO_BITMAP  *bitmapa = mA.openBitmap(800,600);
ALLEGRO_BITMAP  *bitmapa_tlo = mA.openBitmap(800,600);
ALLEGRO_KEYBOARD_STATE klawisz;
ALLEGRO_LOCKED_REGION *lr;
unsigned char *ptr;

void *__gxx_personality_v0;


int main()
{

    circleScroll();
	return 0;
}


void circleScroll() {
    float xt,yt, alfa=0, alfaStart = 0;
    float rx=100;
    float licznik;

    napis abc;
    abc.init("tahoma.ttf", 20);
    abc.setTekstlitery((char *)"TO JEST NAPIS BEZ ZNACZENIA...", 0);

    flash migaj;
    cout <<"jest?";
    migaj.setFlash(2,false,0);
    cout <<"jest?";


    while( !al_key_down( & klawisz, ALLEGRO_KEY_ESCAPE ) )    {

        alfa = alfaStart;
        lr = al_lock_bitmap(bitmapa, ALLEGRO_PIXEL_FORMAT_ABGR_8888, ALLEGRO_LOCK_WRITEONLY);
        ptr = (unsigned char *)lr->data;

        for (int i=0; i<abc.getDlugosc(); i++)
        {
            xt = sin (alfa*PI/180)*rx;
            yt = cos (alfa*PI/180)*50;
            abc.setXY(i,400+xt,300+yt);
            alfa=alfa+10;
        }

        alfaStart=alfaStart-1;
        rx=rx+0.2;


        licznik+=0.1;
        if (licznik>5) migaj.mignij();
            else al_clear_to_color(al_map_rgb(0,0,0));

        abc.wypisz();

        al_draw_bitmap(bitmapa,0,0,0);
        al_unlock_bitmap(bitmapa);
        al_flip_display();
        al_get_keyboard_state( & klawisz );
        al_rest(0.004);
        }
}


void flashScreen(unsigned char jasnosc)  {
     al_clear_to_color(al_map_rgb(jasnosc, jasnosc, jasnosc));

}

