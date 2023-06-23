#include "sistema.h"

sistema::sistema(){
    this->usuarioAtualId = -1;
    this->logado = false;
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

usuario sistema::getUsuarioByPos(int idtoSerach) const{
    return this->todosUsuarios.at(idtoSerach);
}

int sistema::getUsuarioAtual() const{
    return this->usuarioAtualId;
}

std::string sistema::getServidorAtual() const{
    return this->nomeServidorAtual;
}

bool sistema::emailCadastrado(std::string email) const{
    int tam = this->todosUsuarios.size();
    for (int i = 0; i < tam; i++){
        if(getUsuarioByPos(i).getEmail() == email){
            return true;
        }
    }
    return false;
}

void sistema::addUsuario(usuario u){
    this->todosUsuarios.push_back(u);
}

bool sistema::getEstadoLogin(){
    return this->logado;
}

void sistema::createUser(std::vector<std::string> atributos){
    if(emailCadastrado(atributos.at(0)) == false){
        addUsuario(usuario(getTamUser() + 1, atributos.at(2), atributos.at(0), atributos.at(1)));
        std::cout << "Cadastro realizado com sucesso!" << std::endl;
    } else{
        std::cout << "Esse email já está cadastrado!" << std::endl;
    }
}

void sistema::setLoginStatus(bool status, int idUser){
    this->logado = status;
    this->usuarioAtualId = idUser;
}
void sistema::loginUser(std::vector<std::string> atributos){
    int tam = this->todosUsuarios.size();
    for(int i = 0; i < tam; i++){
        std::string email = getUsuarioByPos(i).getEmail();
        std::string senha = getUsuarioByPos(i).getSenha();
        if(email == atributos.at(0) && senha == atributos.at(1)){
            setLoginStatus(true ,i);
            std::cout << "Logado como " << email << std::endl;
            return;
        }
    }
    std::cout << "Email ou Senha incorretos" << std::endl;
}

void sistema::logoffUser(){
    std::cout << "Desconectando Usuário " << getUsuarioByPos(getUsuarioAtual()).getEmail() << std::endl;
    setLoginStatus(false, -1);
}

void sistema::addServer(servidor s){
    this->todosServidores.push_back(s);
}

servidor sistema::getServerByPos(int pos) const{
    return this->todosServidores.at(pos);
}

bool sistema::servidorCadastrado(std::string nomeServer){
    int tam = this->todosServidores.size();
    for (int i = 0; i < tam; i++){
        if(getServerByPos(i).getNomeServidor() == nomeServer){
            return true;
        }
    }
    return false;
}

void sistema::createServer(std::vector<std::string> atributos){
    if(servidorCadastrado(atributos.at(0)) == false){
        addServer(servidor(this->getUsuarioAtual(), atributos.at(0)));
        std::cout << "Servidor '" << atributos.at(0) << "' criado com sucesso!" << std::endl;
        return;
    }
    std::cout << "Servidor '" << atributos.at(0) << "' já existe." << std::endl;
}