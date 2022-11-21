#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define OK 1
#define reservarMemoriaNodo(X, Y, Z, W) (( (X)= (typeof(X))malloc (Y))== NULL || ((Z)= malloc(W))== NULL ? free(X), 0: 1)
#define MINIMO(X,Y) ((X)<(Y)? (X):(Y))

typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,
                      *der;
}tNodoArbol;

typedef tNodoArbol *tArbolBinBusq;


void crearArbolBinBusq(tArbolBinBusq *p);

int insertarArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, int (*cmp)(const void *, const void *));///iterativa
int insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, int (*cmp)(const void *, const void *)); ///recursivo
int cmp(const void* a, const void* b);


int cargarDesdeDatorOrdenadosRec(tArbolBinBusq *p, void *d, unsigned (*leer)(void **, void *, unsigned, void *params), int li, int ls, void*params);
int cargarArchivoBinOrdenadoAbiertoArbolBinBusq(tArbolBinBusq *p, FILE *pf, unsigned tamInfo);
int cargarArchivoBinOrdenandoArbolBinBusq(tArbolBinBusq *p, const char *path, unsigned tamInfo);
unsigned leerDesdeArchivoBin(void **d, void *pf, unsigned pos, void *params);
int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq *p, void *d, unsigned cantReg, unsigned (*leer)(void**,void*,unsigned,void *params), void *params);
//void guardarBinAlumno(void* alu, void* params, unsigned n);

int eliminarRaizArbolBinBusq(tArbolBinBusq *p);
int eliminarElemArbolBinBusq(tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*));
int buscarElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*));
tNodoArbol ** mayorNodoArbolBinBusq(const tArbolBinBusq *p);
tNodoArbol ** menorNodoArbolBinBusq(const tArbolBinBusq *p);
tNodoArbol ** mayorRecNodoArbolBinBusq(const tArbolBinBusq *p);
tNodoArbol ** menorRecNodoArbolBinBusq(const tArbolBinBusq *p);
tNodoArbol ** buscarNodoArbolBinBusq(const tArbolBinBusq *p, const void *d, int(*cmp)(const void*, const void *));
tNodoArbol ** buscarRecNodoArbolBinBusq(const tArbolBinBusq *p, const void *d, int (*cmp)(const void*, const void*));
unsigned alturaArbolBin(const tArbolBinBusq *p);


void recorrerEnOrdenRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void *params, void(*accion)(void*,unsigned, unsigned,void*));
void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq *p, void *params, void(*accion)(void*, unsigned, unsigned, void*));
void recorrerEnOrdenInversoRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void *params, void (*accion)(void*,unsigned,unsigned,void *));
void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq *p, void *params, void(*accion)(void*, unsigned, unsigned, void*));
void recorrerPreOrdenRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void *params, void(*accion)(void*, unsigned,unsigned, void*));
void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq *p, void *params, void(*accion)(void*,unsigned,unsigned,void*));
void recorrerPosOrdenRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void* params,void(*accion)(void*, unsigned, unsigned, void*));
void recorrerPosOrdenArbolBinBusq(const tArbolBinBusq *p, void* params, void(*accion)(void*, unsigned, unsigned, void*));
void recorrerEnOrdenSimpleArbolBinBusq(const tArbolBinBusq*p, void* params, void(*accion)(void*, unsigned, void*));
void recorrerPreOrdenSimpleArbolBinBusq(const tArbolBinBusq*p, void* params, void(*accion)(void*, unsigned, void*));
void recorrerPosOrdenSimpleArbolBinBusq(const tArbolBinBusq*p, void* params, void(*accion)(void*, unsigned, void*));

int mayorElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*));
const tArbolBinBusq * mayorNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const tArbolBinBusq *mayor, int (*cmp)(const void*,const void*));
int menorElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*));
const tArbolBinBusq * menorNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const tArbolBinBusq *menor, int (*cmp)(const void*,const void*));
int buscarElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int (*cmp)(const void*, const void*));
const tArbolBinBusq* buscarNodoNoClaveArbolBinBusq( const tArbolBinBusq *p, const void* d, int (*cmp)(const void*, const void*));



//utilididades
unsigned cantNodosArbolBin(const tArbolBinBusq *p);
int mayorElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam);
int menorElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam);
unsigned cantNodosHastaNivelArbonBin(const tArbolBinBusq *p, int n);
int esCompletoHastaNivelArbolBin(const tArbolBinBusq *p, int n);
int esCompletoArbolBin(const tArbolBinBusq *p);
int esBalanceadoArbolBin(const tArbolBinBusq *p);
int esAVLArbolBin(const tArbolBinBusq *p);
int esCompleto2ArbolBin(const tArbolBinBusq *p);
int esBalanceado2ArbolBin(const tArbolBinBusq *p);
int esAVL2CalculoArbolBin(const tArbolBinBusq *p);
int esAVL2ArbolBin( const tArbolBinBusq *p);
void imprimirConForma(void * info, unsigned tam, unsigned n, void* params);
void imprimir(void *info, unsigned tam, unsigned n, void* params);
//void imprimir_forma_alumno(void* v_alu, void *params, unsigned n);
unsigned leerDesdeVectorEnteros(void** d, void *vec, unsigned pos, void * params);
int cmp_ent(const void *v1 , const void* v2);
void podar_arbol (tArbolBinBusq *p);

#endif // ARBOL_H_INCLUDED
