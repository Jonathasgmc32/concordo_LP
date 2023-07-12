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
    this->participantesId.push_back(idDono);
}

/**
 * * @brief Destrutor da classe servidor
*/
servidor::~servidor() {
}

/**
* @brief Função que desaloca os ponteiros de canais de um servidor
*/
void servidor::clearServidor(){
    for (canal* c : this->canais) {
        delete c;
    }
    this->canais.clear();
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
* @brief Obtém a descrição do servidor
* @return Uma string que contém a descrição do servidor
*/
std::string servidor::getDescricao(){
    return this->descServidor;
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

/**
* @brief Imprime os canais, de acordo com seu tipo, ou imprime um feedback de que não ha canais
*/

void servidor::imprimirCanais() const{
    int tam = this->canais.size();
    int qtdText = 0, qtdVoz = 0;
    std::cout << "#canais de texto" << std::endl;
    for(int i = 0; i < tam; i++){
        if(this->canais.at(i)->tipoCanal() == "texto"){
            std::cout << this->canais.at(i)->getNomeCanal() << std::endl;
            qtdText++;
        }
    }
        if(qtdText == 0){
            std::cout << "Não há canais de texto nesse servidor" << std::endl;
        }
    std::cout << "#canais de voz" << std::endl;
    for(int i = 0; i < tam; i++){
        if(this->canais.at(i)->tipoCanal() == "voz"){
            std::cout << this->canais.at(i)->getNomeCanal() << std::endl;
            qtdVoz++;
        }
    }
        if(qtdVoz == 0){
            std::cout << "Não há canais de voz nesse servidor" << std::endl;
        }
}

/**
* @brief Função que verifica se um canal já existe ou não
* @param nome Nome do canal
* @return int com indice do canal, ou -1 caso o canal não exista
*/
int servidor::getIndiceCanalByNome(std::string nomeCanal) const {
    int tam = this->canais.size();
    for(int i = 0; i < tam; i++){
        if(this->canais.at(i)->getNomeCanal() == nomeCanal){
            return i;
        }
    }
    return -1;
}

/**
* @brief Insere canal no vector de canais
* @param c canal a ser inserido
*/

void servidor::insertCanal(canal *c){
    this->canais.push_back(c);
}

/**
* @brief Função que adiciona canal ao servidor
* @param nome Nome do canal
* @param tipo tipo do canal
*/
void servidor::addCanal(std::string nome, std::string tipo){
    if(tipo != "texto" && tipo != "voz"){
        std::cout << "O tipo só pode ser 'texto' ou 'voz'" << std::endl;
        return;
    }
    if(getIndiceCanalByNome(nome) > -1){
        std::cout << "O canal '" << nome <<"' já existe" << std::endl;
        return;
    }
    if(tipo == "voz"){
        canalVoz *c = new canalVoz(nome);
        insertCanal(c);
        //this->canais.push_back(c);
    } else if(tipo == "texto"){
        canalTexto *c = new canalTexto(nome);
        insertCanal(c);
        //this->canais.push_back(c);
    }
    
    std::cout << "Canal de " << tipo << " '" << nome << "' adicionado com sucesso!" << std::endl;
}

/**
* @brief Função que retorna todos os canais do servidor
* @return Um vector de ponteiros de canais
*/
std::vector<canal*> servidor::getAllCanais(){
    return this ->canais;
}

/**
* @brief Função que adiciona uma mensagem a um dos canais do servidor
* @param idUser Id do usuário que enviou a mensagem
* @param mensg string que contem o conteúdo da mensagem
* @param dataHora string que contem a data e a hora de envio da mensagem
* @param nomeCanal nome do canal que a mensagem será enviada
*/
void servidor::envarMensagem(int userId, std::string mensg, std::string dataHora, std::string nomeCanal){
    this->canais.at(getIndiceCanalByNome(nomeCanal))->enviarMensagem(userId, mensg, dataHora);
}

/**
* @brief Função que obtém um pontero de canal no vector de canais a partir do nome do canal
* @return um ponteiro de canal
*/
canal* servidor::getCanalByName(std::string nome){
    return this->canais.at(getIndiceCanalByNome(nome));
}