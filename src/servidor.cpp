#include "servidor.h"

servidor::servidor(){}
servidor::servidor(int idDono, std::string nomeServidor){
    this->userDonoId = idDono;
    this->nomeServidor = nomeServidor;
}

servidor::~servidor() {
    for (auto canal: canais){
        delete canal;
    }
    canais.clear();
}

std::string servidor::getNomeServidor() const {
    return this->nomeServidor;
}