#include "usuario.h"

usuario::usuario(){}

usuario::usuario(const int id, const std::string nome, const std::string email, const std::string senha){
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

std::string usuario::getEmail(){
    return this->email;
}