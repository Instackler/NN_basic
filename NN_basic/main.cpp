#include <iostream>
#include "Network.h"





int main()
{
	float x[3] { 2,2,2 };

	Network n(3, 8, 1);

	printf_s("%f\n", n.process(x)[0]);
	//std::cout << n.process(x)[0] << std::endl;

	std::cin.get();

	return 0;
}