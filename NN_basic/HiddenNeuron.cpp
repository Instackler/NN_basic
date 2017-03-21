#include "HiddenNeuron.h"
#include <math.h>
#include <random>
#define e 2.7182818284


int HiddenNeuron::input_num;

double HiddenNeuron::out(double* input)
{
	double buffer = 0;
	for (int i = 0; i < input_num; ++i)
	{
		buffer += input[i] * weights[i];
	}
	
	last = 1.0 / (1.0 + pow(e, -buffer));
	return last;
}

void HiddenNeuron::set_input_num(int in_num)
{
	input_num = in_num;
}

HiddenNeuron::HiddenNeuron()
{
	weights = new double[input_num];
	for (int i = 0; i < input_num; ++i)
	{
		weights[i] = (double)(rand() % 1000 + 1) / 1000.0;
	}
}

void HiddenNeuron::set_weights(double* w)
{
	for (int i = 0; i < input_num; ++i)
	{
		weights[i] = w[i];
	}
}

double HiddenNeuron::get_last()
{
	return last;
}

double* HiddenNeuron::get_weights()
{
	return weights;
}

