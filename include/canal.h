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
*@class canal
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
        /**
         * @brief Destrutor de canal
         */
        virtual ~canal();

        /**
         * @brief Função que obtém o nome do canal
         * @return string com o nome do canal
         */
        std::string getNomeCanal();

        /**
        * @brief Função virtual que obtém o tipo do canal.
        * @return Uma string com o tipo do canal.
        */
        virtual std::string tipoCanal() const = 0;

        /**
        * @brief Função virtual que adiciona uma mensagem ao vector de mensagens.
        * @param idUser O id do usuário que enviou a mensagem.
        * @param mensg A mensagem a ser enviada.
        * @param dataHora A data e hora da mensagem.
        */
        virtual void enviarMensagem(int idUser, std::string mensg, std::string dataHora) = 0;

        /**
        * @brief Função virtual que retorna o vector de mensagens do canal.
        * @return Um vector contendo as mensagens do canal.
        */
        virtual std::vector<mensagem> getMensagens() = 0;
};
#endif