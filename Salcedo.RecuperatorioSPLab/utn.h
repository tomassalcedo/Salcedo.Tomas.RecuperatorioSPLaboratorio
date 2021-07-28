#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

/** \brief Solicita un caracter al usuario y valida que el ingreso sea correcto
 *
 * \param caracter char* puntero donde se guardara el caracter
 * \param mensaje char* mensaje para pedir el caracter
 * \param mensajeError char* mensaje de error a mostrar
 * \param reintentos int cantidad de intentos que tiene el usuario para el ingreso del caracter
 * \return retorna 1 si el ingreso fue corrector, retorna 0 si no lo fue o en caso de ERROR
 *
 */
int getChar(char* caracter, char* mensaje, char* mensajeError, int reintentos);
