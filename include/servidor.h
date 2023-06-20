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


};
#endif