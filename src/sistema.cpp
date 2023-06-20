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

int sistema::getTamUser() const{
    return this->todosUsuarios.size();
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

void sistema::addUsuario(usuario u){
    this->todosUsuarios.push_back(u);
}