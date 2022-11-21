#ifndef PILAE_H_INCLUDED
#define PILAE_H_INCLUDED


#define TAM 15
#define PILA_LLENA 0
#define OK 1
#define MIN(X,Y)((X)<(Y)? (X):(Y))

typedef struct
{
    char vect[TAM];
    unsigned tope;
}t_Pila;

void crearPila(t_Pila *pp);
int ponerEnPila(t_Pila *pp, const void *pd, unsigned tam);
int sacarDePila(t_Pila *pp, void *pd, unsigned tam);
int verTopePila(t_Pila *pp, void *pd, unsigned tam);
void vaciarPila(t_Pila *pp);
int pilaLlena(const t_Pila *pp, unsigned tam);
int pila_vacia(t_Pila *pp);



#endif // PILAE_H_INCLUDED
