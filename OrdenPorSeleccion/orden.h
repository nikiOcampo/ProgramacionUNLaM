#ifndef ORDEN_H_INCLUDED
#define ORDEN_H_INCLUDED

typedef struct sNodo
{
    void *info;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo *tlista;

void ordenPorSeleccion(tlista *pl, int (*cmp)(const void *, const void *));
void intercambiar(void* v1, void*v2, unsigned tam);
int cmp(const void *a, const void *b);
tlista* buscarMenor(tlista *pl, int(*cmp)(const void*,const void*));

#endif // ORDEN_H_INCLUDED
