#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>


/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double R1;
    double R2;
    double R3;

    printf("Value 1: ");
    scanf_s("%lf", &R1);
    printf("Value 2: ");
    scanf_s("%lf", &R2);
    printf("Value 3: ");
    scanf_s("%lf", &R3);

    printf("Result: ");
    printf("V = %.2lf\n", (R1*R2*R3)/(R1*R2 + R2*R3 + R1*R3));

    return 0;
}
