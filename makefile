win: main.cpp
    g++ main.cpp \
        -Wall -Wextra -Wpendantic \
        -wError -o Programa.exe

nix: main.cpp
    g++ main.cpp \
        -Wall -Wextra -Wpendantic \
        -wError -o Programa