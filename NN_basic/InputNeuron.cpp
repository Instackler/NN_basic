#include "InputNeuron.h"
#include <random>
#include <time.h>


float InputNeuron::out(float input)
{
	return input * weight;
}

InputNeuron::InputNeuron()
{
	srand(time(NULL));
	weight = (float)(rand() % 1000 + 1) / (float)1000;
}


