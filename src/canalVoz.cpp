#include "canalVoz.h"

/**
* @brief Construtor padrão da classe canalVoz
*/

/**
* @brief Construtor da classe canalVoz com atributos
*/
canalVoz::canalVoz(std::string nome) : canal(nome){
}
/**
* @brief Destrutor da classe canalVoz
*/
canalVoz::~canalVoz(){}
/**
* @brief Função que retorna o tipo do canal
* @return String com o tipo do canal
*/
std::string canalVoz::tipoCanal() const{
    return "voz";
};


/**
* @brief Função que muda a ultima mensagem do canal.
* @param idUser O id do usuário que enviou a mensagem.
* @param mensg A mensagem a ser enviada.
* @param dataHora A data e hora da mensagem.
*/
void canalVoz::enviarMensagem(int idUser, std::string mensg, std::string dataHora){
    this->ultimaMensagem = mensagem(idUser, mensg, dataHora);
}

/**
* @brief Função que retorna a mensagem presente no canal.
* @return Um vector contendo as mensagens uma mensagem do canal.
*/
std::vector<mensagem> canalVoz::getMensagens(){
    std::vector<mensagem> m;
    if(this->ultimaMensagem.getConteudoMensagem() != ""){
         m.push_back(this->ultimaMensagem);
    }
    return m;
}