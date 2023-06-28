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

>Observação 2: Comandos que forem feitos em locais inválidos (ex: leave-server mesmo não estando em um servidor) ou em um estado de login inválido (ex: desconect estando deslogado) retornarão uma mensagem de erro ou um feedback

## Roteiro de exemplo

<h3> Criar dois usuários e logar com um deles</h3>

```bash
create-user usuario1@gmail.com senhasegura Usuario1
create-user usuario2@gmail.com senhamaissegura Usuario bacana
login usuario1@gmail.com senhasegura
```

<h3> Criar e configurar um servidor (estando logado na conta 1), e desconectar</h3>

```bash
create-server servidor-bacana
create-server meu-segundo-servidor
set-server-desc servidor-bacana "um servidor para pessoas legais"
set-server-desc meu-segundo-servidor "servidor para pessoas mais próximas"
set-server-invite-code meu-segundo-servidor codigo123
disconect
```
<h3> Listar servidores, buscar informações e entrar em servidores com e sem código (estando logado na conta 2) </h3>

```bash
list-servers
info-server servidor-bacana
info-server meu-segundo-servidor
enter-server servidor-bacana
enter-server meu-segundo-servidor
enter-server meu-segundo-servidor codigoaleatorio
enter-server meu-segundo-servidor codigo123
list-participants
leave-server
disconect
```

## Problemas e dificudades

A senha não está com hashing, então ao usar algum getSenha(), o valor é o mesmo que foi digitado. Isso é ruim quando for trabalhar com leitura de arquivo e tentarei aplicar isso nas proximas versões (pelo menos na parte 3 tentarei)

Ler a entrada foi um trabalho um pouco complicado, tanto que a maneira que fiz não pareceu a melhor alternativa para a leitura.

O script de teste não contempla entradas extremamente específicas, como caracteres diferentes do habitual alfabeto, ou que cada função possui um verificador de parâmetros máximo para que o teste não ficasse cansativo(mas sim, todas possuem esse verificador).

Para a classe sistema, foi necessário adicionar um novo atributo: logado, que vê se o usuário está logado ou não. Isso foi necessário para a verificação de comandos ficar mais curta.

Não colocar quit ao final de um arquivo de entrada faz um loop infinito do ultimo comando do arquivo. Isso pode ser problemático na parte 2 caso o último comando seja para enviar mensagem. 
