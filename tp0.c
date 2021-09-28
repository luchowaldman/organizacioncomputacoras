#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFERSIZE 80
#define SIZE_PALABRA 80
#define SIZE_TOTALPALABRAS 5000000



void boublesort (char ** words, int arraysize)
{
	
    int i, j;
    for (i = 0; i < arraysize; i++) 
		{
            
            for (j = i + 1; j < arraysize;  j++) 
			{
				
            
				if (strcmp(words[i] , words[j]) > 0)
				{
					char* temp = words[i];
					words[i] = words[j];
					words[j] = temp;
				}	
            }
        }
    
}



void shellsort(char ** arr, int num)
{
    int i, j, k;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
            	
                if (strcmp(arr[k+i] , arr[k]) > 0)
                    break;
                else
                {
                    char* temp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = temp;
                }
            }
        }
    }
}
             
                    
int main(int argc, char *argv[]) 
{

	char* argu;
	int finpalabra;
	// QUEDA POR DEFAUL EL BOUBBLE SORT COMO MODO DE ORDENAMIENTO
	char modo_ordenamiento = 'N';
	
	// Si tiene un argumento, lo guarda en argu. por default deja '-m'
	if (argc < 2)
	{
		argu = "-m";
	}
	else
	{
		argu = argv[1];
	}
			
	// Muestra la ayuda		
	if ((strcmp(argu, "-h") == 0) || (strcmp(argu, "--help") == 0))
	{
			
		printf("tp0 [OPTIONS][file...]\n");
		printf("-h, --help display this help and exit\n");
		printf("-V, --version display version information and exit\n");
		printf("-m, --bubble use the bubblesort algorithm.\n");
		printf("-s, --sel use the shellsort algorithm.\n");
		return 0;
	}
	
	// Muestra la version		
	if ((strcmp(argu, "-V") == 0) || (strcmp(argu, "--version") == 0))
	{
		printf("Version 1.0\n");
		return 0;
	}
			
	// Metodo de ordenamiento Shel		
	if ((strcmp(argu, "-s") == 0) || (strcmp(argu, "--sel") == 0))
	{	
		modo_ordenamiento = 'S';
	}
			
			
	// Metodo de ordenamiento Boubble
	if ((strcmp(argu, "-m") == 0) || (strcmp(argu, "--bubble") == 0))
	{	
		modo_ordenamiento = 'B';
	}
		
	
    char buffer[BUFFERSIZE];
    char palabra[SIZE_PALABRA];
    char ** words;
    words = malloc(sizeof(void) * SIZE_TOTALPALABRAS);
    int cant_palabras = 0;
    int cant_letras = 0;
    
    
    // LEE LAS PALABRAS DESDE EL ARCHIVO
    FILE* fichero;
	int file_prm = 2;
	for (file_prm = 2; file_prm < argc; file_prm++)
	{
	    if ((fichero = fopen(argv[file_prm], "rt"))  == NULL)
	        return;
	    
		    char letra;
			while ((letra = fgetc(fichero)) != EOF)
			{
				
						finpalabra = 0;
		    			if (letra == ' ')
		    				finpalabra = 1;
		    			
		    			if (letra == '\n') 
		    				finpalabra = 1;
		    			
		    			
		    			
		    			if (finpalabra == 1)
		    			{
		    				if (cant_letras != 0)
							{


								palabra[cant_letras] = '\0';
								cant_letras++;
			    				words[cant_palabras] = malloc(sizeof(char) * cant_letras);
			    				strncpy(words[cant_palabras], palabra, cant_letras);
								cant_letras = 0;
			    				cant_palabras++;
			    				
							}
						}
						else
						{
							palabra[cant_letras] = letra;
							cant_letras++;
						}
			}
			
		
	    fclose(fichero);
	    
	    
	}
    
	// Ordena Segun el Tipo
    if (modo_ordenamiento == 'B')
		boublesort(words, cant_palabras);
	
    if (modo_ordenamiento == 'S')
		shellsort(words, cant_palabras);
	
	// Lista por pantalla las palabras ordenadas y libera memoria
    int i;
    for (i = 0; i < cant_palabras; i++)
    {
    	printf("%s ", words[i]);
	}
    for (i = 0; i < cant_palabras; i++)
 		free(words[i]);

    	
	
	printf("\n");
	free(words);
	return 0;
}


