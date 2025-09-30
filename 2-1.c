#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief рассчитывает площадь трапеции
 * @param side1 первая сторона трапеции
 * @param side2 вторая сторона трапеции
 * @param height высота трапеции
 * @return возвращает рассчитанную площадь
 */
double getS_Trapezoid(const double side1, const double side2, const double height);


/**
 * @brief рассчитывает площадь круга
 * @param radius радиус круга
 * @return возвращает рассчитанную площадь
 */
double getS_Circle(const double radius);

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
    printf("Введите сторону 1 трапеции: ");
    double side1 = getValue();
    checkValue(side1);
    printf("Введите сторону 2 трапеции: ");
    double side2 = getValue();
    checkValue(side2);
    printf("Введите высоту трапеции: ");
    double height = getValue();
    checkValue(height);
    
    printf("Введите радиус круга: ");
    double radius = getValue();
    checkValue(radius);
    
    printf("Площадь трапеции равна %.2lf\n", getS_Trapezoid(side1, side2, height));
    printf("Площадь круга равна %.2lf\n", getS_Circle(radius));

    return 0;
}

double getS_Trapezoid(const double side1, const double side2, const double height)
{
    return 0.5 * (side1 + side2) * height;
}

double getS_Circle(const double radius)
{
    return M_PI * pow(radius, 2);
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

void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Value have to be positive\n");
        abort();
    }
}
