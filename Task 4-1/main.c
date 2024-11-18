#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

enum fill
{
	manual,
	random
};

int input(const char* message);
size_t input_size(const char* message);
int* get_array(const size_t size);
void check_array(const int* const array);
void print_array(const int* const array, const size_t size);
void manual_fill(int* const array, const size_t size);
void random_fill(int* const array, const size_t size, const int min, const int max);
int get_max(const int* const array, const size_t size);
int* copy(const int* const array, const size_t size);

/**
* @brief Точка входа в программу.
* @return \0 в случае правильного выполнения.
*/
int main(void)
{
	setlocale(LC_ALL, "ru-RU");
	const size_t size = input_size("Введите размер массива");
	int* array = get_array(size);
	char message[100];// Некоторые костыли
	int result = sprintf(message, "Как Вы хотите заполнить массив?\n %d - ручной ввод, %d - случайный ввод",
		manual, random);
	const int choice = input(message);
	switch ((enum fill)choice)
	{
	case manual:
	{
		manual_fill(array, size);
		break;
	}
	case random:
	{
		int min = input("Введите минимальное значение массива");
		int max = input("Введите максимальное значение массива");
		if (min > max)
		{
			errno = ERANGE;
			perror("Неправильный диапазон");
			exit(1);
		}
		random_fill(array, size, min, max);
		break;
	}
	default:
	{
		errno = ERANGE;
		perror("Нет такого выбора");
		return 1;
	}
	}
	puts("Массив:");
	print_array(array, size);

	printf_s("\nМаксимальный элемент массива %d\n", get_max(array, size));

	int* copy_array = copy(array, size);
	puts("Копи Массив:");
	copy_array[0] = 100;
	print_array(copy_array, size);
	puts("\nМассив:");
	print_array(array, size);

	free(array);
	free(copy_array);
	return 0;
}

int input(const char* message)
{
	if (NULL != message)
	{
		puts(message);
	}
	int value = 0;
	int result = scanf_s("%d", &value);
	if (result != 1)
	{
		errno = EINVAL;
		perror("Неправильное число");
		exit(1);
	}

	return value;
}

size_t input_size(const char* message)
{
	int size = input(message);
	if (size <= 0)
	{
		errno = EDOM;
		perror("размер массива должен быть строго больше нуля");
		exit(1);
	}

	return (size_t)size;
}

int* get_array(const size_t size)
{
	int* array = (int*)malloc(size * sizeof(int));
	check_array(array);
	return array;
}

void print_array(const int* const array, const size_t size)
{
	check_array(array);
	printf_s("%s", "{ ");
	size_t i = 0;
	for (; i < size - 2; ++i)
	{
		printf_s("%d, ", array[i]);
	}
	printf_s("%d%s", array[i]," }");
}

void manual_fill(int* const array, const size_t size)
{
	char message[100];
	for (size_t i = 0; i < size - 1; ++i)
	{
		int result = sprintf(message, "Введите %zu - й элемент", i + 1);
		array[i] = input(message);
	}
}

void random_fill(int* const array, const size_t size, const int min, const int max)
{
	srand(time(NULL));
	for (size_t i = 0; i < size - 1; ++i)
	{
		array[i] = rand() % (max - min + 1) + min;
	}
}

int get_max(const int* const array, const size_t size)
{
	check_array(array);
	int max = array[0];
	for (size_t i = 1; i < size - 1; ++i)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}

	return max;
}

int* copy(const int* const array, const size_t size)
{
	check_array(array);
	int* copy_array = get_array(size);

	for (size_t i = 1; i < size - 1; ++i)
	{
		copy_array[i] = array[i];
	}

	return copy_array;
}

void check_array(const int* const array)
{
	if (NULL == array)
	{
		errno = ENOMEM;
		perror("Не выделена память");
		exit(1);
	}
}
