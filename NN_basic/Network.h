#pragma once
#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"


class Network
{
public:
	Network(int, int, int);
	float* process(float*);
private:
	int input_num;
	int hidden_num;
	int output_num;
	InputNeuron* input_neurons;
	HiddenNeuron* hidden_neurons;
	OutputNeuron* output_neurons;
	float* in_res;
	float* hid_res;
	float* out_res;

	float learning_rate;
};
