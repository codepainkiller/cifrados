#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <iostream>
#include <string>

using namespace std;

struct Vector2i{
    int x, y;
};

class Playfair
{
    public:
        Playfair();
        ~Playfair();

        string    Encrypt(string text, string key);
        //string    Decrypt(string text, string key);
        void      ShowMatrix();


    private:

        // Genera la matriz usada para esta encriptacion
        void     GenerateMatrix(string text, string key);

        // Retorna los indices el caracter bsucado en la matriz
        Vector2i GetIndexMatrix(char letter);

        // Dada una posicion, retorna el caracter de la matriz
        char     GetLetterMatrix(Vector2i index);


        /// Atributos

        char     m_matrix[5][5];

};


#endif // PLAYFAIR_H
