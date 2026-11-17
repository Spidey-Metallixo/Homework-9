#include <Windows.h>
#include <iostream>
#include <string>
#include <limits>

void PickArray(int*& arr, int size)
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = new int[size];
}

void FillArray(int* arr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void WriteArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void DeleteArray(int*& arr)
{
	if (arr == nullptr)
	{
		return;
	}
	delete[] arr;
	arr = nullptr;
}

void AddElement(int*& arr, int& size, int value)
{
	int* newArr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	newArr[size] = value;

	delete[] arr;
	arr = newArr;
	size++;
}

void InsertElement(int*& arr, int& size, int index, int value)
{
	if (index < 0 || index > size)
	{
		std::cout << "Неверный индекс для вставки!\n";
		return;
	}

	int* newArr = new int[size + 1];

	for (int i = 0; i < index; i++)
	{
		newArr[i] = arr[i];
	}

	newArr[index] = value;

	for (int i = index; i < size; i++)
	{
		newArr[i + 1] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	size++;
}

void RemoveElement(int*& arr, int& size, int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Неверный индекс для удаления!\n";
		return;
	}

	int* newArr = new int[size - 1];

	for (int i = 0; i < index; i++)
	{
		newArr[i] = arr[i];
	}

	for (int i = index + 1; i < size; i++)
	{
		newArr[i - 1] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	size--;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int size = 5;
	int* ptr = nullptr;



	PickArray(ptr, size);
	FillArray(ptr, size);

	std::cout << "Исходный массив:\t";
	WriteArray(ptr, size);
	std::cout << "\n";



	AddElement(ptr, size, 99);
	std::cout << "Добавили 99 в конец:\t";
	WriteArray(ptr, size);
	std::cout << "\n";



	InsertElement(ptr, size, 2, 77);
	std::cout << "Вставили 77 в [2]:\t";
	WriteArray(ptr, size);
	std::cout << "\n";



	RemoveElement(ptr, size, 0);
	std::cout << "Удалили элемент [0]:\t";
	WriteArray(ptr, size);
	std::cout << "\n";



	DeleteArray(ptr);
	std::cout << "\nПамять освобождена: ptr = ";
	if (ptr == nullptr)
	{
		std::cout << "nullptr\n";
	}
	else
	{
		std::cout << "не nullptr\n";
	}




	return 0;
}