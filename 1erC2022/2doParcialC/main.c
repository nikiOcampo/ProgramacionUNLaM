#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <arbol.h>

#define PATH_ARCH_ALUMNOS "../archivos/alumnos.dat"
#define PATH_ARCH_INDICE "../archivos/alumnos.idx"



void imprimirMensaje(int res);
void opAlta(FILE * arch, tArbolBinBusq * pindice);
void opBaja(FILE * arch, tArbolBinBusq * pindice);
void opAgregarMateria(FILE * arch, tArbolBinBusq * pindice);
void opListarIndice(tArbolBinBusq * pindice);
void opListarAlumnos(FILE * arch);
void opListarAlumnosOrdenado(FILE * arch, tArbolBinBusq * pindice);
void opEliminarUltimoIngresado(FILE * arch, tArbolBinBusq * pindice);
void opCompactarYReindexar(FILE ** arch, tArbolBinBusq * pindice, const char * path);

int main()
{
    FILE * arch;
    const char opciones [][TAM_MENU] = {"ABEILMUCS",
                                        "Alta",
                                        "Baja",
                                        "Agregar Materia",
                                        "Listar Indice",
                                        "Listar Alumnos",
                                        "Listar Alumnos Ordenado por DNI",
                                        "Eliminar el ultimo ingresado",
                                        "Compactar Archivo y Reindexar",
                                        "Salir"};
    char op;
    tArbolBinBusq indice;

    ///Descomente esta linea para restaurar las pruebas
    restaurarPrueba_res(PATH_ARCH_ALUMNOS, PATH_ARCH_INDICE);

    arch = fopen(PATH_ARCH_ALUMNOS, "r+b");
    if (!arch)
        exit(1);

    //crearArbolBinBusq_res(&indice);
    crearArbolBinBusq(&indice);

//    if(cargarArchivoBinOrdenadoArbolBinBusq_res(&indice, PATH_ARCH_INDICE, sizeof(tRegInd))==ERROR_ARCHIVO)
//        exit(1);

//ESTO NO FUNCIONA
//    if(cargarDesdeArchivoPreOrdenArbol(&indice, PATH_ARCH_INDICE, sizeof(tRegInd),cmp_reg)==ERROR_ARCHIVO)
//        exit(1);


//ESTO FUNCIONA
    if(cargarArchivoBinOrdenadoArbolBinBusq(&indice, PATH_ARCH_INDICE, sizeof(tRegInd))==ERROR_ARCHIVO)
        exit(1);

    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'A':
                opAlta(arch, &indice);
                break;
            case 'B':
                opBaja(arch, &indice);
                break;
            case 'E':
                opAgregarMateria(arch, &indice);
                break;
            case 'I':
                opListarIndice(&indice);
                break;
            case 'L':
                opListarAlumnos(arch);
                break;
            case 'M':
                opListarAlumnosOrdenado(arch, &indice);
                break;
            case 'U':
                opEliminarUltimoIngresado(arch, &indice);
                break;
            case 'C':
                opCompactarYReindexar(&arch, &indice, PATH_ARCH_ALUMNOS);
                break;
        }
    }while(op!='S');
    //grabarEnArchivoOrdenadoArbolBin_res(&indice, PATH_ARCH_INDICE);
    ///grabarEnArchivoPreOrdenadoArbolBin(&indice,PATH_ARCH_INDICE);
    grabarEnArchivoOrdenadoArbolBin(&indice,PATH_ARCH_INDICE);
    //vaciarArbolBin_res(&indice);
    vaciarArbolBin(&indice);
    fclose(arch);
    return 0;
}

void opAlta(FILE * arch, tArbolBinBusq * pindice)
{
    int res;
    tAlumno alu;
    ingresarAlumno_res(&alu);
    //res= alta_res(&alu, arch, pindice);
    res=alta(&alu,arch,pindice);
    imprimirMensaje(res);
}

void opBaja(FILE * arch, tArbolBinBusq * pindice)
{
    int res;
    tAlumno alu;
    ingresarDniAlumno_res(&alu);
    //res= baja_res(&alu, arch, pindice);
    res=baja(&alu,arch,pindice);
    imprimirMensaje(res);
}

void opAgregarMateria(FILE * arch, tArbolBinBusq * pindice)
{
    int res;
    //res= agregarMateria_res(arch, pindice);
    res= agregar_materia(arch, pindice);
    imprimirMensaje(res);
}

void opListarIndice(tArbolBinBusq * pindice)
{
    printf("\n\n");
    //arbolGrafico_res(pindice, mostrarDni_res);
    arbolGrafico(pindice,mostrar_dni);
    pausa("\n\n");
}

void opListarAlumnos(FILE * arch)
{
    printf("\n\n");
    //imprimirArchivo_res(arch);
    imprimir_archivo(arch);
    pausa("\n\n");
}

void opListarAlumnosOrdenado(FILE * arch, tArbolBinBusq * pindice)
{
    printf("\n\n");
    //imprimirArchivoOrdenado_res(arch, pindice);
    imprimir_archivo_ordenado(arch, pindice);
    pausa("\n\n");
}

void opEliminarUltimoIngresado(FILE * arch, tArbolBinBusq * pindice)
{
    int res;
    //res= bajaUltimo_res(arch, pindice);
    res= baja_ultimo(arch, pindice);
    imprimirMensaje(res);
}

void opCompactarYReindexar(FILE ** arch, tArbolBinBusq * pindice, const char * path)
{
    int res;
    //res= compactarYReindexar_res(arch, pindice, path);
    res= compactar_y_reindexar(arch, pindice, path);
    imprimirMensaje(res);
}

void imprimirMensaje(int res)
{
    switch(res)
    {
        case TODO_OK: pausa("Operacion realizada correctamente.");
                break;
        case SIN_MEM: pausa("Error de memoria.");
                break;
        case ERROR_ARCHIVO: pausa("Error en el archivo.");
                break;
        case DUPLICADO: pausa("Resgistro duplicado.");
                break;
        case NO_EXISTE: pausa("Resgistro inexistente.");
                break;
    }
}
