
#include <iostream>
#include <string>

int main()
{
	int n;
	float a;
	std::string end{"25"};
	std::cin >> n;
	int c = (n / 10) * ((n / 10) + 1);
	std::string s = std::to_string(c);
	std::cout << s + end;
	return 0;
}
