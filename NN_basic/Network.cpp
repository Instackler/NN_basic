#include "Network.h"
#include "InputNeuron.h"
#include "HiddenNeuron.h"
#include "OutputNeuron.h"


Network::Network(int in, int hidden, int out)
{
	input_num = in;
	hidden_num = hidden;
	output_num = out;
	input_neurons = new InputNeuron[input_num];
	hidden_neurons = new HiddenNeuron[hidden_num];

	output_neurons = new OutputNeuron[output_num];
	
};
