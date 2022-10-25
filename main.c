#include <stdio.h>
#include <stdlib.h>
#include "modelo.h"

int main()
{
    FILE *arch_stock, *arch_pedidos, *arch_noprocesados;
    t_stock stock; //binario
    t_pedidos pedido; //texto
    t_prod_ped product_pedido;
    int leer,noStock=1,ped;
    tCola pc;
    crearCola(&pc);
    crearArchivoStock(arch_stock);
    arch_stock=fopen("productos.dat", "a+b");
    arch_pedidos=fopen("pedidos.txt","rt");
    arch_noprocesados=fopen("noProcesados.txt","wt");
    if(!arch_stock) return 0;
    if(!arch_pedidos)
    {
        fclose(arch_stock);
        return 0;
    }
    if(!arch_noprocesados)
    {
        fclose(arch_stock);
        fclose(arch_pedidos);
        return 0;
    }
    fread(&stock,sizeof(t_stock),1,arch_stock);
    leer=leerArchivoPedidos(arch_pedidos,&pedido);

    while(leer)
    {
        ped=pedido.nroPedido;
        noStock=1;
        while(leer && pedido.nroPedido==ped && !feof(arch_stock))
        {
            ped=pedido.nroPedido;
            if(stock.codProd==pedido.codProd)
            {
                product_pedido.ped= pedido;
                product_pedido.prod= stock;
                if(stock.stock<=pedido.cantPedida)
                {
                    noStock=0;
                }
                ponerEnCola(&pc, &product_pedido, sizeof(t_prod_ped));
            }
            else
            {
                fread(&stock,sizeof(t_stock),1,arch_stock);
            }
        }
        if(noStock)
        {
            sacarDeCola(&pc,&product_pedido,sizeof(t_prod_ped));
            fseek(arch_stock,sizeof(t_stock),SEEK_SET);
            product_pedido.prod.stock-=product_pedido.ped.cantPedida;
            fwrite(&product_pedido.prod, sizeof(t_stock), 1, arch_stock);
        }else{
            while(sacarDeCola(&pc,&product_pedido,sizeof(t_prod_ped)))
            {
                fprintf(arch_noprocesados, "Pedido %d con faltantes: ", ped);
                fprintf(arch_noprocesados, "%d - %s : %d %d %c",product_pedido.ped.codProd,product_pedido.prod.descrpcion,product_pedido.prod.stock,
                product_pedido.ped.cantPedida,product_pedido.prod.stock< product_pedido.ped.cantPedida? 'F' :' ');
            }
        }
        leer=leerArchivoPedidos(arch_pedidos,&pedido);
    }
    fclose(arch_stock);
    fclose(arch_pedidos);
    fclose(arch_noprocesados);


    return 0;
}
