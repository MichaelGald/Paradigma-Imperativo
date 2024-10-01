#include <stdio.h>
#include <math.h>  

//funcio para calcular raices
float misqrt(float numero){
	float precision = 0.00001;  
    float aproximacion = numero;  
    float mejorAproximacion;

    // Usamos el metodo de Newton-Raphson
    while (1) {
        mejorAproximacion = 0.5 * (aproximacion + numero / aproximacion);

        //buscamos la mejor aproximacion
        if (fabs(mejorAproximacion - aproximacion) < precision)
            break;

        aproximacion = mejorAproximacion;
    }
    return mejorAproximacion;
}

// Funcion para calcular las raices de una ecuacion cuadratica
void calcularRaices(float a, float b, float c) {
    float determinante;
	float raiz1;
	float raiz2;
	float parteReal;
	float parteImaginaria;

    determinante = b * b - 4 * a * c;

    //determinante mayor que 0 = dos raices reales
    if (determinante > 0) {
        raiz1 = (-b + misqrt(determinante)) / (2 * a);
        raiz2 = (-b - misqrt(determinante)) / (2 * a);
        printf("Las raices son reales y diferentes.\n");
        printf("Raiz 1 = %.2f\n", raiz1);
        printf("Raiz 2 = %.2f\n", raiz2);
    }
    // determinante igual a 0 = dos raices reales e iguales
    else if (determinante == 0) {
        raiz1 = -b / (2 * a);
        printf("Las raices son reales e iguales.\n");
        printf("Raiz 1 = %.2f\n", raiz1);
        printf("Raiz 2 = %.2f\n", raiz1);
    }
    // Caso 3: Discriminante menor que 0 -> raíces complejas
    else {
        parteReal = -b / (2 * a);
        parteImaginaria = misqrt(-determinante) / (2 * a);
        printf("Las raices son complejas e imaginarias.\n");
        printf("Raiz 1 = %.2f + %.2fi\n", parteReal, parteImaginaria);
        printf("Raiz 2 = %.2f - %.2fi\n", parteReal, parteImaginaria);
    }
}

int main() {
    float a;
	float b;
	float c;

    printf("Introduce el coeficiente a: ");
    scanf("%f", &a);
    printf("Introduce el coeficiente b: ");
    scanf("%f", &b);
    printf("Introduce el coeficiente c: ");
    scanf("%f", &c);

    // Si a es 0, no es una ecuacion cuadratica
    if (a == 0) {
        printf("El valor de 'a' no puede ser 0. No es una ecuacion cuadratica.\n");
    } else {
        calcularRaices(a, b, c);
    }

    return 0;
}

