#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void menu()
{
    cout << "\n\n\t Cifrado de Cesar \n\n";
    cout << "\t 1. Encriptar \n";
    cout << "\t 2. Desencriptar \n";
    cout << "\t 3. Salir \n";

    cout << "\n\t Opcion > ";
}

bool VerificarMensaje(string mensaje)
{
    for (int i=0; i < mensaje.size(); i++)
    {
        if ( mensaje[i] != 32 && (mensaje[i] > 122 || mensaje[i] < 97) )
            return false;
    }

    return true;
}

vector<char> DefinirAlfabeto()
{
    vector<char> alfabeto;

    for(int i = 0; i < 26; i++)
    {
        char x =  i + 97;
        alfabeto.push_back(x);
    }

    return alfabeto;
}


string Encriptar(string textoPlano, vector<char> alfabeto)
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

string Desencriptar(string textoCifrado, vector<char> alfabeto)
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


int main()
{
    vector<char>    alfabeto;
    string          textoPlano;
    string          textoCifrado;
    int             opcion;

    alfabeto = DefinirAlfabeto();

    do
    {
        menu(); cin >> opcion;

        textoCifrado.clear();
        textoPlano.clear();
        cout << endl;

        switch (opcion)
        {
            case 1:

                cout << " Texto Plano: ";
                cin.ignore();
                getline(cin, textoPlano);

                if (VerificarMensaje(textoPlano))
                {
                    textoCifrado = Encriptar(textoPlano, alfabeto);
                    cout << "\n Texto Cifrado: " << textoCifrado << endl;
                }
                else
                {
                    cout << "\n Texto no valido!" << endl;
                }

                break;

            case 2:

                cout << " Texto Cifrado: ";
                cin.ignore();
                getline(cin, textoCifrado);

                if (VerificarMensaje(textoCifrado))
                {
                    textoPlano = Desencriptar(textoCifrado, alfabeto);
                    cout << "\n Texto Plano: " << textoPlano << endl;
                }
                else
                {
                    cout << "\n Texto no valido!" << endl;
                }

                break;

            case 3:

                exit(0);
        }

        cout << endl;
        system("pause");
        system("cls");

    } while(opcion != 3);

    return 0;
}
