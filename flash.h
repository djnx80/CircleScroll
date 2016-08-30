using namespace std;

class flash
{
private:
    int przyrost;
    bool wJednaStrone;
    unsigned char stan;
    bool czyKoniec;

public:
    void setFlash(int, bool, int);
    void mignij();
};
