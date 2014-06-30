#include "Cesar.h"

Cesar::Cesar()
{
    //ctor
}

Cesar::~Cesar()
{
    //dtor
}
string Cesar::Encrypt(string textoPlano)
{
    string  mensajeCifrado;
    int     C;  // Carater texto cifrado
    char    P;  // Caracter texto plano

    for(int i = 0; i < textoPlano.size(); i++)
    {
        if (textoPlano[i] != 32)
        {
            P = textoPlano[i] - 97;
            C = (P + 3) % 26;
            C = C + 97;
            mensajeCifrado.push_back(C);
        }
        else
        {
            mensajeCifrado.push_back(' ');
        }
    }

    return mensajeCifrado;
}

string Cesar::Descrypt(string textoCifrado)
{
    string textoPlano;
    int     C;   // Carater texto cifrado
    char    P;   // Caracter texto plano

    for(int i = 0; i < textoCifrado.size(); i++)
    {
        if (textoCifrado[i] != 32)
        {
            C = textoCifrado[i] - 97;  // caracter a numero
            P = (C - 3) % 26;

            if (C < 3)
                P = 26 - (3 - C);

            P = P + 97;    // numero a letra
            textoPlano.push_back(P);
        }
        else
        {
            textoPlano.push_back(' ');
        }
    }

    return textoPlano;
}

