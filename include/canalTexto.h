/**
* @file canalTexto.h
* @brief Definição da classe canal de texto
*/
#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <iostream>
#include <vector>
#include "canal.h"


/**

* @class canalTexto
* @brief Representa um canal de texto.
* Essa classe é derivada da classe "canal"
e as funções aqui presentes são específicas para os canais de texto
*/
class canalTexto : public canal{
    private:
        std::vector<mensagem> mensagens;
    public:
    /**
    * @brief Construtor padrão de canalTexto.
    */

    /**
    * @brief Construtor de canalTexto com atributos
    */
    canalTexto(std::string nome);
    /**
    * @brief Destrutor da classe canalTexto
    */
    ~canalTexto();
    /**
    * @brief Função que retorna o tipo do canal
    * @return String com o tipo do canal
    */
    std::string tipoCanal() const override;

    /**
    * @brief Adiciona uma mensagem ao vector de mensagens.
    * @param idUser O id do usuário que enviou a mensagem.
    * @param mensg A mensagem a ser enviada.
    * @param dataHora A data e hora da mensagem.
    */
    void enviarMensagem(int idUser, std::string mensg, std::string dataHora) override;

    /**
    * @brief Função que retorna o vector de mensagens do canal
    * @return um vector contendo as mensagens do canal
    */
    std::vector<mensagem> getMensagens() override;
};

#endif