/**
* @file servidor.h
* @brief Definição da classe mensagem
*/
#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <iostream>

/**
*@class mensagem
*@brief Classe responsável pelo gerenciamento de mensagem
*/
class mensagem{
    private:
        std::string dataHora;
        int enviadaPor;
        std::string conteudo;
    public:
        /**
         * @brief Construtor padrão da classe mensagem
         */
        mensagem();
        /**
         * @brief Construtor da classe servidor, com os atributos
         * @param dataHora data e hora da mensagem
         * @param enviadaPor Id do usuário que enviou a mensagem
         * @param conteudo Texto da mensagem
         */
        mensagem(const std::string dataHora, const int envadaPor, const std::string conteudo);
};

#endif