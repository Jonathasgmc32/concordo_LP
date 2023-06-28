#include "usuario.h"

/**
* @brief Construtor padrão da classe usuario
*/
usuario::usuario(){}

/**
* @brief Construtor da classe usuario com parâmetros
* @param id Id do usuário
* @param nome Nome do usuário
* @param email Email do usuário
* @param senha Senha do usuário
*/
usuario::usuario(const int id, const std::string nome, const std::string email, const std::string senha){
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

/**
* @brief Obtém o email do usuário
* @return Sring contendo o email do usuário
*/
std::string usuario::getEmail(){
    return this->email;
}
/**
* @brief Obtém a senha do usuário
* @return Sring contendo a senha do usuário
*/
std::string usuario::getSenha(){
    return this->senha;
}
/**
* @brief Obtém o nome do usuário
* @return Sring contendo o nome do usuário
*/
std::string usuario::getNome(){
    return this->nome;
}