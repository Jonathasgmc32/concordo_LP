#include "servidor.h"
/**
* @brief Construtor padrão da classe servidor
*/
servidor::servidor(){}
/**
* @brief Construtor da classe servidor com parâmetros
* @param idDono ID do usuário dono do servidor
* @param nomeServidor Nome do servidor
*/
servidor::servidor(int idDono, std::string nomeServidor){
    this->userDonoId = idDono;
    this->nomeServidor = nomeServidor;
}

/**
 * * @brief Destrutor da classe servidor, delete os ponteiros para canais
*/
servidor::~servidor() {
    for (auto canal: canais){
        delete canal;
    }
    canais.clear();
}

/**
* @brief Obtém o nome do servidor
* @return Nome do servidor
*/
std::string servidor::getNomeServidor() const {
    return this->nomeServidor;
}

/**
* @brief Obtém o ID do usuário dono do servidor
* @return ID do usuário dono do servidor
* 
*/
int servidor::getIdDono() const{
    return this->userDonoId;
}

/**
* @brief Verifica se um usuário está presente no servidor
* @param id ID do usuário a ser buscado
* @return true se o usuário está presente, false caso contrário
*/
bool servidor::buscaUserId(int id) const{
    int tam = this->participantesId.size();
    for (int i = 0; i < tam; i++){
        if(this->participantesId.at(i) == id){
            return true;
        }
    }
    return false;
}

/**
* @brief Verifica se um usuário já está no servidor, e o adiciona se não estiver
* @param id ID do usuário a ser adicionado
*/
void servidor::addUserId(int id){
    if(buscaUserId(id) == false){
        this->participantesId.push_back(id);
    }
}

/**
* @brief Define a descrição do servidor
* @param novaDesc Nova descrição do servidor
*/
void servidor::setDescricao(std::string novaDesc){
    this->descServidor = novaDesc;
}

/**
* @brief Exibe informações sobre o servidor (nome, descrição e quantidade de membros)
*/
void servidor::infoServer() const{
    std::cout << "Nome do Servidor: " << this->nomeServidor << std::endl;
    std::cout << "Descrição do Servidor: " << this->descServidor << std::endl;
    std::cout << "Quantidade de membros: " << this->participantesId.size() << std::endl;
}

/**
* @brief Define/altera o código de convite do servidor
* @param novoCodigo Novo código de convite
*/
void servidor::setCodigoConvite(std::string novoCodigo){
    this->codigoConvite = novoCodigo;
}

/**
* @brief Obtém o código de convite do servidor
* @return Código de convite do servidor
*/
std::string servidor::getCodigoConvite() const{
    return this->codigoConvite;
}

/**
* @brief Obtém todos os IDs dos usuários participantes do servidor
* @return Vetor com os IDs dos usuários participantes
*/
std::vector<int> servidor::getAllUsers() const{
    return this->participantesId;
}