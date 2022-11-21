#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define OK 1
#define MINIMO(X,Y) ((X)<(Y)? (X):(Y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo *t_lista;

void crearLista(t_lista *pl);
int listaLlena(const t_lista *pl,unsigned tam);
void vaciarLista(t_lista *pl);
int cmp(const void*, const void*);
void actualizar(void *vexis, const void * vnuevo);

int ponerAlComienzo(t_lista *pl, void *pd, unsigned tam);
int ponerAlUltimo(t_lista *pl, void *pd, unsigned tam);
int ponerEnPosicion(t_lista *pl, void *pd, unsigned tam, int pos);
int ponerOrdenado(t_lista *pl, const void *pd, unsigned tam, int((*cmp)(const void *, const void*)));
int ponerYActualizar(t_lista *pl, const void *pd, unsigned tam, int(*cmp)(const void*, const void*), void (*actualizar)(void * ,const void*));


int sacarPrimero(t_lista *pl, void *pd, unsigned tam);
int sacarUltimo(t_lista *pl, void *pd, unsigned tam);
int sacarDePosicion(t_lista *pl, const void *pd, unsigned tam, int((*cmp)(const void *, const void*)));


#endif // LISTA_H_INCLUDED
