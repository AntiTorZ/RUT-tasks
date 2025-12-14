#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
int getValid();

/**
* @brief Проверяет что переменная не меньше единицы
* @param input - значение проверяемой переменной
*/
void checkValueForN(const int input);

/**
* @brief Проверяет, лежит ли чсило в указанном диапазоне
* @param input - значение проверяемой переменной
*/
void checkValue(const int input, const int min, const int max);

/**
* @brief Считает сумму согласно условию №1
* @param arr - массив
* @param size - размер массива
* @return Посчитанное значение
*/
int defForTask1(const int* arr, const size_t size);

/**
* @brief Находит индексы согласно условию №2
* @param arr - массив
* @param size - размер массива
*/
int defForTask2(const int* arr, const size_t size);

/**
* @brief Создаёт новый массив согласно условию №3
* @param arr - массив
* @param size - размер массива
*/
void defForTask3(int* arr, const size_t size);

/**
* @brief Находит первый элемент массива отличный от 0
* @param arr - массив
* @param size - размер массива
* @return Возвращaет первый элемент массива отличный от 0
*/
int defFIRST(const int* arr, const size_t size);

/**
@brief CHOISE_ONE - первый выбор (Ручное заполнение массива)
@brief  CHOISE_TWO - второй выбор (Автоматическое заполнение массива)
@brief  TASK_ONE - выполнение первого задания
@brief  TASK_TWO - выполнение второго задания
@brief  TASK_THREE - выполнение третьего задания
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief Проверяет диапазон на корректност ввода
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void defCheckMinMax(const int min, const int max);

/**
* @brief Заполняет массив элементами, который пользователь вводит с клавиатуры, c учётом максимально и минимально возможного
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getManual(int* arr, const size_t size, const int min, const int max);

/**
* @brief Заполняет массив случайнами элементами, c учётом максимально и минимально возможного
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getRandom(int* arr, const size_t size, const int min, const int max);

/**
* @brief Выводит все элементы массива на экран
* @param arr - массив
* @param size - размер массива
*/
void defPrintArr(const int* arr, const size_t size);

/**
* @brief Копирует все элементы массива в новый
* @param arr - массив
* @param size - размер массива
* @return Новый массив, идентичный старому
*/
int* defcopyArr(const int* arr, const size_t size);


/**
* @brief Проверят корректно ли выделана память под массив
* @param arr - массив
*/
void check_pointer(const int* arr);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите размер массива: ");
	size_t size = (size_t)getValid();
	checkValueForN(size);

	int* A = calloc(size, sizeof(int));
	check_pointer(A);

	printf("Введите диапазон, в котором будут задаваться числа массива: \n");
	const int min = getValid();
	const int max = getValid();
	defCheckMinMax(min, max);
	printf("Числа массива будут задаваться в диапазоне [%d,%d]\n", min, max);

	printf("\nКак будет заполнен массив?\n %d - Ручной ввод\n %d - Автоматический ввод\n", CHOISE_ONE, CHOISE_TWO);
	int choise = getValid();

	switch (choise)
	{
	case CHOISE_ONE:
		getManual(A, size, min, max);
		break;

	case CHOISE_TWO:
		getRandom(A, size, min, max);
		break;

	default:
		fprintf(stderr, "Error");
		free(A);
		exit(1);
	}

	defPrintArr(A, size);
	int* copyA = defcopyArr(A, size);
	check_pointer(copyA);

	printf("\nКакие будут преобразования?\n%d - Найти сумму элементов, имеющих нечётные индексы\n%d - Подсчитать количество элементов массива, значения которых больше заданного числа А и кратных 5\n%d - Разделить все элементы массива с четными номерами на первый элемент (первый элемент отличен от 0)\n", TASK_ONE, TASK_TWO, TASK_THREE);
	int second_choise = getValid();

	switch (second_choise)
	{
	case TASK_ONE:
		printf("\nСумма чётных отрицательных элементов = %d\n", defForTask1(copyA, size));
		break;

	case TASK_TWO:
		printf("\nКол-во элементов кратных 5 и больше A = %d\n", defForTask2(copyA, size));
		break;

	case TASK_THREE:
		printf("\nНовый массив: \n");
		defForTask3(copyA, size);
		break;

	default:
		fprintf(stderr, "Error");
		free(A);
		free(copyA);
		exit(1);
	}

	free(A);
	free(copyA);

	return 0;
}

int getValid()
{
	int valid = 0;
	if (!scanf_s("%d", &valid))
	{
		fprintf(stderr, "Error");
		exit(1);
	}
	return valid;
}

void checkValue(const int input, const int min, const int max)
{
	if (input > max || input < min)
	{
		fprintf(stderr, "Error\n Число должно лежать в промежутке [%d;%d]", min, max);
		exit(1);
	}
}

void getManual(int* arr, const size_t size, const int min, const int max)
{
	check_pointer(arr);

	printf("\nВведи %zu элемент-а(ов) массива:\n", size);
	for (size_t i = 0; i < size; i++)
	{
		int num = getValid();
		checkValue(num, min, max);
		printf("A[%zu] = %d\n", i, num);
		arr[i] = num;
	}
}

void defCheckMinMax(const int min, const int max)
{
	if (min >= max)
	{
		fprintf(stderr, "Error\n Неправильно указан диапазон");
		exit(1);
	}
}

void getRandom(int* arr, const size_t size, const int min, const int max)
{
	check_pointer(arr);
	srand(time(NULL));

	for (size_t i = 0; i < size; i++)
	{
		int numm = (rand() % (max - min + 1)) + min;
		arr[i] = numm;
	}
}

void defPrintArr(const int* arr, const size_t size)
{
	check_pointer(arr);

	printf("\nВведённый массив: \n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void checkValueForN(const int input)
{
	if (input < 1)
	{
		fprintf(stderr, "Error\nЧисло должно быть не меньше 1");
		exit(1);
	}
}

int defForTask1(const int* arr, const size_t size)
{
	check_pointer(arr);

	int summ = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i % 2 != 0)
		{
			summ += arr[i];
		}
	}
	return summ;
}

int defForTask2(const int* arr, const size_t size)
{
	check_pointer(arr);
	int count = 0;
	printf("\nВведите число A: ");
	const int A = getValid();

	for (size_t i = 0; i < size; i++)
	{
		if ((arr[i] % 5 == 0) && (arr[i] > A))
		{
			count++;
		}
	}
	return count;
}

int* defcopyArr(const int* arr, const size_t size)
{
	check_pointer(arr);

	int* copyArr = calloc(size, sizeof(int));
	check_pointer(copyArr);
	for (size_t i = 0; i < size; i++)
	{
		copyArr[i] = arr[i];
	}
	return copyArr;
}

int defFIRST(const int* arr, const size_t size)
{
	check_pointer(arr);

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			return arr[i];
		}
	}
}

void defForTask3(int* arr, const size_t size)
{
	float* result = malloc(size * sizeof(float));
	check_pointer(result);
	for (size_t i = 0; i < size; i++)
	{
		result[i] = (float)arr[i];
	}

	const int def_first = defFIRST(arr, size);

	for (size_t i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			result[i] = result[i] / (float)def_first;
		}

		printf("%.2f\n", result[i]);
	}

}

void check_pointer(const int* arr)
{
	if (arr == NULL)
	{
		fprintf(stderr, "Memory Error\n");
		exit(1);
	}
}
