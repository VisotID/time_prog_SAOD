// �������� �.�.
#pragma once // ��������� � �++, ��� �������������� ������������� ��������� ������ � ���� �� ������������� �����
#include <iostream> // ���������� �++, ���������� �� ������ � ������(��� ������� cin - ������� ������, cout - ������� ������)
#include <fstream> // ���������� �++ ��� ������ � �������
#include <random> // ���������� �++ ��� ��������� ��������� �����
#include <chrono> // ���������� �++ ��� ������ �� ��������
#include <string> // ���������� �++ ��� ������ �� ��������
#include <cassert> // ���������� �++ ��� ����������� ���������� ������ � ���������(��� ������� assert)
#include <functional> // ���������� ������� ����������� ���������� C++, ������� �������� ��������� ������� �������

using namespace std; // ���������� ������������ ���� std ��� ����, ����� �� ������ ����� ��������� cin, cout "std"
using namespace chrono; // ������������ ��� chrono ������������� ��� ������ � ����� � ��������


/// ������ ������� ���������� ������� ���������� �������
/// size_t n - ������ �������, Temp start - ��������� �������, Temp fin - �������� �������
template <typename Temp>
Temp* Arr_create(size_t n, Temp start, Temp fin)
{
	random_device rand; // ��������� ��������� �����
	mt19937 gen(rand()); // ��������� ��������� �����, mt19937 - ���� �� ��������� ���������� ��������������� ����� ����� �������
	if (typeid(Temp) == typeid(int)) // ���� ��� �������������
	{
		uniform_int_distribution<> dist_fil(start, fin); // ������ ��������� ������������� �������� � ���������� ������������ � �������� ���������, uniform_int_distribution - ����������� �������������
		Temp* arr = new Temp[n]; // �������� �������������� �������
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = dist_fil(gen); // ������� ������� = ��������� �����
		}
		return arr; // ���������� ������
	}
	else // �����
	{
		uniform_real_distribution<> dist_fil(start, fin); // ���������� ��������� ������������ ��������, ������� ����� ����������� ������������� � �������� ���������, uniform_real_distribution - ����������� �������������
		Temp* arr = new Temp[n]; // �������� ������������� �������
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = dist_fil(gen); // ������� ������� = ��������� �����
		}
		return arr; // ���������� ������
	}
}

/// ������ ������� ���������� ������� ���������� ������� ��������� �������������
/// size_t n - ������ �������, Temp start - ��������� �������, Temp fin - �������� �������
template <typename Temp>
Temp* Arr_create_m(size_t n, Temp start, Temp fin)
{
	random_device rand; // ���������� ������������� ��������� ��������� �����, ������� ����� ������������������� ��������� �����
	mt19937 gen(rand()); // ������������� ������ �������, mt19937 - ���� �� ��������� ���������� ��������������� ����� ����� �������
	if (typeid(Temp) == typeid(int)) // ���� ��� �������������
	{
		uniform_int_distribution<> dist_fil(start, fin); // ������ ��������� ������������� �������� � ���������� ������������ � �������� ���������, uniform_int_distribution - ����������� �������������
		Temp* arr = new Temp[n]; // �������� �������������� �������
		arr[0] = dist_fil(gen); // ������� ������� ������� = ��������� �����
		for (size_t i = 1; i < n; i++)
		{
			arr[i] = arr[i-1]+(dist_fil(gen)/10);
		}
		return arr; // ���������� ������
	}
	else // �����
	{
		uniform_real_distribution<> dist_fil(start, fin); // ���������� ��������� ������������ ��������, ������� ����� ����������� ������������� � �������� ���������, uniform_real_distribution - ����������� �������������
		Temp* arr = new Temp[n]; // �������� ������������� �������
		arr[0] = dist_fil(gen); // ������� ������� ������� = ��������� �����
		for (size_t i = 1; i < n; i++)
		{
			arr[i] = arr[i - 1] + (dist_fil(gen) / 10);
		}
		return arr; // ���������� ������
	}
}

/// ������ ������� �������� ���������� ������� �� �����������
/// size_t n - ������ �������, Temp* arr - ������
template <typename Temp>
bool Arr_is_sorted(size_t n, Temp* arr)
{
	for (size_t i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1]) // ���� ������� ������� ������ �����������
		{
			return false; // ���������� ����
		}
	}
	return true; // ���������� ������
}

/// ������ ������� ���������� �������� � �������
/// ���������� ����� �������� � �������(������ + 1), ���� �������� ���, �� ���������� 0
/// size_t n - ������ �������, Temp* arr - ������, Temp el - ������ �������
template <typename Temp>
size_t Arr_elem(size_t n, Temp* arr, Temp el)
{
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] == el) // ���� ������� ������� = ������� ��������
		{
			return i+1; // ���������� ������
		}
	}
	return 0; // ���������� ����
}

/// ������ ������� ���������� ������� ������ �������
/// Temp func - �������, ����� ������ ������� ����� ����������
template <typename Temp>
int Time_func(Temp func)
{
	auto t = steady_clock::now(); // ��������� �����, steady_clock::now() - ���������� ������� ����� �� ������� ������ steady_clock
	func(); // ������������� �������
	auto t2 = steady_clock::now(); // �������� �����
	auto delta = duration_cast<milliseconds>(t2 - t); // duration_cast<milliseconds>(t2 - t) - ������������ ��� �������������� ������� ������������ � ��� ������������ � �������������
	return delta.count(); // ���������� ���������
}

/// ������ ������� ���������� ������ ������� ������ ���������
/// size_t n - ������ �������, Temp start - ��������� ������� ��������� �����, Temp fin - �������� ������� ��������� �����, Temp* arr - ������
template <typename Temp>
void Time_tot(size_t n, Temp start, Temp fin, Temp* arr)
{
	random_device rand; // ���������� ������������� ��������� ��������� �����, ������� ����� ������������������� ��������� �����
	mt19937 gen(rand()); // ������������� ������ �������, mt19937 - ���� �� ��������� ���������� ��������������� ����� ����� �������
	uniform_int_distribution<> dist_fil(start, fin); // ������ ��������� ������������� �������� � ���������� ������������ � �������� ���������, uniform_int_distribution - ����������� �������������
	int start_time = 0; // ��������� �����
	for (int i = 0; i < 100; i++)
	{
		Temp find_el = dist_fil(gen);
		start_time += Time_func([&]() {bool k = Arr_elem<Temp>(n, arr, find_el); }); // ����������� ������� ������ ���������
	}
	cout << start_time / 100.0;
}

/// ������ ������� ���������� ������� � ����
/// size_t n - ������ �������, string namef - ��� �����, Temp* arr - ������
template <typename Temp>
void Save_f(size_t n, const string& namef, Temp* arr)
{
	ofstream f; // ofstream ��� ������ � ����
	f.open(namef); //��������� ����
	if (f.is_open()) // ���� ��������
	{
		for (size_t i = 0; i < n; i++)
		{
			f << arr[i] << "\n"; // ������ � ����
		}
	}
	f.close(); // ��������� ����
}

/// �������� ����� �������� � �������
/// ���������� ����� �������� � �������(������ + 1), ���� �������� ���, �� ���������� 0
/// BigO time (best - 1; average - log(n); worst - log(n))
/// BigO space (1)
/// Temp* arr - ������, size_t left - ����� ������� �������, size_t right - ������ ������� �������, Temp elem - ������� �������
template <typename Temp>
size_t BynFind(Temp* arr, size_t left, size_t right, Temp elem)
{
	while (left <= right) // ���� ������� �� ����� �����
	{
		size_t mid = left + (right - left) / 2; // ������� �������� ������ �������
		if (elem == arr[mid]) // ���� ������� ������� ����� �������� � �������� ������ �������
			return mid + 1; // ���������� ������ + 1;
		if (elem > arr[mid]) // ���� ������� ������� ������ �������� � �������� ������ �������
			left = mid + 1; // ���� � ������ �����
		if (elem < arr[mid]) // ���� ������� ������� ������ �������� � �������� ������ �������
			right = mid - 1; // ���� � ����� �����
	}
	return 0; // ���� ������� �� ������, �� ���������� 0
}

/// ���������������� ����� �������� � �������
/// ���������� ����� �������� � �������(������ + 1), ���� �������� ���, �� ���������� 0
/// BigO time (average - log2(log2(n)); worst - n)
/// BigO space (1)
/// Temp* arr - ������, size_t left - ����� ������� �������, size_t right - ������ ������� �������, Temp elem - ������� �������
template <typename Temp>
size_t InterFind(Temp* arr, size_t left, size_t right, Temp elem)
{
	size_t index = 0; // ������ ��������
	if (left <= right && elem >= arr[left] && elem <= arr[right]) // ���� ������� � �������� �������
	{
		if (arr[index] == elem) // ���� ������� ������� ����� �������� � ������� �� ����������� �������
			return index + 1; // ���������� ������ + 1;
		index = left + (((double)(right-left)/(arr[right]-arr[left]))*(elem-arr[left])); // ��������� ������ �� �������
		if (arr[index] == elem) // ���� ������� ������� ����� �������� � ������� �� ����������� �������
			return index + 1; // ���������� ������ + 1;
		if (arr[index] < elem) // ���� ������� ������� ������ �������� � ������� �� ����������� �������
			return InterFind(arr, index + 1, right, elem); // ���� ������
		if (arr[index] > elem) // ���� ������� ������� ������ �������� � ������� �� ����������� �������
			return InterFind(arr, left, index - 1, elem); // ���� �����
	}
	return 0; // ���� ������� �� ������, �� ���������� 0
}

/// ������ ������� ���������� �� ����������� ���������
/// BigO time (best - n; average - n^2; worst - n^2)
/// BigO space (1)
/// Temp* arr - ������, size_t n - ������ �������
template <typename Temp>
void BubleSort(Temp* arr, size_t n)
{
	if (n == 1)
	{
		return;
	}
	for (size_t i = 0; i < n - 1; i++) // ���� �� ����� �������
	{
		for (size_t j = 0; j < n - i - 1; j++) // ���� ��������� �������� �� ���������� �����
		{
			if (arr[j] > arr[j + 1]) // ��������� �������� ���������
				swap(arr[j], arr[j + 1]); // ������ �������
		}
	}
}

/// ������ ������� ��������� �������(�������� ������ ��������� ����� �� ������� �������� piv, � ������� ������)
/// Temp* arr - ������, size_t left - ����� ������� �������, size_t right - ������ ������� �������, Temp piv - ������ �������
template <typename Temp>
size_t Partit(Temp* arr, size_t left, size_t right, Temp piv)
{
	size_t Pind = left; // ����� �������
	for (size_t i = left; i <= right; i++)
	{
		if (arr[i] <= piv) // ���� ������� ������� ������ ��� ������
		{
			swap(arr[Pind], arr[i]); // ������ ������� ������� [Pind] � ������� ���������
			Pind++; // ����������� ������
		}
	}
	return Pind-1; // ���������� �������
}

/// ������ ������� ���������� �� ����������� QuickSort
/// BigO time (best - n*log(n); average - n*log(n); worst - n^2)
/// BigO space (log(n))
/// Temp* arr - ������, size_t left - ����� ������� �������, size_t right - ������ ������� �������
template <typename Temp>
void QuickSort(Temp* arr, size_t left, size_t right)
{
	if (left < right)
	{
		Temp pivot = arr[right]; // ����������� ������� - ������ ������� �������
		size_t Pind = Partit(arr, left, right, pivot); // �������� ����������� ������ ������������ ������� ��������
		if (right == left + 1)
		{
			return;
		}
		QuickSort(arr, left, Pind - 1); // ���������� �������� �������
		QuickSort(arr, Pind + 1, right); // ���������� �������� �������
	}
	return;
}

/// ������ ������� ���������� �� ����������� �����
/// BigO time (best - n*log(n); average - (n*log(n))^2; worst - (n*log(n))^2)
/// BigO space (1)
/// Temp* arr - ������, size_t n - ������ �������
template <typename Temp>
void ShellSort(Temp* arr, size_t n)
{
	if (n == 1)
	{
		return;
	}
	for (size_t gap = n / 2; gap > 0; gap = gap / 2) // ��������� � �������� ����������, ����� ���������
	{
		for (size_t i = gap; i < n; i++)
		{
			Temp temp = arr[i]; // ��������� arr[i] � temp
			size_t j;
			for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
			{
				arr[j] = arr[j - gap]; // �������� ����� ��������������� �� ���������� �������� �� ��� ���, ���� �� ����� ������� ���������� �������������� ��� arr[i]
			}
			arr[j] = temp; // �������� temp(�������� arr[i]) � ������ �����
		}
	}
}

/// ������ ������� ������� ���� ����������� �� ������� arr[]
/// ������ ��������� arr[left..mid], ������ ��������� arr[mid+1..right]
/// Temp* arr - ������, size_t left - ����� ������� �������, size_t mid - �������� �������, size_t right - ������ ������� �������
template <typename Temp>
void merge(Temp* arr, size_t left, size_t mid, size_t right)
{
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;
	Temp* L = new Temp(n1); // �������� ����������
	Temp* R = new Temp(n2); // �������� ����������
	for (size_t i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}
	for (size_t i = 0; i < n2; i++)
	{
		R[i] = arr[mid + 1 + i];
	}
	size_t i = 0;
	size_t j = 0;
	size_t k = left;
	while ((i < n1) && (j < n2)) // ������� ����������� ������� � arr[left..right]
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) // �������� ���������� �������� ���������� L
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) // �������� ���������� �������� ���������� R
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/// ������� ���������� �� ����������� ��������
/// BigO time (best - n*log(n); average - n*log(n); worst - n*log(n))
/// BigO space (n)
/// Temp* arr - ������, size_t left - ����� ������� �������, size_t right - ������ ������� �������
template <typename Temp>
void MergeSort(Temp* arr, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t mid = left + (right - left) / 2; // ��������� �������� �������
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

/// ���������� ��������� �� �����������
/// BigO time (best - n; average - n^2; worst - n^2)
/// BigO space (1)
/// Temp* arr - ������, size_t n - ������ �������
template <typename Temp>
void InsertSort(Temp* arr, size_t n)
{
	if (n == 1)
	{
		return;
	}
	for (size_t i = 1; i < n; i++)
	{
		Temp key = arr[i];
		size_t j = i - 1;
		
		while (j >= 0 && arr[j] > key) // ������� �������� arr[0..i-1], ������ ��������� �������� �� ���� ������� ���� �� ������� �������
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void test_for_is_sort(); // ������������ ������� ���������� �������

void test_for_find_pos(); // ������������ ������� ���������� �������� � �������

void test_for_byn_iter_find(); // ������������ ������� ��������� � ����������������� ������ �������� � �������

void test_bublsort(); // ������������ ������� ���������� ���������

void test_quicksort(); // ������������ ������� ���������� QuickSort

void test_shellsort(); // ������������ ������� ������� ���������� �����

void test_mergesort(); // ������������ ������� ���������� ��������

void test_insertsort(); // ������������ ������� ���������� ���������