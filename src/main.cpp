#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include "sistema.h"

void createComs(std :: map <std::string , std::pair<bool, int>> &coms){
    coms["create-user"] = std::pair(false, 3);
    coms["login"] = std::pair(false, 2);
    coms["disconect"] = std::pair(true, 0);
    coms["create-server"] = std::pair(true, 1);
    coms["set-server-desc"] = std::pair(true, 2);
    coms["set-server-invite-code"] = std::pair(true, 2);
}

std::vector<std::string> splitEntrada(std::string restanteLinha, std::string comando){
    std::vector<std::string> atributos;
    std::string a1, a2, a3, entComposta;
    std::istringstream iss(restanteLinha);
    if(comando == "set-server-desc"){
    }
    else if (comando == "create-user"){
        iss >> a1;
        iss >> a2;
        while(iss>> entComposta){
        a3 += entComposta + " ";
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
        if(comando == "quit"){
            std::cout << "Saindo do Concordo..." << std::endl;
        } else{
            std::vector<std::string> atr_sep = splitEntrada(atributos, comando);
            if(coms.find(comando) != coms.end()){
                if(coms[comando].first == s.getEstadoLogin()){
                    if(coms[comando].second != atr_sep.size()){
                        std::cout << "O comando '" << comando << "' esperava " << coms[comando].second <<
                        " argumentos, mas foram passados "<< atr_sep.size() << std::endl;
                    }
                    else{
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
            else{
                std::cout << "Entrada inválida" << std::endl;
            }
        }
    }
    return 0;
}