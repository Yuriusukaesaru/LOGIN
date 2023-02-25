/*PRIMER PARTE DE PROGRAMA MAMALON*/

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <cstring>
#include<iostream>


const int LONGITUD{20},LIMITE_USUARIOS{50};


using std::cin;
using std::cout;

void ingresar(char *usuario , char *clave);
void registrar(struct Usuario *registrar);
int buscar(char *buscar_usuario, char *buscar_contraseña, struct Usuario *buscar, int *i);

struct Usuario
{
    char User[LONGITUD];
    char Password[LONGITUD];
};

int usuarios_registrados{0};

int main(void){
        const char USER_ADMIN[] ="SOYADMIN", PASSWORD_ADMIN[]="CONTRASENIA";//CONSTRASEÑA ADMIN
        struct Usuario Usuarios[LIMITE_USUARIOS];
        int Opcion,Desicion,i{0};
        char usuario[LONGITUD],clave[LONGITUD],decision_regresar;
        bool continuar {true},exito{false};
        
        do{
            
        cout<<"\n\n\t\t\t\t\t              |ESTAS SON LAS OPCIONES|"
            <<"\n\n\t\t\t\t\t               1.- INGRESAR"
            <<"\n\n\t\t\t\t\t               2.- REGISTRARSE"
            <<"\n\n\t\t\t\t\t               3.- SALIR"
            <<"\n\n\t\t\t\t\t               * DIGITE LA OPCION: ";
            cin>>Opcion;


            //cin.ignore();
            i = 0;
            exito = 0;

            switch (Opcion)
            {
            case 1:
                


                cin.ignore();

                if (usuarios_registrados > 0)
                {
                        
                        ingresar(usuario,clave);
                        
                        
                }else
                {
                    cout<<"\n\n\t\t\t\t\tNO HAY USUARIOS EN LA BASE DE DATOS";
                }

                while(i  <=  usuarios_registrados and exito == false)
                {
                    
                    exito = buscar(usuario,clave, Usuarios + i, &i);                    
                        ++i;
                }


                cout<<"\n\n\t\t\t\t\tQUIERES VOLVER AL MENU?: [S]= SI [N]=NO: ";
                cin>>decision_regresar;

                break;

            case 2:
                cin.ignore();//AQUI DEBES DE INICAR SESION CON LA MISMA CONTRASEÑA PREDERMINADA 
                cout<<"\n\n\t\t\t\t\tDEBES INICIAR SESION COMO ADMINISTRADOR PARA TENER ESTE PRIVILEGIO";
                ingresar(usuario,clave);
                if (strcmp(usuario,USER_ADMIN)==0 and strcmp(clave,PASSWORD_ADMIN )== 0 and usuarios_registrados <LIMITE_USUARIOS)
                {

                registrar(Usuarios + usuarios_registrados );
                
                cin.ignore();
                }else{
                 cout<<"\n\n\t\t\t\t\tNO SE PUEDE INGRESAR"; 
                }

                cout<<"\n\n\t\t\t\t\tQUIERES VOLVER AL MENU?: [S]= SI [N]=NO: ";
                cin>>decision_regresar;
                 
                break;
            case 3:
                cout<<"\n\n\t\t\t\t\tHASTA LUEGO :)";
                continuar = false;
                break;
            default:
                cout<<"\n\n\t\t\t\t\tOPCION NO VALIDA d:";
                cin.ignore();
                decision_regresar = 's';
                break;
            }
            }while((decision_regresar =='S' or decision_regresar == 's')  and  continuar == true ) ;
    
}



void ingresar(char *usuario , char *clave)
{

        char leer;
        int intento{3},ingreso{0},cont{0};
       
        
            
            printf("\n\n\t\t\t\t\t+-----------------------+----------------------+");
            printf("\n\n\t\t\t\t\t               +|INICIO DE SESION|+ ");
            printf("\n\n\t\t\t\t\t+-----------------------+----------------------+");
            printf("\n\n\t\t\t\t\t*BIENVENIDO POR FAVOR INGRESE SU USUARIO: ");
            fgets(usuario,LONGITUD,stdin);
            usuario[strlen(usuario) - 1] = '\0';
            fflush(stdin);
            printf("\n\n\t\t\t\t\t*POR FAVOR TECLEE SU CONTRA: ");
            while(leer=getch())
            {
                
                if(leer==13){
                    clave[cont]='\0';
                  break;
                }else if(leer==8 && cont>0){
                    
                        cont--;
                        printf("\b \b");   
                    
                }else if(cont<LONGITUD){
                    printf("*");
                    clave[cont]=leer;
                    cont++;
                }

            }     
           

}

int buscar(char *buscar_usuario, char *buscar_contraseña, struct Usuario *buscar, int *i){

        
        bool busqueda_exitosa {false};
        if(strcmp(buscar_usuario,buscar->User) == 0 ) 
        {
            if (strcmp(buscar_contraseña,buscar->Password) == 0){

                cout<<"\n\n\t\t\t\t\tBIENVENIDO USUARIO: "<<buscar->User <<"\t\tNUMERO DE USUARIO: "<<*i + 1;
                    
                busqueda_exitosa = true;
            }else{
                cout<<"\n\n\t\t\t\t\tCONTRASEÑA INCORRECTA :(";
            }
        }  

        return busqueda_exitosa;

}


    
void registrar(struct Usuario *registrar ){
        
        //aritmetica de punteros
        cout << "\n\n\t\t\t\t\tREGISTRANDO AL USUARIO NUMERO: "<<usuarios_registrados+ 1
             << "\n\n\t\t\t\t\tPOR FAVOR INGRESE SU NOMBRE DE USUARIO: ";
       cin.getline( registrar->User , LONGITUD);
       cin.ignore();
       cout << "\n\n\t\t\t\t\tINGRESE SU CONTRASEÑA: ";
       cin.getline( registrar -> Password  , LONGITUD);
       cin.ignore();
      
        
       ++usuarios_registrados;

}