//
//  testes_entidades.cpp
//  Trabalho 1
//
//  Created by Johann Homonnai on 27/02/22.
//

#include "testes_entidades.hpp"

///----------------------------------------------
/// Implementação da classe TUUsuario
///----------------------------------------------

const string TUUsuario::NOME_VALIDO  = "Satoru Gojo";
const string TUUsuario::EMAIL_VALIDO = "satoru_gojo@jujutsu.jp";
const string TUUsuario::SENHA_VALIDA = "Megum1";
const string TUUsuario::NOME_CLASSE  = "USUARIO";

void TUUsuario::setUp(){
    usuario = new Usuario();
    estado = SUCESSO;
}

void TUUsuario::tearDown(){
    delete usuario;
}

void TUUsuario::testarCenarioSucesso(){
    Nome nome;
    nome.setNome(NOME_VALIDO);
    cout << "Nome Válido: " << NOME_VALIDO << endl;
    usuario->setNomeUsuario(nome);
    if (usuario->getNomeUsuario().getNome() != NOME_VALIDO)
        estado = FALHA;
    
    Email email;
    email.setEmail(EMAIL_VALIDO);
    cout << "E-mail Válido: " << EMAIL_VALIDO << endl;
    usuario->setEmailUsuario(email);
    if (usuario->getEmailUsuario().getEmail() != EMAIL_VALIDO)
        estado = FALHA;
    
    Senha senha;
    senha.setSenha(SENHA_VALIDA);
    cout << "Senha Válida: " << SENHA_VALIDA << endl;
    usuario->setSenhaUsuario(senha);
    if (usuario->getSenhaUsuario().getSenha() != SENHA_VALIDA)
        estado = FALHA;
}

int TUUsuario::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

///----------------------------------------------
/// Implementação da classe TUExcursao
///----------------------------------------------

const string TUExcursao::CODIGO_VALIDO    = "1234567";
const string TUExcursao::TITULO_VALIDO    = "Passeio no parque";
const string TUExcursao::CIDADE_VALIDA    = "Nova Iorque";
const string TUExcursao::DESCRICAO_VALIDA = "Visita Central Park";
const string TUExcursao::ENDERECO_VALIDO  = "Central Park NY";
const int TUExcursao::NOTA_VALIDA         = 5;
const int TUExcursao::DURACAO_VALIDA      = 180;
const string TUExcursao::NOME_CLASSE      = "EXCURSAO";

void TUExcursao::setUp(){
    excursao = new Excursao();
    estado = SUCESSO;
}

void TUExcursao::tearDown(){
    delete excursao;
}

void TUExcursao::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setCodigo(CODIGO_VALIDO);
    cout << "Código Válido: " << CODIGO_VALIDO << endl;
    excursao->setCodigoExcursao(codigo);
    if (excursao->getCodigoExcursao().getCodigo() != CODIGO_VALIDO)
        estado = FALHA;
    
    Titulo titulo;
    titulo.setTitulo(TITULO_VALIDO);
    cout << "Título Válido: " << TITULO_VALIDO << endl;
    excursao->setTituloExcursao(titulo);
    if (excursao->getTituloExcursao().getTitulo() != TITULO_VALIDO)
        estado = FALHA;
    
    Nota nota;
    nota.setNota(NOTA_VALIDA);
    cout << "Nota Válida: " << NOTA_VALIDA << endl;
    excursao->setNotaExcursao(nota);
    if (excursao->getNotaExcursao().getNota() != NOTA_VALIDA)
        estado = FALHA;
    
    Cidade cidade;
    cidade.setCidade(CIDADE_VALIDA);
    cout << "Cidade Válida: " << CIDADE_VALIDA << endl;
    excursao->setCidadeExcursao(cidade);
    if (excursao->getCidadeExcursao().getCidade() != CIDADE_VALIDA)
        estado = FALHA;
    
    Duracao duracao;
    duracao.setDuracao(DURACAO_VALIDA);
    cout << "Duração Válida: " << DURACAO_VALIDA << endl;
    excursao->setDuracaoExcursao(duracao);
    if (excursao->getDuracaoExcursao().getDuracao() != DURACAO_VALIDA)
        estado = FALHA;
    
    Descricao descricao;
    descricao.setDescricao(DESCRICAO_VALIDA);
    cout << "Descrição Válida: " << DESCRICAO_VALIDA << endl;
    excursao->setDescricaoExcursao(descricao);
    if (excursao->getDescricaoExcursao().getDescricao() != DESCRICAO_VALIDA)
        estado = FALHA;
    
    Endereco endereco;
    endereco.setEndereco(ENDERECO_VALIDO);
    cout << "Endereço Válido: " << ENDERECO_VALIDO << endl;
    excursao->setEnderecoExcursao(endereco);
    if (excursao->getEnderecoExcursao().getEndereco() != ENDERECO_VALIDO)
        estado = FALHA;
    
}

int TUExcursao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

///----------------------------------------------
/// Implementação da classe TUSessao
///----------------------------------------------

const string TUSessao::CODIGO_VALIDO  = "7654321";
const string TUSessao::DATA_VALIDA    = "02/Fev/2022";
const string TUSessao::HORARIO_VALIDO = "14:30";
const string TUSessao::IDIOMA_VALIDO  = "Frances";
const string TUSessao::NOME_CLASSE    = "SESSAO";

void TUSessao::setUp(){
    sessao = new Sessao();
    estado = SUCESSO;
}

void TUSessao::tearDown(){
    delete sessao;
}

void TUSessao::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setCodigo(CODIGO_VALIDO);
    cout << "Código Válido: " << CODIGO_VALIDO << endl;
    sessao->setCodigoSessao(codigo);
    if (sessao->getCodigoSessao().getCodigo() != CODIGO_VALIDO)
        estado = FALHA;
    
    Data data;
    data.setData(DATA_VALIDA);
    cout << "Data Válida: " << DATA_VALIDA << endl;
    sessao->setDataSessao(data);
    if (sessao->getDataSessao().getData() != DATA_VALIDA)
        estado = FALHA;
    
    Horario horario;
    horario.setHorario(HORARIO_VALIDO);
    cout << "Horário Válido: " << HORARIO_VALIDO << endl;
    sessao->setHorarioSessao(horario);
    if (sessao->getHorarioSessao().getHorario() != HORARIO_VALIDO)
        estado = FALHA;
    
    Idioma idioma;
    idioma.setIdioma(IDIOMA_VALIDO);
    cout << "Idioma Válido: " << IDIOMA_VALIDO << endl;
    sessao->setIdiomaSessao(idioma);
    if (sessao->getIdiomaSessao().getIdioma() != IDIOMA_VALIDO)
        estado = FALHA;
}

int TUSessao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

///----------------------------------------------
/// Implementação da classe TUAvalaicao
///----------------------------------------------

const string TUAvaliacao::CODIGO_VALIDO    = "8542851";
const string TUAvaliacao::DESCRICAO_VALIDA = "Passeio super divertido";
const int TUAvaliacao::NOTA_VALIDA         = 5;
const string TUAvaliacao::NOME_CLASSE      = "AVALIACAO";
 
void TUAvaliacao::setUp(){
    avaliacao = new Avaliacao();
    estado = SUCESSO;
}

void TUAvaliacao::tearDown(){
    delete avaliacao;
}

void TUAvaliacao::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setCodigo(CODIGO_VALIDO);
    cout << "Código Válido: " << CODIGO_VALIDO << endl;
    avaliacao->setCodigoAvaliacao(codigo);
    if (avaliacao->getCodigoAvaliacao().getCodigo() != CODIGO_VALIDO)
        estado = FALHA;
    
    Nota nota;
    nota.setNota(NOTA_VALIDA);
    cout << "Nota Válida: " << NOTA_VALIDA << endl;
    avaliacao->setNotaAvaliacao(nota);
    if (avaliacao->getNotaAvaliacao().getNota() != NOTA_VALIDA)
        estado = FALHA;
    
    Descricao descricao;
    descricao.setDescricao(DESCRICAO_VALIDA);
    cout << "Descrição Válida: " << DESCRICAO_VALIDA << endl;
    avaliacao->setDescricaoAvaliacao(descricao);
    if (avaliacao->getDescricaoAvaliacao().getDescricao() != DESCRICAO_VALIDA)
        estado = FALHA;
}

int TUAvaliacao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
