#include <iostream>
#include "Playfair.h"

using namespace std;

int main()
{
    Playfair pf;

    string te = pf.Encrypt("with a little help from my friends", "beatles");

    pf.ShowMatrix();

    cout << "Texto encriptado: " << te << endl;

    return 0;
}
