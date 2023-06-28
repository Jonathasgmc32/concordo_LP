# Concordo

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

###Comandos que podem ser feitos a qualquer momento:
```bash
#Encerra o concord
quit
```

###Comandos que podem ser feitos com o status deslogado:
```bash
#Criar usuário
create-user <email> <senhaSemEspaço> <nome podendo ter espaço>

#Fazer login
login <email> <senhaSemEspaço>
```

###Comandos que podem ser feitos com o status logado:

####Em qualquer tela:
```bash

#Deslogar de uma conta
disconect

#Criar servidor
create-server <nomeDoServidorSemEspaço>

#Mudar descrição do servidor
set-server-desc <nomeDoServidorSemEspaço> "<descriçao podendo ter espaço>"

#Mudar ou definir código do servidor
set-server-invite-code <nomeDoServidorSemEspaço> <codigo>

#Remover um servidor
remove-server <nomeDoServidorSemEspaço>

#Listar Servidores cadastrados no sistema
list-servers

#Mostrar informações gerais de um servidor
info-server <nomeDoServidorSemEspaço>

#Entrar em um servidor (sem requisito de código)
enter-server <nomeDoServidorSemEspaço>

#Entrar em um servidor (com requisito de código)
enter-server <nomeDoServidorSemEspaço> <codigo>
```

####Visualizando algum servidor

```bash
#Sair do servidor (apenas visualização)
leave-server

#Listar participantes do servidor
list-participants
```
>Observação 1: Os comandos que mudam algum dado de um servidor só podem ser feitos pelo dono do servidor
>Observação 2: Comandos que forem feitos em locais inválidos (ex: leave-server mesmo não estando em um servidor) retornarão uma mensagem de erro ou um feedback