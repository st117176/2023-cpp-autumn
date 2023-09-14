
#include <iostream>
#include <string>
int main()
{
	int a;
	std::cin >> a;
	int lastl = 9 - a;
	std::string lastletter = std::to_string(lastl);
	std::string astring = std::to_string(a);

	std::cout << astring << "9" << lastletter << std::endl;
	return 0;
}

