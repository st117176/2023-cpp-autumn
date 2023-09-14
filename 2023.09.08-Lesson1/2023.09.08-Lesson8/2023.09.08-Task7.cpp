
#include <iostream>

int main()
{
	int num;
	std::cin >> num;
	int next = num + 1;
	int prev = num - 1;
    std::cout << "The next number for the number " << num << " is " << next <<".";
	std::cout << "\n";
	std::cout << "The previous number for the number " << num << " is " << prev <<".";
}
