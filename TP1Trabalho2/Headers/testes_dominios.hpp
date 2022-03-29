//
//  testes.hpp
//  Trabalho 1
//  Arquivo header para os testes de unidade de dominios
//
//  Created by Johann Homonnai on 27/02/22.
//
//

#ifndef Testes_hpp
#define Testes_hpp

// Incluir cabeçalhos.

#include <iostream>
#include "dominios.hpp"

using namespace std;

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Cidade
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUCidade {
private:
    const static string VALOR_VALIDO;       // Valor para cenário de sucesso
    const static string VALOR_INVALIDO;     // Valor para cenário de falha
    Cidade *cidade;                         // Referência para unidade em teste
    int estado;                             // Estado do teste
    void setUp();                           // Método para criar unidade em teste
    void tearDown();                        // Método para destruir unidade em teste
    void testarCenarioSucesso();            // Cenário de teste
    void testarCenarioFalha();              // Cenário de teste
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;            // Definição de constante para reportar resultado de teste
    const static string NOME_CLASSE;
    int run();                              // Método para executar teste
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Codigo
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUCodigo {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    Codigo *codigo;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Data
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUData {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    const static string VALOR_INVALIDO4;
    const static string VALOR_INVALIDO5;
    const static string VALOR_INVALIDO6;
    const static string VALOR_INVALIDO7;
    Data *data;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};


/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Descricao
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUDescricao {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    Descricao *descricao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Duracao
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUDuracao {
private:
    const static int VALOR_VALIDO;
    const static int VALOR_INVALIDO;
    Duracao *duracao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Email
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUEmail {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    const static string VALOR_INVALIDO4;
    const static string VALOR_INVALIDO5;
    const static string VALOR_INVALIDO6;
    const static string VALOR_INVALIDO7;
    const static string VALOR_INVALIDO8;
    const static string VALOR_INVALIDO9;
    const static string VALOR_INVALIDO10;
    Email *email;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Endereco
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUEndereco {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    Endereco *endereco;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Horario
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUHorario {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    const static string VALOR_INVALIDO4;
    Horario *horario;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Idioma
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUIdioma {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;
    Idioma *idioma;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Nome
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUNome {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    const static string VALOR_INVALIDO4;
    const static string VALOR_INVALIDO5;
    const static string VALOR_INVALIDO6;
    const static string VALOR_INVALIDO7;
    const static string VALOR_INVALIDO8;
    const static string VALOR_INVALIDO9;
    Nome *nome;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Nota
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUNota {
private:
    const static int VALOR_VALIDO;
    const static int VALOR_INVALIDO;
    Nota *nota;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Senha
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUSenha {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    const static string VALOR_INVALIDO4;
    const static string VALOR_INVALIDO5;
    Senha *senha;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};

/// @author Johann Homonnai, 17/0014151
/// @brief Classe para teste de unidade do dom&iacute;nio Titulo
/// @details tem a estrutura b&aacute;sica de todos os outros testes de unidade.

class TUTitulo {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO1;
    const static string VALOR_INVALIDO2;
    const static string VALOR_INVALIDO3;
    const static string VALOR_INVALIDO4;
    Titulo *titulo;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha(string);
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    const static string NOME_CLASSE;
    int run();
};


#endif /* Testes_hpp */
