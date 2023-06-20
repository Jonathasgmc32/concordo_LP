#include "sistema.h"

sistema::sistema(){
    this->usuarioAtualId = -1;
}
sistema::~sistema() {
    for (auto usuario: todosUsuarios){
        //delete usuario;
    }
    todosUsuarios.clear();
    for (auto servidor: todosServidores){
        //delete servidor;
    }
    todosServidores.clear();
}

usuario sistema::getUsuarioById(int idtoSerach) const{
    return this->todosUsuarios.at(idtoSerach);
}

int sistema::getUsuarioAtual() const{
    return this->usuarioAtualId;
}

std::string sistema::getServidorAtual() const{
    return this->nomeServidorAtual;
}

int sistema::emailCadastrado(std::string email) const{
    int tam = this->todosUsuarios.size();
    for (int i = 0; i < tam; i++){
        if(getUsuarioById(i).getEmail() == email){
            return 1;
        }
    }
    return 0;
}