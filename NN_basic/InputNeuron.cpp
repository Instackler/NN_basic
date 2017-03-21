#include "InputNeuron.h"


double InputNeuron::out(double input)
{
	last = input * weight;
	return last;
}

InputNeuron::InputNeuron()
{
	//weight = (double)(rand() % 1000 + 1) / (double)1000;
	weight = 1.0;
}

double InputNeuron::get_weight()
{
	return weight;
}

double InputNeuron::get_last()
{
	return last;
}

