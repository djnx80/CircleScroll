#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "flash.h"

using namespace std;

void flash::setFlash(int delta, bool wObieStrony, int ustawStan)  {
    cout <<"?";
    przyrost = delta;
    // wJednaStrone = true 0->255
    // wJednaStrone = false 0->255->0
    wJednaStrone = wObieStrony;
    stan = ustawStan;
    czyKoniec = false;
}

void flash::mignij()    {
    stan = stan + przyrost;
    if (stan<0)
    {
        stan = 0;
        czyKoniec = true;
    }
    if (stan>250)
    {
        stan = 250;
        przyrost = -przyrost;
    }

    al_clear_to_color(al_map_rgb(stan, stan, stan));

}

