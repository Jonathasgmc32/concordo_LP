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