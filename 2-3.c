#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
void checkValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    printf("Введите число 1: ");
    double number1 = getValue();
    checkValue(number1);
    printf("Введите число 2: ");
    double number2 = getValue();
    checkValue(number2);
    printf("Введите число 3: ");
    double number3 = getValue();
    checkValue(number3);
    
    printf("1 число равно %.2lf\n", number1);
    printf("2 число равно %.2lf\n", number2);
    printf("3 число равно %.2lf\n", number3);

    return 0;
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Error\n");
        abort();
    }
    if (value >= 0)
    {
        value = pow(value, 2);
    }
    else
    {
        value = pow(value, 4);
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Value have to be positive\n");
        abort();
    }
}
