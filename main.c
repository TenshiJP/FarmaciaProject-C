///Angel Roberto Jacinto Payes
///Carnet: 5990-20-1756
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//Utilize dos documentos.txt nombrados: informes.txt y medicina.txt
int menu();
int inventario();
void fecha_hora();
void LeerInforme();
void MontoLanzaprazol(int cantidad);
void MontoIbuprofen(int cantidad);
void MontoAceptaminofen(int cantidad);
void MontoBudena(int cantidad);
void MontoSalbutamol(int cantidad);

int trasaccion()
{
    int valor=0;
    printf("\nIngrese cantidad: ");
    scanf("%d",&valor);
    printf("\n");
    return valor;
}

int main()
{
    FILE *medicamentos;//Apuntador de Cantidades del Inventario
    FILE *archivo;//Apuntador de los Informes
    int medicamento[5];//Variables Invetrario Inicial.
    int opcion=0, medicina=0, cantidad=0, caja=0;//Variables extras.
    int nitProveedor[14];//Variables de Datos del cliente o Proveedor
    char nitCliente[14];
    char nombre_archivo[13]="informes.txt";//Archivo de texto donde se guardara información

    medicamentos = fopen("medicina.txt", "rt");//Leer valores iniciales de los Medicamentos
    fscanf (medicamentos,"%d",&medicamento[0]);//Lanzaprazol
    fscanf (medicamentos,"%d",&medicamento[1]);//Ibuprofen
    fscanf (medicamentos,"%d",&medicamento[2]);//Aceptaminofen
    fscanf (medicamentos,"%d",&medicamento[3]);//Budena
    fscanf (medicamentos,"%d",&medicamento[4]);//Salbutamol
    fclose(medicamentos);

    printf("\n****************************** EMILY DRUGSTORE I ******************************\n\n");
    do
    {
        caja=(((medicamento[0])*1)+((medicamento[1])*2)+((medicamento[2])*3)+((medicamento[3])*20)+((medicamento[4])*25));//Mantener Efectivo en Caja Actualizado
        printf("Dinero en Caja actual: Q. %d.00\n",caja);
        printf("Inventario Actual en Farmacia:\n\n|*Medicamento*| |*Cantidad*| |*Precio Q.*|\n| Lanzoprazol | |    %d    | |     1     |\n|  Ibuprofen  | |    %d    | |     2     |\n|Aceptaminofen| |    %d    | |     3     |\n|   Budena    | |    %d    | |     20    |\n| Salbutamol  | |    %d    | |     25    |\n\n",medicamento[0],medicamento[1],medicamento[2],medicamento[3],medicamento[4]);
       opcion=menu();
       switch (opcion)
       {
            case 1:
                printf("\n*** COMPRA DE MEDICAMENTO ***");//Algoritmo para aumentar Inventario
                printf("\nIngrese NIT: ");//Datos del Cliente, Proveedor
                archivo= fopen(nombre_archivo,"w+");//Guardar informe de transacción en informe.txt
                scanf("%s",&nitProveedor);
                fputs("\n*** Información de Compra ***\nNit del Proveedor: ",archivo);
                fwrite(nitProveedor, sizeof(unsigned char),strlen(nitProveedor),archivo);
                medicina=inventario();//Transacción
                   switch(medicina)
                    {
                    case 1:
                        cantidad=trasaccion();
                        medicamento[0]=(medicamento[0]+cantidad);
                        fputs("\nSe compro Lanzaprazol, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoLanzaprazol(cantidad);
                        break;
                    case 2:
                        cantidad=trasaccion();
                        medicamento[1]=(medicamento[1]+cantidad);
                        fputs("\nSe compro Ibuprofen, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoIbuprofen(cantidad);
                        break;
                    case 3:
                        cantidad=trasaccion();
                        medicamento[2]=(medicamento[2]+cantidad);
                        fputs("\nSe compro Aceptaminofen, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoAceptaminofen(cantidad);
                        break;
                    case 4:
                        cantidad=trasaccion();
                        medicamento[3]=(medicamento[3]+cantidad);
                        fputs("\nSe compro Budena, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoBudena(cantidad);
                        break;
                    case 5:
                        cantidad=trasaccion();
                        medicamento[4]=(medicamento[4]+cantidad);
                        fputs("\nSe compro Salbutamol, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoSalbutamol(cantidad);
                    }
                medicamentos = fopen("medicina.txt", "w");//Actualizar el Inventario
                fprintf(medicamentos,"%d\n",medicamento[0]);
                fprintf(medicamentos,"%d\n",medicamento[1]);
                fprintf(medicamentos,"%d\n",medicamento[2]);
                fprintf(medicamentos,"%d\n",medicamento[3]);
                fprintf(medicamentos,"%d\n",medicamento[4]);
                fclose(medicamentos);//Fin de aactualizar Inventario
                printf("\n********************* INFORME *********************\n");
                LeerInforme();
                printf("\n\n***************************************************\n\n\n");
                break;

            case 2:
                printf("\n*** VENTA DE MEDICAMENTO ***");//Algoritmo para disminuir Inventario
                printf("\nIngrese NIT: ");//Datos del Cliente
                archivo= fopen(nombre_archivo,"w+");//Guardar informe de transacción en informe.txt
                scanf("%s",&nitCliente);
                fputs("\n*** Información de Venta ***\nNit del Cliente: ",archivo);
                fwrite(nitCliente, sizeof(unsigned char),strlen(nitCliente),archivo);
                fclose(archivo);
                fecha_hora();
                archivo= fopen(nombre_archivo,"a");//Guardar más información
                medicina=inventario();//Transacción
                switch(medicina)
                    {
                    case 1:
                        cantidad=trasaccion();
                        medicamento[0]=(medicamento[0]-cantidad);
                        fputs("\nSe realizo la venta de Lanzaprazol, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoLanzaprazol(cantidad);
                        break;
                    case 2:
                        cantidad=trasaccion();
                        medicamento[1]=(medicamento[1]-cantidad);
                        fputs("\nSe realizo la venta de Ibuprofen, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoIbuprofen(cantidad);
                        break;
                    case 3:
                        cantidad=trasaccion();
                        medicamento[2]=(medicamento[2]-cantidad);
                        fputs("\nSe realizo la venta de Aceptaminofen, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoAceptaminofen(cantidad);
                        break;
                    case 4:
                        cantidad=trasaccion();
                        medicamento[3]=(medicamento[3]-cantidad);
                        fputs("\nSe realizo la venta de Budena, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoBudena(cantidad);
                        break;
                    case 5:
                        cantidad=trasaccion();
                        medicamento[4]=(medicamento[4]-cantidad);
                        fputs("\nSe realizo la venta de Salbutamol, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoSalbutamol(cantidad);
                    }
                medicamentos = fopen("medicina.txt", "w");//Actualizar el Inventario
                fprintf(medicamentos,"%d\n",medicamento[0]);
                fprintf(medicamentos,"%d\n",medicamento[1]);
                fprintf(medicamentos,"%d\n",medicamento[2]);
                fprintf(medicamentos,"%d\n",medicamento[3]);
                fprintf(medicamentos,"%d\n",medicamento[4]);
                fclose(medicamentos);//Fin de aactualizar Inventario
                printf("\n********************* INFORME *********************\n");
                LeerInforme();
                printf("\n\n***************************************************\n\n\n");
                break;

            case 3:
                printf("\n*** TRASLASDO DE MEDICAMENTO ***");//Algoritmo para disminuir Inventario
                archivo= fopen(nombre_archivo,"w+");//Guardar informe de transacción en informe.txt
                fputs("\n*** Información de Traslado ***\nSe traslado a EMILY DRUGSTORE II: ",archivo);
                fclose(archivo);
                fecha_hora();
                archivo= fopen(nombre_archivo,"a");//Guardar más información
                medicina=inventario();//Transacción
                switch(medicina)
                    {
                    case 1:
                        cantidad=trasaccion();
                        medicamento[0]=(medicamento[0]-cantidad);
                        fputs("\nSe traslado Lanzaprazol, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoLanzaprazol(cantidad);
                        break;
                    case 2:
                        cantidad=trasaccion();
                        medicamento[1]=(medicamento[1]-cantidad);
                        fputs("\nSe traslado Ibuprofen, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoIbuprofen(cantidad);
                        break;
                    case 3:
                        cantidad=trasaccion();
                        medicamento[2]=(medicamento[2]-cantidad);
                        fputs("\nSe traslado Aceptaminofen, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoAceptaminofen(cantidad);
                        break;
                    case 4:
                        cantidad=trasaccion();
                        medicamento[3]=(medicamento[3]-cantidad);
                        fputs("\nSe traslado Budena, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoBudena(cantidad);
                        break;
                    case 5:
                        cantidad=trasaccion();
                        medicamento[4]=(medicamento[4]-cantidad);
                        fputs("\nSe traslado Salbutamol, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        fclose(archivo);//Fin de Informe de transsacción
                        MontoSalbutamol(cantidad);
                    }
                medicamentos = fopen("medicina.txt", "w");//Actualizar el Inventario
                fprintf(medicamentos,"%d\n",medicamento[0]);
                fprintf(medicamentos,"%d\n",medicamento[1]);
                fprintf(medicamentos,"%d\n",medicamento[2]);
                fprintf(medicamentos,"%d\n",medicamento[3]);
                fprintf(medicamentos,"%d\n",medicamento[4]);
                fclose(medicamentos);//Fin de aactualizar Inventario
                printf("\n********************* INFORME *********************\n");
                LeerInforme();
                printf("\n\n***************************************************\n\n\n");
       }

    } while(opcion!=4);

    return 0;
}

//Menu
int menu()//Función para seleccionar el tipo de transacción a realizar en la farmacia.
{
    int opcion=0;
    printf("\n ****** MENU PRINCIPAL ***** \n\nIngrese el numero de la transaccion que desea realizar: \n 1. Compra de Medicina \n 2. Venta de Medicina \n 3. Traslados de Medicina \n 4. Salir\n* Opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

//Inventario
int inventario()//Funcion seleccionar un medicamento.
{
    int opcion=0;
    printf("\n\n***** INVENTARIO *****\n\nIngrese el numero del medicamento que desee:\n 1. Lanzoprazol\n 2. Ibuprofen\n 3. Aceptaminofen\n 4. Budena\n 5. Salbutamol\n * Opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
//Fecha y Hora
void fecha_hora ()//Función para llamar la fecha y hora actual del Equipo.
{
    FILE*archivo;
    char nombre_archivo[13]="informes.txt";
    archivo= fopen(nombre_archivo,"a");//Guardar la fecha en informes.txt
    time_t t = time(NULL); // Tiempo actual
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[40]; // Varible para la fecha y hora
    char *formato = "Fecha: %d-%m-%Y \nHora: %H:%M";//Formato que se mostrara los datos
    int pregunta = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);// Intentar formatear el tiempo
    if (pregunta != 0)//Pregunta por si surge Error.
    {
        fprintf(archivo,"\n%s",fechaHora);
        fclose(archivo);
    }
    else
    {
        fprintf(archivo,"\nError formateando fecha");
        fclose(archivo);
    }
}
//Leer Informe
void LeerInforme()//Funcion para leer Informe de la Transacción
{
    FILE*fp;
    int c;
    fp=fopen("informes.txt","r");
    while(1)
    {
        c= fgetc(fp);
        if ( feof(fp))
        {
            break;
        }
        printf("%c",c);
    }
    fclose(fp);
}
//Funciones para el Monto a Cancelar
void MontoLanzaprazol(int cantidad)
{
    FILE*archivo;
    char nombre_archivo[13]="informes.txt";
    archivo= fopen(nombre_archivo,"a");//Guardar Monto informes.txt
    cantidad=cantidad*1;
    fprintf(archivo,"\nCancelado: Q. %d.00",cantidad);
    fclose(archivo);
}
void MontoIbuprofen(int cantidad)
{
    FILE*archivo;
    char nombre_archivo[13]="informes.txt";
    archivo= fopen(nombre_archivo,"a");//Guardar Monto informes.txt
    cantidad=cantidad*2;
    fprintf(archivo,"\nCancelado: Q. %d.00",cantidad);
    fclose(archivo);
}
void MontoAceptaminofen(int cantidad)
{
    FILE*archivo;
    char nombre_archivo[13]="informes.txt";
    archivo= fopen(nombre_archivo,"a");//Guardar Monto informes.txt
    cantidad=cantidad*3;
    fprintf(archivo,"\nCancelado: Q. %d.00",cantidad);
    fclose(archivo);
}
void MontoBudena(int cantidad)
{
    FILE*archivo;
    char nombre_archivo[13]="informes.txt";
    archivo= fopen(nombre_archivo,"a");//Guardar Monto informes.txt
    cantidad=cantidad*20;
    fprintf(archivo,"\nCancelado: Q. %d.00",cantidad);
    fclose(archivo);
}
void MontoSalbutamol(int cantidad)
{
    FILE*archivo;
    char nombre_archivo[13]="informes.txt";
    archivo= fopen(nombre_archivo,"a");//Guardar Monto informes.txt
    cantidad=cantidad*25;
    fprintf(archivo,"\nCancelado: Q. %d.00",cantidad);
    fclose(archivo);
}
