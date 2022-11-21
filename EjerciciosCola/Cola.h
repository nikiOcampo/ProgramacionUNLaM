#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM 300
#define COLA_LLENA 0
#define COLA_VACIA 0
#define MIN(X,Y)((X)<(Y)? (X):(Y))
#define OK 1

typedef struct
{
    char cola[TAM];
    unsigned pri;
    unsigned ult;
    unsigned tamDisp;
}t_cola;

void crearCola(t_cola *pc);
int colaLlena(const t_cola *pc,unsigned tam);
int ponerEnCola(t_cola *pc, const void *pd, unsigned tam);
int sacarDeCola(t_cola *pc, void *pd, unsigned tam);
void vaciarCola(t_cola *pc);
int colaVacia(const t_cola *pc);




#endif // COLA_H_INCLUDED
