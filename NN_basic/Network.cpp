#include "Network.h"
#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"
#include <random>
#include <time.h>


Network::Network(int in, int hidden, int out)
{
	srand(time(NULL));
	input_num = in;
	hidden_num = hidden;
	output_num = out;
	input_neurons = new InputNeuron[in];
	HiddenNeuron::set_input_num(in);
	hidden_neurons = new HiddenNeuron[hidden];
	OutputNeuron::set_hidden_num(hidden);
	output_neurons = new OutputNeuron[out];
	in_res = new double[in] {0};
	hid_res = new double[hidden] {0};
	out_res = new double[out] {0};
};

double* Network::process(double* input_array)
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

void Network::learn(double* input, double* expected, double rate)
{
	double* output = this->process(input);

	double coeff = 0;
	double* new_weights = new double[hidden_num];

	for (int i = 0; i < output_num; ++i)
	{
		coeff = (output[i] - expected[i]) * output[i] * (1 - output[i]);
		double* old_weights = output_neurons[i].get_weights();
		
		for (int j = 0; j < hidden_num; ++j)
		{
			new_weights[j] = old_weights[j] - hidden_neurons[j].get_last() * coeff * rate;
		}
		output_neurons[i].set_weights(new_weights);

		delete new_weights;
	}

	double error = 0;

	for (int i = 0; i < hidden_num; ++i)
	{
		error = output_neurons[0].get_weights()[i] * coeff;
		coeff = error * hidden_neurons[i].get_last() * (1 - hidden_neurons[i].get_last());
		double* old_weights = hidden_neurons[i].get_weights();
		new_weights = new double[input_num];
		for (int j = 0; j < input_num; ++j)
		{
			new_weights[j] = old_weights[j] - input_neurons[j].get_last() * coeff * rate;
		}
		hidden_neurons[i].set_weights(new_weights);
		delete new_weights;
	}

}

void Network::show_weights()
{
	for (int i = 0; i < input_num; ++i)
	{
		printf_s("%f, ", input_neurons[i].get_weight());
	}
	printf_s("\n");

	double* hid_w;
	for (int i = 0; i < hidden_num; ++i)
	{
		hid_w = hidden_neurons[i].get_weights();
		for (int j = 0; j < input_num; ++j)
		{
			printf_s("%f, \n", hid_w[j]);
		}
	}
	printf_s("\n");

	double* out_w;
	for (int i = 0; i < output_num; ++i)
	{
		out_w = output_neurons[i].get_weights();
		for (int j = 0; j < hidden_num; ++j)
		{
			printf_s("%f, ", out_w[j]);
		}
	}
	printf_s("\n");
}

