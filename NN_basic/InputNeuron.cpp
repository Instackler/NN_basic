#include "InputNeuron.h"


float InputNeuron::calc(int input)
{
	return input * this->weight;
}


