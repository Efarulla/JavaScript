#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc.h>

using namespace std;

#define MAX_SIZE 100
#define MAX_BUFFER 250

char * getenv(const char * env);

/*******************************************************************************
Nota: Hay que hacer la definici�n de funciones antes de implementarlas	
*******************************************************************************/
bool Obtiene_Valor( const char * str, char strValue[MAX_SIZE], char * strName);

/*******************************************************************************
Nota: ahora se implementa la funci�n
*******************************************************************************/
bool Obtiene_Valor(const char * str, char strValue[MAX_SIZE], char * strName )
{
    	char * str1 = strstr(str, strName );
    	if (str1 == NULL)
    	{
        		strcpy(strValue, " ");
        		strValue[1] = '\0';
        		return false;
    	}
    	while (strchr( (const char *)str1, '+' ))
        strchr( (const char *)str1, '+' )[0] = ' ';  
	    int n1 = strcspn(str1, "=") + 1;
    	int n2 = strcspn(str1, "&") + 1;
    	if (n2 - n1 - 1 > MAX_SIZE - 1) 
    	{
        		strncpy( strValue, str1 + n1, MAX_SIZE - 1);
        		strValue[MAX_SIZE - 1] = '\0';
    	}
    	else 
    	{
		        strncpy( strValue, str1 + n1, n2 - n1 - 1 );
		        strValue[n2 - n1 - 1] = '\0';
    	}
    	return true;
}




int main(int argc, char *argv[])
{
/*******************************************************************************
       Obtiene la variable de entorno: QUERY_STRING.                                                                                                                                                                	
*******************************************************************************/    
    
   	   const char *strq = getenv("QUERY_STRING");
   	   
//*******************************************************************************
   	   
    	if (strq == NULL) return 0; // Por si el m�todo Post fue usado antes del Get

		char Nombre[MAX_SIZE];
    	char Correo[MAX_SIZE];

	    bool Buleano;

    	Buleano = Obtiene_Valor(strq, Nombre, "Name"); //Name es un campo de la p�gina Web
    	Buleano = Obtiene_Valor(strq, Correo, "Email");//Email es un campo de la p�gina Web
    	
    	// Ahora vamos a crear la p�gina Web "Din�micamente".
    	
    	printf("Content-Type: text/html\r\n\r\n"); 
    	printf("<html><body>");
    	printf("<H3>Hola que tal: %s,<BR><H3>", Nombre);
 		printf("<H3>pronte te escribiremos a: %s<BR><H3>", Correo);
    	printf("</body></html>");
    
    //system("PAUSE");
    //return EXIT_SUCCESS;
}
