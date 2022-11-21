#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\Usuario\Desktop\NICOLE OCAMPO\00 UNLaM\16 programación\pila\EjerciciosPila\Pila.h"

int main()
{
//    1- Crear/cargar Pila1 por teclado con 5 elementos.
//    Poner los primeros tres elementos de la PilaAux1 y los restantes a otra PilaAux2, ambas inicializadas en null/vacias.
//    t_Pila pila1,pilaAux1,pilaAux2;
//    int i,elem;
//    crearPila(&pila1);
//    crearPila(&pilaAux1);
//    crearPila(&pilaAux2);
//    for(i=0;i<5;i++)
//    {
//        printf("\nIngrese un elemento para la pila ppal: ");
//        scanf("%d", &elem);
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem)))
//            puts("PILA LLENA");
//    }
//    printf("\nPILA PPAL CORRECTAMENTE CARGADA");
//    for(i=0;i<5;i++)
//    {
//        if(i<2)
//        {
//            printf("\nPILA AUX 2");
//            if(!sacarDePila(&pila1,&elem,sizeof(elem)))
//                puts("\nNo pudo sacar");
//            if(!ponerEnPila(&pilaAux2,&elem,sizeof(elem)))
//                puts("PILA LLENA");
//            printf("\nse ingreso correctamente el elemento: %d", elem);
//
//        }
//        else
//        {
//            printf("\nPILA AUX 1");
//            if(!sacarDePila(&pila1,&elem,sizeof(elem)))
//                puts("\nNo pudo sacar");
//            if(!ponerEnPila(&pilaAux1,&elem,sizeof(elem)))
//            puts("PILA LLENA");
//            printf("\nse ingreso correctamente el elemento: %d", elem);
//        }
//    }


//2- Cargar PilaOrigen por teclado e inicializar en vacio PilaDestino. Pasar todos los elementos de PilaOrigen a la PilaDestino.
//
//    t_Pila pilaOrigen, pilaDestino;
//    crearPila(&pilaOrigen);
//    crearPila(&pilaDestino);
//    int i,elem;
//    for(i=0;i<5;i++)
//    {
//        printf("\nIngrese un elemento para la pila Origen: ");
//        scanf("%d", &elem);
//        if(!ponerEnPila(&pilaOrigen,&elem,sizeof(elem)))
//           puts("PILA LLENA");
//    }
//    for(i=0;i<5;i++)
//    {
//        if(!sacarDePila(&pilaOrigen,&elem,sizeof(elem)))
//            puts("PILA VACIA");
//        if(!ponerEnPila(&pilaDestino,&elem,sizeof(elem)))
//            puts("No se pudo poner en Pila Destino");
//        printf("\nSe ingreso correctamente el elemento %d en la pila destino", elem);
//    }

//   3- Cargar desde teclado Pila1 y pasar a PilaDestino todos aquellos elementos distintos a 3(tres).
//    t_Pila pila1, pilaDestino;
//    crearPila(&pila1);
//    crearPila(&pilaDestino);
//    int cant,elem,i;
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem)))
//            puts("\nNo se pudo poner en pila");
//    }
//    for(i=0;i<cant;i++)
//    {
//        if(!sacarDePila(&pila1,&elem,sizeof(elem)))
//            puts("\nNO SE PUDO SACAR DE PILA");
//        if(elem!=3)
//        {
//            if(!ponerEnPila(&pilaDestino,&elem,sizeof(elem)))
//                puts("\nNo se pudo poner en pila destino");
//            printf("\nSe ingreso el elemnto %d", elem);
//        }
//    }

//4- Cargar desde taclado PilaOrigen e
//inicializar (null) la PilaDestino.
//Pasar los elementos de PilaOrigen a PilaDestino pero deben quedar en el mismo orden.
//    t_Pila pilaOrigen, PilaDestino,pilaAux;
//    crearPila(&pilaOrigen);
//    crearPila(&PilaDestino);
//    crearPila(&pilaAux);
//    int cant,elem,i;
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pilaOrigen,&elem,sizeof(elem)))
//            puts("\nNo se pudo poner en pila");
//    }
//    for(i=0;i<cant;i++)
//    {
//        if(!sacarDePila(&pilaOrigen,&elem,sizeof(elem))) puts("NO SE PUDO SACAR DE PILA");
//        if(!ponerEnPila(&pilaAux,&elem,sizeof(elem))) puts("NO SE PUDO PONER EN PILA AUX");
//    }
//    for(i=0;i<cant;i++)
//    {
//        if(!sacarDePila(&pilaAux,&elem,sizeof(elem))) puts("NO SE PUDO SACAR DE PILA AUX");
//        if(!ponerEnPila(&PilaDestino,&elem,sizeof(elem))) puts("No se pudo poner en pila destino");
//        printf("\nSe ingreso el numero %d a pila destino", elem);
//    }

//5- Cargar desde teclado Pila1. Invertir la pila para que Pila1 contenga los elementos cargados originalmente en orden inverso.
//    t_Pila pila1, pilaAux,pilaAux2;
//    crearPila(&pila1);
//    crearPila(&pilaAux);
//    crearPila(&pilaAux2);
//    int cant,elem,i;
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem)))
//            puts("\nNo se pudo poner en pila");
//    }
//    for(i=0;i<cant;i++)
//    {
//        if(!sacarDePila(&pila1,&elem,sizeof(elem))) puts("No se pudo sacar de pila1");
//        if(!ponerEnPila(&pilaAux,&elem,sizeof(elem))) puts("No se pudo poner en pilaAux");
//    }
//    for(i=0;i<cant;i++)
//    {
//        if(!sacarDePila(&pilaAux,&elem,sizeof(elem))) puts("No se pudo sacar de pilaAux");
//        if(!ponerEnPila(&pilaAux2,&elem,sizeof(elem))) puts("No se pudo poner en pilaAux2");
//    }
//    for(i=0;i<cant;i++)
//    {
//        if(!sacarDePila(&pilaAux2,&elem,sizeof(elem))) puts("No se pudo sacar de pilaAux2");
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("No se pudo poner en pila1");
//        printf("\npila 1: elemento %d: %d",(i+1),elem);
//    }
//6- Pasar el primer elemento de la Pila1 a su última posición, dejando los restantes en el mismo orden.
//    t_Pila pila1, pilaAux, pilaAux2;
//    crearPila(&pila1);
//    crearPila(&pilaAux);
//    crearPila(&pilaAux2);
//    int cant,elem,i;
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila");
//    }
//    for(i=0;i<cant;i++)
//    {
//        if(!sacarDePila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo sacar de pila1");
//        if(!ponerEnPila(&pilaAux,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaAux");
//    }
//    if(!sacarDePila(&pilaAux,&elem,sizeof(elem))) puts("No se pudo sacar de pilaAux");
//    if(!ponerEnPila(&pilaAux2,&elem,sizeof(elem))) puts("No se pudo poner en pilaAux2");
//    for(i=0;i<cant-1;i++)
//    {
//        if(!sacarDePila(&pilaAux,&elem,sizeof(elem))) puts("No se pudo sacar de pilaAux");
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("No se pudo poner en pila 1");
//        printf("\nSe ingreso en Pila1: %d", elem);
//    }
//    if(!sacarDePila(&pilaAux2,&elem,sizeof(elem))) puts("No se pudo sacar de pilaAux2");
//    if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("No se pudo poner en pila1");
//    printf("\nSe ingreso en Pila1: %d", elem);

// 7- Pasar el último elemento de la Pila1 a su primera posición, dejando los restantes en el mismo orden.
//    t_Pila pila1,pilaAux,pilaAux2;
//    crearPila(&pila1);
//    crearPila(&pilaAux);
//    crearPila(&pilaAux2);
//    int cant,elem,i;
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila");
//    }
//    if(!sacarDePila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo sacar de pila1");
//    if(!ponerEnPila(&pilaAux,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaAux");
//    for(i=0;i<cant-1;i++)
//    {
//        if(!sacarDePila(&pila1,&elem,sizeof(elem)))puts("\nNo se pudo sacar de pila1");
//        if(!ponerEnPila(&pilaAux2,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaAxu2");
//    }
//    if(!sacarDePila(&pilaAux,&elem,sizeof(elem))) puts("\nNo se pudo sacar de pilaAux");
//    if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila1");
//    printf("\nSe ingreso %d a pila1",elem);
//    for(i=0;i<cant-1;i++)
//    {
//        if(!sacarDePila(&pilaAux2,&elem,sizeof(elem)))puts("\nNo se pudo sacar de pilaAux2");
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila1");
//        printf("\nSe ingreso %d a pila1",elem);
//    }
//8- Repartir los elementos de la PilaMazo en la PilaJugador1 y PilaJugador2 en forma alternada.
//    t_Pila pilaMazo,pilaJugador1, pilaJugador2;
//    crearPila(&pilaMazo);
//    crearPila(&pilaJugador1);
//    crearPila(&pilaJugador2);
//    int cant,elem,i;
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pilaMazo,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaMazo");
//    }
//    for(i=0;i<cant/2;i++)
//    {
//        if(!sacarDePila(&pilaMazo,&elem,sizeof(elem))) puts("\nNo se pudo sacar de la pila Mazo");
//        if(!ponerEnPila(&pilaJugador1,&elem,sizeof(elem))) puts("\nNo se pudo poner el pilaJugador1");
//        printf("\nPila jugador 1: %d",elem);
//        if(!sacarDePila(&pilaMazo,&elem,sizeof(elem))) puts("\nNo se pudo sacar de la pila Mazo");
//        if(!ponerEnPila(&pilaJugador1,&elem,sizeof(elem))) puts("\nNo se pudo poner el pilaJugador2");
//        printf("\nPila jugador 2: %d", elem);
//    }
//9- Comparar la cantidad de elementos de la PilaA y PilaB. Mostrar por pantalla el resultado.
//    t_Pila pilaA,pilaB;
//    crearPila(&pilaA);
//    crearPila(&pilaB);
//    int i,elem,cont1=0,cont2=0;
//    for(i=0;i<6;i++)
//    {
//        printf("\nIngrese un elemento para la pila A: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pilaA,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaA");
//    }
//    for(i=0;i<2;i++)
//    {
//        printf("\nIngrese un elemento para la pila B: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pilaB,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaB");
//    }
//    while(pilaA)
//    {
//        if(!sacarDePila(&pilaA,&elem,sizeof(elem))) puts("No se pudo sacar de pilaA");
//        cont1++;
//    }
//    while(pilaB)
//    {
//        if(!sacarDePila(&pilaB,&elem,sizeof(elem))) puts("No se pudo sacar de pilaB");
//        cont2++;
//    }
//    (cont1>cont2)? printf("La pila A tiene mayor cantidad de elementos"): printf("La pila B tiene mayor cantidad de elementos");

//10- Comparar la cantidad de elementos de la PilaA y PilaB, evaluando si son complemente iguales (en cant de elementos, valores y posiciones).
// Mostrar por pantalla el resultado.
//    t_Pila pilaA,pilaB;
//    crearPila(&pilaA);
//    crearPila(&pilaB);
//    int i,elem,elem2,cont1=0,cont2=0;
//    for(i=0;i<6;i++)
//    {
//        printf("\nIngrese un elemento para la pila A: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pilaA,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaA");
//    }
//    for(i=0;i<6;i++)
//    {
//        printf("\nIngrese un elemento para la pila B: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pilaB,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaB");
//    }
//    while(pilaA)
//    {
//        if(!sacarDePila(&pilaA,&elem,sizeof(elem))) puts("No se pudo sacar de pilaA");
//        cont1++;
//        if(!sacarDePila(&pilaB,&elem2,sizeof(elem2))) puts("No se pudo sacar de pilaB");
//        cont2++;
//        if(cont1!=cont2)
//        {
//            printf("\nLas pilas no son igaules");
//        }
//        else
//        {
//            if(elem2!=elem)
//            {
//                printf("\nLas pilas no son iguales");
//                return 0;
//            }
//        }
//    }
//        printf("\nLas pilas son iguales en cantidad, contenido y posiciones");

//11- Suponiendo la existencia de PilaModelo no vacia, eliminar de la Pila1 todos los elementos que sean iguales al tope de la PilaModelo.
//    t_Pila pilaModelo, Pila1,pilaAux;
//    crearPila(&pilaModelo);
//    crearPila(&Pila1);
//    crearPila(&pilaAux);
//    int cant,elem,i,tope;
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila Modelo: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pilaModelo,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila modelo");
//    }
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila 1: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&Pila1,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila modelo");
//    }
//    if(!sacarDePila(&pilaModelo,&tope,sizeof(tope))) puts("\nNo se pudo sacar de pila modelo");
//    while(Pila1)
//    {
//        if(!verTopePila(&Pila1,&elem,sizeof(elem))) puts("No se pudo ver el tope de pila 1");
//        if(elem==tope)
//        {
//            if(!sacarDePila(&Pila1,&elem,sizeof(elem))) puts("\nNo se pudo sacar de pila 1");
//            printf("\nSe saco de pila 1 el elemento %d", elem);
//        }
//        else
//        {
//            if(!sacarDePila(&Pila1,&elem,sizeof(elem))) puts("\nNo se pudo sacar de pila 1");
//            if(!ponerEnPila(&pilaAux,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila aux");
//        }
//    }
//    while(pilaAux)
//    {
//        if(!sacarDePila(&pilaAux,&elem,sizeof(elem))) puts("\nNo se pudo sacar de pila aux");
//        if(!ponerEnPila(&Pila1,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila 1");
//        printf("\nElemento de Pila 1: %d", elem);
//    }

//12- Suponiendo la existencia de PilaModelo vacia o no, eliminar de la Pila1 todos los elementos que existan en PilaModelo.
//    t_Pila pilaModelo, pila1, pilaAux;
//    crearPila(&pila1);
//    crearPila(&pilaAux);
//    crearPila(&pilaModelo);
//    int cant,i,elem,ban=0;
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila Modelo: ");
//    scanf("%d", &cant);
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila Modelo: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pilaModelo,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila modelo");
//    }
//    printf("\nIngrese la cantidad de elementos que desea ingresar en la pila 1: ");
//    scanf("%d", &cant);
//    int vect[cant];
//    for(i=0;i<cant;i++)
//    {
//        printf("\nIngrese un elemento para la pila 1: ");
//        scanf("%d",&elem);
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila 1");
//    }
//    i=0;
//    while(pilaModelo)
//    {
//        if(!sacarDePila(&pilaModelo,&elem,sizeof(elem))) puts("\nNo se pudo sacar de pila Modelo");
//        vect[i]=elem;
//        i++;
//    }
//    while(pila1)
//    {
//        ban=0;
//        if(!sacarDePila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo sacar de pila 1");
//        for(i=0;i<cant;i++)
//        {
//            if(elem==vect[i])
//            {
//                ban=1;
//            }
//        }
//        if(!ban)
//        {
//            if(!ponerEnPila(&pilaAux,&elem,sizeof(elem))) puts("\nNo se pudo poner en pilaAux");
//        }
//    }
//    while(pilaAux)
//    {
//        if(!sacarDePila(&pilaAux,&elem,sizeof(elem)))puts("\nNo se pudo sacar de pila Aux");
//        if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("\nNo se pudo poner en pila 1");
//        printf("\nSe quedo el elemento %d en pila 1", elem);
//    }

//13- Suponiendo la existencia de PilaLimite, pasar los elementos de la Pila1 que sean
//>= que el tope de PilaLimite a la PilaMayores y los menores a la pilaMenores.
    t_Pila pilaLimite,pila1,pilaMayores,pilaMenores;
    crearPila(&pilaLimite);
    crearPila(&pila1);
    crearPila(&pilaMayores);
    crearPila(&pilaMenores);
    int cant,i,elem,tope;
    printf("\nIngrese la cantidad de elemntos a cargar en la pila limite: ");
    scanf("%d", &cant);
    for(i=0;i<cant;i++)
    {
        printf("\nIngrese el elemento a ingresar en la pilaLimite: ");
        scanf("%d", &elem);
        if(!ponerEnPila(&pilaLimite,&elem,sizeof(elem))) puts("No se pudo poner en pila Limite");
    }
    printf("\nIngrese la cantidad de elemntos a cargar en la pila 1: ");
    scanf("%d", &cant);
    for(i=0;i<cant;i++)
    {
        printf("\nIngrese el elemento a ingresar en la pila1: ");
        scanf("%d", &elem);
        if(!ponerEnPila(&pila1,&elem,sizeof(elem))) puts("No se pudo poner en pila 1");
    }
    if(!verTopePila(&pilaLimite,&tope,sizeof(tope))) puts("No se pudo ver el tope de la pila Limite");
    while(pila1)
    {
        if(!sacarDePila(&pila1,&elem,sizeof(elem)))puts("\nNo se pudo sacar de pila1");
        if(elem>=tope)
        {
            if(!ponerEnPila(&pilaMayores,&elem,sizeof(elem))) puts("\nNo se pudo poner en PIla Mayores");
            printf("\nSe ingreso a pila Mayores: %d ", elem);
        }
        else
        {
            if(!ponerEnPila(&pilaMenores,&elem,sizeof(elem))) puts("\nNo se pudo poner en PIla Menores");
            printf("\nSe ingreso a pila Menores: %d ", elem);
        }
    }
    return 0;
}
