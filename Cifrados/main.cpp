#include "Cesar.h"
#include "Afin.h"
#include "Vigenere.h"
#include "Playfair.h"
#include "Hill.h"
#include "Vernam.h"

#include <iostream>

using namespace std;

int main()
{
    Playfair pf;

    string te = pf.Encrypt("with a little help from my friends", "beatles");

    pf.ShowMatrix();

    cout << "Texto encriptado: " << te << endl;

    return 0;
}
