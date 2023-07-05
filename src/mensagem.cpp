#include "mensagem.h"

/**
* @brief Construtor padrão da classe mensagem
*/
mensagem::mensagem(){}


/**
* @brief Construtor da classe menagem, com atributos
* @param id Id de quem enviou a mensagem
* @param conteudo Conteúdo da mensagem
* @param dataHora Data e hora de envio da mensagem
*/
mensagem::mensagem(int id, std::string conteudo, std::string dataHora){
    this->enviadaPor = id;
    this->conteudo = conteudo;
    this->dataHora = dataHora;
}

/**
* @brief Função que retorna o id de quem enviou a mensagem
* @return um int do id do usuário
*/
int mensagem::getIdUserMensagem(){
    return this->enviadaPor;
}
/**
* @brief Função que retorna a data e a hora de envio da mensagem
* @return uma string contendo a data e a hora da mensagem
*/
std::string mensagem::getDataMensagem(){
    return this->dataHora;
}
/**
* @brief Função que retorna o conteúdo da mensagem
* @return uma string contendo o conteúdo da mensagem
*/
std::string mensagem::getConteudoMensagem(){
    return this->conteudo;
}