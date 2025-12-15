#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

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
* @brief Проверяет лежит ли переменная в интервале [min;max]
* @param input - значение проверяемой переменной
*/
void checkValue(const int input, const int min, const int max);

/**
* @brief Создаёт новый массив согласно условию 1
* @param arr - массив
* @param size - размер массива
*/
void defForTask1(int* arr, const size_t size);

/**
* @brief Создаёт новый массив согласно условию 2
* @param arr - массив
* @param size - размер массива
*/
void defForTask2(const int* arr, const size_t size);

/**
* @brief Создаёт новый массив согласно условию 3
* @param arr - массив
* @param size - размер массива
*/
int* defForTask3(const int* arr, const size_t size);

/**
* @brief Находит последнее отрицательное значение
* @param arr - массив
* @param size - размер массива
* @return Возвращaет максимальный элемент массива
*/
int defLastNEGATIVE(const int* arr, const size_t size);

/**
* @brief Проверяет, чётность первой цифры в числе
* @param input - проверяемое число
* @return Возвращaет 1 или 0 в зависимости от верности условия
*/
bool findFirstEVEN(int input);

/**
* @brief Находит количество чисел массива, в которых первая цифра чётная
* @param arr - массив
* @param size - размер массива
* @return Возвращaет количество элементов, удовлетворяющих условию
*/
const int defCountEVEN(const int* arr, const size_t size);

/**
@brief CHOISE_ONE - первый выбор (Ручное заполнение массива)
@brief  CHOISE_TWO - второй выбор (Автоматическое заполнение массива)
@brief  TASK_ONE - выполнение первого задания
@brief  TASK_TWO - выполнение второго задания
@brief  TASK_THREE - выполнение третьего задания
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief Проверяет интервал на корректность ввода
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
* @brief Проверяет, удалось ли выделить память для массива
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
	printf("Числа массива будут в диапазоне [%d,%d]", min, max);

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

	int* AforTask3 = defForTask3(copyA, size);

	printf("\nКакие будут преобразования?\n%d - Заменить последний отрицательный элемент массива предпоследним элементом массива\n%d - Удалить из массива все элементы, первая цифра которых четная\n%d - 3.	Из элементов массива D сформировать массив A той же размерности по правилу: если номер четный, то значение элемента находится по формуле A[i] = pow(D[i],2), а если нечетный, то по формуле A[i] = 2 * D[i]\n", TASK_ONE, TASK_TWO, TASK_THREE);
	int second_choise = getValid();

	switch (second_choise)
	{
	case TASK_ONE:
		defForTask1(copyA, size);
		break;

	case TASK_TWO:
		defForTask2(copyA, size);
		break;

	case TASK_THREE:
		defPrintArr(AforTask3, size);
		break;

	default:
		fprintf(stderr, "Error");
		free(A);
		free(copyA);
		free(AforTask3);
		exit(1);
	}

	free(A);
	free(copyA);
	free(AforTask3);

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
		fprintf(stderr, "Error\nЧисло должно лежать в промежутке [%d;%d]", min, max);
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

	printf("\nМассив: \n");
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

void defForTask1(int* arr, const size_t size)
{
	check_pointer(arr);

	const int deflastnegative = defLastNEGATIVE(arr, size);
	const int prelastelement = arr[size - 2];

	printf("\nНовый массив: \n");
	arr[deflastnegative] = prelastelement;
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void defForTask2(const int* arr, const size_t size)
{
	check_pointer(arr);

	size_t newsize = size - defCountEVEN(arr, size);

	int* newarr = calloc(newsize, sizeof(int));
	check_pointer(newarr);

	size_t j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (j < newsize)
		{
			if (findFirstEVEN(arr[i]) == 0)
			{
				newarr[j++] = arr[i];
			}
		}
		else
		{
			fprintf(stderr, "Error");
			exit(1);
		}
	}

	defPrintArr(newarr, newsize);
	free(newarr);
}

int* defForTask3(const int* arr, const size_t size)
{
	check_pointer(arr);

	int* newarr = calloc(size, sizeof(int));
	check_pointer(newarr);

	for (size_t i = 0; i < size; i++)
	{

		if (arr[i] % 2 == 0)
		{
			newarr[i] = pow(arr[i], 2);
		}
		else
		{
			newarr[i] = 2 * arr[i];
		}
	}

	return newarr;
}

int defLastNEGATIVE(const int* arr, const size_t size)
{
	check_pointer(arr);

	for (size_t i = size - 1; i < size; i--)
	{
		if (arr[i] < 0)
		{
			return i;
		}
	}
	return 0;
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

bool findFirstEVEN(int input)
{
	input = abs(input);

	while (input >= 10)
	{
		input /= 10;
	}
	if (input % 2 == 0)
	{
		return 1;
	}
	return 0;
}

const int defCountEVEN(const int* arr, const size_t size)
{
	check_pointer(arr);

	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (findFirstEVEN(arr[i]) == 1)
		{
			count += 1;
		}
	}
	return count;
}

void check_pointer(const int* arr)
{
	if (arr == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}
}
