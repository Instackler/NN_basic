#pragma once

class InputNeuron
{
public:
	InputNeuron();
	double out(double);
	double get_weight();
	double get_last();
private:
	double weight;
	double last;
};