//
//  testes.cpp
//  Trabalho 1
//
//  Created by Johann Homonnai on 27/02/22.
//

#include "testes_dominios.hpp"
#include "auxiliar.hpp"

///----------------------------------------------
/// Cidade
///----------------------------------------------

const string TUCidade::VALOR_VALIDO   = "Nova Iorque";
const string TUCidade::VALOR_INVALIDO = "Berlim";
const string TUCidade::NOME_CLASSE    = "CIDADE";

void TUCidade::setUp(){
    cidade = new Cidade();
    estado = SUCESSO;
}

void TUCidade::tearDown(){
    delete cidade;
}

void TUCidade::testarCenarioSucesso(){
    try{
        cidade->setCidade(VALOR_VALIDO);
        if (cidade->getCidade() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Cidade': " << err.what() << endl;
    }
}

void TUCidade::testarCenarioFalha(){
    try{
        cidade->setCidade(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (cidade->getCidade() == VALOR_INVALIDO)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Cidade': " << err.what() << endl;
    }
}

int TUCidade::run(){
    setUp();
    cout << "Cidade Válida: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Cidade Inválida: " << VALOR_INVALIDO << endl;
    testarCenarioFalha();
    tearDown();
    return estado;
}


///----------------------------------------------
/// Codigo
///----------------------------------------------

const string TUCodigo::VALOR_VALIDO    = "1234567";
const string TUCodigo::VALOR_INVALIDO1 = "0000000";
const string TUCodigo::VALOR_INVALIDO2 =   "12415";
const string TUCodigo::VALOR_INVALIDO3 = "abcdefg";
const string TUCodigo::NOME_CLASSE     = "CODIGO";

void TUCodigo::setUp(){
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown(){
    delete codigo;
}

void TUCodigo::testarCenarioSucesso(){
    try{
        codigo->setCodigo(VALOR_VALIDO);
        if (codigo->getCodigo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Codigo': " << err.what() << endl;
    }
}

void TUCodigo::testarCenarioFalha(string valor_invalido){
    try{
        codigo->setCodigo(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (codigo->getCodigo() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Codigo': " << err.what() << endl;
    }
}

int TUCodigo::run(){
    setUp();
    cout << "Código Válido: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Código Inválido: " << VALOR_INVALIDO1 << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "Código Inválido: " << VALOR_INVALIDO2 << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "Código Inválido: " << VALOR_INVALIDO3 << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    tearDown();
    return estado;
}

///----------------------------------------------
/// Data
///----------------------------------------------

const string TUData::VALOR_VALIDO    = "05/Jun/2022";
const string TUData::VALOR_INVALIDO1 = "02/Mai/1997";  // Ano conta a partir de 2000
const string TUData::VALOR_INVALIDO2 = "02/Onz/2001";  // Mês em formato inválido
const string TUData::VALOR_INVALIDO3 = "29/Fev/2015";  // 2015 não foi ano bissexto
const string TUData::VALOR_INVALIDO4 = "30/Fev/2015";  // Fevereiro teve 28 dias
const string TUData::VALOR_INVALIDO5 = "30/Fev/2016";  // Fevereiro teve 29 dias
const string TUData::VALOR_INVALIDO6 = "32/Jul/2016";  // Não existe mês com 32 dias
const string TUData::VALOR_INVALIDO7 = "31/07/2016";   // Data em formato inválido
const string TUData::NOME_CLASSE     = "DATA";

void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown(){
    delete data;
}

void TUData::testarCenarioSucesso(){
    try{
        data->setData(VALOR_VALIDO);
        if (data->getData() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Data': " << err.what() << endl;
    }
}

void TUData::testarCenarioFalha(string valor_invalido){
    try{
        data->setData(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (data->getData() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Data': " << err.what() << endl;
    }
}

int TUData::run(){
    setUp();
    cout << "Data Válida: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Data Inválida: " << VALOR_INVALIDO1 << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "Data Inválida: " << VALOR_INVALIDO2 << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "Data Inválida: " << VALOR_INVALIDO3 << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    cout << "Data Inválida: " << VALOR_INVALIDO4 << endl;
    testarCenarioFalha(VALOR_INVALIDO4);
    cout << "Data Inválida: " << VALOR_INVALIDO5 << endl;
    testarCenarioFalha(VALOR_INVALIDO5);
    cout << "Data Inválida: " << VALOR_INVALIDO6 << endl;
    testarCenarioFalha(VALOR_INVALIDO6);
    cout << "Data Inválida: " << VALOR_INVALIDO7 << endl;
    testarCenarioFalha(VALOR_INVALIDO7);
    tearDown();
    return estado;
}

///----------------------------------------------
/// Descricao
///----------------------------------------------

const string TUDescricao::VALOR_VALIDO    = "Passeio no parque.";
const string TUDescricao::VALOR_INVALIDO1 = "Passeio pelas maravilhas do parque.";  // Acima de 30 caracteres
const string TUDescricao::VALOR_INVALIDO2 = "Passeio  no parque.";                  // Espaços em sequência
const string TUDescricao::VALOR_INVALIDO3 = "Descubra...";                          // Pontos em sequência
const string TUDescricao::NOME_CLASSE     = "DESCRICAO";

void TUDescricao::setUp(){
    descricao = new Descricao();
    estado = SUCESSO;
}

void TUDescricao::tearDown(){
    delete descricao;
}

void TUDescricao::testarCenarioSucesso(){
    try{
        descricao->setDescricao(VALOR_VALIDO);
        if (descricao->getDescricao() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Descricao': " << err.what() << endl;
    }
}

void TUDescricao::testarCenarioFalha(string valor_invalido){
    try{
        descricao->setDescricao(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (descricao->getDescricao() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Descricao': " << err.what() << endl;
    }
}

int TUDescricao::run(){
    setUp();
    cout << "Descrição Válida: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Descrição Inválida: " << VALOR_INVALIDO1 << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "Descrição Inválida: " << VALOR_INVALIDO2 << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "Descrição Inválida: " << VALOR_INVALIDO3 << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    tearDown();
    return estado;
}

///----------------------------------------------
/// Duracao
///----------------------------------------------

const int TUDuracao::VALOR_VALIDO   = 90;
const int TUDuracao::VALOR_INVALIDO = 100;  // Duração deve ser uma entre {30, 60, 90, 120, 180}
const string TUDuracao::NOME_CLASSE = "DURACAO";

void TUDuracao::setUp(){
    duracao = new Duracao();
    estado = SUCESSO;
}

void TUDuracao::tearDown(){
    delete duracao;
}

void TUDuracao::testarCenarioSucesso(){
    try{
        duracao->setDuracao(VALOR_VALIDO);
        if (duracao->getDuracao() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Duracao': " << err.what() << endl;
    }
}

void TUDuracao::testarCenarioFalha(){
    try{
        duracao->setDuracao(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (duracao->getDuracao() == VALOR_INVALIDO)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Duracao': " << err.what() << endl;
    }
}

int TUDuracao::run(){
    setUp();
    cout << "Duração Válida: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Duração Inválida: " << VALOR_INVALIDO << endl;
    testarCenarioFalha();
    tearDown();
    return estado;
}

///----------------------------------------------
/// Email
///----------------------------------------------

const string TUEmail::VALOR_VALIDO     = "johann@gmail.com";
const string TUEmail::VALOR_INVALIDO1  = "johann@gmail@com";  // 2 '@'s
const string TUEmail::VALOR_INVALIDO2  = "johann12345678910111213141516171819202122232425262728293031323334@gmail.com";  // Parte local com 65 caracteres (deve ter até 64)
const string TUEmail::VALOR_INVALIDO3  = ".johann@gmail.com"; // Parte local começando com ponto
const string TUEmail::VALOR_INVALIDO4  = "johann.@gmail.com"; // Parte local terminando com ponto
const string TUEmail::VALOR_INVALIDO5  = "johann..homonnai@gmail.com";  // Parte local com pontos em sequência
const string TUEmail::VALOR_INVALIDO6  = "johann,@gmail.com";  // Caractere especial proibido em parte local
const string TUEmail::VALOR_INVALIDO7  = "johann@gmail12948108108294819084902859012890249025092u159129051902u5i2h5i2i5hi2h5ih12i5hi12jgmail12948108108294819084902859012890249025092u159129051902u5i2h5i2i5hi2h5ih12i5hi12jgmail12948108108294819084902859012890249025092u159129051902u5i2h5i2i5hi2h5ih12i5hi12j.com";  // Domínio com mais de 253 caracteres (259)
const string TUEmail::VALOR_INVALIDO8  = "johann@gmail..com";  // Domínio com pontos em sequência
const string TUEmail::VALOR_INVALIDO9  = "johann@gmail_com";  // Domínio com caractere especial proibido
const string TUEmail::VALOR_INVALIDO10 = "johann@.gmail.com";  // Domínio começando com pontos em sequência
const string TUEmail::NOME_CLASSE      = "EMAIL";

void TUEmail::setUp(){
    email = new Email();
    estado = SUCESSO;
}

void TUEmail::tearDown(){
    delete email;
}

void TUEmail::testarCenarioSucesso(){
    try{
        email->setEmail(VALOR_VALIDO);
        if (email->getEmail() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Email': " << err.what() << endl;
    }
}

void TUEmail::testarCenarioFalha(string valor_invalido){
    try{
        email->setEmail(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (email->getEmail() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Email': " << err.what() << endl;
    }
}

int TUEmail::run(){
    setUp();
    cout << "E-mail Válido: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "E-mail Inválido: " << VALOR_INVALIDO1  << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "E-mail Inválido: " << VALOR_INVALIDO2  << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "E-mail Inválido: " << VALOR_INVALIDO3  << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    cout << "E-mail Inválido: " << VALOR_INVALIDO4  << endl;
    testarCenarioFalha(VALOR_INVALIDO4);
    cout << "E-mail Inválido: " << VALOR_INVALIDO5  << endl;
    testarCenarioFalha(VALOR_INVALIDO5);
    cout << "E-mail Inválido: " << VALOR_INVALIDO6  << endl;
    testarCenarioFalha(VALOR_INVALIDO6);
    cout << "E-mail Inválido: " << VALOR_INVALIDO7  << endl;
    testarCenarioFalha(VALOR_INVALIDO7);
    cout << "E-mail Inválido: " << VALOR_INVALIDO8  << endl;
    testarCenarioFalha(VALOR_INVALIDO8);
    cout << "E-mail Inválido: " << VALOR_INVALIDO9  << endl;
    testarCenarioFalha(VALOR_INVALIDO9);
    cout << "E-mail Inválido: " << VALOR_INVALIDO10 << endl;
    testarCenarioFalha(VALOR_INVALIDO10);
    tearDown();
    return estado;
}

///----------------------------------------------
/// Endereco
///----------------------------------------------

const string TUEndereco::VALOR_VALIDO    = "Arco do Triunfo.";
const string TUEndereco::VALOR_INVALIDO1 = "Catedral de Notre-Dame.";  // Endereço com mais de 20 caracteres (23)
const string TUEndereco::VALOR_INVALIDO2 = "Arco do Triunfo..";  // Pontos em sequência
const string TUEndereco::VALOR_INVALIDO3 = "Arco  do Triunfo.";  // Espaços em sequência
const string TUEndereco::NOME_CLASSE     = "ENDERECO";

void TUEndereco::setUp(){
    endereco = new Endereco();
    estado = SUCESSO;
}

void TUEndereco::tearDown(){
    delete endereco;
}

void TUEndereco::testarCenarioSucesso(){
    try{
        endereco->setEndereco(VALOR_VALIDO);
        if (endereco->getEndereco() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Endereco': " << err.what() << endl;
    }
}

void TUEndereco::testarCenarioFalha(string valor_invalido){
    try{
        endereco->setEndereco(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (endereco->getEndereco() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Endereco': " << err.what() << endl;
    }
}

int TUEndereco::run(){
    setUp();
    cout << "Endereço Válido: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Endereço Inválido: " << VALOR_INVALIDO1 << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "Endereço Inválido: " << VALOR_INVALIDO2 << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "Endereço Inválido: " << VALOR_INVALIDO3 << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    tearDown();
    return estado;
}


///----------------------------------------------
/// Horario
///----------------------------------------------

const string TUHorario::VALOR_VALIDO    = "14:00";
const string TUHorario::VALOR_INVALIDO1 = "9:30";   // Horário com 4 caracteres, formato H:MM
const string TUHorario::VALOR_INVALIDO2 = "14h00";  // Formato "HHhMM"
const string TUHorario::VALOR_INVALIDO3 = "24:00";  // Horário acima de 23 horas
const string TUHorario::VALOR_INVALIDO4 = "14:60";  // Minutos acima de 59;
const string TUHorario::NOME_CLASSE     = "HORARIO";

void TUHorario::setUp(){
    horario = new Horario();
    estado = SUCESSO;
}

void TUHorario::tearDown(){
    delete horario;
}

void TUHorario::testarCenarioSucesso(){
    try{
        horario->setHorario(VALOR_VALIDO);
        if (horario->getHorario() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Horario': " << err.what() << endl;
    }
}

void TUHorario::testarCenarioFalha(string valor_invalido){
    try{
        horario->setHorario(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (horario->getHorario() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Horario': " << err.what() << endl;
    }
}

int TUHorario::run(){
    setUp();
    cout << "Horário Inválido: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Horário Inválido: " << VALOR_INVALIDO1 << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "Horário Inválido: " << VALOR_INVALIDO2 << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "Horário Inválido: " << VALOR_INVALIDO3 << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    cout << "Horário Inválido: " << VALOR_INVALIDO4 << endl;
    testarCenarioFalha(VALOR_INVALIDO4);
    tearDown();
    return estado;
}


///----------------------------------------------
/// Idioma
///----------------------------------------------

const string TUIdioma::VALOR_VALIDO   = "Portugues";
const string TUIdioma::VALOR_INVALIDO = "Alemao";
const string TUIdioma::NOME_CLASSE    = "IDIOMA";

void TUIdioma::setUp(){
    idioma = new Idioma();
    estado = SUCESSO;
}

void TUIdioma::tearDown(){
    delete idioma;
}

void TUIdioma::testarCenarioSucesso(){
    try{
        idioma->setIdioma(VALOR_VALIDO);
        if (idioma->getIdioma() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Idioma': " << err.what() << endl;
    }
}

void TUIdioma::testarCenarioFalha(){
    try{
        idioma->setIdioma(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (idioma->getIdioma() == VALOR_INVALIDO)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Idioma': " << err.what() << endl;
    }
}

int TUIdioma::run(){
    setUp();
    cout << "Idioma Válido: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Idioma Inválido: " << VALOR_INVALIDO << endl;
    testarCenarioFalha();
    tearDown();
    return estado;
}

///----------------------------------------------
/// Nome
///----------------------------------------------

const string TUNome::VALOR_VALIDO    = "Izuku Midoriya";
const string TUNome::VALOR_INVALIDO1 = "Pedro de Alcântara João Carlos Leopoldo Salvador Bibiano Francisco Xavier de Paula Leocádio Miguel Gabriel Rafael Gonzaga de Bragança e Bourbon";  // Nome com mais de 20 caracteres (143)
const string TUNome::VALOR_INVALIDO2 = ".Izuku Midoriya";  // Nome não pode começar com ponto
const string TUNome::VALOR_INVALIDO3 = "Izuku Midoriya.."; // Pontos em sequência
const string TUNome::VALOR_INVALIDO4 = "Izuku  Midoriya";  // Espaços em sequência
const string TUNome::VALOR_INVALIDO5 = "1 2 3 de Oliveira 4";  // Nome com dígitos
const string TUNome::VALOR_INVALIDO6 = "Izuku Midoriya .";  // Ponto precedido por espaço
const string TUNome::VALOR_INVALIDO7 = "Izuku.Midoriya";  // Ponto sucedido por letra
const string TUNome::VALOR_INVALIDO8 = "Izuku midoria";  // Termo iniciando com letra minúscula
const string TUNome::VALOR_INVALIDO9 = "izuku Midoriya";  // Nome começando com letra minúscula
const string TUNome::NOME_CLASSE     = "NOME";

void TUNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioSucesso(){
    try{
        nome->setNome(VALOR_VALIDO);
        if (nome->getNome() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Nome': " << err.what() << endl;
    }
}

void TUNome::testarCenarioFalha(string valor_invalido){
    try{
        nome->setNome(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (nome->getNome() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Nome': " << err.what() << endl;
    }
}

int TUNome::run(){
    setUp();
    cout << "Nome Válido: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Nome Inválido: " << VALOR_INVALIDO1 << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "Nome Inválido: " << VALOR_INVALIDO2 << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "Nome Inválido: " << VALOR_INVALIDO3 << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    cout << "Nome Inválido: " << VALOR_INVALIDO4 << endl;
    testarCenarioFalha(VALOR_INVALIDO4);
    cout << "Nome Inválido: " << VALOR_INVALIDO5 << endl;
    testarCenarioFalha(VALOR_INVALIDO5);
    cout << "Nome Inválido: " << VALOR_INVALIDO6 << endl;
    testarCenarioFalha(VALOR_INVALIDO6);
    cout << "Nome Inválido: " << VALOR_INVALIDO7 << endl;
    testarCenarioFalha(VALOR_INVALIDO7);
    cout << "Nome Inválido: " << VALOR_INVALIDO8 << endl;
    testarCenarioFalha(VALOR_INVALIDO8);
    cout << "Nome Inválido: " << VALOR_INVALIDO9 << endl;
    testarCenarioFalha(VALOR_INVALIDO9);
    tearDown();
    return estado;
}


///----------------------------------------------
/// Nota
///----------------------------------------------

const int TUNota::VALOR_VALIDO   = 5;
const int TUNota::VALOR_INVALIDO = 10;  // Nota fora do intervalo de 0 a 5
const string TUNota::NOME_CLASSE = "NOTA";

void TUNota::setUp(){
    nota = new Nota();
    estado = SUCESSO;
}

void TUNota::tearDown(){
    delete nota;
}

void TUNota::testarCenarioSucesso(){
    try{
        nota->setNota(VALOR_VALIDO);
        if (nota->getNota() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Nota': " << err.what() << endl;
    }
}

void TUNota::testarCenarioFalha(){
    try{
        nota->setNota(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (nota->getNota() == VALOR_INVALIDO)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Nota': " << err.what() << endl;
    }
}

int TUNota::run(){
    setUp();
    cout << "Nota Válida: " << VALOR_INVALIDO << endl;
    testarCenarioSucesso();
    cout << "Nota Inválida: " << VALOR_INVALIDO << endl;
    testarCenarioFalha();
    tearDown();
    return estado;
}


///----------------------------------------------
/// Senha
///----------------------------------------------

const string TUSenha::VALOR_VALIDO    = "SenLa0";
const string TUSenha::VALOR_INVALIDO1 = "SenhaLegal12";  // Senha com mais de 6 caracteres (12)
const string TUSenha::VALOR_INVALIDO2 = "Sene12";  // Senha com caracteres duplicados
const string TUSenha::VALOR_INVALIDO3 = "senha4";  // Senha sem letra maiúscula
const string TUSenha::VALOR_INVALIDO4 = "SENHA4";  // Senha sem letra minúscula
const string TUSenha::VALOR_INVALIDO5 = "123456";  // Senha sem letras
const string TUSenha::NOME_CLASSE     = "SENHA";

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSucesso(){
    try{
        senha->setSenha(VALOR_VALIDO);
        if (senha->getSenha() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Senha': " << err.what() << endl;
    }
}

void TUSenha::testarCenarioFalha(string valor_invalido){
    try{
        senha->setSenha(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (senha->getSenha() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Senha': " << err.what() << endl;
    }
}

int TUSenha::run(){
    setUp();
    cout << "Senha Válida: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Senha Inválida: " << VALOR_INVALIDO1 << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "Senha Inválida: " << VALOR_INVALIDO2 << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "Senha Inválida: " << VALOR_INVALIDO3 << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    cout << "Senha Inválida: " << VALOR_INVALIDO4 << endl;
    testarCenarioFalha(VALOR_INVALIDO4);
    cout << "Senha Inválida: " << VALOR_INVALIDO5 << endl;
    testarCenarioFalha(VALOR_INVALIDO5);
    tearDown();
    return estado;
}


///----------------------------------------------
/// Titulo
///----------------------------------------------

const string TUTitulo::VALOR_VALIDO    = "Visita ao Louvre";
const string TUTitulo::VALOR_INVALIDO1 = "Visita ao Museu do Louvre";  // Título com mais de 20 caracteres (25)
const string TUTitulo::VALOR_INVALIDO2 = "Visita ao Louvre..";  // Pontos em sequência
const string TUTitulo::VALOR_INVALIDO3 = "Visita ao  Louvre";   // Espaços em sequência
const string TUTitulo::VALOR_INVALIDO4 = "2 Visitas ao Louvre";
const string TUTitulo::NOME_CLASSE     = "TITULO";

void TUTitulo::setUp(){
    titulo = new Titulo();
    estado = SUCESSO;
}

void TUTitulo::tearDown(){
    delete titulo;
}

void TUTitulo::testarCenarioSucesso(){
    try{
        titulo->setTitulo(VALOR_VALIDO);
        if (titulo->getTitulo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &err){
        estado = FALHA;
        cout << "ERRO NO TESTE DE 'Titulo': " << err.what() << endl;
    }
}

void TUTitulo::testarCenarioFalha(string valor_invalido){
    try{
        titulo->setTitulo(valor_invalido);
        estado = FALHA;
    }
    catch(invalid_argument &err){
        if (titulo->getTitulo() == valor_invalido)
            estado = FALHA;
        cout << "ERRO NO TESTE DE 'Titulo': " << err.what() << endl;
    }
}

int TUTitulo::run(){
    setUp();
    cout << "Título válido: " << VALOR_VALIDO << endl;
    testarCenarioSucesso();
    cout << "Título inválido: " << VALOR_INVALIDO1 << endl;
    testarCenarioFalha(VALOR_INVALIDO1);
    cout << "Título inválido: " << VALOR_INVALIDO2 << endl;
    testarCenarioFalha(VALOR_INVALIDO2);
    cout << "Título inválido: " << VALOR_INVALIDO3 << endl;
    testarCenarioFalha(VALOR_INVALIDO3);
    cout << "Título inválido: " << VALOR_INVALIDO4 << endl;
    testarCenarioFalha(VALOR_INVALIDO4);
    tearDown();
    return estado;
}
