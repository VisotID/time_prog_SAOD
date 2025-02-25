// Высоцкая И.Д.
#pragma once // директива в С++, для предотвращения многократного включения одного и того же заголовочного файла
#include <iostream> // библиотека С++, отвечающая за чтение и запись(для функций cin - функция чтения, cout - функция вывода)
#include <fstream> // библиотека С++ для работы с файлами
#include <random> // библиотека С++ для генерации случайных чисел
#include <chrono> // библиотека С++ для работы со временем
#include <string> // библиотека С++ для работы со строками
#include <cassert> // библиотека С++ для обнаружения логических ошибок в программе(для функции assert)
#include <functional> // определяет функции стандартной библиотеки C++, которые помогают создавать объекты функций

using namespace std; // используем пространство имен std для того, чтобы не писать перед функциями cin, cout "std"
using namespace chrono; // пространство имён chrono предназначено для работы с датой и временем

/// функция заполнения массива случайными числами
/// size_t n - размер массива, Temp start - начальный элемент, Temp fin - конечный элемент
template <typename Temp>
Temp* Arr_create(size_t n, Temp start, Temp fin)
{
	random_device rand; // генератор случайных чисел
	mt19937 gen(rand()); // генератор случайных чисел, mt19937 - один из вариантов генератора псевдослучайных чисел Вихря Мерсена
	if (typeid(Temp) == typeid(int)) // если тип целочисленный
	{
		uniform_int_distribution<> dist_fil(start, fin); // создаёт случайные целочисленные значения с одинаковой вероятностью в заданном диапазоне 
		Temp* arr = new Temp[n]; // создание целочисленного массива
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = dist_fil(gen); // элемент массива = случайное число
		}
		return arr; // возвращаем массив
	}
	else // иначе
	{
		uniform_real_distribution<> dist_fil(start, fin); // генерирует случайные вещественные значения, которые имеют равномерное распределение в заданном диапазоне
		Temp* arr = new Temp[n]; // создание вещественного массива
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = dist_fil(gen); // элемент массива = случайное число
		}
		return arr; // возвращаем массив
	}
}

/// функция заполнения массива случайными числами монотонно
/// size_t n - размер массива, Temp start - начальный элемент, Temp fin - конечный элемент
template <typename Temp>
Temp* Arr_create_m(size_t n, Temp start, Temp fin)
{
	random_device rand; // равномерно распределённый генератор случайных чисел, который выдаёт недетерминированные случайные числа
	mt19937 gen(rand()); // инициализация метода рандома, mt19937 - один из вариантов генератора псевдослучайных чисел Вихря Мерсена
	if (typeid(Temp) == typeid(int)) // если тип целочисленный
	{
		uniform_int_distribution<> dist_fil(start, fin); // создаёт случайные целочисленные значения с одинаковой вероятностью в заданном диапазоне
		Temp* arr = new Temp[n]; // создание целочисленного массива
		arr[0] = dist_fil(gen); // нулевой элемент массива = случайное число
		for (size_t i = 1; i < n; i++)
		{
			arr[i] = arr[i-1]+(dist_fil(gen)/10);
		}
		return arr; // возвращаем массив
	}
	else // иначе
	{
		uniform_real_distribution<> dist_fil(start, fin); // генерирует случайные вещественные значения, которые имеют равномерное распределение в заданном диапазоне
		Temp* arr = new Temp[n]; // создание вещественного массива
		arr[0] = dist_fil(gen); // нулевой элемент массива = случайное число
		for (size_t i = 1; i < n; i++)
		{
			arr[i] = arr[i - 1] + (dist_fil(gen) / 10);
		}
		return arr; // возвращаем массив
	}
}

/// функция проверки сортировки массива по возрастанию
/// size_t n - размер массива, Temp* arr - массив
template <typename Temp>
bool Arr_sort(size_t n, Temp* arr)
{
	for (size_t i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1]) // если элемент массива меньше предыдущего
		{
			return false; // возвращаем ложь
		}
	}
	return true; // возвращаем правду
}

/// функция нахождения элемента в массиве
/// size_t n - размер массива, Temp* arr - массив, Temp el - нужный элемент
template <typename Temp>
bool Arr_elem(size_t n, Temp* arr, Temp el)
{
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] == el) // если элемент массива = нужному элементу
		{
			return true; // возвращаем правду
		}
	}
	return false; // возвращаем ложь
}

/// функция нахождения времени работы функции
/// Temp func - функция, время работы которой нужно определить
template <typename Temp>
int Time_func(Temp func)
{
	auto t = steady_clock::now(); // начальное время, steady_clock::now() - возвращает текущее время из объекта класса steady_clock
	func(); // использование функции
	auto t2 = steady_clock::now(); // конечное время
	auto delta = duration_cast<milliseconds>(t2 - t); // duration_cast<milliseconds>(t2 - t) - используется для преобразования объекта длительности в тип длительности в миллисекундах
	return delta.count(); // возвращаем результат
}

/// функция нахождения общего времени работы программы
/// size_t n - размер массива, Temp start - начальный элемент случайных чисел, Temp fin - конечный элемент случайных чисел, Temp* arr - массив
template <typename Temp>
void Time_tot(size_t n, Temp start, Temp fin, Temp* arr)
{
	random_device rand; // равномерно распределённый генератор случайных чисел, который выдаёт недетерминированные случайные числа
	mt19937 gen(rand()); // инициализация метода рандома, mt19937 - один из вариантов генератора псевдослучайных чисел Вихря Мерсена
	uniform_int_distribution<> dist_fil(start, fin); // создаёт случайные целочисленные значения с одинаковой вероятностью в заданном диапазоне
	int start_time = 0; // начальное время
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
	ofstream f; // ofstream для записи в файл
	f.open(namef); //открываем файл
	if (f.is_open()) // если открылся
	{
		for (size_t i = 0; i < n; i++)
		{
			f << arr[i] << "\n"; // запись в файл
		}
	}
	f.close(); // закрываем файл
}

/*/// функция бинарного поиска элемента в массиве
/// size_t n - размер массива, Temp* arr - массив, Temp el - нужный элемент
template <typename Temp>
Temp* Arr_elem_b(size_t n, Temp* arr, Temp el)
{
	int mid;
	int l;
	if (n == 1)
	{
		arr = el;
		if (arr == el)
		{
			return arr;
		}
		else cout << "Элемент не найден";
		return;
	}
	else 
	{
		mid = n / 2;
		if (arr[mid] < el)
		{
			l = mid + 1;
		}
		if (arr[mid] > el)
		{
			l = mid - 1;
		}
		if (arr[mid] == el)
		{
			return mid;
		}
	}
}*/