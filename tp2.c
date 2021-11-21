#include <stdio.h>


typedef struct sVia
{
    int time_stamp;
    int tag;
    int is_dirty;

};


typedef struct sBloque
{
 
    struct sVia* vias;
};

typedef struct sMemoria
{
    
    int cantidadvias;
    int cantidadbloques;
    int capaciadbloques;
    
	int bitsoffset;
    int bitsindex;
    int bitstag;
    struct sBloque* Bloque;
};



struct sMemoria memoria;

/*
La funcion init() debe inicializar los bloques de la cache como invalidos,
la memoria simulada en 0 y la tasa de misses a 0.
*/
void init()
{
	printf("%d", memoria.bitsoffset);
  //  prod=malloc(sizeof(struct sBloque));
}


/*
La funcion end() debe desalocar los bloques de la cache.
*/
void end()
{
	printf("%d", memoria.bitsoffset);
}



/*
La funcion find set(unsigned int address) debe devolver el conjunto
de cache al que mapea la direccion address.
*/
unsigned int find_set(unsigned int address)
{
	unsigned int sinoffset = (address >> memoria.bitsoffset);
	unsigned int efes = 0xFFFFFFFF;
	efes = (efes >> (32 - memoria.bitsindex));
	unsigned int ret = efes & sinoffset;
	return ret;
}

/*
La funcion find earliest(unsigned int setnum) debe devolver el
bloque mas 'antiguo' dentro de un conjunto, utilizando el campo correspondiente
de los metadatos de los bloques del conjunto.
*/
unsigned int find_earliest(unsigned int setnum)
{
	struct sBloque bloque = memoria.Bloque[setnum];
	int cont = 0;
	struct sVia viaearliest;

	// LE ASIGNA EL MAYOR NUMERO POSIBLE
	unsigned int ret = -1;

	for (cont = 0; cont < memoria.cantidadvias; cont)
	{
		struct sVia viacandidata = bloque.vias[cont];
		if (ret == -1)
		{
			ret = cont;
			viaearliest = viacandidata;
		}
		else
		{
			if (viaearliest.time_stamp < viaearliest.time_stamp)
			{
				ret = cont;
				viaearliest = viacandidata;
			}
		}
	}
	
}


/*
La funcion is dirty(unsigned int way,unsigned int setnum) debe
devolver el estado del bit D del bloque correspondiente.
*/
unsigned int is_dirty(unsigned int way, unsigned int setnum)
{
	return memoria.Bloque[setnum].vias[way].is_dirty;
}

/*
La funcion find block(unsigned int address) debe devolver el bloque
de memoria correspondiente a la direccion address.
*/

unsigned int find_block (unsigned int address)
{
	/// EL INDICE DE BLOQUE EN MEMORIA FISICA? QUE DIFERENCIA HAY CON find_set

	unsigned int sinoffset = (address >> memoria.bitsoffset);
	unsigned int efes = 0xFFFFFFFF;
	efes = (efes >> (32 - memoria.bitsindex));
	unsigned int ret = efes & sinoffset;
	return ret;
	
}


/*
La funcion read block(unsigned int blocknum) debe leer el bloque
blocknum de memoria y guardarlo en el lugar que le corresponda en
la memoria cache.
*/

void read_block(unsigned int blocknum)
{

}

/*
La funcion write block(unsigned int way, unsigned int
setnum) debe escribir en las posiciones correspondientes de memoria
el contenido del bloque setnum de la via way.
*/
void write_block(unsigned int way, unsigned int setnum)
{

}


/*
La funcion read byte(unsigned int address, char *hit) debe retornar
el valor correspondiente a la posicioon de memoria address,
buscnandolo primero en el cache, y escribir 1 en *hit si es un hit y 0 si
es un miss.
*/
char read_byte(unsigned int address, unsigned char *hit)
{

}


/*
La funcion write byte(unsigned int address, char value) debe
escribir el valor value en la posicion correcta del bloque que corresponde
a address, si esta en el cache, y escribir 1 en *hit si es un hit
y 0 si es un miss.
*/
void write_byte(unsigned int address, char value, unsigned char *hit)
{

}

/*
La funcion get miss rate() debe devolver el porcentaje de misses
desde que se inicializo el cache.
read byte() y write byte() solo deben interactuar con la memoria
a traves de las otras primitivas.
*/
char get_miss_rate()
{

}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	memoria.bitsoffset = 3;
	memoria.bitstag = 5;
	memoria.bitsindex = 5;	
	unsigned int g = find_set(1);
	g = find_set(2);
	printf("%d", g);
	
	g = find_set(8);
	printf("%d", g);
	
	g = find_set(256);
	printf("%d", g);
	
	g = find_set(264);
	printf("%d", g);
	
	init();
	return 0;
}
