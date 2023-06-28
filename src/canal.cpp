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