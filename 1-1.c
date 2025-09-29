#define _USE_MATH_DEFINES // for C
#include <math.h>
#include <stdio.h>

/**
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getB(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = 1.852;
    const double y = 18.225;
    const double z = -3.298;
    printf("A = %lf", getA(x, y, z));
    printf("B = %lf", getB(x, y, z));
    return 0;
}

double getB(const double x, const double y, const double z)
{
    return (y-x) + ((y-z)/(y-x))/(3 + pow(z,2)/5);
}

double getA(const double x, const double y, const double z)
{
    return pow(x, y/x) - pow(y/x, 1/3);
}
