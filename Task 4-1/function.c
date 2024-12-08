#include <errno.h>
#include <stdarg.h>
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
		perror("Размер массива должен быть строго больше нуля");
		exit(1);
	}

	return (size_t)size;
}

enum fill input_choice(const char* message)
{
	const int choice = input(message);
	return ((enum fill)choice);
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

	printf_s("{ ");

	size_t i = 0;
	for (; i < size - 1; ++i)
	{
		printf_s("%d, ", array[i]);
	}

	printf_s("%d }", array[i]);
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
			if (array[i] > array[j])
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

char* make_message(const char* fmt, ...)
{
	va_list args1;
	va_start(args1, fmt);
	va_list args2;
	va_copy(args2, args1);
	const int need_size = 1 + snprintf(NULL, 0, fmt, args1);
	char* buffer = (char*)malloc(need_size);
	va_end(args1);
	vsnprintf(buffer, need_size, fmt, args2);
	va_end(args2);
	return buffer;
}

size_t binary_search(
	const int* const array,
	const size_t size,
	const int target)
{
	check_array(array);
	size_t start = 0;
	size_t finish = size;
	return binary_search_inner(array, size, target, start, finish);
}

size_t binary_search_inner(
	const int* const array,
	const size_t size,
	const int target,
	const size_t start,
	const size_t finish)
{
	if (start >= finish)
	{
		return size;
	}

	size_t index = (start + finish) / 2;

	if (target < array[index])
	{
		return binary_search_inner(array, size, target, start, index - 1);
	}

	if (target > array[index])
	{
		return binary_search_inner(array, size, target, index + 1, finish);
	}

	return index;
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

unsigned long long factorial(int number)
{
	return factorial_inner(number, 1ULL);
}

unsigned long long factorial_inner(int number, unsigned long long tail)
{
	if (number < 2)
	{
		return tail;
	}

	return factorial_inner(number - 1, tail * number);
}
