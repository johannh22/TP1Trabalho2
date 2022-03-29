//
//  auxiliar.cpp
//  Trabalho 1
//
//  Created by Johann Homonnai on 27/02/22.
//

#include "auxiliar.hpp"

/// @brief Verifica se uma string cont&eacute;m pontos em sequ&ecirc;ncia
/// @param teste String a ser testada
/// @return true se a string possui pontos em sequ&ecirc;ncia, false caso contr&aacute;rio

bool pontoEmSequencia(string teste)
{
    bool ultimoPonto = false;
    unsigned long tam = teste.length();
    
    for (int i = 0; i < tam; i++)
    {
        if (teste[i] == '.') {
            if (ultimoPonto)
                return true;
            ultimoPonto = true;
        }
        else ultimoPonto = false;
    }
    
    return false;
}

/// @brief Verifica se uma string cont&eacute;m espa&ccedil;os em sequ&ecirc;ncia
/// @param teste String a ser testada
/// @return true se a string possui espa&ccedil;os em sequ&ecirc;ncia, false caso contr&aacute;rio

bool espacoEmSequencia(string teste)
{
    bool ultimoEspaco = false;
    unsigned long tam = teste.length();
    
    for (int i = 0; i < tam; i++)
    {
        if (teste[i] == ' ') {
            if (ultimoEspaco)
                return true;
            ultimoEspaco = true;
        }
        else ultimoEspaco = false;
    }
    
    return false;
}
