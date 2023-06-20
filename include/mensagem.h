#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <iostream>

class mensagem{
    private:
        std::string dataHora;
        int enviadaPor;
        std::string conteudo;
    public:
        mensagem();
        mensagem(const std::string dataHora, const int envadaPor, const std::string conteudo);
};

#endif