#include "sistema.h"

sistema::sistema(){
    this->usuarioAtualId = -1;
    this->logado = false;
}
sistema::~sistema() {
}

int sistema::getTamUser() const{
    return this->todosUsuarios.size();
}

usuario sistema::getUsuarioByPos(int idtoSerach) const{
    return this->todosUsuarios.at(idtoSerach);
}

int sistema::getUsuarioAtual() const{
    return this->usuarioAtualId;
}

std::string sistema::getServidorAtual() const{
    return this->nomeServidorAtual;
}

bool sistema::emailCadastrado(std::string email) const{
    int tam = this->todosUsuarios.size();
    for (int i = 0; i < tam; i++){
        if(getUsuarioByPos(i).getEmail() == email){
            return true;
        }
    }
    return false;
}

void sistema::addUsuario(usuario u){
    this->todosUsuarios.push_back(u);
}

bool sistema::getEstadoLogin(){
    return this->logado;
}

void sistema::createUser(std::vector<std::string> atributos){
    if(emailCadastrado(atributos.at(0)) == false){
        addUsuario(usuario(getTamUser() + 1, atributos.at(2), atributos.at(0), atributos.at(1)));
        std::cout << "Cadastro realizado com sucesso!" << std::endl;
    } else{
        std::cout << "Esse email já está cadastrado!" << std::endl;
    }
}

void sistema::setLoginStatus(bool status, int idUser){
    this->logado = status;
    this->usuarioAtualId = idUser;
    this->nomeServidorAtual = "";
}
void sistema::loginUser(std::vector<std::string> atributos){
    int tam = this->todosUsuarios.size();
    for(int i = 0; i < tam; i++){
        std::string email = getUsuarioByPos(i).getEmail();
        std::string senha = getUsuarioByPos(i).getSenha();
        if(email == atributos.at(0) && senha == atributos.at(1)){
            setLoginStatus(true ,i);
            std::cout << "Logado como " << email << std::endl;
            return;
        }
    }
    std::cout << "Email ou Senha incorretos" << std::endl;
}

void sistema::logoffUser(){
    std::cout << "Desconectando Usuário " << getUsuarioByPos(getUsuarioAtual()).getEmail() << std::endl;
    setLoginStatus(false, -1);
}

void sistema::addServer(servidor s){
    this->todosServidores.push_back(s);
}

servidor sistema::getServerByPos(int pos) const{
    return this->todosServidores.at(pos);
}

int sistema::getIndiceServidorByName(std::string nomeServer) const{
    int tam = this->todosServidores.size();
    for (int i = 0; i < tam; i++){
        if(getServerByPos(i).getNomeServidor() == nomeServer){
            return i;
        }
    }
    return -1;
}

void sistema::createServer(std::vector<std::string> atributos){
    if(getIndiceServidorByName(atributos.at(0)) == -1){
        addServer(servidor(getUsuarioAtual(), atributos.at(0)));
        this->todosServidores.at(getIndiceServidorByName(atributos.at(0))).addUserId(getUsuarioAtual());
        std::cout << "Servidor '" << atributos.at(0) << "' criado com sucesso!" << std::endl;
        return;
    }
    std::cout << "Servidor '" << atributos.at(0) << "' já existe." << std::endl;
}

void sistema::listServers() const{
    int tam = this->todosServidores.size();
    if(tam == 0){
        std::cout << "Não há servidores criados" << std::endl;
    }
    else{
        for (int i = 0; i < tam; i++){
            std::cout << getServerByPos(i).getNomeServidor() << std::endl;
        }
    }
}

void sistema::deleteServer(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if(indice > -1){
        if(getServerByPos(indice).getIdDono() == this->usuarioAtualId){
            this->nomeServidorAtual = "";
            this->todosServidores.erase(this->todosServidores.begin() + indice);
            std::cout << "Servidor '" << atributos.at(0) << "' removido com sucesso" << std::endl;
        }
        else{
            std::cout << "Esse servidor não pertence a você" << std::endl;
        }
    }
    else{
        std::cout << "Servidor '" << atributos.at(0) << "' não foi encontrado" << std::endl;
    }
}

void sistema::setDescricao(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if (indice > -1){
        if(getServerByPos(indice).getIdDono() == this->usuarioAtualId){
            std::string novaDesc = atributos.at(1);
            if(novaDesc.length() >=2){
                if(novaDesc[0] != '"' || novaDesc[novaDesc.length()-1] != '"'){
                std::cout << "A descrição deve ser passada entre aspas duplas (\"<descricao>\")"
                << std::endl;
                }
                else{
                    novaDesc = novaDesc.substr(1, novaDesc.length() -2);
                    this->todosServidores.at(indice).setDescricao(novaDesc);
                    std::cout << "Descrição alterada com sucesso" << std::endl;
                }
            }
            else{
                std::cout << "Há algo de errado no parametro <descricao>" << std::endl;
            }
        }
        else{
            std::cout << "Esse servidor não pertence a você" << std::endl;
        }
    }
    else{
        std::cout << "Servidor '" << atributos.at(0) << "' não foi encontrado" << std::endl;
    }
}

void sistema::getInformacaoServer(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if(indice > -1){
        getServerByPos(indice).infoServer();
    }
    else{
        std::cout << "Servidor '" << atributos.at(0) << "' não foi encontrado" << std::endl;
    }
}

void sistema::setCodigoConvite(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if (indice > -1){
        if(getServerByPos(indice).getIdDono() == this->usuarioAtualId){
            this->todosServidores.at(indice).setCodigoConvite(atributos.at(1));
            if(atributos.at(1) == ""){
                std::cout << " O Código de convite foi removido" << std::endl;
            }
            else{
                std::cout << "Código de convite alterado com sucesso!" << std::endl;
            }
        }
        else{
            std::cout << "Esse servidor não pertence a você" << std::endl;
        }

    }
    else{
        std::cout << "Servidor '" << atributos.at(0) << "' não foi encontrado" << std::endl;
    }
}

void sistema::enterServer(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if (indice > -1){

        if(this->todosServidores.at(indice).buscaUserId(this->getUsuarioAtual()) == true){
            if (this->nomeServidorAtual == getServerByPos(indice).getNomeServidor()){
                std::cout << "Você já está visualizando o servidor '" << getServerByPos(indice).getNomeServidor()
                << "'" << std::endl;
            }
            else{
                std::cout << "Agora você está visualizando o servidor '" << getServerByPos(indice).getNomeServidor()
                << "'" << std::endl;
                this->nomeServidorAtual = getServerByPos(indice).getNomeServidor();
            }
        }
        else{
            if(this->todosServidores.at(indice).getCodigoConvite() == ""){
                this->todosServidores.at(indice).addUserId(this->getUsuarioAtual());
                std::cout << "Você entrou no servidor '" << getServerByPos(indice).getNomeServidor()
                << "'" << std::endl;
                this->nomeServidorAtual = getServerByPos(indice).getNomeServidor();
            }
            else{
                if(atributos.at(1) == ""){
                    std::cout << "O servidor '" << getServerByPos(indice).getNomeServidor()
                << "' requer um código de convite" << std::endl;
                }
                else if (atributos.at(1) == getServerByPos(indice).getCodigoConvite()){
                    this->todosServidores.at(indice).addUserId(this->getUsuarioAtual());
                std::cout << "Você entrou no servidor '" << getServerByPos(indice).getNomeServidor()
                << "'" << std::endl;
                this->nomeServidorAtual = getServerByPos(indice).getNomeServidor();
                } else{
                    std::cout << "Código de convite inválido" << std::endl;
                }
            }
        }
    }
    else{
        std::cout << "Servidor '" << atributos.at(0) << "' não foi encontrado" << std::endl;
    }
}

void sistema::leaveServer(){
    if(this->nomeServidorAtual == ""){
        std::cout << "Você não está visualizando nenhum servidor" << std::endl;
    }
    else{
        std::cout << "Saindo do servidor '" << this->nomeServidorAtual << "'" << std::endl;
        this->nomeServidorAtual = "";
    }
}

void sistema::listarParticipantes() const{
    if (this->nomeServidorAtual == ""){
        std::cout << "Você precisa está vusualizando um servidor para poder usar esse comando" << std::endl;
    } else{
        std::vector<int> ids = this->todosServidores.at(this->getIndiceServidorByName(this->nomeServidorAtual)).getAllUsers();
        int tam = ids.size();
        for(int i = 0; i < tam; i++){
            std::cout<< getUsuarioByPos(ids.at(i)).getNome() << std::endl;
        }
    }
}