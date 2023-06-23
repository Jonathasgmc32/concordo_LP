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
        bool logado;
        std::string nomeServidorAtual;
        std::string nomeCanalAtual;
    public:
        sistema();
        ~sistema();
        int getTamUser() const;
        usuario getUsuarioByPos(int idtoSerach) const;
        int getUsuarioAtual () const;
        void setUsuarioAtual();
        std::string getServidorAtual () const;
        void setServidorAtual();
        std::string getCanalAtual () const;
        void setCanalAtual();
        bool emailCadastrado(std::string email) const;
        void addUsuario(usuario u);
        bool getEstadoLogin();
        void createUser(std::vector<std::string> atributos);
        void setLoginStatus(bool status, int idUser);
        void loginUser(std::vector<std::string> atributos);
        void logoffUser();
        void addServer(servidor s);
        servidor getServerByPos(int pos) const;
        bool servidorCadastrado(std::string nomeServer);
        void createServer(std::vector<std::string> atributos);
};
#endif