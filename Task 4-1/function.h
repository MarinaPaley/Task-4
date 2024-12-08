/**
 * @brief Перечисление, определяющее способ заполнения массива элементами.
 */
enum fill
{
	/**
	* @brief Ручной. Элементы вводятся вручную с клавиатуры.
	*/
	manual,

	/**
	* @brief Автоматичесий. Элементы генерируются при помощи ГПСЧ из заданного диапазона значений.
	*/
	random
};

/**
* @brief Ввод целого числа.
* @param[in] message Сообщение.
* @remarks Экстренно завершает работу программу в случае неправильного ввода.
* @returns Возвращает целое число.
*/
int input(const char* message);

/**
* @brief Ввод размера массива.
* @param[in] message Сообщение.
* @remarks Экстренно завершает работу программу в случае неправильного ввода.
* @returns Возвращает размер массива.
*/
size_t input_size(const char* message);

/**
* @brief Ввод выбора пользователя относительно способа заполнения массива.
* @param[in] message Сообщение.
* @remarks Экстренно завершает работу программу в случае неправильного ввода.
* @returns Возвращает выбор пользователя относительно способа заполнения массива.
*/
enum fill input_choice(const char* message);

/**
* @brief Выделяет память под массив.
* @param[in] size Размер массива.
* @remarks Экстренно завершает работу программу в случае невозможности выделения памяти.
* @returns Возвращает указатель на массив.
*/
int* get_array(const size_t size);

/**
* @brief Проверяет, выделена ли память.
* @param[in] array Указатель на массив.
* @remarks Экстренно завершает работу программу в случае указателя \c NULL.
*/
void check_array(const int* const array);

/**
* @brief Печать массива.
* @param[in] array Указатель на массив.
* @param[in] size Размер массива.
* @param[in] message Сообщение.
* @remarks Экстренно завершает работу программу в случае указателя \c NULL.
*/
void print_array(const int* const array, const size_t size, const char* message);

/**
* @brief Заполняет массив с клавиатуры.
* @param[in] array Указатель на массив.
* @param[in] size Размер массива.
* @remarks Экстренно завершает работу программу в случае указателя \c NULL.
*/
void manual_fill(int* const array, const size_t size);

/**
* @brief Заполняет массив случайными числами.
* @param[in] array Указатель на массив.
* @param[in] size Размер массива.
* @remarks Экстренно завершает работу программу в случае указателя \c NULL.
*/
void random_fill(int* const array, const size_t size, const int min, const int max);

/**
* @brief Находит максимальный размер массива.
* @param[in] array Указатель на массив.
* @param[in] size Размер массива.
* @remarks Экстренно завершает работу программу в случае указателя \c NULL.
*/
int get_max(const int* const array, const size_t size);

/**
* @brief Выделяет память под массив.
* @param[in] array Указатель на оригинальный массив.
* @param[in] size Размер массива.
* @remarks Экстренно завершает работу программу в случае невозможности выделения памяти.
* @returns Возвращает указатель на скопированный массив массив.
*/
int* copy(const int* const array, const size_t size);

/**
* @brief Сортировка пузырьком.
* @param[in] array Указатель на массив.
* @param[in] size Размер массива.
* @remarks Экстренно завершает работу программу в случае указателя @c NULL.
*/
void bubble_sort(int* const array, const size_t size);

/**
* @brief Обмен значениями двух целых чисел.
* @param[in] lha Левый аргумент.
* @param[in] rha Правый аргумент.
*/
void swap(int* lha, int* rha);

/**
* @brief Строит сообщение в виде @c C строки по формату @p fmt и набору дополнительных аргументов.
* @param[in] fmt Форматная строка.
* @remarks ОСТОРОЖНО! ВНУТРИ ЧЁРНАЯ МАГИЯ И СТРАШНОЕ КОЛДУНСТВО!
* @returns Сформированное сообщение в виде @c C строки.
*/
char* make_message(const char* fmt, ...);

/**
* @brief Бинарный поиск
* @param[in] array Указатель на массив.
* @param[in] size Размер массива.
* @param[in] target Искомый элемент.
* @remarks Экстренно завершает работу программу в случае указателя @c NULL.
* @returns Индекс найденного эдемента.
* @remarks Если элемент не найден, возвращает индекс, больший размера массива.
*/
size_t binary_search(
	const int* const array,
	const size_t size,
	const int target);

/**
* @brief Бинарный поиск. Рекурсивная функция.
* @param[in] array Указатель на массив.
* @param[in] size Размер массива.
* @param[in] target Искомый элемент.
* @param[in] start Начальный индекс поиска.
* @param[in] finish Конечный индекс поиска.
* @returns Индекс найденного эдемента.
* @remarks Если элемент не найден, возвращает индекс, больший размера массива.
*/
size_t binary_search_inner(
	const int* const array,
	const size_t size,
	const int target,
	const size_t start,
	const size_t finish);

unsigned long long factorial_inner(int number, unsigned long long tail);
unsigned long long factorial(int number);
