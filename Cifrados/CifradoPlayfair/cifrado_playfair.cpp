#include <iostream>
#include <string>
#include <vector>

#define SIZE 5

using namespace std;

// Caracteres de la a - z
vector<char> alfabeto;

template<class T>
void Mostrar(vector<T> _vector)
{
    for(int i = 0; i < _vector.size(); i++)
        cout << _vector[i] << "\t";

    cout << endl;
}

vector<char> CrearAlfabeto()
{
    vector<char> alf(26);

    for (int i = 0; i < 26; i++)
        alf[i] = i + 97;

    return alf;
}

bool ExisteEnAlfabeto(char c)
{

    return false;
}

void GenerarMatriz(string text, string key)
{
    char matrix[SIZE][SIZE];

    string valores;

    valores.append(key[0]):

    int i = 0;

    while (i < key.size())
    {
        if ()
        valores.find(key[i],);
        i++;
    }


}

int main()
{
    string text, key;
    //alfabeto = CrearAlfabeto();

    getline(cin, text, '\n');
    getline(cin, key, '\n');

    cout << text << endl;
    cout << key << endl;

    GenerarMatriz(text, key);


    return 0;
}
