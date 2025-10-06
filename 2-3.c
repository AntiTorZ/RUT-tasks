#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет, что переменная отрицательная или положительная
 * и возводит её в степень
 * @param value значение переменной
 */
double transformValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{

    double modNumber1;
    double modNumber2;
    double modNumber3;

    setlocale(LC_ALL, "Russian");

    printf("Введите число 1: ");
    double number1 = getValue();

    printf("Введите число 2: ");
    double number2 = getValue();

    printf("Введите число 3: ");
    double number3 = getValue();

    modNumber1 = transformValue(number1);
    modNumber2 = transformValue(number2);
    modNumber3 = transformValue(number3);

    printf("Число 1 равно % .2lf\n", modNumber1);
    printf("Число 2 равно %.2lf\n", modNumber2);
    printf("Число 3 равно %.2lf\n", modNumber3);

    return 0;
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

double transformValue(const double value)
{
    if (value >= 0)
    {
        return pow(value, 2);
    }
    else
    {
        return pow(value, 4);
    }
}
