#include "Afin.h"

Afin::Afin()
{
    //ctor
}

Afin::~Afin()
{
    //dtor
}

string Afin::Encrypt(string textoPlano, int a, int b)
{
    string  mensajeCifrado;
    int     C;  // Carater texto cifrado
    char    P;  // Caracter texto plano

    for(int i = 0; i < textoPlano.size(); i++)
    {
        if (textoPlano[i] != 32)
        {
            P = textoPlano[i] - 97;
            C = (a * P + b) % 26;
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

string Afin::Descrypt(string textoCifrado, int a, int b)
{
    string textoPlano;
    int     C;          // Caracter texto cifrado
    char    P;          // Caracter texto plano
    int     inverso_a;

    inverso_a = this->InvMultiplicativo(a, 26);

    cout << " Inverso a: " << inverso_a << endl;

    for(int i = 0; i < textoCifrado.size(); i++)
    {
        if (textoCifrado[i] != 32)
        {
            C = textoCifrado[i] - 97;  // caracter a numero
            P = (inverso_a * C + 26 % b) % 26;

            if (P < 0)
                P = 25 - C;

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

vector<int> Afin::EuclidesExtendido(int a, int b)
{
    vector<int> arr(3, 0); // [d, x, y]
    int x1, x2, y1, y2; // variables temporales
    int q, r; // variables cociente y resto

// Caso base
    if (b == 0)
    {
        arr[0] = a; // d
        arr[1] = 1; // x
        arr[2] = 0; // y
        return arr;
    }

// Inicializamos variables
    x1 = 0;
    x2 = 1;
    y1 = 1;
    y2 = 0;

    while (b > 0)
    {
        q = a / b;
        r = a - q * b;

        arr[1] = x2 - q * x1; // x
        arr[2] = y2 - q * y1; // y

        a = b;
        b = r;

        x2 = x1;
        y2 = y1;

        x1 = arr[1];
        y1 = arr[2];
    }
    arr[0] = a;
    arr[1] = x2;
    arr[2] = y2;

    return arr;
}

int Afin::InvMultiplicativo(int a, int n)
{
    vector<int> _mcd;

    _mcd = EuclidesExtendido(n, a);

    int d = _mcd[0];
    int x = _mcd[1];
    int y = _mcd[2];

    cout << " mcd = " << d << endl;

    if (d != 1)
    {
        return -1; // No es inversible!
    }
    else
    {
        if (y < 0)
            return y + n;
        else
            return y;
    }
}
