#include "InputNeuron.h"


float InputNeuron::out(int input)
{
	return input * weight;
}

InputNeuron::InputNeuron() {};


