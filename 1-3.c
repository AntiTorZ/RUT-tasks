#include <math.h>
#include <stdio.h>
#include <locale.h>

/**
 * @brief рассчитывает сопротивление соединения
 * @param R1 сопротивление резистора 1
 * @param R2 сопротивление резистора 2
 * @param R3 сопротивление резистора 3
 * @return возвращает сопротивление соединения
 */
double getResistance(const double R1, const double R2, const double R3);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");

    double R1 = 0;
    double R2 = 0;
    double R3 = 0;

    printf("Введите сопротивление резистора 1: ");
    scanf_s("%lf", &R1);
    printf("Введите сопротивление резистора 2: ");
    scanf_s("%lf", &R2);
    printf("Введите сопротивление резистора 3: ");
    scanf_s("%lf", &R3);

    printf("Сопротивление соединения равно %.2lf\n", getResistance(R1, R2, R3));

    return 0;
}

double getResistance(const double R1, const double R2, const double R3)
{
    return (R1 * R2 * R3) / (R1 * R2 + R2 * R3 + R1 * R3);
}
