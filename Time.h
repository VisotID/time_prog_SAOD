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

/// ������� ���������� ������� ���������� �������
/// size_t n - ������ �������, Temp start - ��������� �������, Temp fin - �������� �������
template <typename Temp>
Temp* Arr_create(size_t n, Temp start, Temp fin)
{
	random_device rand;
	mt19937 gen(rand()); // ������������� ������ �������
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

/// ������� ���������� ������� ���������� ������� ���������
/// size_t n - ������ �������, Temp start - ��������� �������, Temp fin - �������� �������
template <typename Temp>
Temp* Arr_create_m(size_t n, Temp start, Temp fin)
{
	random_device rand;
	mt19937 gen(rand()); // ������������� ������ �������
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

/// ������� �������� ���������� ������� �� �����������
/// size_t n - ������ �������, Temp* arr - ������
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

/// ������� ���������� �������� � �������
/// size_t n - ������ �������, Temp* arr - ������, Temp el - ������ �������
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

/// ������� ���������� ������� ������ �������
/// Temp func - �������, ����� ������ ������� ����� ����������
template <typename Temp>
int Time_func(Temp func)
{
	auto t = steady_clock::now(); // ��������� �����
	func(); // ������������� �������
	auto t2 = steady_clock::now(); // �������� �����
	auto delta = duration_cast<milliseconds>(t2 - t);
	return delta.count();
}

/// ������� ���������� ������ ������� ������ ���������
/// size_t n - ������ �������, Temp start - ��������� ������� ��������� �����, Temp fin - �������� ������� ��������� �����, Temp* arr - ������
template <typename Temp>
void Time_tot(size_t n, Temp start, Temp fin, Temp* arr)
{
	random_device rand;
	mt19937 gen(rand()); // ������������� ������ �������
	uniform_int_distribution<> dist_fil(start, fin);
	int start_time = 0;
	for (int i = 0; i < 100; i++)
	{
		Temp find_el = arr[dist_fil(gen)];
		start_time += Time_func([&]() {bool k = Arr_elem<Temp>(n, arr, find_el); });
	}
	cout << start_time / 100.0;
}

/// ������� ���������� ������� � ����
/// size_t n - ������ �������, string namef - ��� �����, Temp* arr - ������
template <typename Temp>
void Save_f(size_t n, string namef, Temp* arr)
{
	ofstream f;
	f.open(namef); //��������� ����
	if (f.is_open())
	{
		for (size_t i = 0; i < n; i++)
		{
			f << arr[i] << "\n"; // ������ � ����
		}
	}
	f.close(); // ��������� ����
}