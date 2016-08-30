//#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

class napis
{

    private:
        ALLEGRO_FONT *fontttf;
        const char *tekst;
        char *tekstlitery;
        int dlugosc;
        float pozX[200];
        float pozY[200];

    public:
        void init(char const *, int);
        void napisz(float, float, const char *);
        void napisz(float, float, const char *, unsigned char, unsigned char, unsigned char);
        void setTekst(const char *);
        void setTekstlitery(char *, int);
        void setXY(int, float, float);
        float getX(int);
        float getY(int);
        void wypisz();
        int getDlugosc();


};

