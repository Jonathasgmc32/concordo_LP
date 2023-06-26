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

int servidor::getIdDono() const{
    return this->userDonoId;
}

bool servidor::buscaUserId(int id) const{
    int tam = this->participantesId.size();
    for (int i = 0; i < tam; i++){
        if(this->participantesId.at(i) == id){
            return true;
        }
    }
    return false;
}

void servidor::addUserId(int id){
    if(buscaUserId(id) == false){
        this->participantesId.push_back(id);
    }
}

void servidor::setDescricao(std::string novaDesc){
    this->descServidor = novaDesc;
}

void servidor::infoServer() const{
    std::cout << "Nome do Servidor: " << this->nomeServidor << std::endl;
    std::cout << "Descrição do Servidor: " << this->descServidor << std::endl;
    std::cout << "Quantidade de membros: " << this->participantesId.size() << std::endl;
}

void servidor::setCodigoConvite(std::string novoCodigo){
    this->codigoConvite = novoCodigo;
}

std::string servidor::getCodigoConvite() const{
    return this->codigoConvite;
}

std::vector<int> servidor::getAllUsers() const{
    return this->participantesId;
}