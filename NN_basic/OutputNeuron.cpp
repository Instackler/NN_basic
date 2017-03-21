#include "OutputNeuron.h"
#include <random>


int OutputNeuron::hidden_num;

OutputNeuron::OutputNeuron()
{
	weights = new double[hidden_num];
	for (int i = 0; i < hidden_num; ++i)
	{
		weights[i] = (double)(rand() % 1000 + 1) / 1000.0;
	}
}

void OutputNeuron::set_hidden_num(int num)
{
	hidden_num = num;
}

double OutputNeuron::out(double* input)
{
	double buffer = 0;
	for (int i = 0; i < hidden_num; ++i)
	{
		buffer += input[i] * weights[i];
	}


	return buffer;
}


