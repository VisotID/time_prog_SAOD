// Высоцкая И.Д.
#include "Time.h" // подключение заголовочного файла модуля
#include <cassert>

// тестирование функции сортировки массива
void test_for_is_sort()
{
	// отсортированные массивы
	int arr1_s[] = { 1, 2, 3, 4, 5 };
	double arr2_s[] = { 1.1, 1.2, 1.3, 1.4, 2.5 };
	int arr3_s[] = { 200 };
	int* arr4_s = nullptr;
	assert(Arr_is_sort(5, arr1_s) == true);
	assert(Arr_is_sort(5, arr2_s) == true);
	assert(Arr_is_sort(1, arr3_s) == true);
	assert(Arr_is_sort(0, arr4_s) == true);

	// не отсортированные массивы
	int arr1_us[] = { 5, 6, 4, 1, 9 };
	double arr2_us[] = { 2.5, 1.4, 1.3, 1.2, 1.1 };
	int arr3_us[] = { 5, 5, 5, 4, 5 };
	double arr4_us[] = { -1.3, -3.7, 0.1, 6.9 };
	assert(Arr_is_sort(5, arr1_us) == false);
	assert(Arr_is_sort(5, arr2_us) == false);
	assert(Arr_is_sort(5, arr3_us) == false);
	assert(Arr_is_sort(4, arr4_us) == false);

	// массив с одинаковыми элементами
	int arr_w_sim_el[] = { 1, 1, 1, 1, 1 };
	assert(Arr_is_sort(5, arr_w_sim_el) == true);

	// массив с соседними одинаковыми элементами
	int arr_w_dub_el[] = { 1, 1, 4, 4, 5 };
	assert(Arr_is_sort(5, arr_w_dub_el) == true);
}

// тестирование функции нахождения элемента в массиве
void test_for_find_pos()
{
	int arr1[] = { 10, 20, 60, 30, 5000, 40 };

	int arr2[] = { 100 };

	size_t n1 = 6;

	assert(Arr_elem(n1, arr1, 30) == 4);

	assert(Arr_elem(n1, arr1, 40) == 6);

	assert(Arr_elem(n1, arr1, 10) == 1);

	assert(Arr_elem(n1, arr1, 2) == 0);

	assert(Arr_elem(n1, arr1, 2000) == 0);

	assert(Arr_elem(1, arr2, 100) == 1);

	assert(Arr_elem(1, arr2, 200) == 0);

}

// тестирование функций бинарного и итерационного поиска элемента в массиве
void test_for_byn_iter_find()
{
	int arr1_sort[] = { 5, 6, 9, 10, 100, 500, 5000, 80000 };
	size_t n1 = 8;
	int arr_w_1_el[] = { 50 };

	assert(BynFind(arr1_sort, 0, n1-1, 5) == 1);

	assert(BynFind(arr1_sort, 0, n1 - 1, 80000) == 8);

	assert(BynFind(arr1_sort, 0, n1 - 1, 10) == 4);

	assert(BynFind(arr1_sort, 0, n1 - 1, 600) == 0);

	assert(BynFind(arr_w_1_el, 0, 1-1, 80) == 0);

	assert(BynFind(arr_w_1_el, 0, 1-1, 50) == 1);

	assert(InterFind(arr1_sort, 0, n1 - 1, 5) == 1);

	assert(InterFind(arr1_sort, 0, n1 - 1, 80000) == 8);

	assert(InterFind(arr1_sort, 0, n1 - 1, 10) == 4);

	assert(InterFind(arr1_sort, 0, n1 - 1, 600) == 0);

	assert(InterFind(arr_w_1_el, 0, 0, 80000) == 0);

	assert(InterFind(arr_w_1_el, 0, 0, 5000) == 1);
}

// тестирование функции сортировки пузырьком
void test_bublsort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(Arr_is_sort(11, arr1) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sort(9, arr2) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(Arr_is_sort(8, arr3) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(Arr_is_sort(12, arr4) == false);
	BubleSort(arr1, 11);
	assert(Arr_is_sort(11, arr1) == true);
	BubleSort(arr2, 9);
	assert(Arr_is_sort(9, arr2) == true);
	BubleSort(arr3, 8);
	assert(Arr_is_sort(8, arr3) == true);
	BubleSort(arr4, 12);
	assert(Arr_is_sort(12, arr4) == true);
}

// тестирование функции сортировки QuickSort
void test_quicksort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(Arr_is_sort(11, arr1) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sort(9, arr2) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(Arr_is_sort(8, arr3) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(Arr_is_sort(12, arr4) == false);
	QuickSort(arr1, 0, 10);
	assert(Arr_is_sort(11, arr1) == true);
	QuickSort(arr2, 0, 8);
	assert(Arr_is_sort(9, arr2) == true);
	QuickSort(arr3, 0, 8);
	assert(Arr_is_sort(8, arr3) == true);
	QuickSort(arr4, 0, 11);
	assert(Arr_is_sort(12, arr4) == true);
}

// тестирование функции функции сортировки Шелла
void test_shellsort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(Arr_is_sort(11, arr1) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sort(9, arr2) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(Arr_is_sort(8, arr3) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(Arr_is_sort(12, arr4) == false);
	ShellSort(arr1, 11);
	assert(Arr_is_sort(11, arr1) == true);
	ShellSort(arr2, 9);
	assert(Arr_is_sort(9, arr2) == true);
	ShellSort(arr3, 8);
	assert(Arr_is_sort(8, arr3) == true);
	ShellSort(arr4, 12);
	assert(Arr_is_sort(12, arr4) == true);
}

// тестирование функции сортировки слиянием
void test_mergesort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(Arr_is_sort(11, arr1) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sort(9, arr2) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(Arr_is_sort(8, arr3) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(Arr_is_sort(12, arr4) == false);
	MergeSort(arr1, 0, 10);
	assert(Arr_is_sort(11, arr1) == true);
	MergeSort(arr2, 0, 8);
	assert(Arr_is_sort(9, arr2) == true);
	MergeSort(arr3, 0, 8);
	assert(Arr_is_sort(8, arr3) == true);
	MergeSort(arr4, 0, 11);
	assert(Arr_is_sort(12, arr4) == true);
}