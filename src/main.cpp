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
    std::string novoEmail, novaSenha, novoNome, elementoLinha;
    std::istringstream iss(atributos);
    iss >>novoEmail;
    iss >> novaSenha;
    while(iss>> elementoLinha){
        novoNome += elementoLinha + " ";
    }
    if(novoEmail == ""){
        std::cout << "Atributo 'email' não pode ser vazio!" << std::endl;
        return;
    }
    if(novaSenha == ""){
        std::cout << "Atributo 'senha' não pode ser vazio!" << std::endl;
        return;
    }
    if(novoNome == ""){
        std::cout << "Atributo 'nome' não pode ser vazio!" << std::endl;
        return;
    }

    if(s.emailCadastrado(novoEmail) == 0){
        s.addUsuario(usuario(s.getTamUser() + 1, novoNome, novoEmail, novaSenha));
        std::cout << "Cadastro realizado com sucesso!" << std::endl;
    } else{
        std::cout << "Esse email já está cadastrado!" << std::endl;
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
        std::string atributos;
        std::string restanteLinha;
        while (iss >> restanteLinha) {
            atributos += restanteLinha + " ";
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