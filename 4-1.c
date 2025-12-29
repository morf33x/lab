#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/**
* @btief ввод числа и проверка правильности типа
* @return введенное число
*/
int getInt();
/**
* @brief ввод размера массива
* @param сообщение о необходимости размера массива
* @return размер массива
*/
size_t getSize(const char* message);
/**
 * @brief cчитывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);
/**
 * @brief заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);
/**
 * @brief создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);
/**
 * @brief cыводит массив
 * @param arr массив
 * @param size размер массива
 */
void printArray(const int* arr, const size_t size);
/**
* @brief выводит есть ли в массиве пары чисел с одни знаком
* @param arr массив
* @param size размер массива
*/
void PlusMinus(const int* arr, const size_t size);
/**
* @brief выводит индексы элементов массива которые больше предыдущих
* @param arr массив
* @param size размер массива
*/
void printindex(const int* arr, const size_t size);
/**
* @brief меняет средний элемент массива на минимальный
* @param arr массив
* @param size размер массива
*/
void changeMinToAvg(int* arr, const size_t size);
/**
* @brief сортирует массив
* @param arr массив
* @param size размер массива
*/
void sortArry(int* arr, const size_t size);
/**
* @brief создает пустой массив ненулевого размера
* @param size размер массива
* @return созданный массив
*/
int* makeArr(const size_t size);
/**
* @param RANDOM случайное запрлнение массива
* @param MMANUAL заполнение массива вручную
*/
enum { RANDOM = 1, MANUAL };
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main() {
	setlocale(LC_ALL, "rus");
	printf("Выберите тип заполнения массива:\n%d - случайное\n%d - вручную\n", RANDOM, MANUAL);
	const int choise = getInt();
	size_t size = getSize("Введите размер массива\n");
	int* arr = makeArr(size);
	switch (choise) {
	case RANDOM:
		fillRandom(arr, size);
		break;
	case MANUAL:
		fillArray(arr, size);
		break;
	default:
		printf("Error");
		exit(1);
	}
	int* copy = copyArray(arr, size);
	changeMinToAvg(copy, size);
	printindex(copy, size);
	PlusMinus(copy, size);
	free(arr);
	free(copy);
	return 0;
}
int* makeArr(const size_t size) {
	int* arr = malloc(size * sizeof(int));
	if (arr == NULL) {
		printf("Error");
		exit(1);
	}
	return arr;
}

void sortArry(int* arr, const size_t size)
{
	if (arr == NULL) {
		printf("Error");
		exit(1);
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void printindex(int* arr, const size_t size) {
	if (arr == NULL) {
		printf("Error");
		exit(1);
	}
	printf("Индексы элементов значения у которых больше предыдущих: ");
	for (size_t i = 1; i < size; i++) {
		if (arr[i] > arr[i - 1]) {
			printf("%d ", i);
		}
	}
	printf("\n");
}
void PlusMinus(int* arr, const size_t size) {
	if (arr == NULL) {
		printf("Error");
		exit(1);
	}
	for (size_t i = 0; i < size - 1; i++) {
		if (arr[i] > 0 && arr[i + 1] > 0 || arr[i] == 0 && arr[i + 1] == 0 || arr[i] < 0 && arr[i + 1] < 0) {
			printf("В массиве есть пары рядомстоящих чисел с одинаковым знаком");
			return;
		}
	}
	printf("В массиве нет пар рядомстоящих чисел с одинаковым знаком");
}
void changeMinToAvg(int* arr, const size_t size) {
	int* copy1 = copyArray(arr, size);
	sortArry(copy1, size);
	const int Min = copy1[0];
	const int avg = copy1[size / 2];
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == Min) {
			arr[i] = avg;
			break;
		}
	}
	printf("Массив с замененым минимальным элементом на средний\n");
	printArray(arr, size);
	free(copy1);
}
size_t getSize(char* message) {
	printf("%s", message);
	int size = 0;
	scanf_s("%d", &size);
	if (size <= 0) {
		printf("error");
		abort();
	}
	return (size_t)size;
}
void fillRandom(int* arr, const size_t size) {
	printf("Ведите начало и конец диапозона\n");
	const int start = getInt();
	const int end = getInt();
	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % (end - start) + start;
	}
	printf("\n Массив:\n");
	printArray(arr, size);
}
int getInt() {
	int value = 0;
	if (!scanf_s("%d", &value)) {
		printf("error");
		abort();
	}
	return value;
}
int* copyArray(const int* arr, const size_t size)
{
	if (arr == NULL) {
		printf("Error");
		exit(1);
	}
	int* copyArr = makeArr(size);
	for (size_t i = 0; i < size; i++)
	{
		copyArr[i] = arr[i];
	}
	return copyArr;
}
void printArray(const int* arr, const size_t size)
{
	if (arr == NULL) {
		printf("Error");
		exit(1);
	}
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n ");
}
void fillArray(int* arr, size_t size) {
	if (arr == NULL) {
		printf("Error");
		exit(1);
	}
	for (size_t i = 0; i < size; i++) {
		printf("Введите %d-й эелемент массива", i);
		arr[i] = getInt();
	}
}
