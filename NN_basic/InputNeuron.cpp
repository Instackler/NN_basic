#include "InputNeuron.h"


double InputNeuron::out(double input)
{
	return input * weight;
}

InputNeuron::InputNeuron()
{
	//weight = (double)(rand() % 1000 + 1) / (double)1000;
	weight = 1.0;
}


