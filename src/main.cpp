/*PRIMER PARTE DE PROGRAMA MAMALON*/

#include <iostream>
#include <string>
#include <cstring>
// #include <ncurses.h>
#include <conio.h>

enum Opcion : const std::int16_t { INGRESAR = 1, REGISTRAR_USUARIO, SALIR };
enum Tecla : char { BACKSPACE = 8, ENTER = 13 };

struct Usuario {
	std::string nombre;
	std::string password;
};

const std::int32_t &MAX_STRING{ 20 };
const std::int32_t &LIMITE_USUARIOS{ 50 };

auto leer_datos_usuario() -> struct Usuario;
auto buscar_usuario( const struct Usuario _UsuarioLeido, const struct Usuario *_BaseDatos,
		const std::int32_t &_Usuarios ) -> bool;
auto registrar_usuario( struct Usuario *_BaseDatos, std::int32_t *_Usuarios ) -> void;

using std::cout;
using std::cin;

auto main() -> std::int32_t/*{{{*/
{
	struct Usuario usuarios_database[ LIMITE_USUARIOS ];
	const struct Usuario &admin { { "SOYADMIN" }, { "CONTRASENIA" } };
	struct Usuario usuario_leido{ { "" }, { "" } };
	std::int32_t n_registrados{ 0 };

	std::int16_t opcion;

	[[ maybe_unused ]] bool se_encontro_usuario{ false };
	char decision_continuar{ '\0' };
	bool continuar{ true };

	do {
		cout	<< "\n\n\t\t\t              |ESTAS SON LAS OPCIONES|"
				<< "\n\n\t\t\t               1.- INGRESAR"
				<< "\n\n\t\t\t               2.- REGISTRARSE"
				<< "\n\n\t\t\t               3.- SALIR"
				<< "\n\n\t\t\t               * DIGITE LA OPCION: "
				<< std::endl;
		cin >> opcion;
		cin.ignore(); // Es correcto el cin.ignore() en este punto

		switch ( opcion ) {

			case Opcion::INGRESAR:
				if ( n_registrados > 0 ) {
					usuario_leido = leer_datos_usuario();
					se_encontro_usuario =
						buscar_usuario( usuario_leido, usuarios_database, n_registrados );
				}
				else
					cout << "\n\n\t\t\tNO HAY USUARIOS EN LA BASE DE DATOS";

				cout << "\n\n\t\t\tQUIERES VOLVER AL MENU?: [S]= SI [N]=NO: ";
				cin >> decision_continuar;
				cin.ignore();
				break;

			case Opcion::REGISTRAR_USUARIO:
				cout << "\n\n\t\t\tDEBES INICIAR SESION COMO ADMINISTRADOR PARA TENER "
						"ESTE PRIVILEGIO" << std::endl;
				usuario_leido = leer_datos_usuario();

				if (	usuario_leido.nombre == admin.nombre and
						usuario_leido.password == admin.password and
						n_registrados < LIMITE_USUARIOS ) {

					registrar_usuario( usuarios_database, &n_registrados );
				}
				else
					cout<<"\n\n\t\t\tNO SE PUEDE INGRESAR"; 

				cout<<"\n\n\t\t\t\t\tQUIERES VOLVER AL MENU?: [S]= SI [N]=NO: ";
				cin >> decision_continuar;
				cin.ignore();
				break;

			case 3:
				cout << "\n\n\t\t\t\t\tHASTA LUEGO :)";
				continuar = false;
				break;

			default:
				cout << "\n\n\t\t\t\t\tOPCION NO VALIDA d:";
				cin.ignore();
				break;
		}
	} while( ( decision_continuar == 'S' or decision_continuar == 's')  and  continuar == true ) ;
}/*}}}*/

auto leer_datos_usuario() -> struct Usuario/*{{{*/
{
	struct Usuario usuario { { "" }, { "" } };
	char usuario_nombre_C_style[ MAX_STRING ]{ "" };

	std::cout << "\n\n\t\t\t+-----------------------+----------------------+";
	std::cout << "\n\n\t\t\t               +|INICIO DE SESION|+ ";
	std::cout << "\n\n\t\t\t+-----------------------+----------------------+";

	std::cout << "\n\n\t\t\t*BIENVENIDO POR FAVOR INGRESE SU USUARIO: ";
	fgets( usuario_nombre_C_style, MAX_STRING, stdin );
	usuario_nombre_C_style[ strlen( usuario_nombre_C_style ) - 1 ] = '\0';
	usuario.nombre = usuario_nombre_C_style;

	// Vamos a hacer un borrado de buffer porque hay un error y ya no está imprimiendo esto
	std::cout << "\n\n\t\t\t*POR FAVOR TECLEE SU CONTRA: " << std::flush;
	char caracter_leido;
	std::string::size_type n_caracteres{ 0 };
	bool continuar{ true };

	while ( continuar ) {
		caracter_leido = getch();
		if ( caracter_leido == Tecla::ENTER ) {
			usuario.password[ n_caracteres ] = '\0';
			continuar = false;
		}
		else if ( caracter_leido == Tecla::BACKSPACE && n_caracteres > 0 ) {
			--n_caracteres;
			std::cout << "\b \b";
		} else if ( n_caracteres < MAX_STRING ) {
			std::cout << '*';
			usuario.password[ n_caracteres ] = caracter_leido;
			++n_caracteres;
		}
	}

	return usuario;
}/*}}}*/

auto buscar_usuario( const struct Usuario _UsuarioLeido, const struct Usuario *_BaseDatos,/*{{{*/
		const std::int32_t &_UsuariosRegistrados ) -> bool
{
	int32_t i{ 0 };

	// Aquí vamos a implementar el algoritmo de búsqueda, no afuera
	while ( _UsuarioLeido.nombre != ( _BaseDatos + i )->nombre and
			_UsuarioLeido.password != ( _BaseDatos + i )->password and
			i < _UsuariosRegistrados )
		++i;

	/* Aquí metemos dos return al estilo Sertch. En estos casos es bien visto "según yo"
	 * porque hay cierto paralelismo (hasta estético) entre ambos returns, no se ve "truncado" */
	if ( i < _UsuariosRegistrados ) // Salió antes -> SÍ LO ENCONTRÓ
		return true;
	else
		return false;
}/*}}}*/

auto registrar_usuario( struct Usuario *_BaseDatos, std::int32_t *_Usuarios ) -> void/*{{{*/
{
	cout	<< "\n\n\t\t\tREGISTRANDO AL USUARIO NUMERO: " << *_Usuarios + 1
			<< "\n\n\t\t\tPOR FAVOR INGRESE SU NOMBRE DE USUARIO: ";
	cin >> ( _BaseDatos + *_Usuarios )->nombre;
	cin.ignore();

	cout << "\n\n\t\t\tINGRESE SU CONTRASEÑA: ";
	cin >> ( _BaseDatos + *_Usuarios )->password;
	cin.ignore();
	
	++( *_Usuarios );
}/*}}}*//*}}}*/
