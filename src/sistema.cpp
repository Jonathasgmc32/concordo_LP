#include "sistema.h"


/**
* @brief Construtor da classe sistema. 
* Os valores padrões para representar que ninguém está logado são -1 em usuarioAtualId e falso em logado
*/
sistema::sistema(){
    this->usuarioAtualId = -1;
    this->logado = false;
}

/**
* @brief Destrutor da classe sistema
*/
sistema::~sistema() {
}

/**
* @brief Obtém um usuário pela posição no vector de usuários. Geralmente usada com laços for
* @param posToSearch posição do vector para a procura
* @return O usuário da posição
*/
usuario sistema::getUsuarioByPos(int posToSerach) const{
    return this->todosUsuarios.at(posToSerach);
}

/**
* @brief Percorre o vector de usuários do sistema, um de cada vez, obtém o email e compara com o que foi passado
* @param email Email a ser verificado
* @return Booleano, verdadeiro se o email está cadastrado, falso caso contrário
*/
bool sistema::emailCadastrado(std::string email) const{
    int tam = this->todosUsuarios.size();
    for (int i = 0; i < tam; i++){
        if(getUsuarioByPos(i).getEmail() == email){
            return true;
        }
    }
    return false;
}

/**
* @brief Adiciona um novo usuário ao sistema
* @param u Usuário a ser adicionado
*/
void sistema::addUsuario(usuario u){
    this->todosUsuarios.push_back(u);
}

/**
* @brief Obtém o estado do login no sistema
* @return verdadeiro, se logado, falso caso contrário
*/
bool sistema::getEstadoLogin(){
    return this->logado;
}

/**
* @brief Verifica se o email passado como parâmetro já existe, chamando a função emailCadastrado(),
* e se não existir, cria e adiciona um novo usuário ao vector de usuários
* @param atributos Vector de strings com os atributos de cadastro
*/
void sistema::createUser(std::vector<std::string> atributos){
    if(emailCadastrado(atributos.at(0)) == false){
        addUsuario(usuario(this->todosUsuarios.size() + 1, atributos.at(2), atributos.at(0), atributos.at(1)));
        std::cout << "Cadastro realizado com sucesso!" << std::endl;
    } else{
        std::cout << "Esse email já está cadastrado!" << std::endl;
    }
}

/**
* @brief Define o status de login para um usuário, tanto logado quanto deslogado.
* @param status Status do login (logado ou deslogado)
* @param idUser ID do usuário
*/
void sistema::setLoginStatus(bool status, int idUser){
    this->logado = status;
    this->usuarioAtualId = idUser;
    this->nomeServidorAtual = "";
    this->nomeCanalAtual = "";
}
/**
* @brief Percorre o vector de usuários do sistema, fazendo a comparação do email e senha cadastrados com os
* atributros email e senha passados. Caso exista uma combinação em que todos os fatores sejam iguais, é realizado
* o login, caso contrário, dá uma mensagem de erro
* @param atributos Vector de strings, onde são passados os dados de email e senha para o login
*/
void sistema::loginUser(std::vector<std::string> atributos){
    int tam = this->todosUsuarios.size();
    for(int i = 0; i < tam; i++){
        std::string email = getUsuarioByPos(i).getEmail();
        std::string senha = getUsuarioByPos(i).getSenha();
        if(email == atributos.at(0) && senha == atributos.at(1)){
            setLoginStatus(true, getUsuarioByPos(i).getId());
            std::cout << "Logado como " << email << std::endl;
            return;
        }
    }
    std::cout << "Email ou Senha incorretos" << std::endl;
}

/**
* @brief Desloga o usuário atualmente logado.
*/
void sistema::logoffUser(){
    std::cout << "Desconectando Usuário " << getUsuarioByPos(this->usuarioAtualId - 1).getEmail() << std::endl;
    setLoginStatus(false, -1);
}

/**
* @brief Adiciona um novo servidor ao vector de servidores do sistema.
* @param s Servidor a ser adicionado.
*/
void sistema::addServer(servidor s){
    this->todosServidores.push_back(s);
}

/**
* @brief Obtém o índice de um servidor, buscando pelo nome passado na lista de servidores
* @param nomeServer Nome do servidor
* @return Índice do servidor encontrado, ou -1 caso não encontre
*/
int sistema::getIndiceServidorByName(std::string nomeServer) const{
    int tam = this->todosServidores.size();
    for (int i = 0; i < tam; i++){
        if(this->todosServidores.at(i).getNomeServidor() == nomeServer){
            return i;
        }
    }
    return -1;
}

/**
* @brief Verifica se um servidor já existe com o nome passado, se não existir, cria um novo e adiciona
* ao vector de servidores (chamando a função de addServer()). Também adiciona o usuário quem criou o servidor
* ao mesmo, mas não troca a vizualização atual
* @param atributos Atributos para a criação do servidor (apenas o nome).
*/
void sistema::createServer(std::vector<std::string> atributos){
    if(getIndiceServidorByName(atributos.at(0)) == -1){
        addServer(servidor(this->usuarioAtualId, atributos.at(0)));
        this->todosServidores.at(getIndiceServidorByName(atributos.at(0))).addUserId(this->usuarioAtualId);
        std::cout << "Servidor '" << atributos.at(0) << "' criado com sucesso!" << std::endl;
        return;
    }
    std::cout << "Servidor '" << atributos.at(0) << "' já existe." << std::endl;
}

/**
* @brief Lista todos os servidores do sistema.
*/
void sistema::listServers() const{
    int tam = this->todosServidores.size();
    if(tam == 0){
        std::cout << "Não há servidores criados" << std::endl;
    }
    else{
        for (int i = 0; i < tam; i++){
            std::cout << todosServidores.at(i).getNomeServidor() << std::endl;
        }
    }
}

/**
* @brief Verifica se o servidor existe, e caso exista, verifica se quem usou o comando
* de deletar servidor é o dono. Caso seja o dono, apaga o indice do vector onde o servidor se encontra
* @param atributos Atributos para exclusão do servidor (nome do servidor).
*/
void sistema::deleteServer(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if(indice > -1){
        if(todosServidores.at(indice).getIdDono() == this->usuarioAtualId){
            if(this->nomeServidorAtual == atributos.at(0)){
                this->nomeServidorAtual = "";
                this->nomeCanalAtual = "";
            }
            this->todosServidores.at(indice).clearServidor();
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

/**
* @brief Verifica se o servidor existe. Se existir, verifica se quem chamou o comando é o dono.
* Se for o dono, verifica se a entrada possui, pelo menos, 2 caracteres (já que "" é obrigatório).
* Verifica se as palavras da descrição estão entre "", as remove e muda a descrição do servidoe;
* @param atributos Descrição a ser colocada.
*/
void sistema::setDescricao(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if (indice > -1){
        if(todosServidores.at(indice).getIdDono() == this->usuarioAtualId){
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

/**
* @brief Verifica se o servidor existe. Caso exista, chama uma função da classe servidor que
obtém as informações gerais de um servidor (nome, descrição e quantidade de membros)
* @param atributos Nome do servidor
*/
void sistema::getInformacaoServer(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if(indice > -1){
        todosServidores.at(indice).infoServer();
    }
    else{
        std::cout << "Servidor '" << atributos.at(0) << "' não foi encontrado" << std::endl;
    }
}

/**
* @brief Verifica se um servidor existe, e se existir, verifica se quem chamou o comando é o dono do servidor.
*Se tiver deixado o campo <codigo> vazio, o código será removido. Se tiver colocado algo, o código se torna aquilo
*que foi passado para o comando. 
* @param atributos Novo códivo do servidor
*/
void sistema::setCodigoConvite(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if (indice > -1){
        if(todosServidores.at(indice).getIdDono() == this->usuarioAtualId){
            this->todosServidores.at(indice).setCodigoConvite(atributos.at(1));
            if(atributos.at(1) == ""){
                std::cout << "O Código de convite foi removido" << std::endl;
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

/**
* @brief Verifica se um servidor existe, caso exista, verifica se o usuário que usou o comando já entrou
alguma vez nesse servidor. Caso tenha entrado, não será necessário inserir o código de convite, e a visualização será
alterada para o servidor que solicitou (caso esteja vizualizando outro/nenhum servidor). Se é a primeira vez tentando
entrar no servidor, então é feita uma verificação: se o servidor possui ou não código de convite. Se não possuir, a entrada é
garantita, caso tenha, o parâmetro <codigo> passado deve ser igual ao código salvo no servidor para que seja permitida a entrada.
Em ambos os casos, ao entrar, a vizualização é alternada para o servidor solicitado.
* @param atributos Nome do servidor e código de convite 
*/
void sistema::enterServer(std::vector<std::string> atributos){
    int indice = getIndiceServidorByName(atributos.at(0));
    if (indice > -1){

        if(this->todosServidores.at(indice).buscaUserId(this->usuarioAtualId) == true){
            if (this->nomeServidorAtual == todosServidores.at(indice).getNomeServidor()){
                std::cout << "Você já está visualizando o servidor '" << todosServidores.at(indice).getNomeServidor()
                << "'" << std::endl;
            }
            else{
                std::cout << "Agora você está visualizando o servidor '" << todosServidores.at(indice).getNomeServidor()
                << "'" << std::endl;
                this->nomeServidorAtual = todosServidores.at(indice).getNomeServidor();
                this->nomeCanalAtual = "";
            }
        }
        else{
            if(this->todosServidores.at(indice).getCodigoConvite() == ""){
                this->todosServidores.at(indice).addUserId(this->usuarioAtualId);
                std::cout << "Você entrou no servidor '" << todosServidores.at(indice).getNomeServidor()
                << "'" << std::endl;
                this->nomeServidorAtual = todosServidores.at(indice).getNomeServidor();
                this->nomeCanalAtual = "";
            }
            else{
                if(atributos.at(1) == ""){
                    std::cout << "O servidor '" << todosServidores.at(indice).getNomeServidor()
                << "' requer um código de convite" << std::endl;
                }
                else if (atributos.at(1) == todosServidores.at(indice).getCodigoConvite()){
                    this->todosServidores.at(indice).addUserId(this->usuarioAtualId);
                std::cout << "Você entrou no servidor '" << todosServidores.at(indice).getNomeServidor()
                << "'" << std::endl;
                this->nomeServidorAtual = todosServidores.at(indice).getNomeServidor();
                this->nomeCanalAtual = "";
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

/**
// * @brief Verifica se está visualizando um servidor, e sai dele caso esteja (muda a vizualização para uma strng vazia);
*/
void sistema::leaveServer(){
    if(this->nomeServidorAtual == ""){
        std::cout << "Você não está visualizando nenhum servidor" << std::endl;
    }
    else{
        std::cout << "Saindo do servidor '" << this->nomeServidorAtual << "'" << std::endl;
        this->nomeServidorAtual = "";
        this->nomeCanalAtual = "";
    }
}

/**
* @brief Verifica se o usuário está visualizando algum servidor, e, caso esteja, lista quem participa desse servidor visualizado
*/
void sistema::listarParticipantes() const{
    if (this->nomeServidorAtual == ""){
        std::cout << "Você precisa está vusualizando um servidor para poder usar esse comando" << std::endl;
    } else{
        std::vector<int> ids = this->todosServidores.at(this->getIndiceServidorByName(this->nomeServidorAtual)).getAllUsers();
        int tam = ids.size();
        for(int i = 0; i < tam; i++){
            std::cout<< getUsuarioByPos(ids.at(i) - 1).getNome() << std::endl;
        }
    }
}

/**
* @brief Função que faz as verificações necessárias e imprime os canais de um servidor
*/

void sistema::listarCanais() const{
    if (this->nomeServidorAtual == ""){
        std::cout << "Você precisa está vusualizando um servidor para poder usar esse comando" << std::endl;
    } else{
        todosServidores.at(getIndiceServidorByName(nomeServidorAtual)).imprimirCanais();
    }
}

/**
* @brief Função que faz as verificações necessárias e cria canais em um servidor
*/
void sistema::criarCanalEmServidor(std::vector<std::string> atributos){
    if (this->nomeServidorAtual == ""){
        std::cout << "Você precisa está vusualizando um servidor para poder usar esse comando" << std::endl;
    }
    else{
        int indice = getIndiceServidorByName(this->nomeServidorAtual);
        if (todosServidores.at(indice).getIdDono() == this->usuarioAtualId){
            this->todosServidores.at(indice).addCanal(atributos.at(0), atributos.at(1));
        }
        else{
            std::cout << "Esse servidor não pertence a você" << std::endl;
        }
    }
}

/**
* @brief Função que faz as verificações necessárias e entra em canais de um servidor
* @param abritubos nome do canal e tipo dele
*/
void sistema::entrarCanalEmServidor(std::vector<std::string> atributos){
    if (this->nomeServidorAtual == ""){
        std::cout << "Você precisa está vusualizando um servidor para poder usar esse comando" << std::endl;
    } else{
        if(this->nomeCanalAtual == atributos.at(0)){
            std::cout << "Você já está visualizando o canal '"<< atributos.at(0) << "'" << std::endl;
        }
        else{
            int indice = getIndiceServidorByName(this->nomeServidorAtual);
            if(todosServidores.at(indice).getIndiceCanalByNome(atributos.at(0)) < 0){
                std::cout << "O canal '"<< atributos.at(0) << "' não existe nesse servidor" << std::endl;
            } else{
                this->nomeCanalAtual = atributos.at(0);
                std::cout << "Você entrou no canal '"<< atributos.at(0) << "'" << std::endl;
            }
        }
    }
}

/**
* @brief Função que faz as verificações necessárias e sai de um canal
*/
void sistema::sairCanalEmServidor(){
    if (this->nomeServidorAtual == ""){
        std::cout << "Você precisa está vusualizando um servidor para poder usar esse comando" << std::endl;
    } else{
        if(this->nomeCanalAtual == ""){
            std::cout << "Você não está visualizando nenhum canal no momento" << std::endl;
        }
        else{
            std::cout << "Saindo do canal..." << std::endl;
        }
    }
}

/**
* @brief Função que faz as verificações necessárias e envia uma mensagem
* @param mensg String que contem o conteúdo da mensagem
* @param dataHora String que contem a data e a hora de envio da mensagem
*/
void sistema::envioDeMensagem(std::string mensg, std::string dataHora){
    if (this->nomeServidorAtual == ""){
        std::cout << "Você precisa está vusualizando um servidor para poder usar esse comando" << std::endl;
    } else{
        if(this->nomeCanalAtual == ""){
            std::cout << "Você precisa está vusualizando um canal para poder usar esse comando" << std::endl;
        }
        else{
            int indice = getIndiceServidorByName(this->nomeServidorAtual);
            this->todosServidores.at(indice).envarMensagem(this->usuarioAtualId, mensg, dataHora, this->nomeCanalAtual);
        }
    }
}

/**
* @brief Função que faz as verificações necessárias, obtém as mensagens presentes no canal, e imprime-as
*/
void sistema::listarMensagens(){
    if (this->nomeServidorAtual == ""){
        std::cout << "Você precisa está vusualizando um servidor para poder usar esse comando" << std::endl;
    } else{
        if(this->nomeCanalAtual == ""){
            std::cout << "Você precisa está vusualizando um canal para poder usar esse comando" << std::endl;
        }
        else{
            canal* c = this->todosServidores.at(getIndiceServidorByName(this->nomeServidorAtual)).getCanalByName(this->nomeCanalAtual);
            if(c->getMensagens().size() == 0){
                std::cout << "Não há mensagens nesse canal" << std::endl;
            }
            else{
                std::vector<mensagem> m = c->getMensagens();
                for(int i = 0; i < m.size(); i++){
                    std::cout << getUsuarioByPos(m.at(i).getIdUserMensagem() - 1).getNome() << " " << m.at(i).getDataMensagem() << ": " << m.at(i).getConteudoMensagem() << std::endl;
                }
            }
        }
    }
}