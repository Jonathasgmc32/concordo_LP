# Concordo

## Aluno
>Jonathas Gabriel Martins Costa

## Instalação e Execução
> **Para compilar o projeto é necessário ter o CMAKE instalado em sua máquina.**

* No prompt de comando, dê ```git clone https://github.com/Jonathasgmc32/concordo_LP.git``` para clonar o repositório em sua maquina, ou baixe e descompacte o arquivo zip disponibilizado;
* Vá até a pasta "build" ```(cd concordo_LP/build)```, depois use o comando ```cmake ..``` e depois use o comando ```make``` para compilar, caso dê erro de cache, apague as pastas e arquivos referentes ao cmake da pasta build e tente novamente;
* Use ```./program``` para Executar o programa. Caso deseja usar um arquivo teste, contendo entradas de um
exemplo de excecução, use ```./program < entradasTeste.txt```

## Entradas

As entradas do programa são comandos, seguidos (ou não) por parâmetros. Aqui está a lista de comandos disponíveis:
```bash

#criar usuário (só pode ser executado sem está logado)
create-user <email> <senhaSemEspaço> <nome podendo ter espaço>
