#pragma once
#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"


class Network
{
public:
	Network(int, int, int);
	double* process(double*);
private:
	int input_num;
	int hidden_num;
	int output_num;
	InputNeuron* input_neurons;
	HiddenNeuron* hidden_neurons;
	OutputNeuron* output_neurons;
	double* in_res;
	double* hid_res;
	double* out_res;

	double learning_rate;
};
