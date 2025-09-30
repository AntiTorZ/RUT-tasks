#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief рассчитывает значение функции
 * @param a значение переменной a
 * @param x значение переменной x
 * @return возвращает значение функции
 */
double getFunc(const double a, const double x);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double a, const double x);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    printf("Введите значение переменной a: ");
    double a = getValue();
    printf("Введите значение переменной x больше 1.2: ");
    double x = getValue();
    checkValue(a, x);
    printf("Значение функции y равно %.2lf\n",getFunc(a, x));

    return 0;
}

double getFunc(const double a, const double x)
{
    return a*pow(x,2) + 4;
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double a, const double x)
{
    if (x < 1.2 )
    {
        printf("Нет решений\n");
        abort();
    }
    if (x >= 1.2 * (a + 4 * x))
    {
        printf("Нет решений\n");
        abort();
    }
}
