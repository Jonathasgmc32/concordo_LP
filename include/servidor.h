/**
* @file servidor.h
* @brief Definição da classe servidor
*/
#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <vector>
#include "canal.h"

/**
*@class sistema
*@brief Classe responsável pelo gerenciamento de servidor
*/
class servidor{
    private: 
        int userDonoId;
        std::string nomeServidor;
        std::string descServidor;
        std::string codigoConvite;
        std::vector<canal *> canais;
        std::vector<int> participantesId;
    public:
        /**
         * @brief Construtor padrão da classe servidor
         * @param idDono ID do usuário dono do servidor
         * @param nomeServidor Nome do servidor
         */
        servidor();
        /**
         * @brief Construtor da classe servidor
         * @param idDono ID do usuário dono do servidor
         * @param nomeServidor Nome do servidor
         */
        servidor(int idDono, std::string nomeServidor);

        /**
         * @brief Destrutor da classe servidor
         */
        ~servidor();

        /**
         * @brief Obtém o nome do servidor
         * @return Nome do servidor
         */
        std::string getNomeServidor() const;

        /**
         * @brief Obtém o ID do usuário dono do servidor
         * @return ID do usuário dono do servidor
         */
        int getIdDono() const;

        /**
         * @brief Verifica se um usuário está presente no servidor
         * @param id ID do usuário a ser buscado
         * @return true se o usuário está presente, false caso contrário
         */
        bool buscaUserId(int id) const;

        /**
         * @brief Adiciona um ID de usuário ao servidor
         * @param id ID do usuário a ser adicionado
         */
        void addUserId(int id);

        /**
         * @brief Define a descrição do servidor
         * @param novaDesc Nova descrição do servidor
         */
        void setDescricao(std::string novaDesc);

        /**
         * @brief Exibe informações sobre o servidor
         */
        void infoServer() const;

        /**
         * @brief Define o código de convite do servidor
         * @param novoCodigo Novo código de convite
         */
        void setCodigoConvite(std::string novoCodigo);

        /**
         * @brief Obtém o código de convite do servidor
         * @return Código de convite do servidor
         */
        std::string getCodigoConvite() const;

        /**
         * @brief Obtém todos os IDs dos usuários participantes do servidor
         * @return Vetor com os IDs dos usuários participantes
         */
        std::vector<int> getAllUsers() const;

};
#endif