# ERROR CRITICO 1: flags mal escritos. es -Wpedantic y es -Werror.

# ERROR CRÍTICO 2: Te he comentado que lo que diferencía una receta de su target es la IDENTACIÓN.
# Por alguna razón tu editor NO ESTÁ GUARDANDO EL CARACTER TABULADOR COMO TAL. Hay que revisarlo.

# ERROR CRÍTICO 3: Yo hice una nueva estructura de archivos y carpetas que no estás tomando
# en cuenta. En ese sentido tampoco estás creando la carpeta bin/ donde debería ir tu ejecutable.

# SUGERENCIA 1: solo romper lineas cuando sea necesario

# SUGERENCIA 2: usar nombres de ejecutables mas representativos

# SUGERENCIA 3: Usaremos el flag -g para que agrege lo necesario para depuración
win: src/main.cpp
	mkdir -p bin
	g++ src/main.cpp -g -Wall -Wextra -Wpedantic -Werror -o bin/login.exe

# La versión para Linux usará ncurses
nix: src/main.cpp
	mkdir -p bin
	g++ src/main.cpp -g -lncurses -Wall -Wextra -Wpedantic -Werror -o bin/login

.PHONY: clean
clean:
	rm bin/*
