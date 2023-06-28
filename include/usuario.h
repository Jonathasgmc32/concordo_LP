/**
* @file usuario.h
* @brief Definição da classe usuario
*/
#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
/**
*@class usuario
*@brief Classe responsável pelo gerenciamento de usuário
*/
class usuario{
    private:
        int id;
        std::string nome;
        std::string email;
        std::string senha;
    public:
        /**
        * @brief Construtor padrão da classe usuario
        */
        usuario();
        /**
        * @brief Construtor da classe usuario com parâmetros
        * @param id Id do usuário
        * @param nome Nome do usuário
        * @param email Email do usuário
        * @param senha Senha do usuário
        */
        usuario(const int id, const std::string nome, const std::string email, const std::string senha);
        /**
        * @brief Obtém o email do usuário
        * @return Sring contendo o email do usuário
        */
        std::string getEmail();
        /**
        * @brief Obtém a senha do usuário
        * @return Sring contendo a senha do usuário
        */
        std::string getSenha();
        /**
        * @brief Obtém o nome do usuário
        * @return Sring contendo o nome do usuário
        */
        std::string getNome();
};

#endif