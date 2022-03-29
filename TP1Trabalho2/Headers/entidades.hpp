//
//  entidades.hpp
//  Trabalho 1
//
//  Created by Johann Homonnai on 25/02/22.
//

#ifndef Entidades_hpp
#define Entidades_hpp

#include <stdio.h>
#include "dominios.hpp"

/// @author Johann Homonnai, 17/0014151
/// @brief Usuario do sistema
/// @details Cada usu&aacute;rio possui nome, e-mail e senha.


class Usuario {
private:
    Nome nomeUsuario;
    Email emailUsuario;
    Senha senhaUsuario;
public:
    void setNomeUsuario(const Nome&);
    Nome getNomeUsuario() const;
    void setEmailUsuario(const Email&);
    Email getEmailUsuario() const;
    void setSenhaUsuario(const Senha&);
    Senha getSenhaUsuario() const;
};

/// Métodos SET

/// @brief Recebe e define inst&acirc;ncia de Nome para usu&aacute;rio
/// @param nomeUsuario Nome do usu&aacute;rio

inline void Usuario::setNomeUsuario(const Nome &nomeUsuario)
{
    this->nomeUsuario = nomeUsuario;
}

/// @brief Recebe e define inst&acirc;ncia de Email para usu&aacute;rio
/// @param emailUsuario E-mail do usu&aacute;rio

inline void Usuario::setEmailUsuario(const Email &emailUsuario)
{
    this->emailUsuario = emailUsuario;
}

/// @brief Recebe e define inst&acirc;ncia de Senha para usu&aacute;rio
/// @param senhaUsuario Senha do usu&aacute;rio

inline void Usuario::setSenhaUsuario(const Senha &senhaUsuario)
{
    this->senhaUsuario = senhaUsuario;
}

/// Métodos GET

/// @brief L&ecirc; nome do usu&aacute;rio
/// @return nomeUsuario

inline Nome Usuario::getNomeUsuario() const
{
    return this->nomeUsuario;
}

/// @brief L&ecirc; e-mail do usu&aacute;rio
/// @return emailUsuario

inline Email Usuario::getEmailUsuario() const
{
    return this->emailUsuario;
}

/// @brief L&ecirc; senha do usu&aacute;rio
/// @return senhaUsuario

inline Senha Usuario::getSenhaUsuario() const
{
    return this->senhaUsuario;
}

/// @author Johann Homonnai, 17/0014151
/// @brief Excurs&atilde;o cadastrada no sistema
/// @details Cada excurs&atilde;o possui c&oacute;digo, t&iacute;tulo, nota, cidade, dura&ccedil;&atilde;o, descri&ccedil;&atilde;o e endere&ccedil;o.

class Excursao {
private:
    Codigo codigoExcursao;
    Titulo tituloExcursao;
    Nota notaExcursao;
    Cidade cidadeExcursao;
    Duracao duracaoExcursao;
    Descricao descricaoExcursao;
    Endereco enderecoExcursao;
public:
    void setCodigoExcursao(const Codigo&);
    Codigo getCodigoExcursao() const;
    void setTituloExcursao(const Titulo&);
    Titulo getTituloExcursao() const;
    void setNotaExcursao(const Nota&);
    Nota getNotaExcursao() const;
    void setCidadeExcursao(const Cidade&);
    Cidade getCidadeExcursao() const;
    void setDuracaoExcursao(const Duracao&);
    Duracao getDuracaoExcursao() const;
    void setDescricaoExcursao(const Descricao&);
    Descricao getDescricaoExcursao() const;
    void setEnderecoExcursao(const Endereco&);
    Endereco getEnderecoExcursao() const;
};

/// Métodos SET

/// @brief Recebe e define inst&acirc;ncia de Codigo para excurs&atilde;o
/// @param codigoExcursao C&oacute;digo da excurs&atilde;o

inline void Excursao::setCodigoExcursao(const Codigo &codigoExcursao)
{
    this->codigoExcursao = codigoExcursao;
}

/// @brief Recebe e define inst&acirc;ncia de Titulo para excurs&atilde;o
/// @param tituloExcursao T&iacute;tulo da excurs&atilde;o

inline void Excursao::setTituloExcursao(const Titulo &tituloExcursao)
{
    this->tituloExcursao = tituloExcursao;
}

/// @brief Recebe e define inst&acirc;ncia de Nota para excurs&atilde;o
/// @param notaExcursao Nota da excurs&atilde;o

inline void Excursao::setNotaExcursao(const Nota &notaExcursao)
{
    this->notaExcursao = notaExcursao;
}

/// @brief Recebe e define inst&acirc;ncia de Cidade para excurs&atilde;o
/// @param cidadeExcursao Cidade da excurs&atilde;o

inline void Excursao::setCidadeExcursao(const Cidade &cidadeExcursao)
{
    this->cidadeExcursao = cidadeExcursao;
}

/// @brief Recebe e define inst&acirc;ncia de Duracao para excurs&atilde;o
/// @param duracaoExcursao Dura&ccedil;&atilde;o da excurs&atilde;o

inline void Excursao::setDuracaoExcursao(const Duracao &duracaoExcursao)
{
    this->duracaoExcursao = duracaoExcursao;
}

/// @brief Recebe e define inst&acirc;ncia de Descricao para excurs&atilde;o
/// @param descricaoExcursao Descri&ccedil;&atilde; da excurs&atilde;o

inline void Excursao::setDescricaoExcursao(const Descricao &descricaoExcursao)
{
    this->descricaoExcursao = descricaoExcursao;
}

/// @brief Recebe e define inst&acirc;ncia de Endereco para excurs&atilde;o
/// @param enderecoExcursao C&oacute;digo da excurs&atilde;o

inline void Excursao::setEnderecoExcursao(const Endereco &enderecoExcursao)
{
    this->enderecoExcursao = Endereco(enderecoExcursao);
}

/// Métodos GET

/// @brief L&ecirc; c&oacute;digo da excurs&atilde;o
/// @return codigoExcursao

inline Codigo Excursao::getCodigoExcursao() const
{
    return this->codigoExcursao;
}

/// @brief L&ecirc; t&iacute;tulo da excurs&atilde;o
/// @return tituloExcursao

inline Titulo Excursao::getTituloExcursao() const
{
    return this->tituloExcursao;
}

/// @brief L&ecirc; nota da excurs&atilde;o
/// @return notaExcursao

inline Nota Excursao::getNotaExcursao() const
{
    return this->notaExcursao;
}

/// @brief L&ecirc; cidade da excurs&atilde;o
/// @return cidadeExcursao

inline Cidade Excursao::getCidadeExcursao() const
{
    return this->cidadeExcursao;
}

/// @brief L&ecirc; dura&ccedil;&atilde;o da excurs&atilde;o
/// @return duracaoExcursao

inline Duracao Excursao::getDuracaoExcursao() const
{
    return this->duracaoExcursao;
}

/// @brief L&ecirc; descri&ccedil;&atilde;o da excurs&atilde;o
/// @return descricaoExcursao

inline Descricao Excursao::getDescricaoExcursao() const
{
    return this->descricaoExcursao;
}

/// @brief L&ecirc; endere&ccedil;o da excurs&atilde;o
/// @return enderecoExcursao

inline Endereco Excursao::getEnderecoExcursao() const
{
    return this->enderecoExcursao;
}

/// @author Johann Homonnai, 17/0014151
/// @brief Sess&atilde;o de uma excurs&atilde;o
/// @details Cada sess&atilde;o possui c&oacute;digo, data, hor&aacute;rio e idioma

class Sessao {
private:
    Codigo codigoSessao;
    Data dataSessao;
    Horario horarioSessao;
    Idioma idiomaSessao;
public:
    void setCodigoSessao(const Codigo&);
    Codigo getCodigoSessao() const;
    void setDataSessao(const Data&);
    Data getDataSessao() const;
    void setHorarioSessao(const Horario&);
    Horario getHorarioSessao() const;
    void setIdiomaSessao(const Idioma&);
    Idioma getIdiomaSessao() const;
};

/// Métodos SET

/// @brief Recebe e define inst&acirc;ncia de Codigo para sesss&atilde;o
/// @param codigoSessao C&oacute;digo da sess&atilde;o

inline void Sessao::setCodigoSessao(const Codigo &codigoSessao)
{
    this->codigoSessao = codigoSessao;
}

/// @brief Recebe e define inst&acirc;ncia de Data para sesss&atilde;o
/// @param dataSessao Data da sess&atilde;o

inline void Sessao::setDataSessao(const Data &dataSessao)
{
    this->dataSessao = Data(dataSessao);
}

/// @brief Recebe e define inst&acirc;ncia de Horario para sesss&atilde;o
/// @param horarioSessao Hor&aacute;rio da sess&atilde;o

inline void Sessao::setHorarioSessao(const Horario &horarioSessao)
{
    this->horarioSessao = horarioSessao;
}

/// @brief Recebe e define inst&acirc;ncia de Idioma para sesss&atilde;o
/// @param idiomaSessao Idioma da sess&atilde;o

inline void Sessao::setIdiomaSessao(const Idioma &idiomaSessao)
{
    this->idiomaSessao = idiomaSessao;
}

/// Métodos GET

/// @brief L&ecirc; c&oacute;digo da sess&atilde;o
/// @return codigoSessao

inline Codigo Sessao::getCodigoSessao() const
{
    return this->codigoSessao;
}

/// @brief L&ecirc; data da sess&atilde;o
/// @return dataSessao

inline Data Sessao::getDataSessao() const
{
    return this->dataSessao;
}

/// @brief L&ecirc; hor&aacute;rio da sess&atilde;o
/// @return horarioSessao

inline Horario Sessao::getHorarioSessao() const
{
    return this->horarioSessao;
}

/// @brief L&ecirc; idioma da sess&atilde;o
/// @return idiomaSessao

inline Idioma Sessao::getIdiomaSessao() const
{
    return this->idiomaSessao;
}

/// @author Johann Homonnai, 17/0014151
/// @brief Avalia&ccedil;&atilde;o de uma excurs&atilde;o
/// @details Cada avalia&ccedil;&atilde;o possui c&oacute;digo, nota e descri&ccedil;&atilde;o.

class Avaliacao {
private:
    Codigo codigoAvaliacao;
    Nota notaAvaliacao;
    Descricao descricaoAvaliacao;
public:
    void setCodigoAvaliacao(const Codigo&);
    Codigo getCodigoAvaliacao() const;
    void setNotaAvaliacao(const Nota&);
    Nota getNotaAvaliacao() const;
    void setDescricaoAvaliacao(const Descricao&);
    Descricao getDescricaoAvaliacao() const;
};


/// Métodos SET

/// @brief Recebe e define inst&acirc;ncia de Codigo para avalia&ccedil;&atilde;o
/// @param codigoAvaliacao C&oacute;digo da avalia&ccedil;&atilde;o

inline void Avaliacao::setCodigoAvaliacao(const Codigo &codigoAvaliacao)
{
    this->codigoAvaliacao = codigoAvaliacao;
}

/// @brief Recebe e define inst&acirc;ncia de Nota para avalia&ccedil;&atilde;o
/// @param notaAvaliacao Nota da avalia&ccedil;&atilde;o

inline void Avaliacao::setNotaAvaliacao(const Nota &notaAvaliacao)
{
    this->notaAvaliacao = notaAvaliacao;
}

/// @brief Recebe e define inst&acirc;ncia de Descricao para avalia&ccedil;&atilde;o
/// @param descricaoAvaliacao Descri&ccedil;&atilde;o da avalia&ccedil;&atilde;o

inline void Avaliacao::setDescricaoAvaliacao(const Descricao &descricaoAvaliacao)
{
    this->descricaoAvaliacao = descricaoAvaliacao;
}

/// Métodos GET

/// @brief L&ecirc; c&oacute;digo da avalia&ccedil;&atilde;o
/// @return codigoAvaliacao

inline Codigo Avaliacao::getCodigoAvaliacao() const
{
    return this->codigoAvaliacao;
}

/// @brief L&ecirc; nota da avalia&ccedil;&atilde;o
/// @return notaAvaliacao

inline Nota Avaliacao::getNotaAvaliacao() const
{
    return this->notaAvaliacao;
}

/// @brief L&ecirc; descri&ccedil;&atilde;o da avalia&ccedil;&atilde;o
/// @return descricaoAvaliacao

inline Descricao Avaliacao::getDescricaoAvaliacao() const
{
    return this->descricaoAvaliacao;
}

#endif /* Entidades_hpp */
