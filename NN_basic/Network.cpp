#include "Network.h"
#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"


Network::Network(int in, int hidden, int out)
{
	input_num = in;
	hidden_num = hidden;
	output_num = out;
	input_neurons = new InputNeuron[in];
	HiddenNeuron::set_input_num(in);
	hidden_neurons = new HiddenNeuron[hidden];
	OutputNeuron::set_hidden_num(hidden);
	output_neurons = new OutputNeuron[out];
	in_res = new float[in] {0};
	hid_res = new float[hidden] {0};
	out_res = new float[out] {0};
};

float* Network::process(float* input_array)
{
	for (int i = 0; i < input_num; ++i)
	{
		in_res[i] = input_neurons[i].out(input_array[i]);
	}
	
	for (int i = 0; i < hidden_num; ++i)
	{
		hid_res[i] = hidden_neurons[i].out(in_res);
	}

	for (int i = 0; i < output_num; ++i)
	{
		out_res[i] = output_neurons[i].out(hid_res);
	}


	return out_res;
}


