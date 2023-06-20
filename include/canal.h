#ifndef CANAL_H
#define CANAL_H
#include <iostream>
#include <vector>
#include "mensagem.h"

class canal{
    private:
        std::string nome;
    public:
        canal();
        canal(const std::string nome);
};

class canalTexto : public canal{
    std::vector<mensagem> mensagens;
    canalTexto();
    canalTexto(mensagem novaMensagem);
};

class canalVoz : public canal{
    mensagem ultimaMensagem;
    canalVoz();
    canalVoz(mensagem mensagemVoz);
};
#endif