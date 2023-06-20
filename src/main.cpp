#include <iostream>
#include <sstream>
#include "sistema.h"

void createUser(sistema &s, std::string atributos){
    if(s.getUsuarioAtual() != -1){
        std::cout << "Você não pode usar esse comando enquanto logado" << std::endl;
        return;
    }
    if(atributos == ""){
        std::cout << "Poucos atributos passados para o comando 'create-user'" << std::endl;
        return;
    }
}

int main(){
    sistema s;
    std::string linha;
    std::string comando = "start";
    while(linha != "quit"){
        std::getline(std::cin, linha);
        std::istringstream iss(linha);
        iss >> comando;
        std::string restanteLinha;
        std::string atributos;
        while (iss >> atributos) {
            restanteLinha += atributos + " ";
        }
        if(comando == "quit"){
            std::cout << "Saindo do Concordo..." << std::endl;
        } else if (comando == "create-user"){
            createUser(s, atributos);
        } else{
            std::cout << "Entrada inválida" << std::endl;
        }
    }
    return 0;
}