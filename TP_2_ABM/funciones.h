#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXCANT 20

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
* @brief inicializa array de usuarios
* @param lista el array se pasa como parametro.
* @param length longitud del array.
* @return 0 cuando la actualizacion se realice de forma correcta y -1 para errores.
*/
int  inicializarArray(EPersona lista[], int lenght);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int lenght);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
EPersona* buscarPorDni(EPersona lista[], int dni);

/**
* @brief Alta de personas
* @param lista el array se pasa como parametro.
* @param posicion posicion donde se insertara la nueva persona
* @param ePersona la estructura se pasa como parametro
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int altaPersonas(EPersona lista[], int lenght, int dni, int edad, char nombre[]);

/**
* @brief borra de forma lógica personas
* @param lista el array se pasa como parametro.
* @param length longitud del array
* @param dni el valor por el cual se buscara la persona a dar de baja
* @return 0 para cuando el alta se dio de forma exitosa -1 para cualquier error
*/
int bajaPersonas(EPersona lista[], int dni);

/**
* @brief lista los usuarios ordenados por nombre
* @param lista el array que se va a ordenar
* @param length longitud del array
*/
void listarOrdenado(EPersona lista[], int lenght);

/**
* @brief Grafica por grupo de edades
* @param lista el array que se va a ordenar
* @param length longitud del array
*/
void graficarEdades(EPersona lista[], int lenght);
/**
* @brief Solicita un número al usuario y lo valida
* @param input Se carga el numero ingresado
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error
* @param lowLimit Limite inferior a validar
* @param hiLimit Limite superior a validar
* @return Si obtuvo el numero [0] si no [-1]
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* @brief Solicita un número al usuario y lo valida
* @param input Se carga el numero ingresado
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error
* @param lowLimit Limite inferior a validar
* @param hiLimit Limite superior a validar
* @return Si obtuvo el numero [0] si no [-1]
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/**
* @brief Solicita un caracter al usuario y lo valida
* @param input Se carga el caracter ingresado
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error
* @param lowLimit Limite inferior a validar
* @param hiLimit Limite superior a validar
* @return Si obtuvo el caracter [0] si no [-1]
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

/**
* @brief Solicita una cadena de caracteres al usuario y la valida
* @param input Se carga el string ingresado
* @param message Es el mensaje a ser mostrado
* @param eMessage Es el mensaje a ser mostrado en caso de error
* @param lowLimit Longitud mínima de la cadena
* @param hiLimit Longitud máxima de la cadena
* @return Si obtuvo la cadena [0] si no [-1]
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
#endif // FUNCIONES_H_INCLUDED
