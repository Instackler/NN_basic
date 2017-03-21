#include <iostream>
#include "Network.h"




int main()
{
	Network n(3, 8, 1);

	double* x;
	double* exp;
	for (int i = 0; i < 200; ++i)
	{
		x = new double[3]{ (double)((rand() % 1000 + 1) / 1000), (double)((rand() % 1000 + 1) / 1000), (double)((rand() % 1000 + 1) / 1000) };
		exp = new double[1]{ x[0] + x[1] + x[2] };
		n.learn(x, exp, 0.1);
		delete x;
		delete exp;
	}

	n.show_weights();
	double y[3]{ 0.051,0.152,0.701 };
	printf_s("%f\n", n.process(y)[0]);
	//std::cout << n.process(x)[0] << std::endl;

	std::cin.get();

	return 0;
}