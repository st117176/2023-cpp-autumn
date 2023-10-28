#include "header.h"
#include <iostream>
#include <clocale>
#include <ctime>

void printArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
	}
	std::cout << std::endl;
}

void printArrayInAscendingOrder(int* a, int len)
{
	int temp = 0;
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = 0; j < len - 1; ++j)
			{
				if (a[j] > a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
	std::cout << std::endl;
}

int findIndexOfMinElement(int* a, int len)
{
	if (a != nullptr)
	{
		int minIndex = 0;
		for (int i = 0; i < len - 1; ++i)
		{
			if (a[minIndex] >= a[i + 1])
			{
				minIndex = i + 1;
			}
		}
		return minIndex;
	}
	return -1;
}

int findIndexOfMaxElement(int* a, int len)
{
	if (a != nullptr)
	{
		int maxIndex = len - 1;
		for (int i = len - 1; i >= 1; --i)
		{
			if (a[i - 1] >= a[maxIndex])
			{
				maxIndex = i - 1;
			}
		}
		return maxIndex;
	}
	return -1;
}

void swapElements(int* a, int len, int index1, int index2)
{
	if (a != nullptr)
	{
		int elem1 = a[index1];
		a[index1] = a[index2];
		a[index2] = elem1;
	}
}

void replaceMaxAndMin(int* a, int len)
{
	if (len > 1)
	{
		swapElements(a, len, findIndexOfMinElement(a, len), findIndexOfMaxElement(a, len));
	}
}

void deleteRepeatableElements(int*& a, int& len)
{
	if (len > 1)
	{
		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (a[i] == a[j])
				{
					extractElement(a, len, j);
					j--;
				}
			}
		}
	}
}

void expandArray(int*& a, int& len)
{
	int* newA = new int[len + 1]{ 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	++len;
}

void addElement(int*& a, int& len, int element)
{
	expandArray(a, len);
	a[len - 1] = element;
}

void contractArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len - 1];
		for (int i = 0; i < len - 1; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
		a = newA;
		--len;
	}
}

bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);
}

int extractElement(int*& a, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = a[index];
		for (int i = index; i < len - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		contractArray(a, len);
	}
	return res;
}

void printReverseArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[len - i - 1] << " ";
		}
	}
	std::cout << std::endl;
}

void AddRandomNumbers(int*& a, int& len, int n)
{
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		addElement(a, len, rand() % 100);
	}
}