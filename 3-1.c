#define _USE_MATH_DEFINES // for C
#include <math.h>
#include <stdio.h>

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double min_x = 0.4;
    const double max_x = 1;
    const double step_x = 0.05;

    printf("x           f(x)\n");
    for (double x = min_x; x < max_x; x += step_x)
    {
        const double result = x + pow(x, 0.5) + pow(x, 1.0 / 3) - 2.5;
        printf("%.2lf       ", x);
        printf("%.2lf\n", result);
    }

    return 0;
}
