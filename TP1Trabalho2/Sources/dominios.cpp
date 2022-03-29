///
///  Implementação de classes dominios.cpp
///  Trabalho 1 - Técnicas de Programação 1, turma C
///  Trabalho feito por Johann Homonnai, matrícula 17/0014151
///

#include "Dominios.hpp"
#include "auxiliar.hpp"

using namespace std;

///----------------------------------------------
/// Implementação da classe Cidade
///----------------------------------------------

vector<string> Cidade::CIDADES = {"Hong Kong", "Bangkok", "Macau", "Singapura", "Londres", "Paris",
                             "Dubai", "Delhi", "Istambul", "Kuala Lumpur", "Nova Iorque",
                             "Antalya", "Mumbai", "Shenzhen", "Phuket"};
string Cidade::PADRAO          = "CIDADE";

void Cidade::validar(string cidadeTeste)
{
    for (auto &city: CIDADES)
    {
        if (cidadeTeste.compare(city) == 0)
            return;
    }
    
    throw invalid_argument("Cidade deve estar na lista fornecida:\n Hong Kong, Bangkok, Macau, Singapura, Londres, Paris, Dubai, Delhi, Istambul, Kuala Lumpur, Nova Iorque, Antalya, Mumbai, Shenzhen, Phuket.");
}

/// @brief Construtor padr&atilde;o para a classe Cidade
/// @details N&atilde;o recebe nenhum par&acirc;metro e atribui o valor padr&atilde;o ao membro cidade.

Cidade::Cidade() : cidade{this->PADRAO} {}

/// @brief Construtor n&atilde;o-padr&atilde;o para a classe Cidade
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param cidadeExcursao Nome da cidade da excurs&atilde;o.

Cidade::Cidade(string cidadeExcursao)
{
    this->setCidade(cidadeExcursao);
}

/// @brief Fun&ccedil;&atilde;o para designar nome da cidade
/// @details &Eacute; em ess&ecirc;ncia igual ao construtor n&atilde;o padr&atilde;o.
/// @param cidadeExcursao Nome da cidade da excurs&atilde;o.

inline void Cidade::setCidade(string cidadeExcursao)
{
        this->validar(cidadeExcursao);
        this->cidade = cidadeExcursao;
}

///----------------------------------------------
/// Implementação da classe Codigo
///----------------------------------------------

string Codigo::ERRADO = "0000000";
string Codigo::PADRAO = "DDDDDDX";

/// @brief Fun&ccedil;&atilde;o de valida&ccedil;&atilde;o de um C&oacute;digo.
/// @details A fun&ccedil;&atilde;o testa tr&ecirc;s cen&aacute;rios e lan&ccedil;a excec&ccedil;&otilde;es de acordo: se o c&oacute;digo &eacute; composto por zeros; se o c&oacute;digo tem tamanho 7; ou se o c&oacute;digo &eacute; composto somente por d&iacute;gitos.
/// @param codigoTeste C&oacute;digo a ser validado

void Codigo::validar(string codigoTeste)
{
    if (codigoTeste == this->ERRADO)
    {
        throw invalid_argument("Código não pode ser composto somente por 0s.");
    }
    else if (codigoTeste.length() != 7)
    {
        throw invalid_argument("Código deve ser composto por 7 dígitos.");
    }
    else
    {
        for (auto &digito: codigoTeste)
        {
            if (!isdigit(digito))
                throw invalid_argument("Código deve ser composto somente por dígitos decimais.");
        }
    }
}

/// @brief Construtor padr&atilde;o da classe Codigo.
/// @details Simplesmente atribui o valor padr&atilde;o ao membro codigo. N&atilde;o recebe par&acirc;metros.

Codigo::Codigo() : codigo{this->PADRAO} {}

/// @brief Construtor parametrizado da classe Codigo.
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param codigoExcursao C&oacute;digo da excurs&atilde;o.

Codigo::Codigo(string codigoExcursao)
{
    this->setCodigo(codigoExcursao);
}

/// @brief Fun&ccedil;&atilde;o para designar c&oacute;digo da excurs&atilde;o.
/// @details Recebe um c&oacute;digo, valida e, caso n&atilde;o ocorra exce&ccedil;&atilde;o, atribui o valor ao membro.
/// @param codigoExcursao C&oacute;digo da excurs&atilde;o.

void Codigo::setCodigo(string codigoExcursao)
{
    this->validar(codigoExcursao);
    this->codigo = codigoExcursao;
}

///----------------------------------------------
/// Implementação da classe Data
///----------------------------------------------

vector<string> Data::MESES = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun",
                        "Jul", "Ago", "Set", "Out", "Nov", "Dez"};
string Data::PADRAO        = "DD/MMM/YYYY";
vector<string> vetor30     = {"Abr", "Jun", "Set", "Nov"};
vector<string> vetor31     = {"Mar", "Mai", "Jul", "Ago", "Out", "Dez"};

/// @brief Fun&ccedil;&atilde;o auxiliar para transformar a string data.
/// @details Esta fun&ccedil;&atilde;o recebe e separa cada parte da data em dia, m&ecirc;s e ano. Retorna em formato de tupla tr&ecirc;s valores, um para cada peda&ccedil;o da data.
/// @param data Data completa, em formato "DD/MMM/YYYY".
/// @return Uma tupla com o dia, o m&ecirc;s e o ano da data.

tuple<string, string, string> Data::separaData(string data)
{
    int i = 0, contBarra = 0;
    string dia, mes, ano;
    
    while (data[i] != '\0'){
        if (contBarra == 0){ //Iterando por dia
            if (data[i] != '/')
                dia += data[i];
            else
                contBarra++;
        }
        else if (contBarra == 1) {
            if (data[i] != '/')
                mes += data[i];
            else
                contBarra++;
        }
        else {
            ano += data[i];
        }
        i++;
    }
    
    return {dia, mes, ano};
}

/// @brief Fun&ccedil;&atilde;o que valida uma data.
/// @details Recebe a data e faz os testes para verificar se &eacute; v&aacute;lida de acordo com as regras: o m&ecirc;s tem de estar no formado especificado, fevereiro acomoda 29 dias se o ano for bissexto (ano este que deve estar entre 2000 e 9999) e tem de ser levado em conta se o m&ecirc;s tem 30 ou 31 dias.

void Data::validar(string dataTeste)
{
    /// Por padr&atilde;o, a data deve ter 11 caracteres
    if (dataTeste.length() != 11)
        throw invalid_argument("Formato inválido, data deve ter 11 caracteres.");
    /// Declara&ccedil;&otilde;es
    auto [dia, mes, ano] = this->separaData(dataTeste);
    int anoNum = stoi(ano);
    auto testeMes = find(this->MESES.begin(), this->MESES.end(), mes);
    auto mes30 = find(vetor30.begin(), vetor30.end(), mes);
    int diaNum = stoi(dia);
    auto ehBissexto = [](int a) {
        if (a % 4 == 0) {
            if (a % 100 != 0 || a % 400 == 0)
                return true;
        }
        return false;
    };
    auto testeBissexto = ehBissexto(anoNum);
    
    /// Validar ano
    if (anoNum < this->MIN_ANO || anoNum > this->MAX_ANO)
        throw invalid_argument("Ano deve ser entre 2000 e 9999.");
    
    /// Validar m&ecirc;s
    if (testeMes == end(this->MESES))
        throw invalid_argument("Mês está em formato inválido. Lembre-se que deve estar contido em:\n{ Jan, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez }.");
    if (diaNum < this->MIN_DIA || diaNum > this->MAX_DIA)
        throw invalid_argument("O dia deve estar entre 1 e 31");
    
    /// Validar dia
    if (mes == "Fev"){
        if (diaNum == 29 && !testeBissexto){
            throw invalid_argument(ano + " não é um ano bissexto, logo 29/02 não é uma data válida");
        }
        else if (diaNum == 30 || diaNum == 31){
            if (testeBissexto)
                throw invalid_argument("Fevereiro tem somente 29 dias.");
            else
                throw invalid_argument("Fevereiro tem somente 28 dias.");
        }
    }
    else if (mes30 == end(vetor30) && diaNum == 31){
        throw invalid_argument(mes + " possui 30 dias, não 31.");
    }
}

/// @brief Construtor padr&atilde;o para Data
/// @details Simplesmente atribui o valor padr&atilde;o para a data.

Data::Data() : data{this->PADRAO} {}

/// @brief Construtor parametrizado para Data
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param dataSessao data da sess&atilde;o.

Data::Data(string dataSessao)
{
    this->setData(dataSessao);
}

/// @brief Fun&ccedil;&atilde;o para mudar a data.
/// @details Recebe uma data, valida-a e atribui o valor (caso exce&ccedil;&atilde;o n&atilde;o seja lan&ccedil;ada.
/// @param dataSessao data da sess&atilde;o.

void Data::setData(string dataSessao)
{
    this->validar(dataSessao);
    this->data = dataSessao;
}

///----------------------------------------------
/// Implementação da classe Descricao
///----------------------------------------------

string Descricao::PADRAO = "DESCRIÇÃO";

///@brief Fun&ccedil;&atilde;o que valida o valor de uma descri&ccedil;&atilde;o teste.
///@details A fun&ccedil;&atilde;o verifica se o texto con&eacute;m de 0 a 30 caracteres, se h&aacute; espa&ccedil;os em branco em sequ&ecirc;ncia e, finalmente, se h&aacute; pontos (.) em sequ&ecirc;ncia.

void Descricao::validar(string testeDescricao)
{
    if (testeDescricao.length() < 0 || testeDescricao.length() > 30)
        throw invalid_argument("Descrição deve conter entre 0 e 30 caracteres.");
    else {
        if (pontoEmSequencia(testeDescricao))
            throw invalid_argument("Descrição não pode conter pontos em sequência.");
        if (espacoEmSequencia(testeDescricao))
            throw invalid_argument("Descrição não pode conter espaços em sequência.");
    }
}

/// @brief Construtor padr&atilde;o da classe Descricao
/// @details Simplesmente atribui ao valor descricao o valor padr&atilde;o DESCRI&Ccedil;&Atilde;O.

Descricao::Descricao() : descricao{this->PADRAO} {}

/// @brief Construtor parametrizado da classe Descricao
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param descricaoExcursao Descri&ccedil;&atilde;o da excurs&atilde;o.

Descricao::Descricao(string descricaoExcursao)
{
    this->setDescricao(descricaoExcursao);
}

/// @brief Fun&ccedil;&atilde;o para mudar a descri&ccedil;&atilde;o da excurs&atilde;o.
/// @details Recebe o par&acirc;metro e o valida com base na fun&ccedil;&atilde;o validar. Captura poss&iacute;vel exce&ccedil;&atilde;o lan&ccedil;ada. Caso n&atilde;o haja exce&ccedil;&atilde;o, simplesmente atribui o valor ao atributo descricao.
/// @param descricaoExcursao Descri&ccedil;atilde; da excurs&atilde;o.

void Descricao::setDescricao(string descricaoExcursao)
{
    this->validar(descricaoExcursao);
    this->descricao = descricaoExcursao;
}

///----------------------------------------------
/// Implementação da classe Duracao
///----------------------------------------------

vector<int> Duracao::DURACOES = {30, 60, 90, 120, 180};
int Duracao::PADRAO           = 90;

/// @brief Fun&ccedil;&atilde;o que valida uma dura&ccedil;&atilde;o.
/// @details Ela precisa verificar se a dura&ccedil;&atilde;o fornecida est&aacute; entre as poss&iacute;veis.

void Duracao::validar(int duracaoTeste)
{
    auto testeDuracao = find(Duracao::DURACOES.begin(), Duracao::DURACOES.end(), duracaoTeste);
    
    if (testeDuracao == end(Duracao::DURACOES))
        throw invalid_argument("A duração deve ser uma dentre as seguintes:\n {30, 60, 90, 120, 180}");
}

/// @brief Construtor padr&atilde;o da classe Duracao
/// @details Simplesmente atribui ao valor duracao o valor padr&atilde;o 90.

Duracao::Duracao() : duracao{this->PADRAO} {}

/// @brief Construtor parametrizado da classe Duracao
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param duracaoExcursao Dura&ccedil;&atilde;o da excurs&atilde;o.

Duracao::Duracao(int duracaoExcursao)
{
    this->setDuracao(duracaoExcursao);
}

/// @brief Fun&ccedil;&atilde;o para mudar a dura&ccedil;&atilde;o da excurs&atilde;o.
/// @details Recebe o par&acirc;metro e o valida com base na fun&ccedil;&atilde;o validar. Captura poss&iacute;vel exce&ccedil;&atilde;o lan&ccedil;ada. Caso n&atilde;o haja exce&ccedil;&atilde;o, simplesmente atribui o valor ao atributo duracao.
/// @param duracaoExcursao Dura&ccedil;atilde; da excurs&atilde;o.

void Duracao::setDuracao(int duracaoExcursao)
{
    this->validar(duracaoExcursao);
    this->duracao = duracaoExcursao;
}

///----------------------------------------------
/// Implementação da classe Email
///----------------------------------------------

string Email::PADRAO          = "parte-local@dominio";
vector<char> Email::ESPECIAIS = {'!', '#', '$', '%', '&', '\'', '*', '+', '-', '/', '=', '?', '^', '_', '`', '{', '|', '}', '~', '.'};

/// @brief Fun&ccedil;&atilde;o para validar um e-mail
/// @details A fun&ccedil;&atilde;o precisa verificar se tem o formato pedido, ou seja, se possui um @ entre duas strings. Ap&oacute;s isso, precisa validar se:
/// 1. parte-local tem at&eacute; 64 caracteres;
/// 2. Primeiro ou &uacute;ltimo caractere de parte-local n&atilde;o &eacute; um ponto;
/// 3. N&atilde;o h&aacute; pontos em sequ&ecirc;ncia;
/// 4. N&atilde;o h&aacute; um caractere especial fora dos especificados;
/// 5. dominio tem at&eacute; 253 caracteres;
/// 6. dominio n&atil;o possui ponto como primeiro caractere ou em sequ&ecirc;ncia.
/// @param emailTeste E-mail a ser validado.

void Email::validar(string emailTeste)
{
    int countArroba = 0; // Validar quantidade de arrobas
    int idxArroba = 0; // Guardar índice do @
    string parteLocal, dominio;
    
    for (int i = 0; i < emailTeste.length(); i++) {
        if (emailTeste[i] == '@') {
            countArroba++;
            if (countArroba > 1)
                throw invalid_argument("E-mail só poder ter um @.");
            idxArroba = i;
        }
    }
    
    parteLocal = emailTeste.substr(0, idxArroba);
    dominio = emailTeste.substr(idxArroba + 1, emailTeste.length() - idxArroba - 1);

    unsigned long tamP = parteLocal.length();
    unsigned long tamD = dominio.length();
    
    // Verificação de parte-local
    if (tamP > 64)
        throw invalid_argument("Parte local deve ter até 64 caracteres.");
    else if (parteLocal[0] == '.' || parteLocal[tamP - 1] == '.')
        throw invalid_argument("Parte local não pode começar nem terminar com ponto.");
    
    // Verificar pontos em sequência e caracteres especiais
    if (pontoEmSequencia(parteLocal))
        throw invalid_argument("Parte local não pode ter pontos em sequência.");
    
    for (int i = 0; i < tamP; i++)
    {
        // Agora posso checar se é algum outro caractere especial
        if (!isalnum(parteLocal[i])){
            if (find(Email::ESPECIAIS.begin(), Email::ESPECIAIS.end(), parteLocal[i]) == end(Email::ESPECIAIS))
                throw invalid_argument("Os caracteres especiais permitidos são:\n {'!', '#', '$', '%', '&', '\'', '*', '+', '-', '/', '=', '?', '^', '_', '`', '{', '|', '}', '~', '.'}");
        }
    }
    
    // Verificar domínio agora
    if (tamD > 253)
        throw invalid_argument("Domínio deve conter até 253 caracteres.");
    else if (dominio[0] == '.')
        throw invalid_argument("Domínio não pode começar com ponto.");
    else if (pontoEmSequencia(dominio))
        throw invalid_argument("Domínio não pode conter pontos em sequência.");
    else {
        for (auto &chr: dominio) {
            if (!isalnum(chr) && chr != '-' && chr != '.')
                throw invalid_argument("Domínio não aceita caracteres especiais fora '-' e '.'");
        }
    }
}

/// @brief Construtor padr&atilde;o de Email
/// @details Simplesmente atribui o valor "parte-local@dominio" ao atributo email.

Email::Email() : email{this->PADRAO} {}

/// @brief Construtor parametrizado da classe Email
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param emailUsuario E-mail do usu&aacute;rio.

Email::Email(string emailUsuario)
{
    this->setEmail(emailUsuario);
}

/// @brief Fun&ccedil;&atilde;o para mudar e-mail do usu&aacute;rio.
/// @details Recebe o par&acirc;metro e o valida com base na fun&ccedil;&atilde;o validar. Captura poss&iacute;vel exce&ccedil;&atilde;o lan&ccedil;ada. Caso n&atilde;o haja exce&ccedil;&atilde;o, simplesmente atribui o valor ao atributo email.
/// @param emailUsuario E-mail do usu&aacute;rio.

void Email::setEmail(string emailUsuario)
{
    this->validar(emailUsuario);
    this->email = emailUsuario;
}

///----------------------------------------------
/// Implementação da classe Endereco
///----------------------------------------------

string Endereco::PADRAO = "ENDEREÇO";

/// @brief Fun&ccedil;&atilde;o que valida um endere&ccedil;o.
/// @details Precisa verificar se:
/// 1. enderecoTeste possui de 0 a 20 caracteres;
/// 2. N&atilde;o h&aacute; espa&ccedil;os em branco em sequ&ecirc;ncia;
/// 3. N&atilde;o h&aacute; pontos (.) em sequ&ecirc;ncia.
/// @param enderecoTeste Endere&ccedil;o a ser testado.

void Endereco::validar(string enderecoTeste)
{
    unsigned long tamEnd = enderecoTeste.length();
    
    if (tamEnd > 20)
        throw invalid_argument("Endereço deve conter até 20 caracteres.");
    else {
        
        if (pontoEmSequencia(enderecoTeste))
            throw invalid_argument("Endereço não pode conter pontos em sequência.");
        if (espacoEmSequencia(enderecoTeste))
            throw invalid_argument("Endereço não pode conter espaços em sequência.");
    }
}

/// @brief Construtor padr&atilde;o de Endereco
/// @details Simplesmente atribui o valor "ENDERE&CCEDIL;O" ao atributo endereco

Endereco::Endereco() : endereco{this->PADRAO} {}

/// @brief Construtor parametrizado de Endereco
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param enderecoExcursao Endere&ccedil;o da excurs&atilde;o.

Endereco::Endereco(string enderecoExcursao)
{
    this->setEndereco(enderecoExcursao);
}

/// @brief Fun&ccedil;&atilde;o que muda o endere&ccedil;o da excurs&atilde;o
/// @details Recebe o valor, valida com a fun&ccedil;&atilde;o validar. Caso lance exce&ccedil;&atilde;o, trata-a.
/// @param enderecoExcursao Endere&ccedil;o da excurs&atilde;o.

void Endereco::setEndereco(string enderecoExcursao)
{
    this->validar(enderecoExcursao);
    this->endereco = enderecoExcursao;
}

///----------------------------------------------
/// Implementação da classe Horario
///----------------------------------------------

string Horario::PADRAO = "HH:MM";

/// @brief Fun&ccedil;&atilde;o que valida o hor&aacute;rio fornecido.
/// @details O hor&aacute;rio deve satisfazer tr&ecirc;s requisitos:
/// 1. Formato HH:MM;
/// 2. HH - 00 a 23;
/// 3. MM - 00 a 59.

void Horario::validar(string horarioTeste)
{
    if (horarioTeste.length() > 5)
        throw invalid_argument("Horário deve ser no formato HH:MM, com 5 caracteres");
    
    vector<char> carHorarios = { horarioTeste[0], horarioTeste[1], horarioTeste[3], horarioTeste[4] };
    
    bool horarioValido = all_of(carHorarios.begin(), carHorarios.end(), [](char c){
        return isdigit(c);
    });
    
    bool formatoValido = horarioValido && horarioTeste[2] == ':';
    
    if (!formatoValido)
        throw invalid_argument("Horário deve ser no formato HH:MM");
    
    // Verificar valores
    int horas = stoi(horarioTeste.substr(0, 2));
    int minutos = stoi(horarioTeste.substr(3, 2));
    
    if (horas < 0 || horas > 23)
        throw invalid_argument("As horas devem estar entre 00 e 23.");
    else if (minutos < 0 || minutos > 59)
        throw invalid_argument("Os minutos devem estar entre 00 e 59.");
}

/// @brief Construtor padr&ati;de;o de Horario
/// @details Simplesmente atribui "HH:MM" ao atributo horario.

Horario::Horario() : horario{this->PADRAO} {}

/// @brief Construtor parametrizado de Horario
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param horarioSessao Hor&aacute;rio da sess&&atilde;o.

Horario::Horario(string horarioSessao)
{
    this->setHorario(horarioSessao);
}

/// @brief Fun&ccedil;&atilde;o que muda o hor&aacute;rio.
/// @details Recebe o valor, valida-o, e trata poss&iacute;vel exce&ccedil;&atilde;o.
/// @param horarioSessao Hor&aacute;rio da sess&&atilde;o.

void Horario::setHorario(string horarioSessao)
{
    this->validar(horarioSessao);
    this->horario = horarioSessao;
}

///----------------------------------------------
/// Implementação da classe Idioma
///----------------------------------------------

vector<string> Idioma::IDIOMAS = {"Ingles", "Chines Mandarim", "Hindi", "Espanhol", "Frances", "Arabe", "Bengali", "Russo", "Portugues", "Indonesio"};
string Idioma::PADRAO          = "Portugues";

/// @brief Fun&ccedil;&atilde;o que valida o idioma
/// @details O idioma deve ser um dentre os presentes em Idioma::IDIOMAS.

void Idioma::validar(string idiomaTeste)
{
    auto idiomaValido = ( find(Idioma::IDIOMAS.begin(), Idioma::IDIOMAS.end(), idiomaTeste)
                         != end(Idioma::IDIOMAS));
    
    if (!idiomaValido)
        throw invalid_argument("O idioma deve ser um dentre:\n {\"Ingles\", \"Chines Mandarim\", \"Hindi\", \"Espanhol\", \"Frances\", \"Arabe\", \"Bengali\", \"Russ\", \"Portugues\", \"Indonesio\"}");
}

/// @brief Construtor padr&ati;de;o de Idioma
/// @details Simplesmente atribui "Portugues" ao atributo idioma.
Idioma::Idioma() : idioma{this->PADRAO} {}

/// @brief Construtor parametrizado de Idioma
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param idiomaSessao Idioma da sess&atilde;o.

Idioma::Idioma(string idiomaSessao)
{
    this->setIdioma(idiomaSessao);
}

/// @brief Fun&ccedil;&atilde;o que muda o idioma da sess&atilde;o.
/// @details Recebe o valor, valida-o, e trata poss&iacute;vel exce&ccedil;&atilde;o.
/// @param idiomaSessao Idioma da sess&atilde;o.

void Idioma::setIdioma(string idiomaSessao)
{
    this->validar(idiomaSessao);
    this->idioma = idiomaSessao;
}

///----------------------------------------------
/// Implementação da classe Nome
///----------------------------------------------

string Nome::PADRAO = "NOME";

/// @brief Fun&ccedil;&atilde;o que valida o nome do usu&aacute;rio
/// @details O nome precisa ser um caractere do alfabeto ou então ponto ou espa&ccedil;o. Deve satisfazer:
/// 1. Ponto &eacute; precedido por letra;
/// 2. Ponto &eacute; &uacute;ltimo caractere ou &eacute; seguido por um espa&ccedil;o em branco;
/// 3. N&atilde;o h&aacute; espa&ccedil;os em branco em sequ&ecirc;ncia;
/// 4. Primeira letra de cada termo &eacute; letra mai&uacute;scula (A-Z).

void Nome::validar(string nomeTeste)
{
    char chr;
    bool ultimoEspaco = false;
    
    if (nomeTeste.length() < 5 || nomeTeste.length() > 20)
        throw invalid_argument("O nome deve conter entre 5 e 20 caracteres.");
    
    if (nomeTeste[0] == '.')
        throw invalid_argument("Nome não pode começar com ponto.");
    
    if (islower(nomeTeste[0]))
        throw invalid_argument("Nome deve ter a primeira letra maiúscula.");
    
    if (pontoEmSequencia(nomeTeste))
        throw invalid_argument("Não pode haver pontos em sequência.");
    if (espacoEmSequencia(nomeTeste))
        throw invalid_argument("Não pode haver espaços em sequência.");
    
    for (int i = 0; i < nomeTeste.length(); i++) {
        chr = nomeTeste[i];
        if (i > 0){
            if (nomeTeste[i-1] == ' ')
                ultimoEspaco = true;
            else
                ultimoEspaco = false;
        }
        
        if (!(isalpha(chr)) && chr != ' ' && chr != '.')
            throw invalid_argument("Nome deve conter somente letra do alfabeto, ponto ou espaço.");
        else if (chr == '.') {
            if (!isalpha(nomeTeste[i-1]))
                throw invalid_argument("Ponto deve ser precedido por letra.");
            else if (i < (nomeTeste.length() - 1) && nomeTeste[i+1] != ' ')
                throw invalid_argument("Ponto deve ser sucedido por espaço em branco.");
        }
        else if (ultimoEspaco && islower(chr))
            throw invalid_argument("A primeira letra de cada termo deve ser maiúscula.");
    }
}

/// @brief Construtor padr&atilde;o da classe Nome
/// @details Simplesmente atribui o valor "NOME" ao atributo nome

Nome::Nome() : nome{this->PADRAO} {}

/// @brief Construtor parametrizado da classe Nome
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param nomeUsuario Nome do usu&aacute;rio.

Nome::Nome(string nomeUsuario)
{
    this->setNome(nomeUsuario);
}

/// @brief Fun&ccedil;&atilde;o que muda o nome do usu&aacute;rio.
/// @details Valida o nome e trata a exce&ccedil;&atilde;o se lan&ccedil;ada.
/// @param nomeUsuario Nome do usu&aacute;rio.

void Nome::setNome(string nomeUsuario)
{
    this->validar(nomeUsuario);
    this->nome = nomeUsuario;
}

///----------------------------------------------
/// Implementação da classe Nota
///----------------------------------------------

int Nota::PADRAO = 3;

/// @brief Fun&ccedil;&atilde;o que valida a nota
/// @details A nota deve ser entre 0 e 5.

void Nota::validar(int notaTeste)
{
    bool notaValida = (notaTeste >= 0 && notaTeste <= 5);
    
    if (!notaValida)
        throw invalid_argument("Nota deve ser entre 0 e 5.");
}

/// @brief Construtor padr&atilde;o da classe Nota
/// @details Simplesmente atribui o valor 3 ao atributo nota.

Nota::Nota() : nota{this->PADRAO} {}

/// @brief Construtor parametrizado da classe Nota
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param notaExcursao Nota dada &agrave; excurs&atilde;o.

Nota::Nota(int notaExcursao)
{
    this->setNota(notaExcursao);
}

/// @brief Fun&ccedil;&atilde;o que muda a nota
/// @details Recebe uma nota, valida e trata exce&ccedil;&atilde;o se lan&ccedil;ada.
/// @param notaExcursao Nota dada &agrave; escurs&atilde;o.

void Nota::setNota(int notaExcursao)
{
    this->validar(notaExcursao);
    this->nota = notaExcursao;
}


///----------------------------------------------
/// Implementação da classe Senha
///----------------------------------------------

string Senha::PADRAO = "XXXXXX";

/// @brief Fun&ccedil;&atilde;o que valida uma senha
/// @details A senha deve obedecer aos seguintes requisitos:
/// 1. Ter somente caracteres alfanum&eacute;ricos (A-Z, a-z e 0-9);
/// 2. N&atilde;o ter caracteres repetidos;
/// 3. Ter pelo menos uma letra mai&uacute;scula, uma letra min&uacute;scula e um d&iacute;gito

void Senha::validar(string senhaTeste)
{
    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temDigito = false;
    vector<char> caracteres = {};
    
    /// Testar tamanho
    if (senhaTeste.length() != 6)
        throw invalid_argument("Senha deve ter 6 caracteres.");
    else {
        for (auto &chr: senhaTeste) {
            if (find(caracteres.begin(), caracteres.end(), chr) != end(caracteres))
                throw invalid_argument("Senha não pode ter caracteres duplicados.");
            else
                caracteres.push_back(chr);
            if (isupper(chr))
                temMaiuscula = true;
            else if (islower(chr))
                temMinuscula = true;
            else if (isdigit(chr))
                temDigito = true;
        }
        if (!(temMaiuscula && temMinuscula && temDigito))
            throw invalid_argument("Senha deve conter pelo menos uma letra maiúscula, uma letra minúscula e um dígito.");
    }
}

/// @brief Construtor padr&atilde;o de Senha
/// @details Simplesmente atribui "XXXXXX" ao atributo senha

Senha::Senha() : senha{this->PADRAO} {}

/// @brief Construtor parametrizado da classe Senha
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param senhaUsuario Senha do usu&aacute;rio.

Senha::Senha(string senhaUsuario)
{
    this->setSenha(senhaUsuario);
}

/// @brief Fun&ccedil;&atilde;o que muda a senha
/// @details Recebe uma senha, valida e trata exce&ccedil;&atilde;o se lan&ccedil;ada.
/// @param senhaUsuario Senha do usu&aacute;rio.

void Senha::setSenha(string senhaUsuario)
{
    this->validar(senhaUsuario);
    this->senha = senhaUsuario;
}


///----------------------------------------------
/// Implementação da classe Titulo
///----------------------------------------------

string Titulo::PADRAO = "TITULO";

/// @brief Fun&ccedil;&atilde;o que valida o t&iacute;tulo de uma excurs&atilde;o.
/// @details O t&iacute;tulo deve obedecer aos seguintes requisitos:
/// 1. 5 a 20 letras (A-Z)(a-z);
/// 2. N&atilde;o h&aacute; espa&ccedil;os em branco em sequ&ecirc;ncia;
/// 3. N&atilde;o h&aacute; pontos (.) em sequ&ecirc;ncia.

void Titulo::validar(string tituloTeste)
{
    vector<char> caracteres = {};
    for (auto &chr: tituloTeste) caracteres.push_back(chr);
    
    auto testeChars = (all_of(caracteres.begin(), caracteres.end(), [](char x) {
        return (isalpha(x) || x == ' ' || x == '.');
    }));
    
    if (tituloTeste.length() < 5 || tituloTeste.length() > 20)
        throw invalid_argument("Título deve conter entre 5 e 20 caracteres.");
    
    if (pontoEmSequencia(tituloTeste))
        throw invalid_argument("Título não pode conter pontos em sequência.");
    if (espacoEmSequencia(tituloTeste))
        throw invalid_argument("Título não pode conter espaços em sequência.");
    
    if (!testeChars)
        throw invalid_argument("Título deve conter somente letras, espaços em branco ou pontos.");
}

/// @brief Construtor padr&atilde;o de Titulo
/// @details Simplesmente atribui o valor "TITULO" ao atributo titulo

Titulo::Titulo() : titulo{this->PADRAO} {}

/// @brief Construtor parametrizado da classe Titulo
/// @details Recebe um par&acirc;metro e utiliza o m&eacute;todo set para construir o objeto.
/// @param tituloExcursao T&iacute;tulo da excurs&atilde;o.

Titulo::Titulo(string tituloExcursao)
{
    this->setTitulo(tituloExcursao);
}

/// @brief Fun&ccedil;&atilde;o que muda o t&iacute;tulo
/// @details Recebe um t&iacute;tulo, valida e trata exce&ccedil;&atilde;o se lan&ccedil;ada.
/// @param tituloExcursao T&iacute;tulo da excurs&atilde;o.

void Titulo::setTitulo(string tituloExcursao)
{
    this->validar(tituloExcursao);
    this->titulo = tituloExcursao;
}
