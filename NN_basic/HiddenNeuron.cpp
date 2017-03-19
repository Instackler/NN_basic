#include "HiddenNeuron.h"


int HiddenNeuron::input_num;

float HiddenNeuron::out(float* input)
{
	float buffer = 0;
	for (int i = 0; i < input_num; ++i)
	{
		buffer += input[i];
	}
	
	
	return buffer;
}

void HiddenNeuron::set_input_num(int in_num)
{
	input_num = in_num;
}

HiddenNeuron::HiddenNeuron()
{
	
}
