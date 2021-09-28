#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFERSIZE 80
#define SIZE_PALABRA 80
#define SIZE_TOTALPALABRAS 5000000


void boublesort (char ** words, int arraysize)
{
	
	int h, i, j;
	
	char* word;
	char* word2;
  
    for (i = 0; i < arraysize - 1; i++) 
		{
            word = words[i];
            char palabraVecotr[strlen(word) + 1];
            strcpy(palabraVecotr, word);
            
            
            for (j = i + 1; j < arraysize;  j++) 
			{
            	word2 = words[j];
				char palabraVecotr2[strlen(word2) + 1];
            	strcpy(palabraVecotr2, word2);
            
				if (strcmp(palabraVecotr , palabraVecotr2) > 0)
				{
					char* temp = words[i];
					words[i] = words[j];
					words[j] = temp;
				}	
            }
            words[j] = word;
        }
    
}



void shellsort (char ** words, int arraysize)
{
	int h, i, j;
	
	char* word;
	char* word2;
    for (h = arraysize; h /= 2;) 
	{
        for (i = h; i < arraysize; i++) 
		{
            word = words[i];
            
            char palabraVecotr[strlen(word) + 1];
            strcpy(palabraVecotr, word);
            
            
            for (j = i; j >= h; j -= h) 
			{
            	word2 = words[j - h];
            
				char palabraVecotr2[strlen(word2) + 1];
            	strcpy(palabraVecotr2, word2);
            
				if (strcmp(palabraVecotr , palabraVecotr2) > 0)
					break;
				
				
                words[j] = words[j - h];
            }
            words[j] = word;
        }
    }
}

                    
                    
int main(int argc, char *argv[]) 
{

	char* argu;
	
	// QUEDA POR DEFAUL EL BOUBBLE SORT COMO MODO DE ORDENAMIENTO
	char modo_ordenamiento = 'B';
	
	// Si tiene un argumento, lo guarda en argu. por default deja '-m'
	if (argc < 2)
	{
		argu = "-m";
	}
	else
	{
		argu = argv[1];
	}
			
			
	if ((strcmp(argu, "-h") == 0) || (strcmp(argu, "--help") == 0))
	{
			
		printf("tp0 [OPTIONS][file...]\n");
		printf("-h, --help display this help and exit\n");
		printf("-V, --version display version information and exit\n");
		printf("-m, --bubble use the bubblesort algorithm.\n");
		printf("-s, --sel use the shellsort algorithm.\n");
		return 0;
	}
	
			
	if ((strcmp(argu, "-V") == 0) || (strcmp(argu, "--version") == 0))
	{
		printf("Version 1.0\n");
		return 0;
	}
			
			
	if ((strcmp(argu, "-s") == 0) || (strcmp(argu, "--sel") == 0))
	{	
		modo_ordenamiento = 'S';
	}
		
	
    char buffer[BUFFERSIZE];
    char palabra[SIZE_PALABRA];
    char ** words;
    words = malloc(sizeof(void) * SIZE_TOTALPALABRAS);
    int cant_palabras = 0;
    int cant_letras = 0;
    
    
	while (fgets(buffer, BUFFERSIZE , stdin) != NULL)
    {

    	int c = 0;
    	for (c = 0; c < BUFFERSIZE; c++)
    		{
    			int finpalabra = 0;
    			
    			if (buffer[c] == ' ')
    				finpalabra = 1;
    			
    			if (buffer[c] == '\n') 
    				finpalabra = 0;
    			
    			
    			if (finpalabra == 1)
    			{
    				if (cant_letras != 0)
					{
	    				words[cant_palabras] = malloc(sizeof(char) * cant_letras);
	    				strncpy(words[cant_palabras], palabra, cant_letras);
						cant_letras = 0;
	    				cant_palabras++;
	    				
					}
				}
				else
				{
					palabra[cant_letras] = buffer[c];
					cant_letras++;
				}
			}
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
    	free(words[i]);
	}
	free(words);
	return 0;
}


