/**
* @file servidor.h
* @brief Definição da classe servidor
*/
#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <vector>
#include "canal.h"
#include "canalVoz.h"
#include "canalTexto.h"

/**
*@class servidor
*@brief Classe responsável pelo gerenciamento de servidor
*/
class servidor{
    private: 
        int userDonoId;
        std::string nomeServidor;
        std::string descServidor;
        std::string codigoConvite;
        std::vector<canal*> canais;
        std::vector<int> participantesId;
    public:
        /**
         * @brief Construtor padrão da classe servidor
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
         * @brief Obtém a descrição do servidor
         * @return Uma string que contém a descrição do servidor
         */
        std::string getDescricao();

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

        /**
         * @brief Imprime o nome dos canais, classificando em texto e voz
         */
        void imprimirCanais() const;

        /**
        * @brief Função que verifica se um canal já existe ou não
        * @param nome Nome do canal
        * @return int com indice do canal, ou -1 caso o canal não exista
        */
        int getIndiceCanalByNome(std::string nomeCanal) const;

        /**
         * @brief Insere canal no vector de canais
         * @param c canal a ser inserido
         */
        void insertCanal(canal *c);
        /**
         * @brief Função que adiciona canal ao servidor
         * @param nome Nome do canal
         * @param tipo tipo do canal
         */
        void addCanal(std::string nome, std::string tipo);
        
        /**
         * @brief Função que retorna todos os canais do servidor
         * @return Um vector de ponteiros de canais
         */
        std::vector<canal*> getAllCanais();
        /**
         * @brief Função que desaloca os ponteiros de canais de um servidor
         */
        void clearServidor();

        /**
         * @brief Função que adiciona uma mensagem a um dos canais do servidor
         * @param idUser Id do usuário que enviou a mensagem
         * @param mensg string que contem o conteúdo da mensagem
         * @param dataHora string que contem a data e a hora de envio da mensagem
         * @param nomeCanal nome do canal que a mensagem será enviada
         */
        void envarMensagem(int idUser, std::string mensg, std::string dataHora, std::string nomeCanal);

        /**
         * @brief Função que obtém um pontero de canal no vector de canais a partir do nome do canal
         * @return um ponteiro de canal
         */
        canal* getCanalByName(std::string nome);
};
#endif