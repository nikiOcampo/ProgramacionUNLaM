#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define PILA_LLENA 0
#define OK 1
#define MINIMO(X,Y)((X)<(Y)? (X):(Y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo *t_Pila;

void crearPila(t_Pila *pp);
int ponerEnPila(t_Pila *pp, const void *pd, unsigned tam);
int sacarDePila(t_Pila *pp, void *pd, unsigned tam);
int verTopePila(t_Pila *pp, void *pd, unsigned tam);
void vaciarPila(t_Pila *pp);
int pilaLlena(const t_Pila *pp, unsigned tam);
int pila_vacia(t_Pila *pp);


#endif // PILA_H_INCLUDED

