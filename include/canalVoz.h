/**
* @file canalVoz.h
* @brief Definição da classe canal de Voz
*/
#ifndef CANALVOZ_H
#define CANALVOZ_H
#include <iostream>
#include <vector>
#include "canal.h"


/**

* @class canalVoz
* @brief Representa um canal de voz.
* Essa classe é derivada da classe "canal"
e as funções aqui presentes são específicas para os canais de voz
*/
class canalVoz : public canal{
    private:
        mensagem ultimaMensagem;

    public:
    /**
    * @brief Construtor padrão de canalVoz
    */
    /**
    * @brief Construtor de canalVoz com atributos
    */
    canalVoz(std::string nome);
    /**
    * @brief Destrutor da classe canalVoz
    */
    ~canalVoz();
    /**
    * @brief Função que retorna o tipo do canal
    * @return String com o tipo do canal
    */
    std::string tipoCanal() const override;
    
    /**
    * @brief Muda a variavel ultimaMensagem para a nova mensagem que foi enviada
    * @param idUser O id do usuário que enviou a mensagem.
    * @param mensg A mensagem a ser enviada.
    * @param dataHora A data e hora da mensagem.
    */
    void enviarMensagem(int idUser, std::string mensg, std::string dataHora) override;
    
    /**
    * @brief Função que retorna a unica mensagem do canal
    * @return um vector de 1 elemento mensagem
    */
    std::vector<mensagem> getMensagens() override;
};

#endif