#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include "sistema.h"

/**
* @brief Cria um map com os comandos, o estado de login desejado e a quantidade de parâmetros do comando
* @param coms mapa original criado na main, passado por referência
*/
void createComs(std :: map <std::string , std::pair<bool, int>> &coms){
    coms["quit"] = std::pair(false, 0);
    coms["create-user"] = std::pair(false, 3);
    coms["login"] = std::pair(false, 2);
    coms["disconect"] = std::pair(true, 0);
    coms["create-server"] = std::pair(true, 1);
    coms["set-server-desc"] = std::pair(true, 2);
    coms["set-server-invite-code"] = std::pair(true, 2);
    coms["list-servers"] = std::pair(true, 0);
    coms["remove-server"] = std::pair(true, 1);
    coms["info-server"] = std::pair(true, 1);
    coms["enter-server"] = std::pair(true, 2);
    coms["leave-server"] = std::pair(true, 0);
    coms["list-participants"] = std::pair(true, 0);
}

/**
* @brief Trata o restante da entrada que veio após o comando, separando cada atributo em uma posição
do vector. Alguns comandos tem tratametos diferentes.
* @param restanteLinha String com os atributos inseridos pelo usuário
* @param comando Comando que foi solicitado
*/
std::vector<std::string> splitEntrada(std::string restanteLinha, std::string comando){
    std::vector<std::string> atributos;
    std::string a1, a2, a3, entComposta;
    std::istringstream iss(restanteLinha);
    if(comando == "set-server-desc"){ //ou send-message
        iss >> a1;
        atributos.push_back(a1);
        while(iss>> entComposta){
            if(!a2.empty() && a2[a2.length() - 1 != ' ']){
                a2 += " ";
            }
            a2 += entComposta;
        }
        if(!a2.empty()){
            atributos.push_back(a2);
        }
    }
    else if (comando == "create-user"){
        iss >> a1;
        iss >> a2;
        while(iss>> entComposta){
            if(!a3.empty() && a3[a3.length() - 1 != ' ']){
                a3 += " ";
            }
            a3 += entComposta;
        }
        if(a1 != ""){
            atributos.push_back(a1);
        }
        if(a2 != ""){
            atributos.push_back(a2);
        }
        if(a3 != ""){
            atributos.push_back(a3);
        }
    }
    else{
        while(iss>> entComposta){
            atributos.push_back(entComposta);
        }
    }
    if((comando == "set-server-invite-code" || comando == "enter-server") && atributos.size() == 1){
        atributos.push_back("");
    }
    return atributos;
}

/**
* @brief Função main. Cria um objeto da classe sistema, faz as verificações do status e da quantidade
de parâmetros passados, e chama as funções de sistema para o respectivo comando passado.
*/
int main(){
    sistema s;
    std::string linha;
    std::string comando = "start";
    std :: map <std::string , std::pair<bool, int>> coms;
    createComs(coms);
    while(linha != "quit"){
        std::getline(std::cin, linha);
        std::istringstream iss(linha);
        iss >> comando;
        std::string atributos;
        std::string restanteLinha;
        while (iss >> restanteLinha) {
            atributos += restanteLinha + " ";
        }
        std::vector<std::string> atr_sep = splitEntrada(atributos, comando);
        if(coms.find(comando) != coms.end()){
            if(coms[comando].second != atr_sep.size()){
                std::cout << "O comando '" << comando << "' esperava " << coms[comando].second <<
                    " argumentos, mas foram passados "<< atr_sep.size() << std::endl;
            }
             else{
                if(comando == "quit"){
                        std::cout << "Saindo do Concordo..." << std::endl;
                }
                else{
                    if(coms[comando].first == s.getEstadoLogin()){
                        if(comando == "create-user"){
                            s.createUser(atr_sep);
                        }
                        if(comando == "login"){
                            s.loginUser(atr_sep);
                        }
                        if(comando == "disconect"){
                            s.logoffUser();
                        }
                        if(comando == "create-server"){
                            s.createServer(atr_sep);
                        }
                        if(comando == "list-servers"){
                            s.listServers();
                        }
                        if(comando == "remove-server"){
                            s.deleteServer(atr_sep);
                        }
                        if(comando == "set-server-desc"){
                            s.setDescricao(atr_sep);
                        }
                        if(comando == "info-server"){
                            s.getInformacaoServer(atr_sep);
                        }
                        if(comando == "set-server-invite-code"){
                        s.setCodigoConvite(atr_sep);
                        }
                        if(comando == "enter-server"){
                            s.enterServer(atr_sep);
                        }
                        if(comando == "leave-server"){
                            s.leaveServer();
                        }
                        if(comando == "list-participants"){
                            s.listarParticipantes();
                        }
                    }
                    else{
                        if(s.getEstadoLogin() == false){
                            std::cout << "É necessário está logado para executar o comando '" << comando << "'" << std::endl;
                        }
                        else{
                            std::cout << "O comando '" << comando << "' não pode ser feito enquanto logado" << std::endl;
                        }
                    }
                }
            }
        }
        else{
            std::cout << "Comando inválido" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}