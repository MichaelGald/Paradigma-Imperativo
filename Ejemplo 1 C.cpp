#include <stdio.h>

int main(void) {
    // Declaración de variables
    int codigo_articulo, cantidad_vendida, tipo_articulo;
    int contador_tipo1 = 0, contador_tipo2 = 0, contador_tipo3 = 0, tipo_mayor;
    float precio, importe, suma_tipo1 = 0, suma_tipo2 = 0, suma_tipo3 = 0;
    float promedio_tipo1 = 0, promedio_tipo2 = 0, promedio_tipo3 = 0;

    // Solicitar el código de artículo al usuario por primera vez
    printf("\nIngrese el codigo del articulo (-1 para finalizar): ");
    scanf("%d", &codigo_articulo);

    // Bucle que continua mientras el código del artículo no sea -1
    while (codigo_articulo != -1) {
        // Solicitar al usuario los datos de la venta
        printf("\nIngrese la cantidad vendida: ");
        scanf("%d", &cantidad_vendida);

        printf("\nIngrese el tipo de producto (1, 2 o 3): ");
        scanf("%d", &tipo_articulo);

        printf("\nIngrese el precio del articulo: ");
        scanf("%f", &precio);

        // Calcular el importe total de la venta
        importe = cantidad_vendida * precio;

        // Sumar los datos a las respectivas variables segun el tipo de artículo
        switch (tipo_articulo) {
            case 1:
                contador_tipo1++;
                suma_tipo1 += importe;
                break;
            case 2:
                contador_tipo2++;
                suma_tipo2 += importe;
                break;
            case 3:
                contador_tipo3++;
                suma_tipo3 += importe;
                break;
            default:
                printf("\nError: Tipo de articulo no valido.");
        }

        // Volver a solicitar el código de artículo para continuar o terminar
        printf("\nIngrese el codigo del articulo (-1 para finalizar): ");
        scanf("%d", &codigo_articulo);
    }

    // Calcular el promedio de ventas por tipo de artículo (si hubo ventas)
    if (contador_tipo1 > 0) {
        promedio_tipo1 = suma_tipo1 / contador_tipo1;
    }
    if (contador_tipo2 > 0) {
        promedio_tipo2 = suma_tipo2 / contador_tipo2;
    }
    if (contador_tipo3 > 0) {
        promedio_tipo3 = suma_tipo3 / contador_tipo3;
    }

    // Determinar que tipo de articulo tuvo mas ventas
    if (contador_tipo1 > contador_tipo2 && contador_tipo1 > contador_tipo3) {
        tipo_mayor = 1;
    } else if (contador_tipo2 > contador_tipo3) {
        tipo_mayor = 2;
    } else {
        tipo_mayor = 3;
    }

    // Mostrar los resultados al usuario
    printf("\n--- Resultados ---\n");
    printf("Tipo 1 - Total de ventas: %d, Importe total: %.2f, Promedio: %.2f\n", contador_tipo1, suma_tipo1, promedio_tipo1);
    printf("Tipo 2 - Total de ventas: %d, Importe total: %.2f, Promedio: %.2f\n", contador_tipo2, suma_tipo2, promedio_tipo2);
    printf("Tipo 3 - Total de ventas: %d, Importe total: %.2f, Promedio: %.2f\n", contador_tipo3, suma_tipo3, promedio_tipo3);
    printf("\nEl tipo de articulo con mayor cantidad de ventas es el tipo %d\n", tipo_mayor);

    return 0;
}

