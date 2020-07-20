#include  <stdio.h>
#include <string.h>

char *cifrar (char*);
int   verificar_credenciales (char*);

//argc: dword ptr [rbp -  0x8]
//argv: qword ptr [rbp - 0x10]

int main( int argc, char *argv[]) {
    
    int var_1 = 0;                  //dword ptr [rbp - 0x4]
   
    if (argc < 2)
    {
        printf( "Error: No se proveyeron argumentos.\n"
                "Modo de uso %s <password>\n" , argv[0] );
        return 0;
    }

    if (verificar_credenciales( cifrar( argv[1] ) ))
    {
        printf( " (\\(\\\n(=' :')\n(,(\")(\")\n" );
        printf( "Bienvenido, usuario.\n"
                "Se te garantiza acceso a todo!\n" );
    }
    else
        printf( "Acceso Denegado.\n" );
}

char *cifrar (char *cadena) { //cadena: qword ptr [rbp - 0x8]
    
    int    rot =                11; //dword ptr [rbp -  0xc]
    int    min =         (int) '0'; //dword ptr [rbp - 0x10]
    int    max =         (int) 'z'; //dword ptr [rbp - 0x14]
    int limite =     (max - min)+1; //dword ptr [rbp - 0x18]
    int      i =                 0; //dword ptr [rbp - 0x1c]
    
    while (*(cadena+i) != '\0')
    {
        *(cadena+i) = (char) (*(cadena+i) + rot) - min;
        *(cadena+i) = (char) (*(cadena+i) % limite) + min;

        i++;
    }

    return cadena;
}

int verificar_credenciales (char * cadena) {
    
    int var_1 = 0;
    char buffer[68];

    strcpy( buffer, cadena );
    if (strcmp( buffer, "nzYpuz_;9") == 0)
        var_1 = 1;

    return var_1;
}
