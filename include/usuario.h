#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

class usuario{
    private:
        int id;
        std::string nome;
        std::string email;
        std::string senha;
    public:
        usuario();
        usuario(const int id, const std::string nome, const std::string email, const std::string senha);
        std::string getEmail();
};

#endif