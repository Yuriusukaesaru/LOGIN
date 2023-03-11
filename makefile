# Error critico: flags mal escritos. es -Wpedantic y es -Werror
# Sugerencia: solo romper lineas cuando sea necesario
# Sugerencia 2: usar nombres d ejecutables mas representativos
win: main.cpp
    g++ main.cpp -Wall -Wextra -Wpedantic -wError -o loginexe

nix: main.cpp
    g++ main.cpp -Wall -Wextra -Wpedantic -Werror -o login
