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

* @class canalTexti
* @brief Representa um canal de texto.
* Essa classe é derivada da classe "canal"
e as funções aqui presentes são específicas para os canais de texto
(que serão implementadas na parte 2)
*/
class canalTexto : public canal{
    private:
        std::vector<mensagem> mensagens;
    public:
    /**
    * @brief Construtor padrão de canalTexto.
    */
    canalTexto();
};

#endif