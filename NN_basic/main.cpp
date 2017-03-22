#include <iostream>
#include "Network.h"
#include <random>
#include <time.h>


double x[3];
double expected[1];

int main()
{
	Network n(3, 16, 1);

	for (int i = 0; i < 50000; ++i)
	{
		x[0] = rand() % 2;
		x[1] = rand() % 2;
		x[2] = rand() % 2;
		expected[0] = ((bool)x[0] & (bool)x[1]) || (bool)x[2];
		n.learn(x, expected, 5.0);
	}

	n.show_weights();
	double y1[3]{ 1.0,1.0,1.0 };
	double y2[3]{ 1.0,1.0,0.0 };
	double y3[3]{ 1.0,0.0,0.0 };
	double y4[3]{ 1.0,0.0,1.0 };
	double y5[3]{ 0.0,0.0,0.0 };
	double y6[3]{ 0.0,0.0,1.0 };
	double y7[3]{ 0.0,1.0,0.0 };
	double y8[3]{ 0.0,1.0,1.0 };
	printf_s("%f\n", n.process(y1)[0]);
	printf_s("%f\n", n.process(y2)[0]);
	printf_s("%f\n", n.process(y3)[0]);
	printf_s("%f\n", n.process(y4)[0]);
	printf_s("%f\n", n.process(y5)[0]);
	printf_s("%f\n", n.process(y6)[0]);
	printf_s("%f\n", n.process(y7)[0]);
	printf_s("%f\n", n.process(y8)[0]);
	//std::cout << n.process(x)[0] << std::endl;

	std::cin.get();

	return 0;
}