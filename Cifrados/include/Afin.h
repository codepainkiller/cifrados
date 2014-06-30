#ifndef AFIN_H
#define AFIN_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Afin
{
    public:
        Afin();
        ~Afin();

        string Encrypt(string textoPlano, int a, int b);
        string Descrypt(string textoCifrado, int a, int b);

    private:

        vector<int> EuclidesExtendido(int a, int b);
        int InvMultiplicativo(int a, int n);

};

#endif // AFIN_H
