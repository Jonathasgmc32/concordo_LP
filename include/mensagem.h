/**
* @file mensagem.h
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
         * @param id Id do usuário que enviou a mensagem
         * @param conteudo Texto da mensagem
         * @param dataHora data e hora da mensagem
         */
        mensagem(int id, std::string conteudo, std::string dataHora);

        /**
         * @brief Função que retorna o id de quem enviou a mensagem
         * @return um int do id do usuário
         */
        int getIdUserMensagem();
        /**
         * @brief Função que retorna a data e a hora de envio da mensagem
         * @return uma string contendo a data e a hora da mensagem
         */
        std::string getDataMensagem();
        /**
         * @brief Função que retorna o conteúdo da mensagem
         * @return uma string contendo o conteúdo da mensagem
         */
        std::string getConteudoMensagem();
};

#endif