#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

/**
 * @brief рассчитывает периметр квадрата
 * @param side сторона квадрата
 * @return возвращает рассчитанный Периметр
 */
double getV(const double side);

double getS(const double side);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double R;
    scanf_s("%lf", &R);
    printf("V = %.2lf\n", getV(R));
    printf("S = %.2lf", getS(R));

    return 0;
}

double getV(const double R)
{
    return (4.0/3) * pow(R, 3) * M_PI;
}

double getS(const double R)
{
    return 4 * M_PI * pow(R, 2);
}
