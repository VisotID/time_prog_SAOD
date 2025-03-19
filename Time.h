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


/// шаблон функции заполнения массива случайными числами
/// size_t n - размер массива, Temp start - начальный элемент, Temp fin - конечный элемент
template <typename Temp>
Temp* Arr_create(size_t n, Temp start, Temp fin)
{
	random_device rand; // генератор случайных чисел
	mt19937 gen(rand()); // генератор случайных чисел, mt19937 - один из вариантов генератора псевдослучайных чисел Вихря Мерсена
	if (typeid(Temp) == typeid(int)) // если тип целочисленный
	{
		uniform_int_distribution<> dist_fil(start, fin); // создаёт случайные целочисленные значения с одинаковой вероятностью в заданном диапазоне, uniform_int_distribution - равномерное распределение
		Temp* arr = new Temp[n]; // создание целочисленного массива
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = dist_fil(gen); // элемент массива = случайное число
		}
		return arr; // возвращаем массив
	}
	else // иначе
	{
		uniform_real_distribution<> dist_fil(start, fin); // генерирует случайные вещественные значения, которые имеют равномерное распределение в заданном диапазоне, uniform_real_distribution - равномерное распределение
		Temp* arr = new Temp[n]; // создание вещественного массива
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = dist_fil(gen); // элемент массива = случайное число
		}
		return arr; // возвращаем массив
	}
}

/// шаблон функции заполнения массива случайными числами монотонно возрастающими
/// size_t n - размер массива, Temp start - начальный элемент, Temp fin - конечный элемент
template <typename Temp>
Temp* Arr_create_m(size_t n, Temp start, Temp fin)
{
	random_device rand; // равномерно распределённый генератор случайных чисел, который выдаёт недетерминированные случайные числа
	mt19937 gen(rand()); // инициализация метода рандома, mt19937 - один из вариантов генератора псевдослучайных чисел Вихря Мерсена
	if (typeid(Temp) == typeid(int)) // если тип целочисленный
	{
		uniform_int_distribution<> dist_fil(start, fin); // создаёт случайные целочисленные значения с одинаковой вероятностью в заданном диапазоне, uniform_int_distribution - равномерное распределение
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
		uniform_real_distribution<> dist_fil(start, fin); // генерирует случайные вещественные значения, которые имеют равномерное распределение в заданном диапазоне, uniform_real_distribution - равномерное распределение
		Temp* arr = new Temp[n]; // создание вещественного массива
		arr[0] = dist_fil(gen); // нулевой элемент массива = случайное число
		for (size_t i = 1; i < n; i++)
		{
			arr[i] = arr[i - 1] + (dist_fil(gen) / 10);
		}
		return arr; // возвращаем массив
	}
}

/// шаблон функции проверки сортировки массива по возрастанию
/// size_t n - размер массива, Temp* arr - массив
template <typename Temp>
bool Arr_is_sorted(size_t n, Temp* arr)
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

/// шаблон функции нахождения элемента в массиве
/// возвращает место элемента в массиве(индекс + 1), если элемента нет, то возвращает 0
/// size_t n - размер массива, Temp* arr - массив, Temp el - нужный элемент
template <typename Temp>
size_t Arr_elem(size_t n, Temp* arr, Temp el)
{
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] == el) // если элемент массива = нужному элементу
		{
			return i+1; // возвращаем правду
		}
	}
	return 0; // возвращаем ложь
}

/// шаблон функции нахождения времени работы функции
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

/// шаблон функции нахождения общего времени работы программы
/// size_t n - размер массива, Temp start - начальный элемент случайных чисел, Temp fin - конечный элемент случайных чисел, Temp* arr - массив
template <typename Temp>
void Time_tot(size_t n, Temp start, Temp fin, Temp* arr)
{
	random_device rand; // равномерно распределённый генератор случайных чисел, который выдаёт недетерминированные случайные числа
	mt19937 gen(rand()); // инициализация метода рандома, mt19937 - один из вариантов генератора псевдослучайных чисел Вихря Мерсена
	uniform_int_distribution<> dist_fil(start, fin); // создаёт случайные целочисленные значения с одинаковой вероятностью в заданном диапазоне, uniform_int_distribution - равномерное распределение
	int start_time = 0; // начальное время
	for (int i = 0; i < 100; i++)
	{
		Temp find_el = dist_fil(gen);
		start_time += Time_func([&]() {bool k = Arr_elem<Temp>(n, arr, find_el); }); // определение времени работы программы
	}
	cout << start_time / 100.0;
}

/// шаблон функции сохранения массива в файл
/// size_t n - размер массива, string namef - имя файла, Temp* arr - массив
template <typename Temp>
void Save_f(size_t n, const string& namef, Temp* arr)
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

/// бинарный поиск элемента в массиве
/// возвращает место элемента в массиве(индекс + 1), если элемента нет, то возвращает 0
/// BigO time (best - 1; average - log(n); worst - log(n))
/// BigO space (1)
/// Temp* arr - массив, size_t left - левая граница массива, size_t right - правая граница массива, Temp elem - искомый элемент
template <typename Temp>
size_t BynFind(Temp* arr, size_t left, size_t right, Temp elem)
{
	while (left <= right) // пока границы не будут равны
	{
		size_t mid = left + (right - left) / 2; // находим середину границ массива
		if (elem == arr[mid]) // если искомый элемент равен элементу в середине границ массива
			return mid + 1; // возвращаем индекс + 1;
		if (elem > arr[mid]) // если искомый элемент больше элемента в середине границ массива
			left = mid + 1; // ищем в правой части
		if (elem < arr[mid]) // если искомый элемент меньше элемента в середине границ массива
			right = mid - 1; // ищем в левой части
	}
	return 0; // если элемент не найден, то возвращаем 0
}

/// интерполяционный поиск элемента в массиве
/// возвращает место элемента в массиве(индекс + 1), если элемента нет, то возвращает 0
/// BigO time (average - log2(log2(n)); worst - n)
/// BigO space (1)
/// Temp* arr - массив, size_t left - левая граница массива, size_t right - правая граница массива, Temp elem - искомый элемент
template <typename Temp>
size_t InterFind(Temp* arr, size_t left, size_t right, Temp elem)
{
	size_t index = 0; // индекс элемента
	if (left <= right && elem >= arr[left] && elem <= arr[right]) // пока элемент в границах массива
	{
		if (arr[index] == elem) // если искомый элемент равен элементу в массиве на вычисленной позиции
			return index + 1; // возвращаем индекс + 1;
		index = left + (((double)(right-left)/(arr[right]-arr[left]))*(elem-arr[left])); // вычисляем индекс по формуле
		if (arr[index] == elem) // если искомый элемент равен элементу в массиве на вычисленной позиции
			return index + 1; // возвращаем индекс + 1;
		if (arr[index] < elem) // если искомый элемент больше элемента в массиве на вычисленной позиции
			return InterFind(arr, index + 1, right, elem); // ищем правее
		if (arr[index] > elem) // если искомый элемент меньше элемента в массиве на вычисленной позиции
			return InterFind(arr, left, index - 1, elem); // ищем левее
	}
	return 0; // если элемент не найден, то возвращаем 0
}

/// шаблон функции сортировки по возрастанию пузырьком
/// BigO time (best - n; average - n^2; worst - n^2)
/// BigO space (1)
/// Temp* arr - массив, size_t n - размер массива
template <typename Temp>
void BubleSort(Temp* arr, size_t n)
{
	if (n == 1)
	{
		return;
	}
	for (size_t i = 0; i < n - 1; i++) // пока не конец массива
	{
		for (size_t j = 0; j < n - i - 1; j++) // если последние элементы на правильном месте
		{
			if (arr[j] > arr[j + 1]) // сравнение соседних элементов
				swap(arr[j], arr[j + 1]); // меняем местами
		}
	}
}

/// шаблон функции разбиения массива(элементы меньше находятся слева от осевого элемента piv, а большие справа)
/// Temp* arr - массив, size_t left - левая граница массива, size_t right - правая граница массива, Temp piv - осевой элемент
template <typename Temp>
size_t Partit(Temp* arr, size_t left, size_t right, Temp piv)
{
	size_t Pind = left; // левая граница
	for (size_t i = left; i <= right; i++)
	{
		if (arr[i] <= piv) // если текущий элемент меньше чем осевой
		{
			swap(arr[Pind], arr[i]); // меняем местами элемент [Pind] с текущим элементом
			Pind++; // увеличиваем индекс
		}
	}
	return Pind-1; // возвращаем элемент
}

/// шаблон функции сортировки по возрастанию QuickSort
/// BigO time (best - n*log(n); average - n*log(n); worst - n^2)
/// BigO space (log(n))
/// Temp* arr - массив, size_t left - левая граница массива, size_t right - правая граница массива
template <typename Temp>
void QuickSort(Temp* arr, size_t left, size_t right)
{
	if (left < right)
	{
		Temp pivot = arr[right]; // определённый элемент - правая граница массива
		size_t Pind = Partit(arr, left, right, pivot); // получаем фактический индекс определённого осевого элемента
		if (right == left + 1)
		{
			return;
		}
		QuickSort(arr, left, Pind - 1); // рекурсивно вызываем функцию
		QuickSort(arr, Pind + 1, right); // рекурсивно вызываем функцию
	}
	return;
}

/// шаблон функции сортировки по возрастанию Шелла
/// BigO time (best - n*log(n); average - (n*log(n))^2; worst - (n*log(n))^2)
/// BigO space (1)
/// Temp* arr - массив, size_t n - размер массива
template <typename Temp>
void ShellSort(Temp* arr, size_t n)
{
	if (n == 1)
	{
		return;
	}
	for (size_t gap = n / 2; gap > 0; gap = gap / 2) // начнинаем с большого промежутка, затем уменьшаем
	{
		for (size_t i = gap; i < n; i++)
		{
			Temp temp = arr[i]; // сохраняем arr[i] в temp
			size_t j;
			for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
			{
				arr[j] = arr[j - gap]; // сдвигаем ранее отсортированные по промежутку элементы до тех пор, пока не будет найдено правильное местоположение для arr[i]
			}
			arr[j] = temp; // помещаем temp(исходный arr[i]) в нужное место
		}
	}
}

/// шаблон функции слияния двух подмассивов из массива arr[]
/// первый подмассив arr[left..mid], второй подмассив arr[mid+1..right]
/// Temp* arr - массив, size_t left - левая граница массива, size_t mid - середина массива, size_t right - правая граница массива
template <typename Temp>
void merge(Temp* arr, size_t left, size_t mid, size_t right)
{
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;
	Temp* L = new Temp(n1); // создание подмассива
	Temp* R = new Temp(n2); // создание подмассива
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
	while ((i < n1) && (j < n2)) // слияние подмассивов обратно в arr[left..right]
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
	while (i < n1) // копируем оставшиеся элементы подмассива L
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) // копируем оставшиеся элементы подмассива R
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/// функция сортировки по возрастанию слиянием
/// BigO time (best - n*log(n); average - n*log(n); worst - n*log(n))
/// BigO space (n)
/// Temp* arr - массив, size_t left - левая граница массива, size_t right - правая граница массива
template <typename Temp>
void MergeSort(Temp* arr, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t mid = left + (right - left) / 2; // вычисляем середину массива
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

/// Сортировка вставками по возрастанию
/// BigO time (best - n; average - n^2; worst - n^2)
/// BigO space (1)
/// Temp* arr - массив, size_t n - размер массива
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
		
		while (j >= 0 && arr[j] > key) // двигаем элементы arr[0..i-1], больше ключевого элемента на одну позицию выше их текущей позиции
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void test_for_is_sort(); // тестирование функции сортировки массива

void test_for_find_pos(); // тестирование функции нахождения элемента в массиве

void test_for_byn_iter_find(); // тестирование функций бинарного и интерполяционного поиска элемента в массиве

void test_bublsort(); // тестирование функции сортировки пузырьком

void test_quicksort(); // тестирование функции сортировки QuickSort

void test_shellsort(); // тестирование функции функции сортировки Шелла

void test_mergesort(); // тестирование функции сортировки слиянием

void test_insertsort(); // тестирование функции сортировки вставками