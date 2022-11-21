#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pbin, *ptxt; //puntero a binario y puntero a texto
    //de fijo a binario
    crea_textoF();
    muestra_textoF();

    ptxt = fopen("archivo_textoFijo.txt","rt");
    pbin = fopen("archivo_binario.bin","wb");


    if(!pbin || !ptxt)
    {
        printf("Error de archivo\n");
        return 1;
    }

    textoFijoABinario(ptxt,pbin);
    return 0;
}
