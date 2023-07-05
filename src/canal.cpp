#include "canal.h"

/**
* @brief Construtor padrão da classe canal
*/
canal::canal(){}

/**
* @brief Construtor da classe canal, com atributo
* @param nomeCanal Nome do canal
*/
canal::canal(std::string nomeCanal){
    this->nome = nomeCanal;
}
/**
* @brief Destrutor da classe canal
*/
canal::~canal(){}
/**
* @brief Função que obtém o nome de um canal
* @return Uma string com o nome do canal
*/
std::string canal::getNomeCanal(){
    return this->nome;
}

/**
* @brief Função que retorna o tipo do canal
* @return Uma string com o tipo do canal
*/
std::string canal::tipoCanal() const{
    return "canal";
}

/**
* @brief Função que adiciona uma mensagem ao vector de mensagens.
* @param idUser O id do usuário que enviou a mensagem.
* @param mensg A mensagem a ser enviada.
* @param dataHora A data e hora da mensagem.
*/
void canal::enviarMensagem(int idUser, std::string mensg, std::string dataHora){
}

/**
* @brief Função que retorna o vector de mensagens do canal.
* @return Um vector contendo as mensagens do canal.
*/
std::vector<mensagem> canal::getMensagens(){
    std::vector<mensagem> m;
    return m;
}