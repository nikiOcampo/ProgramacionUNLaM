#ifndef ELIMREP_H_INCLUDED
#define ELIMREP_H_INCLUDED

typedef struct sNodo
{
    void *info;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo *tlista;

void eliminarRepetidos(tlista *pl, int(*cmp)(const void*, const void*));
int cmp(const void *a, const void *b);

#endif // ELIMREP_H_INCLUDED
