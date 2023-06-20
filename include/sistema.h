#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <vector>
#include "usuario.h"
#include "servidor.h"


class sistema{
    private:
        std::vector<usuario> todosUsuarios;
        std::vector<servidor> todosServidores;
        int usuarioAtualId;
        std::string nomeServidorAtual;
        std::string nomeCanalAtual;
    public:
        sistema();
        ~sistema();
        int getTamUser() const;
        usuario getUsuarioById(int idtoSerach) const;
        int getUsuarioAtual () const;
        void setUsuarioAtual();
        std::string getServidorAtual () const;
        void setServidorAtual();
        std::string getCanalAtual () const;
        void setCanalAtual();
        int emailCadastrado(std::string email) const;
        void addUsuario(usuario u);
};
#endif