#include "canalTexto.h"

/**
* @brief Construtor padrão da classe canalTexto
*/

/**
* @brief Construtor da classe canalTexto com atributos
*/
canalTexto::canalTexto(std::string nome) : canal(nome){
}
/**
* @brief Destrutor da classe canalTexto
*/
canalTexto::~canalTexto(){}
/**
* @brief Função que retorna o tipo do canal
* @return String com o tipo do canal
*/
std::string canalTexto::tipoCanal() const{
    return "texto";
};

/**
* @brief Função que adiciona uma mensagem ao vector de mensagens.
* @param idUser O id do usuário que enviou a mensagem.
* @param mensg A mensagem a ser enviada.
* @param dataHora A data e hora da mensagem.
*/
void canalTexto::enviarMensagem(int idUser, std::string mensg, std::string dataHora){
    this->mensagens.push_back(mensagem(idUser, mensg, dataHora));
}

/**
* @brief Função que retorna o vector de mensagens do canal.
* @return Um vector contendo as mensagens do canal.
*/
std::vector<mensagem> canalTexto::getMensagens(){
    return this->mensagens;
}