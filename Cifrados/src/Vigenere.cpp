#include "Vigenere.h"

Vigenere::Vigenere()
{
    //ctor
}

Vigenere::~Vigenere()
{
    //dtor
}

string Vigenere::Encrypt(string textoPlano, string clave)
{
    string  textoCifrado;
    int     cont;           // interador de la clave
    int     ci;              // valor numerico de caracter cifrado
    int     mi;             // valor numerico de caracter cifrado del texto plano
    int     ki;             // valor numerico de caracter cifrado de la clave
    char    x;              // Caracter a agregar al texto cifrado

    cont = 0;

    for (int i = 0; i < textoPlano.size(); i++)
    {
        if (textoPlano[i] != 32)
        {
            // Convierte a su equivalente numerico
            mi = textoPlano[i] - 97;
            ki = clave[cont] - 97;

            // Valor numerico de caracter cifrado
            ci  = (mi + ki) % 26;
            // Convierte a  su valor en letra
            x  = ci + 97;

            // Agrega loa caracteres cifrados
            textoCifrado.push_back(x);

            // Recorre caracteres de la clave
            if (cont == clave.size() - 1)
                cont = 0;
            else
                cont++;
        }
        else
        {
            textoCifrado.push_back(' ');
        }
    }

    return textoCifrado;
}

string Vigenere::Decrypt(string textoCifrado, string clave)
{
    string  textoPlano;
    int     cont;           // interador de la clave
    int     ci;             // valor numerico de caracter cifrado
    int     mi;             // valor numerico de caracter cifrado del texto plano
    int     ki;             // valor numerico de caracter cifrado de la clave
    char    x;              // Caracter a agregar al texto plano

    cont = 0;

    for (int i = 0; i < textoCifrado.size(); i++)
    {
        if (textoCifrado[i] != 32)
        {
            // Convierte a su equivalente numerico
            ci = textoCifrado[i] - 97;
            ki = clave[cont] - 97;

            // Valor numerico de caracter cifrado
            if (ci < ki)
                mi = 26 - (ki - ci);
            else
                mi  = (ci - ki) % 26;

            // Convierte a  su valor en letra
            x  = mi + 97;

            // Agrega loa caracteres cifrados
            textoPlano.push_back(x);

            // Recorre caracteres de la clave
            if (cont == clave.size() - 1)
                cont = 0;
            else
                cont++;
        }
        else
        {
            textoPlano.push_back(' ');
        }
    }

    return textoPlano;
}
