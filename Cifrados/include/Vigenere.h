#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <iostream>

using namespace std;

class Vigenere
{
    public:
        Vigenere();
        ~Vigenere();

        string Encrypt(string textoPlano, string clave);
        string Decrypt(string textoCifrado, string clave);

    private:


};

#endif // VIGENERE_H
