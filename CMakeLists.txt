cmake_minimum_required(VERSION 3.22.1)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( program
                src/main.cpp
                src/servidor.cpp 
                src/sistema.cpp
                src/usuario.cpp
                src/mensagem.cpp
                src/canal.cpp
                src/canalTexto.cpp
                src/canalVoz.cpp
                )