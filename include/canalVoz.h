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
(que serão implementadas na parte 2)
*/
class canalVoz : public canal{
    private:
        mensagem ultimaMensagem;

    public:
    /**
    * @brief Construtor padrão de canalVoz.
    */
    canalVoz();
};

#endif