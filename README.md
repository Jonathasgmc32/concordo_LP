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

list-channels
#Lista os canais do servidor

create-channel <nomeDoCanalSemEspaço> <tipoCanal>
#Cria um canal no servidor. O tipoCanal só pode ser "texto" ou "voz"

enter-channel <nomeDoCanalSemEspaço>
#Entra em um canal do servidor
```

<h4> Visualizando algum canal </h4>

```bash
leave-channel
#Sai do canal

send-message <mensagem que pode ter espaço>
#Envia uma mensagem ao canal visualizado

list-messages
#Lista todas as mensagens do canal vizualizado
```
>Observação 1: Os comandos que mudam algum dado de um servidor só podem ser feitos pelo dono do servidor

>Observação 2: Comandos que forem feitos em locais inválidos (ex: leave-server mesmo não estando em um servidor) ou em um estado de login inválido (ex: desconect estando deslogado) retornarão uma mensagem de erro ou um feedback

>Observação 3: O comando send-message não dá nenhum retorno se bem sucedido. Você pode ver as mensagens mais
recentes usando o list-messages

## Roteiro de exemplo

>Esse roteiro irá usar duas contas, e as ações ocorrem cronologicamente na
ordem que foram citadas nesse roteiro, na mesma exceução, para que fique melhor de exempliciar

<h3> Criar dois usuários e logar com um deles</h3>

```bash
create-user usuario1@gmail.com senhasegura Usuario1
create-user usuario2@gmail.com senhamaissegura Usuario bacana
login usuario1@gmail.com senhasegura
```

<h3> Criar e configurar um servidor (logando como Usuario1), e desconectar</h3>

```bash
create-server servidor-bacana
create-server meu-segundo-servidor
set-server-desc servidor-bacana "um servidor para pessoas legais"
set-server-desc meu-segundo-servidor "servidor para pessoas mais próximas"
set-server-invite-code meu-segundo-servidor codigo123
enter-server servidor-bacana
create-channel geral texto
create-channel estudos texto
create-channel calls voz
list-channels
enter-server meu-segundo-servidor
create-channel geral texto
create-channel calls voz
list-channels
disconect
```
<h3> Listar servidores, buscar informações, entrar em servidores com e sem código, e mandar mensagens (logando como Usuario Bacana) </h3>

```bash
login usuario2@gmail.com senhamaissegura
list-servers
info-server servidor-bacana
info-server meu-segundo-servidor
enter-server servidor-bacana
list-channels
enter-channel geral
send-message Bom dia tudo bem?
list-messages
enter-server meu-segundo-servidor
enter-server meu-segundo-servidor codigoaleatorio
enter-server meu-segundo-servidor codigo123
list-participants
leave-server
disconect
```
## Adições, correções e Melhorias

<h3>v3.0</h3>

* Corrigido um problema grave em que adicionar multiplos servidores causava erro
* Corrigido problema ao sair de canal
* Adicionados carregamento e leitura de arquivos
* Hashing para senha

<h3>v2.0</h3>

* Adicionado gerenciamento de canais (criar, entrar e sair de canal);
* Adicionado envio e listagem de mensagens em um canal;
* Corrigida a variavel "usuarioAtualId" está armazenando o indice do usuário logado em vez do seu id
* Deletar um servidor não tirará mais a visualização do servidor que você está (a menos que seja o próprio servidor a ser deletado)
* Corrigido problema em que apertar enter, sem nenhum comando escrito, replicava a última entrada inserida
* Corrigido problemas na documentação de alguns .h
* Retiradas algumas funções redundantes em sistema.h/sistema.cpp

## Problemas e dificudades

Ler a entrada foi um trabalho um pouco complicado, tanto que a maneira que fiz não pareceu a melhor alternativa para a leitura.

O script de teste não contempla entradas extremamente específicas, como caracteres diferentes do habitual alfabeto, ou todas as combinações possiveis de comandos, pricipalmente em relação ao verificador de está logado ou não/quantidade de parâmetros (mas sim, todas possuem esses verificadores).

Para a classe sistema, foi necessário adicionar um novo atributo: logado, que vê se o usuário está logado ou não. Isso foi necessário para a verificação de comandos ficar mais curta.

Não colocar quit ao final de um arquivo de entrada faz um loop infinito do ultimo comando do arquivo. Isso pode ser problemático caso o último comando seja para enviar mensagem. 

Tive problemas na classe de canais, principalmente na função de add, pois o meu destrutor estava destruindo
todos os canais ao fim de cada execução de adicionar. Mas me alertaram o que poderia ser o erro e a correção
foi rápida

A classe mensagem também deu um bug esquisito, caso o nome da variavel que passei na função fosse a mesma que é
o atributo da classe, no caso só ocorreu com a int enviadaPor (fazer "this->enviadaPor = enviadaPor" dava erros, mesmo que as demais não dessem)

As funções de carregar e salvar PRECISAM que os arquivos estejam formatados da maneira que foi proposta. Qualquer desvio dessa maneira acarretará em erros. A manipulação dos ids dos usuários (trocar a ordem, ou repetir ids) também gerará erros, uma vez que o sistema quem gerencia os ids automaticamente, bem como a mainipulação de servidores.txt pode causar interações inesperadas (ter dois canais ou servidores com o mesmo nome)