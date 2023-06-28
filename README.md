# Concordo - Um clone do Discord

## Aluno
>Jonathas Gabriel Martins Costa

## Instalação e Execução
> **Para compilar o projeto é necessário ter o CMAKE instalado em sua máquina.**

* No prompt de comando, dê ```git clone https://github.com/Jonathasgmc32/concordo_LP.git``` para clonar o repositório em sua maquina, ou baixe e descompacte o arquivo zip disponibilizado;
* Vá até a pasta "build" ```(cd concordo_LP/build)```, depois use o comando ```cmake ..``` e depois use o comando ```make``` para compilar. Caso dê erro de cache, apague as pastas e arquivos referentes ao cmake da pasta build e tente novamente **(não apague entradasTeste.txt)**;
* Use ```./program``` para Executar o programa. Caso deseja usar um arquivo teste, contendo entradas de um
exemplo de excecução, use ```./program < entradasTeste.txt```

## Entradas

As entradas do programa são comandos, seguidos (ou não) por parâmetros. Aqui está a lista de comandos disponíveis:

<h3> Comandos que podem ser feitos a qualquer momento: </h3>

```bash
quit
#Encerra o concord
```

<h3> Comandos que podem ser feitos com o status deslogado: </h3>

```bash
create-user <email> <senhaSemEspaço> <nome podendo ter espaço>
#Cria um novo usuário

login <email> <senhaSemEspaço>
#Faz login
```

<h3> Comandos que podem ser feitos com o status logado: </h3>

<h4> Em qualquer tela </h4>

```bash
disconect
#Desloga de uma conta

create-server <nomeDoServidorSemEspaço>
#Cria um servidor

set-server-desc <nomeDoServidorSemEspaço> "<descriçao podendo ter espaço>"
#Muda a descrição do servidor

set-server-invite-code <nomeDoServidorSemEspaço> <codigo>
#Muda ou define o código do servidor

remove-server <nomeDoServidorSemEspaço>
#Remove um servidor

list-servers
#Lista os servidores cadastrados no sistema

info-server <nomeDoServidorSemEspaço>
#Mostra as informações gerais de um servidor

enter-server <nomeDoServidorSemEspaço>
#Entra em um servidor (sem requisito de código)

enter-server <nomeDoServidorSemEspaço> <codigo>
#Entra em um servidor (com requisito de código)
```

<h4> Visualizando algum servidor </h4>

```bash
leave-server
#Sai do servidor (apenas visualização)

list-participants
#Lista os participantes do servidor
```
>Observação 1: Os comandos que mudam algum dado de um servidor só podem ser feitos pelo dono do servidor
<br>

>Observação 2: Comandos que forem feitos em locais inválidos (ex: leave-server mesmo não estando em um servidor) retornarão uma mensagem de erro ou um feedback