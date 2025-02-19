#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <cassert>
#include <functional>

using namespace std;
using namespace chrono;

/// функция заполнения массива случайными числами
/// size_t n - размер массива, Temp start - начальный элемент, Temp fin - конечный элемент
template <typename Temp>
Temp* Arr_create(size_t n, Temp start, Temp fin)
{
	random_device rand;
	mt19937 gen(rand()); // инициализация метода рандома
	if (typeid(Temp) == typeid(int))
	{
		uniform_int_distribution<> dist_fil(start, fin);
		Temp* arr = new Temp[n];
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = dist_fil(gen);
		}
		return arr;
	}
	else 
	{
		uniform_real_distribution<> dist_fil(start, fin);
		Temp* arr = new Temp[n];
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = dist_fil(gen);
		}
		return arr;
	}
}

/// функция заполнения массива случайными числами монотонно
/// size_t n - размер массива, Temp start - начальный элемент, Temp fin - конечный элемент
template <typename Temp>
Temp* Arr_create_m(size_t n, Temp start, Temp fin)
{
	random_device rand;
	mt19937 gen(rand()); // инициализация метода рандома
	if (typeid(Temp) == typeid(int))
	{
		uniform_int_distribution<> dist_fil(start, fin);
		Temp* arr = new Temp[n];
		arr[0] = dist_fil(gen);
		for (size_t i = 1; i < n; i++)
		{
			arr[i] = arr[i-1]+(dist_fil(gen)/10);
		}
		return arr;
	}
	else
	{
		uniform_real_distribution<> dist_fil(start, fin);
		Temp* arr = new Temp[n];
		arr[0] = dist_fil(gen);
		for (size_t i = 1; i < n; i++)
		{
			arr[i] = arr[i - 1] + (dist_fil(gen) / 10);
		}
		return arr;
	}
}

/// функция проверки сортировки массива по возрастанию
/// size_t n - размер массива, Temp* arr - массив
template <typename Temp>
bool Arr_sort(size_t n, Temp* arr)
{
	for (size_t i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}
	return true;
}

/// функция нахождения элемента в массиве
/// size_t n - размер массива, Temp* arr - массив, Temp el - нужный элемент
template <typename Temp>
bool Arr_elem(size_t n, Temp* arr, Temp el)
{
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] == el)
		{
			return true;
		}
	}
	return false;
}

/// функция нахождения времени работы функции
/// Temp func - функция, время работы которой нужно определить
template <typename Temp>
int Time_func(Temp func)
{
	auto t = steady_clock::now(); // начальное время
	func(); // использование функции
	auto t2 = steady_clock::now(); // конечное время
	auto delta = duration_cast<milliseconds>(t2 - t);
	return delta.count();
}

/// функция нахождения общего времени работы программы
/// size_t n - размер массива, Temp start - начальный элемент случайных чисел, Temp fin - конечный элемент случайных чисел, Temp* arr - массив
template <typename Temp>
void Time_tot(size_t n, Temp start, Temp fin, Temp* arr)
{
	random_device rand;
	mt19937 gen(rand()); // инициализация метода рандома
	uniform_int_distribution<> dist_fil(start, fin);
	int start_time = 0;
	for (int i = 0; i < 100; i++)
	{
		Temp find_el = arr[dist_fil(gen)];
		start_time += Time_func([&]() {bool k = Arr_elem<Temp>(n, arr, find_el); });
	}
	cout << start_time / 100.0;
}

/// функция сохранения массива в файл
/// size_t n - размер массива, string namef - имя файла, Temp* arr - массив
template <typename Temp>
void Save_f(size_t n, string namef, Temp* arr)
{
	ofstream f;
	f.open(namef); //открываем файл
	if (f.is_open())
	{
		for (size_t i = 0; i < n; i++)
		{
			f << arr[i] << "\n"; // запись в файл
		}
	}
	f.close(); // закрываем файл
}