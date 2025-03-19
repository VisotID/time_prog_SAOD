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
	assert(Arr_is_sorted(5, arr1_s) == true);
	assert(Arr_is_sorted(5, arr2_s) == true);
	assert(Arr_is_sorted(1, arr3_s) == true);
	assert(Arr_is_sorted(0, arr4_s) == true);

	// не отсортированные массивы
	int arr1_us[] = { 5, 6, 4, 1, 9 };
	double arr2_us[] = { 2.5, 1.4, 1.3, 1.2, 1.1 };
	int arr3_us[] = { 5, 5, 5, 4, 5 };
	double arr4_us[] = { -1.3, -3.7, 0.1, 6.9 };
	assert(Arr_is_sorted(5, arr1_us) == false);
	assert(Arr_is_sorted(5, arr2_us) == false);
	assert(Arr_is_sorted(5, arr3_us) == false);
	assert(Arr_is_sorted(4, arr4_us) == false);

	// массив с одинаковыми элементами
	int arr_w_sim_el[] = { 1, 1, 1, 1, 1 };
	assert(Arr_is_sorted(5, arr_w_sim_el) == true);

	// массив с соседними одинаковыми элементами
	int arr_w_dub_el[] = { 1, 1, 4, 4, 5 };
	assert(Arr_is_sorted(5, arr_w_dub_el) == true);
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

// тестирование функций бинарного и интерполяционного поиска элемента в массиве
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

	assert(InterFind(arr_w_1_el, 0, 0, 50) == 1);
}

// тестирование функции сортировки пузырьком
void test_bublsort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(Arr_is_sorted(11, arr1) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sorted(9, arr2) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(Arr_is_sorted(8, arr3) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(Arr_is_sorted(12, arr4) == false);
	int arr_5[] = { 1 };
	int arr_6[] = { 5, 1 };
	assert(Arr_is_sorted(2, arr_6) == false);

	BubleSort(arr1, 11);
	assert(Arr_is_sorted(11, arr1) == true);
	BubleSort(arr2, 9);
	assert(Arr_is_sorted(9, arr2) == true);
	BubleSort(arr3, 8);
	assert(Arr_is_sorted(8, arr3) == true);
	BubleSort(arr4, 12);
	assert(Arr_is_sorted(12, arr4) == true);
	BubleSort(arr_5, 1);
	assert(Arr_is_sorted(1, arr_5) == true);
	BubleSort(arr_6, 2);
	assert(Arr_is_sorted(2, arr_6) == true);
}

// тестирование функции сортировки QuickSort
void test_quicksort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 100, 40 };
	assert(Arr_is_sorted(11, arr1) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sorted(9, arr2) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(Arr_is_sorted(12, arr4) == false);
	int arr_5[] = { 1 };
	int arr_6[] = { 5, 1 };
	assert(Arr_is_sorted(2, arr_6) == false);

	QuickSort(arr1, 0, 10);
	assert(Arr_is_sorted(11, arr1) == true);
	QuickSort(arr2, 0, 8);
	assert(Arr_is_sorted(9, arr2) == true);
	QuickSort(arr4, 0, 11);
	assert(Arr_is_sorted(12, arr4) == true);
	QuickSort(arr_5, 0, 0);
	assert(Arr_is_sorted(1, arr_5) == true);
	QuickSort(arr_6, 0, 1);
	assert(Arr_is_sorted(2, arr_6) == true);

}

// тестирование функции функции сортировки Шелла
void test_shellsort()
{
	int arr_1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(Arr_is_sorted(11, arr_1) == false);
	int arr_2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sorted(9, arr_2) == false);
	int arr_3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(Arr_is_sorted(8, arr_3) == false);
	int arr_4[] = { 1 };
	int arr_5[] = { 5, 1 };
	assert(Arr_is_sorted(2, arr_5) == false);

	ShellSort(arr_1, 11);
	assert(Arr_is_sorted(11, arr_1) == true);
	ShellSort(arr_2, 9);
	assert(Arr_is_sorted(9, arr_2) == true);
	ShellSort(arr_3, 8);
	assert(Arr_is_sorted(8, arr_3) == true);
	ShellSort(arr_4, 1);
	assert(Arr_is_sorted(1, arr_4) == true);
	ShellSort(arr_5, 2);
	assert(Arr_is_sorted(2, arr_5) == true);
}

// тестирование функции сортировки слиянием
void test_mergesort()
{
	int arr_1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 100, 40 };
	assert(Arr_is_sorted(11, arr_1) == false);
	int arr_2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sorted(9, arr_2) == false);
	int arr_3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(Arr_is_sorted(8, arr_3) == false);
	int arr_4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(Arr_is_sorted(12, arr_4) == false);
	int arr_5[] = { 1 };
	int arr_6[] = { 5, 1 };
	assert(Arr_is_sorted(2, arr_6) == false);

	MergeSort(arr_1, 0, 10);
	assert(Arr_is_sorted(11, arr_1) == true);
	MergeSort(arr_2, 0, 8);
	assert(Arr_is_sorted(9, arr_2) == true);
	MergeSort(arr_3, 0, 7);
	assert(Arr_is_sorted(8, arr_3) == true);
	MergeSort(arr_4, 0, 11);
	assert(Arr_is_sorted(12, arr_4) == true);
	MergeSort(arr_5, 0, 0);
	assert(Arr_is_sorted(1, arr_5) == true);
	MergeSort(arr_6, 0, 1);
	assert(Arr_is_sorted(2, arr_6) == true);
}

// тестирование функции сортировки вставками
void test_insertsort()
{
	int arr_1[] = { 5, 10, 2, 5, 2, 6, 4, 9, 10, 100, 40 };
	assert(Arr_is_sorted(11, arr_1) == false);
	int arr_2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(Arr_is_sorted(9, arr_2) == false);
	int arr_3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(Arr_is_sorted(8, arr_3) == false);
	int arr_4[] = { 1 };
	int arr_5[] = { 5, 1 };
	assert(Arr_is_sorted(2, arr_5) == false);

	InsertSort(arr_1, 11);
	assert(Arr_is_sorted(11, arr_1) == true);
	InsertSort(arr_2, 9);
	assert(Arr_is_sorted(9, arr_2) == true);
	InsertSort(arr_3, 8);
	assert(Arr_is_sorted(8, arr_3) == true);
	InsertSort(arr_4, 1);
	assert(Arr_is_sorted(1, arr_4) == true);
	InsertSort(arr_5, 2);
	assert(Arr_is_sorted(2, arr_5) == true);
}