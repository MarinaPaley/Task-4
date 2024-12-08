/**
* @brief Флаг, указывающий на необходимость дополнительной настройки локали пользователя.
* @remarks Стоит обратить внимание на флаги сборки/запуска для предзаданных констант @c -D
* @see https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html
*/
#define USE_LOCALE 0

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#if USE_LOCALE == 1
#include <locale.h>
#endif // USE_LOCALE

#include "function.h"

/**
* @brief Точка входа в программу.
* @return Код ошибки. @c 0 в случае правильного выполнения.
*/
int main(void)
{
	#if USE_LOCALE == 1
		setlocale(LC_ALL, "ru-RU");
	#endif // USE_LOCALE

	const size_t size = input_size("Введите размер массива");
	int* array = get_array(size);

	//const char* message = make_message(
	//	"Как Вы хотите заполнить массив?\n%d - ручной ввод, %d - случайный ввод\n",
	//	manual,
	//	random);

	printf_s("Как Вы хотите заполнить массив?\n%d - ручной ввод, %d - случайный ввод\n",
		manual,
		random);

	const enum fill choice = input_choice(NULL);
	switch (choice)
	{
		case manual:
		{
			manual_fill(array, size);
			break;
		}
		case random:
		{
			const int min = input("Введите минимальное значение массива");
			const int max = input("Введите максимальное значение массива");
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

	print_array(array, size, "Массив");

	printf_s("\nМаксимальный элемент массива %d\n", get_max(array, size));

	int* copy_array = copy(array, size);
	copy_array[0] = 100;
	print_array(copy_array, size, "Копия Массива");

	print_array(array, size, "\nМассив");

	bubble_sort(array, size);
	print_array(array, size, "\nОтсортированный Массив");

	int target = input("\nВведите элемен для поиска = ");
	size_t searched = binary_search(array, size, target);
	if (searched < size)
	{
		printf_s("\nЭлемент %d находится на позиции %zu", target, searched + 1);
	}
	else
	{
		printf_s("\nИскомый элемент %d не найден", target);
	}

	free(array);
	free(copy_array);

	return 0;
}
