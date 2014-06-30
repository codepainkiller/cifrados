#ifndef CESAR_H
#define CESAR_H

#include <string>
#include <iostream>

using namespace std;

class Cesar
{
    public:
        Cesar();
        ~Cesar();

        string Encrypt(string textoPlano);
        string Descrypt(string textoCifrado);

    private:
};

#endif // CESAR_H
