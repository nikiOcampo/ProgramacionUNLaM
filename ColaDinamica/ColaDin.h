#ifndef COLADIN_H_INCLUDED
#define COLADIN_H_INCLUDED

#define COLA_LLENA 0
#define COLA_VACIA 0
#define MIN(X,Y)((X)<(Y)? (X):(Y))
#define OK 1

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo*sig;
}tNodo;

typedef struct
{
    tNodo *pri;
    tNodo *ult;
}t_cola;

void crearCola(t_cola *pc);
int ponerEnCola(t_cola *pc, const void *pd, unsigned tam);
int sacarDeCola(t_cola *pc, void *pd, unsigned tam);
int frenteDeCola(t_cola *pc,void *pd, unsigned tam);
int colaLlena(const t_cola *pc,unsigned tam);
int colaVacia(const t_cola *pc);


#endif // COLADIN_H_INCLUDED
