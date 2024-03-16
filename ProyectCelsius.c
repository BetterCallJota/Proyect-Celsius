#include <stdio.h>

float calcularPromedio(float temp1, float temp2, float temp3) {
    return (temp1 + temp2 + temp3) / 3;
}

int main() {
    int n, i;
    char fecha[11];
    float temp_manana, temp_tarde, temp_noche;

    // Registro de temperaturas
    FILE *file = fopen("registro_temperaturas.txt", "w");

    if (file) {
        printf("Ingrese la cantidad de dias a registrar: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            printf("Ingrese la fecha (DD/MM/AAAA): ");//Colocar solo numeros
            scanf("%s", fecha);
            printf("Temperatura de la manana: ");
            scanf("%f", &temp_manana);
            printf("Temperatura de la tarde: ");
            scanf("%f", &temp_tarde);
            printf("Temperatura de la noche: ");
            scanf("%f", &temp_noche);

            fprintf(file, "%s %f %f %f\n", fecha, temp_manana, temp_tarde, temp_noche);
        }

            } else {
        printf("No se pudo abrir el archivo para escritura.");
    }

    // Mostrar registros
    file = fopen("registro_temperaturas.txt", "r");
    char c;

    if (file) {
        printf("\nRegistros de temperaturas:\n");
        while ((c = getc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    } else {
        printf("No se pudo abrir el archivo para lectura.");
    }

    // Calcular promedio
    float promedio = calcularPromedio(temp_manana, temp_tarde, temp_noche);
    printf("\nEl promedio de temperaturas es: %.2f\n", promedio);

    return 0;
}


