#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>

/**
 * @brief рассчитывает объём шара
 * @param R радиус шара
 * @return возвращает рассчитанный объём шара
 */
double getV(const double R);

/**
 * @brief рассчитывает площадь поверхности шара
 * @param R радиус шара
 * @return возвращает площадь поверхности шара
 */
double getS(const double R);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");

    double R = 0;
    printf("Введите радиус шара: ");
    scanf_s("%lf", &R);

    printf("V = %.2lf\n", getV(R));
    printf("S = %.2lf", getS(R));

    return 0;
}

double getV(const double R)
{
    return (4.0 / 3) * pow(R, 3) * M_PI;
}

double getS(const double R)
{
    return 4 * M_PI * pow(R, 2);
}
