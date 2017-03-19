#include "OutputNeuron.h"


int OutputNeuron::hidden_num;

void OutputNeuron::set_hidden_num(int num)
{
	hidden_num = num;
}

float OutputNeuron::out(float* input)
{
	float buffer = 0;
	for (int i = 0; i < hidden_num; ++i)
	{
		buffer += input[i];
	}


	return buffer;
}


