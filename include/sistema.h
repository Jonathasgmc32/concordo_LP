/**
* @file sistema.h
* @brief Definição da classe sistema
*/
#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <vector>
#include "usuario.h"
#include "servidor.h"

/**
*@class sistema
*@brief Classe responsável pelo gerenciamento do sistema
*/
class sistema{
    private:
        std::vector<usuario> todosUsuarios;
        std::vector<servidor> todosServidores;
        int usuarioAtualId;
        bool logado;
        std::string nomeServidorAtual;
        std::string nomeCanalAtual;
    public:
        /**
        * @brief Construtor da classe sistema
        */
        sistema();
        /**
        * @brief Destrutor da classe sistema
        */
        ~sistema();
        /**
        * @brief Obtém o tamanho do vetor de usuários
        * @return Tamanho do vetor de usuários
        */
        int getTamUser() const;
        /**
        * @brief Obtém um usuário pela posição no vetor
        * @param posToSearch posição do vector para a procura
        * @return O usuário da posição
        */
        usuario getUsuarioByPos(int posToSerach) const;
        /**
        * @brief Obtém o ID do usuário atualmente logado no sistema
        * @return ID do usuário atualmente logado
        */
        int getUsuarioAtual () const;
        /**
        * @brief Muda o id do usuário atualmente logado no sistema
        * @param idUser novo valor para o Id atual 
        */
        void setUsuarioAtual(int idUser);
        /**
        * @brief Obtém o nome do servidor que está sendo visualizado
        * @return Nome do servidor que está sendo visualizado
        */
        std::string getServidorAtual () const;
        /**
        * @brief Muda o nome do servidor que será visualizado
        */
        void setServidorAtual(std::string nomeServidor);
        /**
        * @brief Obtém o nome do canal que está selecionado (implementação na parte 2)
        * @return Nome do canal que está selecionado.
        */
        std::string getCanalAtual () const;
        /**
        * @brief Define o canal atualmente selecionado (implementação na parte 2)
        */
        void setCanalAtual();
        /**
        * @brief Verifica se um email está cadastrado no sistema
        * @param email Email a ser verificado
        * @return Booleano, verdadeiro se o email está cadastrado, falso caso contrário
        */
        bool emailCadastrado(std::string email) const;
        /**
        * @brief Adiciona um novo usuário ao sistema
        * @param u Usuário a ser adicionado
        */
        void addUsuario(usuario u);
        /**
        * @brief Obtém o estado do login no sistema
        * @return verdadeiro, se logado, falso caso contrário
        */
        bool getEstadoLogin();
        /**
        * @brief Cria um novo usuário no sistema com base nos atributos fornecidos
        * @param atributos Vector de strings com os atributos de cadastro
        */
        void createUser(std::vector<std::string> atributos);
        /**
        * @brief Define o status de login para um usuário
        * @param status Status do login (logado ou deslogado)
        * @param idUser ID do usuário
        */
        void setLoginStatus(bool status, int idUser);
        /**
        * @brief Realiza o login de um usuário com base nos dados passados.
        * @param atributos Vector de strings, onde são passados os dados de email e senha para o login
        */
        void loginUser(std::vector<std::string> atributos);
        /**
        * @brief Desloga o usuário atualmente logado.
        */
        void logoffUser();
        /**
        * @brief Adiciona um novo servidor ao ao vector de servidores do sistema
        * @param s Servidor a ser adicionado
        */
        void addServer(servidor s);
        /**
        * @brief Obtém um servidor pelo índice
        * @param pos Índice da posição no vector de servidores
        * @return Servidor na posição dada
        */
        servidor getServerByPos(int pos) const;
        /**
        * @brief Obtém o índice de um servidor pelo nome.
        * @param nomeServer Nome do servidor.
        * @return Índice do servidor encontrado, ou -1 caso não encontre.
        */
        int getIndiceServidorByName(std::string nomeServer) const;
        /**
        * @brief Cria um novo servidor no sistema com base nos atributos fornecidos.
        * @param atributos Atributos para a criação do servidor (apenas o nome).
        */
        void createServer(std::vector<std::string> atributos);
        /**
        * @brief Lista todos os servidores do sistema.
        */
        void listServers() const;
        /**
        * @brief Exclui um servidor do sistema a partir do nome.
        * @param atributos Atributos para exclusão do servidor (nome do servidor).
        */
        void deleteServer(std::vector<std::string> atributos);
        /**
        * @brief Define ou altera a descrição de um servidor.
        * @param atributos Descrição a ser colocada.
        */
        void setDescricao(std::vector<std::string> atributos);
        /**
        * @brief Obtém as informações gerais de um servidor (nome, descrição e quantidade de membros)
        * @param atributos Nome do servidor
        */
        void getInformacaoServer(std::vector<std::string> atributos);
        /**
        * @brief Define ou altera o código de convite de um servidor
        * @param atributos Novo códivo do servidor
        */
        void setCodigoConvite(std::vector<std::string> atributos);
        /**
        * @brief Entra em um servidor, caso não esteja nele/visualizando ele
        * @param atributos Nome do servidor e código de convite 
        */
        void enterServer(std::vector<std::string> atributos);
        /**
        * @brief Sai de um servidor (apenas no quesito visualização)
        */
        void leaveServer();
        /**
        * @brief Lista todos os participantes do servidor atual.
        */
        void listarParticipantes() const;
};
#endif