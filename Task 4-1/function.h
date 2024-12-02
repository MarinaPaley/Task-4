enum fill
{
	manual,
	random
};

int input(const char* message);
size_t input_size(const char* message);
int* get_array(const size_t size);
void check_array(const int* const array);
void print_array(const int* const array, const size_t size, const char* message);
void manual_fill(int* const array, const size_t size);
void random_fill(int* const array, const size_t size, const int min, const int max);
int get_max(const int* const array, const size_t size);
int* copy(const int* const array, const size_t size);
void bubble_sort(int* const array, const size_t size);
void swap(int* lha, int* rha);
