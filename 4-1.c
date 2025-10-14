#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int getValue();

int modMassive(const int n, const char choice);
 
/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void) {
    printf("Введите размер массива: ");
    int n = getValue();
    
    
    printf("Заполнение массива случайно - N/по вашему желанию - Y: ");
    char choice = 'N';
    choice = scanf("%s", &choice);
    int arr = modMassive(n, choice);
    return 0;
}

int getValue()
{
    int value = 0;
    if (!scanf("%if",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

int modMassive(const int n, const char choice)
{
    int arr[1] = {0};
    if (choice == 'N')
    {
        
    }
    else
    {
        
    }
    return 0;
}
