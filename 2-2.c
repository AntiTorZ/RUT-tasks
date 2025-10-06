#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/**
 * @brief рассчитывает значение функции
 * @param a значение переменной a
 * @param x значение переменной x
 * @return возвращает значение функции
 */
double func1(const double a, const double x);

/**
 * @brief рассчитывает значение функции
 * @param a значение переменной a
 * @param x значение переменной x
 * @return возвращает значение функции
 */
double func2(const double a, const double x);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");

    const double a = 2.8;

    printf("Введите значение переменной x: ");
    double x = getValue();

    if (x < 1.2)
    {
        printf("Значение функции равно %.2lf\n", func1(a, x));
    }
    else
    {
        printf("Значение функции равно %.2lf\n", func2(a, x));
    }

    return 0;
}

double func1(const double a, const double x)
{
    return a * pow(x, 2) + 4;
}

double func2(const double a, const double x)
{
    return (a + 4 * x) * pow(pow(x, 2 * a), 0.5);
}

double getValue()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}
