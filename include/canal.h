/**
* @file canal.h
* @brief Definição da classe canal
*/
#ifndef CANAL_H
#define CANAL_H
#include <iostream>
#include <vector>
#include "mensagem.h"

/**
*@class mensagem
*@brief Classe responsável pelo gerenciamento de canal
*/
class canal{
    private:
        std::string nome;
    public:
        /**
         * @brief Construtor padrão da classe canal
         */
        canal();
        /**
         * @brief Construtor da classe canal, com atributo
         * @param nomeCanal Nome do canal
         */
        canal(const std::string nomeCanal);
};
#endif