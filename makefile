# Error critico 1: flags mal escritos. es -Wpedantic y es -Werror.
#
# Error crítico 2: Te he comentado que lo que diferencía una receta de su target es la IDENTACIÓN.
# Por alguna razón tu editor NO ESTÁ GUARDANDO EL CARACTER TABULADOR COMO TAL. Hay que revisarlo.
#
# Sugerencia: solo romper lineas cuando sea necesario
# 
# Sugerencia 2: usar nombres de ejecutables mas representativos
#
win: main.cpp
	g++ main.cpp -Wall -Wextra -Wpedantic -wError -o login.exe

nix: main.cpp
	g++ main.cpp -Wall -Wextra -Wpedantic -Werror -o login
