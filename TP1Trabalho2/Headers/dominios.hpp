///
///  Declaração das classes de domínios: dominios.hpp
///  Trabalho 1 - Técnicas de Programação 1, Turma C
///  Feito por Johann Homonnai, matrícula: 17/0014151
///

#ifndef Dominios_hpp
#define Dominios_hpp

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;


///----------------------------------------------
/// Declaração da classe Cidade
///----------------------------------------------
///
/// @author Johann Homonnai - 17/0014151
/// @brief Cidade da excurs&atilde;o
/// @details Nome próprio de uma das cidades da lista fornecida
///

class Cidade
{
private:
    static vector<string> CIDADES;
    static string PADRAO;
    void validar(string);
    string cidade;
public:
    Cidade();
    Cidade(string);
    void setCidade(string);
    string getCidade() const;
};

///
/// @brief Retorna a cidade da excurs&atilde;o
/// @return Cidade
///

inline string Cidade::getCidade() const
{
    return this->cidade;
}

///----------------------------------------------
/// Declaração da classe Codigo
///----------------------------------------------
///
/// @author Johann Homonnai - 17/0014151
/// @brief C&oacute;digo da excurs&atilde;o.
/// @details Constitu&iacute;do por 7 d&iacute;gitos, n&atilde;o podendo ser todo de zeros.
///

class Codigo {
private:
    const static int TAM = 7;
    static string ERRADO;
    static string PADRAO;
    string codigo;
    void validar(string);
public:
    Codigo();
    Codigo(string);
    void setCodigo(string);
    string getCodigo() const;
};

///
/// @brief Retorna o valor armazenado em c&oacute;digo.
/// @return c&oacute;digo
///

inline string Codigo::getCodigo() const
{
    return this->codigo;
}

///----------------------------------------------
/// Declaração da classe Data
///----------------------------------------------

/// @author Johann Homonnai, 17/0014151
/// @brief Classe que armazena a data da excurs&atilde;o
/// @details A data &eacute; no formado DD-MES-AAAA, sendo que DD - 01 a 31, MES - Jan, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez e AA - 2000 a 9999. A data considera a ocorr&ecirc;ncia de ano bissexto.

class Data {
private:
    const static int MIN_ANO = 2000;
    const static int MAX_ANO = 9999;
    const static int MIN_DIA = 0;
    const static int MAX_DIA = 31;
    static vector<string> MESES;
    static string PADRAO;
    string data;
    void validar(string);
public:
    Data();
    Data(string);
    void setData(string);
    string getData();
    tuple<string, string, string> separaData(string);
};

///
/// @brief Retorna a data da excurs&atilde;o
/// @return Data
///

inline string Data::getData()
{
    return this->data;
}


///----------------------------------------------
/// Declaração da classe Descricao
///----------------------------------------------
///
/// @author Johann Homonnai - 17/0014151
/// @brief Descri&ccedil;&atilde;o da excurs&atilde;o.
/// @details Tem um máximo de 30 caracteres.
///

class Descricao
{
private:
    static const int TAM_MAX = 30; // Não pode superar 30 caracteres
    static string PADRAO;
    string descricao;
    void validar(string);
public:
    Descricao();
    Descricao(string);
    void setDescricao(string);
    string getDescricao();
};

///
/// @brief Pega valor armazenado em descricao
/// @return Descrição
///

inline string Descricao::getDescricao()
{
    return this->descricao;
}

///----------------------------------------------
/// Declaração da classe Duracao
///----------------------------------------------

/// @author Johann Homonnai - 17/0014151
/// @brief Duração da excurs&atilde;o.
/// @details É constituída por um valor dentre  30, 60, 90, 120, 180.
///

class Duracao
{
private:
    int duracao;
    static int PADRAO;
    static vector<int> DURACOES;
    void validar(int);
public:
    Duracao();
    Duracao(int);
    void setDuracao(int);
    int getDuracao();
};

///
/// @brief Retorna a dura&ccedil;&atilde;o da excurs&atilde;o
/// @return Dura&ccedil;&atilde;o
///

inline int Duracao::getDuracao()
{
    return this->duracao;
}


///----------------------------------------------
/// Declaração da classe Email
///----------------------------------------------

/// @author Johann Homonnai - 17/0014151
/// @brief E-mail do usu&atilde;rio.
/// @details Mostra o e-mail de cada usu&atilde;rio. O formato é parte-local@dominio. Parte-local tem at&etilde; 64 caracteres. Dominio tem at&etilde; 253 caracteres.

class Email {
private:
    const static int MAX_PARTE_LOCAL = 64;
    const static int MAX_DOMINIO = 253;
    static vector<char> ESPECIAIS;
    static string PADRAO;
    string email;
    void validar(string);
public:
    Email();
    Email(string);
    string getEmail();
    void setEmail(string);
};

/// @brief Retorna valor armazenado em email
/// @return Email

inline string Email::getEmail()
{
    return this->email;
}

///----------------------------------------------
/// Declaração da classe Endereco
///----------------------------------------------

/// @author Johann Homonnai, 17/0014151
/// @brief Classe que armazena o endere&ccedil;o da excurs&atilde;o.
/// @details Deve conter de 0 a 20 caracteres, sem espa&ccedil;os em branco nem pontos (.) em sequ&ecirc;ncia.

class Endereco {
private:
    const static int MAX = 20;
    static string PADRAO;
    string endereco;
    void validar(string);
public:
    Endereco();
    Endereco(string);
    void setEndereco(string);
    string getEndereco();
};

/// @brief Retorna valor armazenado em endereco
/// @return Endere&ccedil;o

inline string Endereco::getEndereco()
{
    return this->endereco;
}


///----------------------------------------------
/// Declaração da classe Horario
///----------------------------------------------

/// @author Johann Homonnai, 17/0014151
/// @brief Classe que armazena o hor&aacute;rio da excurs&atilde;o.
/// @details Hor&aacute;rio deve ser no formato HH:MM, sendo que HH - 00 a 23 e MM - 00 a 59.

class Horario {
private:
    const static int MAX_HORA = 23;
    const static int MIN_HORA = 0;
    const static int MAX_MINUTOS = 59;
    const static int MIN_MINUTOS = 0;
    static string PADRAO;
    string horario;
    void validar(string);
public:
    Horario();
    Horario(string);
    void setHorario(string);
    string getHorario();
};

/// @brief Retorna hor&aacute;rio da excurs&atilde;o.
/// @return Hor&aacute;rio

inline string Horario::getHorario()
{
    return this->horario;
}


///----------------------------------------------
/// Declaração da classe Idioma
///----------------------------------------------

/// @author Johann Homonnai, 17/0014151
/// @brief Classe que armazena o idioma do usu&aacute;rio.
/// @details Idioma deve estar presente na lista fornecida.

class Idioma {
private:
    static vector<string> IDIOMAS;
    static string PADRAO;
    string idioma;
    void validar(string);
public:
    Idioma();
    Idioma(string);
    void setIdioma(string);
    string getIdioma();
    inline string getPadrao(){return this->PADRAO;}
};

/// @brief Retorna idioma do usu&aacute;rio.
/// @return Idioma

inline string Idioma::getIdioma()
{
    return this->idioma;
}

///----------------------------------------------
/// Declaração da classe Nome
///----------------------------------------------

/// @author Johann Homonnai, 17/0014151
/// @brief Classe que armazena o nome do usu&aacute;rio.
/// @details Nome deve conter de 5 a 20 caracteres. Primeira letra de cada termo &eacute; letra mai&uacute;scula.

class Nome {
private:
    const static int MIN_NOME = 5;
    const static int MAX_NOME = 20;
    static string PADRAO;
    string nome;
    void validar(string);
public:
    Nome();
    Nome(string);
    void setNome(string);
    string getNome();
};

/// @brief Retorna nome do usu&aacute;rio.
/// @return Nome

inline string Nome::getNome()
{
    return this->nome;
}

///----------------------------------------------
/// Declaração da classe Nota
///----------------------------------------------

/// @author Johann Homonnai, 17/0014151
/// @brief Classe que armazena a nota de uma excurs&atilde;o.
/// @details A nota &eacute; dada de 0 a 5.

class Nota {
private:
    static int PADRAO;
    int nota;
    void validar(int);
public:
    Nota();
    Nota(int);
    void setNota(int);
    int getNota();
};

/// @brief Retorna nota da excurs&atilde;o
/// @return Nota

inline int Nota::getNota()
{
    return this->nota;
}

///----------------------------------------------
/// Declaração da classe Senha
///----------------------------------------------

/// @author Johann Homonnai, 17/0014151
/// @brief Classe que armazena a senha do usu&aacute;rio
/// @details Senha tem formato XXXXXX, sendo cada caractere letra ou d&iacute;gito. N&atilde;o existe caractere repetido e existe pelo menos uma letra mai&uacute;scula, uma letra min&uacute;scula e um d&iacute;gito.

class Senha {
private:
    const static int TAM = 6;
    static string PADRAO;
    string senha;
    void validar(string);
public:
    Senha();
    Senha(string);
    void setSenha(string);
    string getSenha();
};

/// @brief Retorna a senha do usu&aacute;rio
/// @return Senha

inline string Senha::getSenha()
{
    return this->senha;
}


///----------------------------------------------
/// Declaração da classe Titulo
///----------------------------------------------

/// @author Johann Homonnai, 17/0014151
/// @brief Classe que armazena o t&iacute;tulo da excurs&atilde;o.
/// @details O t&iacute;tulo &eacute; composto de 5 a 20 letras. N&atilde;o h&aacute; espa&ccedil;os em branco nem pontos (.) em sequ&ecirc;ncia.

class Titulo {
private:
    const static int TAM_MIN = 5;
    const static int TAM_MAX = 20;
    static string PADRAO;
    string titulo;
    void validar(string);
public:
    Titulo();
    Titulo(string);
    void setTitulo(string);
    string getTitulo();
};

/// @brief Retorna t&iacute;tulo da excurs&atilde;o
/// @return Titulo

inline string Titulo::getTitulo()
{
    return this->titulo;
}
    
#endif /* Dominios_hpp */
