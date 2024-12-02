#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"

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

void print_array(
	const int* const array,
	const size_t size,
	const char* message)
{
	check_array(array);

	if (NULL != message)
	{
		printf_s("%s: ", message);
	}

	puts("{ ");

	size_t i = 0;
	for (; i < size - 1; ++i)
	{
		printf_s("%d, ", array[i]);
	}

	printf_s("%d%s", array[i], " }");
}

void manual_fill(int* const array, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		printf_s("Введите %zu-й элемент ", i + 1);
		array[i] = input(NULL);
	}
}

void random_fill(int* const array, const size_t size, const int min, const int max)
{
	srand((unsigned int)time((time_t*)NULL));
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = rand() % (max - min + 1) + min;
	}
}

int get_max(const int* const array, const size_t size)
{
	check_array(array);
	int max = array[0];
	for (size_t i = 1; i < size; ++i)
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

	for (size_t i = 0; i < size; ++i)
	{
		copy_array[i] = array[i];
	}

	return copy_array;
}

void bubble_sort(int* const array, const size_t size)
{
	check_array(array);

	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = i + 1; j < size; ++j)
		{
			if (array[i] < array[j])
			{
				swap(&array[i], &array[j]);
			}
		}
	}
}

void swap(int* lha, int* rha)
{
	int temp = *lha;
	*lha = *rha;
	*rha = temp;
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
