#include<iostream>
#include"header.h"
#include <clocale>

void printMenu();

int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;
	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			printArray(a, len);
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0:
				exit = true;
				break;
			case 1:
				printArray(a, len);
				system("pause");
				break;
			case 2:
			{
				int element = 0;
				std::cout << "Input element to add : ";
				std::cin >> element;
				addElement(a, len, element);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cout << "Input index to extract : ";
				std::cin >> index;
				std::cout << "Extracted  " << extractElement(a, len, index) << std::endl;
				break;
			}
			case 4:
			{
				printArrayInAscendingOrder(a, len);
				break;
			}
			case 5:
			{
				printReverseArray(a, len);
				system("pause");
				break;
			}
			case 6:
			{
				replaceMaxAndMin(a, len);
				printArray(a, len);
				system("pause");
				break;
			}
			case 7:
			{
				deleteRepeatableElements(a, len);
				break;
			}
			case 8:
			{
				int n = 0;
				std::cout << "Print your number: ";
				std::cin >> n;
				AddRandomNumbers(a, len, n);
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl;
				break;
			}
		}
	}
	return 0;
}

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Append element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
	std::cout << "4 - Sort the array in ascending order" << std::endl;
	std::cout << "5 - Reverse the array" << std::endl;
	std::cout << "6 - Change the first max element with the last min element" << std::endl;
	std::cout << "7 - Delete repeatable numbers from the array" << std::endl;
	std::cout << "8 - Add N-random numbers in array" << std::endl;
}