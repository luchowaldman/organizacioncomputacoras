
struct sBloque 
{
    int time_stamp;
    int tag;
    bool dirty;
}


struct sSet 
{
    sBloque[] bloques ;
    

}

struct sMemoria {
    int vias;

    int capacidad;
    int capacidadbloques;


    int bitsoffset;
    int bitsgrupo;
    int bitstag;


    sSet[] Vias;

}

sMemoria memoria = new sMemoria(); 

/*
La funcion init() debe inicializar los bloques de la cache como invalidos,
la memoria simulada en 0 y la tasa de misses a 0.
*/
void init()
{

}


/*
La funcion find set(unsigned int address) debe devolver el conjunto
de cache al que mapea la direccion address.
*/
unsigned int find_set(unsigned int address)
{
    



}

/*
La funcion find earliest(unsigned int setnum) debe devolver el
bloque mas 'antiguo' dentro de un conjunto, utilizando el campo correspondiente
de los metadatos de los bloques del conjunto.
*/
unsigned int find_earliest(unsigned int setnum)


/*
La funcion is dirty(unsigned int way,unsigned int setnum) debe
devolver el estado del bit D del bloque correspondiente.
*/
unsigned int is_dirty(unsigned int way, unsigned int setnum)

/*
La funcion find block(unsigned int address) debe devolver el bloque
de memoria correspondiente a la direccion address.
*/

unsigned int find_block (unsigned int address)


/*
La funcion read block(unsigned int blocknum) debe leer el bloque
blocknum de memoria y guardarlo en el lugar que le corresponda en
la memoria cache.
*/

void read_block(unsigned int blocknum)

/*
La funcion write block(unsigned int way, unsigned int
setnum) debe escribir en las posiciones correspondientes de memoria
el contenido del bloque setnum de la via way.
*/
void write_block(unsigned int way, unsigned int setnum)


/*
La funcion read byte(unsigned int address, char *hit) debe retornar
el valor correspondiente a la posicioon de memoria address,
buscnandolo primero en el cache, y escribir 1 en *hit si es un hit y 0 si
es un miss.
*/
char read_byte(unsigned int address, unsigned char *hit)


/*
La funcion write byte(unsigned int address, char value) debe
escribir el valor value en la posicion correcta del bloque que corresponde
a address, si esta en el cache, y escribir 1 en *hit si es un hit
y 0 si es un miss.
*/
void write_byte(unsigned int address, char value, unsigned char *hit)

/*
La funcion get miss rate() debe devolver el porcentaje de misses
desde que se inicializo el cache.
read byte() y write byte() solo deben interactuar con la memoria
a traves de las otras primitivas.
*/
char get_miss_rate()

int maint