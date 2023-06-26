#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <vector>
#include "canal.h"

class servidor{
    private: 
        int userDonoId;
        std::string nomeServidor;
        std::string descServidor;
        std::string codigoConvite;
        std::vector<canal *> canais;
        std::vector<int> participantesId;
    public:
        servidor();
        servidor(int idDono, std::string nomeServidor);
        ~servidor();
        std::string getNomeServidor() const;
        int getIdDono() const;
        bool buscaUserId(int id) const;
        void addUserId(int id);
        void setDescricao(std::string novaDesc);
        void infoServer() const;
        void setCodigoConvite(std::string novoCodigo);
        std::string getCodigoConvite() const;
        std::vector<int> getAllUsers() const;
};
#endif