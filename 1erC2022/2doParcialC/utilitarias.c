#include<utilitarias.h>
#include<string.h>
#include<varias.h>
#include <arbol.h>
#define PATH_ARCH_ALUMNOS_TMP "../archivos/alumnos_temp.dat"
#define PATH_ARCH_ALUMNOS "../archivos/alumnos.dat"




int cmp_dni(const void *v1,const void *v2)
{
    const tRegInd *e1=(const tRegInd*)v1,
            *e2=(const tRegInd*)v2;
    return (e1->dni)-(e2->dni);
}


int cmp_reg(const void *v1, const void *v2)
{
    tRegInd* a=(tRegInd *)v1;
    tRegInd* b=(tRegInd *)v2;

    return a->dni - b->dni;
}

void escribir_archivo(void *d, unsigned tam, void * arch)
{
    fwrite(d,tam,1,(FILE*)arch);
}

int alta (tAlumno * alu, FILE * arch, tArbolBinBusq* pa)
{
    tRegInd ind;
    int cantReg,r;

    fseek(arch, 0L,SEEK_END);
    cantReg=ftell(arch)/sizeof(tAlumno)-1;
    ind.nro_reg=cantReg;
    ind.dni=alu->dni;
    r=insertarRecArbolBinBusq(pa,&ind,sizeof(tRegInd),cmp_dni);
    if(r!=TODO_OK)
    {
        return r;
    }
    fwrite(alu,sizeof(tAlumno),1,arch);
    return TODO_OK;
}

int baja (tAlumno * alu, FILE * arch, tArbolBinBusq* pa)
{
    tRegInd ind;
    int r;
    ind.dni=alu->dni;
    //r=eliminarElemArbolBinBusq_res(pa,&ind,sizeof(tRegInd),cmp_dni);
    r=eliminarElemArbolBinBusq(pa,&ind,sizeof(tRegInd),cmp_dni);
    if(r!=TODO_OK) return NO_EXISTE;
    fseek(arch,ind.nro_reg*(long)sizeof(tAlumno),SEEK_SET);
    fread(alu,sizeof(tAlumno),1,arch);
    alu->estado='B';
    fseek(arch,-1L*(long)sizeof(tAlumno),SEEK_CUR);
    fwrite(alu,sizeof(tAlumno),1,arch);
    return TODO_OK;
}

int agregar_materia(FILE * arch, tArbolBinBusq * pindice)
{
    tAlumno alu;
    tRegInd ind;
    int r;
    //ingresarDniAlumno_res(&alu);
    ingresar_dni_alumno(&alu);
    ind.dni=alu.dni;
    r=buscarElemArbolBinBusq(pindice,&ind,sizeof(tRegInd),cmp_dni);
    if(r!=TODO_OK) return NO_EXISTE;
    fseek(arch,ind.nro_reg*(long)sizeof(tAlumno),SEEK_SET);
    fread(&alu,sizeof(tAlumno),1,arch);
    fseek(arch,-1L*(long)sizeof(tAlumno),SEEK_CUR);
    //imprimirAlumno_res(&alu);
    imprimir_alumno(&alu);
    //ingresarNuevaMateria_res(&alu);
    ingresar_nueva_materia(&alu);
    //imprimirAlumno_res(&alu);
    imprimir_alumno(&alu);
    fwrite(&alu,sizeof(tAlumno),1,arch);
    return TODO_OK;
}

void mostrar_dni(const void * info)
{
    const tRegInd *i=(const tRegInd*) info;
    printf("%d" , i->dni);
}

void ingresar_dni_alumno(tAlumno* alu)
{
    printf("\nIngrese el DNI: ");
    scanf("%d", &(alu->dni));
}

void imprimir_alumno(const tAlumno* alu)
{

    printf("\n");
    printf("\nDNI: %d", alu->dni);
    printf("\nApellido y Nombre: %s", alu->apyn);
    printf("\nMarerias: %d    Promedio: %f ", alu->cant_materias,alu->promedio);
    printf("\nEstado: %c", alu->estado);
}

void ingresar_nueva_materia(tAlumno* alu)
{
    float nuevaNota=0;
    printf("\nIngrese la nueva nota: ");
    scanf("%f", &nuevaNota);
    float promedio= alu->promedio*alu->cant_materias + nuevaNota;
    alu->cant_materias+=1;
    promedio= promedio/alu->cant_materias;
    alu->promedio=promedio;
}

void imprimir_archivo(FILE * arch)
{
    tAlumno alu;
    fread(&alu,sizeof(tAlumno),1,arch);
    while(!feof(arch))
    {
        printf("\n\n");
        imprimir_alumno(&alu);
        fread(&alu,sizeof(tAlumno),1,arch);
    }
}

void imprimir_archivo_ordenado(FILE * arch, tArbolBinBusq* pa)
{
    int cantReg,i=0;
    fseek(arch, 0L,SEEK_END);
    cantReg=ftell(arch)/sizeof(tAlumno);
    tAlumno vect[cantReg];
    fseek(arch,0L,SEEK_SET);
    fread(&vect[i],sizeof(tAlumno),1,arch);
    while(!feof(arch))
    {
        i++;
        fread(&vect[i],sizeof(tAlumno),1,arch);

    }
    burbuja(vect,cantReg);
    for(i=0;i<cantReg;i++)
    {
        imprimir_alumno(&vect[i]);
    }

}

void burbuja(tAlumno alu[], int n)
{
    int i, j;
    tAlumno aux;
    for(i=0;i<n-1;i++)
    {
         for(j=0;j<n-i-1;j++)
         {
             if(alu[j+1].dni<alu[j].dni)
            {
              aux=alu[j+1];
              alu[j+1]=alu[j];
              alu[j]=aux;
            }
         }
    }
}

int baja_ultimo (FILE * arch, tArbolBinBusq* pa)
{
    tAlumno alu;
    fseek(arch,-1L*(long)(sizeof(tAlumno)),SEEK_END);
    fread(&alu,sizeof(tAlumno),1,arch);
    printf("Eliminando:");
    imprimir_alumno(&alu);
    baja(&alu,arch,pa);

    return TODO_OK;
}

int compactar_y_reindexar(FILE ** arch, tArbolBinBusq * pindice, const char * path)
{
    tRegInd reg_ind;
    reg_ind.nro_reg=0;
    FILE *pfnue= fopen(PATH_ARCH_ALUMNOS_TMP,"wb");
    if(!pfnue) return 0;
    vaciarArbolBin_res(pindice);
    tAlumno alu;
    fseek(*arch,0,SEEK_SET);
    fread(&alu, sizeof(alu),1,*arch);
    while(!feof(*arch))
    {
        if(alu.estado=='A')
        {
            fwrite(&alu,sizeof(alu),1,pfnue);
            reg_ind.dni=alu.dni;
            insertarArbolBinBusq_res(pindice,&reg_ind,sizeof(reg_ind),cmp_dni);
            reg_ind.nro_reg++;
        }
        fread(&alu, sizeof(alu),1,*arch);
    }
    fclose(pfnue);
    fclose(*arch);
    remove(PATH_ARCH_ALUMNOS);
    rename(PATH_ARCH_ALUMNOS_TMP,PATH_ARCH_ALUMNOS);

    *arch=fopen(PATH_ARCH_ALUMNOS, "r+b");

    return *arch!=NULL;
}

