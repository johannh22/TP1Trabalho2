//
//  testes_entidades.hpp
//  Trabalho 1
//
//  Created by Johann Homonnai on 27/02/22.
//
//  Arquivo header para testes de unidade de entidades
//

#ifndef testes_entidades_hpp
#define testes_entidades_hpp

#include <iostream>
#include "entidades.hpp"
#include "dominios.hpp"

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade da entidade Usuario
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUUsuario {
private:
    const static string NOME_VALIDO;
    const static string EMAIL_VALIDO;
    const static string SENHA_VALIDA;
    Usuario *usuario;                       // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    const static string NOME_CLASSE;
    int run();                              // Método para executar teste.
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade da entidade Excursao
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUExcursao {
private:
    const static string CODIGO_VALIDO;
    const static string TITULO_VALIDO;
    const static int NOTA_VALIDA;
    const static string CIDADE_VALIDA;
    const static int DURACAO_VALIDA;
    const static string DESCRICAO_VALIDA;
    const static string ENDERECO_VALIDO;
    Excursao *excursao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade da entidade Sessao
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUSessao {
private:
    const static string CODIGO_VALIDO;
    const static string DATA_VALIDA;
    const static string HORARIO_VALIDO;
    const static string IDIOMA_VALIDO;
    Sessao *sessao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade da entidade Avaliacao
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUAvaliacao {
private:
    const static string CODIGO_VALIDO;
    const static int NOTA_VALIDA;
    const static string DESCRICAO_VALIDA;
    Avaliacao *avaliacao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    const static string NOME_CLASSE;
    int run();
};

#endif /* testes_entidades_hpp */
