#include "Playfair.h"

Playfair::Playfair()
{
    //ctor
}

Playfair::~Playfair()
{
    //dtor
}


string Playfair::Encrypt(string text, string key)
{
    string  textEncrypt;
    int     it;

    this->GenerateMatrix(text, key);

    // Verficar cadena en grupos de 2
    it = 0;

    while (it < text.length())
    {
        if (text[it+1] != ' ')
        {
            if(text[it] == text[it+1])
                text.insert(it + 1, "x");

            it += 2;
        }
        else
        {
            if(text[it] == text[it+2])
                text.insert(it + 1, "x");

            it += 3;
        }
    }

    string temp_text;

    // Cadena sin espacios, para conteo de caracteres
    for (int j = 0; j < text.size(); j++)
        if (text[j] != ' ')
            temp_text.push_back(text[j]);

    // Verifica longitud de cadena, si es impar agregamos 'x' al final
    if (temp_text.length() % 2 != 0)
        temp_text.push_back('x');

    /// Aplicar propiedades pPFC

    // Posiciones en la matriz de los caracteres del texto no cifrado
    struct Vector2i index_letter1;
    struct Vector2i index_letter2;

    // Posiciones en la matriz de caracteres a agregar al texto encriptado
    struct Vector2i index_value1;
    struct Vector2i index_value2;

    it = 0;
    cout << "Texto sin espacios: " << temp_text << endl;

    // Se toman letras 2 en 2 del texto no encriptado
    while (it < temp_text.size())
    {
        index_letter1  = this->GetIndexMatrix( temp_text[it] );
        index_letter2  = this->GetIndexMatrix( temp_text[it + 1] ) ;

        // Estan en la misma fila
        if (index_letter1.x == index_letter2.x)
        {
            cout << "Misma fila" << endl;

            // Primera letra
            if (index_letter1.y== 4)  // Esta en la ultima columna
            {
                index_value1.x = index_letter1.x;
                index_value1.y = 0;
            }
            else
            {
                index_value1.x  = index_letter1.x;
                index_value1.y = index_letter1.y + 1;
            }

            // Segunda letra
            if (index_letter2.y == 4)  // Esta en la ultima columna
            {
                index_value2.x = index_letter2.x;
                index_value2.y = 0;
            }
            else
            {
                index_value2.x  = index_letter2.x;
                index_value2.y = index_letter2.y + 1;
            }

            textEncrypt.push_back( GetLetterMatrix(index_value1) );
            textEncrypt.push_back( GetLetterMatrix(index_value2) );

        } // Estan en la misma columna
        else if (index_letter1.y == index_letter2.y)
        {
            cout << "Misma en columna" << endl;

            // Primera letra
            if (index_letter1.x == 4)  // Esta en la ultima sila
            {
                index_value1.x  = 0;
                index_value1.y = index_letter1.y;
            }
            else
            {
                index_value1.x = index_letter1.x + 1;
                index_value1.y = index_letter1.y;
            }

            // Segunda letra
            if (index_letter2.x == 4)  // Esta en la ultima fila
            {
                index_value2.x = 0;
                index_value2.y = index_letter2.y;
            }

            else
            {
                index_value2.x  = index_letter2.x + 1;
                index_value2.y = index_letter2.y;
            }

            textEncrypt.push_back( GetLetterMatrix(index_value1) );
            textEncrypt.push_back( GetLetterMatrix(index_value2) );

        } // Ni fila ni columna coinciden, se trabaja con las intersecciones
        else
        {
            cout << "Ni fila ni columna" << endl;

            index_value1.x  = index_letter1.x;
            index_value1.y  = index_letter2.y;

            index_value2.x  = index_letter2.x;
            index_value2.y  = index_letter1.y;

            textEncrypt.push_back( GetLetterMatrix(index_value1) );
            textEncrypt.push_back( GetLetterMatrix(index_value2) );
        }

        it += 2;
        cout << "Encriptacion de a 2: " << textEncrypt << endl << endl;
    }

    for (int j = 0; j < text.size(); j++)
        if (text[j] == ' ')
            textEncrypt.insert(j, " ");

    return textEncrypt;
}

void Playfair::GenerateMatrix(string text, string key)
{
    string  values;
    int     it;
    int     ascii;

    it = 0;

    // Se agrega caracteres de la clave
    while (it < key.size())
    {
        if (values.find(key[it], 0) == -1)
        {
            if (key[it] == 'j')
            {
                if (values.find('i', 0) == -1)
                    values.push_back('i');
            }
            else if (key[it] == -92) // (Windows)por al alguna razon el ascii de la ñ  se convierte a -92
            {
                if (values.find('n', 0) == -1)
                    values.push_back('n');
            }
            else
            {
                values.push_back(key[it]);
            }
        }

        it++;
    }

    it      = 0;
    ascii   = 97;

    // Se agrega caracteres que faltan del alfabeto (sin repetir)
    while (ascii <= 122)
    {
        char letter = char(ascii);

        if (letter != 'j')
        {
            if (values.find(letter, 0) == -1)
                values.push_back(letter);
        }
        ascii++;
    }

    it = 0;

    // Se agrega todos los valores en la matriz
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            m_matrix[i][j] = values[it++];
}

void Playfair::ShowMatrix()
{
    cout << "Matrix: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\t";

        for (int j = 0; j < 5; j++)
        {
            cout << m_matrix[i][j] << ' ';
        }

        cout << endl;
    }
}

Vector2i Playfair::GetIndexMatrix(char letter)
{
    struct Vector2i index;

    // Valores por defecto, si no es encontrado
    index.x = -1;
    index.y = -1;

    // Busqueda en la matriz
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (m_matrix[i][j] == letter)
            {
                index.x = i;
                index.y = j;

                return index;
            }
        }
    }

    return index;
}

char Playfair::GetLetterMatrix(Vector2i index)
{
    return  m_matrix[index.x][index.y];
}

